#include "greed.h"

using std::endl;
using std::cout;
using std::cin;


/* ���ӵĹ��캯�� */
Dice::Dice(){
	valid = true;
	num = 0;
}
/* ��ȡ��Ч��: true ��Ч, false ��Ч */
bool Dice::isValid()
{
	return valid;
}
/* ������Ч�� */
void Dice::setValid(bool v)
{
	valid = v;
}
/* Ͷ������ */
void Dice::roll(){
	num = rand() % 6 + 1;
}
/* ��ȡ���ӵ��� */
int Dice::getNum(){
	return num;
}


/* ��ҵĹ��캯�� */
Player::Player()
{
	score = 0;
}
/* ��ҵĹ��캯�� */
Player::Player(std::string n)
{
	score = 0;
	name = n;
}
/* �������� */
void Player::setName(std::string n)
{
	name = n;
}
/* ��ȡ���� */
std::string Player::getName()
{
	return name;
}
/* ��ȡ���� */
int Player::getScore()
{
	return score;
}
/* ���÷��� */
void Player::setScore(int s)
{
	score = s;
}


/* Ͷ������ */
void Referee::rollDice()
{
	for (int i = 0; i < GAME_DICE_NUM; i++)
	{
		dices[i].roll();
	}
}
/* ���÷�����ʧЧ */
void Referee::invalidDice(int invalid_num)
{
	int j = 0;
	for (int i = 0; i < GAME_DICE_NUM; i++) {
		if (dices[i].isValid()) {
			dices[i].setValid(false);
			j++;
		}

		if (j == invalid_num) {
			break;
		}
	}
}
/* ����÷� */
int Referee::calculateScore()
{
	int point[6] = { 0 };    //��ŵ��������飬 point[0] = 3 ����1���������3����
	int score = 0;
	for (int i = 0; i < 6; i++) {
		if (dices[i].isValid()) {
			point[dices[i].getNum()-1] += 1;
		}
	}
	// ���ڵ���1�ĵ÷�ͳ��
	if (point[0] == 6) { 
		score = 3000;
		point[0] -= 6;
		invalidDice(6);			//����÷ֺ�������Ч��
	}
	else if (point[0] < 6 && point[0] >= 3) {
		score += 1000;
		point[0] -= 3;
		invalidDice(3);
	}
	else {}
	
	// ����3����ͬ�����ĵ÷�ͳ��
	for (int i = 1; i < 6; i++)
	{
		if (point[i] == 6) {       //����6����ͬ���������
			score += ((i + 1) * 100) * 2;
			point[i] -= 6;
			invalidDice(6);
		}
		else if (point[i] == 3) {    
			score += (i + 1) * 100;
			point[i] -= 3;
			invalidDice(3);
		}
	}

	// ���ڵ���5�ĵ÷�ͳ��
	score += (point[4]-3) * 50;
	invalidDice(point[4] - 3);

	// cout << endl << "you got  " << score << "  scores" << endl;    ��Ϣ����Ƶ������ĺ���

	return score;
}
/* ��Ϸ��ʼ�� */
void Referee::gameInit()
{
	char flag = 'y';				//�Ƿ�����ı�־: y continue; n exit.
	Player new_player;				//һ�������
	std::string player_name;		//������������

	cout << "game is starting......" << endl;
	//������Ϸ��
	while (flag == 'y'){                                    
		cout << "Please input a new player's name:" << endl << ">> ";
		cin >> player_name;
		new_player.setName(player_name);
		players.push_back(new_player);
		player_num = players.size();

		cout << "Current player num: " << players.size() << endl;
		cout << "Create a new player? (y or n):" << endl << ">> ";
		cin >> flag;
		cout << endl;
	}
	//��Ϸ����������С��2
	if (player_num < 2)
	{
		cout << "The number of Player is less than 2.";
		exit(0);
	}
	//��ʼ����Ϸ˳��




}
/* ��Ϸ��ʼ */
void Referee::gameStart()
{
	// ������񣺱���win_flag    ����winFlag (����ʽ)
	char win_flag = 'y';            //��ʤ��־
	while (win_flag == 'y'){
		for (int i = 0; i < player_num; i++) {
			for (int j = 0; j < GAME_DICE_NUM; j++) {   //Ϊ��һ�ֵ���Ϸ�߼��� GAME_DICE_NUM ������
				dices[j].setValid(true);
			}

			char flag = 'y';
			int cur_turn_score = 0;    //���ֵ÷�
			int cur_roll_score = 0;   //���ѵ÷�
			cout << "It's [" << players[i].getName() << "]'s turn" << endl;

			cout << "| Enter Roll |" << endl;
			cout << "Only who got more than 300 in Enter Roll can have next roll." << endl;
			rollDice(); 
			displayRollResult();
			cur_roll_score = calculateScore();              //���Ͷ��
			cout << "[" << players[i].getName() << "] got " << cur_roll_score << "  scores" << endl;

			if (cur_roll_score < 300) {      //С��300���޷����
				cout << "Sorry , you are out." << endl;
				continue;
			}
			else if (!isExistValidDice()) {      //��ǰ������������Ч
				cout << "This turn over. Your turn score is" << cur_turn_score << endl;
			}
			else {							//�ɹ����
				cout << "You are in." << endl;
			}
			cur_turn_score += cur_roll_score; 
			
			cur_roll_score = 0;
			cout << "Continue roll?(y or n):" << endl << ">> ";
			cin >> flag;
			while (flag == 'y') {
				rollDice();
				displayRollResult();
				cur_roll_score = calculateScore();
				cout << "[" << players[i].getName() << "] got " << cur_roll_score << "  scores" << endl;
				if (cur_roll_score == 0) {
					cout << "Sorry, you got 0 socre. And your current turn score has been cleared." << endl;
					cur_turn_score = 0; 
					break;
				}
				cur_turn_score += cur_roll_score; 
				cur_roll_score = 0;

				if ((players[i].getScore() + cur_turn_score) >= 3000) {   //ʤ���ж�
					break;
				}

				cout << "Continue roll?(y or n):" << endl << ">> ";
				cin >> flag;
			}
			players[i].setScore(players[i].getScore()+cur_turn_score);

			if (players[i].getScore() >= 3000){
				cout << "We have a winner: [" << players[i].getName() << "]" << endl;
				win_flag = 'n';
				break;
			}
		}
	}
}
/* ��Ϸ���� */
void Referee::gameEnd()
{
}

/* չʾ����Ͷ����� */
void Referee::displayRollResult()
{
	for (int i = 0; i < GAME_DICE_NUM; i++)
	{
		if (dices[i].isValid()) {
			cout << dices[i].getNum() << " ";
		}
	}
	cout << endl;
}

/* ��ǰ�Ƿ������Ч����: true ����, false ������ */
bool Referee::isExistValidDice() {
	for (int i = 0; i < GAME_DICE_NUM; i++)
	{
		if (dices[i].isValid()) {
			return true;
		}
	}

	return false;
}
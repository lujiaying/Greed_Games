#include "greed.h"

using std::endl;
using std::cout;
using std::cin;


/* ���ӵĹ��캯�� */
Dice::Dice(){
	valid = true;
	num = 0;
}
/* ��ȡ��Ч�� */
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
	int point[6] = { 0 };
	int score = 0;
	for (int i = 0; i < 6; i++) {
		if (dices[i].isValid())point[dices[i].getNum()-1] += 1;
	}
	if (point[0] == 6) { 
		score = 3000; invalidDice(6); 
	}
	else if (point[0] < 6 && point[0] >= 3) {
		score += 1000;
		point[0] -= 3;
		invalidDice(3);
	}
	else {}
	if (point[4] > 3){
		score += (point[4]-3) * 50;
		invalidDice(point[4] - 3);
	}
	else if (point[4] < 3){ score += point[4] * 50; invalidDice(point[4]); }
	else{}
	for (int i = 1; i < 6; i++)
	{
		if (point[i] == 3){ 
			score += (i + 1) * 100; 
			invalidDice(3);
		}
	}
	cout << endl << "you got  " << score << "  scores" << endl;
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
		cout << "Please input a new player's name: ";
		cin >> player_name;
		new_player.setName(player_name);
		players.push_back(new_player);
		cout << "Current player num: " << players.size() << endl;
		cout << "Create a new player? (y or n): ";
		cin >> flag;
		cout << endl;
	}
	num = players.size();
	//��Ϸ�������������1
	if (num < 2)
	{
		cout << "The number of Player is less than 2.";
		exit(0);
	}
	//��ʼ����Ϸ˳��




}
/* ��Ϸ��ʼ */
void Referee::gameStart()
{
	char winFlag = 'y';
	while (winFlag == 'y'){
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < 6; j++){   //Ϊ��һ�ֵ���Ϸ�߼�����������
				dices[j].setValid(true);
			}

			char flag = 'y';
			int thisScore = 0;    //���ֵ÷�
			int theScore = 0;   //���ѵ÷�
			cout << "It's " << players[i].getName() << "'s turn" << endl;
			rollDice(); theScore = calculateScore();              //���Ͷ��
			if (theScore < 300)continue;
			thisScore += theScore; theScore = 0;
			cout << "Continue anyway? Please input y or n:";
			cin >> flag;
			while (flag){
				rollDice(); theScore = calculateScore();
				if (theScore == 0){
					thisScore = 0; break;
				}
				thisScore += theScore; theScore = 0;
				if ((players[i].getScore() + thisScore) >= 3000)break;
				cout << "Continue anyway? Please input y or n:";
				cin >> flag;
			}
			players[i].setScore(players[i].getScore()+thisScore);
			if (players[i].getScore() >= 3000){
				cout << "We have a winner:" << players[i].getName() << endl;
				winFlag = 'n';
				break;
			}
		}
	}
}
/* ��Ϸ���� */
void Referee::gameEnd()
{
}
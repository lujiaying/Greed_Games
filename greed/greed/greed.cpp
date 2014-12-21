#include "greed.h"

using std::endl;
using std::cout;
using std::cin;


/* 骰子的构造函数 */
Dice::Dice(){
	valid = true;
	num = 0;
}
/* 获取有效性 */
bool Dice::isValid()
{
	return valid;
}
/* 设置有效性 */
void Dice::setValid(bool v)
{
	valid = v;
}
/* 投掷骰子 */
void Dice::roll(){
	num = rand() % 6 + 1;
}
/* 获取骰子点数 */
int Dice::getNum(){
	return num;
}


/* 玩家的构造函数 */
Player::Player()
{
	score = 0;
}
/* 玩家的构造函数 */
Player::Player(std::string n)
{
	score = 0;
	name = n;
}
/* 设置姓名 */
void Player::setName(std::string n)
{
	name = n;
}
/* 获取姓名 */
std::string Player::getName()
{
	return name;
}
/* 获取分数 */
int Player::getScore()
{
	return score;
}
/* 设置分数 */
void Player::setScore(int s)
{
	score = s;
}


/* 投掷骰子 */
void Referee::rollDice()
{
	for (int i = 0; i < GAME_DICE_NUM; i++)
	{
		dices[i].roll();
	}
}
/* 将得分骰子失效 */
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
/* 计算得分 */
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
/* 游戏初始化 */
void Referee::gameInit()
{
	char flag = 'y';				//是否继续的标志: y continue; n exit.
	Player new_player;				//一个新玩家
	std::string player_name;		//玩家输入的姓名

	cout << "game is starting......" << endl;
	//输入游戏者
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
	//游戏者数量必须大于1
	if (num < 2)
	{
		cout << "The number of Player is less than 2.";
		exit(0);
	}
	//初始化游戏顺序




}
/* 游戏开始 */
void Referee::gameStart()
{
	char winFlag = 'y';
	while (winFlag == 'y'){
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < 6; j++){   //为新一轮的游戏者激活六个骰子
				dices[j].setValid(true);
			}

			char flag = 'y';
			int thisScore = 0;    //本轮得分
			int theScore = 0;   //本把得分
			cout << "It's " << players[i].getName() << "'s turn" << endl;
			rollDice(); theScore = calculateScore();              //入局投掷
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
/* 游戏结束 */
void Referee::gameEnd()
{
}
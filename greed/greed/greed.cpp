#include "greed.h"

using std::endl;
using std::cout;
using std::cin;


/* 骰子的构造函数 */
Dice::Dice(){
	valid = true;
	num = 0;
}
/* 获取有效性: true 有效, false 无效 */
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
/* 将得分骰子的失效个数增加: 增加数为输入参数 */
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
	int point[6] = { 0 };    //存放点数的数组， point[0] = 3 代表1点的骰子有3个。
	int score = 0;
	for (int i = 0; i < 6; i++) {
		if (dices[i].isValid()) {
			point[dices[i].getNum()-1] += 1;
		}
	}
	// 关于点数1的得分统计
	if (point[0] == 6) { 
		score += 3000;
		point[0] -= 6;
		invalidDice(6);			//计算得分后将骰子无效化
	}
	else if (point[0] < 6 && point[0] >= 3) {
		score += 1000;
		point[0] -= 3;
		invalidDice(3);
	}
	score +=  point[0] * 50;
	invalidDice(point[0]);
	
	// 关于3个相同点数的得分统计，需排除点数0
	for (int i = 1; i < 6; i++)
	{
		if (point[i] == 6) {       //考虑6个相同点数的情况
			score += ((i+1)*100) * 2;
			point[i] -= 6;
			invalidDice(6);
		}
		else if (point[i] == 3) {    
			score += (i+1) * 100;
			point[i] -= 3;
			invalidDice(3);
		}
	}

	// 关于点数5的得分统计
	score += point[4] * 50;
	invalidDice(point[4]);

	// cout << endl << "you got  " << score << "  scores" << endl;    信息输出移出功能函数

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
	//游戏者数量不能小于2
	if (player_num < 2)
	{
		cout << "The number of Player is less than 2.";
		exit(0);
	}
	//初始化游戏顺序




}
/* 游戏开始 */
void Referee::gameStart()
{
	// 命名风格：变量win_flag    函数winFlag (骆驼式)
	char win_flag = 'y';            //获胜标志
	char turn_flag = 'y';           //轮标志
	int roll_index = 0;					//投掷把数

	while (win_flag == 'y'){
		for (int i = 0; i < player_num; i++) {
			for (int j = 0; j < GAME_DICE_NUM; j++) {   //为新一轮的游戏者激活 GAME_DICE_NUM 个骰子
				dices[j].setValid(true);
			}
			system("cls");
			turn_flag = 'y';
			int cur_turn_score = 0;    //本轮得分
			int cur_roll_score = 0;   //本把得分
			cout << "It's [" << players[i].getName() << "] turn. Total score is " << players[i].getScore() << "." << endl;
			/**   //代码移入while中
			cout << "| Enter Roll |" << endl;
			cout << "Only who got more than 300 in Enter Roll can have next roll." << endl;
			rollDice(); 
			displayRollResult();
			cur_roll_score = calculateScore();              //入局投掷
			cout << "[" << players[i].getName() << "] got " << cur_roll_score << "  scores" << endl;

			if (cur_roll_score < 300) {      //小于300分无法入局
				cout << "Sorry , you are out." << endl;
				continue;
			}
			else if (!isExistValidDice()) {      //当前所有骰子已无效
				cout << "This turn over. Your turn score is" << cur_turn_score << endl;
			}
			else {							//成功入局
				cout << "You are in." << endl;
			}
			cur_turn_score += cur_roll_score; 
			
			cur_roll_score = 0;
			cout << "Continue roll?(y or n):" << endl << ">> ";
			cin >> flag;
			**/
			while (turn_flag == 'y') {
				cout << "[" << players[i].getName() << "] " << roll_index << "th roll:" << endl;   // [xxx] 1st roll.
				cout << "    ";
				rollDice();
				displayRollResult();
				cur_roll_score = calculateScore();
				cout << "Got " << cur_roll_score << " score." << endl;
				roll_index++;

				if (roll_index == 1) {			//入局投掷
					cout << "| Enter Roll | Only who got more than 300 in Enter Roll can in." << endl;
					if (cur_roll_score < 300) {				//小于300分无法入局
						cout << "Sorry , you are out." << endl;
						cur_turn_score = 0;
						break;
					}
					else {									//成功入局
						cout << "You are in." << endl;
						cur_turn_score += cur_roll_score;
					}
				}
				else {							//非入局投掷
					if (cur_roll_score == 0) {
						cout << "Sorry, you got 0 socre. And your current turn score has been cleared." << endl;
						cur_turn_score = 0;
						break;
					}
					else {
						cout << "You have next roll." << endl;
						cur_turn_score += cur_roll_score;
					}
				}

				if ((players[i].getScore() + cur_turn_score) >= 3000) {   //胜利判断
					break;
				}
				else if (!isExistValidDice()) {		//当前所有骰子已无效
					cout << "All dices has benn calculated." << endl;
					cout << "This turn is over. Your turn score is " << cur_turn_score << endl;
					cin.get();//清屏用
					cur_turn_score = cur_roll_score;
					break;
				}

				cout << "Your turn score is " << cur_turn_score << ". And there're " << getValidDiceNum() << " dices valid." << endl;
				cout << "Continue roll?(y or n):" << endl << ">> ";
				cin >> turn_flag;
			}
			cout << endl;
			cin.get();		// pause
			roll_index = 0;
			players[i].setScore(players[i].getScore()+cur_turn_score);

			if (players[i].getScore() >= 3000) {
				cout << "We have a winner: [" << players[i].getName() << "], and total score is" << players[i].getScore() << endl;
				win_flag = 'n';
				break;
			}
		}
	}
}

/* 游戏结束 */
void Referee::gameEnd()
{
}

/* 展示骰子投掷结果 */
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

/* 当前是否存在有效骰子: true 存在, false 不存在 */
bool Referee::isExistValidDice() {
	for (int i = 0; i < GAME_DICE_NUM; i++)
	{
		if (dices[i].isValid()) {
			return true;
		}
	}
	return false;
}

/* 获得当前剩余有效骰子的数量 */
int Referee::getValidDiceNum()
{
	int valid_num = 0;
	for (int i = 0; i < GAME_DICE_NUM; i++)
	{
		if (dices[i].isValid()) {
			valid_num++;
		}
	}
	return valid_num;
}
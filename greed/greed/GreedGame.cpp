#include <stdlib.h>
#include <string>
#include "GreedGame.h"

using std::string;

/* 骰子的构造函数 */
Dice::Dice(){
	valid = true;
	num = 0;
}

/* 投掷骰子 */
void Dice::roll(){
	num = rand()%6 + 1;
}

/* 获取骰子点数 */
int Dice::getNum(){
	return num;
}

/* 获取骰子是否可用。false代表不可用， treu代表可用*/
bool Dice::isValid(){
	return valid;
}


/* 玩家的构造函数 */
Player::Player(){
	order = 0;
	score = 0;
}

/* 设置玩家名字 */
void Player::setName(string new_name)
{
	name = new_name;
}

/* 获得玩家名字 */
string Player::getName()
{
	return name;
}

/* 设置玩家游戏顺序 */
void Player::setOrder(int game_order)
{
	order = game_order;
}
/* 获得玩家游戏顺序 */
int Player::getOrder()
{
	return order;
}

/* 给玩家加分 */
void Player::addScore(int current_turn_score){
	score += current_turn_score;
}

/* 获得玩家当前的总得分 */
int Player::getScore(){
	return score;
}
#include <stdlib.h>
#include <iostream>
#include "GreedGame.h"

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
	dices = new Dice[dice_num];
	current_score = 0;
	total_score = 0;
}

/* 玩家的析构函数 */
Player::~Player(){
	delete[] dices;
}

/* 投掷当前所有可用的骰子 */
void Player::roll(){
	for (int i = 0; i < dice_num; i++){
		if (dices[i].isValid){
			dices[i].roll();
			std::cout << "dices[" << i << "] roll: " << dices[i].getNum() << std::endl;
		}
	}
}

/* 给玩家本轮得分加分 */
void Player::addCurrentScore(int score){
	current_score += score;
}

/* 给玩家本局总得分加分 */
void Player::addTotaltScore(int score){
	total_score += score;
}

/* 获得玩家本轮得分 */
int Player::getCurrentScore(){
	return current_score;
}

/* 获得玩家本局总得分 */
int Player::getTotalScore(){
	return total_score;
}
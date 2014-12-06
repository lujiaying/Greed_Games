#include <stdlib.h>
#include "GreedGame.h"

Dice::Dice(){
	valid = 1;
	num = 0;
}

/* 投掷骰子 */
int Dice::roll(){
	num = rand()%6 + 1;
	return num;
}

/* 获取骰子点数 */
int Dice::getNum(){
	return num;
}


Player::Player(){
	for (int i = 0; i < 6; i++){
		dices[i] = Dice();
	}
	current_score = 0;
	total_score = 0;
}

/* 投掷当前所有可用的骰子。
返回true代表可继续投掷，返回false代表本轮投掷结束。*/
bool Player::roll(){
	return true;
}
#include <stdlib.h>
#include <iostream>
#include "GreedGame.h"

/* ���ӵĹ��캯�� */
Dice::Dice(){
	valid = true;
	num = 0;
}

/* Ͷ������ */
void Dice::roll(){
	num = rand()%6 + 1;
}

/* ��ȡ���ӵ��� */
int Dice::getNum(){
	return num;
}

/* ��ȡ�����Ƿ���á�false�������ã� treu�������*/
bool Dice::isValid(){
	return valid;
}


/* ��ҵĹ��캯�� */
Player::Player(){
	dices = new Dice[dice_num];
	current_score = 0;
	total_score = 0;
}

/* ��ҵ��������� */
Player::~Player(){
	delete[] dices;
}

/* Ͷ����ǰ���п��õ����� */
void Player::roll(){
	for (int i = 0; i < dice_num; i++){
		if (dices[i].isValid){
			dices[i].roll();
			std::cout << "dices[" << i << "] roll: " << dices[i].getNum() << std::endl;
		}
	}
}

/* ����ұ��ֵ÷ּӷ� */
void Player::addCurrentScore(int score){
	current_score += score;
}

/* ����ұ����ܵ÷ּӷ� */
void Player::addTotaltScore(int score){
	total_score += score;
}

/* �����ұ��ֵ÷� */
int Player::getCurrentScore(){
	return current_score;
}

/* �����ұ����ܵ÷� */
int Player::getTotalScore(){
	return total_score;
}
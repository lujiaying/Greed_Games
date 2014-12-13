#include <stdlib.h>
#include <string>
#include "GreedGame.h"

using std::string;

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
	order = 0;
	score = 0;
}

/* ����������� */
void Player::setName(string new_name)
{
	name = new_name;
}

/* ���������� */
string Player::getName()
{
	return name;
}

/* ���������Ϸ˳�� */
void Player::setOrder(int game_order)
{
	order = game_order;
}
/* ��������Ϸ˳�� */
int Player::getOrder()
{
	return order;
}

/* ����Ҽӷ� */
void Player::addScore(int current_turn_score){
	score += current_turn_score;
}

/* �����ҵ�ǰ���ܵ÷� */
int Player::getScore(){
	return score;
}
#include <stdlib.h>
#include "GreedGame.h"

Dice::Dice(){
	valid = 1;
	num = 0;
}

/* Ͷ������ */
int Dice::roll(){
	num = rand()%6 + 1;
	return num;
}

/* ��ȡ���ӵ��� */
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

/* Ͷ����ǰ���п��õ����ӡ�
����true����ɼ���Ͷ��������false������Ͷ��������*/
bool Player::roll(){
	return true;
}
#include <iostream>
#include <string>
#include <vector>

#ifndef GREED_H
#define GREED_H

#define GAME_DICE_NUM 6

class Dice
{
private:
	bool valid;      // ��Ч��
	int num;         //����
public:
	/* ���캯�� */
	Dice();
	/* ��ȡ��Ч�� */
	bool isValid();
	/* ������Ч�� */
	void setValid(bool);
	/* Ͷ�� */
	void roll();
	/* ��õ��� */
	int getNum();
};

class Player
{
private:
	std::string name;      //�������
	int score;             //��ҵ÷�
public:
	/* ���캯�� */
	Player();
	Player(std::string);
	/* �������� */
	void setName(std::string);
	/* ��ȡ���� */
	std::string getName();
	/* ��ȡ���� */
	int getScore();
	/* ���÷��� */
	void setScore(int);
};

class Referee
{
private:
	Dice dices[GAME_DICE_NUM];      //����
	int num;						//��Ϸ������
	std::vector<Player>  players;     //��Ϸ�� 
public:
	/* ��Ϸ��ʼ�� */
	void gameInit();
	/* ��Ϸ��ʼ */
	void gameStart();
	/* ��Ϸ���� */
	void gameEnd();
	/* roll Dice */
	void rollDice();
	/* ����÷� */
	int calculateScore();
	/* ����������Ч */
	void invalidDice(int);
};

#endif
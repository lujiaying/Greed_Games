#include <iostream>
#include <string>
#include <vector>

#ifndef GREED_H
#define GREED_H

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
	void setValid(bool v);
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
	Player(std::string n);
	/* �������� */
	void setName(std::string n);
	/* ��ȡ���� */
	std::string getName();
	/* ��ȡ���� */
	int getScore();
	/* ���÷��� */
	void setScore(int s);
};

class Referee
{
private:
	Dice d[6];      //����
	int num;
	std::vector<Player>  actor;     //��Ϸ�� 
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
	void invalidDice(int n);
};

#endif
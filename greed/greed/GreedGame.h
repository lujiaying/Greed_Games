#include <string>

#ifndef GREED_H
#define GREED_H

/* ���� */
class Dice{
private:
	int num;    //����
	bool valid;  //�Ƿ���ã�false�������ã�true�������
public:
	/* ���ӵĹ��캯�� */
	Dice();

	/* Ͷ������ */
	void roll();		
	/* ��ȡ���ӵ��� */
	int getNum();
	/* ���������Ƿ���á�false�������ã�true������� */
	void setValid(bool);
	/* ��ȡ�����Ƿ���á�false�������ã� treu������� */
	bool isValid();
};


/* ��� */
class Player{
private:
	std::string name;	//�������
	int order;			//��Ϸ˳��
	int score;			//��Ϸ���ܵ÷�
public:
	/* ��ҵĹ��캯�� */
	Player();

	/* ����������� */
	void setName(std::string);
	/* ���������� */
	std::string getName();
	/* ���������Ϸ˳�� */
	void setOrder(int);
	/* ��������Ϸ˳�� */
	int getOrder();
	/* ����Ҽӷ� */
	void addScore(int);
	/* �����ҵ�ǰ���ܵ÷� */
	int getScore();
};


#endif
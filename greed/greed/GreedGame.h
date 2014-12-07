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
	/* ��ȡ�����Ƿ���á�false�������ã� treu�������*/
	bool isValid();
};


/* ��� */
class Player{
private:
	int dice_num = 6;	//��������
	Dice *dices;		//��̬��������
	int current_score;	//���ֵ÷�
	int total_score;	//������Ϸ���ܵ÷�
public:
	/* ��ҵĹ��캯�� */
	Player();
	/* ��ҵ��������� */
	~Player();

	/* Ͷ����ǰ���п��õ����ӡ�*/
	void roll();
	/* ����ұ��ֵ÷ּӷ� */
	void addCurrentScore(int);
	/* ����ұ����ܵ÷ּӷ� */
	void addTotaltScore(int);
	/* �����ұ��ֵ÷� */
	int getCurrentScore();
	/* �����ұ����ܵ÷� */
	int getTotalScore();
};



/* ��Ϸϵͳ */
class GameSystem{
private:
	int player_num;		//������Ϸ����Ҹ���
	Player *players;	//��̬�������

};


#endif
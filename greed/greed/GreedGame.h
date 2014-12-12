#include <string>

#ifndef GREED_H
#define GREED_H

/* 骰子 */
class Dice{
private:
	int num;    //点数
	bool valid;  //是否可用，false代表不可用，true代表可用
public:
	/* 骰子的构造函数 */
	Dice();

	/* 投掷骰子 */
	void roll();		
	/* 获取骰子点数 */
	int getNum();
	/* 设置骰子是否可用。false代表不可用，true代表可用 */
	void setValid(bool);
	/* 获取骰子是否可用。false代表不可用， treu代表可用 */
	bool isValid();
};


/* 玩家 */
class Player{
private:
	std::string name;	//玩家名字
	int order;			//游戏顺序
	int score;			//游戏的总得分
public:
	/* 玩家的构造函数 */
	Player();

	/* 设置玩家名字 */
	void setName(std::string);
	/* 获得玩家名字 */
	std::string getName();
	/* 设置玩家游戏顺序 */
	void setOrder(int);
	/* 获得玩家游戏顺序 */
	int getOrder();
	/* 给玩家加分 */
	void addScore(int);
	/* 获得玩家当前的总得分 */
	int getScore();
};


#endif
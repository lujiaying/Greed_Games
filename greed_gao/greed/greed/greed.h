#include <iostream>
#include <string>
#include <vector>

#ifndef GREED_H
#define GREED_H

class Dice
{
private:
	bool valid;      // 有效性
	int num;         //点数
public:
	/* 构造函数 */
	Dice();
	/* 获取有效性 */
	bool isValid();
	/* 设置有效性 */
	void setValid(bool v);
	/* 投掷 */
	void roll();
	/* 获得点数 */
	int getNum();
};

class Player
{
private:
	std::string name;      //玩家姓名
	int score;             //玩家得分
public:
	/* 构造函数 */
	Player();
	Player(std::string n);
	/* 设置姓名 */
	void setName(std::string n);
	/* 获取姓名 */
	std::string getName();
	/* 获取分数 */
	int getScore();
	/* 设置分数 */
	void setScore(int s);
};

class Referee
{
private:
	Dice d[6];      //骰子
	int num;
	std::vector<Player>  actor;     //游戏者 
public:
	/* 游戏初始化 */
	void gameInit();
	/* 游戏开始 */
	void gameStart();
	/* 游戏结束 */
	void gameEnd();
	/* roll Dice */
	void rollDice();
	/* 计算得分 */
	int calculateScore();
	/* 将骰子置无效 */
	void invalidDice(int n);
};

#endif
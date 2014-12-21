#include <iostream>
#include <string>
#include <vector>

#ifndef GREED_H
#define GREED_H

#define GAME_DICE_NUM 6

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
	void setValid(bool);
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
	Player(std::string);
	/* 设置姓名 */
	void setName(std::string);
	/* 获取姓名 */
	std::string getName();
	/* 获取分数 */
	int getScore();
	/* 设置分数 */
	void setScore(int);
};

class Referee
{
private:
	Dice dices[GAME_DICE_NUM];      //骰子
	int num;						//游戏者人数
	std::vector<Player>  players;     //游戏者 
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
	void invalidDice(int);
};

#endif
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
	/* 获取骰子是否可用。false代表不可用， treu代表可用*/
	bool isValid();
};


/* 玩家 */
class Player{
private:
	int dice_num = 6;	//骰子数量
	Dice *dices;		//动态骰子数组
	int current_score;	//本轮得分
	int total_score;	//本局游戏的总得分
public:
	/* 玩家的构造函数 */
	Player();
	/* 玩家的析构函数 */
	~Player();

	/* 投掷当前所有可用的骰子。*/
	void roll();
	/* 给玩家本轮得分加分 */
	void addCurrentScore(int);
	/* 给玩家本局总得分加分 */
	void addTotaltScore(int);
	/* 获得玩家本轮得分 */
	int getCurrentScore();
	/* 获得玩家本局总得分 */
	int getTotalScore();
};



/* 游戏系统 */
class GameSystem{
private:
	int player_num;		//本局游戏的玩家个数
	Player *players;	//动态玩家数组

};


#endif
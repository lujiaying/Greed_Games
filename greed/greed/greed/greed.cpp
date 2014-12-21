#include "greed.h"


/* 骰子的构造函数 */
Dice::Dice(){
	valid = true;
	num = 0;
}
/* 获取有效性 */
bool Dice::isValid()
{
	return valid;
}
/* 设置有效性 */
void Dice::setValid(bool v)
{
	valid = v;
}
/* 投掷骰子 */
void Dice::roll(){
	num = rand() % 6 + 1;
}
/* 获取骰子点数 */
int Dice::getNum(){
	return num;
}
/* 构造函数 */
Player::Player()
{
	score = 0;
}
Player::Player(std::string n)
{
	score = 0;
	name = n;
}
/* 设置姓名 */
void Player::setName(std::string n)
{
	name = n;
}
/* 获取姓名 */
std::string Player::getName()
{
	return name;
}
/* 获取分数 */
int Player::getScore()
{
	return score;
}
/* 设置分数 */
void Player::setScore(int s)
{
	score = s;
}

/* 投掷骰子 */
void Referee::rollDice()
{
	for (int i = 0; i < 6; i++)
	{
		d[i].roll();
	}
}
/* 将得分骰子失效 */
void Referee::invalidDice(int n){
	int j = 0;
	for (int i = 0; i < 6; i++){
		if (d[i].isValid()){
			d[i].setValid(false);
			j++;
		}
		if (j == n)break;
	}
}
/* 计算得分 */
int Referee::calculateScore()
{
	int point[6] = { 0 };
	int score=0;
	for (int i = 0; i < 6; i++){
		if (d[i].isValid())point[d[i].getNum()-1] += 1;
	}
	if (point[0] == 6){ score = 3000; invalidDice(6); }
	else if (point[0] < 6 && point[0] >= 3){
		score += 1000;
		point[0] -= 3;
		invalidDice(3);
	}
	else {}
	if (point[4] > 3){
		score += (point[4]-3) * 50;
		invalidDice(point[4] - 3);
	}
	else if (point[4] < 3){ score += point[4] * 50; invalidDice(point[4]); }
	else{}
	for (int i = 1; i < 6; i++)
	{
		if (point[i] == 3){ 
			score += (i + 1) * 100; 
			invalidDice(3);
		}
	}
	std::cout << std::endl << "you got  " << score << "  scores" << std::endl;
	return score;
}
/* 游戏初始化 */
void Referee::gameInit()
{
	char flag = 'y';
	std::string s;
	Player p;
	std::cout << "game is starting......" << std::endl;
	//输入游戏者
	while (flag == 'y'){                                    
		std::cout << "Please input the new player's name:";
		std::cin >> s;
		p.setName(s);
		actor.push_back(p);
		std::cout << "Continue anyway? Please input y or n:";
		std::cin >> flag;
	}
	num = actor.size();
	//游戏者数量必须大于1
	if (num < 2)
	{
		std::cout << "The number of Player is less than 2.";
		exit(0);
	}
	//初始化游戏顺序




}
/* 游戏开始 */
void Referee::gameStart()
{
	char winFlag = 'y';
	while (winFlag == 'y'){
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < 6; j++){   //为新一轮的游戏者激活六个骰子
				d[j].setValid(true);
			}

			char flag = 'y';
			int thisScore = 0;    //本轮得分
			int theScore = 0;   //本把得分
			std::cout << "It's " << actor[i].getName() << "'s turn" << std::endl;
			rollDice(); theScore = calculateScore();              //入局投掷
			if (theScore < 300)continue;
			thisScore += theScore; theScore = 0;
			std::cout << "Continue anyway? Please input y or n:";
			std::cin >> flag;
			while (flag){
				rollDice(); theScore = calculateScore();
				if (theScore == 0){
					thisScore = 0; break;
				}
				thisScore += theScore; theScore = 0;
				if ((actor[i].getScore() + thisScore) >= 3000)break;
				std::cout << "Continue anyway? Please input y or n:";
				std::cin >> flag;
			}
			actor[i].setScore(actor[i].getScore()+thisScore);
			if (actor[i].getScore() >= 3000){
				std::cout << "We have a winner:" << actor[i].getName() << std::endl;
				winFlag = 'n';
				break;
			}
		}
	}
}
/* 游戏结束 */
void Referee::gameEnd()
{
}
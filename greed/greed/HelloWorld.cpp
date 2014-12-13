#include <iostream>
#include "GreedGame.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	/*Dice dice;
	for (int i = 0; i < 10; i++) {
		cout << i+1 << "st roll: " << dice.roll() << endl;
	}*/

	Player player;
	char continue_roll = 'y';
	while (continue_roll != 'n') {
		cout << endl << "type y to continue, n to end: ";
		cin >> continue_roll;
		player.roll();
	}
	getchar();
}
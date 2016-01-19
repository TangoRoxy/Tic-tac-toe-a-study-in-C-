#include <iostream>
using namespace std;
/**
	Tic-tac-toe practice
	Purpose: 2 player tic-tac-toe game
	@author: Tango
	@version: 1.3
 */

char square[9] = {'1','2','3','4','5','6','7','8','9'};

int checkwin();
void drawboard();

int main()
{
	int player = 1;
	int flag, choice;

	char mark;
	do
	{
		drawboard();
		player=(player%2)?1:2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice >= 1 && choice <=9 && square[choice-1] != 'O'
			&& square[choice-1] != 'X')
			square[choice-1] = mark; 
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		flag=checkwin();

		player++;
	}while(flag==-1);
	drawboard();
	if(flag==1)

		cout<<"Player "<<--player<<" win ";
	else
		cout<<"Game draw";

	cin.ignore();
	cin.get();
	return 0;
}

/**
	checkwin: check the game result:
	1 if the current player wins
	0 if it's a draw
	-1 if there's no winner yet
*/

int checkwin()
{
	for (int i=0; i<3; i++)
	{
		if(square[i]==square[i+1]&&square[i+1]==square[i+2])
		return 1;
		if(square[i]==square[i+3]&&square[i+3]==square[i+6])
		return 1;	
	}
	if (square[0]==square[4]&&square[4]==square[8])
	return 1;
	if (square[2]==square[4]&&square[4]==square[6])
	return 1;
	
	for(int i=0; i<9; i++)
	{
		if (!(square[i]=='X'||square[i]=='O'))
		return -1;
	}

	return 0;
}


/**
	draws the board
*/


void drawboard()
{
	system("cls");
	cout << "\nTic Tac Toe\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
	cout << "     |     |     " << endl << endl;
}


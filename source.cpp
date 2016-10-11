//Fergal O'Shea
//2015

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void printBoard(int board[]);
void makeMove(int player, int board[]);
void isGameOver(int turn, int board[]);
void checkMove(int &move);
int switchPlayer(int player);
bool gameOver = false;
int board[9] = {1,2,3,4,5,6,7,8,9};
int turn = 1;
int winner = 1;


int main() {
	int player=2;

	cout << "Let's Play Tic Tac Toe" << endl;
	printBoard(board);

	while (gameOver== false) {

		player = switchPlayer(player);
		makeMove(player, board);
		printBoard(board);

		isGameOver(turn, board);
		turn++;
	}

	if (winner == 0) {
		cout << "It's a draw!" << endl;
	}
	else {
		cout << "Player " << player << " is the winner!" << endl;
	}
	return 0;

}

void printBoard(int board[]) {
	for (int i = 0; i<9; i++) {
		if (board[i] == 10) {
			cout << "X ";
		}
		else if (board[i] == 11) {
			cout << "O ";
		}
		else {
			cout << board[i] << " ";
		}

		if (i % 3 == 2) {
			cout << endl;
		}
	}

}

void makeMove(int player, int board[]) {
	int move=0;

	cout << "player " << player << ", make your move..." << endl;
	cin >> move;
	checkMove(move);

	while (move != board[move-1]) {
		cout << "Invalid move, Please enter a different number, between 1-9"<<endl;
		cin >> move;
		checkMove(move);
	}

	if (player == 1) {
		board[move-1] = 10;
	}
	else {
		board[move-1] = 11;
	}


}

void isGameOver(int turn, int board[]) {

		for (int i = 0; i < 9; i = i + 3) {
			if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
				gameOver = true;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
				gameOver = true;
			}
		}
		if (board[0] == board[4] && board[0] == board[8]) {
			gameOver = true;
		}
		else if (board[2] == board[4] && board[2] == board[6]) {
			gameOver = true;
		}
		if (gameOver == false) {
			if (turn == 9) {
				gameOver = true;
				winner = 0;
			}
		}
}

int switchPlayer(int player) {
	if (player == 1) {
		player = 2;
	}
	else {
		player = 1;
	}

	return player;
}

void checkMove(int &move) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please input a number between 1-9" << endl;
		cin >> move;
	}

}

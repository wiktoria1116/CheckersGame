#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void draw_map(int board[8][8]) {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (i < 3) {
				if (j % 2 == 0) {

					if (i % 2 == 0) {
						board[i][j] = 0;
					}
					else {
						board[i][j] = 2;
					}
				}
				else {
					if (i % 2 == 0) {
						board[i][j] = 2;
					}
					else {
						board[i][j] = 0;
					}
				}
			}
			else if (i >= 3 && i < 5) {
				if (j % 2 == 0) {

					if (i % 2 == 0) {
						board[i][j] = 0;
					}
					else {
						board[i][j] = 1;
					}
				}
				else {
					if (i % 2 == 0) {
						board[i][j] = 1;
					}
					else {
						board[i][j] = 0;
					}
				}

			}
			else {
				if (j % 2 == 0) {

					if (i % 2 == 0) {
						board[i][j] = 0;
					}
					else {
						board[i][j] = 3;
					}
				}
				else {
					if (i % 2 == 0) {
						board[i][j] = 3;
					}
					else {
						board[i][j] = 0;
					}
				}

			}

		} 
		
	}

}
void name(string *name1, string *name2) {
	cout << "Give name 1:  ";
	cin >> *name1;
	cout << "Give name 2:  ";
	cin >> *name2;

}
void enter_place_of_pawn(int *ver, string *hor, int *ver_movement, string *hor_movement) { //hor-horizontally, ver-vertical
	cout << endl;
	cout << " Enter vertical and horizontal coordinate: "; 
	cin >> *ver >> *hor;

	cout << "Enter new vertical and horizontal coordinate: ";
	cin >> *ver_movement >> *hor_movement;

}
int main()
{
	int board[8][8], game_duration = 0, ver, ver_movement, black_or_white;
	bool win = false;
	string name_of_j[10] = { "A", "B", "C", "D", "E", "F", "G", "H" };
	string name1, name2, hor, hor_movement;

	name(&name1, &name2);
	draw_map(board);

	cout << "  ";
	for (int j = 0; j < 8; j++) {
		cout << " " << name_of_j[j];
	}cout << endl;

	cout << "   ";
	for (int j = 0; j < 8; j++) {
		cout << "--";
	}cout << endl;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (j == 0) {
				cout << i << " " << "|";
			}
			if (board[i][j] == 0) {

				if (j != 7) {
					cout << "  ";
				}
				else {
					cout << " ";
				}
			}
			if (board[i][j] == 1) {

				if (j != 7) {
					cout << "  ";
				}
				else {
					cout << " ";
				}
			}
			if (board[i][j] == 2) {

				if (j != 7) {
					cout << "W ";
				}
				else {
					cout << "W";
				}
			}
			if (board[i][j] == 3) {

				if (j != 7) {
					cout << "B ";
				}
				else {
					cout << "B";
				}
			}
			if (j == 7) {
				cout << "|";
			}
			//cout << board[i][j];

		}cout << endl;

	}

	cout << "   ";
	for (int j = 0; j < 8; j++) {
		cout << "--";
	}cout << endl;


	do {
		if (game_duration % 2 == 0) {
			cout << "Gamer 1: " << name1;
		}
		else {
			cout << "Gamer 2: " << name2;
		}

		enter_place_of_pawn(&ver, &hor, &ver_movement, &hor_movement);

		for( int i = 0; i < 8; i++){

			for (int j = 0; j < 8; j++) {

				if ((i == ver) && (hor == name_of_j[j])) {

					if (board[i][j] == 0) {
						system("cls");
						cout << "Something is wrong. White place" << endl;
						exit(0);
					}
					else {
						if (board[i][j] == 2) {
							board[i][j] = 1; //black_or_white = 2 -black pawn
							black_or_white = 2;
						}
						else if (board[i][j] == 3) {
							board[i][j] = 1;
							black_or_white = 2; // white pawn
						}
					}
				}
			}
		
		}
		system("cls");

		cout << "  ";
		for (int j = 0; j < 8; j++) {
			cout << " " << name_of_j[j];
		}cout << endl;

		cout << "   ";
		for (int j = 0; j < 8; j++) {
			cout << "--";
		}cout << endl;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				if (j == 0) {
					cout << i << " " << "|";
				}
				if (board[i][j] == 0) {

					if (j != 7) {
						cout << "  ";
					}
					else {
						cout << " ";
					}
				}
				if (board[i][j] == 1) {

					if (j != 7) {
						cout << "  ";
					}
					else {
						cout << " ";
					}
				}
				if (board[i][j] == 2) {

					if (j != 7) {
						cout << "W ";
					}
					else {
						cout << "W";
					}
				}
				if (board[i][j] == 3) {

					if (j != 7) {
						cout << "B ";
					}
					else {
						cout << "B";
					}
				}
				if (j == 7) {
					cout << "|";
				}
				//cout << board[i][j];

			}cout << endl;

		}

		cout << "   ";
		for (int j = 0; j < 8; j++) {
			cout << "--";
		}cout << endl;

		game_duration++;
	} while (win == true);

		return 0;


}


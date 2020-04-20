#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;
void draw_board(int board[8][8]) {

	char name_of_j[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	cout << "  ";
	for (int j = 0; j < 8; j++) {
		cout << " " << j;
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
					cout << " |";
				}
				else {
					cout << " ";
				}
			}
			if (board[i][j] == 1) {

				if (j != 7) {
					cout << " |";
				}
				else {
					cout << " ";
				}
			}
			if (board[i][j] == 2) {

				if (j != 7) {
					cout << "W|";
				}
				else {
					cout << "W";
				}
			}
			if (board[i][j] == 3) {

				if (j != 7) {
					cout << "B|";
				}
				else {
					cout << "B";
				}
			}
			if (board[i][j] == 4) {

				if (j != 7) {
					cout << "w|";
				}
				else {
					cout << "w";
				}
			}
			if (board[i][j] == 5) {

				if (j != 7) {
					cout << "b|";
				}
				else {
					cout << "b";
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


}

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

void enter_place_of_pawn(int &ver, int &hor, int &ver_movement, int &hor_movement) { //hor-horizontally, ver-vertical
	char hor1, hor_movement1;

	cout << endl;
	cout << " Enter vertical and horizontal coordinate: "; 
	cin >> ver;
	cin>> hor;
	//int horizontal  = hor = (int)hor1;

	cout << "Enter new vertical and horizontal coordinate: ";
	cin >> ver_movement;
	cin >> hor_movement;
    //int horizonlat_movement = hor_movement = (int)hor_movement1;

}

void move_pawn( int ver, int hor, int board[8][8], int ver_movement, int hor_movement) {

				if (board[ver][hor] == 0) {
	    			cout << "Something is wrong. White place" << endl;
				}
				else if (board[ver][hor] == 4) {
					if ((board[ver_movement - 1][hor_movement - 1] == 3) && (board[ver_movement][hor_movement] == 1)) {
						board[ver][hor] = 1;
						board[ver_movement][hor_movement] = 4;
						board[ver_movement - 1][hor_movement - 1] = 1;

					}
					else if ((board[ver_movement - 1][hor_movement + 1] == 3) && (board[ver_movement][hor_movement] == 1)) {
						board[ver][hor] = 1;
						board[ver_movement][hor_movement] = 4;
						board[ver_movement - 1][hor_movement + 1] = 1;

					}
					else {
						board[ver][hor] = 1;
						board[ver_movement][hor_movement] = 2;
					}

				}
				else if (board[ver][hor] == 5) {
					if ((board[ver_movement - 1][hor_movement - 1] == 3) && (board[ver_movement][hor_movement] == 1)) {
						board[ver][hor] = 1;
						board[ver_movement][hor_movement] = 5;
						board[ver_movement - 1][hor_movement - 1] = 1;

					}
					else if ((board[ver_movement - 1][hor_movement + 1] == 3) && (board[ver_movement][hor_movement] == 1)) {
						board[ver][hor] = 1;
						board[ver_movement][hor_movement] = 5;
						board[ver_movement - 1][hor_movement + 1] = 1;

					}
					else {
						board[ver][hor] = 1;
						board[ver_movement][hor_movement] = 2;
					}

				}
				else {
					if (board[ver][hor] == 2) {
						if ((board[ver_movement - 1][hor_movement - 1] == 3) && (ver - ver_movement != 1) && (ver - ver_movement != -1) && (hor - hor_movement != 1) && (hor - hor_movement != -1)) {
							board[ver][hor] = 1;
							board[ver_movement][hor_movement] = 2;
							board[ver_movement - 1][hor_movement - 1] = 1;

						}
						else if ((board[ver_movement - 1][hor_movement + 1] == 3) && (board[ver_movement][hor_movement] == 1) && (ver - ver_movement != 1) && (ver - ver_movement != -1) && (hor - hor_movement != 1) && (hor - hor_movement != -1)) {
							board[ver][hor] = 1;
							board[ver_movement][hor_movement] = 2;
							board[ver_movement - 1][hor_movement + 1] = 1;

						}
						else if ( ver_movement == 7) {
							board[ver_movement][hor_movement] = 4;
						}
						else {
							board[ver][hor] = 1;
							board[ver_movement][hor_movement] = 2;
						}
					}
					else if (board[ver][hor] == 3) {

						if ((board[ver_movement - 1][hor_movement - 1] == 2) && (board[ver_movement][hor_movement] == 1) && (ver - ver_movement != 1) && (ver - ver_movement != -1) && (hor - hor_movement != 1) && (hor - hor_movement != -1)) {
							board[ver][hor] = 1;
							board[ver_movement][hor_movement] = 3;
							board[ver_movement - 1][hor_movement - 1] = 1;

						}
						else if ((board[ver_movement - 1][hor_movement + 1] == 2) && (board[ver_movement][hor_movement] == 1) && (ver - ver_movement != 1) && (ver - ver_movement != -1) && (hor - hor_movement != 1) && (hor - hor_movement != -1)) {
							board[ver][hor] = 1;
							board[ver_movement][hor_movement] = 3;
							board[ver_movement - 1][hor_movement + 1] = 1;

						}
						else if (ver_movement == 0) {
							board[ver_movement][hor_movement] = 5;
						}
						else {
							board[ver][hor] = 1;
							board[ver_movement][hor_movement] = 3;
						}	
					}
				}

	}

void maps(int board[8][8], int ver, int ver_movement, int hor, int hor_movement, int black_or_white) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i == ver_movement) && (j == hor_movement)) {

				if (board[i][j] == 0) {
					system("cls");
					cout << "Something is wrong. White place" << endl;
					exit(0);
				}
				else {
					if (black_or_white == 2) {
						if ((ver - ver_movement == -1) && (hor - hor_movement == 1) || (ver - ver_movement == -1) && (hor - hor_movement == -1)) {
							board[i][j] = 2;
						}
						else {
							system("cls");
							cout << "WRONG!";
							exit(0);
						}

					}
					else if (black_or_white == 3) {
						//board[i][j] = 3;
						if ((ver - ver_movement == 1) && (hor - hor_movement == -1) || (ver - ver_movement == 1) && (hor - hor_movement == 1)) {
							board[i][j] = 3;
						}
						else {
							system("cls");
							cout << "WRONG!";
							exit(0);
						}
					}

				}

			}
		}
	}
}

int main()
{
	int board[8][8], game_duration = 1, ver, ver_movement, hor, hor_movement;
	bool win = false;
	string name1, name2;
	
	name(&name1, &name2);
	
	draw_map(board);
	draw_board(board);

	do {

		if (game_duration % 2 == 0) {
			cout << "Gamer 1: " << name1;
			cout << endl << endl;
		}
		else {
			cout << "Gamer 2: " << name2;
			cout << endl << endl;
		}
		enter_place_of_pawn(ver, hor, ver_movement, hor_movement);
		move_pawn(ver, hor, board, ver_movement, hor_movement);
		cout << endl;
		draw_board(board);

		game_duration++;

	} while (win==false);


}


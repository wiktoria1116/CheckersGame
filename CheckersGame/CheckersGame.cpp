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
void name(string name1, string name2) {
	cout << "Give name:  ";
	cin >> name1;
	cout << "Give name:  ";
	cin >> name2;

}
int main()
{
	int board[8][8];
	string name_of_j[10] = { "A", "B", "C", "D", "E", "F", "G", "H" };
	string name1, name2;

	//name(name1,name2);
	draw_map(board);

	cout << "  ";
	for (int j = 0; j < 8; j++) {
		cout << " "<<name_of_j[j];
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

		
	return 0;


}


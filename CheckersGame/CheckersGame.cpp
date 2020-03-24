// CheckersGame.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

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
			if (i % 2 == 0) {
				if (j % 2==0) {
					board[i][j] = 2;
				}
			}
		}
	}
}

int main()
{
	int board[8][8];
	draw_map(board);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout<<board[i][j];
		}
		cout << endl;
	}

	return 0;


}


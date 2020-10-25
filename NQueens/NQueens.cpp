#include <iostream>
#include "NQueens.h"
using namespace std;

Queens::Queens(int _numfQueens) : NumOfQueens(_numfQueens) {

	chessTable.resize(NumOfQueens);
	for (auto& chessRow : chessTable) {
		chessRow.resize(NumOfQueens);
	}
}

void Queens::solve() {
	if (setQueens(0)) {
		printQueens();
	}
	else {
		cout << "No solution" << endl;
	}
}

bool Queens::setQueens(int col) {
	if (col == NumOfQueens) return true;
	for (int row = 0; row < NumOfQueens; ++row) {
		if (isPlaceValid(row, col)) {
			chessTable[row][col] = 1;
			if (setQueens(col + 1)) {
				return true;
			}
			chessTable[row][col] = 0;
		}
	}
	return false;
}

bool Queens::isPlaceValid(int row, int col) const {
	for (int i = 0; i < col; i++) {
		if (chessTable[row][i] == 1) {
			return false;
		}
	}
	for (int i = row, j = col; j >= 0 && i >= 0; i--, j--) {
		if (chessTable[i][j] == 1) {
			return false;
		}
	}

	for (int i = row, j = col; i < NumOfQueens && j >= 0; i++, j--) {
		if (chessTable[i][j] == 1) {
			return false;
		}
	}
	return true;
}

void Queens::printQueens() const {
	for (size_t i = 0; i < chessTable.size(); i++) {
		for (size_t j = 0; j < chessTable.size(); j++) {
			if (chessTable[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
}
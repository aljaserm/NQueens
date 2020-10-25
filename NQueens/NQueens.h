#pragma once
#include<vector>
using std::vector;

class Queens {
	vector<vector<int>> chessTable;
	int NumOfQueens = 0;
public:
	Queens(int _numOfQueens);
	void solve();

private:
	bool setQueens(int col);
	bool isPlaceValid(int row, int col) const;
	void printQueens() const;
};
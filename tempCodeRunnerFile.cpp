#include <iostream>
using namespace std;
bool board[4][6][2] = { false, };
#define blue 0
#define green 1
#define start 2
int gb[4] = { 0,1,3,2 };
int score = 0, nblock = 0;
void DeleteCol(int col, int mode) {
	int i, j;
	for (i = col; i >= 0; i--) {
		for (j = 0; j < 4; j++) {
			if (i < 2)
				board[j][i][mode] = false;
			else
				board[j][i][mode] = board[j][i - 1][mode];
		}
	}
}
void Check(int col, int mode) {
	int i;
	for (i = 0; i < 4; i++) {
		if (!board[i][col][mode]) return;
	}
	score++;
	DeleteCol(col, mode);
}
int Stop(int x, int mode) {
	int col;
	for (col = 0; col < 5; col++) {
		if (!board[x][col][mode] && board[x][col + 1][mode])
			return col;
	}
	return 5;
}
void Move(int t, int x, int mode) {
	int i;
	int stop = Stop(x, mode);
	if (t == 3) {
		int stop2 = Stop(x + 1, mode);
		stop = (stop < stop2 ? stop : stop2);
		board[x + 1][stop][mode] = true;
	}
	board[x][stop][mode] = true;
	if (stop < start) DeleteCol(5, mode);
	else Check(stop, mode);
	if (t == 2) Move(1, x, mode);
}
int main() {
	int N, i, j, k;
	int t, x, y;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> t >> x >> y;
		Move(t, x, blue);
		Move(gb[t], y, green);
	}

	for (i = 0; i < 4; i++) {
		for (j = 2; j < 6; j++) {
			for (k = 0; k < 2; k++) {
				if (board[i][j][k]) nblock++;
			}
		}
	}
	cout << score << '\n' << nblock << '\n';
	return 0;
}

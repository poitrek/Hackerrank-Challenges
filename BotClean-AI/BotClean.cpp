#include <iostream>
#include <vector>
using namespace std;

// Manhattan distance between points
int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

string next_move(int botx, int boty, vector<string> &board) {
	// If the robot is standing on the dirty cell
	if (board[boty][botx] == 'd')
		return "CLEAN";
	// Greedy algorithm - nearest point first

	// Nearest point's coordinates and distance
	int nrst_pos[2] = { 5,5 };
	int nrst_dist = 10;
	//int nrst_dist = dist(botx, boty, 5, 5);

	// Find the nearest point
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == 'd') {
				int dis = dist(botx, boty, j, i);
				if (dis < nrst_dist) {
					nrst_dist = dis;
					nrst_pos[0] = j;
					nrst_pos[1] = i;
				}
			}
		}

	//cout << "Nearest pt: " << nrst_pos[0] << ", " << nrst_pos[1] << endl;
	//cout << "Nearest dist = " << nrst_dist << endl;
	// Head the proper direction
	int dx = nrst_pos[0] - botx;
	int dy = nrst_pos[1] - boty;
	if (dx != 0)
		if (dx > 0)
			return "RIGHT";
		else
			return "LEFT";
	else
		if (dy > 0)
			return "DOWN";
		else
			return "UP";
}

int main() {
	int pos[2];
	vector<string> board;
	cin >> pos[0] >> pos[1];
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		board.push_back(s);
	}
	cout << next_move(pos[1], pos[0], board) << endl;
	return 0;
}
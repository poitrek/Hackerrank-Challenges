/* https://www.hackerrank.com/challenges/3d-surface-area/problem
*/
#include <iostream>
#include <vector>

using namespace std;

// Method 1
// count growths/descents of adjacent & not yet visited pillars of each pillar 
// Faster by a constant factor
int calc_area(const vector<vector<int>> &A, int H, int W) {
	int area = 0;
	for (int i = 0; i < H+1; i++)
		for (int j = 0; j < W+1; j++) {
			int A_ij = A[i][j];
			area += abs(A_ij - A[i+1][j]) + abs(A_ij - A[i][j+1]);
		}
	area += 2 * H * W;
	return area;
}

// Method 2
// for each pillar, count (only) descents in height to its adjacent pillars 
int calc_area2(const vector<vector<int>> &A, int H, int W) {
	int area = 2 * H * W;
	for (int i = 1; i < H+1; i++)
		for (int j = 1; j < W+1; j++) {
			int A_ij = A[i][j];
			area += max(0, A_ij - A[i-1][j]);
			area += max(0, A_ij - A[i+1][j]);
			area += max(0, A_ij - A[i][j-1]);
			area += max(0, A_ij - A[i][j+1]);
		}
	return area;
}

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<int>> A(H+2, vector<int>(W+2, 0));
	for (int i = 1; i < H+1; i++)
		for (int j = 1; j < W+1; j++)
			cin >> A[i][j];
	cout << calc_area(A, H, W) << endl;
	return 0;
}

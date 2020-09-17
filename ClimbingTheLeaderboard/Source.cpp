/*

Challenge - Climbing The Leaderboard

Difficulty: Medium

Problem:
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

*/

#include <iostream>
#include <vector>

using namespace std;

// Operator to print a vector
ostream& operator << (ostream& o, vector<int>& vec) {
	o << "vector[";
	for (int i = 1; i < vec.size(); i++)
		o << vec[i] << ", ";
	o << vec.back() << "]";
	return o;
}


int main() {
	int n, m;
	vector<int> scores(1, 0), alice;
	cin >> n;
	cin >> scores[0];
	for (int i = 0; i < n-1; i++) {
		int x;
		cin >> x;
		// Fill score array without repeating the values
		if (x != scores.back())
			scores.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		alice.push_back(x);
	}
	cout << "Scores: " << scores << endl;
	cout << "Alice: " << alice << endl;

	return 0;
}
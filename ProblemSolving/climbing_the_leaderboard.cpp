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
template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(ost, "\n"));
	return ost;
}

// Solution with complexity O(n+m), where
// n - size of scores
// m - size of alice
vector<int> ranks(vector<int> &scores, vector<int> &alice) {
	// Guard element at front
	scores.insert(scores.begin(), INT32_MAX);
	vector<int> ranks;
	auto sc_it = scores.rbegin();
	int sc_idx = scores.size() - 1;
	for (auto al_it = alice.begin(); al_it != alice.end(); ++al_it) {
		while (*al_it > *sc_it) {
			++sc_it;
			sc_idx--;
		}
		if (*al_it == *sc_it) {
			ranks.push_back(sc_idx);
		}
		else {
			ranks.push_back(sc_idx + 1);
		}
	}
	return ranks;
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
	vector<int> aliceRanks = ranks(scores, alice);
	cout << aliceRanks << endl;
	return 0;
}
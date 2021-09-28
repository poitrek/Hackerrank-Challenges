/* The Grid Search
https://www.hackerrank.com/challenges/the-grid-search/problem
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool is_matched(const vector<string> &G, const vector<string> &P,
				int R, int C, int r, int c) {
	for (int i = 0; i < R-r+1; i++) {
		for (int j = 0; j < C-c+1; j++) {
			bool match = true;
			for (int k = 0; k < r && match; k++) {
				for (int l = 0; l < c && match; l++) {
					if (P[k][l] != G[i+k][j+l]) {
						match = false;
					}
				}
			}
			if (match) {
				// A pattern match is found
				return true;
			}
		}
	}
	// No match of the pattern is found
	return false;	
}

// Probably more efficient

bool is_matched2(const vector<string> &G, const vector<string> &P,
				int R, int C, int r, int c) {
	for (int i = 0; i < R-r+1; i++) {
		size_t pos = G[i].find(P[0]);
		while (pos != string::npos) {
			// Check match of all other rows
			bool match = true;
			for (int j = 1; j < r; j++) {
				if (G[i+j].substr(pos, c) != P[j]) {
					match = false;
					break;
				}
			}
			if (match)
				return true;
			pos = G[i].find(P[0], pos+1);
		}
	}
	return false;
}

bool input_and_solve() {
	int R, C, r, c;
	vector<string> G, P;
	cin >> R >> C;
	string s_temp;
	for (int i = 0; i < R; i++) {
		cin >> s_temp;
		G.push_back(s_temp);
	}
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s_temp;
		P.push_back(s_temp);
	}
	return is_matched2(G, P, R, C, r, c);
}

int main(){
	int t;
	cin >> t;
	vector<bool> results(t, 0);
	for (int i = 0; i < t; i++)
		results[i] = input_and_solve();
	for (bool r : results)
		cout << (r ? "YES" : "NO") << endl;
	return 0;
}

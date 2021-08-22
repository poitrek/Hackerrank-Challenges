/*
https://www.hackerrank.com/challenges/lisa-workbook/problem
*/

#include <iostream>
#include <vector>

using namespace std;

// O(n) solution, where n - number of chapters (n_problems.size())

int count_special_problems(const vector<int> &n_problems, int prob_per_page) {
	if (prob_per_page == 1) {
		// All problems in the first chapter only
		return n_problems.front();
	}
	int special_cnt = 0;
	int start_page = 1;
	for (int _n_problems : n_problems) {
		
		// Number of the last page of the current chapter
		int stop_page = start_page + int((_n_problems-1) / prob_per_page);
		
		if (stop_page <= _n_problems) {
			// There are (1 or 2) special problems
			if (start_page > 1 && start_page % (prob_per_page - 1) == 1 &&
					!(stop_page % prob_per_page == 0 && stop_page == _n_problems)) {
				special_cnt += 2;
			}
			else {
				special_cnt += 1;
			}
		}
        start_page = stop_page + 1;
	}
	return special_cnt;
}

int main() {
	int n, k;
	vector<int> arr;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	// n = 10, k = 5;
	// arr = {3, 8, 15, 11, 14, 1, 9, 2, 24, 31};
	cout << count_special_problems(arr, k) << endl;
	return 0;
}

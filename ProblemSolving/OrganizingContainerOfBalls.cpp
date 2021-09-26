/* Organizing Containers of Balls
https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void increment_entry(map<int, int> &_map, int key) {
	if (_map.find(key) != _map.end()) {
		_map[key]++;
	}
	else {
		_map.insert(pair<int, int>(key, 1));
	}
}

// Time complexity: O(n*(n+log(n))) = O(n^2)

bool input_and_solve() {
	int n;
	cin >> n;
	vector<vector<int>> container(n, vector<int>(n, 0));
	// total num. of balls in each container
	vector<int> container_total(n, 0);
	// how many containers have k total balls (k - key)
	map<int, int> container_total_cnt;
	// total num. of balls of each type
	vector<int> ball_type_total(n, 0);
	// how many ball types have k total balls
	map<int, int> ball_type_total_cnt;
	for (int i = 0; i < n; i++) {
		int cont_total = 0;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			container[i][j] = x;
			cont_total += x;
			ball_type_total[j] += x;
		}
		container_total[i] = cont_total;
		// increment the number of containers that have this many balls
		increment_entry(container_total_cnt, cont_total);
	}
	for (int btt : ball_type_total) {
		increment_entry(ball_type_total_cnt, btt);
	}
	// for (int i = 0; i < n; i++)
	// 	cout << "balls in container " << i << ": " << container_total[i] << endl;
	// for (int i = 0; i < n; i++)
	// 	cout << "balls of type " << i << ": " << ball_type_total[i] << endl;
	if (ball_type_total_cnt.size() != container_total_cnt.size())
		return false;
	for (auto bttc_it = ball_type_total_cnt.begin(), ctc_it = container_total_cnt.begin();
		bttc_it != ball_type_total_cnt.end(); ++bttc_it, ++ctc_it) {
		// cout << ctc_it->second << " containers have " << ctc_it->first << " balls" << endl;
		// cout << bttc_it->second << " ball types have " << bttc_it->first << " balls" << endl;
		if (bttc_it->first != ctc_it->first || bttc_it->second != ctc_it->second)
			return false;
	}
	return true;
}

int main(){
	int q;
	cin >> q;
	vector<bool> results(q, 0);
	for (int i = 0; i < q; i++) {
		results[i] = input_and_solve();
	}
	for (bool r : results) {
		cout << (r ? "Possible" : "Impossible") << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n, q;
	cin >> n;
	unordered_map<string, int> string_cnt;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (string_cnt.find(s) == string_cnt.end()) {
			string_cnt[s] = 1;
		}
		else {
			string_cnt[s]++;
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		string q;
		cin >> q;
		if (string_cnt.find(q) == string_cnt.end())
			cout << 0 << endl;
		else
			cout << string_cnt[q] << endl;
	}
	return 0;
}

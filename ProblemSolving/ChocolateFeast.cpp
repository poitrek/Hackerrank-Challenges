#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	vector<int> results(t,0);
	for (auto it = results.begin(); it != results.end(); ++it) {
		// n - initial money, c - cost of a bar, m - extra bar exchange
		int n, c, m;
		cin >> n >> c >> m;
		// first amount of bars - initial money / cost for one
		int new_bars (n / c);
		int cur_bars = new_bars;
		int tot_bars = new_bars;
		while (new_bars > 0) {
			// obtain new extra amount
			new_bars = int(cur_bars / m);
			tot_bars += new_bars;
			cur_bars = new_bars + cur_bars % m;
		}
		*it = tot_bars;
	}
	for (int r : results) {
		cout << r << endl;
	}
	return 0;
}

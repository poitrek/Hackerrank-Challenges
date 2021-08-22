/* "Service Lane" - Finding minimum value in array range*/

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
	for (T e : v) ost << e << endl;
	return ost;
}

typedef pair<int, int> pint;

const int MIN_LANE_WIDTH = 1;

// O(N*T) time complexity
// Can be done in O(N+T) time

vector<int> max_vehicle_width(const vector<int> &width, const vector<pint> &cases) {
	vector<int> result;
	for (pint c : cases) {
		int min_width = width[c.first];
		for (int i = c.first; i <= c.second; i++) {
			int w = width[i];
			if (w == MIN_LANE_WIDTH) {
				min_width = MIN_LANE_WIDTH;
				break;
			}
			else {
				min_width = min(min_width, w);
			}
		}
		result.push_back(min_width);
	}
	return result;
}


int main(){
	int n, t;
	cin >> n >> t;
	vector<int> width;
	vector<pint> cases;
	for (int i = 0; i < n; i++) {
		int w; cin >> w;
		width.push_back(w);
	}
	for (int i = 0; i < t; i++) {
		int f, s; cin >> f >> s;
		cases.emplace_back(f, s);
	}
	cout << max_vehicle_width(width, cases) << endl;
	return 0;
}

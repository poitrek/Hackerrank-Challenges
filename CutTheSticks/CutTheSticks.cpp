#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(ost, " "));
	return ost;
}


// solution 1. O(n^2) complexity, not the best
vector<int> solve(vector<int> arr) {
	vector<int> lengths;
	size_t arsize = arr.size();
	while (arsize > 0) {
		lengths.push_back(arsize);
		int min_el = *min_element(arr.begin(), arr.end());
		vector<int>::iterator it = arr.begin();
		while (it != arr.end()) {
			*it -= min_el;
			if (*it == 0) {
				it = arr.erase(it);
			}
			else
				++it;
		}
		arsize = arr.size();
	}
	return lengths;
}


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int a : solve(arr))
		cout << a << endl;
	return 0;
}
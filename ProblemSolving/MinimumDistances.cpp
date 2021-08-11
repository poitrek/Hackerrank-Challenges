
/*
The distance between two array values is the number of indices between them. Given a, 
find the minimum distance between any pair of equal elements in the array. If no such 
value exists, return -1.
Example:
a = [3, 2, 1, 2, 3]
There are two matching pairs of values: 3 and 2. The indices of the 3's are i=0 and j=4, 
so their distance is d[i,j]=|4-0|=4. The indices of the 2's are i=1 and j=3, so their distance
is d[i,j]=|3-1|=2. The minimum distance is 2.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// O(n*log(n)) time, O(n) space 
// O(n^2) pessimistic time

int minimum_dist(const vector<int> &a) {
	// default value
	int min_dist = a.size();
	map<int, int> last_pos;
	for (int i = 0; i < a.size(); i++) {
		int a_i = a[i];
		// get the last position of value a_i
		map<int, int>::iterator it = last_pos.find(a_i);
		// no position yet, add to map
		if (it == last_pos.end()) {
			last_pos[a_i] = i;
		}
		// calculate the distance, update last position
		else {
			int dist = i - last_pos[a_i];
			if (dist < min_dist)
				min_dist = dist;
			last_pos[a_i] = i;
		}
	}
	if (min_dist == a.size())
		min_dist = -1;
	return min_dist;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << minimum_dist(a) << endl;
	return 0;
}

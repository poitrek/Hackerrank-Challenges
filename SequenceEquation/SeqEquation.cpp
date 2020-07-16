
/*
Challenge: Divisible Sum Pairs
Difficulty: Easy
Problem:
Given a sequence of n integers, p(1), p(2),..., p(n) where each element distinct and satisfies
1 <= p(x) <= n. For each x, where 1 <= x <= n, find any integer y such that p(p(y)) = x and print
the value of y on a new line.
*/

#include <iostream>
#include <vector>

using namespace std;

// Template structure for an array (vector) that indexes values from 1
template <typename T>
struct ArrayFrom1 {
	ArrayFrom1(size_t size, const T t) {
		arr.clear();
		arr.insert(arr.begin(), size, t);
	}
	T& operator [](int idx) {
		return arr[idx - 1];
	}
private:
	vector<T> arr;
};

/*
Remarks:
- This solution doesn't need new structure to comfortably index elements
from 1. We can just allocate a container of (n+1) elements and ignore
the value at [0].
- Since index [] operator has complexity O(n), the implementation might be 
more time efficient using: a list with pointers to elements that the inverse
sequence returns at given indexes OR hashing tables/dictionaries
*/

int main() {
	// Input number of elements in the sequence
	int n;
	cin >> n;
	// Initialize already the inverse sequence to p. Such that for every x,
	ArrayFrom1<int> q(n, 0);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		q[x] = i;
	}
	/*cout << "q = p^-1:" << endl;
	for (int i = 1; i <= n; i++)
		cout << q[i] << " ";
	cout << endl;
	cout << "q * q:" << endl;*/
	for (int i = 1; i <= n; i++)
		cout << q[q[i]] << endl;
	return 0;
}
/*
https://www.hackerrank.com/challenges/cut-the-sticks/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <map>
#include "BST.hpp"
using namespace std;

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(ost, " "));
	return ost;
}

template<typename T, typename U>
std::ostream& operator << (std::ostream& ost, const std::pair<T, U> p) {
	ost << "(" << p.first << ", " << p.second << ")";
	return ost;
}


// solution I - naive
// O(n^2) complexity
vector<int> solve(vector<int> arr) {
	vector<int> lengths;
	size_t arsize = arr.size();
	while (arsize > 0) {
		lengths.push_back(arsize);
		// get the shortest stick
		int min_el = *min_element(arr.begin(), arr.end());
		vector<int>::iterator it = arr.begin();
		// shorten each stick
		// if length=0, remove from array
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

// solution II - sort first, then count neighbour differences
// O(n*logn) complexity

template<typename T>
void quicksort_range(vector<T>& v, int low, int high) {
	if (low < high) {
		int pivot = v[high];
		int i = low;
		for (int j = low; j < high; j++) {
			if (v[j] < pivot) {
				int h = v[j]; v[j] = v[i]; v[i] = h;
				i++;
			}
		}
		int h = v[high]; v[high] = v[i]; v[i] = h;
		quicksort_range(v, low, i - 1);
		quicksort_range(v, i + 1, high);
	}
}

template<typename T>
void quicksort(vector<T> &v) {
	quicksort_range(v, 0, v.size() - 1);
}

vector<int> solve2(vector<int> arr) {
	quicksort(arr);	
	vector<int> stick_counts;
	int rem_count = arr.size();
	stick_counts.push_back(rem_count);
	rem_count--;
	for (auto it = arr.begin(); it != std::prev(arr.end()); ++it, rem_count--) {
		if (*it != *(it + 1)) {
			stick_counts.push_back(rem_count);
		}
	}
	return stick_counts;
}

// solution III - store array values in BST
// O(n*logn) complexity
vector<int> solve3(vector<int> arr) {
	// Make BST
	BSTNode<int> root(arr.front());
	for (auto it = arr.begin() + 1; it != arr.end(); ++it)
		root.add(*it);
	// Init vector of sticks counts
	vector<int> stick_counts;
	int rem_count = arr.size();
	for (pair<int, int> p : root.to_sorted()) {
		stick_counts.push_back(rem_count);
		rem_count -= p.second;
	}
	return stick_counts;
}

void test_bst_1() {
	// Create sample tree from value list
	BSTNode<int> root(3);
	vector<int> values = { 5, 2, 2, 1, 6, 4, 1, 4, 6, 2, 4 };
	for (int i : values)
		root.add(i);
	// List BST values in order, with counts
	auto sorted_v = root.to_sorted();
	for (auto p : sorted_v) {
		cout << p << " ";
	}
	cout << endl;
}

// solution IV - analogous to solution III, but using standard-library tree map
vector<int> solve4(vector<int> arr) {
	std::map<int, int> length_cnt;
	// Fill the map of length counts
	for (int a : arr) {
		if (length_cnt.find(a) == length_cnt.end())
			length_cnt.emplace(a, 1);
		else
			length_cnt[a]++;
	}
	// Init vector of sticks counts
	vector<int> stick_counts;
	int rem_count = arr.size();
	for (pair<int, int> p : length_cnt) {
		stick_counts.push_back(rem_count);
		rem_count -= p.second;
	}
	return stick_counts;
}

int main() {
	//test_bst_1();
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int a : solve3(arr))
		cout << a << endl;
	return 0;
}
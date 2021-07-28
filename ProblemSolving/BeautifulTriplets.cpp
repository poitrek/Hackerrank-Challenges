#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

void print_arr(const vector<pair<int,int>> &arr) {
	for (pair<int,int> p : arr){
		cout << "(" << p.first << ", " << p.second << ") ";
	}
	cout << endl;
}

/* First solution, slower. Uses sequencial container (vector) for 
sequence elements */
int count_triplets(const vector<pair<int,int>> &arr, int d) {
	int i = 0;
	int count = 0;
	while (true) {
		int i_tr2, i_tr3;
		// 2nd expected element
		int tr2 = arr[i].first + d;
		// 3rd expected element
		int tr3 = tr2 + d;
		// 3rd element exceeds sequence -> stop 
		if (tr3 > arr.back().first)
			break;
		int j = i+1;
		while (arr[j].first < tr2)
			j++;
		if (arr[j].first == tr2){
			i_tr2 = j;
			while (arr[j].first < tr3)
				j++;
			if (arr[j].first == tr3){
				// A triple is found
				i_tr3 = j;
				count += arr[i].second * arr[i_tr2].second * arr[i_tr3].second;
			}
		}
		i++;
	}
	return count;
}

/* Faster solution. Uses a tree map to store elements of the sequence*/
int count_triplets_2(const map<int, int> &nums, int d) {
	int cnt = 0;
	int _2d = 2*d;
	// For each distinct sequence element
	for (pair<int,int> n : nums){
		auto n_d = nums.find(n.first + d);
		auto n_2d = nums.find(n.first + _2d);
		// Check if n+d and n+2d are present in the sequence too
		if (n_d != nums.end() && n_2d != nums.end())
			cnt += n.second * n_d->second * n_2d->second;
	}
	return cnt;
}

void solve_1(){
	int n, d;
	cin >> n >> d;
	int num1, num2, cnt = 1;
	vector<pair<int, int>> arr;
	cin >> num1;
	for (int i = 0; i < n-1; i++) {
		cin >> num2;
		if (num2 != num1) {
			arr.push_back(pair<int,int>(num1, cnt));
			cnt = 0;
			num1 = num2;
		}
		cnt++;
	}
	arr.push_back(pair<int,int>(num1, cnt));
	// print_arr(arr);
	cout << count_triplets(arr, d) << endl;
}

void solve_2(){
	int n, d;
	cin >> n >> d;
	// Use std::map (binary search tree) to store elements
	std::map<int, int> nums;
	int num1, num2, cnt = 1;
	cin >> num1;
	for (int i = 0; i < n-1; i++) {
		cin >> num2;
		if (num2 != num1) {
			nums.insert(pair<int, int>(num1, cnt));
			cnt = 0;
			num1 = num2;
		}
		cnt++;
	}
	nums.insert(pair<int, int>(num1, cnt));
	cout << count_triplets_2(nums, d) << endl;
}

int main(){
	solve_2();
	return 0;
}

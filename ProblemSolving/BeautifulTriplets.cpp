#include <iostream>
#include <vector>

using namespace std;

void print_arr(const vector<pair<int,int>> &arr) {
	for (pair<int,int> p : arr){
		cout << "(" << p.first << ", " << p.second << ") ";
	}
	cout << endl;
}

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

int main(){
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
	return 0;
}

/*https://www.hackerrank.com/challenges/absolute-permutation/problem
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Proved remark: an absolute permutation (n, k) is possible
if and only if n=2*m*k for some number m.*/

// Time complexity:
// O(n) pessimistic
// O(1) optimistic

vector<int> absolute_permutation(int n, int k) {
	if (k == 0) {
		vector<int> abs_perm;
		for (int i = 1; i <= n; i++)
			abs_perm.push_back(i);
		return abs_perm;
	}
	else if (n % (2 * k) != 0) {
		return vector<int> {-1};
	}
	else {
		vector<int> abs_perm;
		for (int offset = 0; offset < n; offset += 2*k) {
			for (int i = offset+k+1; i <= offset+2*k; i++) {
				abs_perm.push_back(i);
			}
			for (int i = offset+1; i <= offset+k; i++) {
				abs_perm.push_back(i);
			}
		}
		return abs_perm;
	}
}

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
	for (T e : v) ost << e << " ";
	return ost;
}

int main(){
	int t;
	cin >> t;
	vector<vector<int>> result(t, vector<int>());
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		result[i] = absolute_permutation(n, k);
	}
	for (vector<int>& r : result)
		cout << r << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// a1 a2 a3 a4 a5 a6 a7
// rot(3)
// a4 a5 a6 a7 a1 a2 a3

vector<int> leftRot(vector<int>& vec, int n, int d) {
	vector<int> rotv;
	for (int i = 0; i < n; i++)
		rotv.push_back(vec[(i + d) % n]);
	return rotv;
}

int main2()
{
	int n, d;
	vector<int> vec;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		vec.push_back(x);
	}
	vector<int> rotVec = leftRot(vec, n, d);
	for (int r : rotVec)
		cout << r << " ";
	return 0;
}

// Shorter solution, working while handling input
int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> rotvec(n, 0);
	int x;
	for (int i = n - d; i < 2* n - d; i++) {
		cin >> x;
		rotvec[i % n] = x;
	}
	for (int r : rotvec)
		cout << r << " ";
	return 0;
}

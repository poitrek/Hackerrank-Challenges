#include <iostream>
#include <string>

using namespace std;
typedef unsigned long long ulong;
const char token = 'a';

int countCharacter(const string &s, const char token) {
	int cnt{ 0 };
	for (char c : s)
		cnt += (c == token);
	return cnt;
}

ulong countRepetitions(string s, ulong n) {
	return countCharacter(s, token) * (n / s.size()) + countCharacter(s.substr(0, n % s.size()), token);
}

int main() {
	string s;
	ulong n;
	cin >> s >> n;
	cout << countRepetitions(s, n);
	return 0;
}
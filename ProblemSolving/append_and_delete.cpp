#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool conversionPossible(const string& s, const string& t, int k) {
	int minSize = min(s.size(), t.size());
	// Find the length of the longest common prefix of s and t
	int cmnLen = 0;
	if (minSize > 0) {
		while (s[cmnLen] == t[cmnLen] && cmnLen < minSize)
			cmnLen++;
	}
	// minimum operations needed to convert s to t
	int minOperations = s.size() + t.size() - 2 * cmnLen;
	return (k >= minOperations + 2 * cmnLen) || (k >= minOperations && (k - minOperations) % 2 == 0);
}

int main()
{
	string s, t;
	int k;
	cin >> s >> t >> k;
	if (conversionPossible(s, t, k))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

// Solution: we are iterating through all steps denoted by
// proper letters. New valley can be counted if and only
// if the previous step was 'U' (UP) and the current level is 0.
int countValleys(string steps) {
	int level = 0;
	int valleys = 0;
	for (char s : steps)
		if (s == 'U') {
			level++;
			if (level == 0)
				valleys++;
		}
		else
			level--;
	return valleys;
}

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	cout << countValleys(s);
	return 0;
}
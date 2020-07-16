#include <iostream>
#include <vector>

using namespace std;

// The simple implementation, for fixed number of categories
void countBirdsSimple() {
	int n;
	cin >> n;
	// Array of birds counts
	int bCnt[5];
	for (int i = 0; i < 5; i++)
		bCnt[i] = 0;

	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		++bCnt[x - 1];
	}
	int bMax = 0;
	for (int i = 1; i < 5; i++)
		if (bCnt[i] > bCnt[bMax])
			bMax = i;
	// Correction for the id
	bMax = bMax + 1;
	cout << bMax;
}


int main()
{
	countBirdsSimple();
	return 0;
}
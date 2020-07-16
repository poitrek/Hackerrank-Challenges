#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// My problem solution
// Uses an unordered map to count appearance of every sock color
int sockMerchant(vector<int>& socks) {
	unordered_map<int, int> colorCount;
	// Count socks for each color with the map
	for (int s : socks) {
		if (colorCount.find(s) == colorCount.end())
			colorCount[s] = 1;
		else
			colorCount[s]++;
	}
	int sumOfPairs = 0;
	// Count available pairs by dividing each color count by two, without remainder
	for (pair<int, int> cc : colorCount) {
		sumOfPairs += cc.second / 2;
	}
	return sumOfPairs;
}

// Problem solution from other user
// Uses unordered SET
// Checks for every sock if there exists an unpaired sock of that color,
// if so, increment number of pairs and remove the sock color from the set
int sockMerchant2(vector<int>& socks) {
	int pairs{ 0 };
	unordered_set<int> sockColor;
	for (int s : socks) {
		if (sockColor.find(s) == sockColor.end())
			sockColor.insert(s);
		else {
			pairs++;
			sockColor.erase(s);
		}		
	}
	return pairs;
}


int main()
{
	int n;
	cin >> n;
	vector<int> socks(n, 0);
	for (int i = 0; i < n; i++)
		cin >> socks[i];
	cout << sockMerchant2(socks);
	return 0;
}
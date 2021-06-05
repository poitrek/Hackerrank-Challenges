#include <iostream>
#include <unordered_map>

using namespace std;

// Basic method, stores numbers counts in a simple array
int pickNumbers(vector<int> &a) {
	vector<int> numbers( 100, 0 );
	for (int k : a) {
		numbers[k]++;
		numbers[k - 1]++;
	}
	int maxnum = 0;
	for (int n : numbers)
		if (n > maxnum)
			maxnum = n;
	return maxnum;
}


// More sophisticated method, store numbers in unordered/ordered map
int pickNumbers2(vector<int> &a) {
	unordered_map<int, int> numbers;
	// Count appearance of all numbers
	for (int k : a) {
		// If the key hasn't been found yet
		if (numbers.find(k) == numbers.end())
			// Set 1 as this is the first presence in the array
			numbers[k] = 1;
		else
			// Otherwise increment exisiting count of this number
			numbers[k]++;
	}
	// To be completed
	return 0;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << pickNumbers(a);
	return 0;
}

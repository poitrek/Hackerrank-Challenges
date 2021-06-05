// DivisibleSumPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Challenge: Divisible Sum Pairs
Difficulty: Easy
Problem:
Given an array of integers ar = [ar0, ar1,..., arN] and a positive integer k,
find and print the number pairs (i, j) such that i < j and ar[i] + ar[j] is 
divisible by k.

Input format:
n k	[n - length of array ar]
ar[0] ar[1] ... ar[n-1]
*/


#include <iostream>
#include <vector>

using namespace std;

// Solution, simple
void sumPairs()
{
	// Handle input
	int n, k;
	cin >> n >> k;
	vector<int> ar(n, 0);
	for (auto it = ar.begin(); it != ar.end(); it++)
		cin >> *it;

	// Main loop
	int counter{ 0 };
	for (int i = 0; i < n - 1; i++)
	{
		int ar_i = ar[i];
		for (int j = i + 1; j < n; j++)
			if ((ar_i + ar[j]) % k == 0)
				++counter;
	}
	cout << counter;
}

// Solution, optimized
/* This solution counts how many times every remainder
modulo k appeared in the array, then for those pairs
that sum up to k, calculates how many times they can be
picked from the array.
*/
void sumPairsOptimized()
{
	int n, k;
	cin >> n >> k;
	vector<int> ar(n, 0);
	// Counts of remainders modulo k
	vector<int> modK(k, 0);
	for (auto it = ar.begin(); it != ar.end(); it++) {
		cin >> *it;
		// Increment counter of proper remainder
		modK[*it % k]++;
	}
	int counter{ 0 };
	// For the numbers that are divisible by k
	//for (int m : modK)
	//	cout << m << " ";
	//cout << endl;
	counter += modK[0] * (modK[0] - 1) / 2;
	// For every supplementary pair of remainders count the number
	// of combinations they can be returned from the array
	for (int i = 1; i <= (k - 1) / 2; i++) {
		counter += modK[i] * modK[k - i];
	}
	// If k is even
	if (k % 2 == 0)
	{
		int mid = modK[k / 2];
		counter += mid * (mid - 1) / 2;
	}
	cout << counter;
}

// k = 7
// 0 1 2 3 4 5 6
//   
// k = 8
// 0 1 2 3 4 5 6 7
// - @ # $ % $ # @

int main()
{
	sumPairsOptimized();
	//sumPairs();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// https://www.hackerrank.com/challenges/strange-code/problem

#include <iostream>
#include <cmath>
using namespace std;

// O(1) time complexity (reverse function to the counter)

long long counter_value(long long t) {
	int run = floor(log2(double(t+2)/3.0));
	// return 9 * pow(2, run-1) - t;
	return (long long)(3 * (pow(2, run+1) - 1)) - t + 1;
}

long long run(long long t) {
	return floor(log2(double(t+2)/3.0));
}

int main(){
	long long t;
	cin >> t;
	cout << counter_value(t) << endl;
	// for (int i = 1; i < 50; i++)
	// 	cout << counter_value(i) << " ";
	return 0;
}

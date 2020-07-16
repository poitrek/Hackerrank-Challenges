#ifndef _DEBUG
#define DEBUG(x)
#else
#define DEBUG(x) do { std::cerr << x; } while (0)
#endif // !_DEBUG

/*
Challenge - Between Two Sets

Difficulty: Easy

Problem:

There are two arrays of integers: A and B. Find the number of integers x such that:
 - x is divisible by every element of A
 - every element of B is divisible by x

 For example, for arrays A = [2, 4], B = [48, 72, 144] there are 3 such numbers:
 4, 8, 12  (4, 8, and 12 are divisible by 2 and 4, and 48, 72, 144 are divisible by them)

 Input format:
 n m
 a[]
 b[]

 n - number of elements in a, m - number of elements in b
 a, b - arrays of integers

 Constraints:
 1 <= n, m <= 10
 1 <= a[i], b[j] <= 100

 Output format:
 x

 x - number of numbers satisfying given conditions

*/

/*
SOLUTION:

1. Find the Greatest Common Divisor of all elements of B - bGCD
2. Find the Lowest Common Multiple of all elements of A - aLCM
3. Count the number of multiples of aLCM that divide evenly bGCD
   - number of natural divisors of bGCD/aLCM

Time complexity - O(n log(n)) (why?)

Notes:

1) If at least one element in A is not divisible by at least one element in B,
then there are 0 numbers satysfying conditions.
Similarly, if at least one element of A is greater than any element of B, then
the answer is 0.


*/

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;


// Operator to print a vector
ostream& operator << (ostream& o, vector<int> & vec) {
	o << "vector[";
	for (int i = 1; i < vec.size(); i++)
		o << vec[i] << ", ";
	o << vec.back() << "]";
	return o;
}

// Returns the Greatest Common Divisor of two numbers, Euclid's algorithm
int GCD(int a, int b) {
	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;
	return a;
}

// Returns the GCD of all numbers in a vector

// Faster implementation ?

int GCD(vector<int> vec) {
	int gcd{ vec[0] };
	for (int i = 1; i < vec.size(); i++)
		gcd = GCD(gcd, vec[i]);
	return gcd;
}

// Returns the Lowest Common Multiple of two numbers
int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

// Return the LCM of all elements in a vector
// Faster implementation ?
int LCM(vector<int> vec) {
	int lcm{ vec[0] };
	for (int i = 1; i < vec.size(); i++)
		lcm = LCM(lcm, vec[i]);
	return lcm;
}


int countDivisors(int n) {
	if (n == 1)
		return 1;
	int k;
	int counter = 0;
	for (k = 1; k * k < n; k++)
		if (n % k == 0)
			counter += 2;
	// When n is a square of an integer
	if (k * k == n)
		counter += 1;
	return counter;
}

// Returns the number of integers that satisfy the problem conditions
int getTotalX(vector<int> &a, vector<int> &b) {

	// Check if any element of a is greater than the minimum of b
	int minb = b.front();
	for (int kb : b)
		if (kb < minb)
			minb = kb;
	for (int ka : a)
		if (ka > minb)
			return 0;

	// Lowest Common Multiple of a
	int aLCM = LCM(a);
	// Greatest Common Divisor of b
	int bGCD = GCD(b);
	//DEBUG("LCM of a: " + to_string(aLCM) + "\n");
	//DEBUG("GCD of b: " + to_string(bGCD) + "\n");

	// If bGCD still doesn't divide evenly aLCM
	if (bGCD % aLCM != 0)
		return 0;
	else {
		return countDivisors(bGCD / aLCM);
	}

}


int main() {
	//std::cout << "3 + 3 equals " << 3 + 3 << std::endl;
	//DEBUG("This is sample debug output.");

	//for (int i = 1; i < 20; i++)
	//	cout << i << " -> " << countDivisors(i) << endl;

	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0), b(m, 0);
	for (auto it = a.begin(); it != a.end(); it++)
		cin >> *it;
	for (auto it = b.begin(); it != b.end(); it++)
		cin >> *it;

	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	cout << "Total x: ";
	cout << getTotalX(a, b);

	return 0;
}

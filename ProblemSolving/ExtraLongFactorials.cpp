#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <math.h>
using namespace std;

class BigInt {
	static int baseLength;
	// Will be of form 10^m
	static int base;

	vector<int> digits;
public:
	BigInt(string s) {
		// Split string of digits into segments containing baseLength digits each
		// Eg. "13299438329072484", baseLength=3
		// 01 234 567  89 10  11 12 13  14 15 16
		// 13 299 438  32 9   0  7  2   4  8  4
		int slen(s.length());
		int s_div = int(slen / baseLength);
		int s_rem = slen % baseLength;
		for (int i = 1; i <= s_div; i++) {
			digits.push_back(stoi(s.substr(slen - i * baseLength, baseLength)));
		}
		if (s_rem > 0)
			digits.push_back(stoi(s.substr(0, s_rem)));
	}
	BigInt(int n) {
		do {
			digits.push_back(n % base);
			n = n / base;
		} while (n != 0);
	}
	BigInt() {

	}
	void print(bool pretty = false) {
		// Print first digit
		vector<int>::reverse_iterator it = digits.rbegin();
		if (it != digits.rend())
			cout << *it;
		if (pretty) cout << " ";
		it++;
		// Print other digits, use leading zeros
		while (it != digits.rend()) {
			cout << setw(BigInt::baseLength) << setfill('0') << *it;
			if (pretty) cout << " ";
			it++;
		}
		cout << endl;
	}

	void add(BigInt b) {
		int carry = 0;
	}

	BigInt operator+(BigInt& b) {
		int aLength = this->digits.size();
		int bLength = b.digits.size();
		vector<int> rDigits;
		// Assign pointers to longer and shorter sequence of digits
		vector<int>* maxDigits, * minDigits;
		if (aLength >= bLength) {
			maxDigits = &this->digits;
			minDigits = &b.digits;
		}
		else {
			maxDigits = &b.digits;
			minDigits = &this->digits;
		}
		// Additional most significant digits
		maxDigits->push_back(0);
		minDigits->push_back(0);
		rDigits = *maxDigits;
		int carry = 0;
		int i = 0;
		while (i < minDigits->size()) {
			int newDigit = rDigits[i] + (*minDigits)[i] + carry;
			if (newDigit >= base) {
				newDigit -= base;
				carry = 1;
			}
			else
				carry = 0;
			rDigits[i] = newDigit;
			i++;
		}
		while (carry != 0) {
			int newDigit = rDigits[i] + carry;
			if (newDigit >= base) {
				newDigit -= base;
				carry = 1;
			}
			else
				carry = 0;
			rDigits[i] = newDigit;
			i++;
		}
		// If the most significant digit is zero, remove it
		if (rDigits.back() == 0)
			rDigits.pop_back();
		minDigits->pop_back();
		maxDigits->pop_back();
		BigInt result;
		result.digits = rDigits;
		return result;
	}

	BigInt operator *(BigInt& b) {
		int tLength = this->digits.size();
		int bLength = b.digits.size();
		vector<BigInt> terms;
		for (int i = 0; i < bLength; i++) {
			BigInt term;
			// Insert trailing zeros
			term.digits.assign(i, 0);
			int carry = 0;
			for (int j = 0; j < tLength; j++) {
				int product = b.digits[i] * this->digits[j] + carry;
				term.digits.push_back(product % base);
				carry = product / base;
			}
			if (carry != 0)
				term.digits.push_back(carry);
			terms.push_back(term);
		}
		BigInt result("0");
		for (BigInt t : terms)
			result = result + t;
		return result;
	}

	BigInt pow(int k) {
		BigInt p(1);
		for (int i = 0; i < k; i++)
			p = p * *this;
		return p;
	}


};

int BigInt::baseLength = 4;
int BigInt::base = int(std::pow(10, BigInt::baseLength));

BigInt fact(int n) {
	BigInt p(1);
	for (int i = 2; i <= n; i++) {
		BigInt s(i);
		p = p * s;
	}
	return p;
}

int main()
{
	BigInt n1("348258074784538959012740238743829473473472894714748274034734");
	BigInt n2("4535436748258074789012740238743829473473472894714766453444827455034734");
	//int n = 40;
	auto start = chrono::high_resolution_clock::now();
	//BigInt n12 = n1 * n2;
	BigInt a("1072348917814345");
	BigInt aa = a.pow(60);
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	//n12.print();
	aa.print();
	cout << "Calculation time: " << duration.count() << " ms" << endl;
	return 0;
}
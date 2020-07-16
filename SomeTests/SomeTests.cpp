// SomeTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


void test_vector() {
	int arr[] = { 3, 5, 9, 12, 10 };
	vector<int> vec(arr, arr + 5);
	try
	{
		for (int i = 0; i < 8; i++)
			cout << vec.at(i) << endl;
	}
	catch (const std::out_of_range & ex)
	{
		cout << "Out of range exception occured: " << ex.what() << endl;
	}
	catch (const std::exception & ex)
	{
		cout << "Another exception: " << ex.what() << endl;
	}

}

void test_xor() {
	// XOR operator ^
	int a = 13; // 001101
	int b = 34; // 100010
	cout << (a ^ b) << endl;
}

void test_power2() {
	// Left shift operator - multiplication by a power of 2
	cout << "Test '<<' operator - left shift" << endl;
	static constexpr int pow2[] = {
		1 << 0, 1 << 1, 1 << 2, 1 << 3
	};
	for (int i = 0; i < 4; i++)
		cout << pow2[i] << "+";
	cout << endl;
	cout << "1 << 5: " << (1 << 5) << endl;
	cout << "2 << 5: " << (2 << 5) << endl;
	cout << "3 << 4: " << (3 << 4) << endl;
	cout << "1 << 20: " << (1 << 20) << endl;
	cout << "enter n: ";
	int n; cin >> n;
	cout << "2 ^ " << n << " = " << (1 << n) << endl;
}

void test_vector2() {
	vector<int> a;
	int n = 10;
	a.insert(a.begin(), size_t(n), 0);
}

int main()
{
	test_vector2();
	//test_power2();
	//test_xor();
	cout << "Program ended";
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

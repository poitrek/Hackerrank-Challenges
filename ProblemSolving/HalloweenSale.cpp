#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// solution in O(1)

int how_many_products(int p, int d, int m, int s) {
	// q - number of first products whose prices decrease 
	int q (ceil(double(p - m) / d));
	double d_2 = d * 0.5;
	// total cost of the first q products
	int sum_q (q * (p - (q - 1) * d_2));
	// if the budget doesn't exceed total cost of decreasing prices
	// quadratic inequality
	if (s <= sum_q) {
		double delta = pow(d_2 + p, 2.0) - 2 * d * s;
		return floor((d_2 + p - sqrt(delta)) / d);
	}
	// otherwise - linear inequality
	else {
		return floor(double(s + q*(m - p + (q - 1) * d_2)) / m);
	}
}

// solution in /Omega(s) - linear or better

int how_many_products_2(int p, int d, int m, int s) {
	int cnt = 0;
	while (s >= 0)
	{
		s -= max(p - cnt * d, m);
		cnt++;
	}
	return --cnt;
}

int main(){
	int p, d, m, s;
	cin >> p >> d >> m >> s;
	// p = 20, d = 3, m = 6, s = 85;
	// vector<int> ss = {300, 400, 500, 600, 700, 800, 900};
	// for (int i : ss){
	// 	cout << how_many_products(p, d, m, i) << " ~ ";
	// 	cout << how_many_products_2(p, d, m, i) << endl;
	// }
	cout << how_many_products(p, d, m, s) << endl;
	return 0;
}

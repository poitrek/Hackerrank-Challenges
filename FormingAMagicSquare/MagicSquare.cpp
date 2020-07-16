#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Checks if a 3x3 array of ints is a magic square

bool isMagicSquare(int A[][3]) {
	if (A[1][1] != 5)
		return false;
	int sums[] = {
		A[0][0] + A[0][1] + A[0][2], A[1][0] + A[1][1] + A[1][2], A[2][0] + A[2][1] + A[2][2],
		A[0][0] + A[1][0] + A[2][0], A[0][1] + A[1][1] + A[2][1], A[0][2] + A[1][2] + A[2][2],
		A[0][0] + A[1][1] + A[2][2], A[2][0] + A[1][1] + A[0][2]
	};
	for (int i = 0; i < 8; i++)
		if (sums[i] != 15)
			return false;
	return true;
}

void printSquare(int A[][3]) {
	printf("%d %d %d\n%d %d %d\n%d %d %d\n", A[0][0], A[0][1], A[0][2], A[1][0], A[1][1], A[1][2], A[2][0], A[2][1], A[2][2]);
}

// A class to handle 3x3 squares and operations on them
class square3x3 {
public:
	int arr[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	square3x3(int nums[]) {
		int k = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				arr[i][j] = nums[k];
				k++;
			}
	}

	// Copy constructor
	square3x3(const square3x3& sq) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				this->arr[i][j] = sq.arr[i][j];
	}

	bool isMagic() {
		if (arr[1][1] != 5)
			return false;
		int sums[] = {
			arr[0][0] + arr[0][1] + arr[0][2], arr[1][0] + arr[1][1] + arr[1][2], arr[2][0] + arr[2][1] + arr[2][2],
			arr[0][0] + arr[1][0] + arr[2][0], arr[0][1] + arr[1][1] + arr[2][1], arr[0][2] + arr[1][2] + arr[2][2],
			arr[0][0] + arr[1][1] + arr[2][2], arr[2][0] + arr[1][1] + arr[0][2]
		};
		for (int i = 0; i < 8; i++)
			if (sums[i] != 15)
				return false;
		return true;
	}

	// Calculates the absolute difference cost between this square and another
	int absolute(square3x3 sq) {
		int sum = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				sum += abs(this->arr[i][j] - sq.arr[i][j]);
		return sum;
	}

	// Flips square values horizontally
	void flip() {
		for (int i = 0; i < 3; i++) {
			int help = arr[0][i];
			arr[0][i] = arr[2][i];
			arr[2][i] = help;
		}
	}

	// Rotates square values clockwise by 90 degrees
	// implemented manually
	void rotate() {
		int c1 = arr[0][0];
		int e1 = arr[0][1];
		arr[0][0] = arr[2][0];
		arr[0][1] = arr[1][0];
		arr[2][0] = arr[2][2];
		arr[1][0] = arr[2][1];
		arr[2][2] = arr[0][2];
		arr[2][1] = arr[1][2];
		arr[0][2] = c1;
		arr[1][2] = e1;
	}

	// Generate all 8 possible orientations of this square
	// combined of rotating and flipping
	vector<square3x3> generateOrientations() {
		vector<square3x3> vec;
		square3x3 buff(*this);
		vec.push_back(buff);
		for (int i = 0; i < 3; i++) {
			buff.rotate();
			vec.push_back(buff);
		}
		buff.flip();
		vec.push_back(buff);
		for (int i = 0; i < 3; i++) {
			buff.rotate();
			vec.push_back(buff);
		}
		return vec;
	}

	void print() {
		printf("3x3 square:\n%d %d %d\n%d %d %d\n%d %d %d\n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], 
			arr[1][1], arr[1][2], arr[2][0], arr[2][1], arr[2][2]);
	}

};

// Finds the minimum cost of turning given square to one of magic squares
int minimumCost(square3x3& sqr) {
	int arr0[] = { 6, 7, 2, 1, 5 ,9, 8, 3, 4 };
	square3x3 magic0(arr0);
	// Cost turning to default magic square
	int minCost = sqr.absolute(magic0);
	for (square3x3 msq : magic0.generateOrientations()) {
		minCost = fmin(minCost, sqr.absolute(msq));
	}
	return minCost;
}


int main()
{
	int arr[9];
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	square3x3 s(arr);
	cout << minimumCost(s);

	//int arr0[] = { 6, 7, 2, 1, 5 ,9, 8, 3, 4 };
	//int arr1[] = { 4, 9, 2, 3, 5, 7, 8, 1, 5 };
	//int arr2[] = { 4, 8, 2, 4, 5, 7, 6, 1, 6 };
	//square3x3 magic0(arr0);
	//square3x3 sq2(arr1);
	//cout << "Input square:" << endl;
	//sq2.print();

	//cout << "Minimum cost: " << minimumCost(sq2) << endl;
	//cout << isMagicSquare(arr1);
	//cout << sq1.absolute(sq2);
	/*for (square3x3 sq : magic0.generateOrientations()) {
		sq.print();
		cout << "Absolute cost: " << sq2.absolute(sq) << endl;
	}*/
	return 0;
}
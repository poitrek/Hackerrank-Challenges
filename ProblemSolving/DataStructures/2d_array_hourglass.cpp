#include <iostream>
#include <vector>

using namespace std;


void arrayHourglass()
{
	// Initialize array and handle input
	vector<vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	}

	int maxhg;
	maxhg = arr[0][0] + arr[0][1] + arr[0][2] +
		arr[1][1] + arr[2][0] + arr[2][1] + arr[2][2];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int hourglass = arr[i][j] + arr[i][j+1] + arr[i][j+2] +
				arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
			if (hourglass > maxhg)
				maxhg = hourglass;
		}
	cout << maxhg;
}


int main()
{
	arrayHourglass();
	return 0;
}
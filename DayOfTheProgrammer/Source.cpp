#include <iostream>
#include <vector>

using namespace std;

void dayOfProgrammer() {
	int y;
	cin >> y;
	int d, m;
	if (y > 1918) {
		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
			m = 9;
			d = 12;
		}
		else {
			m = 9;
			d = 13;
		}
	}
	else if (y < 1918) {
		if (y % 4 == 0) {
			m = 9;
			d = 12;
		}
		else {
			m = 9;
			d = 13;
		}
	}
	else {
		m = 9;
		d = 26;
	}
	printf("%0*d.%0*d.%d", 2, d, 2, m, y);
}

int main()
{
	dayOfProgrammer();	
	return 0;
}
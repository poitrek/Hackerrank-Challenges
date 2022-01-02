/*
https://www.hackerrank.com/challenges/bomber-man/problem
Level: medium
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<vector<char>> v2c;
typedef pair<int, int> pint;

template<typename T>
void update(vector<vector<T>> &arr, T(*fun)(T)) {
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[i].size(); j++)
			arr[i][j] = fun(arr[i][j]);
}

void to_precise_grid(v2c &grid) {
	update<char>(grid, [](char x)->char {
		return (x == 'O') ? 3 : 0;
	});
}

void to_simple_grid(v2c &grid) {
	update<char>(grid, [](char x)->char {
		return (x == 0) ? '.' : 'O';
	});
}

void next(v2c &grid, int state) {
	// Grid consisting only of 1-sec. & 3-sec. bombs
	if (state == 0) {
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[i].size(); j++) {
				// Decrease bomb timer
				if (grid[i][j] != 0 && grid[i][j] != 1)
					grid[i][j]--;
				else if (grid[i][j] == 1) {
					// Detonate the bomb
					for (pint pos : {
						pint(i, j), pint(i-1, j), pint(i, j-1)
					}) {
						if (pos.first >= 0 && pos.second >= 0)
							grid[pos.first][pos.second] = 0;
					}
					for (pint pos : {
						pint(i+1, j), pint(i, j+1)
					}) {
						if (pos.first < grid.size() && pos.second < grid[i].size() &&
							grid[pos.first][pos.second] != 1)
							grid[pos.first][pos.second] = 0;
					}
				}
			}
	}
	// Grid consisting only of empty cells & 2-sec. bombs
	else {
		update<char>(grid, [](char x)->char {
			return (x == 0) ? 3 : x-1;
		});
	}
}

void simulate(v2c &grid, int n_steps) {
	to_precise_grid(grid);
	for (int i = 0; i < n_steps; i++) {
		next(grid, i % 2);
	}
	to_simple_grid(grid);
}

void simulate_fast(v2c &grid, int n_steps) {
	if (n_steps <= 2) {
		simulate(grid, n_steps);
	}
	else {
		simulate(grid, (n_steps+1)%4+3);
	}
}

void print_grid(const v2c &grid) {
	for (vector<char> row : grid) {
		for (char c : row)
			cout << c;
		cout << endl;
	}
}

void run() {
	int r, c, n;
	cin >> r >> c >> n;
	v2c grid(r, vector<char>(c, '.'));
	cin.get();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			grid[i][j] = char(cin.get());
		}
		cin.get();
	}
	simulate_fast(grid, n);
	print_grid(grid);
}

int main(){
	run();
	return 0;
}

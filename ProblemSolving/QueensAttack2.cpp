/* Queen's Attack II
https://www.hackerrank.com/challenges/queens-attack-2/problem
*/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

typedef pair<int, int> pint;

// Solution: O(k) time complexity (k - number of obstacles)

/* Base line class. Contains initial point,
current limits, and methods for checking
inclusion of a point and updating the limits*/
class line {
protected:
	// origin of the line
	pint p0;
	// limits of the line defined by obstacles
	pint limits;
public:
	line(pint p0, int board_size) : p0(p0) {}
	// checks if point p lies on the line
	virtual bool lies(pint p) = 0;
	// update limits according to the obstacle
	virtual void update_limit(pint obst) {
		if (obst.first < p0.first && obst.first > limits.first) {
			limits.first = obst.first;
		}
		if (obst.first > p0.first && obst.first < limits.second) {
			limits.second = obst.first;
		}
	}
	pint get_limits() {
		return limits;
	}
};
typedef shared_ptr<line> line_ptr;

class l_horizontal : public line {
public:
	l_horizontal(pint p0, int board_size) : line(p0, board_size){
		limits = pint(0, board_size+1);
	}
	bool lies(pint p) {
		return p.second == p0.second;
	}
};

class l_vertical : public line {
public:
	l_vertical(pint p0, int board_size) : line(p0, board_size){
		limits = pint(0, board_size+1);
	}
	bool lies(pint p) {
		return p.first == p0.first;
	}
	void update_limit(pint obst) {
		if (obst.second < p0.second && obst.second > limits.first) {
			limits.first = obst.second;
		}
		if (obst.second > p0.second && obst.second < limits.second) {
			limits.second = obst.second;
		}
	}
};

class l_diagonal_1 : public line {
public:
	l_diagonal_1(pint p0, int board_size) : line(p0, board_size) {
		limits = pint(max(0, p0.first - p0.second), board_size+1-max(0, p0.second - p0.first));
	}
	bool lies(pint p) {
		return p.second - p0.second == p.first - p0.first;
	}
};

class l_diagonal_2 : public line {
public:
	l_diagonal_2(pint p0, int board_size) : line(p0, board_size) {
		limits = pint(max(0, p0.first + p0.second - (board_size+1)), min(board_size+1, p0.first+p0.second));
	}
	bool lies(pint p) {
		return p.first + p.second == p0.first + p0.second;
	}
};

int num_attacked_fields(int n, int r_q, int c_q, const vector<pint> &obst) {
	// Initialize 4 lines
	vector<line_ptr> attack_lines {
		line_ptr(new l_horizontal(pint(r_q, c_q), n)),
		line_ptr(new l_vertical(pint(r_q, c_q), n)),
		line_ptr(new l_diagonal_1(pint(r_q, c_q), n)),
		line_ptr(new l_diagonal_2(pint(r_q, c_q), n))
	};
	for (pint ob : obst) {
		for (line_ptr lin : attack_lines)
			if (lin->lies(ob)) {
				// update limit
				// warning: updating identical for all line types
				// (check x-coordinate) except for vertical (check y-coordinate)
				lin->update_limit(ob);
				break;
			}
	}
	int n_attacked_fields = 0;
	// count attacked fields for each line
	for (line_ptr lin : attack_lines) {
		pint lims = lin->get_limits();
		n_attacked_fields += lims.second - lims.first - 2;
	}
	return n_attacked_fields;
}

int main() {
	int n, k, r_q, c_q;
	cin >> n >> k;
	vector<pint> obst(k, pint(0, 0));
	cin >> r_q >> c_q;
	for (int i = 0; i < k; i++)
		cin >> obst[i].first >> obst[i].second;
	cout << num_attacked_fields(n, r_q, c_q, obst) << endl;
	return 0;
}

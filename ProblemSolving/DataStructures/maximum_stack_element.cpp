#include <iostream>
#include <vector>
#include <stack>
#include <regex>
#include <string>

using namespace std;

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
	for (T e : v) ost << e << endl;
	return ost;
}

vector<int> getMax(vector<string> operations) {
    // Primary stack
	stack<int> nums;
	// Helper stack of maximum numbers (increasing)
	stack<int> max_nums;
	// guard element
	max_nums.push(0);
	// current number
    int cur_num;
	vector<int> oper_3_outputs;
    regex re("(\\d+)\\s?(\\d+)?");
    for (string oper : operations){
        smatch match;
        if (regex_match(oper, match, re)){
            switch (stoi(match.str(1))) {
            case 1:
				// Operation 1 - push element
                cur_num = stoi(match.str(2));
                nums.push(cur_num);
                if (cur_num >= max_nums.top())
                    max_nums.push(cur_num);
                // cout << "op 1 " << "(" << stck.top() << ")" << endl;
                break;
            case 2:
				// Operation 2 - pop element
                cur_num = nums.top();
                nums.pop();
				if (cur_num == max_nums.top())
					max_nums.pop();
                // cout << "op 2" << endl;
                break;
            case 3:
                // cout << "op 3" << endl;
                oper_3_outputs.push_back(max_nums.top());
                break;
            default:
                cout << "Unrecognized line format :(" << endl;
                break;
            }
        }
    }
    return oper_3_outputs;
}


int main(){
	int n;
	vector<string> lines;
	cin >> n;
	string tmp;
	getline(cin, tmp);
	for (int i = 0; i < n; i++){
		string line;
		getline(cin, line);
		lines.push_back(line);
	}
	cout << getMax(lines);
	return 0;
}

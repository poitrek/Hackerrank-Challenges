#include <iostream>
#include <string>
#include <stack>
using namespace std;


// Implementation with a stack (better)
string superReduce2(string s) {
	std::stack<char> stck;	
	for (char c : s) {
		if (!stck.empty() && stck.top() == c)
			stck.pop();
		else
			stck.push(c);
	}
	string new_s;
	while (!stck.empty()) {
		new_s.insert(new_s.begin(), stck.top());
		stck.pop();
	}
	if (new_s.empty())
		return "Empty String";
	else
		return new_s;
}

// First solution (slower)
string superReduce(string s) {
	bool found;
	do
	{
		found = false;
		for (string::iterator it = s.begin(); it != s.end() - 1; ++it) {
 			if (*it == *(it + 1)) {
				s.erase(it + 1);
				s.erase(it);
				found = true;
				break;
			}
		}
		//cout << "reducing: " << s << endl;
	} while (found && s.length() > 0);
	if (s.empty())
		return "Empty String";
	else
		return s;
}


int main() {
	string s;
	cin >> s;
	/*for (auto it = s.begin(); it != s.end() - 1; it++) {
		cout << *it << *(it + 1);
		if (*it == *(it + 1))
			cout << " ~~";
		cout << endl;
	}*/
	cout << superReduce2(s) << endl;
	return 0;
}
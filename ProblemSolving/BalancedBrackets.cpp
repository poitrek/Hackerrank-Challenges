#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>


const std::unordered_map<char, char> matched_brackets = {
	{'}', '{'}, {')', '('}, {']', '['}
};


bool IsBalanced(const std::string& s) {
	std::stack<char> st;
	for (char c : s) {
		auto it = matched_brackets.find(c);
		// Opening bracket found - push on stack
		if (it == matched_brackets.end()) {
			st.push(c);
		}
		else {
			if (st.empty())
				return false;
			// Matching closing bracket - pop the pair
			if (it->second == st.top()) {
				st.pop();
			}
			else {
				// Non-matching bracket found - false
				return false;
			}
		}
	}
	// The string was balanced iff the stack is empty
	return st.empty();
}

int main(){
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		std::cout << (IsBalanced(s) ? "YES" : "NO") << std::endl;
	}
	return 0;
}

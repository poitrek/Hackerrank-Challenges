#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
https://www.hackerrank.com/challenges/reduced-string/problem
Challenge:
Given a string S consising of characters [a-z], in each operation we select 
two adjacent characters that match and remove them. Reduce S with this operation
to its shortest possible length.
E.g.
aaabcddcbccd -> abcddcbccd -> abccbccd -> abbccd -> accd -> ad.
*/


// 2nd solution, with a stack (more efficient)

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
/*
Algorithm: iterate string's characters and put them o the stack. If current
character is the same as top of the stack, pop the value. Otherwise, push
the element on stack. After this procedure, the stack contains the reduced
string in reversed order.

Example:
s = "aaabcddcbccd"

i=0		s[i]='a'
stack: [a]
i=1		s[i]='a' = stack.top() -> stack.pop()
stack: []
i=2		s[i]='a'
stack: [a]
i=3		s[i]='b'
stack: [ab]
i=4		s[i]='c'
stack: [abc]
i=5		s[i]='d' = stack.top() -> stack.pop()
stack: [abcd]
i=6		s[i]='d'
stack: [abc]
i=7		s[i]='c' = stack.top() -> stack.pop()
stack: [ab]
i=8		s[i]='b' = stack.top() -> stack.pop()
stack: [a]
i=9		s[i]='c'
stack: [ac]
i=10	s[i]='c' = stack.top() -> stack.pop()
stack: [a]
i=11	s[i]='d'
stack: [ad]

reduced string: "ad"
*/


// 3rd solution (concise & efficient)
string superReduce3(string s) {
	// guard character
	s = "@#" + s;
	for (string::iterator it = s.begin(); it < s.end() - 1; it++) {
		if (*it == *(it + 1)) {
			s.erase(it); s.erase(it);
			it -= 2;
		}
	}
	s.erase(0, 2);
	return s.empty() ? "Empty String" : s;
}

// First solution (slow)
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
	cout << superReduce3(s) << endl;
	return 0;
}
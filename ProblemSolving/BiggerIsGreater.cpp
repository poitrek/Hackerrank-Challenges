#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string next_word(string s) {
	string no_ans = "no answer";
	int len(s.size());
	int idx = -1;
	for (int i = len-1; i > 0; i--)
		if (s[i-1] < s[i]){
			idx = i-1;
			break;
		}
	if (idx == -1)
		return no_ans;
	char s_idx = s[idx];
	int i;
	for (i = len-1; s[i] <= s_idx; i--) ;
	// swap the characters
	s[idx] = s[i];
	s[i] = s_idx;
	reverse(s.begin()+idx+1, s.end());
	return s;
}

int main(){
	// cout << next_word("abcgfe");
	int t;
	cin >> t;
	vector<string> words(t);
	for (int i = 0; i < t; i++){
		cin >> words[i];
	}
	for (int i = 0; i < t; i++){
		cout << next_word(words[i]) << endl;
	}
	return 0;
}

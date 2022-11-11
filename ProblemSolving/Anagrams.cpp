#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int alph_size = 26;

int anagram(string s) {
    if (s.size() % 2 == 1)
        return -1;
    int cnt[alph_size];
    for (int i = 0; i < alph_size; i++)
        cnt[i] = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = s.size() / 2; i < s.size(); i++) {
        cnt[s[i] - 'a']--;
    }
    int tot_abs = 0;
    for (int i = 0; i < alph_size; i++) {
        tot_abs += abs(cnt[i]);
    }
    return tot_abs / 2;
}


int main() {
	int t;
	cin >> t;
	vector<string> s (t);
	for (int i = 0; i < t; i++)
		cin >> s[i];
	for (int i = 0; i < t; i++)
		cout << anagram(s[i]) << endl;
	return 0;
}

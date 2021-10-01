#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// O(n) time complexity

bool happy_ladybugs_possible(string &b, int n) {
    // Flag checking that there is a space
    bool space_exists = false;
    // Flag checking that the ladybugs are already happy
    bool happy_already = true;
    // Single/multiple flag for each letter
    map<char, bool> letter_multiple;
    // Number of letters that appear once
    int single_letter_cnt = 0;
    // previous character
    char prev_c = ' ';
    // Is previous character different
    bool prev_different = false;
    for (char c : b) {
        if (c == '_')
            space_exists = true;
        else {
            if (letter_multiple.find(c) == letter_multiple.end()) {
                letter_multiple.insert(pair<char, int>(c, 0));
                single_letter_cnt++;
            }
            else if (letter_multiple[c] == 0) {
                letter_multiple[c] = 1;
                single_letter_cnt--;
            }
        }
        bool cur_different = (c != prev_c);
        // Two differences in a row - unhappy bug
        if (cur_different && prev_different)
            happy_already = false;
        prev_different = cur_different;
        prev_c = c;
    }
    // Check that the last letter isn't alone
    happy_already = happy_already && !prev_different;
    return !single_letter_cnt && (space_exists || happy_already);
}

bool input_and_solve() {
    int n;
    cin >> n;
    string b;
    cin >> b;
    return happy_ladybugs_possible(b, n);
}


int main(int argc, char const *argv[])
{
    int g;
    cin >> g;
    vector<bool> results (g, 0);
    for (int i = 0; i < g; i++) {
        results[i] = input_and_solve();
    }
    for (bool r : results) {
        cout << (r ? "YES" : "NO") << endl;
    }
    return 0;
}

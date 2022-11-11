#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


 void increment_entry(map<char, int> &_map, char key) {
    if (_map.find(key) != _map.end()) {
        _map[key]++;
    }
    else {
        _map.insert(pair<char, int>(key, 1));
    }
}

// Check if characters ca and cb appear in string alternatingly
bool check_alternating(const string &s, char ca, char cb) {
    char prev_c = '0';
    for (char c : s) {
        if (c == ca || c == cb) {
            if (c == prev_c)
                return false;
            prev_c = c;
        }
    }
    return true;
}


int alternate(string s) {
    if (s == "")
        return 0;
    map<char, int> symbol_cnt;
    // creation of set
    // first filter of necessary symbols - exclude subsequently appearing
    set<char> unnecessary_symbols;
    char prev_c = '0';
    for (char c : s) {
        if (c == prev_c)
            unnecessary_symbols.insert(c);
        else {
            increment_entry(symbol_cnt, c);
        }
        prev_c = c;
    }
    for (char c : unnecessary_symbols) {
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
        symbol_cnt.erase(c);
    }
    // less than two necessary symbols - no solution
    if (symbol_cnt.size() < 2)
        return 0;
    int max_alternating_length = 0;
    // For every pair of counted symbols
    for (auto it = symbol_cnt.begin(); it != prev(symbol_cnt.end()); ++it) {
        for (auto jt = next(it); jt != symbol_cnt.end(); jt++) {
            // check if their count differs by 0 or 1
            if (abs(it->second - jt->second) <= 1) {
                if (check_alternating(s, it->first, jt->first))
                    max_alternating_length = max<int>(max_alternating_length,
                        it->second + jt->second);
            }
        }
    }
    return max_alternating_length;
}


int main() {
    string s = "aaa";
    cout << alternate(s) << endl;
    return 0;
}
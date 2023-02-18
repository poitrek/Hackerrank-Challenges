#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int max_same_height = 0;
    h1.push_back(0);
    h2.push_back(0);
    h3.push_back(0);
    int h1h = 0, h2h = 0, h3h = 0;
    int h1size = h1.size()-1, h2size = h2.size()-1, h3size = h3.size()-1;
    for (int i1 = 0, i2 = 0, i3 = 0; 
        i1 < h1size || i2 < h2size || i3 < h3size;) {
            if (h1h == h2h && h2h == h3h) {
                max_same_height = h1h;
                h1h += h1[i1++];
                h2h += h2[i2++];
                h3h += h3[i3++];
            }
            else {
                int hmax = max({h1h, h2h, h3h});
                if (h1h < hmax && i1 <= h1size) {
                    h1h += h1[i1++];
                }
                if (h2h < hmax && i2 <= h2size) {
                    h2h += h2[i2++];
                }
                if (h3h < hmax && i3 <= h3size) {
                    h3h += h3[i3++];
                }
            }
        }
    return max_same_height;
}

int equalStacks(vector<vector<int>> &h) {
    int n = h.size();
    int max_same_height = 0;
    for (int i = 0; i < h.size(); i++) {
        h[i].push_back(0);
    }
    vector<int> h_cur_hght (h.size(), 0);
    vector<int> it (h.size(), 0);
    int max_cur_hght = 0;
    bool stop = false;
    while (!stop) {
        bool all_same_hght = true;
        for (int i = 0; i < n; i++) {
            // increase current height
            while (h_cur_hght[i] < max_cur_hght && it[i] < h[i].size()) {
                h_cur_hght[i] += h[i][it[i]++];
            }
            if (h_cur_hght[i] > max_cur_hght) {
                max_cur_hght = h_cur_hght[i];
                all_same_hght = false;
            }
            if (it[i] >= h[i].size() && h_cur_hght[i] < max_cur_hght) {
                stop = true;
            }
        }
        if (all_same_hght) {
            // update the maximum same height
            max_same_height = max_cur_hght;
            for (int i = 0; i < n; i++) {
                if (it[i] < h[i].size()) {
                    h_cur_hght[i] += h[i][it[i]++];
                    if (h_cur_hght[i] > max_cur_hght)
                        max_cur_hght = h_cur_hght[i];
                }
            }
        }
    }
    return max_same_height;
}

int main()
{
    int s1, s2, s3;
    int n = 3;
    cin >> s1 >> s2 >> s3;

    // init stacks' vectors
    vector<vector<int>> h;
    h.push_back(vector<int>(s1));
    h.push_back(vector<int>(s2));
    h.push_back(vector<int>(s3));


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < h[i].size(); j++)
            cin >> h[i][j];
    }
    
    for (int i = 0; i < n; i++) {
        reverse(h[i].begin(), h[i].end());
    }

    cout << equalStacks(h) << endl;

    return 0;
}

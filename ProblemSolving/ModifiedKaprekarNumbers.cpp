#include <iostream>
#include <string>

using namespace std;

bool is_kaprekar_number(long long n){
    int d = to_string(n).size();
    string s = to_string((long long)(n * n));
    string l = s.substr(0, s.size()-d);
    string r = s.substr(s.size()-d, d);
    long long li = (l.size() > 0) ? stoll(l) : 0; 
    long long ri = (r.size() > 0) ? stoll(r) : 0; 
    return (li + ri == n);
}

int main(){
    long long begin, end;
    cin >> begin >> end;
    // begin = 1000, end = 10000;
    bool kaprekar_exist = false;
    for (long long i = begin; i <= end; i++){
        if (is_kaprekar_number(i)) {
            cout << i << " ";
            kaprekar_exist = true;
        }
    }
    if (!kaprekar_exist)
        cout << "INVALID RANGE" << endl;
    return 0;
}
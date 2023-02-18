#include<iostream>
#include<map>
#include<vector>

// Print pair
template<typename T1, typename T2>
std::ostream& operator << (std::ostream& ost, const std::pair<T1, T2> p) {
    ost << "(" << p.first << ", " << p.second << ")";
    return ost;
}

// Print vector
template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> &v) {
    ost << "[ ";
	for (T e : v) ost << e << " ";
	ost << "]" << std::endl;
    return ost;
}

// Print map
template<typename K, typename V>
std::ostream& operator << (std::ostream& ost, const std::map<K, V> m) {
    ost << "{ ";
    for (const std::pair<K, V> &p : m) {
        ost << p.first << ": " << p.second << ", ";
    }
    ost << "}";
    return ost;
}

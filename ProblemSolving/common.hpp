#include<fstream>
#include<vector>

template<typename T>
std::ostream& operator << (std::ostream& ost, const std::vector<T> v) {
    ost << "{ ";
	for (T e : v) ost << e << " ";
	ost << "}" << std::endl;
    return ost;
}
/*Flatland Space Stations
Find the maximum difference between consecutive elements
in an array, unsorted on input*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// O(nlog(n) time solution)

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> station_indices(m, 0);
	for (int i = 0; i < m ; i++)
		cin >> station_indices[i];
	sort(station_indices.begin(), station_indices.end());
	int max_dif = 0;
	// check distances (differences) between neighboring cities
	for (int i = 0; i < m-1; i++) {
		int dif = station_indices[i+1] - station_indices[i];
		if (dif > max_dif)
			max_dif = dif;
	}
	max_dif = (int) std::floor(max_dif * 0.5);
	// check the first and the last city
	max_dif = max(max_dif, station_indices.front());
	max_dif = max(max_dif, n - 1 - station_indices.back());
	// std::copy(station_indices.begin(), station_indices.end(), std::ostream_iterator<int>(std::cout, " "));
	cout << max_dif << endl;
	return 0;
}

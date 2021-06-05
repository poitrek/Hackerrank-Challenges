#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Helper function based on the code from Hackerrank
vector<int> split(const string& s);

void dynamicArray(int N, vector<string> queries) {
	// Initialize vector of vectors
	vector<vector<int>> seqList(N, vector<int>());
	int lastAnswer{ 0 };
	for (string q : queries) {
		// Split into arguments
		vector<int> args = split(q);
		// Access proper sequence
		int idx = (args[1] ^ lastAnswer) % N;
		//vector<int> seq = seqList[idx];
		if (args[0] == 1) {
			seqList[idx].push_back(args[2]);
		}
		else if (args[0] == 2) {
			lastAnswer = seqList[idx][args[2] % seqList[idx].size()];
			cout << lastAnswer << endl;
		}
		else
			cout << "Invalid query!" << endl;
	}
}

void dynamicArray2(int N, vector<string> queries) {
	// Initialize vector of vectors
	vector<shared_ptr<vector<int>>> seqList(N, shared_ptr<vector<int>>(new vector<int>()));
	int lastAnswer{ 0 };
	for (string q : queries) {
		// Split into arguments
		vector<int> args = split(q);
		// Access proper sequence
		int idx = (args[1] ^ lastAnswer) % N;
		shared_ptr<vector<int>> seq = seqList[idx];
		//vector<int> seq = seqList[idx];
		if (args[0] == 1) {
			seq->push_back(args[2]);
		}
		else if (args[0] == 2) {
			lastAnswer = (*seq)[args[2] % seq->size()];
			cout << lastAnswer << endl;
		}
		else
			cout << "Invalid query!" << endl;
	}
}


int main2()
{
	int N, Q;
	cin >> N >> Q;
	vector<string> queries;
	string line;
	getline(cin, line);
	for (int i = 0; i < Q; i++) {
		getline(cin, line);
		queries.push_back(line);
	}

	//for (int i = 0; i < Q; i++)
	//	cout << "~" << queries[i] << "~" << endl;
	
	dynamicArray2(N, queries);
	return 0;
}

vector<int> split(const string& s) {
	vector<int> tokens;
	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = s.find(" ", start)) != string::npos) {
		tokens.push_back(stoi(s.substr(start, end - start)));
		start = end + 1;
	}
	tokens.push_back(stoi(s.substr(start, end - start)));
	return tokens;
}
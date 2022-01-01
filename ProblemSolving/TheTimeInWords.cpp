#include <iostream>
#include <vector>

using namespace std;

vector<string> number_words = {
	"zero", 
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
	"twenty",
	"twenty one",
	"twenty two",
	"twenty three",
	"twenty four",
	"twenty five",
	"twenty six",
	"twenty seven",
	"twenty eight",
	"twenty nine"
};

string timeInWords(int h, int m) {
    string time_words;
	string preposition;
	string h_word;
	string minute_word;
	// Transform to time "to"
	if (m > 30) {
		m = 60 - m;
		h++;
		preposition = "to";
	}
	else {
		preposition = "past";
	}
	if (m == 1)
		minute_word = "minute";
	else
		minute_word = "minutes";
	h_word = number_words[h];
	if (m == 0)
		time_words = h_word + " o' clock";
	else if (m == 30)
		time_words = "half " + preposition + " " + h_word;
	else if (m == 15)
		time_words = "quarter " + preposition + " " + h_word;
	else
		time_words = number_words[m] + " " + minute_word + " " + preposition + " " + h_word;
	return time_words;
}

int main(){
	int h, m;
	cin >> h >> m;
	cout << timeInWords(h, m) << endl;
	return 0;
}

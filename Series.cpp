#include<iostream>
#include<string>
#include<list>

//* Given a string of digits, output all the contiguous substrings
//* of length n in that string in the order that they appear.

using namespace std;

list<string> Series(string digits, size_t n) {

    list<string> series;
    for(size_t i = 0; i + n <= digits.size(); i++) {
        const string newDigit = digits.substr(i, n);
        series.push_back(newDigit);
    }
 return series;
}

int main() {

    cout << "Input string of digits: ";
    string digits; cin >> digits;

    cout << "Input length of substring: ";
    size_t n; cin >> n;

    list<string> series = Series(digits, n);
    for(auto it : series) cout << it << endl;
}
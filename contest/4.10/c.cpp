#include <iostream>
#include <string>
using namespace std;

string f(int n) {
	if(n == 1) {
		return "1";
	}	
	return f(n-1) + " " + to_string(n) + " " + f(n-1);
}
int main() {
	int n; cin >> n;
	string s = f(n);
	for(auto c : s) {
		cout << c;
	}
	cout << endl;
}

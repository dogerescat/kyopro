#include <iostream>
#include <vector>
using namespace std;

vector<int> primeNum(int n) {
	vector<int> res;
	for(int i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if(n != 1) res.push_back(n);
	return res;
}

int main() {
	int n; cin >> n;
	vector<int> ans;
	ans = primeNum(n);
	cout << n << ":";
	for(int i : ans) {
		cout << " ";	
		cout << i;
	}
	cout << endl;
}

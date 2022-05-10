#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> ans;
	int x = 0;
	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) x += a[i];
		else x -= a[i];
	}
	ans.push_back(x);
	x /= 2;
	for(int i = 0; i < n-1; i++) {
		x = a[i] - x;	
		ans.push_back(x * 2);
	}
	for(int i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}

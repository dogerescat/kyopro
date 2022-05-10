#include <iostream>
#include <vector>
using namespace std;

void output(int n) {
	vector<int> a;	
	int i = 1;
	while(n) {
		if(n & 1) a.push_back(i);
		i++;
		n >>= 1;
	}
	cout << a.size();
	for(auto x : a) cout << " " << x;
	cout << endl;
}
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	n = min(8, n);
	vector<int> st(200);
	for(int bit = 1; bit < (1 << n); bit++) {
		int x = 0;
		for(int i = 0; i < n; i++) if(bit >> i & 1) x = (x + a[i]) % 200; 
		if(st[x] == 0) st[x] = bit;
		else {
			cout << "Yes" << endl;
			output(bit);
			output(st[x]);
			return 0;
		}
		
	}
	cout << "No" << endl;
}

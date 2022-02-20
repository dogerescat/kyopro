#include <iostream>
#include <vector>
using namespace std;
vector<bool> primeNum() {
	vector<bool> res(100001, true);
	res[0] = false;
	res[1] = false;
	for(int i = 2; i <= 100000; i++) {
		for(int j = 2; i * j <= 100000; j++) {
			res[i*j] = false;	
		}
	}
	return res;
}
int main() {
	int q; cin >> q;	
	vector<bool> p;
	p = primeNum();
	vector<int> a(100001);
	for(int i = 1; i < 100001; i++) {
		if(p[i] && p[(i+1)/2]) a[i] = 1;	
	}
	vector<int> sum(100001);
	for(int i = 1; i < 100001; i++) sum[i] = sum[i-1] + a[i];
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << sum[r] - sum[l-1] << endl;
	}
}

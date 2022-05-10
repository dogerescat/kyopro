#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> eratos() {
	set<int> res;
	vector<bool> isPrime(100010, true);
	isPrime[0] = isPrime[1] = false;	
	for(int i = 2; i <= 100000; i++) {
		if(!isPrime[i]) continue;
		res.insert(i);
		for(int j = 2 * i; j <= 100000; j += i) {
			isPrime[j] = false;
		}
	}
	return res;
}
int main() {
	int q; cin >> q;
	set<int> res = eratos();
	vector<int> likes;
	for(auto i : res) {
		int x = i * 2 - 1;
		if(res.count(x)) {
			likes.push_back(x);
		} 
	}	
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;	
		int left = lower_bound(likes.begin(), likes.end(), l) - likes.begin();
		int right = upper_bound(likes.begin(), likes.end(), r) - likes.begin();
		int ans = right - left;
		cout << ans << endl;
	}
}

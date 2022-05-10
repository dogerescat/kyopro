#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll K = 60;

struct Trie {
	vector<int> l, r, c;
	Trie() : l(1, -1), r(1, -1), c(1, 0){}
	int newNode() {
		int i = l.size();
		l.push_back(-1);
		r.push_back(-1);
		c.push_back(0);
		return i;
	}
	int getNext(int i, int a, bool read=true) {
		if(a == 0) {
			if(l[i] == -1 && !read) {
				int ni = newNode();
				l[i] = ni;
			} 			
			return l[i];
		} else {
			if(r[i] == -1 && !read) {
				int ni = newNode();
				r[i] = ni;
			}
			return r[i];
		}
	}
	void add(ll x) {
		int i = 0;
		c[0]++;
		for(ll b = 1LL << K; b; b >>= 1) {
			int a = (x & b) ? 1 : 0;	
			i = getNext(i, a, false);
			c[i]++;
		}
	}
	int count(ll x) {
		int i = 0, res = 0;	
		for(ll b = 1LL << K; b; b >>= 1) {
			int a = (x & b) ? 1 : 0;	
			if(a == 1) {
				if(l[i] != -1) res += c[l[i]];
			}
			i = getNext(i, a);
			if(i == -1) return res;
		}
		res += c[i];
		return res;
	}
	int getKth(int k) {
		if(k <= 0 || c[0] < k) return -1;	
		int i = 0;
		ll res = 0;
		for(ll b = 1LL << K; b; b >>= 1) {
			if(l[i] != -1 && c[l[i]] >= k) {
				i = l[i];
			} else {
				k -= c[l[i]];
				i = r[i];
				res |= b;
			}
		}
		return res;
	}
};
 
int main() {
	int q; cin >> q;
	Trie T;
	for(int i = 0; i < q; i++) {
		ll t, x, k; cin >> t >> x;
		if(t == 1) {
			T.add(x);	
		} else {
			cin >> k;	
			ll ans = -1;
			if(t == 2) {
				int i = T.count(x) - k + 1;	
				ans = T.getKth(i);
			} else {
				int i = T.count(x-1) + k;
				ans = T.getKth(i);
			}
			cout << ans << endl;
		}
	}
}

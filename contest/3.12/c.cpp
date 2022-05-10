#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

int main() {
	ll n; cin >> n;
	vector<ll> x(n), y(n);
	for(ll i = 0; i < n; i++) cin >> x[i] >> y[i];
	string S; cin >> S;
	vector<P> a;	
	for(ll i = 0; i < n; i++) {
		a.push_back(P(y[i], i));	
	}
	sort(a.begin(), a.end());
	ll pre = -1;
	ll preindex = -1;
	while(a.size()) {
		P p = a.back();	
		a.pop_back();
		ll Y = p.first;
		ll index = p.second;
		if(pre != Y) {
			pre = Y;	
			preindex = index;
			continue;
		}
		if(x[index] > x[preindex]) {
			if(S[index] == 'L' && S[preindex] == 'R') {
				cout << "Yes" << endl;
				return 0;
			} 
		} else  {
			if(S[preindex] == 'L' && S[index] == 'R') {
				cout << "Yes" << endl;
				return 0;
			}
		}
		
	}
	cout << "No" << endl;
}

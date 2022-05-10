#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<int, ll> P;

int main() {
	int N; ll C; cin >> N >> C;
	vector<P> X;
	for(int i = 0; i < N; i++) {
		int a, b; ll c; cin >> a >> b >> c;
		X.push_back(P(a, c));	
		X.push_back(P(b+1, -c));
	}
	sort(X.begin(), X.end());
	ll total = 0;	
	ll ans = 0;
	int prev = 0;
	for(auto i : X) {
		if(total > C) ans += C * (i.first - prev); 
		else ans += total * (i.first - prev);
		prev = i.first;
		total += i.second;
	}
	cout << ans << endl;
}

#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
using P = pair<int, int>;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}
int main() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	set<P> s;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;	
			int X = x[i] - x[j];
			int Y = y[i] - y[j];
			int d = gcd(abs(X), abs(Y));
			X /= d;
			Y /= d;
			s.insert(P(X, Y));
		}
	}
	int ans = s.size();
	cout << ans << endl;
}

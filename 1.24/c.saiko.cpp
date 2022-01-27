#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n; cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	set<P> s;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		s.insert(P(x[i], y[i]));
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) {
		P p = P(x[j] - y[j] + y[i], y[j] + x[j] - x[i]);
		P q = P(x[i] - y[j] + y[i], y[i] + x[j] - x[i]);
		if(s.count(p) && s.count(q)) {
			int X = (x[i] - x[j]) * (x[i] - x[j]);
			int Y = (y[i] - y[j]) * (y[i] - y[j]);
			ans = max(ans, X + Y);
		}
	}
	cout << ans << endl;
}

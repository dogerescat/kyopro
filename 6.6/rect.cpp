#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	set<P> s;
	for(int i = 0; i < n; i++) s.insert(P(x[i], y[i]));
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(x[i] == x[j] || y[i] == y[j]) continue; 
			if(s.count(P(x[i], y[j])) && s.count(P(x[j], y[i]))) ans++;
		}
	}
	cout << ans/2 << endl;
}

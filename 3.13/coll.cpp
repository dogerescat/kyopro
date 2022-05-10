#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1001001001;
int main() {
	int n; cin >> n; 
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	string s; cin >> s;
	vector<P> a;
	for(int i = 0; i < n; i++) {
		a.push_back(P(y[i], i));	
	}
	a.push_back(P(-1, -1));
	sort(a.begin(), a.end());
	int right_min = INF;
	int left_max = 0;
	bool ok = false;
	int pre = -1;
	while(a.size()) {
		P p = a.back();
		a.pop_back();
		int Y = p.first;
		int index = p.second;
		if(pre != Y) {
			if(right_min < left_max) ok = true;
			pre = Y;
			right_min = INF;
			left_max = 0;
		}	
		if(s[index] == 'R') {
			right_min = min(right_min, x[index]);
		} else {
			left_max = max(left_max, x[index]);
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}

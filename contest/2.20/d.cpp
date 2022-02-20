#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<P> x;	
	x.push_back(P(a[0], 1));
	int cnt = 1;
	cout << cnt << endl;
	for(int i = 1; i < n; i++) {
		P p = x.back();	
		cnt++;
		if(p.first == a[i]) {
			x.pop_back();	
			p.second++;
			if(p.first == p.second) cnt -= p.second;
			else x.push_back(P(p.first, p.second));
		} else x.push_back(P(a[i], 1));
		cout << cnt << endl;
	}
}

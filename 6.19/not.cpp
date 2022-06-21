#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> x(1000001);
	set<int> a;	
	for(int i = 0; i < n; i++) {
		int b; cin >> b;
		if(a.count(b)) x[b]++;
		a.insert(b);
	}
	for(int i : a) {
		int j = i;
		while(j + i <= 1000000) {
			j += i;
			x[j]++;
		}
	}
	int ans = 0;
	for(int i : a) {
		if(!x[i])	ans++;
	}
	cout << ans << endl;
}

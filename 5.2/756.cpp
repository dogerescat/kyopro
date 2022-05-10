#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int> p;	
	auto prime_dis = [&](int m) {
		for(int i = 2; 1LL * i * i <= m; i++) {
			while(m % i == 0) {
				m /= i;
				p[i]++;
			}
		}	
		if(m > 1) p[m]++;
	};
	for(int i = 1; i <= n; i++)	prime_dis(i);	
	int ans = 0;	
	for(int i = 2; i <= n; i++) if(74 <= p[i]) ans++;
	for(int i = 2; i <= n; i++) for(int j = 2; j <= n; j++) {
		if(i != j && 14 <= p[i] && 4 <= p[j]) ans++;
	}
	for(int i = 2; i <= n; i++) for(int j = 2; j <= n; j++) {
		if(i != j && 24 <= p[i] && 2 <= p[j]) ans++;
	}
	for(int i = 2; i <= n; i++) for(int j = 2; j <= n; j++) for(int k = j+1; k <= n; k++) {
		if(i != j && i != k && 2 <= p[i] && 4 <= p[j] && 4 <= p[k]) ans++;
	}
	cout << ans << endl;
}

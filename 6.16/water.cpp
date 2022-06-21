#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n, w; cin >> n >> w;
	vector<ll> x(200001);	
	for(int i = 0; i < n; i++) {
		int s, t; ll p; cin >> s >> t >> p;
		x[s] += p;
		x[t] -= p;
	}
	for(int i = 1; i < 200001; i++) x[i] += x[i-1];
	for(int i = 0; i < 200001; i++) {
		if(x[i] > w) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}

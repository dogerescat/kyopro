#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int X, Y, Z, K; cin >> X >> Y >> Z >> K;
	vector<ll> x(X), y(Y), z(Z);
	for(int i = 0; i < X; i++) cin >> x[i];
	for(int i = 0; i < Y; i++) cin >> y[i];
	for(int i = 0; i < Z; i++) cin >> z[i];
	vector<ll> xy;
	for(int i = 0; i < X; i++) for(int j = 0; j < Y; j++) xy.push_back(x[i]+y[j]);
	sort(xy.rbegin(), xy.rend());	
	vector<ll> xyz;
	for(int i = 0; i < min(K, (int)xy.size()); i++) {
		for(int j = 0; j < Z; j++) {
			xyz.push_back(xy[i] + z[j]);	
		}
	}
	sort(xyz.rbegin(), xyz.rend());
	for(int i = 0; i < K; i++) cout << xyz[i] << endl;
}

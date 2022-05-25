#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
	ll k; cin >> k;	
	ll N = 50;
	vector<ll> a(N);
	iota(a.begin(), a.end(), 0);
	ll d = k % N;
	ll t = k / N;
	for(int i = 0; i < N; i++) a[i] += t;
	for(int i = 0; i < d; i++) a[i] += (N - d + 1);
	for(int i = d; i < N; i++) a[i] -= d;
	cout << N << endl;
	for(int i = 0; i < N; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}

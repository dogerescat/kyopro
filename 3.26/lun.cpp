#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int k; cin >> k;
	vector<ll> a;	
	queue<ll> que;
	for(int i = 1; i <= 9; i++) que.push(i);
	while(!que.empty()) {
		ll v = que.front(); que.pop();
		a.push_back(v);
		if(a.size() == k) {
			cout << v << endl;
			return 0;
		}
		int w = v % 10;
		if(w != 0) que.push(v * 10 + (w-1));
		que.push(v * 10 + w);
		if(w != 9) que.push(v * 10 + (w + 1));
	}
}

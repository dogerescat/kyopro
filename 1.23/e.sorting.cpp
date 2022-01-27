#include <iostream>
#include <queue>
using namespace std;

int main() {
	int q; cin >> q;
	priority_queue<int, vector<int>, greater<int>> heap;
	queue<int> que;
	for(int i = 0; i < q; i++) {
		int a; cin >> a;
		if(a == 1) {
			int x; cin >> x;
			que.push(x);
		} else if(a == 2) {
			int v;
			if(heap.size()) {
				v = heap.top();
				heap.pop();
			} else {
				v = que.front();
				que.pop();
			}
			cout << v << endl;
		} else {
			while(!que.empty()) {
				int v = que.front(); que.pop();
				heap.push(v);
			}	
		}
	}
}

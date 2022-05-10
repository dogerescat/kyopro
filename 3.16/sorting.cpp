#include <iostream>
#include <queue>
using namespace std;

int main() {
	int Q; cin >> Q;
	queue<int> que;
	priority_queue<int, vector<int>, greater<int>> heap;
	for(int i = 0; i < Q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x; cin >> x;
			que.push(x);
		} else {
			if(t == 2) {
				int v;
				if(heap.size()) {
					v = heap.top();	heap.pop();
				} else {
					v = que.front(); que.pop();
				}
				cout << v << endl;
			} else {
				while(!que.empty()) {
					heap.push(que.front()); que.pop();
				}
			}
		}
	}
}

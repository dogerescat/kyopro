#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;
using P = pair<int, int>;

int main() {
	int a, n; cin >> a >> n;
	queue<P> que;
	set<int> s;
	int m = to_string(n).size();	
	que.push(P(1, 0));
	s.insert(1);
	while(!que.empty()) {
		auto p = que.front(); que.pop();
		int v = p.first;
		int c = p.second;
		if(n == v) {
			cout << c << endl;
			return 0;
		}
		if(m >= to_string(a*v).size() && !s.count(a*v)) {
			que.push(P(a*v, c+1));
			s.insert(a*v);
		}
		if(v >= 10 && v % 10) {
			string st = to_string(v);
			int len = st.size();
			rotate(st.begin(), st.begin() + len - 1, st.end());
			if(!s.count(stoi(st))) {
				que.push(P(stoi(st), c+1));	
			}
		}
	}
	cout << -1 << endl;
}

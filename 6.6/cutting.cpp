#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int L, Q; cin >> L >> Q;	
	set<int> s;
	s.insert(0);
	s.insert(L);
	for(int q = 0; q < Q; q++) {
		int c, x; cin >> c >> x;
		if(c == 1) {
			s.insert(x);	
		} else {
			auto iter = s.lower_bound(x);
			int r = *iter;	
			--iter;
			int l = *iter;
			cout << r - l << endl;
		}
	}
}

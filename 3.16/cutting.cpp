#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int L, Q; cin >> L >> Q;	
	set<int> s;	
	s.insert(0);
	s.insert(L);
	for(int i = 0; i < Q; i++) {
		int c, x; cin >> c >> x;	
		if(c == 1) {
			s.insert(x);
		} else {
			auto ite = s.lower_bound(x);	
			int a = *ite;
			--ite;
			int b = *ite;
			cout << a - b << endl;
		}
	}
}

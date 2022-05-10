#include <iostream>
#include <set>
using namespace std;

int main() {
	int n; cin >> n;
	set<int> s;
	for(int i = 1; i <= 2*n+1; i++) s.insert(i);
	while(1) {
		int ans = *s.begin();
		s.erase(ans);	
		cout << ans << endl;
		int a; cin >> a;
		if(a == 0) break;
		s.erase(a);
	}
	return 0;
}

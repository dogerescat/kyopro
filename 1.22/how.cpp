#include <iostream>
using namespace std;

int main() {
	while(true) {
	  int n, x; cin >> n >> x;
	  if(n == 0) break;
	  int ans = 0;
	  for(int i = 1; i <= n; i++) {
	    for(int j = i+1; j <= n; j++) {
		  for(int k = j+1; k <= n; k++) {
		    int total = i + j + k;
			if(total == x) ans++;
		  }
		}
	  }
	  cout << ans << endl;
	}
	return 0;
}

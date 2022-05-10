#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> x(3), y(3);	
	for(int i = 0; i < 3; i++) cin >> x[i] >> y[i];
	int ans1, ans2;
	if(x[0] == x[1]) ans1 = x[2];
	else if(x[1] == x[2]) ans1 = x[0];
	else if(x[2] == x[0]) ans1 = x[1];
	if(y[0] == y[1]) ans2 = y[2];
	else if(y[1] == y[2]) ans2 = y[0];
	else if(y[2] == y[0]) ans2 = y[1];
	cout << ans1 << ' ' << ans2 << endl;
}

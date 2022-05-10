#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> s(n);
	int index = 0;
	s[index] = 1;
	int color = a[index];
	for(int i = 1; i < n; i++) {
		if(color == a[i]) {
			s[index]++;
		} else if(i % 2 == 1) {
			if(!index) {
				s[index]++;
				color = a[i]; 
			} else {
				s[index-1] += s[index] + 1;
				s[index] = 0;
				--index;
			}
		} else {
			index++;
			s[index] = 1;
		}
		color = a[i];
	}	
	int ans = 0;
	for(int i = n-1; i >= 0; i--) {
		if(s[i]) {
			if(color) color = 0;
			else {
				ans += s[i];	
				color = 1;
			}
		}			
	}
	cout << ans << endl;
}

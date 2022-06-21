#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; ll k; cin >> n >> k;	
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n, -1);
	vector<int> s;
	int v = 0;
	while(b[v] == -1) {
		b[v] = s.size();
		s.push_back(v);
		v = a[v] - 1;
	}
	int l = b[v];	
	if(k < l) {
		cout << s[k] + 1 << endl;	
	} else {
		k -= l;
		k %= (s.size() - l); 
		k += l;
		cout << s[k] + 1 << endl;
	}
}

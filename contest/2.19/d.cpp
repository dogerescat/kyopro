#include <iostream>
#include <vector>
using namespace std;

vector<bool> primeNum() {
	vector<bool> res(201, true);
	res[0] = false; res[1] = false;
	for(int i = 2; i <= 200; i++) {
		for(int j = 2; i * j <= 200; j++) {
			res[i*j] = false;
		}
	}
	return res;
}
bool f(vector<bool> &p, int &c, int &d, int v) {
	bool ok = false;	
	for(int j = c; j <= d; j++) {
		if(p[v+j]) ok = true;
	}
	return ok;
}
int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	vector<bool> p;
	p = primeNum();
	bool ok = false;
	for(int i = a; i <= b; i++) {
		if(!f(p, c, d, i)) ok = true;
	}
	if(ok) cout << "Takahashi" << endl;	
	else cout << "Aoki" << endl;
}

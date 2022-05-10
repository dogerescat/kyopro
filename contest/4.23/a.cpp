#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	int A = a * b;
	int B = d * e;
	int st = a + c;
	int sa = d + f;
	int pt = x / st;
	int qt = x % st;
	int pa = x / sa;
	int qa = x % sa;
	int takahashi = A * pt;	
	if(qt <= a) takahashi += b * qt;
	else takahashi += a * b;
	int aoki = B * pa;
	if(qa <= d) aoki += e * qa;
	else aoki += d * e;
	if(takahashi == aoki) cout << "Draw" << endl;
	else if(takahashi > aoki) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int w; cin >> w;
	vector<int> ans;
	for(int i = 1; i <= 99; i++) ans.push_back(i);
	for(int i = 1; i <= 99; i++) ans.push_back(i*100);
	for(int i = 1; i <= 99; i++) ans.push_back(i*10000);
	int n = ans.size();
	cout << n << endl;
	for(int i : ans) cout << i << endl;
}

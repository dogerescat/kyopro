#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	deque<int> que;
	que.push_back(n);
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == 'R') que.push_front(i);	
		else que.push_back(i);
	}
	for(auto i : que) {
		cout << i << ' ';
	}
	cout << endl;
}

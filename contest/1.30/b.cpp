#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<int>> a(h, vector<int> (w));
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
	vector<vector<int>> b(w, vector<int> (h));
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) b[j][i] = a[i][j];
	for(int j = 0; j < w; j++) {
		for(int i = 0; i < h; i++) {
			cout << b[j][i] << ' ';
		}
		cout << endl;
	}	
}

#include<iostream>
#include<vector>
#include<map>
using namespace std;	
int N;
vector<int> v;
map<int, bool> h;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
		h[input] = false;
	}
	int s = 0, e = 0;
	long long cnt = 0;
	while (e < N) {
		//cout << "s: " << s << " e: " << e << endl;
		int val = v[e];
		while (h[val]) {
			cnt += (e - s);
			h[v[s++]] = false;
		}
		h[val] = true;
		e++;
	}
	cnt += (long long)(e - s) * (e - s + 1) / 2;
	cout << cnt << endl;
	return 0;
}
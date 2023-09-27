#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int p_size,m,n;
bool print = false;
int main() {
	cin >> p_size >> m >> n;
	vector<int> P_a;
	vector<int> P_b;
	unordered_map<int, int> h_a;
	unordered_map<int, int> h_b;
	int a_size =0;
	int b_size = 0;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		P_a.push_back(input);
		a_size += input;
	}

	for (int j = 0; j < n; j++) {
		int input;
		cin >> input;
		P_b.push_back(input);
		b_size += input;
	}
	h_a[0] = 1;
	h_b[0] = 1;
	h_a[a_size] = 1;
	h_b[b_size] = 1;

	for (int i = 0; i < P_a.size(); i++) {
		for (int j = 0; j < P_a.size(); j++) {
			if(print)cout << "i: " << i << " j: " << j << endl;
			int idx = 0;
			if (i == j) continue;
			else if (i < j) {
				for (int k = 0; k < P_a.size(); k++) {
					if (k >= i && k < j) idx += P_a[k];
				}
				h_a[idx]++;
				if (print) printf("h_a[%d]: %d\n", idx, h_a[idx]);
			}
			else {
				for (int k = 0; k < P_a.size(); k++) {
					if (k >= j && k < i) idx += P_a[k];
				}
				h_a[a_size - idx]++;
				if (print) printf("h_a[%d]: %d\n", a_size - idx, h_a[a_size - idx]);
			}
			
		}
	}

	for (int i = 0; i < P_b.size(); i++) {
		for (int j = 0; j < P_b.size(); j++) {
			if (print)cout << "i: " << i << " j: " << j << endl;
			int idx = 0;
			if (i == j) continue;
			else if (i < j) {
				for (int k = 0; k < P_b.size(); k++) {
					if (k >= i && k < j) idx += P_b[k];
				}
				h_b[idx]++;
				if (print) printf("h_b[%d]: %d\n", idx, h_b[idx]);
			}
			else {
				for (int k = 0; k < P_b.size(); k++) {
					if (k >= j && k < i) idx += P_b[k];
				}
				if(print)cout << "idx: " << idx << endl;
				h_b[b_size - idx]++;
				if (print) printf("h_b[%d]: %d\n", b_size - idx, h_b[b_size - idx]);
			}
		}
	}

	int ans = 0;
	for (auto iter = h_a.begin(); iter != h_a.end(); iter++) { // 음수 제거
		if (p_size - (iter->first) < 0) continue;
		if (print)printf("h_a[%d]: %d\n", iter->first, iter->second);
		if (print)printf("h_b[%d]: %d\n", p_size - (iter->first), h_b[p_size - (iter->first)]);
		if (print) cout << "ans+=" << h_a[iter->first] * h_b[p_size - (iter->first)] << endl;
		ans += h_a[iter->first] * h_b[p_size - (iter->first)];
	}
	cout << ans << endl;
	return 0;
}
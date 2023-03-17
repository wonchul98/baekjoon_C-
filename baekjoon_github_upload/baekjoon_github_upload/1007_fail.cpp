#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
double cal_vec(pair<int, int> f);
pair<int, int>make_vec(pair<int, int> f, pair<int, int> s);
pair<int, int>add_vec(pair<int, int> f, pair<int, int> s);
int main() {
	cout << fixed;
	cout.precision(6);
	freopen("input/1007_input.txt", "r", stdin);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> P;
		pair<int, int> p[20];
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> p[j].first >> p[j].second;
			P.push_back(p[j]);
		}
		sort(P.begin(), P.end());
		double minimum = 987654321;
		do {
			//cout << "현재 P: ";
			for (int i = 0; i < P.size(); i++) {
				//cout << P[i].first << "," << P[i].second << "/ ";
			}
			//cout << endl;
			pair<int, int> rst_vec = make_pair(0, 0);
			int iter = P.size() / 2;
			for (int i = 0; i < iter; i++) {
				rst_vec = add_vec(rst_vec, make_vec(P[i*2], P[i*2 + 1]));
			}
			minimum = min(minimum, cal_vec(rst_vec));
			//cout << "중간 점검 minimum: " << minimum << endl;
		} while (next_permutation(P.begin(), P.end()));
		cout << minimum << endl;
	}
	
	return 0;
}

double cal_vec(pair<int, int> f) {
	//cout << "cal_vec: " << f.first << "," << f.second << endl;
	return pow(pow((f.first), 2) + pow((f.second), 2), 0.5);
}

pair<int, int>make_vec(pair<int, int>f, pair<int, int>s) {
	//cout << "make_vec: (" << f.first << "," << f.second << ") + (" << s.first << "," << s.second << ")" << endl;
	return make_pair(f.first - s.first, f.second - s.second);
}

pair<int, int>add_vec(pair<int, int> f, pair<int, int> s) {
	//cout << "add_vec: (" << f.first << "," << f.second << ") + (" << s.first << "," << s.second << ")" << endl;
	return make_pair(f.first + s.first, f.second + s.second);
}
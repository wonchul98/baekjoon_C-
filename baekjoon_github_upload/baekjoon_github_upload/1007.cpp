#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
double cal_vec(pair<int, int> f);
int main() {
	cout << fixed;
	cout.precision(6);
	freopen("input/1007_input.txt", "r", stdin);
	int T, N;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> P;
		pair<int, int> p[20];
		double minimum = 987654321;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> p[j].first >> p[j].second;
			P.push_back(p[j]);
		}
		sort(P.begin(), P.end());
		int sel = N / 2;
		vector<bool> b(sel, false);
		b.insert(b.end(), sel, true);
		do {
			int sel_first = 0;
			int sel_second = 0;
			int usel_first = 0;
			int usel_second = 0;
			for (int j = 0; j < N; j++) {
				if (b[j]) {//selected ¿Í !selected°è»ê
					sel_first += P[j].first;
					sel_second += P[j].second;
				}
				else {
					usel_first += P[j].first;
					usel_second += P[j].second;
				}
			}
			minimum = min(minimum, cal_vec(make_pair(usel_first - sel_first, usel_second - sel_second)));
		} while (next_permutation(b.begin(), b.end()));
		cout << minimum << endl;
	}
	
	
	return 0;
}

double cal_vec(pair<int, int> f) {
	//cout << "cal_vec: " << f.first << "," << f.second << endl;
	return pow(pow((f.first), 2) + pow((f.second), 2), 0.5);
}

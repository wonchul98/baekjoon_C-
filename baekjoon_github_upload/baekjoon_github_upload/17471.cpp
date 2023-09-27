#include<iostream>
#include<vector>
using namespace std;
int N;
int c_amount[11];
vector<int> con_city[11];
void dfs(int city, int elec);
int main() {
	cin >> N;
	int min_citizen;
	for (int i = 1; i <= N; i++) {
		cin >> c_amount[i];
	}
	for (int i = 0; i < N; i++) {
		int con;
		cin >> con;
		for (int j = 0; j < con; j++) {
			int input;
			cin >> input;
			con_city[i].push_back(input);
		}
	}

	return 0;
}

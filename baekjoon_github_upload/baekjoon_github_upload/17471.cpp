#include<iostream>
#include<vector>
using namespace std;
int N;
int c_amount[11];
int city_elec[11];
vector<int> con_city[11];

bool visited[11] = { false, };
bool print = false;
int dfs(int city, int elec);
int main() {
	cin >> N;
	int min_citizen = 987654321;
	for (int i = 1; i <= N; i++) {
		cin >> c_amount[i];
	}
	for (int i = 1; i <= N; i++) {
		int con;
		cin >> con;
		for (int j = 0; j < con; j++) {
			int input;
			cin >> input;
			con_city[i].push_back(input);
		}
	}
	bool can_make = false;
	for (int i = 1; i <= (1 << N) - 2; i++) { //선거구 BF
		for (int j = 1; j <= N; j++) visited[j] = false;
		for (int j = 0; j < N; j++) { //도시별 선거구 확인
			if (i & (1 << j)) {
				city_elec[j + 1] = 1;
			}
			else city_elec[j + 1] = 0;
		}
		if (print) {
			for (int j = 1; j <= N; j++) {
				cout << city_elec[j];
			}
			cout << "\n";
		}
		bool z_check = false; //0 선거구 
		bool o_check = false; //1 선거구
		int z_sum = 0;
		int o_sum = 0;
		for (int j = 1; j <= N; j++) {
			if (z_check && o_check) break;
			if (city_elec[j] == 0 && !z_check) {
				z_check = true;
				z_sum = dfs(j, 0);
				if (print) cout << "z_sum: " << z_sum << endl;
			}
			if (city_elec[j] == 1 && !o_check) {
				o_check = true;
				o_sum = dfs(j, 1);
				if (print) cout << "o_sum: " << o_sum << endl;
			}
		}
		bool flag = true;
		for (int j = 1; j <= N; j++) {
			if (!visited[j]) { //방문 안한 도시가 있는경우 false
				flag = false;
				break;
			}
		}

		if (flag) {
			if (print) cout << "차이: " << abs(o_sum - z_sum) << endl;
			can_make = true;
			min_citizen = min(min_citizen, abs(o_sum - z_sum));
		}


	}
	if (can_make)cout << min_citizen << endl;
	else cout << "-1" << endl;

	return 0;
}
int dfs(int city, int elec) {
	if (print) printf("dfs(%d, %d)\n", city, elec);
	visited[city] = true;
	int rst = c_amount[city];
	for (int i = 0; i < con_city[city].size(); i++) {
		int next_city = con_city[city][i];
		if (print) cout << "next_city: " << next_city << endl;
		if (city_elec[next_city] == elec && !visited[next_city]) rst += dfs(next_city, elec);
	}
	if(print) cout << "return: " << rst << endl;
	return rst;
}
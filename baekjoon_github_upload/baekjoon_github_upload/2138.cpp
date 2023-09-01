#include<iostream>
#include<string>
using namespace std;
string f_arr;
string s_arr;
int t_arr[100001];
int switch_arr[100001];
bool validation();
int N;
void make_switch();
int min_cost = 987654321;
int cost;
int main() {
	
	cin >> N;
	cin >> f_arr;
	cin >> s_arr;
	for (int i = 0; i < N; i++) {
		if (f_arr[i] != s_arr[i]) t_arr[i + 1] = 1;
		else t_arr[i + 1] = 0;
	}
	// for (int i = 1; i <= N; i++) cout << t_arr[i] << " ";
	switch_arr[0] = 0;
	//case 1
	cost = 0;
	switch_arr[1] = 0;
	make_switch();
	
		
	//case 2
	cost = 1;
	switch_arr[1] = 1;
	make_switch();
	
	if (min_cost != 987654321) {
		cout << min_cost << endl;
	}
	else cout << "-1" << endl;

	return 0;
}
void make_switch() {
	for (int i = 2; i <= N; i++) {
		if (switch_arr[i - 2] + switch_arr[i - 1] == 1) { //둘중 하나가 1인 경우
			if (t_arr[i - 1] == 1) switch_arr[i] = 0;
			else {
				switch_arr[i] = 1;
				cost++;
			}
		}
		else {
			if (t_arr[i - 1] == 1) {
				switch_arr[i] = 1;
				cost++;
			}
			else switch_arr[i] = 0;
		}
	}
	/*for (int i = 1; i <= N; i++) {
		cout << switch_arr[i] << " ";
	}
	cout << "\n";*/
	if (validation()) {
		//cout << "valid" << endl;
		min_cost = min(min_cost, cost);
	}
}

bool validation() {
	if (t_arr[N] == 0) {
		if (switch_arr[N - 1] + switch_arr[N] == 1) return false;
		else return true;
	}
	else{
		if (switch_arr[N - 1] + switch_arr[N] != 1) return false;
		else return true;
	}
}
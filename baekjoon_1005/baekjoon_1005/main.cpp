#include<iostream>

using namespace std;

int number;
int N, K; //N:건물 수, K: 규칙 수
int W;
int cost[1000] = { 0, };
int visitedarr[1000][1000] = { 0, };
int map[1000][1000] = { 0, };

void cal();
void clear();

int main() {
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> N >> K;
		int input1;
		int input2;
		for (int j = 0; j < N; j++) {
			cin >> input1;
			cost[j] = input1;
		}
		for (int j = 0; j < K; j++) {
			cin >> input1 >> input2;
			map[input1][input2] = 1;
		}
		cal();
		
	}
}

void cal() {}

void clear() {
	for (int i = 0; i < N; i++) {
		cost[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visitedarr[i][j] = 0;
			map[i][j] = 0;
		}
	}
}
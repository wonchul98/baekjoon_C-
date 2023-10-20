#include<iostream>
#include<vector>
using namespace std;

vector<int> v;


void DFS(int i, int val);
void logic();

int end[10] = { 0,5,4,5,3,5,3,4,5,0 };
int road[10][6] = {
		{0,0,0,0,0,0},
		{0,2,4,6,8,10}, //1
		{10,13,16,19,25,0}, //2
		{10,12,14,16,18,20}, //3
		{20,22,24,25,0,0}, //4
		{20,22,24,26,28,30},//5
		{25,30,35,40,0,0}, //6
		{30,28,27,26,25,0}, //7
		{30,32,34,36,38,40}, //8
		{0,0,0,0,0,0} //9
};

struct loc {
	int route, idx;
};

int main() {
	for (int i = 0; i < 10; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 1; i <= 4; i++) {
		DFS(0, i);
	}

	return 0;
}

void DFS(int i, int val) {
	/*i==10이면 최대값과 비교*/

	/*i가 이미 끝난 상황이면 리턴*/
	
	/*i에 val값 더하기*/


	for (int j = 1; i <= 4; j++) {
		
		DFS(i + 1, j);
	
	}

}

void logic() {

}
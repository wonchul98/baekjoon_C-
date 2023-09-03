#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int N;
bool print = false;
int c_arr[200001] = { 0, };
int total = 0;
int now_total = 0;
bool visited_size[2001];
int ans[200001];


struct ball {
	int idx;
	int b_color;
	int b_size;
};
struct comp {
	bool operator()(ball& a, ball& b) {
		if (a.b_size == b.b_size) return a.b_color < b.b_color;
		return a.b_size < b.b_size;
	}
};

ball pq[200001];



int main() {
	constexpr auto endl{ '\n' };
	cin.tie(nullptr);

	freopen("input/10800_input.txt", "r", stdin);
	cin >> N;


	for (int i = 0; i <= 2000; i++) {
		visited_size[i] = false;
	}
	
	for (int i = 0; i < N; i++) {
		int left, right;
		cin >> left >> right;
		ball b;
		b.idx = i;
		b.b_color = left;
		b.b_size = right;
		pq[i] = b;
	}
	sort(pq, pq + N, comp());
	for(int i = 0 ; i < N ; i++) {
		ball top = pq[i];
		int color = top.b_color;
		int size = top.b_size;
		int index = top.idx;

		total += size;
		if (!visited_size[size]) {
			now_total = total;
		}//처음 방문하는 사이즈에 대해서는 update
		visited_size[size] = true;
		c_arr[color] += size;
		if(print) cout << "total: " << total << " now_total: " << now_total << " color: " << color << " c_arr: " << c_arr[color] << " size:" << size  << endl;
		if(print) cout << now_total - c_arr[color] << endl;
		if (i != 0 && (pq[i - 1].b_color == color) && (pq[i - 1].b_size == size)) ans[index] = ans[pq[i - 1].idx];
		else ans[index] = now_total - c_arr[color];
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
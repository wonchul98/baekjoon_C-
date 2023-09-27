#define ll long long
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
struct INFO {
	int x, y;
};
INFO pt[5];

ll DFS(int loc, int pt_idx);
vector<char> q;
int N;
int nn;
bool print = true;

ll calc();
int main() {
	ll maximum = -9223372036854775807;
	cin >> N;
	nn = (N + 1) / 2;
	for (int i = 0; i < N; i++) {
		char input;
		cin >> input;
		q.push_back(input);
	}
	if (N == 1) {
		cout << q.front() << endl;
		return 0;
	}
	cout << DFS(0, 0) << endl;
	return 0;
}

ll DFS(int loc,int pt_idx) {
	ll rst;
	if (print)printf("DFS(%d, %d)\n", loc, pt_idx);
	if (loc > N - 2) {
		rst = calc();
		if (print)cout << "calc: " << rst << endl;
		return rst;
	}

	rst = -9223372036854775807;

	pt[pt_idx].x = loc;
	rst = max(rst, DFS(loc + 4, pt_idx + 1));
	pt[pt_idx].x = 0;
	rst = max(rst, DFS(loc + 2, pt_idx));
	
	return rst;
}
ll calc() {
    int pt_idx = 0;
    queue<ll> real_q;  // 데이터 타입 변경

    for (int i = 0; i < q.size(); i++) {
        if (print) cout << "processing: " << q[i] << endl;
        if (i == pt[pt_idx].x) {
            pt_idx++;
            if (print) cout << "괄호 연산" << q[i + 1] << endl;
            if (print) cout << "다음 괄호: " << pt[pt_idx].x << endl;
            switch (q[i + 1]) {
            case '+': {
                real_q.push(q[i] - '0' + q[i + 2] - '0');
                break;
            }
            case '-': {
                real_q.push(q[i] - '0' - (q[i + 2] - '0'));
                break;
            }
            case '*': {
                real_q.push((q[i] - '0') * (q[i + 2] - '0'));
                break;
            }
            }
            i += 2;
        }
        else if (q[i] >= '0' && q[i] <= '9') {
            real_q.push(q[i] - '0');
        }
        else {
            real_q.push(q[i]);  // 연산자 저장
        }
    }
    ll rst = real_q.front();
    real_q.pop();
    while (!real_q.empty()) {
        char op = real_q.front();
        real_q.pop();
        ll num = real_q.front();
        real_q.pop();
        switch (op) {
        case '+': {
            rst += num;
            break;
        }
        case '-': {
            rst -= num;
            break;
        }
        case '*': {
            rst *= num;
            break;
        }
        }
    }
    return rst;
}

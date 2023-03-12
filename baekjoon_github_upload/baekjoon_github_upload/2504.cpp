#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main() {
	stack<char> op_s[15];
	stack<int> num_s[15];
	int cur_s = -1;
	string input;
	//freopen("input/2504_input.txt", "r", stdin);
	cin >> input;
	int ans = 0;
	bool valid = true;
	stack<char> v;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ']') {
			if (v.empty() || v.top()!='[') {
				valid = false;
				break;
			}
			else {
				v.pop();
			}
		}
		else if (input[i] == ')') {
			if (v.empty() || v.top() != '(') {
				valid = false;
				break;
			}
			else {
				v.pop();
			}
		}
		else {
			v.push(input[i]);
		}
	}
	if (valid) {
		for (int i = 0; i < input.size(); i++) {
			//printf("input: %c, cur_s: %d\n", input[i], cur_s);
			if (input[i] == '(') {
				if (i > 0 && (input[i - 1] == ')' || input[i - 1] == ']') && cur_s > -1) {
					op_s[cur_s].push('+');
					//printf("op_s[%d].push('+')\n", cur_s);
				}
				else if (i > 0 && (input[i - 1] == '(' || input[i - 1] == '[') && cur_s > -1) {
					op_s[cur_s].push('*');
					//printf("op_s[%d].push('*')\n", cur_s);
				}
				cur_s++;
				num_s[cur_s].push(2);
				//printf("cur_s: %d, push 2\n", cur_s);
			}
			if (input[i] == '[') {
				if (i > 0 && (input[i - 1] == ')' || input[i - 1] == ']') && cur_s > -1) {
					op_s[cur_s].push('+');
					//printf("op_s[%d].push('+')\n", cur_s);
				}
				else if (i > 0 && (input[i - 1] == '(' || input[i - 1] == '[') && cur_s > -1) {
					op_s[cur_s].push('*');
					//printf("op_s[%d].push('*')\n", cur_s);
				}
				cur_s++;
				num_s[cur_s].push(3);
				//printf("cur_s: %d, push 3\n", cur_s);
			}
			if (input[i] == ')' || input[i] == ']') {//cur_stack에 대해 연산
				int rst = num_s[cur_s].top();
				num_s[cur_s].pop();
				while (!op_s[cur_s].empty()) {
					if (op_s[cur_s].top() == '+') {
						rst += num_s[cur_s].top();
						num_s[cur_s].pop();
						op_s[cur_s].pop();
					}
					else {
						rst *= num_s[cur_s].top();
						num_s[cur_s].pop();
						op_s[cur_s].pop();
					}
				}
				cur_s--;
				if (cur_s >= 0) {
					num_s[cur_s].push(rst);
					//printf("num_s[%d].push(%d)\n", cur_s, rst);
				}
				else {
					ans += rst;
					//printf("ans: %d\n", ans);
				}
			}
		}
	}
	cout << ans << endl;
	
}
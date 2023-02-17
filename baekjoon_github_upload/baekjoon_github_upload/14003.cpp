#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
using namespace std;

int max_idx = 1;
int main_branch[1000001] = {0,};
int N;

struct node {
	int index;
	int value;
	node* left;
	node* right;
	node* parent;
};

class tree {
public:
	node* root;
	tree(int idx, int val) {//tree의 root지정
		node* temp;
		temp = (node*)calloc(1, sizeof(node));
		temp->left = nullptr;
		temp->right = nullptr;
		temp->parent = nullptr;
		temp->index = idx;
		temp->value = val;
		this->root = temp;
	}
	void insert(int val) {
		p_insert(this->root, 1, val);
	}
	void del_inorder(node* n) {
		p_del_inorder(n);
	}

private:
	void p_insert(node* n, int idx, int val) {
		//cout << "inserting: " << val << "index: " << idx << endl;
		node* temp;
		temp = (node*)calloc(1, sizeof(node));
		temp->value = val;
		temp->index = idx;
		//cout << "n: " << n->value << endl;
		if (n->value == temp->value) {
			//cout << "same: " << n->value << endl;
			return;
		}
		if (n->value > temp->value) {
			if (n->left == nullptr) {
				n->left = temp;
				temp->parent = n;
				//printf("temp: %d, temp->parent: %d, idx: %d\n", temp->value, temp->parent->value, idx);
				//printf("max_idx: %d, main_branch[%d]: %d\n", max_idx, idx, main_branch[idx]);
				if (idx == max_idx && main_branch[idx] > temp->value) {
					//printf("smaller: %d\n", temp->value);
					main_branch[idx] = temp->value;
					if (n->parent != nullptr && n->right == nullptr) {
						if (isleftchild(n)) {
							n->parent->left = temp;
							temp->parent = n->parent;
						}
						else {
							n->parent->right = temp;
							temp->parent = n->parent;
						}
					}
				}
			}
			else {
				free(temp);
				p_insert(n->left, idx, val);
			}
		}
		else if (n->value < temp->value) {
			if (n->right == nullptr) {
				n->right = temp;
				temp->parent = n;
				temp->index = ++idx;
				if (max_idx > 3500) printf("temp: %d, temp->parent: %d, idx: %d\n", temp->value, temp->parent->value, idx);
				if (idx > max_idx) {
					max_idx = idx;
					if(max_idx > 3500)cout << "max_idx 갱신: " << max_idx << endl;
					write(temp);
				}
			}
			else {
				free(temp);
				p_insert(n->right, idx+1, val);
			}
		}
	}
	void p_del_inorder(node* n) {
		//printf("del(%d)\n", n->value);
		if (n->left != nullptr) { p_del_inorder(n->left); }
		if (n->right != nullptr) { p_del_inorder(n->right); }
		free(n);
		//printf("return of del\n");
		return;
	}

	void deleteNode(node* n) {
		if (n->parent != nullptr) {
			if (isleftchild(n)) {
				n->parent->left = n->left;
				n->left->parent = n->parent;
			}
			else {
				n->parent->right = n->left;
				n->left->parent = n->parent;
			}
			free(n);
		}
		else { //n이 root인 case
			this->root = n->left;
			free(n);
		}
	}

	bool isleftchild(node* n) {
		if (n->parent->value < n->value) {
			return false;
		}
		return true;
	}
	void write(node *n) {
		while (n->parent != nullptr) {
			if (max_idx > 3500)cout << "n->val: " << n->value << " " << n->index << endl;
			if (!isleftchild(n)) {
				if (max_idx > 3500) cout << "write" << endl;
				if (main_branch[n->index] == n->value) break;
				if (max_idx > 3500) cout << "write" << endl;
				main_branch[n->index] = n->value;
				if (max_idx > 3500) printf("main_branch[%d]: %d\n", n->index, n->value);
			}
			else {
				if (n->parent->right != nullptr) {
					del_inorder(n->parent->right);
					n->parent->right = nullptr;
					deleteNode(n->parent);
				}
			}
			if (n->index == 2 && !isleftchild(n)) {
				main_branch[1] = n->parent->value;
			}
			n = n->parent;

		}
	}
};

int main() {
	freopen("input/14003_input.txt", "r", stdin);
	cin >> N;
	int input;
	cin >> input;
	tree maintree(1, input);
	for (int i = 0; i < N - 1; i++) {
		cin >> input;
		maintree.insert(input);
	}
	for (int i = 1; i <= max_idx; i++) {
		cout << main_branch[i] << " ";
	}
	cout << endl;
	return 0;
}


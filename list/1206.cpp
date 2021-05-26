#include <bits/stdc++.h>
using namespace std;

static const int SKIPLIST_P_VAL = RAND_MAX / 2, MAX_LEVEL = 16;
class Skiplist {
static const int SKIPLIST_P_VAL = RAND_MAX / 2, MAX_LEVEL = 16;
public:
	struct Node {

		int val;
		vector<Node*> level;
		Node(int num, int size = MAX_LEVEL) : val(num), level(size) {}
	};
private:
	Node head_;
	int maxlevel_ = 1;
private:
	static int random_level() {
		int level = 1;
		while (rand() < SKIPLIST_P_VAL && level < MAX_LEVEL)
			++level;
		return level;
	}
	vector<Node*> _search(int target) {
		Node *cur = &head_;
		vector<Node*> pres(MAX_LEVEL);
		for (int i = maxlevel_ - 1; i >= 0; --i) {
			while (cur->level[i] && cur->level[i]->val < target) {
				cur = cur->level[i];
			}
			pres[i] = cur;
		}
		return pres;
	}
public:
	Skiplist() : head_(INT_MIN, MAX_LEVEL) {}
<<<<<<< HEAD
	~Skiplist();
=======
	// ~Skiplist() {};
>>>>>>> 40961d9bad6c2ac3682f3e98d2f93a03069b671c
	// search
	bool search(int target) {
		Node *pre = _search(target)[0];
		return pre->level[0] && pre->level[0]->val == target;
	}
	// add
	void add(int num) {
		auto pres = _search(num);
		int level = random_level();
		if (level > maxlevel_) {
			for (int i = maxlevel_; i < level; ++i)
				pres[i] = &head_;
			maxlevel_ = level;
		}
		Node *cur = new Node(num, level);
		for (int i = level - 1; i >= 0; --i) {
			cur->level[i] = pres[i]->level[i];
			pres[i]->level[i] = cur;
		}
	}
	// erase
	bool erase(int num) {
		auto pres = _search(num);
		if (!pres[0]->level[0] || pres[0]->level[0]->val != num)
			return false;
		Node *del = pres[0]->level[0];
		for (int i = 0; i < maxlevel_; ++i) {
			if (pres[i]->level[i] == del) {
				pres[i]->level[i] = del->level[i];
			}
		}
		delete del;
		while (maxlevel_ > 1 && !head_.level[maxlevel_ - 1])
			--maxlevel_;
		return true;
	}
<<<<<<< HEAD
=======

>>>>>>> 40961d9bad6c2ac3682f3e98d2f93a03069b671c
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main() {
	return 0;
}

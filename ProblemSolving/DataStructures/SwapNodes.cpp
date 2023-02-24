#include <iostream>
#include <vector>

using namespace std;


class Node {
public:
	int index_;
	Node *left_ = nullptr, *right_ = nullptr;
};

class Tree {
protected:
	void FreeR(Node *n) {
		if (n) {
			FreeR(n->left_);
			FreeR(n->right_);
			delete n;
		}
	}
	void PrintInOrderR(ostream &os, Node *n) {
		if (n) {
			PrintInOrderR(os, n->left_);
			os << n->index_ << " ";
			PrintInOrderR(os, n->right_);
		}
	}
public:
	Node *root_;
	void Load(istream &is) {
		int n_nodes;
		is >> n_nodes;
		// allocate memory for n_nodes nodes
		// (!!) Simpler:
		// root_ = new Node[n_nodes] // (no need to use the extra variable)
		Node *node_array = new Node[n_nodes];
		// assign the indexes to the nodes
		for (int i = 0; i < n_nodes; i++) {
			node_array[i].index_ = i+1;
		}
		// assign the children relationships
		for (int i = 0; i < n_nodes; i++) {
			int left_index, right_index;
			is >> left_index >> right_index;
			if (left_index != -1)
				node_array[i].left_ = &node_array[left_index-1];
			if (right_index != -1)
				node_array[i].right_ = &node_array[right_index-1];
		}
		root_ = node_array;
	}
	Tree(istream &is) {
		Load(is);
	}
	void PrintInOrder(ostream &os) {
		PrintInOrderR(os, root_);
		os << endl;
	}
	void Swap(int k) {
		vector<Node*> level, next_level;
		level.push_back(root_);
		int depth = 1;
		while (!level.empty()) {
			if (depth % k == 0) {
				for (Node* n : level) {
					Node *tmp = n->left_;
					n->left_ = n->right_;
					n->right_ = tmp;
				}
			}
			for (Node * n : level) {
				if (n->left_)
					next_level.push_back(n->left_);
				if (n->right_)
					next_level.push_back(n->right_);
			}
			level = next_level;
			next_level.clear();
			depth++;
		}
	}
	void Free() {
		// (!!) THIS WON'T WORK! Nodes' memory is allocated as a continuous block
		// FreeR(root_);
		// root_ points to the continuous block, and we can't free a chosen 
		// sub-block (doesn't make sense?)
		delete [] root_;
	}
	~Tree() {
		Free();
	}
};


int main() {
	Tree t(cin);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k;
		cin >> k;
		t.Swap(k);
		t.PrintInOrder(cout);
	}
	return 0;
}

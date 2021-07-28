#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

enum alg_strategy {
	recursive,
	iterative
};

void preOrder(Node *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		_preOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		_preOrder_ite(root);
}

void _preOrder_rec(Node *root) {
    if (root) {
        cout << root->data << " ";
        _preOrder_rec(root->left);
        _preOrder_rec(root->right);
    }
}

const char CH_LEFT=0;
const char CH_RIGHT=1;

void _preOrder_ite(Node *root) {
	stack<Node*> st_nodes;
    stack<char> st_path;
    Node *cur_node = root;
    while (true) {
        if (cur_node) {
            // Print current node (first)
            cout << cur_node->data << " ";
            // Go to the left branch
            st_nodes.push(cur_node);
            st_path.push(CH_LEFT);
            cur_node = cur_node->left;
        }
        else {
            // Walk up until the parent is reached from its
            // left child, or we get to the root
            while (!st_path.empty() && st_path.top() == CH_RIGHT) {
                st_path.pop();
                st_nodes.pop();
            }
            if (st_path.empty()) {
                break;
            }
            // The top of st_path is CH_LEFT
            cur_node = st_nodes.top();
            st_path.pop();
            // The left branch of cur_node has been traversed,
            // go to the right
            st_path.push(CH_RIGHT);
            cur_node = cur_node->right;
        }
    }
}

void _inOrder_ite(Node *root) {
    stack<Node*> st_nodes;
    stack<char> st_path;
    Node *cur_node = root;
    while (true) {
        if (cur_node) {
            // Go to the left branch
            st_nodes.push(cur_node);
            st_path.push(CH_LEFT);
            cur_node = cur_node->left;
        }
        else {
            // Walk up until the parent is reached from its
            // left child, or we get to the root
            while (!st_path.empty() && st_path.top() == CH_RIGHT) {
                st_path.pop();
                st_nodes.pop();
            }
            if (st_path.empty()) {
                break;
            }
            // The top of st_path is CH_LEFT
            cur_node = st_nodes.top();
            st_path.pop();
            // The left branch of cur_node has been traversed
            // Print current node
            cout << cur_node->data << " ";
            // Go to the right branch
            st_path.push(CH_RIGHT);
            cur_node = cur_node->right;
        }
    }
}

void _postOrder_ite(Node *root) {
    stack<Node*> st_nodes;
    stack<char> st_path;
    Node *cur_node = root;
    while (true) {
        if (cur_node) {
            // Go to the left branch
            st_nodes.push(cur_node);
            st_path.push(CH_LEFT);
            cur_node = cur_node->left;
        }
        else {
            // Walk up until the parent is reached from its
            // left child, or we get to the root
            while (!st_path.empty() && st_path.top() == CH_RIGHT) {
                st_path.pop();
				// Print the node after visiting its right branch
                cout << st_nodes.top()->data << " ";
                st_nodes.pop();
            }
            if (st_path.empty()) {
                break;
            }
            // The top of st_path is CH_LEFT
            cur_node = st_nodes.top();
            st_path.pop();
            // The left branch of cur_node has been traversed
            // Go to the right branch
            st_path.push(CH_RIGHT);
            cur_node = cur_node->right;
        }
    }
}


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree._preOrder_rec(root);
    return 0;
}

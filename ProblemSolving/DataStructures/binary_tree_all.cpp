#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// Sign template function
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

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

// pre-order, in-order, and post-order tree traversals

void preOrder(Node *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		_preOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		_preOrder_ite2(root);
}

void inOrder(Node *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		_inOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		_inOrder_ite2(root);
}

void postOrder(Node *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		_postOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		_postOrder_ite(root);
}

// tree traversals - recursive algs

void _preOrder_rec(Node *root) {
    if (root) {
        cout << root->data << " ";
        _preOrder_rec(root->left);
        _preOrder_rec(root->right);
    }
}

void _inOrder_rec(Node *root) {
    if (root) {
        _preOrder_rec(root->left);
        cout << root->data << " ";
        _preOrder_rec(root->right);
    }
}

void _postOrder_rec(Node *root) {
    if (root) {
        _preOrder_rec(root->left);
        _preOrder_rec(root->right);
        cout << root->data << " ";
    }
}

// tree traversals - iterative algs

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

// Iterative solutions, simpler

void _preOrder_ite2(Node *root) {
    // This stack stores only nodes whose left branches hasn't been traversed yet
    // When the left branch is entirely visited, the node is popped
    stack<Node*> st_nodes;
    Node *current = root;
    while (current || !st_nodes.empty()) {
        if (current) {
            cout << current->data << " ";
            st_nodes.push(current);
            current = current->left;
        }
        else {
            // Go to the latest parent that is reached from its left child,
            // to its right child
            current = st_nodes.top()->right;
            st_nodes.pop();
        }
    }
}

void _inOrder_ite2(Node *root) {
    // This stack stores only nodes whose left branches hasn't been traversed yet
    stack<Node*> st_nodes;
    Node *current = root;
    while (current || !st_nodes.empty()) {
        if (current) {
            st_nodes.push(current);
            current = current->left;
        }
        else {
            // Go to the latest parent that is reached from its left child,
            // to its right child
            current = st_nodes.top();
            cout << current->data << " ";
            current = current->right;
            st_nodes.pop();
        }
    }
}

// void _postOrder_ite2(Node *root) {
//     stack<Node*> st_nodes;
//     Node *current = root;
//     while (current || !st_nodes.empty()) {
//         if (current) {
//             st_nodes.push(current);
//             current = current->left;
//         }
//         else {
//             // Go to the latest parent that is reached from its left child,
//             // to its right child
//             current = st_nodes.top()->right;
//             st_nodes.pop();
//         }
//     }
// }

int height(Node *root, alg_strategy strategy = alg_strategy::iterative) {
    int _height;
    switch (strategy)
    {
    case alg_strategy::iterative:
        _height = _height_ite2(root);
        break;
    case alg_strategy::recursive:
        _height = _height_rec(root);
        break;
    default:
        break;
    }
    return _height;
}

// BT height - recursive

int _height_rec(Node *node) {
    if (node)
        return max(_height_rec(node->left), _height_rec(node->right)) + 1;
    else
        return -1;
}

// BT height iterative - like preorder traversal

int _height_ite1(Node *root) {
    // Perform iterative traversal, like _preOrder_ite2(), and save both current
    // level and maximum level
    stack<pair<Node*, int>> st_nodes_hts;
    Node *current = root;
    int cur_level = 0, max_level = 0;
    while (current || !st_nodes_hts.empty()) {
        if (current) {
            // check (and update) maximum level in the tree
            if (cur_level > max_level)
                max_level = cur_level;
            st_nodes_hts.push(pair<Node*, int>(current, cur_level));
            current = current->left;
            cur_level++;
        }
        else {
            current = st_nodes_hts.top().first;
            cur_level = st_nodes_hts.top().second;
            st_nodes_hts.pop();
            current = current->right;
            cur_level++;
        }
    }
    return max_level;
}

// BT height iterative - BFS
// scan whole levels of nodes consequently
// Simpler than the previous one

int _height_ite2(Node *root) {
    vector<Node*> v_nodes, v_nodes_new;
    if (root) {
        v_nodes.push_back(root);
    }
    int level = -1;
    while (!v_nodes.empty()) {
        // for each next level, add all existing childs as
        // the new sequence
        v_nodes_new.clear();
        for (Node* n : v_nodes) {
            if (n->left)
                v_nodes_new.push_back(n->left);
            if (n->right)
                v_nodes_new.push_back(n->right);
        }
        v_nodes = v_nodes_new;
        level++;
    }
    return level;
}


    Node * insert(Node * root, int data) {
        Node *n = root;
        while (true) {
            if (data < n->data) {
                if (n->left)
                    n = n->left;
                else {
                    n->left = new Node(data);
                    break;
                }
            }
            else if (data > n->data) {
                if (n->right)
                    n = n->right;
                else {
                    n->right = new Node(data);
                    break;
                }
            }
            else {
                break;
            }
        }
        return root;
    }

// Breadth First Search printing

void levelOrder(Node * root) {
    deque<Node*> queue;
    if (root)
        queue.push_back(root);
    Node *cur;
    while (!queue.empty()) {
        cur = queue.front();
        cout << cur->data << " ";
        if (cur->left)
            queue.push_back(cur->left);
        if (cur->right)
            queue.push_back(cur->right);
        queue.pop_front();
    }
}

// Lowest Common Ancestor (LCA)
// O(log(n)) time complexity

Node* lca(Node* root, int v1, int v2) {
    Node *n = root;
    // Calculate differences between values & current node data
    int dif1 = sgn(n->data - v1), dif2 = sgn(n->data - v2);
    while (dif1 && dif2 && (dif1 == dif2))
    {
        // current data greater than both values
        if (dif1 == 1) {
            n = n->left;
        }
        // dif1 == -1
        // current data smaller than both values
        else {
            n = n->right;
        }
        dif1 = sgn(n->data - v1), dif2 = sgn(n->data - v2);
    }
    return n;
}

// Tree top view
// O(n) time complexity (n - number of nodes)

deque<int> topView(Node *root) {
    deque<int> result;
    // x - horizontal coordinate of nodes
    int cur_x = 0;
    int max_x(cur_x), min_x(cur_x);
    deque<pair<Node*, int>> bfs_queue;
    if (root) {
        // starting with root and 0 coord
        bfs_queue.emplace_back(root, cur_x);
        result.push_front(root->data);
    }
    Node *n;

    // Perform BFS (level order) traversal
    while(!bfs_queue.empty()) {
        n = bfs_queue.front().first;
        cur_x = bfs_queue.front().second;
        // push node to the viewed nodes list
        if (cur_x < min_x) {
            min_x = cur_x;
            result.push_front(n->data);
        }
        if (cur_x > max_x) {
            max_x = cur_x;
            result.push_back(n->data);
        }
        if (n->left)
            bfs_queue.emplace_back(n->left, cur_x - 1);
        if (n->right)
            bfs_queue.emplace_back(n->right, cur_x + 1);
        bfs_queue.pop_front();
    }
    return result;
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
  
	myTree._preOrder_ite2(root);
    return 0;
}

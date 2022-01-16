#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "..\common.hpp"

using namespace std;

// Sign template function
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template <typename T1, typename T2, typename T3>
struct triple {
    triple(T1 _first, T2 _second, T3 _third)
        :first(_first), second(_second), third(_third) {}
    triple() {}
    T1 first;
    T2 second;
    T3 third;
};

template<typename T>
class Node {
    public:
        T data;
        Node<T> *left;
        Node<T> *right;
        Node<T>(T d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

template<typename T>
class Solution {
    public:
  		Node<T>* insert(Node<T>* root, T data) {
            if(root == NULL) {
                return new Node<T>(data);
            } else {
                Node<T>* cur;
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

vector<T> preOrder(Node<T> *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		return _preOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		return _preOrder_ite2(root);
}

vector<T> inOrder(Node<T> *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		return _inOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		return _inOrder_ite2(root);
}

vector<T> postOrder(Node<T> *root, alg_strategy strategy=alg_strategy::iterative) {
	if (strategy == alg_strategy::recursive)
		return _postOrder_rec(root);
	else if (strategy == alg_strategy::iterative)
		return _postOrder_ite(root);
}

// tree traversals - recursive algs
vector<T> _preOrder_rec(Node<T> *root) {
    vector<T> sequence;
    _preOrder_rec_r(root, sequence);
    return sequence;
}

void _preOrder_rec_r(Node<T> *root, vector<T> &sequence) {
    if (root) {
        sequence.push_back(root->data);
        _preOrder_rec_r(root->left, sequence);
        _preOrder_rec_r(root->right, sequence);
    }
}

vector<T> _inOrder_rec(Node<T> *root) {
    vector<T> sequence;
    _inOrder_rec_r(root, sequence);
    return sequence;
}

void _inOrder_rec_r(Node<T> *root, vector<T> &sequence) {
    if (root) {
        _inOrder_rec_r(root->left, sequence);
        sequence.push_back(root->data);
        _inOrder_rec_r(root->right, sequence);
    }
}

vector<T> _postOrder_rec(Node<T> *root) {
    vector<T> sequence;
    _postOrder_rec_r(root, sequence);
    return sequence;
}

void _postOrder_rec_r(Node<T> *root, vector<T> &sequence) {
    if (root) {
        _postOrder_rec_r(root->left, sequence);
        _postOrder_rec_r(root->right, sequence);
        sequence.push_back(root->data);
    }
}

// tree traversals - iterative algs

const char CH_LEFT=0;
const char CH_RIGHT=1;

vector<T> _preOrder_ite(Node<T> *root) {
    vector<T> sequence;
	stack<Node<T>*> st_nodes;
    stack<char> st_path;
    Node<T> *cur_node = root;
    while (true) {
        if (cur_node) {
            // Print current node (first)
            sequence.push_back(cur_node->data);
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
    return sequence;
}

vector<T> _inOrder_ite(Node<T> *root) {
    vector<T> sequence;
    stack<Node<T>*> st_nodes;
    stack<char> st_path;
    Node<T> *cur_node = root;
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
            sequence.push_back(cur_node->data);
            // Go to the right branch
            st_path.push(CH_RIGHT);
            cur_node = cur_node->right;
        }
    }
    return sequence;
}

vector<T> _postOrder_ite(Node<T> *root) {
    vector<T> sequence;
    stack<Node<T>*> st_nodes;
    stack<char> st_path;
    Node<T> *cur_node = root;
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
                sequence.push_back(st_nodes.top()->data);
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
    return sequence;
}

// Iterative solutions, simpler

vector<T> _preOrder_ite2(Node<T> *root) {
    // This stack stores only nodes whose left branches hasn't been traversed yet
    // When the left branch is entirely visited, the node is popped
    vector<T> sequence;
    stack<Node<T>*> st_nodes;
    Node<T> *current = root;
    while (current || !st_nodes.empty()) {
        if (current) {
            sequence.push_back(current->data);
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
    return sequence;
}

vector<T> _inOrder_ite2(Node<T> *root) {
    // This stack stores only nodes whose left branches hasn't been traversed yet
    vector<T> sequence;
    stack<Node<T>*> st_nodes;
    Node<T> *current = root;
    while (current || !st_nodes.empty()) {
        if (current) {
            st_nodes.push(current);
            current = current->left;
        }
        else {
            // Go to the latest parent that is reached from its left child,
            // to its right child
            current = st_nodes.top();
            sequence.push_back(current->data);
            current = current->right;
            st_nodes.pop();
        }
    }
    return sequence;
}

// vector<T> _postOrder_ite2(Node<T> *root) {
//     vector<T> sequence;
//     stack<Node<T>*> st_nodes;
//     Node<T> *current = root;
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

int height(Node<T> *root, alg_strategy strategy = alg_strategy::iterative) {
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

int _height_rec(Node<T> *node) {
    if (node)
        return max(_height_rec(node->left), _height_rec(node->right)) + 1;
    else
        return -1;
}

// BT height iterative - like preorder traversal

int _height_ite1(Node<T> *root) {
    // Perform iterative traversal, like _preOrder_ite2(), and save both current
    // level and maximum level
    stack<pair<Node<T>*, int>> st_nodes_hts;
    Node<T> *current = root;
    int cur_level = 0, max_level = 0;
    while (current || !st_nodes_hts.empty()) {
        if (current) {
            // check (and update) maximum level in the tree
            if (cur_level > max_level)
                max_level = cur_level;
            st_nodes_hts.push(pair<Node<T>*, int>(current, cur_level));
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

int _height_ite2(Node<T> *root) {
    vector<Node<T>*> v_nodes, v_nodes_new;
    if (root) {
        v_nodes.push_back(root);
    }
    int level = -1;
    while (!v_nodes.empty()) {
        // for each next level, add all existing childs as
        // the new sequence
        v_nodes_new.clear();
        for (Node<T>* n : v_nodes) {
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


    // Node<T> * insert(Node<T> * root, int data) {
    //     Node<T> *n = root;
    //     while (true) {
    //         if (data < n->data) {
    //             if (n->left)
    //                 n = n->left;
    //             else {
    //                 n->left = new Node<T>(data);
    //                 break;
    //             }
    //         }
    //         else if (data > n->data) {
    //             if (n->right)
    //                 n = n->right;
    //             else {
    //                 n->right = new Node<T>(data);
    //                 break;
    //             }
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     return root;
    // }

// Breadth First Search printing

vector<T> levelOrder(Node<T> * root) {
    vector<T> sequence;
    deque<Node<T>*> queue;
    if (root)
        queue.push_back(root);
    Node<T> *cur;
    while (!queue.empty()) {
        cur = queue.front();
        sequence.push_back(cur->data);
        if (cur->left)
            queue.push_back(cur->left);
        if (cur->right)
            queue.push_back(cur->right);
        queue.pop_front();
    }
    return sequence;
}

// Lowest Common Ancestor (LCA)
// O(log(n)) time complexity

Node<T>* lca(Node<T>* root, int v1, int v2) {
    Node<T> *n = root;
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

deque<int> topView(Node<T> *root) {
    deque<int> result;
    // x - horizontal coordinate of nodes
    int cur_x = 0;
    int max_x(cur_x), min_x(cur_x);
    deque<pair<Node<T>*, int>> bfs_queue;
    if (root) {
        // starting with root and 0 coord
        bfs_queue.emplace_back(root, cur_x);
        result.push_front(root->data);
    }
    Node<T> *n;

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


vector<int> leftView(Node<T> *root) {
    vector<int> result;
    deque<Node<T>*> bfs_queue;
    deque<Node<T>*> next_bfs_queue;
    if (root) {
        bfs_queue.push_back(root);
    }
    while (!bfs_queue.empty()) {
        result.push_back(bfs_queue.front()->data);
        for (Node<T>* n : bfs_queue) {
            if (n->left)
                next_bfs_queue.push_back(n->left);
            if (n->right)
                next_bfs_queue.push_back(n->right);
        }
        bfs_queue = next_bfs_queue;
        next_bfs_queue.clear();
    }
    return result;
}

// More general, side view. pass side='l' for left view and side='r' for right view.
vector<int> sideView(Node<T> *root, const char side = 'l') {
    vector<int> result;
    deque<Node<T>*> bfs_queue;
    deque<Node<T>*> next_bfs_queue;
    if (root) {
        bfs_queue.push_back(root);
    }
    while (!bfs_queue.empty()) {
        if (side == 'r')
            result.push_back(bfs_queue.back()->data);
        else
            result.push_back(bfs_queue.front()->data);
        for (Node<T>* n : bfs_queue) {
            if (n->left)
                next_bfs_queue.push_back(n->left);
            if (n->right)
                next_bfs_queue.push_back(n->right);
        }
        bfs_queue = next_bfs_queue;
        next_bfs_queue.clear();
    }
    return result;
}

    // Is this a binary search tree?

    bool checkBST(Node<T>* root) {
        return _checkBST_rec(root);
    }

    // iterative way
	bool _checkBST_ite(Node<T>* root) {
        // triples <node, min. subtree value, max. subtree value>
        deque<triple<Node<T>*, int, int>> bfs_queue;
        if (root)
            // root without limits (min./max. int values)
            bfs_queue.emplace_back(root, INT_LEAST32_MIN, INT_LEAST32_MAX);
        triple<Node<T>*, int, int> n;
        while (!bfs_queue.empty()) {
            n = bfs_queue.front();
            // target condition - check if the node value falls in the acceptable range
            if (n.first->data <= n.second || n.first->data >= n.third)
                return false;
            if (n.first->left) {
                // for left child - narrow down max. subtree value
                bfs_queue.emplace_back(n.first->left, n.second, n.first->data);
            }
            if (n.first->right) {
                // for right child - narrow up min. subtree value
                bfs_queue.emplace_back(n.first->right, n.first->data, n.third);
            }
            bfs_queue.pop_front();
        }
        return true;
	}

    // recursive way
    bool _checkBST_rec(Node<T>* root) {
        return _checkBST_r(root, INT_LEAST32_MIN, INT_LEAST32_MAX);
    }

    bool _checkBST_r(Node<T>* n, int min, int max) {
        if (!n)
            return true;
        if (n->data <= min || n->data >= max)
            return false;
        return _checkBST_r(n->left, min, n->data) &&
            _checkBST_r(n->right, n->data, max);
    }

    // second method: perform in-order traversal and check if it results
    // in a sorted array (for BST it should)
    bool _checkBST_2(Node<T>* root) {
        vector<T> in_order_seq = _inOrder_ite(root);
        for (int i = 0; i < in_order_seq.size()-1; i++) {
            if (in_order_seq[i] >= in_order_seq[i+1])
                return false;
        }
        return true;
    }


}; //End of Solution

int main() {
  
    Solution<float> myTree;
    Node<float>* root = NULL;
    
    int t;
    float data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    // cout << myTree.levelOrder(root) << endl;
    cout << myTree.sideView(root, 'r') << endl;
    return 0;
}

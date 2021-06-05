#pragma once
#include <memory>
#include <vector>

template<typename T>
class BSTNode {
	// Inner value and its count
	T value;
	int count;
	// Children nodes
	std::shared_ptr<BSTNode> left, right;
	// 
	void add_sorted(std::vector<std::pair<T, int>>&values) {
		if (left)
			left->add_sorted(values);
		values.push_back(std::pair<T, int>(value, count));
		if (right)
			right->add_sorted(values);
	}

public:
	BSTNode(T _value) : value(_value), count(1) {}
	BSTNode() : count(0) {}
	
	// Add new value
	void add(T val) {
		if (val > value)
		{
			if (this->right)
				this->right->add(val);
			else
				this->right = std::shared_ptr<BSTNode>(new BSTNode(val));
		}
		else if (val < value) {
			if (this->left)
				this->left->add(val);
			else
				this->left = std::shared_ptr<BSTNode>(new BSTNode(val));
		}
		else
			this->count++;
	}

	std::vector<std::pair<T, int>> to_sorted() {
		std::vector<std::pair<T, int>> sorted_values;
		add_sorted(sorted_values);
		return sorted_values;
	}

	// Print BST node's values in order
	void print_order(std::ostream& ost) {
		if (right)
			right->print_order(ost);
		//ost << 
	}

};
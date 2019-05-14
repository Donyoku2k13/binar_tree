#pragma once
#include<iostream>

using namespace std;

template <class T1, class T2>
struct node
{
	T1 key;
	T2 value;
	node<T1, T2>*parent = nullptr;
	node<T1, T2>*left = nullptr;
	node<T1, T2>*right = nullptr;
};
template<class T1, class T2>
class tree_{
	node<T1, T2>*root;
	size_t size_;
public:
	tree_() {
		root = nullptr;
		size_ = 0;
	}
	void insert(const T1&key, const T2& value) {
		//create new node
		node<T1, T2> *newnode = new node<T1, T2>;
		newnode->key = key;
		newnode->value = value;
		//create 2 &, what will go daybyday;
		if (root==nullptr)
		{
			root = newnode;
			size_ = 1;
			return;
		}
		//then, we have 1 element
		node<T1, T2> *tmp = root;
		node<T1, T2> *y = nullptr;
		while (tmp!=nullptr)
		{
			y = tmp;
			if (key < tmp->key)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		newnode->parent = y;
		if (key < y->key)
			y->left = newnode;
		else
			y->right = newnode;
		size_++;
	}

	void printNode(node<T1, T2>*nd)const  {
		if (nd!=nullptr)
		{
			printNode(nd->left);
			cout << nd->key << " " << nd->value << endl;
			printNode(nd->right);
			//cout << nd->key << " " << nd->value << endl;
		}
	}
	void print()const  {
		printNode(root);
	}

	const T2& find(const T1& key)const {
		node<T1, T2> *tmp = root;
		while (tmp.key != key && tmp != nullptr)
		{
			if (key < tmp->key)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		return tmp->value;
	}
};


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>


template<class T> class MultiTreeNode;

template<class T, class Container = MultiTreeNode<T> >
class MultiTree {

protected:
	typedef Container nodeType;
public:
	MultiTree();
	MultiTree(nodeType *);
	~MultiTree();
	// pre-order iterator
	class iterator {	// in-body implementation

	public:
		nodeType * _node;
		iterator() : _node(NULL) , skipFlag(false) { skip(); }
		iterator(nodeType *node) : _node(node) ,	skipFlag(false) {
			skip();
		}
		~iterator() {}

		// operator overloading
		T& operator*() const {
			return _node->name;
		}

		// operator overloading
		T* operator->() const {
			return &(_node->name);
		}

		nodeType* get() {
			return _node;
		}

		// return begin
		iterator begin() const { // Constant member function
			return iterator(_node);
		}
		
		// return end
		iterator end() const { // Constant member function
			return iterator(findEnd(_node));
		}

	protected:
		bool skipFlag;
		void skip()
		{
			skipFlag = true;
		}
		nodeType* findEnd(nodeType* current) const
		{
			size_t pos = current->children.size();
			if (pos == 0)
				return current; //这里返回iterator会被析构掉，临时对象
			// find from the end
			return findEnd(current->children[pos - 1]);
			//return NULL;
		}
	};

public:

	nodeType *root;

	// insert a node
	iterator insert(iterator& it, const T& x)	// in-class implementation
	{
		nodeType *tmp = new nodeType(x);
		it._node->children.push_back(tmp);
		tmp->parent = it._node;
		return iterator(tmp);
	}

	// post-order traversal print
	void postTravPrint(nodeType*, unsigned);
	// pre-order traversal print
	void preTravPrint(nodeType* , unsigned);
	// use formatString to print the multiTree
	void formPrint(nodeType*);

private:
	std::stack<std::string> mtStack;
	// initialization
	void Init();
	// post-order free
	void destroy(nodeType *);
};

template<class T, class Container = MultiTreeNode<T> >
void MultiTree<T, Container>::Init()
{
	mtStack.push(std::string(""));
}

template<class T, class Container = MultiTreeNode<T> >
void MultiTree<T, Container>::destroy(nodeType *node)
{
	for (unsigned i = 0; i < node->children.size(); i++)
		destroy(node->children[i]);
	if (node) {
		delete node;
		node = NULL;
	}
}

template<class T, class Container = MultiTreeNode<T> >
MultiTree<T, Container>::MultiTree()
{
	root = NULL;
	Init();
}

template<class T, class Container = MultiTreeNode<T> >
MultiTree<T, Container>::MultiTree(nodeType* node)
{
	root = node;
	Init();
}

template<class T, class Container = MultiTreeNode<T> >
MultiTree<T, Container>::~MultiTree()
{
	destroy(root);
}

template<class T, class Container = MultiTreeNode<T> >
void MultiTree<T, Container>::postTravPrint(nodeType* node, unsigned level)
{
	for (unsigned i = 0; i < node->children.size(); i++)
		postTravPrint(node->children[i], level + 1);
	for (unsigned i = 0; i < level; i++)
		std::cout << "\t";
	std::cout << node->name << std::endl;
}

template<class T, class Container = MultiTreeNode<T> >
void MultiTree<T, Container>::preTravPrint(nodeType* node, unsigned level)
{
	for (unsigned i = 0; i < level; i++)
		std::cout << "\t";
	std::cout << node->name << std::endl;
	for (unsigned i = 0; i < node->children.size(); i++)
		preTravPrint(node->children[i], level + 1);
}

template<class T, class Container = MultiTreeNode<T> >
void MultiTree<T, Container>::formPrint(nodeType* node)
{
	std::string temp;
	temp = mtStack.top() + node->format;
	mtStack.push(temp);
	std::cout << temp;
	std::cout << node->name;
	std::cout << "\n|";
	for (unsigned i = 0; i < node->children.size(); i++)
		formPrint(node->children[i]);
	mtStack.pop();
}

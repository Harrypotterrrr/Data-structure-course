#pragma once
#include <string>
#include <vector>

template<class T>
class MultiTreeNode {

public:
	typedef MultiTreeNode<T> nodeType;
	MultiTreeNode();
	MultiTreeNode(const T& x);
	~MultiTreeNode();

	T name;
	std::string format;
	nodeType *parent;
	std::vector<nodeType*> children;
};

template<class T>
MultiTreeNode<T>::MultiTreeNode()
{
	parent = NULL;
	format = "！！";
}

template<class T>
MultiTreeNode<T>::MultiTreeNode(const T& x)
{
	name = x;
	parent = NULL;
	format = "！！";
}

template<class T>
MultiTreeNode<T>::~MultiTreeNode() {}


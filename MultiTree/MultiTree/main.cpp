#include "MultiTree.hpp"
#include "MultiTreeNode.hpp"

int main()
{
	typedef MultiTreeNode<std::string> MTNString;
	typedef MultiTree<std::string> MTString;

	MTNString *rootNode = new MTNString("root");

	MTString::iterator it(rootNode);
	MTString root(rootNode);
	MTString::iterator a = root.insert(it, "a");
	MTString::iterator b = root.insert(it, "b");
	MTString::iterator c = root.insert(it, "c");
	MTString::iterator a1 = root.insert(a, "a1");
	MTString::iterator a2 = root.insert(a, "a2");
	MTString::iterator a3 = root.insert(a, "a3");
	MTString::iterator b1 = root.insert(b, "b1");
	MTString::iterator b2 = root.insert(b, "b2");
	MTString::iterator c1 = root.insert(c, "c1");
	MTString::iterator c2 = root.insert(c, "c2");
	MTString::iterator c3 = root.insert(c, "c3");
	MTString::iterator c4 = root.insert(c, "c4");
	MTString::iterator c5 = root.insert(c, "c5");
	MTString::iterator a21 = root.insert(a2, "a21");
	MTString::iterator a22 = root.insert(a2, "a22");
	MTString::iterator a23 = root.insert(a2, "a23");
	MTString::iterator a24 = root.insert(a2, "a24");
	MTString::iterator c11 = root.insert(c1, "c11");

	root.formPrint(root.root);
	std::cout << "------------------------------------" << std::endl;

	root.preTravPrint(root.root, 1);
	std::cout << "------------------------------------" << std::endl;

	root.postTravPrint(root.root, 1);
	std::cout << "------------------------------------" << std::endl;

	// test iterator::end() function
	std::cout << (*(it.end())) << std::endl;
	return 0;
}
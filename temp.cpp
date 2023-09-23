#include <iostream>

#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
class BinarySearchTree
{
public:
	struct Node
	{
		T data;
		Node* right = nullptr;
		Node* left = nullptr;
	};

	enum class Traversal
	{
		PreOrder,
		InOrder,
		PostOrder
	};
public:
	~BinarySearchTree()
	{
		Clear();
	}
	bool IsEmpty() const
	{
		return !root;
	}
	bool Search(const T& val) const
	{
		_loc = root;
		_ploc = nullptr;

		while (_loc)
		{
			if (_loc->data == val) break; // found at loc

			if (val < _loc->data)
			{
				_ploc = _loc;
				_loc = _loc->left;
			}
			else
			{
				_ploc = _loc;
				_loc = _loc->right;
			}
		}

		return _loc; //true if _loc is not null
	}
	void Insert(const T& val)
	{
		_loc = nullptr;
		_ploc = nullptr;
		Search(val);		

		if (!_loc) // if _loc is null
		{
			Node* newnode = new Node;
			newnode->data = val;			

			if (!_ploc) root = newnode; //if _ploc is null
			else
			{
				if (_ploc->data > val) _ploc->left = newnode;
				else _ploc->right = newnode;
			}
		}
		else
		{
			std::cout << "Error: Dublicate insertion. Val = " << val << '\n';
		}
	}
	void Clear()
	{
		// Lambda function that deletes node in arg
		const auto deleter = [](Node* n) {
			delete n;
		};
		
		Traverse(deleter);

		root = nullptr;
		_loc = nullptr;
		_ploc = nullptr;
	}

	const Node*& getRoot() const
	{
		return root;
	}
	static bool IsLeaf(const Node* n)
	{
		return n->left == nullptr && n->right == nullptr;
	}

	// Utility Functions

	void Print(Traversal traversal_mode = Traversal::InOrder) const
	{
		// Lambda function that prints all nodes
		const auto printer = [](const Node* n) {
			std::cout << n->data << ' ';
		};

		TraverseConst(printer, traversal_mode);
		std::cout << '\n';
	}
	T SmallestValue() const
	{
		if (!IsEmpty())
		{
			T smallest = root->data;

			// Lambda function that finds min and stores in smallest
			const auto findMin = [&smallest](const Node* n) {
				if (n->data < smallest) smallest = n->data;
			};

			TraverseConst(findMin);

			return smallest;
		}

		std::cout << "Error: SmallestValue() called on empty list\n";
		return T();
	}
	T LargestValue() const
	{
		if (!IsEmpty())
		{
			T largest = root->data;

			// Lambda function that finds max and stores in largest
			const auto findMax = [&largest](const Node* n) {
				if (n->data > largest) largest = n->data;
			};

			TraverseConst(findMax);

			return largest;
		}

		std::cout << "Error: LargestValue() called on empty list\n";
		return T();
	}
	void PrintLeaves() const
	{
		// Lambda function that prints leaf nodes
		const auto leafPrinter = [](const Node* n) {
			if(IsLeaf(n)) std::cout << n->data << ' ';
		};

		TraverseConst(leafPrinter);
		std::cout << '\n';
	}
	int CountNodes() const
	{
		int count = 0;

		// Lambda function that increments count for each node
		const auto nodeCounter = [&count](const Node* n) {
			count++;
		};

		TraverseConst(nodeCounter);
		return count;
	}
	int GetHeight() const
	{
		return GetHeight(root);
	}
	int GetHeight(const Node* n) const
	{
		if (n) // If n is not null
			return 1 + std::max(GetHeight(n->left), GetHeight(n->right));

		return 0;
	}
	int GetDepth(const Node* n) const
	{
		_loc = nullptr;
		_ploc = nullptr;
		Search(n->data);

		if (_loc) // if node found
		{
			if (_ploc) return 1 + GetDepth(_ploc); // if its not root 
			return 0; // if it is root 
		}

		std::cout << "Error: GetDepth() called on non-existant node\n";
		return 0;
	}
	int GetDepth(const T& val) const
	{
		_loc = nullptr;
		_ploc = nullptr;
		Search(val);

		if (_loc) // if node found
		{
			if (_ploc) return 1 + GetDepth(_ploc); // if its not root 
			return 0; // if it is root 
		}

		std::cout << "Error: GetDepth() called on non-existant node\n";
		return 0;
	}

	// Normal Traversal
	// func must be callable using: func(nodeptr)
	// where typename of nodeptr is BinarySearchTree::Node*
	template <class UnaryFunction> 
	void Traverse(const UnaryFunction& func, 
		Traversal traversal_mode = Traversal::PostOrder)
	{
		Traverse(func, traversal_mode, root);
	}

	// Const Traversals
	// func must be callable using: func(nodeptr)
	// where typename of nodeptr is const BinarySearchTree::Node*
	template <class ConstUnaryFunction>
	void TraverseConst(const ConstUnaryFunction& func, 
		Traversal traversal_mode = Traversal::PostOrder) const
	{
		TraverseConst(func, traversal_mode, root);
	}

	// Recursive non-const traversal
	template <class UnaryFunction>
	void Traverse(const UnaryFunction& func, 
		Traversal traversal_mode, Node* start)
	{
		if (start)
		{
			if (traversal_mode == Traversal::PreOrder) func(start);
			Traverse(func, traversal_mode, start->left);
			if (traversal_mode == Traversal::InOrder) func(start);
			Traverse(func, traversal_mode, start->right);
			if (traversal_mode == Traversal::PostOrder) func(start);
		}
	}

	// Recursive const traversal
	template <class ConstUnaryFunction>
	void TraverseConst(const ConstUnaryFunction& func,
		Traversal traversal_mode, const Node* start) const
	{
		if (start)
		{
			if (traversal_mode == Traversal::PreOrder) func(start);
			TraverseConst(func, traversal_mode, start->left);
			if (traversal_mode == Traversal::InOrder) func(start);
			TraverseConst(func, traversal_mode, start->right);
			if (traversal_mode == Traversal::PostOrder) func(start);
		}
	}
private:
	Node* root = nullptr;
	mutable Node* _loc = nullptr;
	mutable Node* _ploc = nullptr;
};
int main()
{
	typedef BinarySearchTree<int> BST;

	BST myBST;

	myBST.Insert(50);
	myBST.Insert(25);
	myBST.Insert(75);

	std::cout << "Starting tree (InOrder) :"; myBST.Print(BST::Traversal::InOrder);
	std::cout << (myBST.IsEmpty() ? "Empty" : "Not empty") << '\n';
	std::cout << "min: " << myBST.SmallestValue() << '\n';
	std::cout << "max: " << myBST.LargestValue() << '\n';
	std::cout << "leaves: "; myBST.PrintLeaves();
	std::cout << "count: " << myBST.CountNodes() << '\n';
	std::cout << "height: " << myBST.GetHeight() << '\n';
	std::cout << "depth of 9: " << myBST.GetDepth(9) << '\n';

	std::cout << "\nInserting values (shown InOrder)\n";

	myBST.Insert(90);
	myBST.Print();
	myBST.Insert(89);
	myBST.Print();
	myBST.Insert(89);
	myBST.Print();
	myBST.Insert(9);
	myBST.Print();
	myBST.Insert(29);
	myBST.Print();
	myBST.Insert(2);
	myBST.Print();
	myBST.Insert(51);
	myBST.Print();

	std::cout << '\n';
	std::cout << "PostOrder: "; myBST.Print(BST::Traversal::PostOrder);
	std::cout << "PreOrder: "; myBST.Print(BST::Traversal::PreOrder);
	std::cout << "min: " << myBST.SmallestValue() << '\n';
	std::cout << "max: " << myBST.LargestValue() << '\n';
	std::cout << "leaves: "; myBST.PrintLeaves();
	std::cout << "count: " << myBST.CountNodes() << '\n';
	std::cout << "height: " << myBST.GetHeight() << '\n';
	std::cout << "depth of 9: " << myBST.GetDepth(9) << '\n';

	return 0;
}
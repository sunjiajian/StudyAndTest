#pragma once

#include <stack>

using std::stack;

#define __NameSpace_bt__ namespace bt{
#define __NameSpaceEnd__ }

__NameSpace_bt__

template <typename T>
class BinNode
{
public:
	T *data;
	BinNode<T> *parent;
	BinNode<T> *lChild;
	BinNode<T> *rChild;

public:
	BinNode(T* t = nullptr, BinNode<T>* p = nullptr);
	BinNode<T>* insertAsLC(T* t);
	BinNode<T>* insertAsRC(T* t);
	int size();
};



template <typename T>
class BinTree
{
protected:
	BinNode *root;
	int height;

public:
};


template <typename T, typename VST>
void preorderVST(BinNode<T>* node, VST& visit)
{
	// 递归方法
	/*
	if (node == nullptr)
	{
		return;
	}

	visit(node->data);

	preorderVST(node->lChild, visit);
	preorderVST(node->rChild, visit);
	*/

	// 迭代方法
	stack<BinNode<T>*> st;
	st.push(node);

	while (!st.empty())
	{
		BinNode<T>* n = st.top();
		st.pop();
		if (n != nullptr)
		{
			visit(n->data);
			st.push(n->rChild);
			st.push(n->lChild);
		}
	}
}


template <typename T, typename VST>
void midorderVST(BinNode<T>* node, VST& visit)
{
	// 迭代方法

}

__NameSpaceEnd__

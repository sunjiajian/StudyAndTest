#pragma once

#include <stack>
#include <queue>

using std::stack;
using std::queue;

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


// �������
template <typename T, typename VST>
void preorderVST(BinNode<T>* node, VST& visit)
{
	// �ݹ鷽��
	/*
	if (node == nullptr)
	{
		return;
	}

	visit(node->data);
	preorderVST(node->lChild, visit);
	preorderVST(node->rChild, visit);
	*/

	// ��������
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

	// ���������
	stack<BinNode<T>*> st;
	BinNode<T>* x = node;
	while (true)
	{
		while (x != nullptr)
		{
			visit(x);
			st.push(x->rChild);
			x = x->lChild;
		}

		if (st.empty())
			break;

		x = st.top();
		st.pop();
	}

}

// �������
template <typename T, typename VST>
void midorderVST(BinNode<T>* node, VST& visit)
{
	// �ݹ鷽��
	//if (node == nullptr)
	//{
	//	return;
	//}

	//midorderVST(node->lChild, visit);
	//visit(node->data);
	//midorderVST(node->rChild, visit);


	// ��������


	// ���������
	stack<BinNode<T>*> st;
	BinNode<T>* x = node;

	while (true)
	{
		while (x != nullptr)
		{
			st.push(x);
			x = x->lChild;
		}

		if (st.empty())
		{
			break;
		}

		x = st.top();
		st.pop();
		visit(x);
		x = x->rChild;
	}
}

// �������
template <typename T, typename VST>
void lastorderVST(BinNode<T>* node, VST& visit)
{
	// �ݹ鷽��
	//if (node == nullptr)
	//{
	//	return;
	//}

	//midorderVST(node->lChild, visit);
	//midorderVST(node->rChild, visit);
	//visit(node->data);

}


// ��α���
template <typename T, typename VST>
void levelorderVST(BinNode<T>* node, VST& visit)
{
	// �ݹ鷽��
	//if (node == nullptr)
	//{
	//	return;
	//}

	//midorderVST(node->lChild, visit);
	//midorderVST(node->rChild, visit);
	//visit(node->data);

	// ����
	queue<BinNode<T>*> que;
	que.push(node);

	while (!que.empty())
	{
		BinNode<T>* x = que.front();
		que.pop();
		if (x != nullptr)
		{
			visit(x);
			que.push(x->lChild);
			que.push(x->rChild);
		}
	}
}
__NameSpaceEnd__

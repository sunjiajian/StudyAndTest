#include "BinTree.h"

using namespace bt;

template<typename T>
inline BinNode<T>::BinNode(T * t, BinNode<T>* p)
{
	data = t;
	parent = p;
	lChild = nullptr;
	rChild = nullptr;
}

template<typename T>
BinNode<T>* BinNode<T>::insertAsLC(T * t)
{
	return lChild = new BinNode(t, this);
}

template<typename T>
BinNode<T>* BinNode<T>::insertAsRC(T * t)
{
	return rChild = new BinNode(t, this);
}

template<typename T>
int BinNode<T>::size()
{
	int s = 0;
	if (lChild != nullptr)
	{
		s += lChild->size();
	}
	if (rChild != nullptr)
	{
		s += rChild->size();
	}
	return s;
}

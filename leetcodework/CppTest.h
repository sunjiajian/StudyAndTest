#pragma once

#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;


#define __NameSpace_ct__ namespace ct{
#define __NameSpaceEnd__ }

__NameSpace_ct__


static void testVector1()
{
	vector<int> vec1;
	cout << "vector.size() = " << vec1.size() << endl;
	cout << "vector.capacity() = " << vec1.capacity() << endl ;
	cout << "vector.data() = " << vec1.data() << endl << endl;

	int size = 100000;
	for (int i = 0; i < size; ++i)
	{
		vec1.push_back(i);
		cout << "vector.size() = " << vec1.size() << endl;
		cout << "vector.capacity() = " << vec1.capacity() << endl;
		cout << "vector.data() = " << vec1.data() << endl << endl;
	}
}


class tvalue
{
public:
	tvalue(int i) : value(i) { cout << "new tvalue:" << value << endl; }
	tvalue(const tvalue& t) : value(t.value) { cout << "copy tvalue:" << value << endl; }
	~tvalue() { cout << "delete tvalue:" << value << endl; }

	int value;
};

void testVector2()
{
	vector<tvalue> vec1;
	cout << "vector.size() = " << vec1.size() << endl;
	cout << "vector.capacity() = " << vec1.capacity() << endl;
	cout << "vector.data() = " << vec1.data() << endl << endl;

	int size = 100000;
	for (int i = 0; i < size; ++i)
	{
		vec1.push_back(tvalue(i));
		cout << "vector.size() = " << vec1.size() << endl;
		cout << "vector.capacity() = " << vec1.capacity() << endl;
		cout << "vector.data() = " << vec1.data() << endl << endl;
	} 
}

void testString1()
{
	string str;
	cout << "vector.size() = " << str.size() << endl;
	cout << "vector.capacity() = " << str.capacity() << endl;
	cout << "vector.data() = " << str.data() << endl << endl;

	int size = 100000;
	for (int i = 0; i < size; ++i)
	{
		str.push_back('s');
		cout << "vector.size() = " << str.size() << endl;
		cout << "vector.capacity() = " << str.capacity() << endl;
		cout << "vector.data() = " << str.data() << endl << endl;
	}
}

__NameSpaceEnd__
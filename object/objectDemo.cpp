
#include "stdafx.h"

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
class CBox1 {
};
class CBox2 {
	int length, width, height;
};
class CBox3 {
	int length, width, height;
	static int count;
};
class CBox4 {
	int foo();
};
class CBox5 {
public:
	CBox5() {};
	~CBox5() {};
};
class CBox6 {
public:
	CBox6() {};
	virtual ~CBox6() {};
};
class A {
};
class B {
};
class C :public A {
};
class D :public virtual B {
};
class E :public A, public B {
};


int _tmain(int argc, _TCHAR* argv[])
{
	CBox1 box1obj;
	cout << "box1: " << sizeof(box1obj) << endl;//Êä³ö1

	CBox2 box2obj;
	cout << "box2: " << sizeof(box2obj) << endl;

	CBox3 box3obj;
	cout << "box3: " << sizeof(box3obj) << endl;

	CBox4 box4obj;
	cout << "box4: " << sizeof(box4obj) << endl;

	CBox5 box5obj;
	cout << "box5: " << sizeof(box5obj) << endl;

	CBox6 box6obj;
	cout << "box6: " << sizeof(box6obj) << endl;

	A a;
	B b;
	C c;
	D d;
	E e;
	cout << "sizeof(a):" << sizeof(a) << endl;
	cout << "sizeof(b):" << sizeof(b) << endl;
	cout << "sizeof(c):" << sizeof(c) << endl;
	cout << "sizeof(d):" << sizeof(d) << endl;
	cout << "sizeof(e):" << sizeof(e) << endl;
	
	getchar();
	return 0;
}
//
//output
//
/*
box1: 1
box2: 12
box3: 12
box4: 1
box5: 1
box6: 4
sizeof(a):1
sizeof(b):1
sizeof(c):1
sizeof(d):4
sizeof(e):1
*/
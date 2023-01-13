#define _CRT_SECURE_NO_WARNINGS 1



#include<iostream>
#include"BSTree.h"
using namespace std;
void test1()
{
	sht::BSTree<int> a;
	a.insert(5);
	a.insert(3);
	a.insert(4);
	a.insert(1);
	a.insert(7);
	a.insert(8);
	a.insert(2);
	a.insert(6);
	a.insert(0);
	a.insert(9);


	sht::levelorder(a.getroot());
}

void test2()
{
	sht::BSTree<int> a;
	a.insert(5);
	a.insert(3);
	a.insert(4);
	a.insert(1);
	a.insert(7);
	a.insert(8);
	a.insert(2);
	a.insert(6);
	a.insert(0);
	a.insert(9);


	sht::levelorder(a.getroot());

	cout << endl;
	a.erase(7);

	sht::levelorder(a.getroot());




}


int main()
{
	test2();
}
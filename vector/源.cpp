#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"vector.h"


using namespace std;

void test1()
{
	sht::vector<int> s(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test2()
{
	sht::vector<int> s;
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
}

void test3()
{
	int a[8] = { 0,1,2,3,4,5,6,7 };
	sht::vector<int> s1(a, a + 8);

	sht::vector<int> s2(s1);

	sht::vector<int> s3;
	s3 = s1;

	for (auto& e : s1)
	{
		cout << e << ' ';
	}
	cout << endl;
	for (auto& e : s2)
	{
		cout << e << ' ';
	}
	cout << endl;
	for (auto& e : s3)
	{
		cout << e << ' ';
	}
}


void test4()
{
	sht::vector<int> s1;
	auto it = s1.begin();
	it=s1.insert(it, 1);
	it = s1.insert(it, 2);
	it = s1.insert(it, 3);
	it = s1.insert(it, 4);
	it = s1.insert(it, 5);
	it = s1.insert(it, 6);
	for (auto& e : s1)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void test5()
{
	int a[8] = { 0,1,2,3,4,5,6,7 };
	sht::vector<int> s1(a, a + 8);
	auto it = s1.begin();
	it = s1.erase(it);
	it = s1.erase(it);
	it = s1.erase(it);
	it = s1.erase(it);

	for (auto& e : s1)
	{
		cout << e << ' ';
	}
	cout << endl;
}





int main()
{
	//test2();
	//test3();
	//test4();
	test5();
}
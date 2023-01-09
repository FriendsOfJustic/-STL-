#define _CRT_SECURE_NO_WARNINGS 1


#include"priority_queue.h"
#include<iostream>

using namespace std;
void test1()
{
	sht::priority_queue<int> q;
	q.push(2);
	q.push(3);
	q.push(1);
	q.push(35);
	q.push(7);
	q.push(9);
	q.push(0);
	cout << q.top() << endl;

}


void test2()
{
	vector<int> s = { 2,3,7,45,36,79,56,6,3 };
	sht::priority_queue<int> q(s.begin(), s.end());

	cout << q.top() << endl;
}


void test3()
{
	int foo[] = { 10,20,5,15,25 };
	sht::priority_queue<int> q(foo, foo + sizeof(foo) / sizeof(int));

	cout << q.top() << endl;
}
int main()
{
	test3();
}
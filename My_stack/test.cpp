#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"My_stack.h"
using namespace std;
int main()
{
	sht::My_stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);


	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}
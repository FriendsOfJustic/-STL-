#define _CRT_SECURE_NO_WARNINGS 1


#include"string.h"
using namespace std;



void test1()
{
	std::string foo = "alpha";
	std::string bar = "beta";

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
}


void test2()
{
	sht::string s("i loveyou");
	s.erase(2, 4);
	cout << s.c_str() << endl;
}

void test3()
{
	sht::string s("i loveyou");
	//sht::operator<<(cout, s);
	cout << s << endl;

	sht::string s1;
	cin >> s1;
	//sht::operator>>(cin, s);
	cout << s1 << endl;
}



void test4()
{
	sht::string s("i loveyou");
	auto it = s.rbegin();
	for (auto e : s)
	{
		cout << e;
	}
	cout << endl;
	while (it != s.rend())
	{
		cout << *it;
		++it;
	}
}


void test5()
{
	sht::string s("i loveyou");
	auto it = s.rbegin();
	for (auto e : s)
	{
		cout << e;
	}
	cout << endl;
	auto is = it;
	while (it != s.rend())
	{
		cout << *it;
		++it;
	}
}

void test6()
{
	sht::string s;
	s.insert(0, "you");
	s.insert(0, "love ");
	s.insert(0, "i ");
	cout << s;
}


int main()
{
	test6();
}
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
int main()
{
	sht::string s("i love you");
	//s.reserve(100);
	//s.resize(20, 'c');

	sht::string s1(s);
	/*s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');

	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');

	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');*/

	//s1.append(" i love you too honey!");
	s1 += " i love you too honey!";

	sht::string s2 = s1 = s;
	s2.clear();
	//cout << s2[1] << endl;



	/*sht::string a;
	a.push_back('a');
	a.push_back('a');
	a.push_back('a');
	a.push_back('a');
	a.push_back('a');
	a.push_back('a');
	a.push_back('a');
	a.push_back('a');*/

	//cout<<s1.find('y', 0);

	/*const char* a = s.c_str();
	cout << a << endl;
	cout << s.find("love");*/



	//s.insert(2, 'u');
	s.insert(0, "fuck you");
	test1();
}
#pragma once

namespace sht
{
	//ref 是数据结构里面数据类型的引用，可以理解为T&
	//Ptr 是数据类型的地址，可以理解为T*

	// 反向迭代器的rbegin =  正向迭代器的 begin
	//反向迭代器的rend =  正向迭代器的 end
	template<class iterator, class Ref,class Ptr>
	class reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;
	public:
		reverse_iterator(iterator it)
			:_it(it)
		{

		}

		Ref operator*()  //返回迭代器指向的前一个元素
		{
			iterator tmp = _it;   
			return *(--tmp);      //正是因为begin =rend end=rbegin 所以这里解引用时正向迭代器的解引用运算符会对tmp的合法性进行检查
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			return --_it;
		}

		Self& operator--()
		{
			return ++_it;
		}
		

		bool operator!=(const Self& t) const
		{
			return _it != t._it;
		}

		bool operator==(const Self& t) const
		{
			return _it == t._it;
		}

	private:
		iterator _it;
	};
}
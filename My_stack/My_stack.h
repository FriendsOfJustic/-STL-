#pragma once
#include<deque>
namespace sht
{
	template<class T,class container=std::deque<T>>
	class My_stack
	{
	public:
		My_stack()
		{

		}

		void push(const T& x)
		{
			c.push_back(x);
		}

		void pop()
		{
			c.pop_back();
		}

		T& top()
		{
			return c.back();
		}

		const T& top()const
		{
			return c.back();
		}

		size_t size()const
		{
			return c.size();
		}

		bool empty()const
		{
			return c.empty();
		}
	private:
		container c;
	};
}
#pragma once
//#include<deque>
//namespace sht
//{
//	template<class T,class container=std::deque<T>>
//	class My_stack
//	{
//	public:
//		My_stack()
//		{
//
//		}
//
//		void push(const T& x)
//		{
//			c.push_back(x);
//		}
//
//		void pop()
//		{
//			c.pop_back();
//		}
//
//		T& top()
//		{
//			return c.back();
//		}
//
//		const T& top()const
//		{
//			return c.back();
//		}
//
//		size_t size()const
//		{
//			return c.size();
//		}
//
//		bool empty()const
//		{
//			return c.empty();
//		}
//	private:
//		container c;
//	};
//}


class Solution {
public:
    string addStrings(string num1, string num2) {
        int maxsize = max(num1.size(), num2.size());
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        stack<int> mid;
        string result;
        int forward = 0;
        for (int i = 0; i < maxsize; i++)
        {
            if (n1 >= 0 && n2 >= 0)
            {
                int sum = stoi(num1[n1]) + stoi(num2[n2]) + sum;
                mid.push(sum % 10);
                forward = sum / 10;
            }
            else if (n1 >= 0 && n2 < 0)
            {
                int  sum = atoi(num1[n1]) + sum;
                mid.push(sum % 10);
                forward = sum / 10;
            }
            else if (n2 >= 0 && n1 < 0)
            {
                int  sum = atoi(num2[n2]) + sum;
                mid.push(sum % 10);
                forward = sum / 10;
            }
            n1--;
            n2--;
        }

        if (forward)
            st.push(1);

        while (!st.empty())
        {
            result.push_back(itoa(st.top()));
            st.pop();
        }
        return result;

    }
};

int main()
{
    string num1 = "123";
    string num2 = "11";

    Solution s;
    s.addStrings(num1.num2);
}
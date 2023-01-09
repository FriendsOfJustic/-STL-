#pragma once
#include<vector>
#include<functional>
#include<assert.h>

namespace sht
{
    template<class T>      //比较函数
    class less
    {
    public:

        bool operator()(const T& x,const T& y)
        {
            return x < y;
        }
    };
    template<class T>      //比较函数
    class greater
    {
    public:
        bool operator()(const T& x, const T& y)
        {
            return x > y;
        }
    };


     
    template <class T, class Container =std::vector<T>, class Compare = less<T> >    //堆 默认为大堆
    class priority_queue
    {
    private:
        void adjustdown(Container& c, int parent)
        {
            int child = parent * 2 + 1;
            while (child<c.size())
            {
                //if (child + 1 < c.size() && c[child] < c[child + 1])
                if (child + 1 < c.size() && comp(c[child], c[child + 1]))
                    child++;
                //if (c[parent] < c[child])
                if (comp(c[parent] , c[child]))
                {
                    std::swap(c[parent], c[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                    break;

            }
        }
        void adjustup(Container& c, int child)
        {
            while (child >0)
            {
                int parent = (child - 1) / 2;
                //if (c[parent] < c[child])
                if (comp(c[parent] , c[child]))
                {
                    parent = (child - 1) / 2;
                    std::swap(c[parent], c[child]);
                    child = parent;
                }
                else
                    break;
            }
        }
    public:
        priority_queue()   //建立一个空堆，后面进行插入,由于默认构造函数会调用成员的默认构造函数，所以写一个全缺省或干脆不写构造函数
        {

        }

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)   //用已知数据来初始化，所以我们要对初始数据进行处理 这里注意last迭代器指向的是最后一个元素的后一个的位置
        {
            auto it = first;
            while (it != last)
            {
                c.push_back(*it);
                it++;
            }

            int parent = (c.size() - 2) / 2;
            for (int i = parent; i >= 0; i--)
            {
                adjustdown(c, i);
            }


        }

        bool empty() const
        {
            return c.empty();
        }

        size_t size() const
        {
            return c.size();
        }

        const T& top() const
        {
            assert(c.size() > 0);
            return c[0];
        }

        void push(const T& x)
        {
            c.push_back(x);
            int child = c.size() - 2;

            while (child > 0)
            {
                adjustup(c, child);
                child = (child - 1) / 2;
            }
        }

        void pop()
        {
            std::swap(c[0], c[c.size() - 1]);
            c.pop_back();

            adjustdown(c, 0);
        }

    private:

        Container c;

        Compare comp;

    };
}
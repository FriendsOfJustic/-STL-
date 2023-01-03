#define _CRT_SECURE_NO_WARNINGS 1

#include<deque>
namespace sht
{
    template<class T, class Con = std::deque<T>>
    class My_queue
    {
    public:
        My_queue()
        {
            //;
        }

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_front();
        }


        T& back()
        {
            return _c.back();
        }

        const T& back()const
        {
            return _c.back();
        }

        T& front()
        {
            return _c.front();
        }

        const T& front()const
        {
            return _c.front();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:

        Con _c;

    };

};

#pragma once

#include<assert.h>

namespace sht
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
            }

        const_iterator cbegin()
        {
            return _start;
            }

        const_iterator cend() const
        {
            return _finish;
            }



            // construct and destroy

        vector()
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr)
        {

        }

        vector(int n, const T& value = T())
        {
            _start = new T[2 * n];
            _finish = _start + n;
            _endOfStorage = _start + 2 * n ;


        }

            template<class InputIterator>
            vector(InputIterator first, InputIterator last)
                :_start(nullptr)
                , _finish(nullptr)
                , _endOfStorage(nullptr)
            {
                reserve(last - first);
                InputIterator cur = first;
                while (cur != last)
                {
                    push_back(*cur);
                    cur++;
                }
             }

            vector(const vector<T>& v)
                :_start(nullptr)
                ,_finish(nullptr)
                ,_endOfStorage(nullptr)
            {
                vector tmp(v._start, v._finish);
                swap(tmp);
            }

            vector<T>& operator= (vector<T> v)
            {
                swap(v);
                v.~vector();
                return *this;
            }

            ~vector()
            {
                free(_start);
                _start = nullptr;
                _finish = nullptr;
                _endOfStorage = nullptr;
            }

            // capacity

            size_t size() const
            {
                return (_finish - _start);
            }

            size_t capacity() const
            {
                return (_endOfStorage - _start) ;
            }

            void reserve(size_t n)
            {
                if (n > capacity())
                {
                    if (_start == nullptr)
                    {
                        _start = new T[n];
                        _finish = _start;
                        _endOfStorage = _start + n;
                        
                    }
                    else
                    {
                        T* tmp = new T[n];
                        std::memcpy(tmp, _start, size()*sizeof(T));
                        int newsize = size();
                        free(_start);
                        _start = tmp;
                        _finish = _start + newsize;
                        _endOfStorage = _start + n;
                    }
                }
            }

            void resize(size_t n, const T& value = T())
            {
                if (n > size() && n > capacity())
                {
                    reserve(2 * n);
                }

                _finish = _start + n;
            }



            ///////////////access///////////////////////////////

            T& operator[](size_t pos)
            {
                return _start[pos];

            }

            const T& operator[](size_t pos)const
            {
                return _start[pos];
            }



            ///////////////modify/////////////////////////////

            void push_back(const T& x)
            {
                if (_start == nullptr)
                    reserve(5);
                if (_finish == _endOfStorage)
                    resize(2 * (_finish - _start));
                *_finish = x;
                _finish++;
            }

            void pop_back()
            {
                assert(_finish == _start);
                _finish--;

            }

            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_endOfStorage, v._endOfStorage);

            }

            iterator insert(iterator pos, const T& x)  //在pos位置插入x
            {
                
                if (_start == nullptr)
                {
                    reserve(5);
                    *_start = x;
                    _finish++;
                    return _start;
                }
                else
                {
                    assert(pos < _finish);
                    if (size() == capacity())    //注意增容以后 地址会发生变化，所以要记录下来偏移量
                    {
                        int offset = pos - _start;    
                        reserve(2 * capacity());
                        pos = _start + offset;

                    }
                    auto cur = _finish;
                    while (cur != pos)
                    {
                        *cur = *(cur-1);
                        --cur;
                    }
                    *cur = x;
                    _finish ++ ;
                    return cur;
                }
            }

            iterator erase(iterator pos)   //删除pos位置的元素
            {
                assert(_start != nullptr);
                assert(pos < _finish);
                auto it = pos;
                _finish--;
                while (it != _finish)
                {
                    *it = *(it + 1);
                    it++;

                }
                return pos;

            }

    private:

        iterator _start; // 指向数据块的开始

        iterator _finish; // 指向有效数据的尾

        iterator _endOfStorage; // 指向存储容量的尾

    };

}
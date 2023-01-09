#pragma once
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
#include<assert.h>
#include"revese_iterator.h"
namespace sht
{
#define npos -1

    template<class T,class Ref,class Ptr>
    class iterator
    {
        typedef iterator<T, T&, T*> Self;
    public:
        iterator(char *p=nullptr)
            :_p(p)
        {

        }

        Ref operator*()
        {
            return *_p;
        }

        Self& operator++()
        {
            ++_p;
            return *this;
        }

        Self& operator--()
        {
            --_p;
            return *this;
        }

        Self operator++(int)
        {
            Self tmp = *this;
            ++(*this);
            return tmp;
        }


        Self operator--(int)
        {
            Self tmp = *this;
            --(*this);
            return tmp;
        }

        Ptr operator->()
        {
            return _p;
        }

        bool operator!=(const Self& t) const
        {
            return _p != t._p;
        }

    private:
        T* _p;

    };






    class string
    {
        //ΪʲôҪ��Ƴ���Ԫ��������Ϊ��������� cout<<string Ĭ����ߵ�����������ұߵ����Ҳ��������Ըղŵ�д��ʵ������cout.operator<<(string),
        //����ʵ������������ĵ����� string.
        friend std::ostream& operator<<(std::ostream& _cout, const sht::string& s);  

        friend std::istream& operator>>(std::istream& _cin, sht::string& s);

    public:
        typedef iterator<char, char&, char*> iterator;
        //sht::reverse_iterator<iterator, char&, char*> _rit;
        typedef reverse_iterator<iterator, char&, char*> reverse_iterator;


        string(const char* str = "")
            :_str(nullptr)
        {
            _size = strlen(str);
            _capacity = 2*_size+1;
            _str = (char*)malloc(_capacity * sizeof(char));
            strcpy(_str, str);
        }

        string(const string& s)
            :_str(nullptr)
            ,_size(0)
            ,_capacity(0)
        {
           /* _capacity = s._capacity;
            _size = s._size;
            _str = (char*)malloc(_capacity * sizeof(char));*/
            string ptr(s._str);
            std::swap(_str, ptr._str);
            _size = s._size;
            _capacity = s._capacity;


        }

        string& operator=(const string& s)
        {
            string tmp(s);
            swap(tmp);
            return *this;
            
        }

        ~string()
        {
            free(_str);
            _size = 0;
            _capacity = 0;
        }



            //////////////////////////////////////////////////////////////

            // iterator

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        reverse_iterator rbegin()
        {
            return end();
        }

        reverse_iterator rend()
        {
            return begin();
        }

            /////////////////////////////////////////////////////////////

            // modify

        void push_back(char c)
        {
            if (_size + 1 == _capacity)
            {
                reserve(2 * _capacity);
                _capacity *= 2;
            }

            _str[_size] = c;
            _str[++_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
        }

        void append(const char* str)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                push_back(str[i]);
            }
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _size = 0;
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return this->_str;
        }



        /////////////////////////////////////////////////////////////

        // capacity

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0')
        {
            if (_size > n)
            {
                _size = n;
                _str[n] = '\0';
            }
            else
            {
                if (n > _capacity)
                {
                    reserve(n+2);
                }
                int i;
                for (i = _size; i < n; i++)
                {
                    _str[i] = c;
                }
                _str[i] = '\0';
            }
        
        }

        void reserve(size_t n)
        {
            if (_capacity < n)
            {
                _str = (char*)realloc(_str,n * sizeof(char));
            }
        }



        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index)
        {
            assert(index > 0);
            assert(index < _size);
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            return _str[index];
        }



        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s)
        {
            int i = 0;
            while (i < s._size && i < _size)
            {
                if (_str[i] < s._str[i])
                    return true;
                else
                    return false;
                i++;
            }

            if (i == s._size)
                return false;
            else
                return true;
        }

        bool operator<=(const string& s)
        {
            return this->operator>(s);
        }

        bool operator>(const string& s)
        {
            int i = 0;
            while (i < s._size && i < _size)
            {
                if (_str[i] > s._str[i])
                    return true;
                else
                    return false;
                i++;
            }

            if (i == s._size)
                return true;
            else
                return false;
        }

        bool operator>=(const string& s)
        {
            return !this->operator<(s);
        }

        bool operator==(const string& s)
        {
            if (_size != s._size)
                return false;
            int i = 0;
            while (i < s._size)
            {
                if (_str[i] != s._str[i])
                    return false;
                i++;
            }
            return true;
        }

        bool operator!=(const string& s)
        {
            return !this->operator==(s);

        }



        // ����c��string�е�һ�γ��ֵ�λ��

        size_t find(char c, size_t pos = 0) const
        {
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == c)
                    return i;
            }

            return npos;    //string::npos��string�����õ��Ǻ궨��
        }

        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��

        size_t find(const char* s, size_t pos = 0) const
        {
            char* ptr = nullptr;
            if (ptr=strstr(_str, s + pos))
                return ptr - _str;
            else
                return npos;

        }

        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

        string& insert(size_t pos, char c)
        {
            assert(pos >= 0);
            push_back('\0');
            int i = 0;
            for (i = _size; i > pos; i--)
            {
                _str[i] = _str[i - 1];
            }
            _str[i] = c;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                push_back('\0');
            }
            int i = 0;
            for (i = strlen(_str)+strlen(str)-1; i > pos+strlen(str)-1; i--)
            {
                _str[i] = _str[i - strlen(str)];
            }
            

            for (int j = strlen(str)-1; j >=0; j--)
            {
                _str[i--] = str[j];
            }
            return *this;

        }



        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��



        string& erase(size_t pos, size_t len)
        {
            for (int i = pos+len ; i <=_size; i++)
            {
                _str[i - len]=_str[i] ;

            }
            return *this;
        }

    private:

        char* _str;

        size_t _capacity;

        size_t _size;   //������'/0'

    };

    std::ostream& operator<<(std::ostream& _cout, const sht::string& s)
    {
        _cout << s._str;
        return _cout;
    }

    std::istream& operator>>(std::istream& _cin, sht::string& s)
    {
        char a;
        std::cin >> a;
        while (a != '\n')
        {
            s.push_back(a);
            _cin.get(a);
        }
       


        return _cin;
    }

}


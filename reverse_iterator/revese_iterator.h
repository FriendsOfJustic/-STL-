#pragma once

namespace sht
{
	//ref �����ݽṹ�����������͵����ã��������ΪT&
	//Ptr ���������͵ĵ�ַ���������ΪT*

	// �����������rbegin =  ����������� begin
	//�����������rend =  ����������� end
	template<class iterator, class Ref,class Ptr>
	class reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;
	public:
		reverse_iterator(iterator it)
			:_it(it)
		{

		}

		Ref operator*()  //���ص�����ָ���ǰһ��Ԫ��
		{
			iterator tmp = _it;   
			return *(--tmp);      //������Ϊbegin =rend end=rbegin �������������ʱ����������Ľ�������������tmp�ĺϷ��Խ��м��
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
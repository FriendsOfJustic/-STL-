#include<iostream>
#include"My_queue.h"
using namespace std;
int main()
{
    sht::My_queue<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);


    while (!st.empty())
    {
        cout << st.front() << endl;
        st.pop();
    }
    return 0;
}

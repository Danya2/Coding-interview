/* There are something to be attention when coding this segment
Firstly, you must be attention the return or parametrs style of function 
in class 
 */
#pragma once
#include <iostream>
#include <stack>

using namespace std;
template <typename T> class CQueue
{
public:
    CQueue(void){};
    ~CQueue(void){};

    void appendTail(const T& element);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}
template <typename T> T CQueue<T>::deleteHead()
{
   if(stack2.size() == 0)
   {
       while(stack1.size())
       {
           T& data = stack1.top();
           stack1.pop();
           stack2.push(data);
       }
   }
   if(stack2.size() != 0)
   {
       T head = stack2.top();
       stack2.pop();
       return head;
   }
   else exit(1);
}


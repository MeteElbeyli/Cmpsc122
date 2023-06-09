
#ifndef __STACK__
//Issue above?
#define __STACK__

#include <iostream>
#include <string>
#include "list.h"
using namespace std;

template<typename T>
class Stack
{
private:
List<T> list; // assume list.head is stack.top
public:
Stack();
bool IsEmpty() const;
void Push(T elem);
T Pop();
T Top();
void Clear();

operator string() const;
};

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::IsEmpty() const
{
return list.IsEmpty();
}

template<typename T>
Stack<T>::operator string() const
{
if (IsEmpty())
return "()";

List<T> copied_list(list);

stringstream os;
os << "(";
while (copied_list.IsEmpty() == false)
{
os << copied_list.GetTail();
copied_list.RemoveTail();
if (copied_list.IsEmpty() == false)
os << ",";
}
os << ")";
string str = os.str();

return str;
}

template<typename T>
void Stack<T>::Push(T elem)
{
list.AddToHead(elem);
}

template<typename T>
T Stack<T>::Pop()
{
return list.RemoveHead();
}
template<typename T>
T Stack<T>::Top()
{
return list.GetHead();
}

template<typename T>
void Stack<T>::Clear()
{
while (!IsEmpty())
list.RemoveTail();
}



// I have an issue when running this bc when I did it with xcode while deleting I hit remove refrence instead of delete so now it was removed from my code and left on my harddrive so I had to find it


 //#ifndef __STACK__
// #define __STACK__
// #include <iostream>
// #include <string>
// #include "list.h"
// template<typename T>
// class Stack
// {
// private:
//     List<T> list; // assume list.head is stack.top
// public:
//     Stack();
//     bool IsEmpty() const;
//     void Push(T elem);
//     T Pop();
//     T Top();
//     void Clear();
 //    operator string() const;
 //  ///////////////////////////////////////////
     // Do not change the above prototype.
     // Add member function(s) below if you need.
     // Do not change the below.
     ///////////////////////////////////////////
// };
// template<typename T>
// Stack<T>::Stack()
// {
// }
// template<typename T>
// bool Stack<T>::IsEmpty() const
// {
//     return list.IsEmpty();
 //}
 //template<typename T>
 //Stack<T>::operator string() const
 //{
  //   if (IsEmpty())
      //   return "()";
    // List<T> copied_list(list);
   //  stringstream os;
  //   os << "(";
  //   while (copied_list.IsEmpty() == false)
  //   {
  //       os << copied_list.GetTail();
  //       copied_list.RemoveTail();
  //       if (copied_list.IsEmpty() == false)
  //           os << ",";
  //   }
  //   os << ")";
  //   string str = os.str();
  //   return str;
// }

#endi

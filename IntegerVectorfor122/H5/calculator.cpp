
//Name:Mete Elbeyli
//Date Due: April 27
//Sources: Youtube, the Cherno, canvas zoom recordings, w3schools


#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "list.h"
#include "stack.h"

using namespace std;
int Precedence(char c);
bool Operand(char c);

string InfixToPostfix(string infix)
{
    
string postfix = "  ";
    
    
Stack<char> s;
                
    for (size_t i = 0; i < infix.length(); i++)
{
if (Operand(infix[i]))
{
    postfix += infix[i];
}
else
{
switch (infix[i])
{
case '(':
    s.Push(infix[i]);
break;

case '-':
case '/':
case '*':
case '+':

        while (!s.IsEmpty() && Precedence(infix[i]) <= Precedence(s.Top()))
postfix += s.Pop();
        
s.Push(infix[i]);
break;
        
        
case ';':
        while (!s.IsEmpty())
postfix += s.Pop(); //pops
        break;
        
case ')':
        while (s.Top() != '(')
postfix += s.Pop();
s.Pop(); //pops
        break; //pops the paracentesis

        
}
    
}
    
}
return postfix;
    //brings the outpost back
}

double EvaluatePostfix(string postfix)
{
Stack<double> st;
for (size_t i = 0; i < postfix.length(); i++)
{

    if (Operand(postfix[i]))
st.Push(postfix[i]-'0'); //- 0
else
{
                double operand1 = st.Pop();
    
                double operand2 = st.Pop();
    
switch (postfix[i])
{
    case '/':
            st.Push(operand2 / operand1);
    break;
        
        
    case '-':
            st.Push(operand2 - operand1);
    break;

        
    case '*':
            st.Push(operand2 * operand1);
    break;
        
        
    case '+':
            st.Push(operand2 + operand1);
    break;

}
}
    
}
    
   // WHERE THE BREAKPOINT WAS ADDED
return st.Pop();
}


bool Operand(char c)
{
    if (c >= '0' && c <= '9')
return true;
    else
return false;
}

int Precedence(char c)
{

    if (c == '(' || c == ')')
return 0;
   
    else if (c == '*' || c == '/')
        return 2;

    else if (c == '+' || c == '-')
        return 1;


else
return -1;
}
// had a breakpoint earlier bc there was an issue whenever I ran

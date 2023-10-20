#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;
Stack_A::Stack_A()
{
    size = 0;
}
void Stack_A::push(int data)
{
    if (size == 1024)
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[size] = data;
        size++;
    }
}
int Stack_A::pop()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        int b = stk[size - 1];
        size--;
        return b;
    }
}
int Stack_A::get_element_from_top(int idx)
{
    if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    return stk[size - idx - 1];
}
int Stack_A::get_element_from_bottom(int idx)
{
    if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}
void Stack_A::print_stack(bool top)
{
    if (top)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << stk[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << endl;
        }
    }
}
int Stack_A::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int c = stk[size - 1] + stk[size - 2];
        size -= 2;
        push(c);
        return c;
    }
}
int Stack_A::subtract()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int d = stk[size - 2] - stk[size - 1];
        size -= 2;
        push(d);
        return d;
    }
}
int Stack_A::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int e = stk[size - 1] * stk[size - 2];
        size -= 2;
        push(e);
        return e;
    }
}
int Stack_A::divide()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        if (stk[size - 1] == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            int k = stk[size - 2] / stk[size - 1];
            if (stk[size - 2] * stk[size - 1] < 0 and stk[size-2]%stk[size-1]!=0)
            {
                k -= 1;
            }
            size -= 2;
            push(k);
            return k;
        }
    }
}
int *Stack_A::get_stack()
{
    int *p;
    p = stk;
    return p;
}
int Stack_A::get_size()
{
    return size;
}

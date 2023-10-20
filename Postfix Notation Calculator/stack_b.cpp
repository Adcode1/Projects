#include <iostream>
#include "stack_b.h"
#include <stdexcept>
using namespace std;
Stack_B::Stack_B()
{
    size = 0;
    capacity = 1024;
    try
    {
        stk = new int[capacity];
    }
    catch (const std::bad_alloc &e)
    {
        throw runtime_error("Out of Memory");
    }
}
Stack_B::~Stack_B()
{
    delete stk;
}
void Stack_B::push(int data)
{
    if (size > capacity - 1)
    {
        int *temp = new int[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = stk[i];
        }
        delete[] stk;
        stk = temp;
        stk[size] = data;
        capacity *= 2;
        size++;
    }
    else
    {
        stk[size] = data;
        size++;
    }
}
int Stack_B::pop()
{
    if (size <= 0)
    {
        throw runtime_error("Empty Stack");
    }
    else if (size < capacity / 4 and capacity > 1024)
    {
        int *temp = new int[capacity / 4];
        for (int i = 0; i < size; i++)
        {
            temp[i] = stk[i];
        }
        delete[] stk;
        stk = temp;
        capacity /= 4;
        size--;
        return stk[size];
    }
    else
    {
        size--;
        return stk[size];
    }
}
int Stack_B::get_element_from_top(int idx)
{
    if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    return stk[size - idx - 1];
}
int Stack_B::get_element_from_bottom(int idx)
{
    if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}
void Stack_B::print_stack(bool top)
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
int Stack_B::add()
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
int Stack_B::subtract()
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
int Stack_B::multiply()
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
int Stack_B::divide()
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
int *Stack_B::get_stack()
{
    int *p;
    p = stk;
    return p;
}
int Stack_B::get_size()
{
    return size;
}

#include <iostream>
#include <stdexcept>
#include "stack_c.h"
using namespace std;
Stack_C::Stack_C()
{
    try
    {
        stk = new List();
    }
    catch (const std::bad_alloc &e)
    {
        throw runtime_error("Out of Memory");
    }
}
void Stack_C::push(int d)
{
    stk->insert(d);
}
Stack_C::~Stack_C()
{
    delete stk;
}
int Stack_C::pop()
{
    if (stk->get_size() <= 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        int a = stk->delete_tail();
        return a;
    }
}
int Stack_C::get_element_from_top(int idx)
{
    Node *head = stk->get_head();
    int s = stk->get_size();
    int index = s - idx - 1;
    if (index < 0 || idx < 0)
    {
        throw runtime_error("Index out of range");
    }
    while (index >= 0)
    {
        head = head->next;
        index--;
    }
    return head->get_value();
}
int Stack_C::get_element_from_bottom(int idx)
{
    Node *head = stk->get_head();
    int s = stk->get_size();
    if (idx > s - 1 || idx < 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        while (idx >= 0)
        {
            head = head->next;
            idx--;
        }
        return head->get_value();
    }
}
void Stack_C::print_stack(bool top_or_bottom)
{
    Node *head = stk->get_head();
    int s = stk->get_size();
    if (top_or_bottom)
    {
        while (s > 0)
        {
            head = head->next;
            s--;
        }
        while (head != stk->get_head())
        {
            cout << head->get_value() << endl;
            head = head->prev;
        }
    }
    else
    {
        while (s > 0)
        {
            head = head->next;
            cout << head->get_value() << endl;
            s--;
        }
    }
}
int Stack_C::add()
{
        
    int s = stk->get_size();
    if (s < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = pop();
        int b = pop();
        int c = a + b;
        push(c);
        return c;
    }
}
int Stack_C::subtract()
{
    int s = stk->get_size();
    if (s < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = stk->delete_tail();
        int b = stk->delete_tail();
        int c = b - a;
        push(c);
        return c;
    }
}
int Stack_C::multiply()
{
    int s = stk->get_size();
    if (s < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = stk->delete_tail();
        int b = stk->delete_tail();
        stk->insert(a * b);
        return a * b;
    }
}
int Stack_C::divide()
{
    int s = stk->get_size();
    if (s < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = stk->delete_tail();
        int b = stk->delete_tail();
        if (a == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            int k = b / a;
            if (a * b < 0 && b % a != 0)
            {
                k -= 1;
            }
            push(k);
            return k;
        }
    }
}
List *Stack_C::get_stack()
{
    return stk;
}
int Stack_C::get_size()
{
    return stk->get_size();
}

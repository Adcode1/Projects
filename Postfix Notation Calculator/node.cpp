#include <iostream>
#include "node.h"
Node::Node(bool sentinel)
{
    is_sentinel = sentinel;
    value = -1;
    next = nullptr;
    prev = nullptr;
}
Node::Node(int v, Node *nxt, Node *prv)
{
    value = v;
    is_sentinel = false;
    next = nxt;
    prev = prv;
}
bool Node::is_sentinel_node()
{
    if (next == nullptr || prev == nullptr)
    {
        return true;
    }
    return false;
}
int Node::get_value()
{
    return value;
}

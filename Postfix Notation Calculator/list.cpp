#include<iostream>
#include "list.h"

using namespace std;
List::List(){
    sentinel_head=new Node();
    sentinel_tail=new Node();
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
    size=0;
}
List::~List(){
    while(sentinel_head->next!=sentinel_tail){
        this->delete_tail();
    }
}
void List::insert(int v){
    Node*temp=new Node(v,nullptr,nullptr);
    Node *temp2=sentinel_tail->prev;
        temp2->next=temp;
        temp->prev=temp2;
        temp->next=sentinel_tail;
        sentinel_tail->prev=temp;
        size++;
}
int List::delete_tail(){
        Node *temp3=sentinel_tail->prev;
            int deleted=0;
            temp3->prev->next=sentinel_tail;
            sentinel_tail->prev=temp3->prev;
            deleted=temp3->get_value();
            delete temp3;
            size--;
            return deleted;
}
int List::get_size(){
    return size;
}
Node* List::get_head(){
    return sentinel_head;
}

//---------------------------------------------------------------------
// Name: Mete Elbeyli
// Email: mbe5290@psu.edu
// Class: CMPSC 122
// Program 4
// Due Date: April 9 2021, 11:59 PM
//
// Description: Contains List class implemenation that will be
// used to implement Set class
//
// Acknowledgements: Used YT and your lectures, This NULL ISSUE isnt going away 
//
//---------------------------------------------------------------------
#include <iostream>
#ifndef UNTITLED9_LIST_H
#define UNTITLED9_LIST_H

#endif //UNTITLED9_LIST_H


class ListNode
{
private:
    int data;
    ListNode* next;
    ListNode* prev;


public:
    
    ListNode() { prev = next = NULL; }
    ListNode(int d, ListNode* p,  ListNode* n) {  data = d; prev = p; next = n; }

    friend class List;
};
 
class List
{
private:
    ListNode* tail;
 ListNode* head;

public:
    List() { head = tail = NULL; }
    ~List();

    bool isEmpty() { return head == NULL; }
    bool contains(int value);
    
    void addToTail(int value);
    void addToHead(int value);
   
    int removeTail();
    int removeHead();
   

    int removeAt(int index);
    bool remove(int value);

    int at(int index);
    int valueOf(const ListNode* elem);
    const ListNode* getNext(const ListNode* node);
    const ListNode* getPrevious(const ListNode* node);
    const ListNode* getTail() { return tail; }
    const ListNode* getHead() { return head; }
  
};

List::~List()
{
    while (!isEmpty())
        removeTail();
}

bool List::contains(int value)
{
    ListNode *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    return temp != NULL;
}

void List::addToHead(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, NULL, NULL);
    }
    else
    {
         head = new ListNode(value, NULL, head);
           head->next->prev = head;
    }
}

void List::addToTail(int value)
{
    if (isEmpty())
    {
           head = tail = new ListNode(value, NULL, NULL);
    }
    else
    {
            tail = new ListNode(value, tail, NULL);
            tail->prev->next = tail;
    }
}

int List::removeHead()
{
    int value = head->data;
    if (head == tail)
    {
        delete tail;
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }

    return value;
}

int List::removeTail()
{
    int value = head->data;
    if (head == tail)
    {
        delete tail;
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }

    return value;
}

int List::removeAt(int index) {
    int c = 0;

    for (ListNode *temporary = head; temporary != NULL; temporary = temporary->next)

        c++;

    if (index < 0 || index > c)

        exit(1);

    else {

        remove(at(index));

        return (at(index));
    }
}

bool List::remove(int value)
{
    if(contains(value))
    {

        ListNode * curr = head;

        ListNode * prev = head;

        while (curr -> data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        ListNode* aft = curr->next;
        prev->next = aft;

        if (aft != NULL)
        {
            aft->prev = prev;
        }

        delete curr;
        return true;
    }
    else

        return false;

}



int List::at(int index)
{
    ListNode *temporary = head;

    for( int i = 1; i < index; i++) {
        if (temporary->next == NULL) {


            exit(1);
        }

        temporary = temporary->next;
    }


    return valueOf(temporary);
}

int List::valueOf(const ListNode* elem)
{
    return elem -> data;
}

const ListNode* List::getNext(const ListNode* node)
{
    return node -> next;
}

const ListNode* List::getPrevious(const ListNode* node)
{
    return node -> prev;
}

//
//  main.cpp
//  HomeWork4Finalredo May 3 2022
//
//  Created by Mete Elbeyli on 5/3/22.
//
// refrences: Nullptr instead of Null


#include <iostream>
#include <unistd.h>
using namespace std;

class ListNode
{
private:
    int data;
    ListNode* prev;
    ListNode* next;
public:
    ListNode() { prev = next = nullptr; }
    ListNode(int d, ListNode* p, ListNode* n) { data = d; prev = p; next = n; }
    friend class List;
};
class List
{
private:
    ListNode* head;
    ListNode* tail;
public:
    List() { head = tail = nullptr; }
    ~List();
    bool isEmpty() { return head == nullptr; }
    bool contains(int value);
    void addToHead(int value);
    void addToTail(int value);
    int removeHead();
    int removeTail();
    int removeAt(int index);
    bool remove(int value);
    int at(int index);
    int valueOf(const ListNode* elem);
    const ListNode* getNext(const ListNode* node);
    const ListNode* getPrevious(const ListNode* node);
    const ListNode* getHead() { return head; }
    const ListNode* getTail() { return tail; }
};

List::~List()
{
    while (!isEmpty())
        removeTail();
}
bool List::contains(int value)
{
    ListNode *temp = head;
    while (temp != nullptr && temp->data != value)
        temp = temp->next;
    return temp != nullptr;
}
void List::addToHead(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, nullptr, nullptr);
    }
    else
    {
        head = new ListNode(value, nullptr, head);
        head->next->prev = head;
    }
}
void List::addToTail(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, nullptr, nullptr);
    }
    else
    {
        tail = new ListNode(value, tail, nullptr);
        tail->prev->next = tail;
    }
}
int List::removeHead()
{
    int value = head->data;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    return value;
}
int List::removeTail()
{
    int value = head->data;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return value;
}
int List::removeAt(int index)
{
    ListNode* temp1 = head;
    for(int i = 0; i <= index; i++)
    {
        temp1 = temp1->next;
    }

    temp1->prev->next = temp1->next;
    temp1->next->prev = temp1->prev;

    int dataTemp = temp1->data;

    delete temp1;

    return dataTemp;
// TODO: implement removeAt
}
bool List::remove(int value)
{
    if(contains(value))
    {
        ListNode *temp1 = head;
        while (temp1->data != value) {
            temp1 = temp1->next;
        }
        if(temp1 == head)
        {
            temp1->next->prev = nullptr;
            head = temp1->next;
        }else if(temp1 == tail)
        {
            temp1->prev->next = nullptr;
            tail = temp1->prev;
        }else {
            temp1->prev->next = temp1->next;
            temp1->next->prev = temp1->prev;
        }

        return true;
    }
    else
    {
        return false;
    }
// TODO: implement remove
}
int List::at(int index)
{
    ListNode *temp1 = head;
    for(int i = 0; (i < index && temp1 != nullptr); i++)
    {
        temp1 = temp1->next;
    }
    if(temp1 == nullptr)
    {
        exit(1);
    }
    return temp1->data;

// TODO: implement at
}
int List::valueOf(const ListNode* elem)
{
    return elem->data;
// TODO: implement valueOf
}
const ListNode* List::getNext(const ListNode* node)
{
    return node->next;
// TODO: imoplement getNext
}
const ListNode* List::getPrevious(const ListNode* node) {
    return node->prev;
// TODO: implement getPrevious
}

class Set
{
private:
    List* list;
    int set_size;
public:
    Set();
    ~Set();
    bool contains(int value);
    bool add(int value);
    bool remove(int value);
    void clear();
    Set* set_union(Set&);
    Set* intersection(Set&);
    Set* difference(Set&);
    void print();
    int size() { return set_size; }
};

Set::Set()
{
    list = new List;
    set_size = 0;
}

Set::~Set()
{
    set_size = 0;
    delete list;
}

bool Set::contains(int value)
{
    return list->contains(value);
}

bool Set::add(int value)
{
    if(!contains(value))
    {
        list->addToTail(value);
        set_size++;
        return true;
    }else
    {
        return false;
    }
}

bool Set::remove(int value)
{
    if(contains(value))
    {
        set_size--;
    }
    return list->remove(value);
}

void Set::clear()
{
    set_size = 0;
    delete list;
}

Set* Set::set_union(Set& other)
{
    Set* unionSet = new Set;
    for(int i = 0; i < set_size; i++)
    {
        unionSet->add(list->at(i));
    }
    for(int i = 0; i < other.set_size; i++)
    {
        unionSet->add(other.list->at(i));
    }
    return unionSet;

}

Set* Set::intersection(Set& other)
{
    Set* intersectionSet = new Set;

    for(int i = 0; i < other.set_size; i++)
    {
        if(contains(other.list->at(i)))
        {
            intersectionSet->add(other.list->at(i));
        }
    }
    return intersectionSet;
}

Set* Set::difference(Set& other)
{
    Set* differenceSet = new Set;

    for(int i = 0; i < set_size; i++)
    {
        if(!other.contains(list->at(i)))
        {
            differenceSet->add(list->at(i));
        }
    }
    return differenceSet;
}

void Set::print()
{
    cout << "set elements(" << set_size << "): ";
    for(int i = 0; i < set_size; i++)
    {
        cout << list->at(i) << " ";
    }
    cout << endl;
}
void menu(Set Set1, Set Set2);
int main() {

    int size_1_set;
    int size_2_set;

    cout << "Enter starting size of Set 1: " << endl;
    cin >> size_1_set;
    cout << "Enter starting size of Set 2: " << endl;
    cin >> size_2_set;

    Set Set1;
    Set Set2;

    int temp;
    cout << "Enter "<< size_1_set <<" values for Set #1: ";
    for(int i = 0; i < size_1_set; i++)
    {
        cin >> temp;
        Set1.add(temp);
    }
    cout << endl;
    cout << "Enter " << size_2_set <<" values for Set #2:" ;
    for(int i = 0; i < size_2_set; i++)
    {
        cin >> temp;
        Set2.add(temp);
    }
    cout << endl;

    menu(Set1, Set2);

    return 0;
}




void menu(Set Set1, Set Set2)
{
    string command;
    bool quit = true;
    int value;
    int index;
    int set;
    
    
    cout << "Now accepting commands (quit to exit program)" << endl;
    do {
        cout << " ";
        cin >> command;
      
        if (command == "contains") {
            cin >> value;
            cin >> set;
            if(set == 1){
                if(Set1.contains(value)){
                    cout << "true" << endl;
                }else
                {
                    cout << "false" << endl;
                }
            }
            else if(set == 2){
                if(Set2.contains(value)){
                    cout << "true" << endl;
                }else
                {
                    cout << "false" << endl;
                }
            }
        }
        
        else if (command == "add") {
            cin >> value;
            cin >> set;
            if (set == 1) {
                if (Set1.add(value)) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            }else if (set == 2) {
                if (Set2.add(value)) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            }
        }else if (command == "remove"){
            cin >> value;
            cin >> set;
            if (set == 1)
            {
                if (Set1.remove(value)) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            }else if (set == 2) {
                if (Set2.remove(value)) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            }
        }
        else if (command == "print")
        {
            cin >> set;
            if(set == 1)
            {
                Set1.print();
            }else if(set == 2)
            {
                Set2.print();
            }
        }
        else if(command == "union")
        {
            Set* unionSet = Set1.set_union(Set2);
            unionSet->print();
        }
        else if(command == "intersection")
        {
            Set* intersectionSet = Set1.intersection(Set2);
            intersectionSet->print();
        }
        
        else if(command == "difference")
        {
            Set* differenceSet1 = Set1.difference(Set2);
            Set* differenceSet2 = Set2.difference(Set1);
            differenceSet1->print();
            differenceSet2->print();
        }else if(command == "quit")
        {
            quit = false;
        }

    }while (quit);
    
    return;
}

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
#include "list.hpp"

using namespace std;

class Set
{
private:
    List* list;
    int set_size;
public:
    Set(){
        list = NULL;
        set_size = 0;
    }
    ~Set(){
        delete list;
        set_size = 0;
    }

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

bool Set::contains(int value) {

    return list -> contains(value);
    }


bool Set::add(int value) {

    if (!contains(value))

    {
        list->addToTail(value);
    }

    else {return false;}

}

bool Set::remove(int value) {

   return list -> remove(value);
}

void Set::clear() {

    set_size = 0;

    delete list;
}

Set *Set::set_union(Set &pS) {

    Set *temporary = new Set();

    for (int i= 1; i<set_size; i++)

        temporary->add(pS.list->at(i));

    return  temporary;

}

Set *Set::intersection(Set &pS) {

    Set *temporary = new Set();
    for ( int i = 0; i < set_size; i++) {

        if (pS.contains(list->at(i))) {

            temporary -> add(list->at(i));
        }
    }

    return temporary;
}

Set *Set::difference(Set &pS) {

    Set *temporary = new Set();

    for ( int i = 0; i < set_size; i++) {

        if (pS.contains(list -> at(i) ) )
        {
            temporary -> add(list -> at (i) );
        }
    }
    return temporary;
}

void Set::print() {
    cout << " set elements(" << size() <<") :"<< flush;

    for (int i = 0; i < size(); i++)
    {
        cout << list -> at(i) << endl;
    }

}

int main() {

    int s1;
    int s2;
    int sz1;
    int sz2;
    string c;
    string cL;


    cout << "Enter size for Set 1:";
    cin >> sz1;
    int sArr1[sz1];

    cout << " Enter size for Set 2:";
    cin >> sz2;
    int sArr2[sz2];

    cout << "  Enter " << s2 << " values for Set 1:";
    for (int i = 1; i < s1; i++)
    {
        cin >> sArr1[i];

    }

    cout << " Enter " << s2 << " values for Set 2:";

    for (int i = 1; i < s1; i++)
    {
       cin >> sArr2[i];
    }

    List l1, l2;
    for(int i = sz1; i <= 0; i--)

        l1.addToHead(sArr1[i]);

    for (int j = sz2; j <= 0; j--)

        l2.addToHead(sArr2[j]);


    Set set_1, set_2;

    cout << "Now accepting commands (quit to exit): ";

    string cmd;

    while(cmd != "quit")
    {
        cin >> cmd;


        if( cmd == "contains"||cmd == "add"||cmd == "remove" )
        {

            int setN;

            int val;

            if(cmd == "contains")

            {

                cin >> setN;

                if(setN == 1)
                {
                    cin >> val;
                    set_1.contains(val);
                }

                if(setN == 2){
                    cin >> val;
                    set_2.contains(val);
                }
            }
            if(cmd == "add"){

                cin >> setN;

                if(setN == 1)
                {
                    cin >> val;
                    set_1.add(val);
                }

                if(setN == 2)
                {
                    cin >> val;
                    set_2.add(val);
                }
            }
            if(cmd == "remove")
            {

                cin >> setN;
                if(setN == 1){
                    cin >> val;
                    set_1.remove(val);
                }

                if(setN == 2){
                    cin >> val;
                    set_2.remove(val);
                }
            }
        }

        if(cmd == "print")
        {
            int setN;
            cin >> setN;

            if(setN == 1)
                set_1.print();

            if(setN == 2)
                set_2.print();
        }

        if(cmd == "union") {

            set_1.set_union(set_2);

            set_1.print();
        }
        if(cmd == "intersection") {

            set_1.intersection(set_2);

            set_1.print();
        }
        if(cmd == "difference"){

            cout << "First - Second: " << set_1.difference(set_2) << endl;

            cout << "Second - First: " << set_2.difference(set_1) << endl;
        }

        if(cmd == "quit")

            exit(0);
    }


    return 0;
}

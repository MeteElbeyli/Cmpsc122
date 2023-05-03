//---------------------------------------------------------------------
// Name: Mete Elbeyli
// Email: mbe5290@psu.edu
// Class: CMPSC 122, Section 3
// Program 3.2
// Due Date: March 19 2020, 11:59 PM
//
// Description: This program implements a basic integer vector
// and provides the user with an interactive prompting system
// to issue commands over an instance of our BasicVector class.
//
// Acknowledgements:
// 1. I used youtube videos such as the Cherno for some help, along side W3 school's
//-----------------------------------------------------
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

template <typename T>

class BasicVector
{

private:
    int vector_size;
    int vector_capacity;
    T *data;
    void resize();

public:
    BasicVector(){}; // A default constructor
    BasicVector(int);
    ~BasicVector();
    
    T & at(int);
    T &operator[](int);
    T &front();
    T &back();
    
    void push_back(T);
    void insert(T, T);
    void pop_back();
    int size();
    int capacity();
    void print();
};

template <typename T>

///
void BasicVector<T>::resize(){
  
    
    this->vector_capacity *= 2;
    //Makes a new capacity
    T *temp = new T[vector_capacity];

    // loop to copy the existing elements from data to temp
    for (int i = 0; i < vector_size; i++)
        temp[i] = data[i];
    delete[]data; // deletes the old mem
    data = temp; // makes data = temp now



    template <typename T>
    BasicVector<T>::BasicVector(int cap)
    {
        if (cap < 16)
            this->vector_capacity = 16;
        int pow2 = 2;
        while (cap > pow2)
        {
            pow2 *= 2;
        }
        this->vector_capacity = pow2;

        // create an array of capacity of type T
        data = new T[vector_capacity];
        vector_size = 0;
    }
    template <typename T>
    BasicVector<T>::~BasicVector()
    {
        delete[]data;
    }

    // function to return the element at given index
    // change the return type to T
    template <typename T>
    T & BasicVector<T>::at(int index)
    {
        return data[index];
    }

    // overloaded operator [] to return the element at given index
    // change the return type to T
    template <typename T>
    T & BasicVector<T>::operator[](int index)
    {
        return data[index];
    }

    // function to return the front element of vector
    template <typename T>
    T & BasicVector<T>::front()
    {
        return data[0];
    }

    // function to return the back element of vector
    // change the return type to T
    template <typename T>
    T & BasicVector<T>::back()
    {
        return data[vector_size - 1];
    }

    // function to insert value at the end of vector
    // change the parameter type to T
    template <typename T>
    void BasicVector<T>::push_back(T value)
    {
        if (vector_size == vector_capacity)
            resize();
        data[vector_size++] = value;
    }

    // function to remove the last element of the vector
    template <typename T>
    void BasicVector<T>::pop_pack()
    {
        if (vector_size == 0) // vector is empty, do nothing
            return;
        data[vector_size - 1] = T(); // set the last element to default value of T instead of 0
        vector_size--; // decrement size by 1
    }

    // function to insert value at given index
    // change the parameter type for value to T
    template <typename T>
    void BasicVector<T>::insert(int index, T value)
    {
        if (vector_size == vector_capacity) // vector is full, resize the vector
            resize();

        // loop to shift the elements right by 1 position from index to end
        for (int i = vector_size; i > index; i--)
            data[i] = data[i - 1];
        data[index] = value; // set element at index to value
        vector_size++; // increment size by 1
    }

    // function to return size of vector
    template <typename T>
    int BasicVector<T>::size()
    {
        return vector_size;
    }

    // function to return capacity of vector
    template <typename T>
    int BasicVector<T>::capacity()
    {
        return vector_capacity;
    }

    // function to display the elements of the vector
    template <typename T>
    void BasicVector<T>::print()
    {
        cout << "elements(" << vector_size << "):";
        // loop from start index(0) to size of vector-1(inclusive), displaying each element of vector
        for (int i = 0; i < vector_size; i++)
            cout << " " << data[i];
        cout << endl;
    }

    // function prototype to execute the menu for the BasicVector object reference of given template type as parameter
  
    /**
    * function that takes as input a reference of BasicVector object and
    * execute the commands input by the user until they quit
    */

    void menu(BasicVector<T>& vector)
    {
        T value; // declare a variable of type T to read the data values
        int index;
        string command;

        cout << endl << "Now accepting commands (quit to exit program):" << endl;

        // loop that continues until the user quits
        while (true)
        {
            cout << "> ";
            cin >> command; // read the command

            // based on command, execute the command
            if (command == "push")
            {
                cin >> value;
                vector.push_back(value);
                cin.ignore();
            }
            else if (command == "at")
            {
                cin >> index;
                cout << vector.at(index) << endl;
                cin.ignore();
            }
            else if (command == "get")
            {
                cin >> index;
                cout << vector[index] << endl;
                cin.ignore();
            }
            else if (command == "front")
            {
                cout << vector.front() << endl;
            }
            else if (command == "back")
            {
                cout << vector.back() << endl;
            }
            else if (command == "insert")
            {
                cin >> index >> value;
                vector.insert(index, value);
                cin.ignore();
            }
            else if (command == "pop")
            {
                vector.pop_pack();
            }
            else if (command == "size")
                cout << vector.size() << endl;
            else if (command == "capacity")
                cout << vector.capacity() << endl;
            else if (command == "print")
                vector.print();
            else if (command == "quit")
                break;
            else
                cout << "invalid command" << endl;
        }

    }
    
}

int main(){
    int type;
    int capacity;

    // input the type of data to store in the vector
    cout << "Specify what data type to store in vector:" << endl;
    cout << "\t1) int" << endl;
    cout << "\t2) float" << endl;
    cout << "\t3) double" << endl;
    cout << "\t4) string" << endl;
    cout << "\t5) bool" << endl;
    cout << "> ";
    cin >> type;

    // input the vector capacity
    cout << "Enter starting capacity of vector: ";
    cin >> capacity;

    // based on data type choice, create a vector of given type and capacity and call menu passing the vector object to execute the commands
    if(type == 1) // int
    {
        BasicVector<int> vector(capacity);
        menu(vector);
    }
    else if(type == 2) // float
    {
        BasicVector<float> vector(capacity);
        menu(vector);
    }
    else if(type == 3) // double
    {
        BasicVector<double> vector(capacity);
        menu(vector);
    }
    else if(type == 4) // string
    {
        BasicVector<string> vector(capacity);
        menu(vector);
    }
    else if(type == 5) // bool
    {
        BasicVector<bool> vector(capacity);
        menu(vector);
    }

    cout << endl << "Exiting program." << endl;
    system("pause");
    return 0;
}

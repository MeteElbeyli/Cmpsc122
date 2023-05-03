//
// Mete Elbeyli 4th draft of HW 3 - updated
// May 2 22
// Code didnt run multiple times becuase of an issue -> updating x code and new version of mac
//

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
    BasicVector() {}; 
    BasicVector(int);
    ~BasicVector();

    
    T & at(int);
    T &operator[](int);
    T &front();
    T &back();

    void push(T);
    void insert(int, T);

    void pop();

    int size();
    int capacity();

    void print();
};

template <typename T>
void BasicVector<T>::resize()
{
    this->vector_capacity *= 2;
    T *temp = new T[vector_capacity];

  
    for (int i = 0; i < vector_size; i++)
        temp[i] = data[i];
    delete[]data;
    data = temp;
}

// constructor
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

    data = new T[vector_capacity];
    vector_size = 0;
}

// destructor
template <typename T>
    BasicVector<T>::~BasicVector()
{
    delete[]data;
}

template <typename T>
    T & BasicVector<T>::at(int index)
{
    return data[index];
}

template <typename T>
T & BasicVector<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
T & BasicVector<T>::front()
{
    return data[0];
}

template <typename T>
T & BasicVector<T>::back()
{
    return data[vector_size - 1];
}

template <typename T>
void BasicVector<T>::push(T value)
{
    if (vector_size == vector_capacity)
        resize();
    data[vector_size++] = value;
}

template <typename T>
void BasicVector<T>::pop()
{
    if (vector_size == 0)
        return;
    data[vector_size - 1] = T();
    vector_size--;
}


template <typename T>
void BasicVector<T>::insert(int index, T value)
{
    if (vector_size == vector_capacity)
        resize();

    for (int i = vector_size; i > index; i--)
        data[i] = data[i - 1];
    data[index] = value;
    vector_size++;
    
}

template <typename T>
int BasicVector<T>::size()
{
    return vector_size;
}

template <typename T>
int BasicVector<T>::capacity()
{
    return vector_capacity;
}

template <typename T>
void BasicVector<T>::print()
{
    cout << "elements(" << vector_size << "):";
    for (int i = 0; i < vector_size; i++)
        cout << " " << data[i];
    cout << endl;
}


template <typename T>
void menu(BasicVector<T>& vector);

int main()
{
    int type;
    int capacity;

    cout << "Specify what data type to store in vector:" << endl;
    cout << "\t1) int" << endl;
    cout << "\t2) float" << endl;
    cout << "\t3) double" << endl;
    cout << "\t4) string" << endl;
    cout << "\t5) bool" << endl;
    cout << "> ";
    cin >> type;

    cout << "Enter starting capacity of vector: ";
    cin >> capacity;


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


template <typename T>
void menu(BasicVector<T>& vector)
{
    T value;
    int index;
    string command;

    cout << endl << "Now accepting all commands /quit to exit/:" << endl;
    
    while (true)
    {
       
        
        cout << "> ";
        cin >> command; 

        if (command == "push")
        {
            cin >> value;
            vector.push(value);
            cin.ignore();
        }
        else if (command == "at")
        {
            cin >> index;
            cout << vector.at(index) << endl;
            cin.ignore();
        }
        else if (command == "help") 
        {
            cout << "push, at, get, front, back, insert, pop ";
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
            vector.pop();
        }
        
        else if (command == "capacity")
            cout << vector.capacity() << endl;
        else if (command == "size")
                cout << vector.size() << endl;
        else if (command == "print")
            vector.print();
        else if (command == "quit")
            break;
            
        else
        cout << "Command inputed is invalid" << endl;
    }

}


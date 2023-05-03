
#include<iostream>
#include<string>
using namespace std;

class BasicVector
{
private:
    int vector_size;
    int vector_capacity;
    int *data;

    void resize();
public:
    BasicVector() {};// default constructor that does nothing
    BasicVector(int);
    ~BasicVector();

    int & at(int);
    int &operator[](int);
    int &front();
    int &back();

    void push(int);
    void insert(int, int);
    void pop();

    int size();
    int capacity();

    void print();
};


void BasicVector::resize() {
        this->vector_capacity *= 2;
        int *temp = new int[vector_capacity];
        for (int i = 0; i < vector_size; i++)
        temp[i] = data[i];
        delete[]data;
        data = temp;
}
BasicVector::BasicVector(int cap) {
    if (cap < 16)
        this->vector_capacity = 16;
    int pow2 = 2;
    while (cap > pow2)
    {
        pow2 *= 2;
    }
    this->vector_capacity = pow2;
    data = new int[vector_capacity];
    vector_size = 0;

}
BasicVector::~BasicVector()
{
    delete[]data;
}

int & BasicVector::at(int index){
    return data[index];
}

int & BasicVector::operator[](int index){
    return data[index];
}

int & BasicVector::front(){
    return data[0];
}

int & BasicVector::back(){
    return data[vector_size - 1];
}

void BasicVector::push(int value){
    if (vector_size == vector_capacity)
        resize();
    data[vector_size++] = value;
}

void BasicVector::pop(){
    if (vector_size == 0)
        return;
   
    data[vector_size - 1] = 0;
    vector_size-- ;
}

void BasicVector::insert(int index, int value){
    if (vector_size == vector_capacity)
        resize();
    for (int i = vector_size; i > index; i--)
        data[i] = data[i - 1];
    data[index] = value;
    vector_size++;
}

int BasicVector::size(){
    return vector_size;
}

int BasicVector::capacity(){
    return vector_capacity;
}



void BasicVector::print(){
    cout << "elements(" << vector_size << "): "<<data[0];
    for (int i = 1; i < vector_size; i++)
        cout << " " << data[i];
    cout << endl;
}

int main()
{
    int capacity;
    cout << "Enter starting capacity of vector: ";
    cin >> capacity;
    BasicVector vector(capacity);
    int value, index;
    string command;
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
        else if (command == "size")
            cout << vector.size() << endl;
        else if (command == "capacity")
            cout << vector.capacity() << endl;
        else if (command == "print")
            vector.print();
        else if (command == "quit")
            break;
        else
            cout << "invalid commnad" << endl;
    }
        
        system("Pause");
        return 1;
}

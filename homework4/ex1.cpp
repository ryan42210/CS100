#include<iostream>
#include<cstring>

using namespace std;

class DynamicArray {
public:
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    ~DynamicArray ();
    void assign(const DynamicArray& other);
    int getSize() const;
    int getCapacity() const;
    int at(int index) const;
    void push(const int item);
    bool remove(const int index);
private:
    int size;
    int capacity;
    int* data;
};

DynamicArray:: DynamicArray (){
    size = 0;
    capacity = 5;
    data = new int[5];
}

DynamicArray:: DynamicArray(const DynamicArray& other){
    data = new int[other.capacity]();
    for (int i = 0; i < other.size; i++){
        data[i] = other.data[i];
    }
    capacity = other.capacity;
    size = other.size;
}

DynamicArray:: ~DynamicArray(){
    delete []data;
}

void DynamicArray:: assign(const DynamicArray& other){
    delete []data;
    data = new int[other.capacity];
    for (int i = 0; i < other.size; i++){
        data[i] = other.data[i];
    }
    capacity = other.capacity;
    size = other.size;
}

int DynamicArray:: getSize() const{
    return size;
}

int DynamicArray:: getCapacity() const{
    return capacity;
}

int DynamicArray:: at(int index) const{
    return data[index];
}

void DynamicArray:: push(const int item){
    data[size] = item;
    size++;
    if (size == capacity){
        std::cout << "(resize) from "<<capacity << " to " << capacity * 2 << '\n';
        capacity = capacity * 2;
        int* newdata = new int[capacity];
        memcpy(newdata,data,size * sizeof(int));
        delete []data;
        data = newdata;
    }
}

bool DynamicArray:: remove(const int index){
    if (index >= 0 && index <= size - 1){
        for (int i = 0; i < size - index - 1; i++){
            data[index + i] = data[index + i + 1];
        }
        size--;
        return true;
    }
    else return false;
}



int main(){
    DynamicArray A;
    A.push(576);
    A.push(23);
    A.push(45);
    A.push(65);
    A.push(93);
    A.push(945);
    A.push(84);
    DynamicArray &a = A;
    DynamicArray B(a);
    DynamicArray c;
    c.assign(a);
    B.remove(1);
    B.remove(0);
    for (int i = 0; i < B.getSize(); i++) {
        std::cout << B.at(i) << std::endl;
    }
    std::cout << B.getSize() << std::endl << B.getCapacity() <<std::endl;
    return 0;
}
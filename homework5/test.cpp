#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;


class base{
public:
    base(int a);
    virtual void func() = 0;
protected:
    int m_a;
    int m_b;
};
base::base(int a){
    m_a = a;
}


class child1 : public base{
public:
    child1(int a);
    virtual void func();
};

class child2 : public base{
public:
    child2(int a);
    virtual void func();
};


child1::child1(int a):base(a) {
    m_b = a + 1;
}

child2::child2(int a):base(a) {
    m_b = a + 2;
}

void child1::func(){
    cout << "call child1  " << m_b << m_a <<endl;
}

void child2::func(){
    cout << "call child2  " << m_b << m_a <<endl;
}

int main() {
    base *b = new child1(1);
    b->func();
    delete b;
}
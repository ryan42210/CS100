#include <iostream>
#include <vector>
#include <string>

class Test {
public:
    Test() {};
    ~Test() {};
    int getNum() {
        return m_num;
    }
    int add(Test& pra) {
        return m_num + pra.m_num;
    };
private:
    int m_num;
};

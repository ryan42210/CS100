#include<iostream>
#include<vector>

class base {
public:
    base(std::pair<int,int> a) {
        m_data.push_back(a);
    };
    base(std::pair<int,int> a,int number) {
        for (int i = 0; i < number; i++) {
            m_data.push_back(a);
        }
    };
    ~base() {};
    int getsize() {
        return m_data.size();
    };
    void printSet() {
        std::cout << '{';
        for(int i = 0; i < m_data.size(); i++) {
            std::cout << m_data[i];
            if(i != m_data.size() - 1)
                std::cout << ", ";
        }
        std::cout << '}' << '\n';
    };
private:
    std::vector<std::pair<int,int>> m_data;
};

int main() {
    std::pair<int,int> a;
    a.first()= 1;
    a.second()= 2;
    base a(5,4);
    base c(1,4);
    a.printSet();
    return 0;
}
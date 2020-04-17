#include <iostream>
#include <fstream>

int main() {
    std::fstream fstr;
    fstr.open("./src/in.txt");
    int row, col;
    fstr >> row >> col;
    std::cout << row <<'\n'<< col <<std::endl;
    return 0;
}
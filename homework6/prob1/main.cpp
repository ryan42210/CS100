#include"customset.h"

int main() {
    string a[3] = {"hello", "aljd", "sjd"};
    string e[2] = {"hello", "aa"};
    CustomSet<string> sample1(a, 3);
    CustomSet<string> sample6(e, 2);
    CustomSet<string> sample5;
    int b[5] = {4, 4, 10, -2, 0};
    CustomSet<int> sample2(b, 5);
    double c[5] = {3.4, 2.2, 10.4, -2.19, 0.98};
    CustomSet<double> sample3(c, 5);
    CustomSet<pair<int,int>> sample4;
    sample1.add("test");
    sample1 -= "test";
    sample1.printSet();
    //sample1 -= sample6;
    //sample1.printSet();
    sample5 = sample1 - sample6;
    sample5.printSet();
    return 0;
}
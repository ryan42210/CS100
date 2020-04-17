#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int g_sortOption;


class ReportParser {
public:
    ReportParser(int numStudents, int numInfos);
    ~ReportParser();
    void readReport();
    void writeStructuredReport(int sortOption);
    void printLevelLine();
    void printTextLine(int lineIndex);
    void printUporDown(int judg);
    int calMaxWidthOfCol(int colNum);
    void infoSort(int sortOption);
    //bool compareString(vector<string> v1, vector<string> v2);
    // Add your own functions and variables here
private:
    // Add your own functions and variables here
    vector<vector<string>> mvv_student;
    vector<int> mv_maxWidthOfCol;
    int m_numStudents;
    int m_numInfos;
};

ReportParser::ReportParser(int numStudents, int numInfos) {
    // Your code here
    m_numStudents = numStudents;
    m_numInfos = numInfos;
}

ReportParser::~ReportParser() {
    // Your code here
}


void ReportParser::readReport(){
    // Your code here
    vector<string> entry;
    string info;
    for (int j = 0; j != m_numStudents; ++j) {
        mvv_student.push_back(entry);
        for (int i = 0; i != m_numInfos; ++i) {
            std::cin >> info;
            mvv_student[j].push_back(info);
        }
    }
}

void ReportParser::writeStructuredReport(int sortOption) {
    // Your code here
    infoSort(sortOption);
    for (int i = 0; i < m_numInfos; ++i) {
        mv_maxWidthOfCol.push_back(calMaxWidthOfCol(i));
    }
    printUporDown(1);
    for (int i = 0; i < m_numStudents; ++i) {
        printTextLine(i);
        if (i != m_numStudents - 1)
            printLevelLine();
    }
    printUporDown(0);

}

void ReportParser::printTextLine(int lineIndex) {
    std::cout << '|';
    for (int i = 0; i < m_numInfos; ++i) {
        //pritnt data and add enough space
        std::cout << ' ';
        std::cout << mvv_student[lineIndex][i];
        int space = mv_maxWidthOfCol[i] - mvv_student[lineIndex][i].size() - 1;
        for (int j = 0; j < space; ++j) std::cout << ' ';
        std::cout << '|';
    }
    std::cout << std::endl;
}

void ReportParser::printUporDown(int judg) {
    //juge == 1 means we want to print upper line.
    if (judg == 1) std::cout << '/';
    else std::cout << '\\';

    for (int i = 0; i < m_numInfos; ++i) {
        for (int j = 0; j < mv_maxWidthOfCol[i]; ++j) {
            std::cout << '-';
        }
        if (i != m_numInfos - 1) std::cout << '-';
    }
    if (judg == 1) std::cout << '\\';
    else std::cout << '/';
    std::cout << std::endl;
}


void ReportParser::printLevelLine(){
    std::cout << '|';
    for (int i = 0; i < m_numInfos; ++i) {
        for (int j = 0; j < mv_maxWidthOfCol[i]; ++j) {
            std::cout << '-';
        }
        std::cout << '|';
    }
    std::cout << std::endl;
}

int ReportParser::calMaxWidthOfCol(int colIndex) {
    int maxWidth = 0;
    for (int i = 0; i < m_numStudents; ++i) {
        if (maxWidth < mvv_student[i][colIndex].size())
            maxWidth = mvv_student[i][colIndex].size();
    }
    return maxWidth + 2;
}

bool compareString(vector<string> v1, vector<string> v2) {
    return (v1[g_sortOption] < v2[g_sortOption]);
}

void ReportParser::infoSort(int sortOption) {
    g_sortOption = sortOption;
    std::sort(mvv_student.begin(), mvv_student.end(),compareString);
}




//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main() {
    int m, n, sortOption;
    std::cin >> m >> n >> sortOption;
    getchar();
    ReportParser p(n, m);
    p.readReport();
    p.writeStructuredReport(sortOption);
    return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//--------------------------class declarations---------------------------------//
class LookupTable {
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment);
    // virtual destructor
    virtual ~LookupTable() = 0;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
protected:
    double m_start;
    double m_end;
    double m_dx;
    int m_number;
    vector<pair<double, double>> mv_data;
};
//---------------------------------------------------------------------------//
class SquareLookupTable : public LookupTable {
public:
    SquareLookupTable(double start, double end, double increment);
    virtual ~SquareLookupTable();
    virtual double getValue(double x);
};
//--------------------------------------------------------------------------//
class SinLookupTable : public LookupTable {
public:
    SinLookupTable(double start, double end, double increment);
    virtual ~SinLookupTable();
    virtual double getValue(double x);
};
//--------------------------------------------------------------------------//
class LogLookupTable : public LookupTable {
public:
    LogLookupTable(double start, double end, double increment);
    virtual ~LogLookupTable();
    virtual double getValue(double x);
};

//-------------------function definitions----------------------------------//
LookupTable::LookupTable(double start, double end, double increment) {
    m_start = start;
    m_end = end;
    m_dx = increment;
    m_number = round((end - start)/increment) + 1;
    pair<double, double> temp;
    for (int i = 0; i < m_number; ++i) {
        temp.first = m_start + i * m_dx;
        temp.second = 0.0;
        mv_data.push_back(temp);
    }
}

LookupTable::~LookupTable(){
}
//--------------------------------------------------------------------------//
SquareLookupTable::SquareLookupTable(double start, double end, double increment):
LookupTable(start,end,increment) {
    for (int i = 0; i < m_number; ++i) {
        mv_data[i].second = (mv_data[i].first) * (mv_data[i].first);
    }
}
SquareLookupTable::~SquareLookupTable() {
    //
}
double SquareLookupTable::getValue(double x){
    for (int i = 0; i < m_number; ++i) {
        if (x == mv_data[i].first)
            return mv_data[i].second;
        else if (x < mv_data[i].first) {
            return ((x - mv_data[i-1].first) * mv_data[i].second + (mv_data[i].first - x) * mv_data[i-1].second)/m_dx;
        }
    }
    return 0;
}
//----------------------------------------------------------------------------//
SinLookupTable::SinLookupTable(double start, double end, double increment):
LookupTable(start,end,increment) {
    for (int i = 0; i < m_number; ++i) {
        mv_data[i].second = sin(mv_data[i].first);
    }
}
SinLookupTable::~SinLookupTable() {
    //
}
double SinLookupTable::getValue(double x){
    for (int i = 0; i < m_number; ++i) {
        if (x == mv_data[i].first)
            return mv_data[i].second;
        else if (x < mv_data[i].first) {
            return ((x - mv_data[i-1].first) * mv_data[i].second + (mv_data[i].first - x) * mv_data[i-1].second)/m_dx;
        }
    }
    return 0;
}
//----------------------------------------------------------------------------//
LogLookupTable::LogLookupTable(double start, double end, double increment):
LookupTable(start,end,increment) {
    for (int i = 0; i < m_number; ++i) {
        mv_data[i].second = log(mv_data[i].first);
    }
}
LogLookupTable::~LogLookupTable() {
    //
}
double LogLookupTable::getValue(double x){
    for (int i = 0; i < m_number; ++i) {
        if (x == mv_data[i].first)
            return mv_data[i].second;
        else if (x < mv_data[i].first) {
            return ((x - mv_data[i-1].first) * mv_data[i].second + (mv_data[i].first - x) * mv_data[i-1].second)/m_dx;
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
#include<iomanip>
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    LookupTable* cal = new SquareLookupTable(a,b,c);
    double x = 9.392283;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> x;
        cout << fixed << setprecision(8) << cal->getValue(x) << endl;
    }
    delete cal;
    return 0;
}


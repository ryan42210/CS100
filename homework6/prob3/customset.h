#ifndef _CUSTOMSET_H_
#define _CUSTOMSET_H_

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template <typename T>
class CustomSet {
public:
	CustomSet() {};

	CustomSet(const CustomSet& other) {
        m_data = other.m_data;
    };

	CustomSet(T arr[], int size) {
        for(int i = 0; i < size; i++) {
            if (find(arr[i]) == nullptr) {
                m_data.push_back(arr[i]);
            }
        }
    };

	~CustomSet() {};

	const int size() const {
        return m_data.size();
    };

	bool add(const T& item) {
        if(find(item) == nullptr) {
            m_data.push_back(item);
            return true;
        } else return false;
    };

	T* find(const T& item) {
        for(int i = 0; i < m_data.size(); i++) {
            if(*(m_data.begin() + i) == item)				//very!!important!!
                return &*(m_data.begin() + i);
        }
        return nullptr;
    };

	bool erase(const T& item) {
        for(int i = 0; i < m_data.size(); ++i) {
            if(m_data[i] == item) {
                m_data.erase(m_data.begin() + i);
                return true;
            }
        }
        return false;
    };

	CustomSet intersection(const CustomSet& other) {
		CustomSet<T> intersection;
		for(int i = 0; i < this->m_data.size(); i++) {
			for(int j = 0; j < other.m_data.size(); j++) {
            	if(this->m_data[i] == other.m_data[j])
                	intersection += other.m_data[j];
        	}
		}
		return intersection;
    };

	void sortSet() {
        std::sort(m_data.begin(), m_data.end());
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

// Operators:
	// The operator+ and operator += are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "plus" an item means adding in the item.
	CustomSet operator+ (const T& item) {
        CustomSet copy(*this);
		copy.add(item);
        return copy;
    };
	// A set "plus" a set means taking the union of two sets.
	CustomSet operator+ (const CustomSet& that) {
        CustomSet newset(that);
		for(int i = 0; i < this->m_data.size(); i++) {
        	for(int j = 0; j < that.m_data.size(); j++) {
				if(this->m_data[i] == that.m_data[j]) break;
				newset.add(this->m_data[i]);
			}
		}
		return newset;
    };
	// However, the difference between + and += is not written here.
	CustomSet& operator+= (const T& item) {
		this->add(item);
        return *this;
	};
	CustomSet& operator+= (const CustomSet& that) {
		int tempsize = this->m_data.size();
        for(int j = 0; j < that.m_data.size(); j++) {
			for(int i = 0; i < tempsize; i++) {
				if(this->m_data[i] == that.m_data[j]) break;
				this->add(that.m_data[j]);
			}
		}
		return *this;
	};

	CustomSet operator- (const T& item) {
        CustomSet copy(*this);
		bool success = copy.erase(item);
		if (success == true) return copy;
	};
	CustomSet operator- (const CustomSet& that) {
		CustomSet copy(*this);
		for(int i = 0; i < that.m_data.size(); i++) {
			copy.erase(that.m_data[i]);
		}
		return copy;
	};
	CustomSet& operator-= (const T& item) {
		erase(item);
		return *this;
	};
	CustomSet& operator-= (const CustomSet& that) {
		for(int i = 0; i < that.m_data.size(); i++) {
			this->erase(that.m_data[i]);
		}
		return *this;
	};


	CustomSet<pair<T, T>> operator* (const CustomSet& that) {
		CustomSet<pair<T, T>> copy;
		for(int i = 0; i < this->m_data.size(); i++) {
        	for(int j = 0; j < that.m_data.size(); j++) {
				pair<T,T> temp;
				temp.first = this->m_data[i];
				temp.second = that.m_data[j];
				copy.add(temp);
			}
		}
		return copy;
	};

	const T getMax() {
		return *max_element(m_data.begin(), m_data.end() );
	};

private:
    vector<T> m_data;
};

#endif
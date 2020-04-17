#ifndef _CUSTOMSET_HPP_
#define _CUSTOMSET_HPP_

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
// Constructors and destructor:
	// Default constructor
	CustomSet() {};

	// Copy constructor. Should construct a copy of "other".
	CustomSet(const CustomSet& other) {
        m_data = other.m_data;
    };

	// Constructor using an array.
	// Note that if there are duplicates in the array, you should ignore them.
	CustomSet(T arr[], int size) {
        for(int i = 0; i < size; i++) {
            if (find(arr[i]) == nullptr) {
                m_data.push_back(arr[i]);
            }
        }
    };

	// Destructor. Pay attention to memory leaks!
	~CustomSet() {};

// Other member functions:
	// Returns the size of the set.
	int size() const {
        return m_data.size();
    };

	// If "item" is already in the set, return false.
	// Otherwise, add it to the set and return true.
	bool add(const T& item) {
        if(find(item) == nullptr) {
            m_data.push_back(item);
            return true;
        } else
            return false;
    };

	// If an object in the set equals "item", return a pointer to it.
	// If "item" is not found, return nullptr(NULL).
	T* find(const T& item) {
        for(int i = 0; i < m_data.size(); i++) {
            if(item == m_data[i])
                return &*(m_data.begin() + i);
        }
        return nullptr;
    };

	// If "item" is not in the set, return false.
	// Otherwise, erase it from the set and return true.
	bool erase(const T& item) {
        for(int i = 0; i < m_data.size(); ++i) {
            if(m_data[i] == item) {
                m_data.erase(m_data.begin() + i);
                return true;
            }
        }
        return false;
    };

	// This function returns the intersection of two sets (*this and other).
	// In other words, the set of all objects that is in both *this and other.
	// If there is no intersection, just return an empty set.
	CustomSet intersection(const CustomSet& other) {
		CustomSet intersection;
		for(int i = 0; i < this->m_data.size(); i++) {
			for(int j = 0; j < other.m_data.size(); j++) {
            	if(this->m_data[i] == other.m_data[j])
                	intersection.m_data.push_back(other.m_data[j]);
        	}
		}
		return intersection;
    };

	// This function sorts the objects in the set in ascending order.
	void sortSet() {
        std::sort(m_data.begin(), m_data.end());
    };

	// This function prints the set, seperating elements by { , , , }.
	// It's safe to assume that it supports operator<< of ostream (cout).
	// For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
	// This function will print: "{2, 4, -2, 800}\n"
	// Note that there are spaces between a comma(,) and the next object.
	// Print a newline at the end. (indicated by the '\n' above)
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
		copy.m_data.push_back(item);
        return copy;
    };
	// A set "plus" a set means taking the union of two sets.
	CustomSet operator+ (const CustomSet& that) {
        CustomSet newset(this);
		for(int i = 0; i < this->m_data.size(); i++) {
        	for(int j = 0; j < that.m_data.size(); j++) {
				if(this->m_data[i] == that.m_data[j]) break;
				newset.m_data.push_back(this->m_data[i]);
			}
		}
		return newset;
    };
	// However, the difference between + and += is not written here.
	CustomSet& operator+= (const T& item) {
		m_data.push_back(item);
        return *this;
	};
	CustomSet& operator+= (const CustomSet& that) {
		int tempsize = this->m_data.size();
		for(int i = 0; i < tempsize; i++) {
        	for(int j = 0; j < that.m_data.size(); j++) {
				if(this->m_data[i] == that.m_data[j]) break;
				this->m_data.push_back(that.m_data[j]);
			}
		}
		return *this;
	};

	// The operator- and operator -= are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "minus" an item means erasing the item.
	CustomSet operator- (const T& item) {
        CustomSet copy(this);
		bool success = copy.erase(item);
		if (success == true) return copy;
	};
	// A set A "minus" a set B means subtracting B from A, or namely, A\B.
	CustomSet operator- (const CustomSet& that) {
		CustomSet copy;
		for(int i = 0; i < that.m_data.size(); i++) {
			copy.erase(that.m_data[i]);
		}
		return copy;
	};
	// However, the difference between - and -= is not written here.
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
				temp.first() = this->m_data[i];
				temp.second() = that.m_data[j];
				copy.m_data.push_back(temp);
			}
		}
		return copy;
	};
	// This function returns the Cartesian product of two sets (*this and that).
	// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
	//		The first element of the ordered pair belongs to first set (*this);
	//		The second element of the ordered pair belongs the second set (that).
	// The (std::)pair (in header <utility>) helps representing the object in it.
	// If you have any question with Cartesian products or std::pair, just look up on Internet!

	T getMax() {
		return *max_element(m_data.begin(), m_data.end() );
	};
private:
    vector<T> m_data;
};


#endif
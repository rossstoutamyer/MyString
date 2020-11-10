// my_string.cpp
#include <iostream>
#include "my_string.h"
#include "my_sstream.h"

// TODO(student): define all necessary my_string methods
// NOTE: some methods suggested here may not be required for you.
//       if you don't need a method, then you are not required to implement it
// NOTE: some methods not suggested here may be required for you.
//       if you need a method, then you are required to implement it (or re-engineer your solution to no longer need the method).

// my_string methods

// constructors
//   default (done for you.  you're welcome.)
my_string::my_string() : _data(new char[1]{0}), _capacity(1), _size(0) {
}
//   rule of "3"
//     my_string copy constructor
my_string::my_string(const my_string& other) {
	my_string* newString = new my_string;
	*newString._data = *(other._data);
	newString._capacity = (other._capacity);
	newString._size = (other._size);
}
//     my_string copy assignment
my_string::my_string& operator=(const my_string& rhs) {
	size = rhs.size();
	_data = new char[size];
	for (size_t i = 0; i < size; ++i) {
		_data[i] = rhs._data[i];
	}
	return *this;
}
//     destructor
my_string::~my_string() {
	
}
//   c-string copy constructor
my_string::my_string(const char* other) {
	my_string* newString = new my_string;
	*newString._data = *other;
}

// element access
const char& operator[](size_type index) const {
	return char[index];
}
char& operator[](size_type index) {
	return char[index];
}
//   at
//   front
//   operator[]

// capacity
//   empty
//   size
size_type size() const;

// operations
//   concatenation
//     my_string + my_string (non-member, friend)
my_string operator+(my_string lhs, const my_string& rhs) {
	my_string totalString;
	totalString._size = lhs.size() + rhs.size();
	totalString._capacity = lhs.capacity() + rhs.capacity();
	totalString._data = new char[totalString.size()];
	
	for (size_t i = 0; i < lhs.size(); ++i) {
		totalString._data[i] = lhs._data[i];
	}
	for (size_t j = lhs.size(); j < lhs.size() + rhs.size(); ++j) {
		totalString._data[j] = rhs._data[j];
	}
	delete [] lhs._data;
	delete [] rhs._data;
	
	return totalString;
}
//     my_string + c-string (non-member, friend)
my_string operator+(my_string lhs, const char* rhs) {
	my_string totalString;
	totalString._size = lhs.size() + sizeof(rhs);
	totalString._capacity = lhs.capacity() + sizeof(rhs);
	totalString._data = new char[totalString.size()];
	
	for (size_t i = 0; i < lhs.size(); ++i) {
		totalString._data[i] = lhs._data[i];
	}
	for (size_t j = lhs.size(); j < lhs.size() + sizeof(rhs)); ++j) {
		totalString._data[j] = rhs[j];
	}
	delete [] lhs._data;
	//NOT SURE
	
	return totalString;
}
//     my_string + char (non-member, friend)
my_string operator+(my_string lhs, char rhs) {
	my_string totalString;
	totalString._size = lhs.size() + 1;
	totalString._capacity = lhs.capacity() + 1;
	totalString._data = new char[totalString.size()];
	
	for (size_t i = 0; i < lhs.size(); ++i) {
		totalString._data[i] = lhs._data[i];
	}
	
	totalString._data[totalString.size() - 1] = rhs;
	delete [] lhs._data;
	
	return totalString;
}
//     c-string + my_string (non-member, friend)
my_string operator+(const char* lhs, const my_string& rhs) {
	my_string totalString;
	totalString._size = rhs.size() + sizeof(lhs);
	totalString._capacity = rhs.capacity() + sizeof(lhs);
	totalString._data = new char[totalString.size()];
	
	for (size_t i = 0; i < sizeof(lhs); ++i) {
		totalString._data[i] = lhs[i];
	}
	for (size_t j = sizeof(lhs); j < sizeof(lhs) + rhs.size()); ++j) {
		totalString._data[j] = rhs._data[j];
	}
	delete [] rhs._data;
	//NOT SURE
	
	return totalString;
}
//     char + my_string (non-member, friend)
my_string operator+(char lhs, my_string rhs) {
	my_string totalString;
	totalString._size = rhs.size() + 1;
	totalString._capacity = rhs.capacity() + 1;
	totalString._data = new char[totalString.size()];
	
	totalString._data[0] = lhs;
	for (size_t i = 1; i < rhs.size() + 1; ++i) {
		totalString._data[i] = rhs._data[i];
	}
	
	totalString._data[totalString.size() - 1] = rhs;
	delete [] rhs._data;
	
	return totalString;
}
//     my_string += my_string
my_string& operator+=(const my_string& rhs);
//     my_string += c-string
my_string& operator+=(const char* rhs);
//     my_string += char
my_string& operator+=(char rhs);

// search
my_string& erase(size_type index1, size_type index2) {######################
	
	
	for (size_t i = index1; i < index2; ++i) {
		
	}
	
	return *this;
}

// non-member functions
//   relational operators
//     my_string == my_string
bool operator==(const my_string& lhs, const my_string& rhs) {
	if (lhs.size() > rhs.size()) {
		return false;
	} else if (rhs.size() > lhs.size()) {
		return false;
	} else {
		for (size_t i = 0; i < rhs.size(); ++i) {
			if (lhs[i] != rhs[i]) {
				return false;
			}
		}
		return true;
	}
}
//     my_string == c-string
bool operator==(const my_string& lhs, const char* rhs);
bool operator!=(const my_string& lhs, const my_string& rhs);
bool operator!=(const my_string& lhs, const char* rhs);

//   stream operators
//     ostream instertion operator
std::ostream& operator<<(std::ostream& os, const my_string& str) {
	for (size_t i = 0; i < str.size(); ++i) {
		os << str[i];
	}
	
	return os;
}
//     istream extraction operator
std::istream& operator>>(std::istream& os, my_string& str) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] != ' ') {
			os >> str[i];
		} else {
			break;
		}
		
	}
	
	return os;
}
//     getline
std::istream& getline(std::istream& is, my_string& str, char delim='\n');

//   numeric conversions
//     to_string


// my_istringstream methods

/* my_istringstream::my_istringstream(const my_string& str) : _str(str), idx(0), state_fail(false), state_eof(str.empty()) {}

void my_istringstream::eat_whitespaces() {
    while (idx < _str.size() && isspace(_str[idx])) {
        idx++;
    }
}

my_istringstream& my_istringstream::operator>>(my_string& str) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    my_string s;
    while (idx < _str.size() && !isspace(_str[idx])) {
        s += _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    str = s;
    return *this;
}

my_istringstream& my_istringstream::operator>>(char& c) {
    eat_whitespaces();
    if (eof()) {
        state_fail = true;
    }
    if (fail()) {
        return *this;
    }
    if (idx < _str.size()) {
        c = _str[idx++];
    }
    if (idx == _str.size()) {
        state_eof = true;
    }
    return *this;
}

bool my_istringstream::good() const { return !(state_fail || state_eof); }
bool my_istringstream::fail() const { return state_fail; }
bool my_istringstream::eof() const { return state_eof; } */

// TODO(student): define other my_istringstream methods, if any

#include "IntVector.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

IntVector::IntVector(unsigned capacity, int value) 
    : _size(capacity), _capacity(capacity), _data(nullptr) {
    if (_capacity > 0) {
        _data = new int[_capacity];
        fill(_data, _data + _size, value);
    }
}

IntVector::~IntVector() {
    delete[] _data;
}

// --- Accessors ---
unsigned IntVector::size() const { return _size; }
unsigned IntVector::capacity() const { return _capacity; }
bool IntVector::empty() const { return _size == 0; }

const int & IntVector::at(unsigned index) const {
    if (index >= _size) throw out_of_range("IntVector::at_range_check");
    return _data[index];
}

int & IntVector::at(unsigned index) {
    if (index >= _size) throw out_of_range("IntVector::at_range_check");
    return _data[index];
}

const int & IntVector::front() const { return _data[0]; }
int & IntVector::front() { return _data[0]; }

const int & IntVector::back() const { return _data[_size - 1]; }
int & IntVector::back() { return _data[_size - 1]; }

// --- Mutators ---

// Matches: void expand()
// Standard doubling logic for amortized O(1) push_back
void IntVector::expand() {
    unsigned newCap = (_capacity == 0) ? 1 : _capacity * 2;
    
    int* newArray = new int[newCap];
    for(unsigned i = 0; i < _size; ++i) {
        newArray[i] = _data[i];
    }
    
    delete[] _data;
    _data = newArray;
    _capacity = newCap;
}

// Matches: void expand(unsigned amount)
// Increases capacity by a specific amount
void IntVector::expand(unsigned amount) {
    unsigned newCap = _capacity + amount;
    int* newArray = new int[newCap];
    
    for(unsigned i = 0; i < _size; ++i) {
        newArray[i] = _data[i];
    }
    
    delete[] _data;
    _data = newArray;
    _capacity = newCap;
}

void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        // Calculate exactly how much more we need to reach 'n'
        expand(n - _capacity); 
    }
}

void IntVector::push_back(int value) {
    if (_size == _capacity) {
        expand();
    }
    _data[_size++] = value;
}

void IntVector::insert(unsigned index, int value) {
    if (index > _size) throw out_of_range("IntVector::insert_range_check");
    if (_size == _capacity) expand();

    for (unsigned i = _size; i > index; --i) {
        _data[i] = _data[i - 1];
    }
    _data[index] = value;
    _size++;
}

void IntVector::erase(unsigned index) {
    if (index >= _size) throw out_of_range("IntVector::erase_range_check");
    for (unsigned i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }
    _size--;
}

void IntVector::resize(unsigned size, int value) {
    if (size > _capacity) {
        // If doubling isn't enough to reach the new size, expand by exact amount
        if (size > _capacity * 2) {
            expand(size - _capacity);
        } else {
            expand();
        }
    }
    
    if (size > _size) {
        fill(_data + _size, _data + size, value);
    }
    _size = size;
}

void IntVector::assign(unsigned n, int value) {
    if (n > _capacity) {
        if (n > _capacity * 2) {
            expand(n - _capacity);
        } else {
            expand();
        }
    }
    _size = n;
    fill(_data, _data + _size, value);
}

void IntVector::pop_back() { _size--; }
void IntVector::clear() { _size = 0; }

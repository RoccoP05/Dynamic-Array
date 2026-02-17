#include<iostream>
#include "IntVector.h"
using namespace std;

//Default testing cases
int main(){
    cout << "---Testing Default Constructor---" << endl;
    IntVector v1;
    cout << "v1 size: " << v1.size() << " v1 capacity: " << v1.capacity() << endl; 

    cout << "\n---Testing Constructor With Arguments---" << endl;
    IntVector v2(5,20);
    cout << "Input: v2(5,20)\n" << "v2 size: " << v2.size() << " v2 capacity: " << v2.capacity() << endl; 

    cout << "\n---Testing at(), front(), back()---" << endl;
    cout << "v2 front: " << v2.front() << " (expected 20)\n" 
    << "v2 back: " << v2.back() << " (expected 20)\n"
    << "v2 at(3): " << v2.at(3)  << " (expected 20)\n"<< endl; 

    cout << "\n---Testing insert()---" << endl;
    cout << "v2 before insert: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << v1.size() << v1.capacity();
    cout << endl;
    cout << "Inserting v2.(0,5)\n";
    cout << "v2 after insert: ";
    v2.insert(0,5);
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << "\nv2 new capacity: " << v2.capacity() << endl;

    cout << "\n---Testing erase()---" << endl;
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;
    cout << "v2.erase(3)" << endl;
    v2.erase(3);
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;

    cout << "\n---Testing push_back()---" << endl;
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;
    cout << "v2.push_back(12)" << endl;
    v2.push_back(12);
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;

    cout << "\n---Testing pop_back()---" << endl;
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;
    cout << "v2.pop_back()" << endl;
    v2.pop_back();
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;

    cout << "\n---Testing resize()---" << endl;
    cout << "resize(10)\n";
    cout << "v2: ";
    v2.resize(10);
    for(unsigned i = 0; i < v2.size(); i++){
    cout << v2.at(i) << " ";
    }
    cout << "\nv1: ";
    v1.resize(10);
    for(unsigned i = 0; i < v1.size(); i++){
    cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "\n---Testing reserve()---" << endl;
    cout << "v2 capacity: " << v2.capacity() << endl;
    cout << "reserve(15)" << endl;
    v2.reserve(15);
    cout << "v2 capacity: " << v2.capacity() << endl;

    cout << "\n---Testing assign()---" << endl;
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;
    cout << "v2.assign(10,8)" << endl;
    v2.assign(10,8);
    cout << "v2: ";
    for(unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;

    cout << "\n---Testing clear()---" << endl;
    cout << "v2 size: " << v2.size() << endl; 
    v2.clear();
    cout << "v2 size: " << v2.size() << endl; 
        
    cout << "\n---All Basic Tests Passed---" << endl;
    
    return 0;
}

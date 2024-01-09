// Program that implements BeanCounter.hpp
// Nadir Mustafa, 12/08/2023, CSCI 1113, Programming assignment 6.

#include <iostream>
#include "BeanCounter.hpp"
using namespace std;


// explicit value constructor
BeanCounter::BeanCounter(int n){ 
  length = n;
  counter = new int[length];
  for(int i = 0; i < length; i++){
    counter[i] = 0;
    }
}

// deafult constructor, sets length to 2
BeanCounter::BeanCounter(){ 
  length = 2;
  counter = new int[length];
  for(int i = 0; i < length; i++){
    counter[i] = 0;
  }
}

// destructor, sets counter to nullptr to prevent any errors
BeanCounter::~BeanCounter(){ 
  // destructor
  delete[] counter;
  counter = nullptr;
}

// add one to counter index i, if i is a legal index
void BeanCounter::tick(int i){ 
  if(i >= 0 && i < length){
    counter[i] += 1;
  }
}

void BeanCounter::maxReset(){
  int largest_val = counter[0]; // set largest_val to first index of counter
  for(int i = 0; i < length; i++){
    if(counter[i] > largest_val){ // iterate over array, largest value in array put into largest_val
        largest_val = counter[i];
    }
  }
  for(int i = 0; i < length; i++){ 
    if(counter[i] != largest_val){ // set all indicies != largest_val to 0
        counter[i] = 0;
    }
  }

}

// setter to set the array counter
void BeanCounter::setCounter(int* new_counter){
    for(int i = 0; i < length; i++){
        counter[i] = new_counter[i];
    }
}

// copy constructor, code from professor's example
BeanCounter::BeanCounter(const BeanCounter &b){ 
  this->length = b.length;
  this->counter = new int[this->length];
  for(int i = 0; i < length; i++){
    this->counter[i] = b.counter[i];
  }
}

// overload assignment operator, code from professor's example
BeanCounter &BeanCounter::operator=(const BeanCounter &b){ 
  if(this != &b){
    this->~BeanCounter();

    this->length = b.length;

    this->counter = new int[length];

    for(int i = 0; i < b.length; i++){
      this->counter[i] = b.counter[i];
    }
  }
  return *this;
}

// outputs a BeanCounter Object's counter array
ostream &operator<<(ostream &out, const BeanCounter &b){
    out << "<";
    for(int i = 0; i < b.getLength()-1; i++){
        out << b.getCounter()[i] << ", ";
    }
    out << b.getCounter()[b.getLength()-1] << ">";
    return out;
}

// adds two BeanCounter object counter arrays
// finds the one with the largest length, creates new array using that length
// then adds the two objects together into the new array
// makes new BeanCounter object and calls setCounter and sets it as *new_total
// returns the new BeanCounter Object
BeanCounter operator+(const BeanCounter &first, const BeanCounter &second){
    int largest_length = 0;
    if(first.getLength() > second.getLength()){
        largest_length = first.getLength();
    }
    else{
        largest_length = second.getLength();
    }
    int *new_total = new int[largest_length];

    for(int i = 0; i < largest_length; i++){
        new_total[i] = first.getCounter()[i] + second.getCounter()[i];
    }
    BeanCounter new_beanCounter(largest_length);
    new_beanCounter.setCounter(new_total);
    return new_beanCounter;
}
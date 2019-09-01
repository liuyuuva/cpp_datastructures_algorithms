#include "array.h"
#include <iostream>
using namespace std;


Array::Array(int capacity) {
  if (capacity < 1) {
    std::cout << "Failed to initiate array: invalid capacity. " << std::endl;
    exit(1);
  }

  if (capacity <= kMinCapacity) {
    p_data_ = new int[kMinCapacity];
    cout << "An array of "<< kMinCapacity << " is established"<< endl;
    capacity_ = kMinCapacity;
    size_ = 0;
  }
  else
  {
    int current_capacity = kMinCapacity * kCapacityIncFactor;
    while (current_capacity < capacity) {
      current_capacity = current_capacity * kCapacityIncFactor;
    }
    p_data_ = new int[current_capacity];
    cout << "An array of " << current_capacity << " is established." << endl;
    capacity_ = current_capacity;
    size_ = 0;
  }
  
}

Array::Array(const Array& other){
  delete[] p_data_;

  capacity_ = other.capacity_;
  size_ = other.size_;

  if (other.p_data_){
    p_data_ = other.p_data_;
    // p_data_ = new int[capacity_];
    // for (int i = 0; i < other.size_; i++){
    //   *(p_data_ + i) = *(other.p_data_ + i);
    //}
  }
  else{
    p_data_ = nullptr;
  }
}

Array::~Array(){
  delete[] p_data_;
  cout << "Array destroyed." <<endl;
}


void Array::Push(int value){
  if (size_ < capacity_){
    *(p_data_ + size_) = value;
    ++size_;
  } else {
    this->SizeUp();
    *(p_data_ + size_) = value;
    ++size_;
  }
}



int& Array::operator[] (int index) const {
  if (index > size_) {
    cout<<"Index out of range! "<<endl;
    exit(1);
  }
  else{
    return *(this->p_data_+index);
  }
}

int Array::GetSize() const{
  return size_;
}

ostream& operator<<(ostream& out, const Array& array) {
  for (int i=0; i < array.GetSize(); ++i){
    out << array[i] << " ";
  }
  return out;
}

int Array::GetCapacity() const{
  return capacity_;
}

bool Array::IsEmpty() const{
  return size_ == 0;
}

int Array::ValueAtIndex(int index) const{
  
   if (index > size_){
     cout << "Index out of range!" << endl;
     exit(1);
    }
    else{
      return *(p_data_+index);
    }
  
}

int Array::Pop(){
  if (size_ == 0){
    cout << "Cannot pop: array is empty." << endl;
    exit(1);
  }
   
  if ((size_ <= ( capacity_ / kCapacityIncFactor - kCapacityModMargin))
           && (capacity_ > kMinCapacity)){
    this->SizeDown();
  }

  int index = size_;
  size_--;
  return *(p_data_ + index);
  
}

void Array::SizeUp(){
  int new_capacity;

  new_capacity = capacity_ * kCapacityIncFactor;

  int* new_p_data = new int[new_capacity];

  for(int i = 0; i < size_; ++i){
    *(new_p_data+i) = *(p_data_ + i);
  }

  delete[] p_data_;
  p_data_ = new_p_data;
  capacity_ = new_capacity;
}


void Array::SizeDown(){
  int new_capacity;
  if (capacity_ > kMinCapacity){
    new_capacity = capacity_ / kCapacityIncFactor;
    }
  else{
    cout << "Cannot downsize: already in minimum capacity." << endl;
    return;
  }
  cout << "Downsizing the array." << endl;
  int* new_p_data = new int[new_capacity];
    
  for(int i = 0; i< size_; ++i){
    *(new_p_data+i) = *(p_data_+i);
  }

  delete[] p_data_;
  p_data_ = new_p_data;
  capacity_ = new_capacity;
}

void Array::Insert(int index, int value) {
  if (size_ == capacity_){
    this->SizeUp();
  }
  for(int i = size_-1; i >= index; --i){
    *(p_data_ + i + 1) = *(p_data_ + i);
  }
  *(p_data_ + index) = value;
  ++size_;
}

void Array::Delete(int index){
  if (index > size_|| this->IsEmpty()){
    cout << "Cannot delete: invalid index or empty array." << endl;
    exit(1);
  }

  for (int i = index; i < size_; ++i){
    *(p_data_ + i ) = *(p_data_ + i + 1);
  }
  --size_;
  if ((size_ <= ( capacity_ / kCapacityIncFactor - kCapacityModMargin))
           && (capacity_ > kMinCapacity)){
    this->SizeDown();
  }
}

int Array::Find(int value) const{
  for(int index = 0; index < size_; index++){
    if (*(p_data_ + index) == value)
    {
      return index;
    }
  }

  return -1;
}


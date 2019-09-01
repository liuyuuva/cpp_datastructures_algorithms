#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

constexpr int kMinCapacity = 16;
constexpr int kCapacityIncFactor = 2;
constexpr int kCapacityModMargin= 4;
//This margin is added to prevent frequent decrease and increase


//template <class T>
class Array {
 private:
  int* p_data_ = nullptr;
  int capacity_;
  int size_ = 0;
  
  
 public:
  Array(int capacity);
  Array(const Array& other);
   ~Array();
  
  int GetSize() const;
  int GetCapacity() const;
  bool IsEmpty() const;
  int ValueAtIndex(int index) const;
  void Push(int value);
  void Insert(int index, int value);
  int Pop();
  void Delete(int index);
  int Find(int value) const;
  void SizeUp();
  void SizeDown();



  friend ostream& operator<<(ostream&, const Array&);
  int& operator[](int index) const;
};
	
	

#endif

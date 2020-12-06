#include "linked_list.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  LinkedList list;
  cout << list.GetSize() <<endl;
  cout << "List is empty: "<< list.IsEmpty() << endl;

  list.PushFront(1);
  //list.GetSize();
  cout << list << endl;
  cout << list.GetSize() << endl;

  list.PushFront(2);
  cout << list << endl;
  cout << list.GetSize() << endl;
  cout << "List is empty: "<< list.IsEmpty() << endl;

  
  cout << "Value at 1 is : "<< list.ValueAt(1) << endl;
  cout<< "Value at 2 is : " << list.ValueAt(2) << endl;
  

  cout << "Value at 1 from end is: " << list.ValueNFromEnd(1) << endl;
  cout << "Value at 2 from end is: " << list.ValueNFromEnd(2) << endl;

  list.PushBack(3);
  list.PushBack(5);
  list.PushBack(7);
  list.PushBack(9);
  list.PushBack(11);
  list.PushFront(0);
  cout << "List is empty: "<< list.IsEmpty() << endl;
  cout << list << endl;
  cout << list.GetSize() << endl;
  static_cast<void>(list.PopFront());

  
  cout << "List after pop front:" << list << endl;

  static_cast<void>(list.PopBack());
  cout << "List after pop back: " << list << endl;

  cout << "front element: " << list.Front() << endl;

  cout << "tail element: " << list.Back() << endl;

  list.Reverse();
  cout << "list reversed: " << list << endl;
  list.Insert(2, 13);
  cout << list<< endl;
  list.Erase(4);
  cout << list << endl;
  list.PushFront(1);
  list.PushFront(1);
  list.PushFront(1);
  list.PushBack(1);
  cout << list << endl;
  list.RemoveValue(1);
  cout << list << endl;
  return 0;
}

#include <iostream>
#include "bst.h"

using namespace std;

int main(int argc, char *argv[])
{
  BST a;
  BSTNode* p1 = a.Insert(a.GetRoot(),8);
  a.SetRoot(p1);

  a.Insert(a.GetRoot(), 3);
  a.Insert(a.GetRoot(), 1);
  a.Insert(a.GetRoot(), 6);
  a.Insert(a.GetRoot(), 4);
  a.Insert(a.GetRoot(), 7);
  a.Insert(a.GetRoot(), 10);
  a.Insert(a.GetRoot(), 9);
  a.Insert(a.GetRoot(), 14);
  a.Insert(a.GetRoot(), 13);
  
  a.InOrderPrint(a.GetRoot());
  cout << endl;
  
  cout << "Total Node Count is: "<< a.GetNodeCount(a.GetRoot()) <<endl;

  cout << " 10 is in tree: " << a.IsInTree(a.GetRoot(), 10) <<endl;
  cout << " 19 is in tree? " << a.IsInTree(a.GetRoot(), 19) << endl;
  cout << " 7 is in tree? " << a.IsInTree(a.GetRoot(), 7) << endl;
  BSTNode* p2 = a.FindInTree(a.GetRoot(), 7);

  cout << "a's root is: " << a.GetRoot() << endl;
  cout << "FindInTree for 7 give the value of: " << p2->GetKey() <<endl;

  cout << "Height of BST is: "<<a.GetHeight(a.GetRoot()) <<endl;

  cout << "Min of BST is: " <<a.GetMin(a.GetRoot())->GetKey() <<endl;
  cout << "Max of BST is: " <<a.GetMax(a.GetRoot())->GetKey() <<endl;

  cout << "Tree is BST? " <<a.IsBST(a.GetRoot())<<endl;

  //Make it not a BST
  //  BSTNode* p3 = a.FindInTree(a.GetRoot(), 1);
  //a.Insert(p3,100);
  //a.InOrderPrint(a.GetRoot());
  //cout << "Tree is BST? " <<a.IsBST(a.GetRoot())<<endl;

  a.DeleteValue(a.GetRoot(), 4);
  a.InOrderPrint(a.GetRoot());
  cout << endl;
  a.DeleteValue(a.GetRoot(), 6);
  a.InOrderPrint(a.GetRoot());
  cout<<endl;
  a.DeleteValue(a.GetRoot(), 8);
  a.InOrderPrint(a.GetRoot());
  cout << endl;

  cout << "13 is leaf? " << a.IsLeaf(a.FindInTree(a.GetRoot(), 13)) << endl;
  cout << "10's successor is: " << a.GetSuccessor(a.GetRoot(), a.FindInTree(a.GetRoot(),10))->GetKey()<<endl;
    cout << "3's successor is: " << a.GetSuccessor(a.GetRoot(), a.FindInTree(a.GetRoot(),3))->GetKey()<<endl;
  return 0;
}

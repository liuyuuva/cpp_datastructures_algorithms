#ifndef LIST_NODE_H
#define LIST_NODE_H


class ListNode{
 private:
  int data_;
  ListNode *p_next_;
  
 public:
  ListNode() : data_(0), p_next_(nullptr) {}

  ListNode(const int &value) : data_(value), p_next_(nullptr)  {}
  

  ListNode(const ListNode&) = delete;


  int GetData() const { return data_; }
  void SetData(const int &value) { data_ = value; }
  void SetNext(ListNode *next) { p_next_ = next; }

  ListNode* GetNext() const { return p_next_; }
};
  

#endif

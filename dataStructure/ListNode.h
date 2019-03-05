#pragma once
class ListNode
{
public:
  ListNode();
  virtual ~ListNode();
  ListNode::ListNode(int val, ListNode *next);
  void ListNode::setVal(int val);
  int ListNode::getVal();
  void ListNode::setNext(ListNode *next);
  ListNode * ListNode::getNext();

  ListNode *ListNode::buildList(int arr[], int len);

  void ListNode::reversalPrint(ListNode *listNode);

private:
  int val;
  ListNode *next;
};


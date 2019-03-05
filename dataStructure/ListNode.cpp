#include "stdafx.h"
#include "ListNode.h"


ListNode::ListNode()
{
}


ListNode::~ListNode()
{
  delete next;
}

ListNode::ListNode(int val, ListNode *next) {
  this->val = val;
  this->next = next;
}

void ListNode::setVal(int val)
{
  this->val = val;
}

int ListNode::getVal() 
{
  return this->val;
}

ListNode * ListNode::getNext()
{
  return this->next;
}

void ListNode::setNext(ListNode *next)
{
  this->next = next;
}

ListNode *ListNode::buildList(int arr[], int len) 
{
  ListNode *first = nullptr, *nextNode = nullptr, *newNode = nullptr;
  for (int i = 0; i < len; i++) 
  {
    if (first == nullptr) {
      first = new ListNode(arr[i], nullptr);
      nextNode = first;
    }
    else
    {
      newNode = new ListNode(arr[i], nullptr);
      nextNode->setNext(newNode);
      nextNode = nextNode->getNext();
    }
  }
  return first;
}

void ListNode::reversalPrint(ListNode *listNode) 
{
  if (listNode == nullptr) {
    return;
  }
  ListNode *next = listNode->getNext();
  reversalPrint(next);
  std::cout << listNode->getVal() << std::endl;
}

#pragma once
#include <stack>
class Queue
{
private:
  std::stack<int> in;
  std::stack<int> out;
public:
  Queue();
  virtual ~Queue();
  int Queue::push(int num);
  int Queue::pop();
};


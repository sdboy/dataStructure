#include "stdafx.h"
#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

void Queue::push(int num)
{
  // �����ջΪ��
  if (this->in.empty())
  {
    // �����ջ��Ϊ��
    if (!this->out.empty())
    {
      while (!this->out.empty())
      {
        this->in.push(out.top());
        out.pop();
      }
    }
    in.push(num);
    while (!this->in.empty())
    {
      this->out.push(in.top());
      in.pop();
    }
  }
}

int Queue::pop()
{
  int result = NULL;
  if (!this->out.empty())
  {
    result = this->out.top();
    this->out.pop();
  }
  return result;
}
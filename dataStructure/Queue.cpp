#include "stdafx.h"
#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}

int Queue::push(int num)
{
  // �����ջΪ��
  if (this->in.empty)
  {
    // �����ջ��Ϊ��
    if (!this->out.empty)
    {
      while (!this->out.empty)
      {
        this->in.push(out.top());
        out.pop();
      }
    }
    while (!this->in.empty)
    {
      this->out.push(in.top);
      in.pop();
    }
  }
}

int Queue::pop()
{

}
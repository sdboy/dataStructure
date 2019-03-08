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
  // 如果进栈为空
  if (this->in.empty)
  {
    // 如果出栈不为空
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
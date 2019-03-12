#include "stdafx.h"
#include "FibonacciSequence.h"


FibonacciSequence::FibonacciSequence()
{
}


FibonacciSequence::~FibonacciSequence()
{
}

int FibonacciSequence::recursion(int n)
{
  if (n <= 1)
  {
    return n;
  }
  int sum = 0;
  if (n > 1)
  {
    sum = recursion(n - 1) + recursion(n - 2);
  }
  return sum;
}

int FibonacciSequence::dynamicProgramming(int n)
{
  if (n <= 1)
  {
    return n;
  }
  int *fib = new int[n + 1];
  fib[0] = 0;
  fib[1] = 1;
  if (n > 1)
  {
    for (int i = 2; i < n + 1; i++)
    {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
  }
  int sum = fib[n];
  delete[]fib;
  return sum;
}

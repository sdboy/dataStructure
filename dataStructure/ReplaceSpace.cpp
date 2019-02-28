#include "stdafx.h"
#include "ReplaceSpace.h"


ReplaceSpace::ReplaceSpace()
{
}


ReplaceSpace::~ReplaceSpace()
{
}

std::string ReplaceSpace::replaceSpace(std::string str) {
  int p1 = str.size() - 1;
  for (int i = 0; i <= p1; i++)
  {
    if (str[i] == ' ') 
    {
      str.append("  ");
    }
  }
  int p2 = str.size() - 1;
  while (p1 >= 0 && p2 > p1)
  {
    char c = str[p1--];
    if (c == ' ') {
      str[p2--] = '0';
      str[p2--] = '2';
      str[p2--] = '%';
    }
    else
    {
      str[p2--] = c;
    }
  }
  return str;
}

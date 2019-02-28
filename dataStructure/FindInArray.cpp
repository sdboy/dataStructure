#include "stdafx.h"
#include "FindInArray.h"


FindInArray::FindInArray()
{
}


FindInArray::~FindInArray()
{
}

bool FindInArray::find(int target, int matrix[5][5], int row, int col) 
{
  
  int r = 0, c = col - 1;
  while (r <= row -1 && c >= 0)
  {
    if (matrix[r][c] == target) 
    {
      return true;
    } else if (matrix[r][c] < target) 
    {
      r++;
    } else 
    {
      c--;
    }
  }
  return false;
}

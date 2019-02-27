#include "stdafx.h"
#include "FindNum.h"



FindNum::FindNum()
{
}


FindNum::~FindNum()
{
}
/**
 * 循环遍历是否有相同数字
 */
int FindNum::findNum(int arr[]) 
{
  int len = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < len; i++) {
    while (arr[i] != i)
    {
      if (arr[i] == arr[arr[i]]) {
        return arr[i];
      }
      FindNum::swap(arr, i, arr[i]);
    }
  }
  return -1;
}

void FindNum::swap(int arr[], int i, int j) 
{
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}

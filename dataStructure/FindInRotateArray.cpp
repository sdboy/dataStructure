#include "stdafx.h"
#include "FindInRotateArray.h"


FindInRotateArray::FindInRotateArray()
{
}


FindInRotateArray::~FindInRotateArray()
{
}

int FindInRotateArray::getMin(int arr[], int left, int right)
{
  int len = right - left + 1;
  if (len <= 2)
  {
    if (arr[left] > arr[right])
    {
      return arr[right];
    }
    else
    {
      return arr[left];
    }
  }
  int mid = (left + right) / 2;
  // 如果中间大于右边
  if (arr[mid] > arr[right])
  {
    return getMin(arr, mid, right);
  }
  // 如果右边等于中间
  else if(arr[mid] == arr[right])
  {
    for (int i = left; i < right; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        return arr[i + 1];
      }
    }
    return arr[left];
  }
  // 如果中间小于右边
  else
  {
    return getMin(arr, left, mid);
  }
}

int FindInRotateArray::getMinLoop(int arr[], int left, int right)
{
  int l = left, r = right;
  while (l < r)
  {
    int mid = (l + r) / 2;
    // 如果中间大于右边
    if (arr[mid] > arr[r])
    {
      l = mid + 1;
    }
    // 如果中间等于右边且等于左边
    else if(arr[mid] == arr[r] && arr[mid] == arr[l])
    {
      for (int i = l; i < r; i++)
      {
        if (arr[i] > arr[i + 1])
        {
          return arr[i + 1];
        }
      }
      return arr[l];
    }
    // 如果中间小于等于右边，在等于右边的时候，由于不等于左边，左边肯定大于右边，中间小于左边
    // 所以最小值在左边到中间的范围里
    else
    {
      r = mid;
    }

  }
  return arr[l];
}

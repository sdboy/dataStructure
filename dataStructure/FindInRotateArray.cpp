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
  // ����м�����ұ�
  if (arr[mid] > arr[right])
  {
    return getMin(arr, mid, right);
  }
  // ����ұߵ����м�
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
  // ����м�С���ұ�
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
    // ����м�����ұ�
    if (arr[mid] > arr[r])
    {
      l = mid + 1;
    }
    // ����м�����ұ��ҵ������
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
    // ����м�С�ڵ����ұߣ��ڵ����ұߵ�ʱ�����ڲ�������ߣ���߿϶������ұߣ��м�С�����
    // ������Сֵ����ߵ��м�ķ�Χ��
    else
    {
      r = mid;
    }

  }
  return arr[l];
}

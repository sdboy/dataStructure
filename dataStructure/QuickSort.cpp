#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}

void * QuickSort::sort(int arr[], int i, int j) 
{
  int left = i, right = j;
  int len = j - i + 1;
  if (len > 2)
  {
    int base = swatchMiddle(arr, left, right);
    while (left < right)
    {
      // �����ߵĴ���base
      if (arr[left] > arr[base])
      {
        bool flag = false;
        // ��ѯ�ұ��Ƿ���С��base��
        while(base < right)
        {
          if (arr[base] > arr[right])
          {
            flag = true;
            break;
          }
          right--;
        }
        // ����ұ���С��ֻ��Ҫ����С����
        if (flag) 
        {
          swap(arr[left], arr[right]);
        }
        else
        {
          swap(arr[left], arr[base]);
          base = left;
          left = base - 1;
        }
      }
      else if(arr[left] == arr[base])
      {  
        // �Ѿ��ƶ�����׼�ڵ�
        if (left == base) {
          while (left < right)
          {
            // ����ұ���С�ڻ�׼��
            if (arr[base] > arr[right]) 
            {
              swap(arr[base], arr[right]);
              base = right;
              right = base + 1;
            }
            else if(arr[base] == arr[right])
            {
              if (base == right) 
              {
                break;
              }
              
            }
            right--;
          }
        }

      }
      left++;
    }
    sort(arr, i, base - 1);
    sort(arr, base + 1, j);
  }
  else if(len == 2)
  {
    if (arr[i] > arr[j])
    {
      swap(arr[i], arr[j]);
    }
    return NULL;
  }
  else
  {
    return NULL;
  }

}

int QuickSort::swatchMiddle(int arr[], int left, int right)
{
  int mid = (left + right) / 2;
  
  if (arr[left] > arr[mid])
  {
    swap(arr[left], arr[mid]);
  }
  if (arr[mid] > arr[right])
  {
    swap(arr[mid], arr[right]);
  }
  if (arr[left] > arr[mid])
  {
    swap(arr[left], arr[mid]);
  }
  return mid;
}

void QuickSort::swap(int &left, int &right) {
  int temp;
  temp = left;
  left = right;
  right = temp;
}

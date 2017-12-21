#include "stdafx.h"
#include "MergeSort.h"


MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::startMergeSort() {
  int arr[] = { 3, 45, 938, 943, 22, 33, 34, 90, 23, 22, 98 };
  int start = 0;
  int end = 10;
  int i = 0;
  std::cout << "before sort:";
  for (i = 0; i < 11; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  merge_sort_up2down(arr, start, end);
  std::cout << "after sort:";
  for (i = 0; i < 11; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  system("pause");
  return;
}

void MergeSort::merge(int a[], int start, int mid, int end)
{
  int *tmp = (int *)malloc((end - start + 1) * sizeof(int));    // tmp是汇总2个有序区的临时区域
  int i = start;          // 第1个有序区的索引
  int j = mid + 1;        // 第2个有序区的索引
  int k = 0;              // 临时区域的索引

  while (i <= mid && j <= end)
  {
    if (a[i] <= a[j])
    {
      tmp[k++] = a[i++];
    }
    else
    {
      tmp[k++] = a[j++];
    }
  }

  while (i <= mid)
  {
    tmp[k++] = a[i++];
  }
  while (j <= end)
  {
    tmp[k++] = a[j++];
  }
  // 将排序后的元素，全部都整合到数组a中。
  for (i = 0; i < k; i++)
  {
    a[start + i] = tmp[i];
  }
  free(tmp);
  tmp = NULL;
  return;
}

void MergeSort::merge_sort_up2down(int a[], int start, int end)
{
  if (a == NULL || start >= end)
  {
    return;
  }
  int mid = (end + start) / 2;
  merge_sort_up2down(a, start, mid); // 递归排序a[start...mid]
  merge_sort_up2down(a, mid + 1, end); // 递归排序a[mid+1...end]
  merge(a, start, mid, end);
}

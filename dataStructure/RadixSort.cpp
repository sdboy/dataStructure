#include "stdafx.h"
#include "RadixSort.h"


RadixSort::RadixSort()
{
}


RadixSort::~RadixSort()
{
}

void RadixSort::startRadixSort()
{
  int i;
  int a[] = { 53, 3, 542, 748, 14, 214, 154, 63, 616 };
  int ilen = (sizeof(a)) / (sizeof(a[0]));
  std::cout << "before sort:";
  for (i = 0; i < ilen; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  radixSort(a, ilen);
  std::cout << "after sort:";
  for (i = 0; i < ilen; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  system("pause");
  return;
}

int RadixSort::getMax(int a[], int n)
{
  int i, max;
  max = a[0];
  for (i = 1; i < n; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }
  return max;
}

void RadixSort::countSort(int a[], int n, int exp)
{
  int output[10];
  int i, buckets[10] = { 0 };
  for (i = 0; i < n; i++)
  {
    buckets[(a[i] / exp) % 10]++;
  }
  for (i = 1; i < n; i++)
  {
    buckets[i] += buckets[i - 1];
  }
  for (i = n - 1; i >= 0; i--)
  {
    output[buckets[(a[i] / exp) % 10] - 1] = a[i];
    buckets[(a[i] / exp) % 10]--;
  }
  for (i = 0; i < n; i++)
  {
    a[i] = output[i];
  }
}

void RadixSort::radixSort(int a[], int n)
{
  int exp;
  int max = getMax(a, n);
  for (exp = 1; max / exp > 0; exp *= 10)
  {
    countSort(a, n, exp);
  }
}

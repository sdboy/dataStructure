#include "stdafx.h"
#include "BucketSort.h"


BucketSort::BucketSort()
{
}


BucketSort::~BucketSort()
{
}

void BucketSort::startBucketSort()
{
  int a[9] = { 8, 2, 3, 4, 3, 6, 6, 3, 9 };
  int count = 9;
  int max = 10;
  int i = 0;
  std::cout << "before sort:";
  for (i = 0; i < 9; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  bucket_sort(a, count, max);
  std::cout << "after sort:";
  for (i = 0; i < 9; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  system("pause");
  return;
}

void BucketSort::bucket_sort(int a[], int n, int max)
{
  int i, j;
  int *buckets;
  if (a == NULL || n < 1 || max < 1)
  {
    return;
  }
  if ((buckets = (int *)malloc(max * sizeof(int))) == NULL)
  {
    return;
  }
  memset(buckets, 0, max * sizeof(int));
  for (i = 0; i < n; i++)
  {
    buckets[a[i]]++;
  }
  for (i = 0, j = 0; i < max; i++)
  {
    while ((buckets[i]--) > 0)
    {
      a[j++] = i;
    }
  }
  free(buckets);
  buckets = NULL;
}

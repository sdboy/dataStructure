#pragma once
class MergeSort
{
public:
  MergeSort();
  ~MergeSort();
  void startMergeSort();
  void merge(int a[], int start, int mid, int end);
  void merge_sort_up2down(int a[], int start, int end);
};


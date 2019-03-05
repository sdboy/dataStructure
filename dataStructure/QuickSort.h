#pragma once
class QuickSort
{
public:
  QuickSort();
  virtual ~QuickSort();
  void * QuickSort::sort(int arr[], int i, int j);
  int QuickSort::swatchMiddle(int arr[], int i, int j);
  void QuickSort::swap(int &left, int &right);
};


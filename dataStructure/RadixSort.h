#pragma once
class RadixSort
{
  public:
    RadixSort();
    ~RadixSort();
    void startRadixSort();
    int getMax(int a[], int n);
    void countSort(int a[], int n, int exp);
    void radixSort(int a[], int n);
};


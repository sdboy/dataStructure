// dataStructure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BucketSort.h"
#include "RadixSort.h"
#include "MergeSort.h"
#include "FindNum.h"
#include "FindInArray.h"


int main()
{
  /*MergeSort ms;
  ms.startMergeSort();*/
  int arr[5][5] = { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
  int len = sizeof(arr) / sizeof(int);
  int col = sizeof(arr[0]) / sizeof(int);
  int row = len / col;
  int target = 5;
  //FindNum fn;
  //int num = fn.findNum(arr);
  //std::cout << num << std::endl;
  FindInArray fia;
  bool flag = fia.find(target, arr, row, col);
  std::cout << flag << std::endl;
  return 0;
}


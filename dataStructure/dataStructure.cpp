// dataStructure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BucketSort.h"
#include "RadixSort.h"
#include "MergeSort.h"
#include "FindNum.h"


int main()
{
  /*MergeSort ms;
  ms.startMergeSort();*/
  int arr[6] = {5,2,3,1,4,2};
  FindNum fn;
  int num = fn.findNum(arr);
  std::cout << num << std::endl;
  return 0;
}


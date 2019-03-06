// dataStructure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "BucketSort.h"
#include "RadixSort.h"
#include "MergeSort.h"
#include "FindNum.h"
#include "FindInArray.h"
#include "ReplaceSpace.h"
#include "ListNode.h"
#include "QuickSort.h"
#include "BinaryTree.h"

int main()
{
  /*MergeSort ms;
  ms.startMergeSort();*/
  /*int arr[5][5] = { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
  int len = sizeof(arr) / sizeof(int);
  int col = sizeof(arr[0]) / sizeof(int);
  int row = len / col;
  int target = 5;*/
  //FindNum fn;
  //int num = fn.findNum(arr);
  //std::cout << num << std::endl;
  /*FindInArray fia;
  bool flag = fia.find(target, arr, row, col);
  std::cout << flag << std::endl;*/
  /*ReplaceSpace rs;
  std::string str = "234343 23432 234324 234";
  std::cout << rs.replaceSpace(str) << std::endl;*/
  //int input[] = { 8,3,4,5,7,9,29 };
  /*int len = sizeof(input) / sizeof(int);
  ListNode ln;
  ListNode *listNode = ln.buildList(input, len);
  ln.reversalPrint(listNode);
  delete listNode;*/
  /*QuickSort qs;
  qs.sort(input, 0, 6);
  for (int i = 0; i < 7; i++)
  {
    std::cout << input[i] << std::endl;
  }*/
  int preOrder[] = { 3, 9, 20, 15, 7 };
  int inOrder[] = { 9, 3, 15, 20, 7 };
  BinaryTree bt;
  BinaryTree *root = bt.buildTree(preOrder, 5, inOrder, 5);
  delete root;
  root = nullptr;
  return 0;
}


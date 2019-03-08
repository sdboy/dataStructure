#pragma once
#include <map>
class BinaryTree
{
private:
  int val;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;
public:
  BinaryTree();
  virtual ~BinaryTree();
  BinaryTree::BinaryTree(int val, BinaryTree *left, BinaryTree *right);
  BinaryTree::BinaryTree(int val, BinaryTree *left, BinaryTree *right, BinaryTree *parent);
  void BinaryTree::setVal(int val);
  int BinaryTree::getVal();
  void BinaryTree::setLeft(BinaryTree *left);
  BinaryTree *BinaryTree::getLeft();
  void BinaryTree::setRight(BinaryTree *right);
  BinaryTree *BinaryTree::getRight();
  void BinaryTree::setParent(BinaryTree *parent);
  BinaryTree *BinaryTree::getParent();
  BinaryTree * BinaryTree::buildTree(int pre[], int preLen, int in[], int inLen);
  BinaryTree * BinaryTree::buildTree(int pre[], int preL, int preR, int inL, std::map<int, int> &indexForInOrder);
  BinaryTree * BinaryTree::buildTree(int pre[], int preL, int preR, int inL, std::map<int, int> &indexForInOrder, BinaryTree *parent);
  void BinaryTree::preOrderTraversal(BinaryTree *binaryTree);
  void BinaryTree::inOrderTraversal(BinaryTree *binaryTree);
  void BinaryTree::postOrderTraversal(BinaryTree *binaryTree);
  BinaryTree *BinaryTree::findNext(BinaryTree *pNode);
  BinaryTree *BinaryTree::findLeft(BinaryTree *pNode);
};


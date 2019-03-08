#include "stdafx.h"
#include "BinaryTree.h"
#include <map>


BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

BinaryTree::BinaryTree(int val, BinaryTree *left, BinaryTree *right)
{
  this->val = val;
  this->left = left;
  this->right = right;
}

BinaryTree::BinaryTree(int val, BinaryTree *left, BinaryTree *right, BinaryTree *parent)
{
  this->val = val;
  this->left = left;
  this->right = right;
  this->parent = parent;
}

void BinaryTree::setVal(int val)
{
  this->val = val;
}

int BinaryTree::getVal()
{
  return this->val;
}

void BinaryTree::setLeft(BinaryTree *left)
{
  this->left = left;
}

BinaryTree *BinaryTree::getLeft()
{
  return this->left;
}

void BinaryTree::setRight(BinaryTree *right)
{
  this->right = right;
}

BinaryTree *BinaryTree::getRight()
{
  return this->right;
}

void BinaryTree::setParent(BinaryTree *parent)
{
  this->parent = parent;
}
BinaryTree *BinaryTree::getParent()
{
  return this->parent;
}

BinaryTree * BinaryTree::buildTree(int pre[], int preLen, int in[], int inLen)
{
  std::map<int, int> indexForInOrder;
  for (int i = 0; i < inLen; i++)
  {
    indexForInOrder.insert(std::map<int, int>::value_type(in[i], i));
  }
  BinaryTree *root = buildTree(pre, 0, preLen - 1, 0, indexForInOrder, nullptr);
  return root;
}

BinaryTree * BinaryTree::buildTree(int pre[], int preL, int preR, int inL, std::map<int, int> &indexForInOrder)
{
  BinaryTree *root = new BinaryTree(pre[preL], nullptr, nullptr);

  std::map<int, int>::iterator iter;
  int index;
  iter = indexForInOrder.find(pre[preL]);
  if (iter != indexForInOrder.end())
  {
    index = iter->second;
  }
  else
  {
    return nullptr;
  }
  int leftTreeSize = index - inL;
  BinaryTree *left = nullptr;
  if (preL + 1 <= preL + leftTreeSize)
  {
    left = buildTree(pre, preL + 1, preL + leftTreeSize, inL, indexForInOrder);
  }
  if (left != nullptr)
  {
    root->setLeft(left);
  }
  BinaryTree *right = nullptr;
  if (preL + leftTreeSize + 1 <= preR)
  {
    right = buildTree(pre, preL + leftTreeSize + 1, preR, inL + leftTreeSize + 1, indexForInOrder);
  }
  if (right != nullptr)
  {
    root->setRight(right);
  }
  return root;
}

BinaryTree * BinaryTree::buildTree(int pre[], int preL, int preR, int inL, std::map<int, int> &indexForInOrder, BinaryTree *parent)
{
  BinaryTree *root = new BinaryTree(pre[preL], nullptr, nullptr);

  std::map<int, int>::iterator iter;
  int index;
  iter = indexForInOrder.find(pre[preL]);
  if (iter != indexForInOrder.end())
  {
    index = iter->second;
  }
  else
  {
    return nullptr;
  }
  int leftTreeSize = index - inL;
  BinaryTree *left = nullptr;
  if (preL + 1 <= preL + leftTreeSize)
  {
    left = buildTree(pre, preL + 1, preL + leftTreeSize, inL, indexForInOrder, root);
  }
  if (left != nullptr)
  {
    root->setLeft(left);
  }
  BinaryTree *right = nullptr;
  if (preL + leftTreeSize + 1 <= preR)
  {
    right = buildTree(pre, preL + leftTreeSize + 1, preR, inL + leftTreeSize + 1, indexForInOrder, root);
  }
  if (right != nullptr)
  {
    root->setRight(right);
  }
  if (parent != nullptr)
  {
    root->setParent(parent);
  }
  return root;
}

void BinaryTree::preOrderTraversal(BinaryTree *binaryTree)
{
  if (binaryTree == nullptr)
  {
    return;
  }
  std::cout << binaryTree->getVal() << std::endl;
  BinaryTree *left = binaryTree->getLeft();
  if (left != nullptr)
  {
    preOrderTraversal(left);
  }
  BinaryTree *right = binaryTree->getRight();
  if (right != nullptr)
  {
    preOrderTraversal(right);
  }
  return;
}

void BinaryTree::inOrderTraversal(BinaryTree *binaryTree)
{
  if (binaryTree == nullptr)
  {
    return;
  }
  BinaryTree *left = binaryTree->getLeft();
  if (left != nullptr)
  {
    inOrderTraversal(left);
  }
  std::cout << binaryTree->getVal() << std::endl;
  BinaryTree *right = binaryTree->getRight();
  if (right != nullptr)
  {
    inOrderTraversal(right);
  }
  return;
}

void BinaryTree::postOrderTraversal(BinaryTree *binaryTree)
{
  if (binaryTree == nullptr)
  {
    return;
  }
  BinaryTree *left = binaryTree->getLeft();
  if (left != nullptr)
  {
    inOrderTraversal(left);
  }
  BinaryTree *right = binaryTree->getRight();
  if (right != nullptr)
  {
    inOrderTraversal(right);
  }
  std::cout << binaryTree->getVal() << std::endl;
  return;
}

BinaryTree *BinaryTree::findNext(BinaryTree *pNode)
{
  BinaryTree *right = pNode->getRight();
  if (right != nullptr)
  {
    return findLeft(right);
  }
  else
  {
    BinaryTree *parent = pNode->getParent();
    if (parent != nullptr)
    {
      return parent;
    }
    else
    {
      return nullptr;
    }
  }
}

BinaryTree *BinaryTree::findLeft(BinaryTree *pNode)
{
  BinaryTree *left = pNode->getLeft();
  if (left != nullptr)
  {
    findLeft(left);
  }
  else
  {
    return pNode;
  }
}
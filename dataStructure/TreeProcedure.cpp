#include "stdafx.h"
#include "TreeProcedure.h"


TreeProcedure::TreeProcedure()
{
}


TreeProcedure::~TreeProcedure()
{
}

TreeProcedure::TreeProcedure(RedBlackTree *root)
{
  this->root = root;
}
void TreeProcedure::add(int num)
{
  if (this->root == nullptr)
  {
    RedBlackTree *root = new RedBlackTree(num, true, nullptr, nullptr, nullptr);
    this->root = root;
  }
  else
  {
    put(num, this->root);
  }
  return;
}

void TreeProcedure::put(int num, RedBlackTree *parent)
{
  int pValue = parent->getValue();
  if (pValue < num)
  {
    if (parent->getRight() != nullptr)
    {
      put(num, parent->getRight());
    }
    else
    {
      RedBlackTree *node = new RedBlackTree(num, false, parent, nullptr, nullptr);
      parent->setRight(node);
    }
  }
  else
  {
    if (parent->getLeft() != nullptr)
    {
      put(num, parent->getLeft());
    }
    else
    {
      RedBlackTree *node = new RedBlackTree(num, false, parent, nullptr, nullptr);
      parent->setLeft(node);
    }
  }
  return;
}
RedBlackTree *TreeProcedure::buildRedBlackTree(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    add(arr[i]);
  }
  if (this->root != nullptr)
  {
    return this->root;
  }
  return nullptr;
}
void TreeProcedure::preOrderTraversal(RedBlackTree *redBlackTree)
{
  if (redBlackTree == nullptr)
  {
    return;
  }
  std::cout << redBlackTree->getValue() << std::endl;
  RedBlackTree *left = redBlackTree->getLeft();
  if (left != nullptr)
  {
    preOrderTraversal(left);
  }
  RedBlackTree *right = redBlackTree->getRight();
  if (right != nullptr)
  {
    preOrderTraversal(right);
  }
  return;
}
void TreeProcedure::inOrderTraversal(RedBlackTree *redBlackTree)
{
  if (redBlackTree == nullptr)
  {
    return;
  }
  RedBlackTree *left = redBlackTree->getLeft();
  if (left != nullptr)
  {
    inOrderTraversal(left);
  }
  std::cout << redBlackTree->getValue() << std::endl;
  RedBlackTree *right = redBlackTree->getRight();
  if (right != nullptr)
  {
    inOrderTraversal(right);
  }
  return;
}
void TreeProcedure::postOrderTraversal(RedBlackTree *redBlackTree)
{
  if (redBlackTree == nullptr)
  {
    return;
  }
  RedBlackTree *left = redBlackTree->getLeft();
  if (left != nullptr)
  {
    inOrderTraversal(left);
  }
  RedBlackTree *right = redBlackTree->getRight();
  if (right != nullptr)
  {
    inOrderTraversal(right);
  }
  std::cout << redBlackTree->getValue() << std::endl;
  return;
}

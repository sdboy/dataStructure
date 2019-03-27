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
  RedBlackTree *node = new RedBlackTree();
  if (pValue < num)
  {
    if (parent->getRight() != nullptr)
    {
      put(num, parent->getRight());
    }
    else
    {
      node->setColor(false);
      node->setValue(num);
      node->setParent(parent);
      parent->setRight(node);
      fixup(this->root, node);
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
      node->setColor(false);
      node->setValue(num);
      node->setParent(parent);
      parent->setLeft(node);
      fixup(this->root, node);
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
void TreeProcedure::fixup(RedBlackTree *redBlackTree, RedBlackTree *node)
{
  if (redBlackTree == nullptr || node == nullptr)
  {
    return;
  }
  RedBlackTree *parent = node->getParent();
  while (parent->getColor() == false)
  {
    RedBlackTree *grandParent = parent->getParent();
    RedBlackTree *uncle = nullptr;
    if (parent == grandParent->getLeft())
    {
      uncle = grandParent->getRight();
      if (uncle->getColor() == false)
      {
        parent->setColor(true);
        uncle->setColor(true);
        grandParent->setColor(false);
        node = grandParent;
      }
      else if(node == parent->getRight())
      {
        node = parent;
        // ×óÐý
        parent->setColor(true);
        grandParent->setColor(false);
        // ÓÒÐý
      }
    }
    else
    {
      uncle = grandParent->getLeft();
      if (uncle->getColor() == false)
      {
        parent->setColor(true);
        uncle->setColor(true);
        grandParent->setColor(false);
        node = grandParent;
      }
      else if (node == parent->getLeft())
      {
        node = parent;
        // ×óÐý
        parent->setColor(true);
        grandParent->setColor(false);
        // ÓÒÐý
      }
    }
  }
}
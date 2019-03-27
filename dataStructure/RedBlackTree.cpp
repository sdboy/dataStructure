#include "stdafx.h"
#include "RedBlackTree.h"


RedBlackTree::RedBlackTree()
{
}


RedBlackTree::~RedBlackTree()
{
  delete this->parent;
  delete this->left;
  delete this->right;
}

RedBlackTree::RedBlackTree(int value, bool color, RedBlackTree *parent, RedBlackTree *left, RedBlackTree *right)
{
  this->value = value;
  this->color = color;
  this->parent = parent;
  this->left = left;
  this->right = right;
}

void RedBlackTree::setValue(int value)
{
  this->value = value;
}
int RedBlackTree::getValue()
{
  return this->value;
}
void RedBlackTree::setColor(bool color)
{
  this->color = color;
}
bool RedBlackTree::getColor()
{
  return this->color;
}
void RedBlackTree::setParent(RedBlackTree *parent)
{
  this->parent = parent;
}
RedBlackTree *RedBlackTree::getParent()
{
  return this->parent;
}
void RedBlackTree::setLeft(RedBlackTree *left)
{
  this->left = left;
}
RedBlackTree *RedBlackTree::getLeft()
{
  return this->left;
}
void RedBlackTree::setRight(RedBlackTree *right)
{
  this->right = right;
}
RedBlackTree *RedBlackTree::getRight()
{
  return this->right;
}

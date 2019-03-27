#pragma once
class RedBlackTree
{
private:
  int value;
  bool color;
  RedBlackTree *parent = nullptr;
  RedBlackTree *left = nullptr;
  RedBlackTree *right = nullptr;
public:
  RedBlackTree();
  virtual ~RedBlackTree();
  RedBlackTree::RedBlackTree(int value, bool color, RedBlackTree *parent, RedBlackTree *left, RedBlackTree *right);
  void RedBlackTree::setValue(int value);
  int RedBlackTree::getValue();
  void RedBlackTree::setColor(bool color);
  bool RedBlackTree::getColor();
  void RedBlackTree::setParent(RedBlackTree *parent);
  RedBlackTree *RedBlackTree::getParent();
  void RedBlackTree::setLeft(RedBlackTree *left);
  RedBlackTree *RedBlackTree::getLeft();
  void RedBlackTree::setRight(RedBlackTree *right);
  RedBlackTree *RedBlackTree::getRight();
};


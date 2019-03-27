#pragma once
#include "RedBlackTree.h"

class TreeProcedure
{
private:
  RedBlackTree *root = nullptr;
public:
  TreeProcedure();
  virtual ~TreeProcedure();
  TreeProcedure::TreeProcedure(RedBlackTree *root);
  void TreeProcedure::add(int num);
  void TreeProcedure::put(int num, RedBlackTree *parent);
  RedBlackTree *TreeProcedure::buildRedBlackTree(int arr[], int len);
  void TreeProcedure::preOrderTraversal(RedBlackTree *redBlackTree);
  void TreeProcedure::inOrderTraversal(RedBlackTree *redBlackTree);
  void TreeProcedure::postOrderTraversal(RedBlackTree *redBlackTree);
  void TreeProcedure::fixup(RedBlackTree *redBlackTree, RedBlackTree *node);
};


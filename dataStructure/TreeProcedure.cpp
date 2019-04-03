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
      // 插入节点为红色，这样只会影响特性4
      node->setColor(false);
      node->setValue(num);
      node->setParent(parent);
      parent->setRight(node);
      fixup(node);
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
      fixup(node);
    }
  }

  return;
}

RedBlackTree *TreeProcedure::buildRedBlackTree(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    //add(arr[i]);
    treeInsert(arr[i]);
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

void TreeProcedure::fixup(RedBlackTree *node)
{
  if (node == nullptr || node->getParent() == nullptr)
  {
    return;
  }
  RedBlackTree *parent = node->getParent();
  // 当父节点是黑色时加入红色节点不影响特性4成立，当为红色时可能影响特性4成立
  while (parent != nullptr && parent->getColor() == false)
  {
    // 祖父节点
    RedBlackTree *grandParent = parent->getParent();
    // 叔叔节点
    RedBlackTree *uncle = nullptr;
    if (grandParent == nullptr)
    {
      break;
    }
    // 如果父节点是祖父节点的左孩子
    if (parent == grandParent->getLeft())
    {
      uncle = grandParent->getRight();
      if (uncle != nullptr && uncle->getColor() == false)
      {
        parent->setColor(true);
        uncle->setColor(true);
        grandParent->setColor(false);
        node = grandParent;
        continue;
      }
      else if(node == parent->getRight())
      {
        node = parent;
        // 左旋
		    leftRotate(node);
	    }
		  parent = node->getParent();
		  grandParent = parent->getParent();
		  parent->setColor(true);
		  grandParent->setColor(false);
		  // 右旋
		  rightRotate(grandParent);
    }
    // 如果是右孩子
    else
    {
      uncle = grandParent->getLeft();
      if (uncle != nullptr && uncle->getColor() == false)
      {
        parent->setColor(true);
        uncle->setColor(true);
        grandParent->setColor(false);
        node = grandParent;
        continue;
      }
      else if (node == parent->getLeft())
      {
        node = parent;
        // 右旋
        rightRotate(node);
      }
      parent = node->getParent();
      grandParent = parent->getParent();
      parent->setColor(true);
      grandParent->setColor(false);
      // 左旋
      leftRotate(grandParent);
    }
  }
  parent = node->getParent();
}

void TreeProcedure::treeInsert(int num)
{
  RedBlackTree *y = nullptr;
  RedBlackTree *x = this->root;
  // 如果子树中节点存在
  while (x != nullptr)
	{
    y = x;
    if (x->getValue() > num)
    {
      x = x->getLeft();
    }
    else
    {
      x = x->getRight();
    }
  }
  RedBlackTree *node = new RedBlackTree();
  node->setValue(num);
  // 如果不存在，则插入的节点是根节点
  if (y == nullptr)
  {
    this->root = node;
    return;
  }
  node->setParent(y);
  if (y->getValue() > num)
  {
    y->setLeft(node);
  }
  else
  {
    y->setRight(node);
  }
  fixup(node);
  return;
}

void TreeProcedure::leftRotate(RedBlackTree *node)
{
  // 如果节点是空，结束执行
  if (node == nullptr)
  {
    return;
  }
  // 获取右孩子，如果右孩子为空结束执行
  RedBlackTree *rChild = node->getRight();
  if (rChild == nullptr)
  {
    return;
  }
  // 获取父节点
  RedBlackTree *parent = node->getParent();
  if (parent != nullptr)
  {
    if (parent->getLeft() == node)
    {
      parent->setLeft(rChild);
    }
    else
    {
      parent->setRight(rChild);
    }
  }
  rChild->setParent(parent);
  // 获取右孩子的左孩子，如果不为空将其父节点设为node
  RedBlackTree *glChild = rChild->getLeft();
  if (glChild != nullptr)
  {
    glChild->setParent(node);
  }
  node->setRight(glChild);
  node->setParent(rChild);
  rChild->setLeft(node);
  return;
}

void TreeProcedure::rightRotate(RedBlackTree *node)
{
  // 如果节点是空，结束执行
  if (node == nullptr)
  {
    return;
  }
  // 获取右孩子，如果右孩子为空结束执行
  RedBlackTree *lChild = node->getLeft();
  if (lChild == nullptr)
  {
    return;
  }
  // 获取父节点
  RedBlackTree *parent = node->getParent();
  if (parent != nullptr)
  {
    if (parent->getLeft() == node)
    {
      parent->setLeft(lChild);
    }
    else
    {
      parent->setRight(lChild);
    }
  }
  lChild->setParent(parent);
  // 获取左孩子的右孩子，如果不为空将其父节点设为node
  RedBlackTree *grChild = lChild->getLeft();
  if (grChild != nullptr)
  {
    grChild->setParent(node);
  }
  node->setLeft(grChild);
  node->setParent(lChild);
  lChild->setRight(node);
  return;
}
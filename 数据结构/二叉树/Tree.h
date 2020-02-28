//
// Created by xtt on 2020/2/19.
//

#ifndef _TREE_H
#define _TREE_H

#include <iostream>

using namespace std;

typedef int EleType;
typedef struct Node TreeNode;

struct Node {
    EleType val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    Node() {

    }

    Node(EleType _val) {
        val = _val;
    }
};



void insert(TreeNode *&, EleType);           //插入数据
//递归
void preOrder(TreeNode *);                  //前序遍历
void preOrderNor(TreeNode*);               //非递归前序遍历

void inOrder(TreeNode *);                   //中序遍历
void inOrderNor(TreeNode *);                //非递归中序遍历

void postOrder(TreeNode *);                 //后序遍历

void layerOrder(TreeNode *);                //层序遍历

TreeNode* invertTree(TreeNode* root);       //翻转二叉树
int rangeSumBST(TreeNode* root, int L, int R);
#endif //TEST1_TREE_H

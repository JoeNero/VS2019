#include "Tree.h"
#include <queue>
#include <stack>

//插入数据
void insert(TreeNode *&pRoot, EleType val) {
    TreeNode *pNew = new TreeNode;
    pNew->val = val;
    if ((pRoot == nullptr)) {
        pRoot = pNew;
    } else {
        if (val < pRoot->val) {
            insert(pRoot->left, val);
        } else if (val > pRoot->val) {
            insert(pRoot->right, val);
        } else {

        }
    }
}

//前序遍历
void preOrder(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    cout << pRoot->val << " ";
    preOrder(pRoot->left);
    preOrder(pRoot->right);
}

//非递归前序遍历
void preOrderNor(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    TreeNode *p = pRoot;
    stack<TreeNode *> s;
    while (p || !s.empty()) {
        while (p) {
            cout << p->val << " ";
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

//中序遍历
void inOrder(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    inOrder(pRoot->left);
    cout << pRoot->val << " ";
    inOrder(pRoot->right);
}

//非递归中序号遍历
void inOrderNor(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    TreeNode *p = pRoot;
    stack<TreeNode *> s;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            cout << p->val << " ";
            p = p->right;
        }
    }
}

//后序遍历
void postOrder(TreeNode *pRoot) {
    if (pRoot == nullptr) {
        return;
    }
    postOrder(pRoot->left);
    postOrder(pRoot->right);
    cout << pRoot->val << " ";
}

//二叉树的层序遍历
void layerOrder(TreeNode *pRoot) {
    queue<TreeNode *> tree;
    tree.push(pRoot);
    while (!tree.empty()) {
        TreeNode *fro = tree.front();
        cout << fro->val << " ";       //输出头部元素
        tree.pop();                     //删除头部元素
        if (fro->left != nullptr) {
            tree.push(fro->left);       //加入左
        }
        if (fro->right != nullptr) {
            tree.push(fro->right);
        }
    }
}

//翻转二叉树
TreeNode *invertTree(TreeNode *root) {
    if (root == NULL) return NULL;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->right = left;
    root->left = right;
    return root;
}

//搜索指定两个节点之间的和
int rangeSumBST(TreeNode *root, int L, int R) {
    if (root == NULL) {
        return 0;
    }
    if (root->val < L) {
        return rangeSumBST(root->right, L, R);
    }
    if (root->val > R) {
        return rangeSumBST(root->left, L, R);
    }
    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

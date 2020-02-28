#include <iostream>
#include <vector>
#include <ctime>
#include "Tree.h"
#include <algorithm>

using namespace std;

void printVector(vector<int> &);

void treeTest();

int main() {
//    treeTest();
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    printVector(v);
    return 0;
}

void treeTest() {
    srand((unsigned) time(nullptr));
    TreeNode *pRoot = nullptr;
    for (int i = 0; i < 10; i++) {
        int temp = rand() % 10;
        insert(pRoot, temp);
    }

    cout << endl;
    cout << "遍历" << endl;
    postOrder(pRoot);

    invertTree(pRoot);
//
    cout << endl;
    cout << "翻转后" << endl;
    postOrder(pRoot);
}

void printVector(vector<int> &v) {
    if (v.empty()) {
        cout << "打印Vector为空";
        return;
    } else {
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }
    }
    cout << endl;
}
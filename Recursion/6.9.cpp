//
// Created by joseph on 14/10/2024.
//
//Binary Tree Checker

#include "iostream"

using namespace std;

//Binary Tree Defination

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
};

class tree {
public:
    tree(treeNode* rootNode) {
        _root = rootNode;
    }
    bool publicCheckHeap() {
        return privCheckHeap(_root);
    }


private:
    treeNode* _root;
    bool privCheckHeap(treeNode* rootPtr) {
        //Base Case, tree node is leaf
        if(rootPtr->right == nullptr && rootPtr->left == nullptr) {
            return true;
        }
        else { //Assuming that tree node always has both left and right subtree
            bool checkLeftSubTree = privCheckHeap(rootPtr->left);
            bool checkRightSubTree = privCheckHeap(rootPtr->right);
            bool subTreeGood = checkLeftSubTree && checkRightSubTree;

            return subTreeGood && (rootPtr->data > rootPtr->left->data) && (rootPtr->data > rootPtr->right->data);

        }
    }
};




int main() {

    treeNode* root = new treeNode;
    root->data = 100;

    treeNode* node2 = new treeNode;
    node2->data = 60;

    treeNode* node3 = new treeNode;
    node3->data = 50;

    treeNode* node4 = new treeNode;
    node4->data = 20;

    treeNode* node5 = new treeNode;
    node5->data = 100;

    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    node4->left = nullptr;
    node4->right = nullptr;

    node5->left = nullptr;
    node5->right = nullptr;
    node3->left = nullptr;
    node3->right = nullptr;

    tree testTree(root);

    cout << testTree.publicCheckHeap();

}
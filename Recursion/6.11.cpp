//
// Created by joseph on 15/10/2024.
//
//Binary Tree Insertion

//Posibly add checker to make sure value isnt already in tree, if so it cant be added

#include "iostream"

using namespace std;

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
};

class tree {
public:
    tree(treeNode *rootNode) {
        _root = rootNode;
    }

    void insertNode(treeNode* nodeToAdd, treeNode* rootPtr) {
        if(rootPtr == nullptr) {
            rootPtr = nodeToAdd;
            return;
        }
        if (rootPtr->left == nullptr && rootPtr->right == nullptr) {
            if (rootPtr->data > nodeToAdd->data)
                rootPtr->right = nodeToAdd;
            else {
                rootPtr->right = nodeToAdd;
            }
            return;
        }
        if (rootPtr->data > nodeToAdd->data) {
            insertNode(nodeToAdd, rootPtr->left);
        }
        if (rootPtr->data < nodeToAdd->data)
            insertNode(nodeToAdd, rootPtr->right);
//        int nodeValue = rootPtr->data;


    }


private:
    treeNode *_root;

};

int main() {
    treeNode* root = new treeNode;
    root->data = 100;

    treeNode* node2 = new treeNode;
    node2->data = 60;

    treeNode* node3 = new treeNode;
    node3->data = 150;

    treeNode* node4 = new treeNode;
    node4->data = 20;

    treeNode* node5 = new treeNode;
    node5->data = 80;

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

    treeNode* newNode = new treeNode;
    newNode->data = 90;

    testTree.insertNode(newNode, root);

    cout << node5->right->data;

    char word[9] = "********"


}
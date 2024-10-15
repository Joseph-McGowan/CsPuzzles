//
// Created by joseph on 15/10/2024.
//
//Binary Tree Checker

#include "iostream"
#include "algorithm"

using namespace std;

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
    bool publicCheckIsBinary() {
        return privCheckisBinary(_root);
    }

    int minValue(treeNode* subtree) {
        if (subtree == nullptr)
            return INT_MAX;
        else {
            return min({subtree->data,
                        minValue(subtree->left),
                        minValue(subtree->right)});
        }
    }

    int maxValue(treeNode* subtree) {
        if (subtree == nullptr)
            return INT_MIN;
        else{
            return max({subtree->data,
                        maxValue(subtree->left),
                        maxValue(subtree->right)});
        }
    }


private:
    treeNode* _root;
    bool privCheckisBinary(treeNode* rootPtr) {
        //Base Case, tree node is leaf node
        if(rootPtr->right == nullptr && rootPtr->left == nullptr) {
            return true;
        }
        else {
            bool leftSubTreeBinary = privCheckisBinary(rootPtr->left);
            bool rightSubTreeBinary = privCheckisBinary(rootPtr->right);

            bool subTreesBinary = leftSubTreeBinary && rightSubTreeBinary;

            bool isSubTreeBinary = (subTreesBinary && (rootPtr->data > maxValue(rootPtr->left)) && ( rootPtr->data < minValue(rootPtr->right)));
            return isSubTreeBinary;

        }

    }
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

    cout << testTree.publicCheckIsBinary();
}
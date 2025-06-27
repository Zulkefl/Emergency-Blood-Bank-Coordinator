#include <cstring>
#include <iostream>
#include "RedBlackTree.h"

void RedBlackTree::rotateLeft(Node*& node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left) rightChild->left->parent = node;
    rightChild->parent = node->parent;
    if (!node->parent) root = rightChild;
    else if (node == node->parent->left) node->parent->left = rightChild;
    else node->parent->right = rightChild;
    rightChild->left = node;
    node->parent = rightChild;
}

void RedBlackTree::rotateRight(Node*& node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right) leftChild->right->parent = node;
    leftChild->parent = node->parent;
    if (!node->parent) root = leftChild;
    else if (node == node->parent->left) node->parent->left = leftChild;
    else node->parent->right = leftChild;
    leftChild->right = node;
    node->parent = leftChild;
}

void RedBlackTree::fixInsert(Node* node) {
    while (node->parent && node->parent->isRed) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle && uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rotateRight(node->parent->parent);
            }
        }
        else {
            Node* uncle = node->parent->parent->left;
            if (uncle && uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rotateLeft(node->parent->parent);
            }
        }
    }
    root->isRed = false;
}

RedBlackTree::RedBlackTree() : root(NULL) {}

RedBlackTree::~RedBlackTree() {
    // Simple deletion (not fully balanced, for demo)
    // Add proper RB tree deletion if needed
}

void RedBlackTree::insert(const char* bloodType, int units) {
    Node* newNode = new Node(bloodType, units);
    if (!root) {
        root = newNode;
        root->isRed = false;
        return;
    }
    Node* current = root;
    Node* parent = NULL;
    while (current) {
        parent = current;
        if (strcmp(bloodType, current->bloodType) < 0)
            current = current->left;
        else if (strcmp(bloodType, current->bloodType) > 0)
            current = current->right;
        else {
            current->units += units; // Update existing
            delete newNode;
            return;
        }
    }
    newNode->parent = parent;
    if (strcmp(bloodType, parent->bloodType) < 0)
        parent->left = newNode;
    else
        parent->right = newNode;
    fixInsert(newNode);
}

int RedBlackTree::getUnits(const char* bloodType) const {
    Node* current = root;
    while (current) {
        int cmp = strcmp(bloodType, current->bloodType);
        if (cmp == 0) return current->units;
        current = (cmp < 0) ? current->left : current->right;
    }
    return 0;
}
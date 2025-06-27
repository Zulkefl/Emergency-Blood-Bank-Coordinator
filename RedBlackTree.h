#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include<cstring>
#include<cstddef>
#define NULL 0
class RedBlackTree {
private:
    struct Node {
        char bloodType[4];
        int units;
        bool isRed;
        Node* left;
        Node* right;
        Node* parent;
        Node(const char* bType, int u) {
            strncpy_s(bloodType, sizeof(bloodType), bType ? bType : "N/A", 3);
            bloodType[3] = '\0';
            units = (u > 0) ? u : 0;
            isRed = true;
            left = right = parent = NULL;
        }
    };
    Node* root;
    void rotateLeft(Node*& node);
    void rotateRight(Node*& node);
    void fixInsert(Node* node);
public:
    RedBlackTree();
    ~RedBlackTree();
    void insert(const char* bloodType, int units);
    int getUnits(const char* bloodType) const;
};

#endif
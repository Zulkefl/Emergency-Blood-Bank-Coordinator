#ifndef BLOODBANK_H
#define BLOODBANK_H

#include "RedBlackTree.h"

class BloodBank {
private:
    RedBlackTree stockTree;
public:
    BloodBank();
    void addStock(const char* bloodType, int units);
    int checkStock(const char* bloodType) const;
};

#endif
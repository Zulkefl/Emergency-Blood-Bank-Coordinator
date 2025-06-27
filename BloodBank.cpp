#include "BloodBank.h"

BloodBank::BloodBank() {}

void BloodBank::addStock(const char* bloodType, int units) {
    stockTree.insert(bloodType, units);
}

int BloodBank::checkStock(const char* bloodType) const {
    return stockTree.getUnits(bloodType);
}
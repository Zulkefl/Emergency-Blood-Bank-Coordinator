#include <cstring>
#include <iostream>
#include "Request.h"
#include "BloodBank.h"

Request::Request(const char* bType, int units) {
    strncpy_s(bloodType, sizeof(bloodType), bType ? bType : "N/A", 3);
    bloodType[3] = '\0';
    unitsNeeded = (units > 0) ? units : 1;
}

void Request::process(BloodBank* bank) {
    if (!bank) {
        std::cout << "Error: No blood bank available\n";
        return;
    }
    int stock = bank->checkStock(bloodType);
    if (stock >= unitsNeeded) {
        std::cout << "Request fulfilled for " << unitsNeeded << " units of " << bloodType << "\n";
    }
    else {
        std::cout << "Insufficient stock for " << unitsNeeded << " units of " << bloodType << "\n";
    }
}
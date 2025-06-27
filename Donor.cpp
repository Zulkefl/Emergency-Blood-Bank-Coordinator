#include <cstring>
#include <iostream> // Added for debug output
#include "Donor.h"

Donor::Donor(const char* bType, const char* date, const char* id) {
    strncpy_s(bloodType,sizeof(bloodType), bType ? bType : "N/A", 3);
    bloodType[3] = '\0'; // Ensure null termination
    std::cout << "Setting donationDate to: " << (date ? date : "NULL") << std::endl; // Debug
    strncpy_s(donationDate, date ? date : "N/A", 10); // Copy up to 10 chars for YYYY-MM-DD
    donationDate[10] = '\0'; // Ensure null termination
    std::cout << "Stored donationDate: " << donationDate << std::endl; // Debug
    strncpy_s(donorID, sizeof(donorID), id ? id : "N/A", 9);
    donorID[9] = '\0'; // Ensure null termination
}
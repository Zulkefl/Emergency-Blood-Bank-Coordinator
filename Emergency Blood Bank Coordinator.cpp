#include <iostream>
#include "Donor.h"
#include "BloodBank.h"
#include "Request.h"

int main() {
    BloodBank bank;

    int choice;
    do {
        std::cout << "\nEmergency Blood Bank Menu:\n";
        std::cout << "1. Add Donor (Info only, no storage)\n";
        std::cout << "2. Add Stock\n";
        std::cout << "3. Process Request\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input, please enter a number!\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }
        switch (choice) {
        case 1: {
            char id[10], bType[4], date[11]; // Changed to char array for YYYY-MM-DD
            std::cout << "Enter Donor ID: ";
            std::cin >> id;
            std::cout << "Enter Blood Type (e.g., A+, max 3 chars): ";
            std::cin >> bType;
            std::cout << "Enter Donation Date (YYYY-MM-DD): ";
            std::cin >> date; // Expect input like 2025-06-27
            Donor donor(bType, date, id);
            std::cout << "Donor added: ID " << donor.getDonorID() << ", Type " << donor.getBloodType()
                << ", Date " << (donor.getDonationDate() ? donor.getDonationDate() : "NULL") << "\n"; // Debug
            break;
        }
        case 2: {
            char bType[4];
            int units;
            std::cout << "Enter Blood Type: ";
            std::cin >> bType;
            std::cout << "Enter Units: ";
            std::cin >> units;
            bank.addStock(bType, units);
            std::cout << "Added " << units << " units of " << bType << " to stock\n";
            break;
        }
        case 3: {
            char bType[4];
            int units;
            std::cout << "Enter Blood Type: ";
            std::cin >> bType;
            std::cout << "Enter Units Needed: ";
            std::cin >> units;
            Request req(bType, units);
            req.process(&bank);
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
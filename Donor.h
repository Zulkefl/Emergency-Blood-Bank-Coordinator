#ifndef DONOR_H
#define DONOR_H

class Donor {
private:
    char bloodType[4]; // Fixed size for A+, B+, etc.
    char donationDate[11];
    char donorID[10];  // Fixed size for donor ID
public:
    Donor(const char* bType, const char* date, const char* id);
    ~Donor() {}
    const char* getBloodType() const { return bloodType; }
    const char* getDonationDate() const { return donationDate; }
    const char* getDonorID() const { return donorID; }
};

#endif

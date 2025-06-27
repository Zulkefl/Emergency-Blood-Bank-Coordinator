#ifndef REQUEST_H
#define REQUEST_H

class BloodBank;

class Request {
private:
    char bloodType[4];
    int unitsNeeded;
public:
    Request(const char* bType, int units);
    ~Request() {}
    const char* getBloodType() const { return bloodType; }
    int getUnitsNeeded() const { return unitsNeeded; }
    void process(BloodBank* bank);
};

#endif
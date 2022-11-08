#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

class People
{
private:
    string name;
    string health;
    int treatment;
    bool living;
public:
    People();
    People(string inName, string inHealth, int inTreatment);

    string getName();
    void setName(string inName);

    string getHealth();
    void setHealth(string inHealth);

    int getTreatment();
    bool setTreatment(int inTreatment);

    int getNumPeople();
    void setNumPeople(int inNumPeople);
};
#endif
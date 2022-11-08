#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include "Stats.h"
#include "People.h"
using namespace std;

class Events
{
private:
    int eventNum;
    int numPeople;
    Stats stats;
    People people[5];
public:
    Events();
    Events(int inNum, int inNumPeople, Stats inStats, People inPeople[]);
    
    int getEventNum();
    void setEventNum(int inNum);

    int getNumPeople();
    void setNumPeople(int inNumPeople);

    Stats getStats(); //loss of something like money
    void setStats(Stats inStats);

    People getPersonAt(int index); //person affected by event
    void setPersonAt(int index, People inPerson);
};
#endif
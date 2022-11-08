#include <iostream>
#include <stdlib.h>
#include <string>
#include "Stats.h"
#include "People.h"
#include "Events.h"

using namespace std;

Events::Events()
{
    eventNum = 0;
    numPeople = 5;
    stats.setBullets(0);
    stats.setCash(0);
    stats.setFood(0);
    for(int i = 0; i < numPeople; i++)
    {
        people[i].setName("");
        people[i].setHealth("");
        people[i].setTreatment(0);
    }
}
Events::Events(int inNum, int inNumPeople, Stats inStats, People inPeople[])
{
    eventNum = inNum;
    numPeople = inNumPeople;
    stats = inStats;
    for(int i = 0; i < numPeople; i++)
    {
        people[i] = inPeople[i];
    }
}

int Events::getEventNum()
{
    return eventNum;
}
void Events::setEventNum(int inNum)
{
    eventNum = inNum;
}

int Events::getNumPeople()
{
    return numPeople;
}
void Events::setNumPeople(int inNumPeople)
{
    numPeople = inNumPeople;
}

Stats Events::getStats() //counts the loss of something like food or money
{
    return stats;
}
void Events::setStats(Stats inStats)
{
    stats = inStats;
}

People Events::getPersonAt(int index) //person affected by event (sickness)
{
    return people[index];
}
void Events::setPersonAt(int index, People inPerson)
{
    people[index] = inPerson;
}
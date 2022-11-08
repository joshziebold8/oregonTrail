#ifndef STATS_H
#define STATS_H

#include <string>
using namespace std;

class Stats
{
private:
    int month;
    int day;
    int milesTravelled;
    int distToNext;
    int food;
    int bullets;
    int cash;
public:
    Stats();
    Stats(int inMonth, int inDay, int inMiles, int inDist, int inFood, int inBullets, int inCash);

    string getDate();
    double getMonth();
    void setMonth(int inMonth);
    double getDay();
    void setDay(int inDay);
    void addDays(int inDays);

    int getMiles();
    void setMiles(int inMiles);

    int getDist();
    void setDist(int inDist);

    int getFood();
    void setFood(int inFood);

    int getBullets();
    void setBullets(int inBullets);

    int getCash();
    void setCash(int inCash);
};
#endif
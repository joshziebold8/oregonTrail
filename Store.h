#ifndef STORE_H
#define STORE_H

#include <string>
using namespace std;

class Store
{
private:
    string storeName;
    double markup;
public:
    Store();
    Store(string inStoreName, double inMarkup);

    string getStoreName();
    void setStoreName(string inStoreName);

    double getMarkup();
    void setMarkup(double inMarkup);

    double getOxenPrice();
    double getFoodPrice();
    double getBulletsPrice();
    double getWagonPartsPrice();
    double getMedkitPrice();
};
#endif
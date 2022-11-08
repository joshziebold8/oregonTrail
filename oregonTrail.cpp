#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <cmath>
#include "People.h"
#include "Stats.h"
#include "Events.h"
#include "Store.h"

using namespace std;

bool puzzle()
{
    srand((unsigned)time(0));
    int guess;
    int num = rand() % 6 + 1;
    for(int i = 0; i < 3; i++)
    {
        cout << "Choose a number between 1 and 6:" << endl;
        cin >> guess;
        if(guess == num)
        {
            return true;
        }
    }
    return false;
}

Stats hunt(Stats stats, Events events)
{
    srand((unsigned)time(0));
    string animals;
    int numAnimals = 0, choice, initBullets = stats.getBullets(), foodEaten = 0, foodTot = 0;
    bool huntSuccess = false;
    //one day passes
    //0 miles travelled
    if(rand() % 100 + 1 <= 50) //rand animals appear, ask player if they want to hunt, if bullets < 10 hunt fails, if bullets > 10 then do a puzzle(guess)
    {
        animals += "Rabbit";
        numAnimals++;
        foodTot += 5;
        stats.setBullets(stats.getBullets() - 10);
    }
    if((rand() % 100 + 1) <= 25)
    {
        if(numAnimals > 0)
        {
            animals += ", Fox";
        }
        else
        {
            animals += "Fox";
        }
        numAnimals++;
        foodTot += 10;
        stats.setBullets(stats.getBullets() - 8);
    }
    if((rand() % 100 + 1) <= 15)
    {
        if(numAnimals > 0)
        {
            animals += ", Deer";
        }
        else
        {
            animals += "Deer";
        }
        numAnimals++;
        foodTot += 60;
        stats.setBullets(stats.getBullets() - 5);
    }
    if((rand() % 100 + 1) <= 7)
    {
        if(numAnimals > 0)
        {
            animals += ", Bear";
        }
        else
        {
            animals += "Bear";
        }
        numAnimals++;
        foodTot += 200;
        stats.setBullets(stats.getBullets() - 10);
    }
    if((rand() % 100 + 1) <= 5)
    {
        if(numAnimals > 0)
        {
            animals += ", Moose";
        }
        else
        {
            animals += "Moose";
        }
        numAnimals++;
        foodTot += 500;
        stats.setBullets(stats.getBullets() - 12);
    }
    if(stats.getBullets() < 0)
    {
        stats.setBullets(0);
    }
    if(numAnimals > 0)
    {
        while(choice < 1 || choice > 2)
        {
            cout << "You got lucky! You encountered a " << animals << " ! Do you want to hunt?" << endl;
            cout << "(1) Yes, (2) No" << endl;
            cin >> choice;
            if(choice == 1 && stats.getBullets() >= 10)
            {
                if(puzzle())
                {
                    cout << "You successfully hunted " << animals << " and gained " << foodTot << " pounds of food, but you used " << initBullets - stats.getBullets() << " bullets." << endl;
                    huntSuccess = true;
                }
                else
                {
                    cout << "You tried your hardest but, " << animals << " got away and you used " << initBullets - stats.getBullets() << " bullets." << endl;
                    huntSuccess = false;
                }
            }
            else if(choice == 1 && stats.getBullets() < 10)
            {
                cout << "You don't have enough ammunition to hunt." << endl;
                huntSuccess = false;
            }
            else if(choice == 2)
            {
                cout << "You chose not to hunt." << endl;
                huntSuccess = false;
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }
    }
    else
    {
        cout << "You encountered no animals." << endl;
    }
    if(!huntSuccess)
    {
        foodTot = 0;
    }
    cout << "How much food would you like to eat tonight?" << endl;
    cout << "2 pounds, 3 pounds, or 5 pounds" << endl;
    cin >> foodEaten;
    stats.setFood(stats.getFood() - (foodEaten * events.getNumPeople()) + foodTot);
    return stats;
}

int main()
{
    Stats stats;
    People people[5];
    Events events;
    Store fort;
    string x, sickness;

    bool goodDate = false, dead = false, lost = false;
    int distances[16], lineNum = 0, landmarkNum = 0, choice = 0, cashSpent = 0, num = 0, oxen = 0, wagonParts = 0, medKits = 0, lNum = 0, dNum = 0, a = 0;
    string landmarks[16];

    ifstream file; //read the milestones.txt and use it as a map.
    string line;
    file.open("milestones.txt");
    while(getline(file, line))
    {
        if(isalpha(line[0]))
        {
            landmarks[lNum] = line;
            lNum++;
        }
        else if(isdigit(line[0]))
        {
            distances[dNum] = stoi(line);
            dNum++;
        }
    }

    cout << "This game simulates a trip over the Oregon Trail from Independece, Missouri" << endl; //print out premise of the game.
    cout << " to Oregon City, Oregon in 1847. Your family of five will cover the 2040 mile" << endl;
    cout << " Oregon Trail in 5-6 months --- if you make it alive." << endl;

    cout << endl;
    cout << "Enter your first name:" << endl; //get input for people's names and put them in an array as people objects.
    cin >> x; people[0].setName(x);
    for(int i = 1; i <= 4; i++)
    {
        cout << "Enter the first name of companion number " << i << ":" << endl;
        cin >> x; people[i].setName(x);
    }

    stats.setMiles(0);
    stats.setDist(distances[0]);
    stats.setCash(1600);

    cout << endl;
    cout << "You already have a wagon and you have $1600 to spend on supplies for your trip." << endl;
    cout << "You decide to go to Smelly Joe's 'Oxen, Food, Guns, and More!' to buy supplies." << endl;
    while(choice != 5) //start looping the store menu with limits on how much money can be spent.
    {
        cout << endl;
        cout << "Welcome to Smelly Joe's 'Oxen, Food, Guns, and More!' What would you like to buy? (no refunds)" << endl;
        cout << "(1) Oxen, (2), Food, (3) Bullets, (4) More! or you can (5) Leave the store." << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "You need to spend at least $100 on oxen but no more than $200." << endl;
                cout << "Each yoke contains 2 oxen and costs $40." << endl;
                cout << "How many yokes would you like to purchase?" << endl;
                cin >> num;
                if(num > 5)
                {
                    cout << "You can't afford that many oxen, maybe buy less." << endl;
                }
                else if(num < 3)
                {
                    cout << "Are you trying to die? You're going to have to buy more oxen." << endl;
                }
                else
                {
                    cashSpent += num * 40;
                    oxen += num * 2;
                }
                break;
            case 2:
                cout << "You need at least 200lbs of food for each person, each priced at $0.50 per pound." << endl;
                cout << "How much food would you like to buy?" << endl;
                cin >> num;
                if(num < 1000)
                {
                    cout << "Unless you don't plan on eating, you're going to need more food than that." << endl;
                }
                else
                {
                    if((num / 2) > (1600 - cashSpent))
                    {
                        cout << "TOO POOR" << endl;
                    }
                    else
                    {
                        cashSpent += num / 2;
                        stats.setFood(stats.getFood() + num);
                    }
                }
                break;
            case 3:
                cout << "It's dangerous to go alone! Take this. *Joe gives you a gun*" << endl;
                cout << "You're going to need some bullets for that for hunting and fending off raiders." << endl;
                cout << "Costs $2 for a box of 20 bullets. How many boxes would you like to buy?" << endl;
                cin >> num;
                if((num * 2) > (1600 - cashSpent))
                {
                    cout << "TOO POOR" << endl;
                }
                else
                {
                    cashSpent += num * 2;
                    stats.setBullets(stats.getBullets() + (num * 20));
                }
                break;
            case 4:
                cout << "You're going to want some spare wagon parts just in case." << endl;
                cout << "Each wagon part is $20, how many would you like to buy?" << endl;
                cin >> num;
                if((num * 20) > (1600 - cashSpent))
                {
                    cout << "TOO POOR" << endl;
                }
                else
                {
                    cashSpent += num * 20;
                    wagonParts += num;
                }
                cout << "You also might want to buy some medkits to deal with sickness." << endl;
                cout << "Each medkit will cast you $25, how many do you want?" << endl;
                cin >> num;
                if ((num * 25) > (1600 - cashSpent))
                {
                    cout << "TOO POOR" << endl;
                }
                else
                {
                    cashSpent += num * 25;
                    medKits += num;
                }
                break;
            case 5:
                cout << "Thanks for shopping at Smelly Joe's, good luck on your trip!" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
        cout << "You spent $" << cashSpent << " which means you have $" << 1600 - cashSpent << " remaining." << endl;
    }
    stats.setCash(stats.getCash() - cashSpent);

    cout << endl;
    cout << "You can choose to start on the suggested date: 03/28/1847 or choose your own date between 03/01/1847 and 05/01/1847" << endl; //player decides when to depart, put this info into stats.
    cout << "Keep in mind you can arrive in Oregon city no later than 11/30/1847." << endl;
    while(!goodDate)
    {
        cout << "What month would you like to start in?" << endl;
        cin >> num;
        if(num <= 5 && num >= 3)
        {
            stats.setMonth(num);
            cout << "What day would you like to start on?" << endl;
            cin >> num;
            if(stats.getMonth() == 4)
            {
                if(num <= 30 && num >= 1)
                {
                    stats.setDay(num);
                    goodDate = true;
                }
                else
                {
                    cout << "You must choose a valid day." << endl;
                }
            }
            else
            {
                if(num <= 31 && num >= 1)
                {
                    stats.setDay(num);
                    goodDate = true;
                }
                else
                {
                    cout << "You must choose a valid day." << endl;
                }
            }
        }
        else
        {
            cout << "You must choose a valid month." << endl;
        }
    }
    if(goodDate)
    {
        cout << "You have chosen to depart on " << stats.getDate() << " good luck!" << endl;
    }

    //start core gameplay loop.
    choice = 0;
    while(!(stats.getMonth() == 11 && stats.getDay() >= 30) && !lost)
    {

        if(stats.getFood() < 0)
        {
            cout << "OH NO! You are out of food, not much you can do now except die." << endl;
            lost = true;
            break;
        }

        cout << endl;
        cout << "The date is " << stats.getDate() << endl; //print out stats for beginning of the turn.
        cout << "You have travelled " << stats.getMiles() << " miles." << endl;
        cout << "You are " << stats.getDist() << " miles away from " << landmarks[landmarkNum] << endl;
        cout << "You have " << stats.getFood() << " pounds of food remaining." << endl;
        cout << "You have " << stats.getBullets() << " bullets remaining." << endl;
        cout << "You have $" << stats.getCash() << " remaining." << endl;

        cout << "You can either (1) Rest, (2) Continue on the trail, (3) Hunt, or (4) Give up" << endl; //player chooses 1. rest, 2. continue, 3. hunt.
        cin >> choice;
        //int food = stats.getFood();
        switch(choice)
        {
            case 1: //1. rand 1-3 days pass, 0 miles travelled, 3 food per person per day.
                int x; x = rand() % 3 + 1;
                cout << "You choose to rest for " << x << " days with your remaining party." << endl;
                stats.addDays(x);
                stats.setFood(stats.getFood() - (3 * events.getNumPeople() * x));
                break;
            case 2: //2. 14 days pass, rand 70-140 miles travelled, 3 food per person per day.
                int y; y = rand() % 71 + 70;
                cout << endl;
                if(y < stats.getDist())
                {
                    cout << "You choose to continue on the trail." << endl;
                    cout << "You and your team travel " << y << " miles." << endl;
                    stats.addDays(14);
                    stats.setFood(stats.getFood() - (3 * events.getNumPeople() * 14));
                    stats.setMiles(stats.getMiles() + y);
                    stats.setDist(stats.getDist() - y);
                    break;
                }
                else
                {
                    fort.setStoreName(landmarks[landmarkNum]);
                    landmarkNum++;
                    stats.setMiles(stats.getDist() + stats.getMiles());
                    stats.setDist(distances[landmarkNum] - stats.getMiles());
                    if(landmarks[landmarkNum - 1][0] == 'F')
                    {
                        cout << fort.getStoreName() << endl;
                        cout << "Would you like to buy some stuff here? (1) Yes, (2) No." << endl;
                        cin >> choice;
                        switch(choice)
                        {
                            case 1:
                                fort.setMarkup(.5);
                                cashSpent = 0;
                                    while(choice != 5) //start looping the store menu with limits on how much money can be spent.
                                    {
                                        cout << endl;
                                        cout << "What would you like to buy? (no refunds)" << endl;
                                        cout << "(1) Oxen, (2), Food, (3) Bullets, (4) More! or you can (5) Leave the store." << endl;
                                        cin >> choice;
                                        switch(choice)
                                        {
                                            case 1:
                                                cout << "Each yoke contains 2 oxen and costs $" << 40 + 40*fort.getMarkup() << "." << endl;
                                                cout << "How many yokes would you like to purchase?" << endl;
                                                cin >> num;
                                                if((num * (40 + 40*fort.getMarkup())) > stats.getCash())
                                                {
                                                    cout << "You can't afford that many oxen, maybe buy less." << endl;
                                                }
                                                else
                                                {
                                                    cashSpent += num * (40 + 40*fort.getMarkup());
                                                    oxen += num * 2;
                                                }
                                                break;
                                            case 2:
                                                cout << "Food here is priced at $" << .5 + .5*fort.getMarkup() << " per pound."<< endl;
                                                cout << "How much food would you like to buy?" << endl;
                                                cin >> num;
                                                if((num * (.5 + .5*fort.getMarkup()) > stats.getCash()))
                                                {
                                                    cout << "You don't have enough money for that much food." << endl;
                                                }
                                                else
                                                {
                                                    cashSpent += (num * (.5 + .5*fort.getMarkup()));
                                                    stats.setFood(stats.getFood() + num);
                                                }
                                                break;
                                            case 3:
                                                cout << "Bullets costs $" << (2 + 2*fort.getMarkup()) << " for a box of 20 bullets. How many boxes would you like to buy?" << endl;
                                                cin >> num;
                                                if((num * (2 + 2*fort.getMarkup())) > stats.getCash())
                                                {
                                                    cout << "You can't afford that many bullets." << endl;
                                                }
                                                else
                                                {
                                                    cashSpent += (num * (2 + 2*fort.getMarkup()));
                                                    stats.setBullets(stats.getBullets() + (num * 20));
                                                }
                                                break;
                                            case 4:
                                                cout << "Each wagon part is $20, how many would you like to buy?" << endl;
                                                cin >> num;
                                                if((num * (20 + 20*fort.getMarkup())) > stats.getCash())
                                                {
                                                    cout << "You cant afford that many wagon parts." << endl;
                                                }
                                                else
                                                {
                                                    cashSpent += (num * (20 + 20*fort.getMarkup()));
                                                    wagonParts += num;
                                                }
                                                cout << "Each medkit will cast you $25, how many do you want?" << endl;
                                                cin >> num;
                                                if ((num * (25 + 25*fort.getMarkup())) > stats.getCash())
                                                {
                                                    cout << "TOO POOR" << endl;
                                                }
                                                else
                                                {
                                                    cashSpent += num * (25 + 25*fort.getMarkup());
                                                    medKits += num;
                                                }
                                                break;
                                            case 5:
                                                cout << "Thanks for shopping with us, good luck on your trip!" << endl;
                                                break;
                                            default:
                                                cout << "Invalid input" << endl;
                                                break;
                                        }
                                        cout << "You spent $" << cashSpent << " which means you have $" << stats.getCash() - cashSpent << " remaining." << endl;
                                    }
                                    stats.setCash(stats.getCash() - cashSpent);
                                break;
                            case 2:
                                cout << "You decide not to buy any extra supplies." << endl;
                                break;
                            default:
                                cout << "Invalid input" << endl;
                                break;
                        }
                    }
                    else
                    {
                        cout << fort.getStoreName() << endl;
                        cout << "This seems like a good place to rest." << endl;
                        break;
                    }
                }
                break;
            case 3:
                stats.addDays(1);
                stats = hunt(stats, events);
                break;
            case 4:
                cout << "Well you tried, but it's time to go home, thanks for playing." << endl;
                lost = true;
                cout << endl;
                cout << "The date is " << stats.getDate() << endl;
                cout << "You have travelled " << stats.getMiles() << " miles." << endl;
                cout << "You are " << stats.getDist() << " miles away from " << landmarks[landmarkNum] << endl;
                cout << "You have " << stats.getFood() << " pounds of food remaining." << endl;
                cout << "You have " << stats.getBullets() << " bullets remaining." << endl;
                cout << "You have $" << stats.getCash() << " remaining." << endl;
                return 0;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
        if((rand() % 100 + 1) < 40) //40% chance misfortune, random 1. sickness, 2. oxen death, 3. wagon breaks
        {
            switch(rand() % 3 + 1)
            {
                case 1:
                    int x; x = rand() % events.getNumPeople();
                    switch(rand() % 5 + 1)
                    {
                        case 1:
                            sickness = "Dysentery";
                            break;
                        case 2:
                            sickness = "The Flu";
                            break;
                        case 3:
                            sickness = "Finals Fever";
                            break;
                        case 4:
                            sickness = "Diarrhea";
                            break;
                        case 5:
                            sickness = "The Plague";
                            break;
                    }
                    cout << "OH NO! " << people[x].getName() << " has " << sickness << "." << endl;
                    cout << "What will you do? (1) Use Medkit, (2) Rest, (3) Press On!" << endl; //choose how to deal with sick person
                    cin >> choice;
                    if(people[x].setTreatment(choice))
                    {
                        cout << "Nice! " << people[x].getName() << " survived " << sickness << " and is ready to move on!" << endl;
                    }
                    else
                    {
                        if(x == 0)
                        {
                            cout << "Oh no YOU died from " << sickness << ". Guess that's the end of your trip." << endl;
                            lost = true;
                        }
                        else
                        {
                            cout << "Oh no " << people[x].getName() << " died from " << sickness << ", at least it wasn't you." << endl;
                            events.setNumPeople(events.getNumPeople() - 1);
                            for(int i = x; i < events.getNumPeople(); i++)
                            {
                                people[i] = people[i + 1];
                            }
                        }
                    }
                    break;
                case 2:
                    cout << "OH NO! Your wagon broke!" << endl;
                    wagonParts--;
                    if(wagonParts > 0)
                    {
                        cout << "You repair the wagon and move on." << endl;
                    }
                    else
                    {
                        cout << "You can't repair the wagon, maybe you should have bought more parts." << endl;
                        lost = true;
                    }
                    break;
                case 3:
                    cout << "OH NO! One of your oxen has died" << endl;
                    oxen--;
                    if(oxen > 0)
                    {
                        cout << "You are lucky you still have " << oxen << " oxen left." << endl;
                    }
                    else
                    {
                        cout << "You're out of oxen, and unless you plan on pushing the wagon, your trip is over." << endl;
                        lost = true;
                    }
                    break;
            }
        }
        if((rand() % 2040 + 1) < (stats.getMiles() / 2)) //finally there is a chance raiders will attack, player can 1. run, 2. attack, 3. surrender.
        {
            cout << "Uh oh, what's that sound?" << endl;
            cout << "IT'S RAIDERS YOU HAVE TO THINK FAST, DO YOU (1) RUN, (2) FIGHT, (3) SURRENDER." << endl;
            cin >> choice;
            switch(choice)
            {
                case 1: //1. lose 1 oxen, 100 food, and 1 wagon part
                    oxen--;
                    stats.setFood(stats.getFood() - 100);
                    wagonParts--;
                    break;
                case 2: //2. puzzle(guess), if you fail lose 25% cash and 50 bullets, if you win gain 50 bullets and 50 food.
                    if(puzzle())
                    {
                        cout << "NICE FIGHTING, you win the battle and gain the spoils of war." << endl;
                        stats.setFood(stats.getFood() + 50);
                        stats.setBullets(stats.getBullets() + 50);
                    }
                    else
                    {
                        cout << "You fought valiantly but you lost...  Guess it was just a waste of bullets." << endl;
                        stats.setBullets(stats.getBullets() - 50);
                        if(stats.getBullets() < 0)
                        {
                            stats.setBullets(0);
                        }
                        stats.setCash(stats.getCash() - (stats.getCash() / 4));
                    }
                    break;
                case 3: //3. lose 25% cash.
                    cout << "I guess you just aren't tough enough or fast enough to run or fight." << endl;
                    stats.setCash(stats.getCash() - (stats.getCash() / 4));
                    break;
            }
        } //turn ends
    }
    if(lost) //you lose
    {
        if(stats.getFood() < 0) stats.setFood(0);
        cout << endl;
        cout << "The date is " << stats.getDate() << endl;
        cout << "You have travelled " << stats.getMiles() << " miles." << endl;
        cout << "You are " << stats.getDist() << " miles away from " << landmarks[landmarkNum] << endl;
        cout << "You have " << stats.getFood() << " pounds of food remaining." << endl;
        cout << "You have " << stats.getBullets() << " bullets remaining." << endl;
        cout << "You have $" << stats.getCash() << " remaining." << endl;
    }
    else //you win
    {
        cout << "'Did you make it to Oregon City?'  'Yes'  'What did it cost?'  '$" << 1600 - stats.getCash() << "'" << endl;
        cout << endl;
        cout << "The date is " << stats.getDate() << endl;
        cout << "You have travelled " << stats.getMiles() << " miles." << endl;
        cout << "You are " << stats.getDist() << " miles away from " << landmarks[landmarkNum] << endl;
        cout << "You have " << stats.getFood() << " pounds of food remaining." << endl;
        cout << "You have " << stats.getBullets() << " bullets remaining." << endl;
        cout << "You have $" << stats.getCash() << " remaining." << endl;
    }
    return 0;
}
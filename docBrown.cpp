#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void getInfo(int &choice, int &sHours, int &sMinutes, int &callTime);
double calcCost(int &choice, int &sHours, int &sMinutes, int &callTime);
void displayCost(int &choice, int &sHours, int &sMinutes, int &callTime);

int main()
{
    int choice, sHours, sMinutes, callTime;
    getInfo(choice, sHours, sMinutes, callTime);
    calcCost(choice, sHours, sMinutes, callTime);
    displayCost(choice, sHours, sMinutes, callTime);
    return 0;
}

void getInfo(int &choice, int &sHours, int &sMinutes, int &callTime)
{
    cout << "PHONE BOOTH" << endl << endl
         << "1. Call destined to the United States" << endl
         << "2. Call destined to Mexico or Canada" << endl
         << "3. Call destined to another country" << endl
         << "4. Quit" << endl << endl
         << "Please make a selection: ";
    cin >> choice;
    if(choice != 4)
    {
        cout << endl << endl;
        cout << "=========================================";
        cout << endl << endl;
        cout << "When will your call start?" << endl;
        cout << "Please format entry as so HH:MM" ;
        cin >> sHours;
        cin.ignore();
        cin >> sMinutes;
        cout << "How long will the call be in minutes? ";
        cin >> callTime;
    }
    else
    {
        exit(0);
    }
}

double calcCost(int &choice, int &sHours, int &sMinutes, int &callTime)
{
    const int US = 1, mexCan = 2, other = 3, quit = 4;
    double cost1, cost2, cost3, earlyR = .12, midR = .55, lateR = .35;

    int hourMin = sHours*60 + sMinutes;
    int earlyMins = 420 - hourMin;
    int midMins = 1140 - hourMin;
    int lateMins = 1439 - hourMin;


    if(choice == US)
    {
        if(sHours<=6 && sMinutes<60)
        {
            cost1 = earlyMins * earlyR;
            if(callTime < earlyMins)
            {
                cost2 = callTime*earlyR;
                return cost2;
            }
            else if(callTime - earlyMins > 0 && callTime - earlyMins <= 720)
            {
                cost2 = cost1 + (callTime - earlyMins)* midR;
                return cost2;
            }
            else if(callTime - earlyMins > 0)
            {
                cost3 = cost1 + (midMins- (earlyMins+1))* midR;
                cost2 = (cost3 + (callTime - (midMins + 1)) * lateR);
                return cost2;
            }
            else
                return cost1;

        }

        else if(sHours>= 7 && sHours<= 19)
        {
            cost1 = midMins * midR;
            if(callTime< midMins)
            {
                cost2 = callTime* midR;
                return cost2;
            }
            else if(callTime - midMins > 0)
            {
                cost2 = cost1 + (callTime - midMins) * lateR;
                return cost2;
            }
            else
                return cost1;

        }
        else if(sHours>=19 && sMinutes<60)
        {
            cost2 = callTime * lateR;
            return cost2;
        }
    }

    else if(choice == mexCan)
    {
        if(sHours<=6 && sMinutes<60)
        {
            cost1 = earlyMins * (earlyR*1.50);
            if(callTime < earlyMins)
            {
                cost2 = callTime * (earlyR*1.50);
                return cost2;
            }
            else if(callTime - earlyMins > 0 && callTime - earlyMins <= 720)
            {
                cost2 = cost1 + (callTime - earlyMins)* (midR*1.50);
                return cost2;
            }
            else if(callTime - earlyMins > 0)
            {
                cost3 = (earlyMins*earlyR) + (midMins- (earlyMins+1))* midR;
                cost2 = (cost3 + (callTime - (midMins + 1)) * lateR);
                return cost2*1.5;
            }


        }

        else if(sHours>= 7 && sHours<= 19)
        {
            cost1 = midMins * (midR*1.50);
            if(callTime < midMins)
            {
                cost2 = callTime * (midR*1.50);
                return cost2;
            }
            else if(callTime - midMins > 0)
            {
                cost2 = cost1 + (callTime - midMins) * (lateR*1.50);
                return cost2;
            }

        }
        else if(sHours>=19 && sMinutes<60)
        {
            cost2 = callTime * (lateR*1.50);
            return cost2;
        }
    }

    else if(choice == other)
    {
        if(sHours<=6 && sMinutes<60)
        {
            cost1 = earlyMins * (earlyR*2.25);
            if(callTime < earlyMins)
            {
                cost2 = callTime * (earlyR*2.25);
                return cost2;
            }
            else if(callTime - earlyMins > 0 && callTime - earlyMins <= 720)
            {
                cost2 = cost1 + (callTime - earlyMins)* (midR*2.25);
                return cost2;
            }
            else if(callTime - earlyMins > 0)
            {
                cost3 = (earlyMins*earlyR) + (midMins- (earlyMins+1))* midR;
                cost2 = (cost3 + (callTime - (midMins + 1)) * lateR);
                return cost2*2.25;
            }

        }

        else if(sHours>= 7 && sHours<= 19)
        {
            cost1 = midMins * (midR*2.25);
            if(callTime < midMins)
            {
                cost2 = callTime * (midR*2.25);
                return cost2;
            }
            else if(callTime - midMins > 0)
            {
                cost2 = cost1 + (callTime - midMins) * (lateR*2.25);
                return cost2;
            }

        }
        else if(sHours>=19 && sMinutes<60)
        {
            cost2 = callTime * (lateR*2.25);
            return cost2;
        }
    }

    else if(choice == quit)
    {
        exit(0);
    }
    return 0;
}

void displayCost(int &choice, int &sHours, int &sMinutes, int &callTime)
{
    double cost = calcCost(choice, sHours, sMinutes, callTime);
    cout << cost;
}

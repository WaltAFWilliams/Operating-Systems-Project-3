#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
static int table[2000][3], arrivalTimes[2000];

void populateTables()
{
    srand(time(NULL));

    std:: random_device rd;
    std:: mt19937 gen(rd());
    std:: uniform_int_distribution<> arrivalDistr(1, 1250);
    std:: uniform_int_distribution<> burstDistr(1, 750);
    std:: uniform_int_distribution<> pidDistr(1000, 9999);
    int pid, arrivalTime, burstTime;
    
    for (int i = 0; i < sizeof(table)/sizeof(table[0]); i++)
    {
        // generate random process id, arrival time, and burst time
        pid = pidDistr(gen);
        arrivalTime = arrivalDistr(gen);
        burstTime = burstDistr(gen);
        table[i][0] = pid;
        table[i][1] = arrivalTime;
        arrivalTimes[i] = arrivalTime;
        table[i][2] = burstTime;
    }
}


void swapArray(int processes[2000][3], int index1, int index2){
    int temp = 0;
    for (int n = 0; n < 3; n++)
    {
        // cout << "Before Swap: " << endl << "Item 1: " << processes[index1][n] << endl << "Item 2: " << processes[index2][n] << endl;
        temp = processes[index1][n];
        processes[index1][n] = processes[index2][n];
        processes[index2][n] = temp;
        // cout << "After swap: " << endl << "Item 1: " << processes[index1][n] << endl << "Item 2: " << processes[index2][n] << endl;
    }
    
}

float calculateAverageTime()
{
    int time = table[0][2]; // Set initial time to burst time of first process
    float totalWait = 0.0;
    for (int i = 1; i < sizeof(table)/sizeof(table[0]); i++)
    {
        int waitTime = time - table[i][1];
        totalWait += waitTime;
        time += table[i][2];
    }

    return totalWait / 2000.0;
}

void sortByArrivalTime()
{
    for (int i = 0; i < sizeof(table)/sizeof(table[0]); i++)
    {
        int arrivalTime = arrivalTimes[i];
            for (int j = i+1 ; j < sizeof(table)/sizeof(table[0]); j++)
            {
                if (table[j][1] == arrivalTime)
                {
                    swapArray(table, i, j);
                    break;
                }
            }
    }
}


int main(int argc, char const *argv[])
{
    populateTables();
    sort(arrivalTimes, arrivalTimes + 2000);
    sortByArrivalTime();
    for (int p = 0; p < sizeof(table)/sizeof(table[0]); p++)
    {   
        cout << table[p][1]   << endl;
    }
    
    return 0;
}




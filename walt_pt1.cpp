#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>

/*#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
static float numInCirc = 0;
static float totalNum = 0;
static float pi = 0.0;
void generate_points()
{
    float x,y, distance;
    for (int n = 0; n < 500; n++)
    {  
        x = (float)rand()/RAND_MAX;
        y = (float)rand()/RAND_MAX;
        distance = sqrt(x*x + y*y);
        
        if (distance <= 1)
        {
            numInCirc++;
        }
        totalNum++;
    }
}
int main()
{
    int i;
    pthread_t thrdID;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        pthread_create(&thrdID, NULL, (void *)generate_points, NULL);
        pi = 4 * (numInCirc / totalNum);
        printf("Value of PI after thread %d is: %.4f\n", i+1, pi);
        pthread_join(thrdID, NULL);
    }
    return 0;
}*/

using namespace std;
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int table[2000][3];

    std::random_device rd;
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
        table[i][2] = burstTime;
    }

    // for (int n = 0; n < 5; n++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         /* code */
    //         std::cout << table[n][j] << " ";
    //     }
    //     std::cout << std::endl;
        
    // }
    
    
    return 0;
}



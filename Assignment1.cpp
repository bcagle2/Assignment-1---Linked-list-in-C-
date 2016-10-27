#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <sys/time.h>

using namespace std;

struct node
{
    int ranInt;
    node *next;
};

int main(int argc, char *argv[])
{
    stringstream inString;      /* convert char to int (number of numbers) */
    inString << argv[1];
    int numInList;
    inString >> numInList;

    stringstream searchString;  /* convert number to search to int */
    searchString << argv[2];
    int num2Search;
    searchString >> num2Search;

    int searchVal[32767];


    srand(25);          /* Use a seed so random numbers will be */
                        /* the same for each test */

    node *first;        /* first in the list */
    node *current;      /* current position in the list */

    first = new node;
    first->next = 0;    /* set next to 0 because there is no next */
    first->ranInt = rand();
    current = first;

   
    for(int i=1; i<numInList; i++)
    {
        node *newNum;
        newNum = new node;
        newNum->ranInt = rand();
        newNum->next = 0;
        current->next = newNum;
        current = newNum;

    } /* end of for loop */

    for(int i=0; i<num2Search; i++)
    {
        searchVal[i] = rand();
    } /* end of for loop */

    /*time_t startTime,endTime;*/
    timeval curTime;
    gettimeofday(&curTime, NULL);
    double startTime = curTime.tv_sec + (curTime.tv_usec / 1000000.0);


    cout << "Starting our loop" << endl;

    /* now, loop through and do the searching */
    /*time(&startTime);*/

    /* Search for the numbers */
    for(int i=0; i<num2Search; i++)
    {
        /*cout << "i is: " << i << " & value is: " << searchVal[i] << endl;*/
        current = first;
        for(int j=0; j<numInList; j++)
        {
            /*cout << "  j is: " << j << " & ranInt is: " << current->ranInt << endl;*/
            if(searchVal[i] == current->ranInt)
            {
                break;
            }
            if(current->next == 0)
            {
                break;
            }
            if(current->next != 0)
            {
                current = current->next;
            }
        }   /* end of loop on the list j */

    }   /* end of searching loop i */

    /*time(&endTime);
    double elapse = difftime(endTime,startTime);*/
    gettimeofday(&curTime, NULL);
    double endTime = curTime.tv_sec + (curTime.tv_usec / 1000000.0);
    double elapse = endTime - startTime;
    double timePerSearch = elapse / num2Search;

    cout << "End: " << endTime << " Start: " << startTime << endl;

    cout << "I searched " << numInList << " numbers for "
        << num2Search << " numbers and it took "
        << elapse << " seconds" << " which is " 
        << timePerSearch << " time per search" << endl;



} /* end of main */


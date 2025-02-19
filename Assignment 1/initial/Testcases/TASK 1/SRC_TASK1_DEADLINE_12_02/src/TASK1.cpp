#include "TASK1.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;
const int MAX_LINE_LENGTH = 100;

// Task 1
const int NUM_RANK = 17;
const int RANK_WEIGHT[NUM_RANK] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 15, 18, 20, 30, 40, 50, 70};

int gatherForces(int LF1[], int LF2[])
{
    // TODO: Implement this function
    for(int i = 0; i < 17; i++)
    {
        if(LF1[i] > 1000) LF1[i] = 1000;
        if(LF1[i] < 0) LF1[i] = 0;
    }
    for(int i = 0; i < 17; i++)
    {
        if(LF2[i] > 1000) LF2[i] = 1000;
        if(LF2[i] < 0) LF2[i] = 0;
    }

    int LF1Strength = 0, LF2Strength = 0;

    for(int i = 0; i < NUM_RANK; i++)
    {
        LF1Strength += LF1[i]*RANK_WEIGHT[i];
    }
    for(int i = 0; i < NUM_RANK; i++)
    {
        LF2Strength += LF2[i]*RANK_WEIGHT[i];
    }

    return LF1Strength + LF2Strength;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
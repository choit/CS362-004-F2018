/*******************************************************************************
** Title: Assignment 3 - unittest4.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "whoseTurn" function by checking the following:
**              1. Verify that it is the Player 0's turn first.
**              2. Verify that it is the Player 1's turn second.
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTFUNC "whoseTurn"

int main(int argc, char** argv) {
    int seed       = 1000;
    int numPlayers = 2;
    struct gameState G;
    int k[10] = { adventurer, embargo, village, minion, mine,
                  cutpurse,   sea_hag, tribute, smithy, council_room };

    initializeGame(numPlayers, k, seed, &G);

    printf("\n----------------- TESTING FUNCTION: %s ----------------\n", TESTFUNC);

    printf("\nTEST 1: Check If Player 0's Turn\n");
    if (whoseTurn(&G) == 0)
        printf("Passed: ");
    else
        printf("Failed: ");

    printf("Actual = %d, Expected = %d\n", G.whoseTurn, 0);

    endTurn(&G);

    printf("\nTEST 2: Check If Player 1's Turn\n");
    if (whoseTurn(&G) == 1)
        printf("Passed: ");
    else
        printf("Failed: ");

    printf("Actual = %d, Expected = %d\n", G.whoseTurn, 1);

    printf("\n------------ FINISHED TESTING FUNCTION: %s ------------\n\n", TESTFUNC);
}
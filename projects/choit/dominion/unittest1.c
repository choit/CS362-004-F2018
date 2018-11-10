/*******************************************************************************
** Title: Assignment 3 - unittest1.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "buycard" function by checking the following:
**              1. Verify card purchase with no coins remaining.
**                 (Pass = failure purchasing).
**              2. Verify card purchase with no supply remaining.
**                 (Pass = failure purchasing).
**              3. Verify card purchase with insufficient funds.
**                 (Pass = failure purchasing).
**              4. Verify card purchase during valid purchase condition.
**              4. Verify card purchase during invalid purchase condition.
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTFUNC "buyCard"

int main(int argc, char** argv) {
    int supplyPos  = 0;
    int seed       = 1000;
    int numPlayers = 3;
    struct gameState G;
    int k[10] = { adventurer, embargo, village, minion, mine,
                  cutpurse,   sea_hag, tribute, smithy, council_room };

    initializeGame(numPlayers, k, seed, &G);

    printf("\n----------------- TESTING FUNCTION: %s ----------------\n",
           TESTFUNC);

    printf("\nTEST 1: No Coins Remaining\n");

    G.numBuys             = 0;
    G.supplyCount[estate] = 1;
    supplyPos             = 1;

    if (buyCard(supplyPos, &G) == -1)
        printf("Passed: Purchase was unsuccessful\n");
    else
        printf("Failed: A purchase was made without coins\n");

    endTurn(&G);

    printf("\nTEST 2: No Supply Remaining\n");

    G.numBuys             = 2;
    G.supplyCount[estate] = 0;
    supplyPos             = 1;

    if (buyCard(supplyPos, &G) == -1)
        printf("Passed: Purchase was unsuccessful\n");
    else
        printf("Failed: A purchase was with no supply left\n");

    endTurn(&G);

    printf("\nTEST 3: Insufficient Funds\n");

    G.numBuys            = 1;
    G.supplyCount[duchy] = 1;
    supplyPos            = 2;

    if (buyCard(supplyPos, &G) == -1)
        printf("Passed: Purchase was unsuccessful\n");
    else
        printf("Failed: A purchase was with insufficient coins\n");

    endTurn(&G);

    printf("\nTEST 4: Valid Purchase Condition\n");

    G.numBuys             = 4;
    G.supplyCount[estate] = 1;
    supplyPos             = 1;

    if (buyCard(supplyPos, &G) == 0)
        printf("Passed: Purchase was made successfully\n");
    else
        printf("Failed: Purchase was unsuccessful\n");

    endTurn(&G);

    printf("\nTEST 5: Invalid Purchase Condition\n");

    G.numBuys            = -21;
    G.supplyCount[duchy] = 1;
    supplyPos            = -1;

    if (buyCard(supplyPos, &G) == -1)
        printf("Passed: Purchase was unsuccessful\n");
    else
        printf("Failed: Purchase was made successfully\n");

    endTurn(&G);

    printf("\n------------ FINISHED TESTING FUNCTION: %s ------------\n\n",
           TESTFUNC);
}
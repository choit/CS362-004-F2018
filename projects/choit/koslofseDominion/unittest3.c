/*******************************************************************************
** Title: Assignment 3 - unittest3.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "updatecoins" function by checking the
**              following:
**              1. Check current coin of the state with Copper coin.
**              2. Check current coin of the state with Silver coin.
**              3. Check current coin of the state with Gold coin.
**              4. Check current coin of the state with Gold coin with Bonus.
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTFUNC "updateCoins"

int main(int argc, char** argv) {
    int bonus      = 0;
    int seed       = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G;
    int k[10] = { adventurer, embargo, village, minion, mine,
                  cutpurse,   sea_hag, tribute, smithy, council_room };

    initializeGame(numPlayers, k, seed, &G);
    G.coins = 0;

    printf("\n----------------- TESTING FUNCTION: %s ----------------\n",
           TESTFUNC);

    printf("\nTEST 1: Check Copper Coin\n");

    G.hand[thisPlayer][0] = copper;
    updateCoins(thisPlayer, &G, bonus);
    if (G.coins == 4) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", G.coins, 4);
    G.coins = 0;

    printf("\nTEST 2: Check Silver Coin\n");

    G.hand[thisPlayer][0] = silver;
    updateCoins(thisPlayer, &G, bonus);
    if (G.coins == 5) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", G.coins, 5);
    G.coins = 0;

    printf("\nTEST 3: Check Gold Coin\n");

    G.hand[thisPlayer][0] = gold;
    updateCoins(thisPlayer, &G, bonus);
    if (G.coins == 6) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", G.coins, 6);
    G.coins = 0;

    printf("\nTEST 4: Check Gold Plus Bonus\n");

    G.hand[thisPlayer][0] = gold;
    bonus                 = 1;

    updateCoins(thisPlayer, &G, bonus);
    if (G.coins == 7) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", G.coins, 7);
    G.coins = 0;

    printf("\n------------ FINISHED TESTING FUNCTION: %s ------------\n\n",
           TESTFUNC);
}
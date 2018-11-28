/*******************************************************************************
** Title: Assignment 3 - cardtest4.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "Mine card by checking the following:
**              1. Verify the swap between a copper card and a copper card.
**              2. Verify the swap between a copper card and a gold card.
**              3. Verify the swap between a copper card and a upper range
**                 invalid card (Pass = failure swapping).
**              4. Verify the swap between a copper card and a lower range
**                 invalid card (Pass = failure swapping).
**              5. Verify the swap between a lower range invalid card and a
**                 gold card (Pass = failure swapping).
**              6. Verify the swap between an upper range invalid card and a
**                 gold card (Pass = failure swapping).
** Note:        This card test was developed with the "unmodified" (no bug
**              introduced) version of the "Mine" card implementation.
**              So there is currently an failure on "TEST 2" which checks for
**              a successful swap between a copper card and a gold card.
*******************************************************************************/
#include <assert.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "MINE"

int main() {
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed       = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = { adventurer, embargo, village, minion, mine,
                  cutpurse,   sea_hag, tribute, smithy, council_room };

    initializeGame(numPlayers, k, seed, &G);

    printf("\n----------------- TESTING CARD: %s ----------------\n", TESTCARD);

    printf("\nTEST 1: Swap Copper Card for a Copper Card\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper) {
            choice1 = copper;
            handpos = i;
            break;
        }
    }

    choice2 = copper;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.hand[thisPlayer][handpos] == copper) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.hand[thisPlayer][handpos],
           copper);

    printf("\nTEST 2: Swap Copper Card for a Gold Card\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper) {
            choice1 = copper;
            handpos = i;
            break;
        }
    }

    choice2 = gold;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.hand[thisPlayer][handpos] == gold) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.hand[thisPlayer][handpos],
           gold);

    printf("\nTEST 3: Swap Copper Card for an Invalid Card (Upper Range)\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper) {
            choice1 = copper;
            handpos = i;
            break;
        }
    }

    choice2 = treasure_map + 1;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.hand[thisPlayer][handpos] != treasure_map + 1) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.hand[thisPlayer][handpos],
           treasure_map + 1);

    printf("\nTEST 4: Swap Copper Card for an Invalid Card (Lower Range)\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper) {
            choice1 = copper;
            handpos = i;
            break;
        }
    }

    choice2 = curse - 1;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.hand[thisPlayer][handpos] != curse - 1) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.hand[thisPlayer][handpos],
           curse - 1);

    printf("\nTEST 5: Swap Non-Treasure Card (Lower Range) with a Gold Card\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper) {
            testG.hand[thisPlayer][i] = curse;
            choice1 = curse;
            handpos = i;
            break;
        }
    }

    choice2 = gold;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.hand[thisPlayer][handpos] != gold) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.hand[thisPlayer][handpos],
           gold);

    printf("\nTEST 6: Swap Non-Treasure Card (Upper Range) with a Copper Card\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper) {
            testG.hand[thisPlayer][i] = duchy;
            choice1 = duchy;
            handpos = i;
            break;
        }
    }

    choice2 = copper;
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.hand[thisPlayer][handpos] != copper) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.hand[thisPlayer][handpos],
           copper);

    printf("\n------------ FINISHED TESTING CARD: %s ------------\n\n",
           TESTCARD);

    return 0;
}
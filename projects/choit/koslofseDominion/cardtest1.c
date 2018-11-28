/*******************************************************************************
** Title: Assignment 3 - cardtest1.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "Smithy" card by checking the following:
**              1. Verify that the "Smithy" card has been used by the player.
**              2. Verify the hand count after usage of the "Smithy" card.
**              3. Verify the deck count after usage of the "Smithy" card.
**              4. Verify the discard count after usage of the "Smithy" card.
** Note:        This card test was developed with the "unmodified" (no bug
**              introduced) version of the "Smithy" card implementation.
**              So, there is currently a failure on "TEST 2" which check for the
**              current hand count.
**              In addition, there seems to be an issue with the current
**              discardCard() function [as of Assignment 3].
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "SMITHY"

int main() {
    int i;
    int newCards = 3;
    int played   = 1;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed       = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = { adventurer, embargo, village, minion, mine,
                  cutpurse,   sea_hag, tribute, smithy, council_room };

    initializeGame(numPlayers, k, seed, &G);

    printf("\n----------------- TESTING CARD: %s ----------------\n", TESTCARD);

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == smithy) {
            handpos = i;
            break;
        }
    }

    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("\nTEST 1: Verify Smithy Card Usage\n");

    if (testG.playedCardCount == G.playedCardCount + 1) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.playedCardCount,
           G.playedCardCount + played);

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == smithy) {
            handpos = i;
            break;
        }
    }

    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("\nTEST 2: Verify Hand Count\n");

    if (testG.handCount[thisPlayer]
        == G.handCount[thisPlayer] + newCards - played) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.handCount[thisPlayer],
           G.handCount[thisPlayer] + newCards - played);

    printf("\nTEST 3: Verify Deck Count\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == smithy) {
            handpos = i;
            break;
        }
    }

    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.deckCount[thisPlayer],
           G.deckCount[thisPlayer] - newCards);

    printf("\nTEST 4: Verify Discard Count\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] != smithy) {
            testG.hand[thisPlayer][i] = smithy;
            handpos = i;
            break;
        }
    }

    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + played) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.discardCount[thisPlayer],
           G.discardCount[thisPlayer] + played);

    printf("\n------------ FINISHED TESTING CARD: %s ------------\n\n",
           TESTCARD);
}
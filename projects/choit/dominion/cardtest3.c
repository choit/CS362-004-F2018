/*******************************************************************************
** Title: Assignment 3 - cardtest3.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "Council Room" card by checking the
**              following:
**              1. Verify that the "Council Room" card has been used by the
**                 player.
**              2. Verify the hand count after usage of the "Council Room" card.
**              3. Verify the deck count after usage of the "Council Room" card.
**              4. Verify the discard count after usage of the "Council Room"
**                 card.
**              5. Verify the number of buys after usage of the "Council Room"
**                 card.
** Note:        This card test was developed with the "unmodified" (no bug
**              introduced) version of the "Council Room" card implementation.
**              So there is currently a failure on "TEST 2" and "TEST 3" which
**              check for the current hand count and deck count.
**              In addition, there seems to be an issue with the current
**              discardCard() function [as of Assignment 3].
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "COUNCIL ROOM"

int main() {
    int i;
    int newCards = 4;
    int played   = 1;
    int buyCount = 1;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed       = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = { adventurer, embargo, village, minion, mine,
                  cutpurse,   sea_hag, tribute, smithy, council_room };

    initializeGame(numPlayers, k, seed, &G);

    printf("\n----------------- TESTING CARD: %s ----------------\n", TESTCARD);

    printf("\nTEST 1: Verify Council Room Card Usage\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == council_room) {
            handpos = i;
            break;
        }
    }

    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos,
               &bonus);

    if (testG.playedCardCount == G.playedCardCount + 1) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.playedCardCount,
           G.playedCardCount + played);

    printf("\nTEST 2: Verify Hand Count\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == council_room) {
            handpos = i;
            break;
        }
    }

    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos,
               &bonus);

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
        if (testG.hand[thisPlayer][i] == council_room) {
            handpos = i;
            break;
        }
    }

    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos,
               &bonus);

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
        if (testG.hand[thisPlayer][i] == council_room) {
            handpos = i;
            break;
        }
    }

    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos,
               &bonus);

    if (testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + played) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.discardCount[thisPlayer],
           G.discardCount[thisPlayer] + played);

    printf("\nTEST 5: Verify Number of Buys\n");

    memcpy(&testG, &G, sizeof(struct gameState));

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == council_room) {
            handpos = i;
            break;
        }
    }

    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos,
               &bonus);

    if (testG.numBuys == G.numBuys + buyCount) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.numBuys, G.numBuys + buyCount);

    printf("\n------------ FINISHED TESTING CARD: %s ------------\n\n",
           TESTCARD);
}
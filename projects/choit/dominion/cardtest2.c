/*******************************************************************************
** Title: Assignment 3 - cardtest2.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "Adventurer" card by checking the following:
**              1. Verify that the "Adventurer" card has been used by the
**                 player.
**              2. Verify the hand count after usage of the "Adventurer" card.
**              3. Verify the deck count after usage of the "Adventurer" card.
**              4. Verify the discard count after usage of the "Adventurer"
**                 card.
**              5. Verify the treasure count after usage of the "Adventurer"
**                 card.
**              6. Verify the coin count after usage of the "Adventurer" card.
** Note:        This card test was developed with the "unmodified" (no bug
**              introduced) version of the "Adventurer" card implementation.
**              There is currently n failure on "TEST 1" which is not
**              registering the usage (playedCardCount) of the "Adventurer" card.
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

#define TESTCARD "ADVENTURER"

int main() {

    int newCards       = 2;
    int played         = 1;
    int treasureCount  = 0;
    int treasureCards  = 0;
    int treasureCards2 = 0;
    int i              = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed       = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = { adventurer, embargo, village, minion, gold,
                  silver,     sea_hag, tribute, smithy, copper };

    initializeGame(numPlayers, k, seed, &G);

    printf("\n----------------- TESTING CARD: %s ----------------\n", TESTCARD);

    printf("\nTEST 1: Verify Adventurer Card Usage\n");

    memcpy(&testG, &G, sizeof(struct gameState));
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

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
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.handCount[thisPlayer],
           G.handCount[thisPlayer] + newCards);

    printf("\nTEST 3: Verify Deck Count\n");

    memcpy(&testG, &G, sizeof(struct gameState));
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

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
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + played) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.discardCount[thisPlayer],
           G.discardCount[thisPlayer] + played);

    printf("\nTEST 5: Verify Treasure Count\n");

    memcpy(&testG, &G, sizeof(struct gameState));
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    while (treasureCount < 2) {
        int draw = G.hand[thisPlayer][G.handCount[thisPlayer] - 1];
        if (draw == copper || draw == silver || draw == gold) {
            drawCard(thisPlayer, &G);
            treasureCount++;
        }
        else {
            G.handCount[thisPlayer]--;
        }
    }

    for (i = 0; i < testG.handCount[thisPlayer]; i++) {
        if (testG.hand[thisPlayer][i] == copper
            || testG.hand[thisPlayer][i] == silver
            || testG.hand[thisPlayer][i] == gold) {
            treasureCards++;
        }
    }

    for (i = 0; i < G.handCount[thisPlayer]; i++) {
        if (G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver
            || G.hand[thisPlayer][i] == gold) {
            treasureCards2++;
        }
    }

    if (treasureCards == treasureCards2) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }

    printf("Actual = %d, Expected = %d\n", treasureCards, treasureCards2);

    printf("\nTEST 6: Verify Coin Count\n");

    memcpy(&testG, &G, sizeof(struct gameState));
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    if (testG.coins == G.coins) {
        printf("Passed: ");
    }
    else {
        printf("Failed: ");
    }
    printf("Actual = %d, Expected = %d\n", testG.coins, G.coins);

    printf("\n------------ FINISHED TESTING CARD: %s ------------\n\n",
           TESTCARD);
}
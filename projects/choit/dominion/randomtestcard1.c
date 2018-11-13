/*******************************************************************************
** Title: Assignment 4 - randomtestcard1.c
** Author: Titus Choi
** Last Modified: 11/13/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 11/14/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "Smithy" card by checking the following:
**              1. Verify that the "Smithy" card has been used by the player.
**              2. Verify the hand count after usage of the "Smithy" card.
**              3. Verify the deck count after usage of the "Smithy" card.
**              4. Verify the discard count after usage of the "Smithy" card.
**              5. Verify the treasure count after usage of the "Smithy" card.
**              6. Verify the coin count after usage of the "Smithy" card.
**              7. Verify the "Smithy" card supply after usage.
**
** Random Test: Based on the assignment specifications, the following were
**              randomized to demonstrate the implementation of random testing:
**              Pre-Initialization of Game:
**              • randomSeed:   Random value between 1 and 999999999
**              • numPlayers:   Random value between 2 to 4
**              • thisPlayer:   Random player from the randomized numPlayers
**                              value
**              Post-Initialization of Game:
**              • handCount:    Random value between 0 and MAX_HAND (500)
**              • deckCount:    Random value between 0 and MAX_DECK (500) minus
**                              the randomized handCount value
**              • discardCount: Random value between 0 and MAX_DECK (500) minus
**                              the randomized handCount value
**
** Note:        This card test was developed with the "unmodified" (no bug
**              introduced) version of the "Smithy" card implementation.
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "SMITHY"

// Define a MAX_TEST value for the number of random test iterations to run
#define MAX_TEST 10000

// Define the max seed value as the limit set by the input prompt.
#define MAX_SEED 999999999

// Signal handler for SIGALRM denoting that the test took longer than 5 minutes
void hangError(int sig) {

    // Display the error message and exit
    printf("Testing took longer than 5 minutes, exiting...\n");
    exit(1);
}

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // If SIGALRM is detected, call the handError signal handler
    signal(SIGALRM, hangError);

    // Set the alarm to 300 seconds (5 minute time limit)
    alarm(300);

    int testOneFailed   = 0;
    int testTwoFailed   = 0;
    int testThreeFailed = 0;
    int testFourFailed  = 0;
    int testFiveFailed  = 0;
    int testSixFailed   = 0;
    int testSevenFailed = 0;
    int testCounter     = 0;

    printf("\n----------------- TESTING CARD: %s ----------------\n", TESTCARD);

    while (testCounter < MAX_TEST) {
        struct gameState G, testG;
        int k[10]   = { adventurer, embargo, village, minion, mine,
                      cutpurse,   sea_hag, tribute, smithy, council_room };
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

        // Define and initialize the seed as the random integer between 1 and
        // MAX_SEED.
        int seed = rand() % MAX_SEED + 1;

        // Define and initialize the numPlayers as the random integer between
        // “2” and “4”.
        // Note that MAX_PLAYER is set to “4”, therefore random integer between
        // “0” and “4 - 1” would give us a value between 0 and 2, so adding 2
        // would result in 2 to 4 players total.
        int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;

        // Define and initialize thisPlayer as the random player from the
        // numPlayers generated
        int thisPlayer = rand() % numPlayers;

        // Define and initialize a variable to hold a random value between 0 and
        // MAX_HAND for the handCounter
        int handCounter = rand() % MAX_HAND;

        // Define and initialize a variable to hold a random value between 0 and
        // MAX_DECK for the deckCounter
        int deckCounter = rand() % MAX_DECK;
        int newCards    = 3;
        int played      = 1;
        int i;

        initializeGame(numPlayers, k, seed, &G);

        // Set the deck count as the difference between deck and hand counter
        G.deckCount[thisPlayer] = deckCounter - handCounter;

        // Set the discard count as the difference between deck and hand counter
        G.discardCount[thisPlayer] = deckCounter - handCounter;

        // Set the hand count as handCounter
        G.handCount[thisPlayer] = handCounter;

        memcpy(&testG, &G, sizeof(struct gameState));

        for (i = 0; i < testG.handCount[thisPlayer]; i++) {
            if (testG.hand[thisPlayer][i] == smithy) {
                handpos = i;
                break;
            }
        }

        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        // TEST 1: Verify Smithy Card Usage

        if (testG.playedCardCount != G.playedCardCount + played) {
            testOneFailed++;
        }

        // TEST 2: Verify Hand Count

        if (testG.handCount[thisPlayer]
            != G.handCount[thisPlayer] + newCards - played) {
            testTwoFailed++;
        }

        // TEST 3: Verify Deck Count

        if (testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards) {
            testThreeFailed++;
        }

        // TEST 4: Verify Discard Count

        if (testG.discardCount[thisPlayer]
            != G.discardCount[thisPlayer] + played) {
            testFourFailed++;
        }

        // TEST 5: Verify Treasure Count

        if ((testG.supplyCount[copper] != G.supplyCount[copper])
            || (testG.supplyCount[silver] != G.supplyCount[silver])
            || (testG.supplyCount[gold] != G.supplyCount[gold])) {
            testFiveFailed++;
        }

        // TEST 6: Verify Coin Count

        if (testG.coins != G.coins) {
            testSixFailed++;
        }

        // Test 7: Verify Smithy Supply Count
        if (G.supplyCount[smithy] != testG.supplyCount[smithy]) {
            testSevenFailed++;
        }

        testCounter++;
    }
    printf("\nTEST 1: Verify Smithy Card Usage\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testOneFailed, MAX_TEST);

    printf("\nTEST 2: Verify Hand Count\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testTwoFailed, MAX_TEST);

    printf("\nTEST 3: Verify Deck Count\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testThreeFailed, MAX_TEST);

    printf("\nTEST 4: Verify Discard Count\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testFourFailed, MAX_TEST);

    printf("\nTEST 5: Verify Treasure Count\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testFiveFailed, MAX_TEST);

    printf("\nTEST 6: Verify Coin Count\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testSixFailed, MAX_TEST);

    printf("\nTEST 7: Verify Smithy Supply Count\n");
    printf("PASSED: %d of %d\n", MAX_TEST - testSevenFailed, MAX_TEST);

    printf("\n------------ FINISHED TESTING CARD: %s ------------\n\n",
           TESTCARD);
}
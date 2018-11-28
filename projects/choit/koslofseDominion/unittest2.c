/*******************************************************************************
** Title: Assignment 3 - unittest2.c
** Author: Titus Choi
** Last Modified: 10/28/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: This is the program that tests the functionality, coverage, and
**              correctness of the "getCost" function by checking the following:
**              1. Verifies the card cost of all 27 implemented cards (0 - 26).
**              2. Verify get card cost to an invalid card.
**                 (Pass = failure getting card cost).
*******************************************************************************/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTFUNC "getCost"
#define TOTALCARDS 27

int main(int argc, char** argv) {
    int i = 0;

    printf("\n----------------- TESTING FUNCTION: %s ----------------\n",
           TESTFUNC);

    printf("\nTEST 1: Get The Cost of All Implemented Cards\n");

    for (i = 0; i < TOTALCARDS; i++) {
        if (i == 0) {
            printf("\nCURSE CARD COST:\n");
            if (getCost(i) == 0) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 0);
        }

        if (i == 1) {
            printf("\nESTATE CARD COST:\n");
            if (getCost(i) == 2) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 2);
        }

        if (i == 2) {
            printf("\nDUCHY CARD COST:\n");
            if (getCost(i) == 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 5);
        }

        if (i == 3) {
            printf("\nPROVINCE CARD COST:\n");
            if (getCost(i) == 8) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 8);
        }

        if (i == 4) {
            printf("\nCOPPER CARD COST:\n");
            if (getCost(i) == 0) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 0);
        }

        if (i == 5) {
            printf("\nSILVER CARD COST:\n");
            if (getCost(i) == 3) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 3);
        }

        if (i == 6) {
            printf("\nGOLD CARD COST:\n");
            if (getCost(i) == 6) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 6);
        }

        if (i == 7) {
            printf("\nADVENTURER CARD COST:\n");
            if (getCost(i) == 6) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 6);
        }

        if (i == 8) {
            printf("\nCOUNCIL ROOM CARD COST:\n");
            if (getCost(i) == 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 5);
        }

        if (i == 9) {
            printf("\nFEAST CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 10) {
            printf("\nGARDENS CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 11) {
            printf("\nMINE CARD COST:\n");
            if (getCost(i) == 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 5);
        }

        if (i == 12) {
            printf("\nREMODEL CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 13) {
            printf("\nSMITHY CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 14) {
            printf("\nVILLAGE CARD COST:\n");
            if (getCost(i) == 3) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 3);
        }

        if (i == 15) {
            printf("\nBARON CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 16) {
            printf("\nGREAT HALL CARD COST:\n");
            if (getCost(i) == 3) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 3);
        }

        if (i == 17) {
            printf("\nMINION CARD COST:\n");
            if (getCost(i) == 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 5);
        }

        if (i == 18) {
            printf("\nSTEWARD CARD COST:\n");
            if (getCost(i) == 3) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 3);
        }

        if (i == 19) {
            printf("\nTRIBUTE CARD COST:\n");
            if (getCost(i) == 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 5);
        }

        if (i == 20) {
            printf("\nAMBASSADOR CARD COST:\n");
            if (getCost(i) == 3) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 3);
        }

        if (i == 21) {
            printf("\nCUTPURSE CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 22) {
            printf("\nEMBARGO CARD COST:\n");
            if (getCost(i) == 2) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 2);
        }

        if (i == 23) {
            printf("\nOUTPOST CARD COST:\n");
            if (getCost(i) == 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 5);
        }

        if (i == 24) {
            printf("\nSALVAGER CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 25) {
            printf("\nSEA HAG CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }

        if (i == 26) {
            printf("\nTREASURE MAP CARD COST:\n");
            if (getCost(i) == 4) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(i), 4);
        }
    }

    printf("\nTEST 2: Get The Cost of Non-existent Card\n");
    printf("\nSOOTHSAYER CARD COST:\n");
            if (getCost(27) != 5) {
                printf("Passed: ");
            }
            else {
                printf("Failed: ");
            }
            printf("Actual = %d, Expected = %d\n", getCost(27), 5);

    printf("\n------------ FINISHED TESTING FUNCTION: %s ------------\n\n",
           TESTFUNC);
}
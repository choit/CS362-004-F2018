/*******************************************************************************
** Title: Random Testing Quiz - testme.c
** Author: Titus Choi
** Last Modified: 10/24/2018
** OSU email address: choit@oregonstate.edu
** Course number/section: CS 362/400
** Due Date: 10/28/2018
** Description: Random Testing Quiz with the inputChar and inputString function
**              implementations according to the quiz specifications.
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char inputChar() {
    // TODO: rewrite this function

    // Define and initialize a character array with only the characters from
    // the target if statements in the testme function.
    char charList[9] = { '[', '(', '{', ' ', 'a', 'x', '}', ')', ']' };

    // Define and initialize a random character from the charList array to
    // the randomChar variable.
    char randomChar = charList[rand() % 9];

    // Return the randomized character from the target statement list.
    return randomChar;
}

char* inputString() {
    // TODO: rewrite this function

    // Define and initialize a char pointer to hold the random string and
    // allocate enough memory to hold five characters plus the null terminator.
    char* randomString = (char*)malloc(5 * sizeof(char) + 1);

    // Define and initialize a character array with only the characters from
    // the target if statement in the testme function which checks for the string
    // "reset".
    char charList[4]   = { 'e', 'r', 's', 't' };

    // For loop that iterates through the randomString array by randomizing a
    // character for each of the 5 characters.
    for (int i = 0; i < 5; i++) {

        // The character at index i is a random char from the charList.
        randomString[i] = charList[rand() % 4];
    }

    // Initialize the last character in the string as the null terminator.
    randomString[5] = '\0';

    // Return the randomized string.
    return randomString;
}

void testme() {
    int tcCount = 0;
    char* s;
    char c;
    int state = 0;
    while (1) {
        tcCount++;
        c = inputChar();
        s = inputString();
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s,
               state);

        if (c == '[' && state == 0)
            state = 1;
        if (c == '(' && state == 1)
            state = 2;
        if (c == '{' && state == 2)
            state = 3;
        if (c == ' ' && state == 3)
            state = 4;
        if (c == 'a' && state == 4)
            state = 5;
        if (c == 'x' && state == 5)
            state = 6;
        if (c == '}' && state == 6)
            state = 7;
        if (c == ')' && state == 7)
            state = 8;
        if (c == ']' && state == 8)
            state = 9;
        if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e'
            && s[4] == 't' && s[5] == '\0' && state == 9) {
            printf("error ");
            exit(200);
        }
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    testme();
    return 0;
}

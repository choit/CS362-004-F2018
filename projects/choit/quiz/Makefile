##############################################################################
#  CS362-400 Random Testing Quiz Makefile
#  Author: Titus Choi
#  Email: choit@oregonstate.edu
#
#  ****************************** INSTRUCTIONS *******************************
#  Typing "make" performs the following operation:
#  1. Creates and runs an executable file "testme".
#
#  **************************** IMPORTANT NOTE *******************************
#  1. Typing "make clean" will delete the "testme" executable file.
##############################################################################
CFLAGS = -Wall -std=c99

##############################################################################
#  Default rule.
##############################################################################
default: testme

##############################################################################
#  Rule to create and run the executable file "testme".
##############################################################################
testme:
	gcc -o testme testme.c $(CFLAGS)
	./testme

##############################################################################
#  Rule to clean the created executable file.
##############################################################################
clean:
	rm -r testme
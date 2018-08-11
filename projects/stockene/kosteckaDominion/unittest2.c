/*

   unittest2.c

 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int assertTrue(int input1, int input2, int success)
{
        if(input1 == input2)
        {
                printf("-------SUCCESS-------\n");

                //only return 1 if success is not already set to 0

                if (success == 1)
                {
                  return 1;
                }

                return 0;
        }

        else
        {
                printf("-------FAIL-------\n");
        }

        return 0;
}

#define FUNCTION "fullDeckCount()"

int main() {

        int numPlayers = 2;
        int success = 1;
        int seed = 1000;
        struct gameState G;
        int k[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        printf("----------------- Testing Function: %s ----------------\n", FUNCTION);

        // ----------- TEST 1:  --------------
        printf("TEST 1: Check card counts for player 1 \n");

        int estatePlayer1 = fullDeckCount(0, estate, &G);

        int copperPlayer1 = fullDeckCount(0, copper, &G);

        printf("Estate Count = %d, Expected Count = %d\n", estatePlayer1, 3);
        printf("Copper Count = %d, Expected Count = %d\n", copperPlayer1, 7);

        printf("Comparing estate count to expected estate count...\n");
        success = assertTrue(estatePlayer1, 3, success);

        printf("Comparing copper count to expected copper count...\n");

        success = assertTrue(copperPlayer1, 7, success);

        // ----------- TEST 2:  --------------
        printf("TEST 2: Check card counts for player 2\n");

        int estatePlayer2 = fullDeckCount(1, estate, &G);

        int copperPlayer2 = fullDeckCount(1, copper, &G);

        printf("Estate Count = %d, Expected Count = %d\n", estatePlayer2, 3);
        printf("Copper Count = %d, Expected Count = %d\n", copperPlayer2, 7);

        printf("Comparing estate count to expected estate count...\n");
        success = assertTrue(estatePlayer2, 3, success);

        printf("Comparing copper count to expected copper count...\n");

        success = assertTrue(copperPlayer2, 7, success);

        if (success == 1)
        {
                printf("\nALL TESTS PASSED: Testing complete %s\n\n", FUNCTION);
        }

        if (success == 0)
        {
                printf("\nNOT ALL TESTS PASSED: Testing complete %s \n\n", FUNCTION);
        }

        return 0;
}

/*

   unittest1.c

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

#define FUNCTION "drawCard()"

int main() {

        int numPlayers = 2;
        int success = 1;
        int seed = 1000;
        struct gameState G, newG;
        int k[10] = {adventurer, council_room, feast, gardens, mine,
          remodel, smithy, village, baron, great_hall};


        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        printf("----------------- Testing Function: %s ----------------\n", FUNCTION);

        // ----------- TEST 1:  --------------
        printf("TEST 1: Draw Card From Initial Deck for Player 1 \n");

        memcpy(&newG, &G, sizeof(struct gameState));

        int resultPlayer1 = drawCard(0, &newG);

        printf("New Hand Count = %d, Expected Count = %d\n", newG.handCount[0], G.handCount[0] + 1);
        printf("New Deck Count = %d, Expected Count = %d\n", newG.deckCount[0], G.deckCount[0] - 1);

        printf("Comparing new hand count to expected hand count...\n");
        success = assertTrue(newG.handCount[0], G.handCount[0] + 1, success);

        printf("Comparing new deck count to expected deck count...\n");

        success = assertTrue(newG.deckCount[0], G.deckCount[0] - 1, success);

        printf("Checking if card in hand matches card from deck... \n");

        success = assertTrue(newG.hand[0][G.handCount[0]], G.deck[0][G.deckCount[0] - 1], success);

        printf("Checking function output...");

        success = assertTrue(resultPlayer1, 0, success);

        // ----------- TEST 2:  --------------
        printf("TEST 2: Draw Card From Initial Deck for Player 2 \n");

        int resultPlayer2 = drawCard(1, &newG);

        printf("New Hand Count = %d, Expected Count = %d\n", newG.handCount[1], G.handCount[1] + 1);
        printf("New Deck Count = %d, Expected Count = %d\n", newG.deckCount[1], G.deckCount[1] - 1);

        printf("Comparing new hand count to expected hand count...\n");
        success = assertTrue(newG.handCount[1], G.handCount[1] + 1, success);

        printf("Comparing new deck count to expected deck count...\n");

        success = assertTrue(newG.deckCount[1], G.deckCount[1] - 1, success);

        printf("Checking if card in hand matches card from deck... \n");

        success = assertTrue(newG.hand[1][G.handCount[1]], G.deck[1][G.deckCount[1] - 1], success);

        printf("Checking function output...\n");

        success = assertTrue(resultPlayer2, 0, success);


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

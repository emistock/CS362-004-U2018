/*

   unittest3.c

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

#define FUNCTION "discardCard()"

int main() {

        int numPlayers = 2;
        int success = 1;
        int maxHandCount = 5;

        int coppers[MAX_HAND];
        int handCount;
        int seed = 1000;
        int r, i;

        for (i = 0; i < MAX_HAND; i++)
        {
            coppers[i] = copper;
        }

        struct gameState G;
        int k[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

        printf("----------------- Testing Function: %s ----------------\n", FUNCTION);

        // ----------- TEST 1:  --------------
        printf("TEST 1: Player 1, card is not trashed \n");

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {

                printf("Test player 1 with %d cards in hand\n", handCount);

                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);
                G.handCount[0] = handCount;

                int playCount = G.playedCardCount;

                memcpy(G.hand[0], coppers, sizeof(int) * handCount);
                discardCard(0, 0, &G, 0);

                printf("Checking hand count...\n");

                printf("Hand Count = %d, expected = %d\n", G.handCount[0], handCount - 1);

                success = assertTrue(G.handCount[0], handCount - 1, success);

                printf("Checking play card count...\n");

                success = assertTrue(G.playedCardCount, playCount + 1, success);
        }

        // ----------- TEST 2:  --------------
        printf("TEST 2: Player 1, card is trashed\n");

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
                printf("Test player 1 with %d cards in hand\n", handCount);

                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);
                G.handCount[0] = handCount;
                int playCount = G.playedCardCount;
                memcpy(G.hand[0], coppers, sizeof(int) * handCount);
                discardCard(handCount-1, 0, &G, 1);

                printf("Checking hand count...\n");

                printf("Hand Count = %d, expected = %d\n", G.handCount[0], handCount - 1);

                success = assertTrue(G.handCount[0], handCount - 1, success);

                printf("Checking play card count...\n");

                success = assertTrue(G.playedCardCount, playCount, success);
        }

        // ----------- TEST 3:  --------------
        printf("TEST 3: Player 2, card is not trashed\n");

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
                printf("Test player 2 with %d cards in hand\n", handCount);

                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);
                G.handCount[1] = handCount;
                int playCount = G.playedCardCount;
                memcpy(G.hand[1], coppers, sizeof(int) * handCount);
                discardCard(handCount-1, 1, &G, 0);

                printf("Checking hand count...\n");

                printf("Hand Count = %d, expected = %d\n", G.handCount[1], handCount - 1);

                success = assertTrue(G.handCount[1], handCount - 1, success);

                printf("Checking play card count...\n");

                success = assertTrue(G.playedCardCount, playCount + 1, success);
        }

        // ----------- TEST 4:  --------------
        printf("TEST 4: Player 2, card is trashed\n");

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
                printf("Test player 2 with %d cards in hand\n", handCount);

                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);
                G.handCount[1] = handCount;
                int playCount = G.playedCardCount;
                memcpy(G.hand[1], coppers, sizeof(int) * handCount);
                discardCard(handCount-1, 1, &G, 1);

                printf("Checking hand count...\n");

                printf("Hand Count = %d, expected = %d\n", G.handCount[1], handCount - 1);

                success = assertTrue(G.handCount[1], handCount - 1, success);

                printf("Checking play card count...\n");

                success = assertTrue(G.playedCardCount, playCount, success);
        }

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

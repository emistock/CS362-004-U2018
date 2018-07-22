/*

   cardtest1.c

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

#define CARDTOTEST "adventurer"

int main() {
        int success = 1;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int seed = 1000;
        int numPlayers = 2;
        int playerNum = 0;
        int handCount = 5;
        int r, i;

        int coppers[MAX_HAND];

        for (i = 0; i < MAX_HAND; i++)
        {
            coppers[i] = copper;
        }

        struct gameState G, testG;

        int k[10] = {adventurer, council_room, feast, gardens, mine,
          remodel, smithy, village, baron, great_hall};

        printf("----------------- Testing Card: %s ----------------\n", CARDTOTEST);

        // ----------- TEST 1 --------------
        printf("TEST 1: Player 1 uses adventurer card\n");

        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayers, k, seed, &G);

        G.whoseTurn = 0;
        G.handCount[playerNum] = handCount;

        memcpy(G.hand[playerNum], coppers, sizeof(int) * handCount);

        memcpy(&testG, &G, sizeof(struct gameState));

        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("New Hand Count = %d, Expected Count = %d\n", testG.handCount[playerNum], G.handCount[playerNum] + 2);
        success = assertTrue(testG.handCount[playerNum], G.handCount[playerNum] + 2, success);

        // ----------- TEST 2 --------------
        playerNum = 1;

        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayers, k, seed, &G);

        G.whoseTurn = 1;
        G.handCount[playerNum] = handCount;

        memcpy(G.hand[playerNum], coppers, sizeof(int) * handCount);

        printf("TEST 2: Player 2 uses adventurer card\n");
        memcpy(&testG, &G, sizeof(struct gameState));

        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("New Hand Count = %d, Expected Count = %d\n", testG.handCount[playerNum], G.handCount[playerNum] + 2);
        success = assertTrue(testG.handCount[playerNum], G.handCount[playerNum] + 2, success);

        if (success == 1)
        {
                printf("\nALL TESTS PASSED: Testing complete %s\n\n", CARDTOTEST);
        }

        if (success == 0)
        {
                printf("\nNOT ALL TESTS PASSED: Testing complete %s \n\n", CARDTOTEST);
        }

        return 0;
}

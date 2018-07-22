/*

   cardtest2.c

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

#define CARDTOTEST "smithy"

int main() {
        int success = 1;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int seed = 1000;
        int numPlayers = 2;
        int playerNum = 0;
        struct gameState G, testG;
        int r, i;
        int handCount = 5;
        int coppers[MAX_HAND];

        for (i = 0; i < MAX_HAND; i++)
        {
            coppers[i] = copper;
        }

        int k[10] = {adventurer, council_room, feast, gardens, mine,
          remodel, smithy, village, baron, great_hall};

        printf("----------------- Testing Card: %s ----------------\n", CARDTOTEST);

        // ----------- TEST 1 --------------
        printf("TEST 1: Player 1 uses smithy card\n");
        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayers, k, seed, &G);

        G.whoseTurn = 0;

        G.handCount[playerNum] = handCount;

        memcpy(G.hand[playerNum], coppers, sizeof(int) * handCount);

        memcpy(&testG, &G, sizeof(struct gameState));

        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("New Hand Count = %d, Expected Count = %d\n", testG.handCount[playerNum], G.handCount[playerNum] + 3  - 1);
        success = assertTrue(testG.handCount[playerNum], G.handCount[playerNum] + 3  -  1, success);


        // ----------- TEST 2 --------------

        printf("TEST 2: Player 2 uses smithy card\n");

        playerNum = 1;

        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayers, k, seed, &G);

        G.whoseTurn = 1;

        G.handCount[playerNum] = handCount;

        memcpy(G.hand[playerNum], coppers, sizeof(int) * handCount);

        memcpy(&testG, &G, sizeof(struct gameState));

        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("New Hand Count = %d, Expected Count = %d\n", testG.handCount[playerNum], G.handCount[playerNum] + 3  - 1);
        success = assertTrue(testG.handCount[playerNum], G.handCount[playerNum] + 3  -  1, success);

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

/* based off of betterTestDrawCard.c file from dominion files */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1
#define CARDTOTEST "Adventurer"

int assertTrue(int input1, int input2, int* failCount, int* successCount)
{
        if(input1 == input2)
        {
                *successCount = *successCount + 1;
                return 1;
        }

        else
        {
                *failCount = *failCount + 1;
                return 0;
        }
}

int main () {

        srand( (unsigned) time(NULL));

        printf("----------------- Testing Card: %s ----------------\n", CARDTOTEST);

        printf ("RANDOM TESTS.\n");

        int successCount = 0;
        int failCount = 0;
        int n, k;

        for (n = 0; n < 2000; n++) {

                struct gameState G, testG;

                int success = 1;
                int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
                int seed = 1000;
                int numPlayers = 2;
                int playerNum = rand() % 2;
                int handCount = rand() % MAX_HAND + 1;
                int discardCount = rand() % MAX_DECK + 1;

                int r, i;

                int coppers[MAX_HAND];

                for (i = 0; i < MAX_HAND; i++)
                {
                        coppers[i] = copper;
                }


                int k[10] = {adventurer, council_room, feast, gardens, mine,
                             remodel, smithy, village, baron, great_hall};

                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);

                G.whoseTurn = playerNum;
                G.handCount[playerNum] = handCount;
                G.discardCount[playerNum] = discardCount;

                memcpy(G.hand[playerNum], coppers, sizeof(int) * handCount);

                memcpy(&testG, &G, sizeof(struct gameState));

                cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

                success = assertTrue(testG.handCount[playerNum], G.handCount[playerNum] + 2, &failCount, &successCount);
        }

        if (failCount == 0)
        {
                printf("\nALL TESTS PASSED: Testing complete %s\n\n", CARDTOTEST);
        }

        if (failCount > 0)
        {
                printf("\nNOT ALL TESTS PASSED: Testing complete %s \n\n", CARDTOTEST);
        }

        printf("Number of successes: %d\n", successCount);
        printf("Number of failures: %d\n\n", failCount);

        return 0;

}

/* based off of betterTestDrawCard.c file from dominion files */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1
#define CARDTOTEST "Village"

int assertTrue(int input1, int input2, int success, int* failCount, int* successCount)
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

int checkVillage(int success, int choice1, int choice2, int choice3, struct gameState* G, int handpos, int* bonus, int* failCount, int* successCount) {
        struct gameState testG;
        int playerNum = G->whoseTurn;
        memcpy(&testG, G, sizeof(struct gameState));
        cardEffect(village, choice1, choice2, choice3, &testG, handpos, bonus);
        success = assertTrue(testG.handCount[playerNum], G->handCount[playerNum] + 1 - 1, success, failCount, successCount);
        success = assertTrue(testG.numActions, G->numActions + 2, success, failCount, successCount);
        return success;
}

int main () {

        clock_t begin = clock();

        srand( (unsigned) time(NULL));

        int success = 1;
        int failCount = 0;
        int successCount = 0;
        int i, n, r, p, deckCount, discardCount, handCount;

        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int seed = 1000;
        int numPlayers = 2;

        int k[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

        struct gameState G;

        printf("----------------- Testing Card: %s ----------------\n", CARDTOTEST);

        printf ("RANDOM TESTS.\n");

        for (n = 0; n < 2000; n++) {
                for (i = 0; i < sizeof(struct gameState); i++) {
                        ((char*)&G)[i] = rand() % 257;
                }

                //pick random player
                p = rand() % 2;
                G.deckCount[p] = rand() % MAX_DECK + 1;
                G.discardCount[p] = rand() % MAX_DECK + 1;
                G.handCount[p] = rand() % MAX_HAND + 1;
                G.whoseTurn = p;

                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);

                success = checkVillage(success, choice1, choice2, choice3, &G, handpos, &bonus, &failCount, &successCount);
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

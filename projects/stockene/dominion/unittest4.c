/*

   unittest4.c

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

#define FUNCTION "getCost()"

int main() {

        int success = 1;

        printf("----------------- Testing Function: %s ----------------\n", FUNCTION);

        printf("Checking card costs...\n");

        printf("Checking curse card cost...\n");
        success = assertTrue(getCost(curse), 0, success);

        printf("Checking estate card cost...\n");
        success = assertTrue(getCost(estate), 2, success);

        printf("Checking duchy card cost...\n");
        success = assertTrue(getCost(duchy), 5, success);

        printf("Checking province card cost...\n");
        success = assertTrue(getCost(province), 8, success);

        printf("Checking copper card cost...\n");
        success = assertTrue(getCost(copper), 0, success);

        printf("Checking silver card cost...\n");
        success = assertTrue(getCost(silver), 3, success);

        printf("Checking gold card cost...\n");
        success = assertTrue(getCost(gold), 6, success);

        printf("Checking adventurer card cost...\n");
        success = assertTrue(getCost(adventurer), 6, success);

        printf("Checking council room card cost...\n");
        success = assertTrue(getCost(council_room), 5, success);

        printf("Checking feast card cost...\n");
        success = assertTrue(getCost(feast), 4, success);

        printf("Checking gardens card cost...\n");
        success = assertTrue(getCost(gardens), 4, success);

        printf("Checking mine card cost...\n");
        success = assertTrue(getCost(mine), 5, success);

        printf("Checking remodel card cost...\n");
        success = assertTrue(getCost(remodel), 4, success);

        printf("Checking smithy card cost...\n");
        success = assertTrue(getCost(smithy), 4, success);

        printf("Checking village card cost...\n");
        success = assertTrue(getCost(village), 3, success);

        printf("Checking baron card cost...\n");
        success = assertTrue(getCost(baron), 4, success);

        printf("Checking great hall card cost...\n");
        success = assertTrue(getCost(great_hall), 3, success);

        printf("Checking minion card cost...\n");
        success = assertTrue(getCost(minion), 5, success);

        printf("Checking steward card cost...\n");
        success = assertTrue(getCost(steward), 3, success);

        printf("Checking tribute card cost...\n");
        success = assertTrue(getCost(tribute), 5, success);

        printf("Checking ambassador card cost...\n");
        success = assertTrue(getCost(ambassador), 3, success);

        printf("Checking cutpurse card cost...\n");
        success = assertTrue(getCost(cutpurse), 4, success);

        printf("Checking embargo card cost...\n");
        success = assertTrue(getCost(embargo), 2, success);

        printf("Checking outpost card cost...\n");
        success = assertTrue(getCost(outpost), 5, success);

        printf("Checking salvager card cost...\n");
        success = assertTrue(getCost(salvager), 4, success);

        printf("Checking sea hag card cost...\n");
        success = assertTrue(getCost(sea_hag), 4, success);

        printf("Checking treasure map card cost...\n");
        success = assertTrue(getCost(treasure_map), 4, success);

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

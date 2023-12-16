#include <stdio.h>
#include <stdlib.h>
#include "../include/map.h"

#define UPDATE_VALUE 10

void* updateNum (CellData* pCell) {
    pCell->exampleNum = UPDATE_VALUE;
}

int main () {
    Map testMap;
    mapCreate (&testMap, 100000, 1000);
    mapForEach (&testMap, updateNum);
    mapDestroy (&testMap);
    printf ("howdy\n");
    exit (EXIT_SUCCESS);
}
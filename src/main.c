#include <stdio.h>
#include <stdlib.h>
#include "../include/map.h"

#define UPDATE_VALUE '.'

void* updateNum (CellData* pCell) {
    pCell->exampleChar = UPDATE_VALUE;
    return NULL;
}

void* printVal (CellData* pCell) {
    printf ("%c", pCell->exampleChar);
    return NULL;
}

void* printNewline (CellData* pCell) {
    printf ("\n");
    return NULL;
}

int main () {
    Map testMap;
    mapCreate (&testMap, 80, 24);
    mapForEach (&testMap, updateNum);
    mapForEachCellAndRow (&testMap, printVal, printNewline);
    mapDestroy (&testMap);
    printf ("howdy\n");
    exit (EXIT_SUCCESS);
}
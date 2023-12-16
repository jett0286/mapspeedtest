#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "../include/map.h"

#define UPDATE_VALUE L'╣'

void* updateNum (CellData* pCell) {
    pCell->exampleChar = L'╣';
    return NULL;
}

// edit

void* printVal (CellData* pCell) {
    wprintf (L"%lc", pCell->exampleChar);
    return NULL;
}

void* printNewline (CellData* pCell) {
    wprintf (L"\n");
    return NULL;
}

int main () {
    Map testMap;

    setlocale(LC_ALL, "");
    mapCreate (&testMap, 80, 24);
    mapForEach (&testMap, updateNum);
    mapForEachCellAndRow (&testMap, printVal, printNewline);
    mapDestroy (&testMap);
    exit (EXIT_SUCCESS);
}
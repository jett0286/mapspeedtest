#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "../include/map.h"

#define UPDATE_VALUE L'╣'

void* updateNum (CellData* pCell, void* nothing) {
    return NULL;
}

void* printVal (CellData* pCell, void* nothing) {
    wprintf (L"%lc", pCell->exampleChar);
    // wprintf (L"ɸ");
    return NULL;
}

void* printNewline (CellData* pCell, void* nothing) {
    wprintf (L"\n");
    return NULL;
}

void* scanValsFromFile (CellData* pCell, void* file) {
    //pCell->exampleChar = 0x0278;
    fscanf ((FILE*) file, "%c", &pCell->exampleChar);
    return NULL;
}

void* scanNewlineChar (CellData* pCell, void* file) {
    char buffer;
    fscanf((FILE*) file, "%c", &buffer);
    return NULL;
}

int main () {
    Map testMap;
    FILE* inFile = fopen("./data/board.txt", "r");
    setlocale(LC_ALL, "");
    mapCreate (&testMap, 80, 24);
    mapForEachCellAndRow (&testMap, scanValsFromFile, scanNewlineChar, inFile);
    fclose (inFile);
    mapForEachCellAndRow (&testMap, printVal, printNewline, NULL);
    mapDestroy (&testMap);
    exit (EXIT_SUCCESS);
}
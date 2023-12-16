#include <stdlib.h>
#include <wchar.h>
#include "../include/map.h"

// ACCESSING hTheMap uses the format pMap->hTheMap[y][x]. REMEMBER THIS

void mapCreate (Map* pMap, int width, int height) {
    pMap->height = height;
    pMap->width = width;
    pMap->hTheMap = malloc (sizeof (CellData*) * height); // These are your Y values
    for (int i = 0; i < height; i++) {
        pMap->hTheMap[i] = malloc (sizeof (CellData) * width); // These are your X values
    }
}

void mapDestroy (Map* pMap) {
    for (int i = 0; i < pMap->height; i++) {
        free (pMap->hTheMap[i]);
    }
    free (pMap->hTheMap);
}

void mapForEach (Map* pMap, forEachFuncPtr foreach) {
    for (int i = 0; i < pMap->height; i++) {
        for (int j = 0; j < pMap->width; j++) {
            foreach(&pMap->hTheMap[i][j]);
        }
    }
}

// Like foreach except does something after each row. Meant mainly for printing, but general
// enough to be used for anything that comes up
void mapForEachCellAndRow (Map* pMap, forEachFuncPtr foreachcell, forEachFuncPtr foreachrow) {
    for (int i = 0; i < pMap->height; i++) {
        for (int j = 0; j < pMap->width; j++) {
            foreachcell(&pMap->hTheMap[i][j]);
        }
        foreachrow(&pMap->hTheMap[i][pMap->width - 1]);
    }
}
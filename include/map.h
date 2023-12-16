#include <wchar.h>

// ---------------------------------------------
//  Template for the Map struct
// ---------------------------------------------

typedef struct CellData {
    wchar_t exampleChar;
    // Put the cell's data here (and change the name)
} CellData;

typedef struct Map {
    CellData** hTheMap;
    int width;
    int height;
    // Put any map data in here
} Map;

typedef void* (forEachFuncPtr)(CellData*);

// ------------- NECESSARY ------------------

void mapCreate (Map* pMap, int width, int height);

void mapDestroy (Map* pMap);

void mapForEach (Map* pMap, forEachFuncPtr foreach);
void mapForEachCellAndRow (Map* pMap, forEachFuncPtr foreachcell, forEachFuncPtr foreachrow);
// ------------------------------------------
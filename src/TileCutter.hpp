//
//  TileCutter.hpp
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/21/18.
//

#ifndef TileCutter_hpp
#define TileCutter_hpp

#include "ofMain.h"
#include "TileInfo.h"
#include "Tile.h"

class TileCutter{
public:
    
    void setup(string file);
    void adjustTileSize(int dir);
    
    void cut();
    bool comparePixels(ofImage picA, ofImage picB);
    
    void draw();
    
    void setData(vector<Tile> &sourceTiles, vector<vector<int>> &sourceImage, int &sourceCols, int &sourceRows, int &_tileSize);
    
    ofImage sourcePic;
    int tileSize;
    int cols, rows;
    
    ofImage testTile, testTileB, testTileC;
    
    vector<TileInfo> allTiles;
    vector<TileInfo> uniqueTiles;
    
    bool ready;
};

#endif /* TileCutter_hpp */

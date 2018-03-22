//
//  TileCutter.cpp
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/21/18.
//

#include "TileCutter.hpp"


void TileCutter::setup(string file){
    
    sourcePic.load(file);
    
    tileSize = 16;
    adjustTileSize(0);
    
    allTiles.clear();
    uniqueTiles.clear();
   
    
    ready = false;
}

void TileCutter::adjustTileSize(int dir){
    //cout<<"adjust "<<dir<<endl;
    tileSize += dir;
    while (tileSize > 1 && tileSize<sourcePic.getWidth()/2 && (int)sourcePic.getWidth() % tileSize != 0 && (int)sourcePic.getHeight() % tileSize != 0) {
        tileSize += dir;
        //cout<<"new "<<tileSize<<endl;
    }
    tileSize = CLAMP(tileSize, 1, sourcePic.getWidth()/2);
    
    cols = sourcePic.getWidth()/tileSize;
    rows = sourcePic.getHeight()/tileSize;
}

void TileCutter::cut(){
    //break this thing apart
    for (int y=0; y<rows; y++){
        for (int x=0; x<cols; x++){
            TileInfo tile;
            tile.originalX = x;
            tile.originalY = y;
            tile.pic.cropFrom(sourcePic, tileSize*x, tileSize*y, tileSize, tileSize);
            allTiles.push_back(tile);
        }
    }
    
    //compare
    for (int i=0; i<allTiles.size(); i++){
        bool isUnique = true;
        for (int k=0; k<uniqueTiles.size(); k++){
            if ( comparePixels(uniqueTiles[k].pic, allTiles[i].pic) == true ){
                isUnique = false;
                allTiles[i].idNum = k;
            }
        }
        if (isUnique){
            uniqueTiles.push_back(allTiles[i]);
            allTiles[i].idNum = uniqueTiles.size()-1;
        }
    }
    
    ready = true;
}

bool TileCutter::comparePixels(ofImage picA, ofImage picB){
    ofPixels pixA = picA.getPixels();
    ofPixels pixB = picB.getPixels();
    
    for (int i=0; i<pixA.size(); i++){
        if (pixA[i] != pixB[i]){
            return false;
        }
    }
    
    return true;
}


void TileCutter::draw(){
    ofSetColor(255);
    sourcePic.draw(0,0);
    
    ofSetColor(255,0,0);
    for (int x=0; x<=cols; x++){
        ofDrawLine(x*tileSize, 0, x*tileSize, rows*tileSize);
    }
    for (int y=0; y<=rows; y++){
        ofDrawLine(0, y*tileSize, cols*tileSize, y*tileSize);
    }
    
    ofSetColor(0);
    string info = "Current Tile Size: "+ofToString(tileSize);
    info += "\nup/down to adjust. Enter to confirm.";
    ofDrawBitmapString(info, 5, sourcePic.getHeight()+20);
}



void TileCutter::setData(vector<Tile> &sourceTiles, vector<vector<int>> &sourceImage, int &sourceCols, int &sourceRows, int &_tileSize){
    //source tiles
    sourceTiles.clear();
    for (int i=0; i<uniqueTiles.size(); i++){
        Tile tile;
        tile.pic = uniqueTiles[i].pic;
        tile.idNum = i;
        sourceTiles.push_back(tile);
    }
    
    //source image
    sourceImage.resize(cols);
    for (int i=0; i< cols; i++){
        sourceImage[i].resize(rows);
    }
    for (int i=0; i<allTiles.size(); i++){
        sourceImage[allTiles[i].originalX][allTiles[i].originalY] = allTiles[i].idNum;
    }
    
    //rows and columns
    sourceCols = cols;
    sourceRows = rows;
    _tileSize = tileSize;
}

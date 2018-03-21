//
//  Tile.h
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/19/18.
//

#ifndef Tile_h
#define Tile_h

#include "ofMain.h"

class NeighborInfo{
public:
    int idNum;
    int freq;
};

class Tile{
public:
    ofImage pic;
    int idNum;
    
    //0-N, 1-E, 2-S, 3-W
    vector<NeighborInfo> neighbors[4];
    
    void resetNeighborInfo(){
        for (int i=0; i<4; i++){
            neighbors[i].clear();
        }
    }
    
    void noteNeighbor(int dir, int neighborID){
        
        //is this already in the list?
        for (int i=0; i<neighbors[dir].size(); i++){
            if (neighbors[dir][i].idNum == neighborID){
                neighbors[dir][i].freq++;
                return;
            }
        }
        
        //if not, add it
        NeighborInfo newNeighbor;
        newNeighbor.idNum = neighborID;
        newNeighbor.freq = 1;
        neighbors[dir].push_back(newNeighbor);
        
    }
    
    
};

#endif /* Tile_h */

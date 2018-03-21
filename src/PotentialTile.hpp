//
//  PotentialTile.hpp
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/20/18.
//

#ifndef PotentialTile_hpp
#define PotentialTile_hpp

#include "ofMain.h"
#include "Tile.h"

enum tileState { STATE_INACTIVE, STATE_ACTIVE, STATE_SET };

class PotentialTile{
public:
    
    void reset(int maxNumIDs, int _x, int _y);
    void set(int id);
    int getRandPotentialID();
    
    void ruleOutBasedOnNeightbor(Tile other, int dirToCheck);
    void ruleOutID(int id);
    
    tileState state;
    vector<int> potentialIDs;
    int setID;
    
    int x,y;
    
};

#endif /* PotentialTile_hpp */

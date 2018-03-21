//
//  PotentialTile.cpp
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/20/18.
//

#include "PotentialTile.hpp"


void PotentialTile::reset(int maxNumIDs, int _x, int _y){
    state = STATE_INACTIVE;
    potentialIDs.clear();
    for (int i=0; i<maxNumIDs; i++){
        potentialIDs.push_back(i);
    }
    setID = -1;
    
    x = _x;
    y = _y;
}

void PotentialTile::set(int id){
    state = STATE_SET;
    setID = id;
    potentialIDs.clear();
}

int PotentialTile::getRandPotentialID(){
    return potentialIDs[ (int)ofRandom(potentialIDs.size())];
}

void PotentialTile::ruleOutBasedOnNeightbor(Tile other, int dirToCheck){
    //ignore this if we've already been set
    if (state == STATE_SET){
        return;
    }
    
    //if this is having this removed, it must have a neighbor
    state = STATE_ACTIVE;
    
    vector<int> goodIDs;
    for (int i=0; i<other.neighbors[dirToCheck].size(); i++){
        goodIDs.push_back(other.neighbors[dirToCheck][i].idNum);
    }
    
    //go though and rmeove any IDs of mine that are not good IDs
    for (int i=potentialIDs.size()-1; i>=0; i--){
        bool isGood = false;
        for (int k=0; k<goodIDs.size(); k++){
            if (potentialIDs[i] == goodIDs[k]){
                isGood = true;
            }
        }
        
        if (!isGood){
            potentialIDs.erase(potentialIDs.begin() + i);
        }
    }
    
    //testing
//    cout<<"remaaining: ";
//    for (int i=potentialIDs.size()-1; i>=0; i--){
//        cout<<potentialIDs[i]<<",";
//    }
//    cout<<endl;
}


void PotentialTile::ruleOutID(int id){
    for (int i=potentialIDs.size()-1; i>=0; i--){
        if (potentialIDs[i] == id){
            potentialIDs.erase( potentialIDs.begin()+i );
        }
    }
}

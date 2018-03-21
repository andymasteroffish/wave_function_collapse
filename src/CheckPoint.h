//
//  CheckPoint.h
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/20/18.
//

#ifndef CheckPoint_h
#define CheckPoint_h

#include "ofMain.h"

class MoveInfo{
public:
    
    int col;
    int row;
    int idNum;
    
    void clear(){
        col = -1;
        row = -1;
        idNum = -1;
    }
    
    void set(int _col, int _row, int _id){
        col = _col;
        row = _row;
        idNum = _id;
    }
    
};

class CheckPoint{
public:
    
    CheckPoint * prevPoint;
    CheckPoint * nextPoint;
    
    MoveInfo thisMove;
    
    vector<MoveInfo> badMoves;  //these will be rules out even though they may seem OK just from reading the board
    
   CheckPoint(CheckPoint * _prevMove){
        prevPoint = _prevMove;
        if (prevPoint != NULL){
            prevPoint->nextPoint = this;
        }
        
        nextPoint = NULL;
        
        thisMove.clear();
    }
    
    void move(int col, int row, int idNum){
        thisMove.set(col, row, idNum);
        //cout<<"set move: "<<col<<","<<row<<":"<<idNum<<endl;
    }
    
    void ruleOutMove(MoveInfo _bad){
        MoveInfo bad;
        bad.set(_bad.col, _bad.row, _bad.idNum);
        badMoves.push_back(bad);
    }
    
    void prune(){
        
        if (nextPoint != NULL){
            nextPoint->badMoves.clear();
            nextPoint->prune();
            delete nextPoint;
        }
        
        nextPoint = NULL;
        
    }
    
    int getDepth(){
        if (prevPoint == NULL){
            return 0;
        }else{
            return prevPoint->getDepth()+1;
        }
    }
    
    
    
};


#endif /* CheckPoint_h */

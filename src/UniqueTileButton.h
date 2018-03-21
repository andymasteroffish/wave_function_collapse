//
//  UniqueTileButton.h
//  wave_function_collapse
//
//  Created by Andrew Wallace on 3/21/18.
//

#ifndef UniqueTileButton_h
#define UniqueTileButton_h

#include "ofMain.h"

class UniqueTileButton{
public:
  
    ofRectangle box;
    int idNum;
    
    void setup(int x, int y, int tileSize, int _id){
        box.x = x;
        box.y = y;
        box.width = tileSize;
        box.height = tileSize;
        idNum = _id;
    }
    
    bool checkClick(int mouseX, int mouseY){
        return box.inside(mouseX, mouseY);
    }
    
    void draw(ofImage pic, bool isSelected){
        ofSetColor(255);
        pic.draw(box.x, box.y, box.width, box.height);
        
        if (isSelected){
            ofSetColor(0);
            ofDrawRectangle(box.x-1, box.y-1, box.width+2, box.height+2);
            ofDrawRectangle(box.x-2, box.y-2, box.width+4, box.height+4);
        }
    }
    
};


#endif /* UniqueTileButton_h */


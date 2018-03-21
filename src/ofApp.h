#pragma once

#include "ofMain.h"
#include "Tile.h"
#include "CheckPoint.h"
#include "PotentialTile.hpp"
#include "CheckPoint.h"

#include "TileCutter.hpp"
#include "UniqueTileButton.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void resizeOutput(int newCols, int newRows);
    void reset();
    void doFirstMove();
    
    void setSourceFromString(string map);
    void setNeightborInfo();
    
    void advance();
    vector<NeighborInfo> getTileChoicesWithFreq(int col, int row);
    void updateBoardFromMove(CheckPoint * point);
    void validateBoard();
    
    void update();
    void draw();
    
    void resetOutput();
    void revertToCheckPoint(CheckPoint * point);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void drawOnSourceImage(int x, int y, int newID);
    
    int tileSize;
    vector<Tile> sourceTiles;
    
    bool needFirstMove;
    bool needToGetNeighborInfo;
    bool isDone;
    
    int sourceCols, sourceRows;
    vector< vector<int> > sourceImage;
    
    int outputCols, outputRows;
    vector< vector<PotentialTile> > outputImage;
    
    CheckPoint * rootMove;
    CheckPoint * curMove;
    
    TileCutter tileCutter;
    bool useTileCutter;
    
    vector<UniqueTileButton> uniqueButtons;
    int curSelectedButton;
    
    bool autoPlay;
    bool fastForward;
    bool useFreq;
    float freqWeight;
    
		
};

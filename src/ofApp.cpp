 #include "ofApp.h"

//tiles from https://opengameart.org/content/simple-nes-like-platformer-tiles

//--------------------------------------------------------------
void ofApp::setup(){
    autoPlay = true;
    fastForward = true;
    
    //load in the tiles
    for (int i=0; i<90; i++){
        Tile tile;
        tile.pic.load("tiles/tile_"+ofToString(i)+".png");
        tile.idNum = i;
        sourceTiles.push_back(tile);
    }
    
    tileSize = sourceTiles[0].pic.getWidth();
    
    string map = "";
    map+="0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,\n";
    map+="3,3,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,\n";
    map+="3,8,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,6,9,10,2,2,2,2,2,2,2,2,2,2,2,2,11,2,2,2,12,\n";
    map+="3,3,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,13,14,13,14,2,15,16,17,5,6,2,2,2,2,2,2,18,2,2,11,19,\n";
    map+="19,20,19,21,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,22,23,22,23,2,24,25,26,9,10,2,2,2,2,2,2,18,2,2,18,27,\n";
    map+="27,27,27,28,2,2,2,2,2,2,2,2,2,2,2,2,2,2,29,20,19,20,19,21,30,31,32,22,23,2,2,2,2,2,2,33,2,2,33,27,\n";
    map+="27,27,27,34,2,2,2,2,2,2,2,2,35,36,2,2,2,2,37,27,27,27,27,28,19,19,19,20,19,21,2,2,2,2,38,39,40,38,41,42,\n";
    map+="27,27,34,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,43,27,27,27,27,27,27,27,27,27,27,28,2,2,44,38,45,46,40,47,45,2,\n";
    map+="43,34,2,2,2,2,2,48,49,2,2,2,2,2,2,2,2,2,2,43,42,27,27,27,27,42,42,42,42,34,2,2,35,50,46,2,40,2,47,2,\n";
    map+="2,2,2,2,2,29,20,19,20,19,21,2,2,2,2,2,2,2,2,2,2,37,27,27,28,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,\n";
    
    
    map+="2,2,2,2,2,43,27,27,27,42,34,2,2,2,2,2,2,2,2,2,2,43,42,42,34,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,\n";
    map+="2,2,2,2,2,2,43,42,34,2,2,2,2,2,35,36,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,51,2,2,2,2,2,\n";
    map+="2,2,2,2,2,2,2,2,2,2,2,2,52,53,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,54,55,56,2,2,2,2,\n";
    map+="2,2,2,2,2,2,2,2,2,2,2,57,58,59,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,60,61,62,54,56,2,2,\n";
    map+="2,2,2,2,2,2,2,2,2,2,29,19,20,21,2,2,2,2,2,2,2,2,2,2,52,53,2,2,2,2,2,2,2,63,64,65,63,65,2,2,\n";
    map+="2,2,2,2,66,2,35,36,2,2,43,42,42,34,2,2,2,2,2,2,2,2,2,2,67,68,2,52,53,2,2,2,29,20,19,20,19,20,19,2,\n";
    map+="2,2,2,2,69,57,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,58,59,70,58,59,2,2,2,37,27,27,27,27,27,27,2,\n";
    map+="2,2,2,2,29,19,21,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,71,72,73,71,72,70,2,51,37,27,27,27,27,27,27,2,\n";
    map+="2,74,2,2,43,42,34,2,2,2,2,75,76,2,2,2,2,2,2,2,2,2,2,2,29,20,19,20,19,21,77,78,37,27,27,27,27,27,27,2,\n";
    map+="2,79,74,2,2,2,2,2,74,29,20,19,21,2,2,2,2,2,75,76,2,2,2,2,37,27,27,27,27,28,2,2,37,27,27,27,27,27,27,2,\n";
    
    map+="2,80,79,2,2,2,81,2,80,37,27,27,28,2,70,2,81,2,29,21,2,2,82,83,37,27,27,27,27,28,2,2,37,27,27,27,27,27,27,84,\n";
    map+="84,84,85,84,84,84,84,85,84,37,27,27,28,84,86,84,84,84,37,28,85,84,87,88,37,27,27,27,27,28,84,84,37,27,27,27,27,27,27,89,\n";
    map+="89,89,89,89,89,89,89,89,89,37,27,27,28,89,89,89,89,89,37,28,89,89,89,89,37,27,27,27,27,28,89,89,37,27,27,27,27,27,27,89,\n";
    map+="89,89,89,89,89,89,89,89,89,37,27,27,28,89,89,89,89,89,37,28,89,89,89,89,37,27,27,27,27,28,89,89,37,27,27,27,27,27,27,\n";
     
    
    setSourceFromString(map);

    setNeightborInfo();
    
    
    rootMove = new CheckPoint(NULL);
    
    resetOutput();
    doFirstMove();
    
}

//--------------------------------------------------------------
void ofApp::doFirstMove(){
    //start us off
    rootMove->prune();
    curMove = new CheckPoint(rootMove);
    curMove->move(ofRandom(OUTPUT_COLS), ofRandom(OUTPUT_ROWS), ofRandom(sourceTiles.size())) ;
    updateBoardFromMove(curMove);
}

//--------------------------------------------------------------
void ofApp::setSourceFromString(string map){
    int curX = 0;
    int curY = 0;
    for (int i=0; i<map.length(); i++){
        if (map[i] == ','){
            curX++;
        }
        else if (map[i] == '\n'){
            curX=0;
            curY++;
        }
        else {
            string numString = "x";
            numString[0] = map[i];
            
            if (map[i+1] != ','){
                numString += map[i+1];
                i++;
            }
            
            int idNum = ofToInt(numString);
            //cout<<curX<<","<<curY<<" id: "<<idNum<<endl;
            if (curX < SOURCE_COLS){    //my source image was fucked up so I'm getting rid of the last column
                sourceImage[curX][curY] = idNum;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::setNeightborInfo(){
    for (int i=0; i<sourceTiles.size(); i++){
        sourceTiles[i].resetNeighborInfo();
    }
    
    for (int x=0; x<SOURCE_COLS; x++){
        for (int y=0; y<SOURCE_ROWS; y++){
            int id = sourceImage[x][y];
            
            //check to the north
            if (y>0){
                sourceTiles[id].noteNeighbor(0, sourceImage[x][y-1]);
            }
            
            //check to the east
            if (x<SOURCE_COLS-1){
                sourceTiles[id].noteNeighbor(1, sourceImage[x+1][y]);
            }
            
            //check to the south
            if (y<SOURCE_ROWS-1){
                sourceTiles[id].noteNeighbor(2, sourceImage[x][y+1]);
            }
            
            //check to the west
            if (x>0){
                sourceTiles[id].noteNeighbor(3, sourceImage[x-1][y]);
            }
            
        }
    }
    
//    for (int i=0; i<sourceTiles.size(); i++){
//        cout<<endl;
//        cout<<"TILE "<<i<<endl;
//        string label [4] = { "North", "East", "South", "West" };
//        
//        for (int k=0; k<4; k++){
//            cout<<"  "<<label[k]<<endl;
//            for (int j=0; j<sourceTiles[i].neighbors[k].size(); j++){
//                cout<<"    "<<sourceTiles[i].neighbors[k][j].idNum<<","<<sourceTiles[i].neighbors[k][j].freq<<endl;
//            }
//        }
//        
//    }
    
}

//--------------------------------------------------------------
void ofApp::advance(){
    //cout<<"advance"<<endl;
    CheckPoint * oldMove = curMove;
    curMove = new CheckPoint(oldMove);
    
    //cout<<"move "<<curMove->getDepth()<<endl;
    
    //make a list of the active potential tiels with the fewest posibilits
    int lowVal = sourceTiles.size()+1;
    for (int x=0; x<OUTPUT_COLS; x++){
        for (int y=0; y<OUTPUT_ROWS; y++){
            if (outputImage[x][y].state == STATE_ACTIVE && outputImage[x][y].potentialIDs.size() < lowVal){
                lowVal = outputImage[x][y].potentialIDs.size();
            }
        }
    }
    
    vector<PotentialTile> choices;
    for (int x=0; x<OUTPUT_COLS; x++){
        for (int y=0; y<OUTPUT_ROWS; y++){
            if (outputImage[x][y].state == STATE_ACTIVE && outputImage[x][y].potentialIDs.size() == lowVal){
                choices.push_back(outputImage[x][y]);
            }
        }
    }
    
    if (choices.size() == 0){
        cout<<"all done!"<<endl;
        autoPlay = false;
        return;
    }
    
    //select one at random
    int thisChoice = (int) ofRandom(choices.size());
    //select a tile at random
    int thisTile = (int) ofRandom(choices[thisChoice].potentialIDs.size());
    //make a move
    curMove->move( choices[thisChoice].x, choices[thisChoice].y, choices[thisChoice].potentialIDs[thisTile]);
    
}

//--------------------------------------------------------------
void ofApp::updateBoardFromMove(CheckPoint * point){
    //cout<<"update board"<<endl;
    MoveInfo move = point->thisMove;
    if (move.col == -1){
        cout<<"empty move"<<endl;
        return;
    }
    
    //set the given tiles
    outputImage[move.col][move.row].set(move.idNum);
    
    //rule out anything we need to because it previously lead to dead ends
    for (int i=0; i<point->badMoves.size(); i++){
        MoveInfo badMove = point->badMoves[i];
        outputImage[badMove.col][badMove.row].ruleOutID(badMove.idNum);
        cout<<"hey brah don't do "<<badMove.col<<","<<badMove.row<<": "<<badMove.idNum<<endl;
    }
    
    //go through the neighbors and update them
    
    //north
    if (move.row > 0){
        outputImage[move.col][move.row-1].ruleOutBasedOnNeightbor( sourceTiles[outputImage[move.col][move.row].setID], 0);
    }
    
    //east
    if (move.col < OUTPUT_COLS-1){
        outputImage[move.col+1][move.row].ruleOutBasedOnNeightbor( sourceTiles[outputImage[move.col][move.row].setID], 1);
    }
    
    //south
    if (move.row < OUTPUT_ROWS-1){
        outputImage[move.col][move.row+1].ruleOutBasedOnNeightbor( sourceTiles[outputImage[move.col][move.row].setID], 2);
    }
    
    //west
    if (move.col > 0){
        outputImage[move.col-1][move.row].ruleOutBasedOnNeightbor( sourceTiles[outputImage[move.col][move.row].setID], 3);
    }
    
    //validate
    validateBoard();
}

//--------------------------------------------------------------
//if any potential tiles have no options, this move is dirt!
void ofApp::validateBoard(){
    bool boardIsValid = true;
    for (int x=0; x<OUTPUT_COLS; x++){
        for (int y=0; y<OUTPUT_ROWS; y++){
            if (outputImage[x][y].state == STATE_ACTIVE && outputImage[x][y].potentialIDs.size() == 0){
                cout<<x<<","<<y<<" is no good!"<<endl;
                boardIsValid = false;
            }
        }
    }
    
    if (!boardIsValid){
        //autoPlay = false;
        curMove->prevPoint->ruleOutMove(curMove->thisMove);
        revertToCheckPoint(curMove->prevPoint);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (autoPlay){
        int cycles = 1;
        if (fastForward){
            cycles = 30;
        }
        for (int i=0; i<cycles; i++){
            advance();
            updateBoardFromMove(curMove);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    for (int x=0; x<SOURCE_COLS; x++){
        for (int y=0; y<SOURCE_ROWS; y++){
            sourceTiles[ sourceImage[x][y] ].pic.draw( x*tileSize, y*tileSize);
        }
    }

    ofPushMatrix();
    ofTranslate(SOURCE_COLS*tileSize+tileSize, 0);
    for (int x=0; x<OUTPUT_COLS; x++){
        for (int y=0; y<OUTPUT_ROWS; y++){
            
            ofPushMatrix();
            ofTranslate(x*tileSize, y*tileSize);
            
            ofFill();
            if (outputImage[x][y].state == STATE_INACTIVE){
                ofSetColor(50);
                ofDrawRectangle(0, 0, tileSize, tileSize);
            }
            if (outputImage[x][y].state == STATE_ACTIVE){
                ofSetColor(170);
                ofDrawRectangle(0, 0, tileSize, tileSize);
                ofSetColor(0);
                ofDrawBitmapString( ofToString(outputImage[x][y].potentialIDs.size()), tileSize*0.25, tileSize*0.75);
            }
            if (outputImage[x][y].state == STATE_SET){
                ofSetColor(255);
                sourceTiles[ outputImage[x][y].setID ].pic.draw( 0,0 );
            }
            
            ofNoFill();
            ofSetColor(0);
            ofDrawRectangle(0, 0, tileSize, tileSize);
            
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
    
    ofSetColor(0);
    ofDrawBitmapString("auto: "+ofToString(autoPlay), 10,ofGetHeight()-50);
    ofDrawBitmapString("fast: "+ofToString(fastForward), 10,ofGetHeight()-30);
    
}

//--------------------------------------------------------------
void ofApp::resetOutput(){
    for (int x=0; x<OUTPUT_COLS; x++){
        for (int y=0; y<OUTPUT_ROWS; y++){
            outputImage[x][y].reset(sourceTiles.size(), x, y);
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::revertToCheckPoint(CheckPoint * point){
    cout<<"REVERT to "<<point->getDepth()<<endl;
    resetOutput();
    
    curMove = rootMove;
    //int steps =0;
    while(curMove != point){
        //steps++;
        //cout<<"step: "<<steps<<endl;
        updateBoardFromMove(curMove);
        curMove = curMove->nextPoint;
    }
    
    updateBoardFromMove(curMove);
    
    curMove->prune();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        advance();
        updateBoardFromMove(curMove);
    }
    
    if (key == 'z'){
        curMove->prevPoint->ruleOutMove(curMove->thisMove);
        revertToCheckPoint(curMove->prevPoint);
    }
    
    if (key == 'a'){
        autoPlay = !autoPlay;
    }
    if (key == 'f'){
        fastForward = !fastForward;
    }
    
    if (key == 'r'){
        resetOutput();
        doFirstMove();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

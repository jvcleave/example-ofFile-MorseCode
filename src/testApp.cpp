#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
	
	currentIndex = 0;

	string filePath = "morse.csv";
	font.loadFont("frabk.ttf", 122);
	
	//Load file placed in bin/data
	ofFile file = ofFile(filePath);
	if(!file.exists())
	{
		ofLogError(filePath + " is missing");
	}
	
	ofBuffer buffer(file);
	
	while (!buffer.isLastLine()) 
	{
		string line = buffer.getNextLine();
		vector<string> words = ofSplitString(line, ",", false, true);
		for (int i=0; i<words.size(); i++) 
		{
			MorseCodeSymbol symbol;
			symbol.character = words[0];
			symbol.code = words[1];
			morseCodeSymbols.push_back(symbol);
		}
	}
	player.setup();
}

//--------------------------------------------------------------
void testApp::update()
{
	player.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
	string output = currentSymbol.character + "\n" + currentSymbol.code;
	font.drawString(output, (ofGetWidth() - font.stringWidth(output))/2, ofGetHeight()/2);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	string myKey;
	myKey = (char) key;
	
	for (int i=0; i<morseCodeSymbols.size(); i++)
	{
		if (morseCodeSymbols[i].character == ofToUpper(myKey))
		{
			currentSymbol = morseCodeSymbols[i];
			player.playCode(currentSymbol.code);
			return;
		}
		
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{
	

}





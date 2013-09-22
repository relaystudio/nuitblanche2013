#pragma once

#include "ofMain.h"
#include "Viewport.h"
#include "camera.h"
#include "particles.h"

#define N_PROJECTOR 4
#define N_LAYER 5


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        // Graphics mode
        void drawGraphics();
        void updateGraphics();
        void drawDebug();
    
        // Edit mode
        void setEditMode(bool active);
        bool getEditMode();
        void updateEdit();
        void drawEdit();
        void drawEditGrid();
        void saveEditted();
        void resetCurrent();
        void exportSettings();
        void reloadSettings();
    
        //Events
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        int pw, ph; // Projector width/height;
        float cvDebug;
    
        ofFbo fbo; // Primary muxed output
        ofFbo mask; // Masking layer
        ofFbo cont; // Particles layer
        ofShader shader;
        ofShader alpha; // Alpha masks
        ofFbo canvas; // Project + Draw
    
        Camera * cam;
    
        Viewport * pview[N_PROJECTOR];
        Particles * part;
        ofTrueTypeFont ttf;
    
	
        vector<ofRectangle> rect; // Holdes the editing rectangles
        ofPoint currentPoint;
        ofRectangle * rectBuf; // Holds cur buffer
    
        bool edit, save, debug;
        int editLayer;
        int editCanvas;
};

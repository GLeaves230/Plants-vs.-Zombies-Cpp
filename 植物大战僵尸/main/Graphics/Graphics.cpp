#ifndef GRAPHICS_MAIN
#define GRAPHICS_MAIN
#include "Graphics.h"
#include "..\\ClassInclude.cpp"
#include "..\\main.cpp"
#include "..\\LawnApp\\LawnAppMain.cpp"
class Graphics {
public:
	LawnApp* mApp;
	floatRect ClearRect;
	floatRect DrawRect;
	intColor DrawColor;
	GameImage mImage = GameImage(1, 0);
	Graphics() {
		ClearRect.left = 0;
		ClearRect.top = 0;
		ClearRect.widht = 0;
		ClearRect.height = 0;
		DrawRect.left = 0;
		DrawRect.top = 0;
		DrawRect.widht = 0;
		DrawRect.height = 0;
		DrawColor.R = 0;
		DrawColor.G = 0;
		DrawColor.B = 0;
		DrawColor.A = 0;
	}

	~Graphics() {
	}
	void SetImageSize(int Widht,int Height) {
		mImage.Init(Widht, Height);
	}
	void Draw() {
	}
}; 
#endif

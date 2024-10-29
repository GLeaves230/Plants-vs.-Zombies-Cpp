#ifndef BOARD_MAIN
#define BOARD_MAIN
#include "..\\..\\ClassInclude.cpp"
#include "..\\..\\Graphics\\Graphics.cpp"
#include "..\\LawnAppMain.cpp"
class Board {
public:
	LawnApp* mApp;

	Board() {
	}

	~Board() {
	}

	void update() {

	}

	void init(LawnApp* mApp) {
	}

	void draw(Graphics* mGar) {
		mGar->ClearRect.draw(mGar);
	}
};
#endif
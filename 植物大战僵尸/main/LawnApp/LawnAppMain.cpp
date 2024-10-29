#ifndef LAWN_APP_MAIN
#define LAWN_APP_MAIN
#include "..\\ClassInclude.cpp"
#include "..\\Graphics\\Graphics.cpp"
#include "Board\\BoardMain.cpp"
class LawnApp {
public:
	Board* mBoard;
	Graphics* mGra;
	int a;
	LawnApp() {
		mBoard = NULL;
		mGra = NULL;
	}

	~LawnApp() {
		if (mBoard != NULL)
			delete mBoard;

		if (mGra != NULL)
			delete mGra;
	}

	void update() {

	}

	void init() {
	}

	void del() {
	}
};
#endif
#include "..\\..\\ClassInclude.cpp"

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
		mApp->a = 2;
	}
};
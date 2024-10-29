#include "..\\ClassInclude.cpp"

class LawnApp {
public:
	Board* mBoard;
	int a;
	LawnApp() {
		a = 1;
	}

	~LawnApp() {
		if (mBoard != NULL)
			delete mBoard;
	}

	void update() {

	}

	void init() {
	}

	void del() {
	}
};
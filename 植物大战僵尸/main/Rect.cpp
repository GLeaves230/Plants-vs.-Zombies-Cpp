#ifndef RECT_MAIN
#define RECT_MAIN
#include "ClassInclude.cpp"
#include "Graphics\\Graphics.cpp"
#include "main.cpp"
class intRect {
public:
	int left;
	int top;
	int widht;
	int height;
	intRect() {
	}

	~intRect() {
	}

	void draw(Graphics* mGra) {
	}
};

class floatRect {
public:
	float left;
	float top;
	float widht;
	float height;
	floatRect() {
	}

	~floatRect() {
	}
	void draw(Graphics* mGra) {
	}
};
#endif

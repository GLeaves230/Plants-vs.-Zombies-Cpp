#ifndef MAIN_CPP
#define  MAIN_CPP
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
#include "ClassInclude.cpp"
class intPoint {
public:
	int left;
	int top;
	intPoint() {
	}
	~intPoint() {
	}
};

class intRect : public intPoint {
public:
	int widht;
	int height;
	intRect() {
	}

	~intRect() {
	}

	void draw(Graphics* mGra) {
	}
};
class floatPoint {
public:
	float left;
	float top;
	floatPoint() {
	}
	~floatPoint() {
	}
};
class floatRect : public floatPoint {
public:
	float widht;
	float height;
	floatRect() {
	}

	~floatRect() {
	}
	void draw(Graphics* mGra) {
	}
};

class intColor {
public:
	int R;
	int G;
	int B;
	int A;
	intColor() {
	}

	~intColor() {
	}
};

class intDrawPoint : public intPoint {
public:
	intColor Color;
};

class floatDrawPoint : public floatPoint {
public:
	intColor Color;
};
#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;
#include "ScreenImage.cpp"
ScreenImage* mScr = new ScreenImage;
#include "Image.cpp"
#include "LawnApp\\LawnAppMain.cpp"
#include "LawnApp\\GameWindow\\GameWindowMain.cpp"
#include "LawnApp\\Board\\BoardMain.cpp"
#include "Graphics\\Graphics.cpp"
#endif


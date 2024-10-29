#ifndef GAME_IMAGE
#define GAME_IMAGE
#include "main.cpp"
class GameImage {
public:
	intRect DrawRect;
	floatDrawPoint point[WINDOW_WIDTH][WINDOW_HEIGHT];
	GameImage(int Width,int Height) {
		Init(Width, Height);
	}

	~GameImage(){
	}

	void Init(int Width, int Height) {
		DrawRect.left = 0;
		DrawRect.top = 0;
		DrawRect.widht = Width;
		DrawRect.height = Height;
		InitAllColor();
	}

	void InitAllColor() {
		for (int i = 0; i < DrawRect.widht; i++) {
			for (int j = 0; j < DrawRect.height; j++) {
				point[i][j] = floatDrawPoint();
				point[i][j].left = i;
				point[i][j].top = j;
				point[i][j].Color.A = 0;
				point[i][j].Color.R = 0;
				point[i][j].Color.G = 0;
				point[i][j].Color.B = 0;
			}
		}
	}

	void Draw() {
		for (int i = 0; i < DrawRect.widht; i++) {
			for (int j = 0; j < DrawRect.height; j++) {
				floatDrawPoint a = point[i][j];
				DrawPoint(a);
			}
		}
	}
	void DrawPoint(floatDrawPoint DrawPoint) {
		mScr->SetPoint(DrawPoint);
	}
	void Claer() {
		for (int i = 0; i < DrawRect.widht; i++) {
			for (int j = 0; j < DrawRect.height; j++) {
				point[i][j].Color.A = 255;
				point[i][j].Color.R = 255;
				point[i][j].Color.G = 255;
				point[i][j].Color.B = 255;
				floatDrawPoint a = point[i][j];
				DrawPoint(a);
			}
		}
	}
};
#endif
#ifndef SCREEN_IMAGE
#define SCREEN_IMAGE
#include "main.cpp"
class ScreenImage {
public:
	intRect DrawRect;
	HDC hdc;
	PAINTSTRUCT ps;
	HWND hwnd;
	floatDrawPoint point[WINDOW_WIDTH][WINDOW_HEIGHT];
	ScreenImage() {
		Init();
	}

	~ScreenImage() {
	}
	void Ready(HDC hdc, PAINTSTRUCT ps, HWND hwnd) {
		this->hdc = hdc;
		this->ps = ps;
		this->hwnd = hwnd;
	}

	void Init() {
		DrawRect.left = 0;
		DrawRect.top = 0;
		DrawRect.widht = WINDOW_WIDTH;
		DrawRect.height = WINDOW_HEIGHT;
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

	void SetPoint(floatDrawPoint DrawPoint) {
		int i = DrawPoint.left;
		int j = DrawPoint.top;
		point[i][j].Color.A = DrawPoint.Color.A;
		point[i][j].Color.R = DrawPoint.Color.R;
		point[i][j].Color.G = DrawPoint.Color.G;
		point[i][j].Color.B = DrawPoint.Color.B;
		this->DrawPoint(DrawPoint);
	}

	void DrawPoint(floatDrawPoint DrawPoint) {
		SetPixel(hdc, DrawPoint.left, DrawPoint.top, RGB(DrawPoint.Color.R, DrawPoint.Color.G, DrawPoint.Color.B));
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
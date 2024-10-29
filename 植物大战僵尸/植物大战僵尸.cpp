#ifndef PLANCT_VS_ZOMBIES_CPP
#define PLANCT_VS_ZOMBIES_CPP
#include "main\\main.cpp"
LawnApp* mApp = new LawnApp;
Graphics* mGra = new Graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	switch (uMsg) {
	case WM_DESTROY:										    //退出程序
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN: {										//鼠标按下事件
		break;
		}
	case WM_KEYDOWN: {											//键盘按下事件
		break;
		}
	case WM_PAINT: {
		hdc = BeginPaint(hwnd, &ps);//绘制事件
		mScr->Ready(hdc, ps, hwnd);
		mScr->Draw();
		mScr->Claer();
		mScr->InitAllColor();
		EndPaint(hwnd, &ps);
		break;
		}
	default: {
		break;
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
struct GameMsg : public tagMSG {
};
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASS Head = {};
	Head.hInstance = hInstance;                               // 应用程序实例句柄
	Head.lpszClassName = TEXT("Plants vs. Zombies");                        // 窗口类名称
	Head.lpfnWndProc = WindowProc;							  // 设置消息处理函数指针
	RegisterClass(&Head);									  // 注册窗口类
	HWND Window = CreateWindowEx(0, TEXT("Plants vs. Zombies"), TEXT("植物大战僵尸"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL); // 创建窗口
	if (Window == NULL) {
		return 0;											 // 如果创建窗口失败，返回0
	}
	ShowWindow(Window, nCmdShow);							 // 显示
	UpdateWindow(Window);									 // 更新
	mApp->mGra = mGra;
	mGra->mApp = mApp;
	
	GameMsg msg = {};											 // 定义消息变量
	while (GetMessage(&msg, NULL, 0, 0)) {					 // 进入消息循环
		TranslateMessage(&msg);								 // 转换消息格式
		DispatchMessageW(&msg);								 // 分发消息给相应的窗口过程函数处理
	}														 // 作销毁处理
	delete mApp;
	delete mScr;
	return msg.wParam;										 // 返回程序退出值
};
#endif
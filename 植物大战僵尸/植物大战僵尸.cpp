#include "main\\main.cpp"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASS Head = {};
	Head.hInstance = hInstance;                               // 应用程序实例句柄
	Head.lpszClassName = TEXT("Plants vs. Zombies");                        // 窗口类名称
	Head.lpfnWndProc = WindowProc;							  // 设置消息处理函数指针
	RegisterClass(&Head);									  // 注册窗口类
	HWND Window = CreateWindowEx(0, TEXT("Plants vs. Zombies"), TEXT("植物大战僵尸"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL); // 创建窗口
	if (Window == NULL) {
		return 0;											 // 如果创建窗口失败，返回0
	}
	ShowWindow(Window, nCmdShow);							 // 显示
	UpdateWindow(Window);									 // 更新

	MSG msg = {};											 // 定义消息变量
	LawnApp* mApp = new LawnApp;
	Board* mBorad = new Board;
	mBorad->mApp = mApp;
	mApp->mBoard = mBorad;
	
	while (GetMessage(&msg, NULL, 0, 0)) {					 // 进入消息循环
		mApp->update();
		mApp->mBoard->mApp->mBoard->init(mApp);
		TranslateMessage(&msg);								 // 转换消息格式
		DispatchMessage(&msg);								 // 分发消息给相应的窗口过程函数处理
	}														 // 作销毁处理
	delete mApp;
	return msg.wParam;										 // 返回程序退出值
};
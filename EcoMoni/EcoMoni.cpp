#include "stdafx.h"
#include "EcoMoni.h"

using namespace std;

const LPARAM MONITOR_ON = -1;
const LPARAM MONITOR_OFF = 2;

int main() {
	// 一定時間経過したらモニターをオフにし、マウスカーソルの位置を監視する.
	SleepEx(1000, true);

	POINT point;
	GetCursorPos(&point);
	int x = point.x;
	int y = point.y;

	// マウスが動くまでループする.
	while (true) {
		// 一定時間スリープする.
		SleepEx(100, true);

		// モニタをオフにする.
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, MONITOR_OFF);

		GetCursorPos(&point);
#ifdef _DEBUG
		cout << "Mouse poisition: " << point.x << ", " << point.y << endl;
#endif
		if (x != point.x || y != point.y) {
			break;
		}

		x = point.x;
		y = point.y;
	}

	// モニタをオンにする.
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, MONITOR_ON);

#ifdef _DEBUG
	pause();
#endif
	return 0;
}

void pause() {
	cout << "Hit Enter key" << endl;
	char line[2];
	fgets(line, sizeof(line), stdin);
}

#include "stdafx.h"
#include "EcoMoni.h"

using namespace std;

const LPARAM MONITOR_ON = -1;
const LPARAM MONITOR_OFF = 2;

int main() {
	// ��莞�Ԍo�߂����烂�j�^�[���I�t�ɂ��A�}�E�X�J�[�\���̈ʒu���Ď�����.
	SleepEx(1000, true);

	POINT point;
	GetCursorPos(&point);
	int x = point.x;
	int y = point.y;

	// �}�E�X�������܂Ń��[�v����.
	while (true) {
		// ��莞�ԃX���[�v����.
		SleepEx(100, true);

		// ���j�^���I�t�ɂ���.
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

	// ���j�^���I���ɂ���.
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

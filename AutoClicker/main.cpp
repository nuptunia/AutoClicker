#include <Windows.h>
#include <iostream> 
#include <string>

void run() {

	int cps = 0;

	if (cps == 0) {
		std::cout << "Enter a CPS to click: ";
		std::cin >> cps;
	}

	std::cout << "AutoClicker started. Press F6 for left click \n And F7 For right click! same to disable" << "\n";
	std::cout << "Current CPS: " + std::to_string(cps);

	bool clicking_left = false;
	bool clicking_right = false;

	while (true) {
		if (GetAsyncKeyState(VK_F6) & 1) {
			clicking_left = !clicking_left;

			std::cout << (clicking_left ? "Now clicking left!" : "Stopped clicking left") << "\n";
		} 

		if (GetAsyncKeyState(VK_F7) & 1) {
			clicking_right = !clicking_right;

			std::cout << (clicking_right ? "Now clicking left!" : "Stopped clicking left") << "\n";
		}

		if (clicking_left) {
			INPUT input = { 0 };
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &input, sizeof(INPUT)); 

			ZeroMemory(&input, sizeof(INPUT));
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP; 
			SendInput(1, &input, sizeof(INPUT)); 

			Sleep(cps);
		} 

		if (clicking_right) {
			INPUT input = { 0 };
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			SendInput(1, &input, sizeof(INPUT)); 

			ZeroMemory(&input, sizeof(INPUT)); 
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			SendInput(1, &input, sizeof(INPUT));

			Sleep(cps);
		}
		Sleep(1);
	} 
}

int main() {
	run();
	return 0;
}
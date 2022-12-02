#pragma once
#include "framework.h"
class MyTable
{
private:
    void OnInit(HWND hDlg);
    void OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);
public:
    int Run(HWND hwndParent, int id);
    INT_PTR CALLBACK DlgWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

extern void WorkTable(HWND hWnd);
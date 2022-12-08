#pragma once
#include "framework.h"
class MyTable
{
private:
    HWND hWndDlg;
    void OnInit(HWND hDlg);
    void OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);
public:
    void Run(HWND hwndParent, int id);
    INT_PTR CALLBACK DlgWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

extern void WorkTable(HWND hWnd);
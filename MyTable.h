#pragma once
#include "framework.h"
#include "Shape.h"
#include <string>

using namespace std;

class MyTable
{
private:
    HWND hWndDlg;
    HWND hWndParent;
    MyTable* pdlg;
    void OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);
public:
    void Show();
    void OnCreate(HWND hwndParent);
    void Add(wstring line);
    wstring ConnectToLine(string name, long x1, long y1, long x2, long y2);
    INT_PTR CALLBACK DlgWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};
//extern void WorkTable(HWND hWnd, HWND hDlg, int id);
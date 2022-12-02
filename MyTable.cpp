#include "MyTable.h"

static MyTable* pdlg = NULL;

static INT_PTR CALLBACK CalledWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (pdlg) return pdlg->DlgWndProc(hDlg, message, wParam, lParam);
    return (INT_PTR)FALSE;
}

INT_PTR MyTable::DlgWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        OnInit(hDlg);
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, IDCANCEL);
            break;
        }
        OnCommand(hDlg, wParam, lParam);
        break;
    }
    return (INT_PTR)FALSE;
}

void MyTable::OnInit(HWND hDlg)
{

}

void MyTable::OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{

}

int MyTable::Run(HWND hwndParent, int id)
{

    return DialogBox((HINSTANCE)GetWindowLongPtr(hwndParent, GWLP_HINSTANCE),
        MAKEINTRESOURCE(id), hwndParent, CalledWndProc);
}
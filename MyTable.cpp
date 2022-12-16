#include "MyTable.h"
#include "resource1.h"
#include <iostream>
#include <fstream>
#include <codecvt>

MyTable* pDlg;

static INT_PTR CALLBACK CalledWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (pDlg) return pDlg->DlgWndProc(hDlg, message, wParam, lParam);
    return (INT_PTR)FALSE;
}

INT_PTR MyTable::DlgWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_SYSCOMMAND:
        if (wParam == SC_CLOSE) DestroyWindow(hDlg);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, IDCANCEL);
            break;
        }
        OnCommand(hDlg, wParam, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default: break;
    }
    return (INT_PTR)FALSE;
}

void MyTable::OnCreate(HWND hwndParent)
{
    pDlg = this;
    hWndParent = hwndParent;
    hWndDlg = CreateDialog((HINSTANCE)GetWindowLongPtr(hwndParent, GWLP_HINSTANCE),
        MAKEINTRESOURCE(IDD_TABLE), hwndParent, CalledWndProc);

    ofstream file;
    file.open("Table.txt");
    file.close();
    wstring line = L"Назва\t\t\tx1\ty1\tx2\ty2";
    Add(line);
}

void MyTable::OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
    case IDOK:
        EndDialog(hDlg, IDOK);
        break;
    case IDCANCEL:
        ShowWindow(hDlg, SW_HIDE);
        break;
    default:
        break;
    }
}

void MyTable::Add(wstring line)
{
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> convert;

    fstream file;
    file.open ("Table.txt", fstream::app);
    auto str = line.c_str();
    file << convert.to_bytes(line) << endl;
    file.close();

    SendDlgItemMessage(hWndDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)line.c_str());
}

void MyTable::Show()
{
    ShowWindow(hWndDlg, 1);
}

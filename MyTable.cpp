#include "MyTable.h"
#include "resource1.h"

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
        if(pdlg) pdlg->OnInit(hDlg);
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
        if(pdlg) pdlg->OnCommand(hDlg, wParam, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default: break;
    }
    return (INT_PTR)FALSE;
}

void MyTable::OnInit(HWND hDlg)
{
    SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"²À-01");
    SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"²À-02");
    SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"²À-03");
}

void MyTable::OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
    case IDOK:
        EndDialog(hDlg, IDOK);
        break;
    default:
        break;
    }
}

void MyTable::Run(HWND hwndParent, int id)
{
    pdlg = this;
    hWndDlg = CreateDialog((HINSTANCE)GetWindowLongPtr(hwndParent, GWLP_HINSTANCE),
        MAKEINTRESOURCE(id), hwndParent, CalledWndProc);
    ShowWindow(hWndDlg, 1);
}

void WorkTable(HWND hWnd)
{
    MyTable* pt;
    pt = new MyTable;
    if (pt)
    {
        pt->Run(hWnd, IDD_TABLE);
        delete pt;
    }
}
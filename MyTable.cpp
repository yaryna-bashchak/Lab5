#include "MyTable.h"
#include "resource1.h"

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
        //if(pdlg) pdlg->OnInit(hWnd, hDlg);
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
        //if(pdlg) pdlg->
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
    pdlg = this;
    pDlg = this;
    hWndParent = hwndParent;
    hWndDlg = CreateDialog((HINSTANCE)GetWindowLongPtr(hwndParent, GWLP_HINSTANCE),
        MAKEINTRESOURCE(IDD_TABLE), hwndParent, CalledWndProc);

    wstring line = L"�����\tx1\ty1\tx2\ty2";
    Add(line);
    //SendDlgItemMessage(hWndDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)line.c_str());
    /*wchar_t buffer[40] = L"first";
    const wchar_t* string = L"   second ";
    wcsncat_s(buffer, string, 41);
    SendDlgItemMessage(hWndDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)buffer);*/
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

void MyTable::Add(wstring line)
{
    SendDlgItemMessage(hWndDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)((wstring)line).c_str());
}

void MyTable::Show()
{
    ShowWindow(hWndDlg, 1);
}

//void WorkTable(HWND hWnd, HWND hDlg, int id)
//{
//    MyTable* pt;
//    pt = new MyTable;
//    if (pt)
//    {
//        pt->Run();
//        delete pt;
//    }
//}
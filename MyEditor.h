#pragma once
#include "shapes.h"
#include "Toolbar.h"

class MyEditor
{
private:
	MyEditor() {};
	MyEditor(const MyEditor&);
	MyEditor& operator =(MyEditor&);
	static const int ARRAY_SIZE = 103;
	int COUNT_OF_OBJECTS = 0;
	Shape* pcshape[ARRAY_SIZE];
public:
	static MyEditor& getInstance()
	{
		static MyEditor instance;
		return instance;
	}
	void Start(HWND hWnd, Shape *);
	void OnLBdown(HWND hWnd);
	Shape* OnLBup(HWND hWnd);
	void OnMouseMove(HWND hWnd);
	void OnPaint(HWND hWnd);
	void OnInitMenuPopup(HWND, WPARAM);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
};
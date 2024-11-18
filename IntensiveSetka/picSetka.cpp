// picSetka.cpp: файл реализации
//

#include "pch.h"
#define my_rect lpDrawItemStruct->rcItem
#include "IntensiveSetka.h"
#include "picSetka.h"
using namespace Gdiplus;
using namespace std;


// picSetka

IMPLEMENT_DYNAMIC(picSetka, CStatic)

picSetka::picSetka()
{
	GdiplusStartupInput input;
	Status s;
	s = GdiplusStartup(&token, &input, NULL);
	if (s != Ok) MessageBox(L"s != Ok", L"Error!");
	fl_start = true;
	fl_lbutton = false;
}

picSetka::~picSetka()
{
	GdiplusShutdown(token);
}


BEGIN_MESSAGE_MAP(picSetka, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// Обработчики сообщений picSetka




void picSetka::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  Добавьте исходный код для отображения указанного элемента
	if (fl_start)
	{
		scaleX = (double)my_rect.right / x;
		scaleY = (double)my_rect.bottom / y;
		fl_start = false;
	}

	Graphics wnd(lpDrawItemStruct->hDC);
	Bitmap buffer(lpDrawItemStruct->rcItem.right, lpDrawItemStruct->rcItem.bottom, &wnd);
	Graphics draw_in_buffer(&buffer);
	Matrix matr;
	matr.Scale(scaleX, scaleY);
	PointF pt[2];

	draw_in_buffer.Clear(Color::White);

	Pen p_black(Color::Black, 2);
	for (int i = 0; i <= y; i++) //горизонтальные линии
	{
		pt[0] = PointF(0, i);
		pt[1] = PointF(x, i);
		matr.TransformPoints(pt, 2);
		draw_in_buffer.DrawLine(&p_black, pt[0], pt[1]);
	}

	for (int i = 0; i <= x; i++) //вертикальные линии
	{
		pt[0] = PointF(i, 0);
		pt[1] = PointF(i, y);
		matr.TransformPoints(pt, 2);
		draw_in_buffer.DrawLine(&p_black, pt[0], pt[1]);
	}

	FontFamily my_font_family(L"Arial");
	Gdiplus::Font my_font(&my_font_family, 14, FontStyleRegular, UnitPixel);
	SolidBrush brush_font(Color(255, 0, 0, 0));

	for (int i = 0; i < x; i++) //рисуем пси (антенны)
	{
		for (int j = 0; j < y; j++)
		{
			if (!antenna[j][i])
				continue;

			pt[0] = PointF(i, j);
			matr.TransformPoints(pt);
			draw_in_buffer.DrawString(L"Ψ", -1, &my_font, pt[0], &brush_font);
		}
	}

	wnd.DrawImage(&buffer, 0, 0, 0, 0, lpDrawItemStruct->rcItem.right, lpDrawItemStruct->rcItem.bottom, UnitPixel);
}

void picSetka::SetParam(int _x, int _y)
{
	x = _x; y = _y;
	antenna = vector<vector<bool>>(y, vector<bool>(x, true));
}


void picSetka::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	fl_lbutton = true;
	int my_x = (double)point.x / scaleX;
	int my_y = (double)point.y / scaleY;
	antenna[my_y][my_x] = !antenna[my_y][my_x];
	Invalidate(FALSE);
	CStatic::OnLButtonDown(nFlags, point);
}


void picSetka::OnMouseMove(UINT nFlags, CPoint point) //подумать как избежать перерисовки быстрой (чтобы не мелькали)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	/*if (fl_lbutton)
	{
		int my_x = (double)point.x / scaleX;
		int my_y = (double)point.y / scaleY;
		antenna[my_y][my_x] = !antenna[my_y][my_x];
		Invalidate(FALSE);
		Sleep(10);
	}*/
	CStatic::OnMouseMove(nFlags, point);
}


void picSetka::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	fl_lbutton = false;
	CStatic::OnLButtonUp(nFlags, point);
}

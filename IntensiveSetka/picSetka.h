#pragma once
#include <gdiplus.h>
#include <vector>

// picSetka

class picSetka : public CStatic
{
	DECLARE_DYNAMIC(picSetka)

public:
	picSetka();
	virtual ~picSetka();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	UINT_PTR token;
	int x;
	int y;
	double scaleX;
	double scaleY;
	bool fl_start;
	bool fl_lbutton;
	//true - ���� �������, false - ��� �������
	std::vector<std::vector<bool>> antenna;

	void SetParam(int _x, int _y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


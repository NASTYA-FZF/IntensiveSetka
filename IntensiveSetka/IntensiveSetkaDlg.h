﻿
// IntensiveSetkaDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CIntensiveSetkaDlg
class CIntensiveSetkaDlg : public CDialogEx
{
// Создание
public:
	CIntensiveSetkaDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTENSIVESETKA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

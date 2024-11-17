
// IntensiveSetka.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CIntensiveSetkaApp:
// Сведения о реализации этого класса: IntensiveSetka.cpp
//

class CIntensiveSetkaApp : public CWinApp
{
public:
	CIntensiveSetkaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CIntensiveSetkaApp theApp;

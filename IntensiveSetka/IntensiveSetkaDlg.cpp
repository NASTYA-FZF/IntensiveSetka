
// IntensiveSetkaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "IntensiveSetka.h"
#include "IntensiveSetkaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CIntensiveSetkaDlg



CIntensiveSetkaDlg::CIntensiveSetkaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INTENSIVESETKA_DIALOG, pParent)
	, lyamda(0.1)
	, R(200)
	, Ksosed(0.5)
	, maxX(400)
	, maxY(400)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIntensiveSetkaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SETKA, my_antenna);
	DDX_Control(pDX, IDC_PICINTENSIVE, pic_intensive);
	DDX_Text(pDX, IDC_EDIT1, lyamda);
	DDX_Text(pDX, IDC_EDIT2, R);
	DDX_Text(pDX, IDC_EDIT3, Ksosed);
	DDX_Text(pDX, IDC_EDIT4, maxX);
	DDX_Text(pDX, IDC_EDIT5, maxY);
}

BEGIN_MESSAGE_MAP(CIntensiveSetkaDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CIntensiveSetkaDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CIntensiveSetkaDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CIntensiveSetkaDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Обработчики сообщений CIntensiveSetkaDlg

BOOL CIntensiveSetkaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	my_antenna.SetParam(11, 11, false);
	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CIntensiveSetkaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CIntensiveSetkaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIntensiveSetkaDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	reshetka.Main(lyamda, R, Ksosed, maxX, maxY, my_antenna.GetPosAntenna());
	pic_intensive.SetMatr(reshetka.GetIntensive(), 0, 0, 0, false);
	pic_intensive.Invalidate(FALSE);
}


void CIntensiveSetkaDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	my_antenna.SetParam(my_antenna.x, my_antenna.y, false);
	my_antenna.Invalidate(FALSE);
}


void CIntensiveSetkaDlg::OnBnClickedButton3()
{
	// TODO: добавьте свой код обработчика уведомлений
	my_antenna.SetParam(my_antenna.x, my_antenna.y, true);
	my_antenna.Invalidate(FALSE);
}

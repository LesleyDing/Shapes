
// Shapes.7Dlg.h : header file
//

#pragma once


// CShapes7Dlg dialog
class CShapes7Dlg : public CDialogEx
{
// Construction
public:
	CShapes7Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPES7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
  afx_msg void OnCbnSelchangeCombo1();
private:
  void calcSquare();
  void calcCube();
  void calcRectangle();
  void calcBox();
  void calcTriangle();
  void calcPrism();
  void calcCircle();
  void calcCylinder();
public:
  afx_msg void OnEnChangeEdit5();
};

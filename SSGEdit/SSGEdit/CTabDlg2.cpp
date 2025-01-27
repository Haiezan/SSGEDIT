﻿// CTabDlg2.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg2.h"



// CTabDlg2 对话框

IMPLEMENT_DYNAMIC(CTabDlg2, CDialogEx)

CTabDlg2::CTabDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG2, pParent)
{
	arrConcMat.SetSize(20);
	arrConcMat.SetAt(0,TEXT("C15"));
	arrConcMat.SetAt(1,TEXT("C20"));
	arrConcMat.SetAt(2,TEXT("C25"));
	arrConcMat.SetAt(3,TEXT("C30"));
	arrConcMat.SetAt(4,TEXT("C35"));
	arrConcMat.SetAt(5,TEXT("C40"));
	arrConcMat.SetAt(6,TEXT("C45"));
	arrConcMat.SetAt(7,TEXT("C50"));
	arrConcMat.SetAt(8,TEXT("C55"));
	arrConcMat.SetAt(9,TEXT("C60"));
	arrConcMat.SetAt(10,TEXT("C65"));
	arrConcMat.SetAt(11,TEXT("C70"));
	arrConcMat.SetAt(12,TEXT("C75"));
	arrConcMat.SetAt(13,TEXT("C80"));
	arrConcMat.SetAt(14,TEXT("C85"));
	arrConcMat.SetAt(15,TEXT("C90"));
	arrConcMat.SetAt(16,TEXT("C95"));
	arrConcMat.SetAt(17,TEXT("C100"));
	arrConcMat.SetAt(18,TEXT("C105"));
	arrRebarMat.SetSize(15);
	arrRebarMat.SetAt(0, TEXT("HPB235"));
	arrRebarMat.SetAt(1, TEXT("HRB300"));
	arrRebarMat.SetAt(2, TEXT("HRB335"));
	arrRebarMat.SetAt(3, TEXT("HRB400"));
	arrRebarMat.SetAt(4, TEXT("HRB500"));
	arrRebarMat.SetAt(5, TEXT("CRB550"));
	arrRebarMat.SetAt(6, TEXT("CRB600H"));
	arrRebarMat.SetAt(7, TEXT("HTRB600"));
	arrRebarMat.SetAt(8, TEXT("HTRB630"));
	arrRebarMat.SetAt(9, TEXT("HRB635"));
	arrRebarMat.SetAt(10, TEXT("T63"));	
	arrSteelMat.SetSize(20);
	arrSteelMat.SetAt(0, TEXT("Q235"));
	arrSteelMat.SetAt(1, TEXT("Q345"));
	arrSteelMat.SetAt(2, TEXT("Q390"));
	arrSteelMat.SetAt(3, TEXT("Q420"));
	arrSteelMat.SetAt(4, TEXT("Q460"));
	arrSteelMat.SetAt(5, TEXT("Q500"));
	arrSteelMat.SetAt(6, TEXT("Q550"));
	arrSteelMat.SetAt(7, TEXT("Q620"));
	arrSteelMat.SetAt(8, TEXT("Q690"));
	arrSteelMat.SetAt(9, TEXT("Q235GJ"));
	arrSteelMat.SetAt(10, TEXT("Q345GJ"));
	arrSteelMat.SetAt(11, TEXT("Q390GJ"));
	arrSteelMat.SetAt(12, TEXT("Q420GJ"));
	arrSteelMat.SetAt(13, TEXT("Q460GJ"));
	arrSteelMat.SetAt(14, TEXT("Q355"));
	
}

CTabDlg2::~CTabDlg2()
{
}

void CTabDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_Grid_Beam);
}


BEGIN_MESSAGE_MAP(CTabDlg2, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_C, OnWriteDate)
END_MESSAGE_MAP()


// CTabDlg2 消息处理程序


void CTabDlg2::SetBeamData(Beam& beam, CDataFile& fin)
{
	beam.ID = fin.GetInt();
	beam.iPKPM = fin.GetInt();
	beam.iLine = fin.GetInt(); 
	beam.iType = fin.GetInt();
	beam.iSection = fin.GetInt();
	beam.iSubType = fin.GetInt();
	beam.bArtiNode1 = fin.GetInt();
	beam.bArtiNode2 = fin.GetInt();
	beam.iConcMat = fin.GetInt();
	beam.iRebarMat = fin.GetInt();
	beam.iStirrupMat = fin.GetInt();
	beam.iSteelMat = fin.GetInt();
	beam.iStory = fin.GetInt();
	beam.iStage = fin.GetInt();
	beam.iTower = fin.GetInt();
	beam.fRotateAng = fin.GetFloat();
	beam.fOffsetX1 = fin.GetFloat();
	beam.fOffsetY1 = fin.GetFloat();
	beam.fOffsetZ1 = fin.GetFloat();
	beam.fOffsetX2 = fin.GetFloat();
	beam.fOffsetY2 = fin.GetFloat();
	beam.fOffsetZ2 = fin.GetFloat();
	beam.fUpperRebarLeft = fin.GetFloat();
	beam.fUpperRebarMid = fin.GetFloat();
	beam.fUpperRebarRight = fin.GetFloat();
	beam.fLowerRebarLeft = fin.GetFloat();
	beam.fLowerRebarMid = fin.GetFloat();
	beam.fLowerRebarRight = fin.GetFloat();
	beam.fStirrupArea_D = fin.GetFloat();
	beam.fStirrupArea_UD = fin.GetFloat();
	beam.nForceParament=fin.GetInt();
	if (beam.nForceParament == 2) {
		 fin.GetInt();
		 fin.GetInt();
		 beam.fF1 = fin.GetFloat();
		 beam.fLength = fin.GetFloat();
		 fin.GetFloat();
		 fin.GetInt();
		 fin.GetInt();
		 beam.fF2 = fin.GetFloat();
		 fin.GetFloat();
		 fin.GetFloat();
	}
	beam.iMidPerformType = fin.GetInt();
	beam.iSeverePerformType = fin.GetInt();
	beam.iStructType = fin.GetInt();
	beam.iMidNormSectPerformObject = fin.GetInt();
	beam.iMidDiagSectPerformObject = fin.GetInt();
	beam.iRareNormSectPerformObject = fin.GetInt();
	beam.iRareDiagSectPerformObject = fin.GetInt();
	beam.iParaNumbers = fin.GetInt();
	if (beam.iParaNumbers == 8)
	{
		beam.fAxisFactor = fin.GetFloat();
		beam.fMomentFactor = fin.GetFloat();
		beam.fShearFactor = fin.GetFloat();
		beam.iAppendMat = fin.GetInt();
		beam.iNode1Sec = fin.GetInt();
		beam.iNode2Sec = fin.GetInt();
		beam.iShearNonlinear = fin.GetInt();
		beam.fBeamSpan = fin.GetFloat();
	}
	if (beam.iParaNumbers == 9)
	{
		beam.fAxisFactor = fin.GetFloat();
		beam.fMomentFactor = fin.GetFloat();
		beam.fShearFactor = fin.GetFloat();
		beam.iAppendMat = fin.GetInt();
		beam.iNode1Sec = fin.GetInt();
		beam.iNode2Sec = fin.GetInt();
		beam.iShearNonlinear = fin.GetInt();
		beam.fBeamSpan = fin.GetFloat();
		beam.iReinforcedSec= fin.GetInt();
	}
}

void CTabDlg2::GetBeamData(CGridCtrl& m_Grid_Beam, int iRow)
{
	vBeam[iRow].ID = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 0));
	vBeam[iRow].iPKPM = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 1));
	vBeam[iRow].iLine = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 2));
	vBeam[iRow].iType = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 3));
	vBeam[iRow].iSection = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 4));
	vBeam[iRow].iSubType = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 5));
	vBeam[iRow].bArtiNode1 = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 6));
	vBeam[iRow].bArtiNode2 = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 7));
	if (m_Grid_Beam.GetItemText(iRow + 1, 8) != _T("0"))
	{
		vBeam[iRow].iConcMat = GetComboBoxIndex(m_Grid_Beam.GetItemText(iRow + 1, 8));
	}
	else 
	{
		vBeam[iRow].iConcMat = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 8));
	}
	if (m_Grid_Beam.GetItemText(iRow + 1, 9) != _T("0"))
	{
		vBeam[iRow].iRebarMat = GetComboBoxIndex(m_Grid_Beam.GetItemText(iRow + 1, 9));
	}
	else
	{
		vBeam[iRow].iRebarMat = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 9));
	}
	if (m_Grid_Beam.GetItemText(iRow + 1, 10) != _T("0"))
	{
		vBeam[iRow].iStirrupMat = GetComboBoxIndex(m_Grid_Beam.GetItemText(iRow + 1, 10));
	}
	else
	{
		vBeam[iRow].iStirrupMat = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 10));
	}
	if (m_Grid_Beam.GetItemText(iRow + 1, 11) != _T("0"))
	{
		vBeam[iRow].iSteelMat = GetComboBoxIndex(m_Grid_Beam.GetItemText(iRow + 1, 11));
	}
	else
	{
		vBeam[iRow].iSteelMat = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 11));
	}
	vBeam[iRow].iStory = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 12));
	vBeam[iRow].iStage = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 13));
	vBeam[iRow].iTower = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 14));
	vBeam[iRow].fRotateAng = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 15));
	vBeam[iRow].fOffsetX1 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 16));
	vBeam[iRow].fOffsetY1 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 17));
	vBeam[iRow].fOffsetZ1 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 18));
	vBeam[iRow].fOffsetX2 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 19));
	vBeam[iRow].fOffsetY2 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 20));
	vBeam[iRow].fOffsetZ2 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 21));
	vBeam[iRow].fUpperRebarLeft = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 22));
	vBeam[iRow].fUpperRebarMid = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 23));
	vBeam[iRow].fUpperRebarRight = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 24));
	vBeam[iRow].fLowerRebarLeft = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 25));
	vBeam[iRow].fLowerRebarMid = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 26));
	vBeam[iRow].fLowerRebarRight = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 27));
	vBeam[iRow].fStirrupArea_D = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 28));
	vBeam[iRow].fStirrupArea_UD = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 29));
	vBeam[iRow].nForceParament = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 30));
	if (vBeam[iRow].nForceParament == 2)
	{
		vBeam[iRow].fF1 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 31));
		vBeam[iRow].fLength = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 32));
		vBeam[iRow].fF2 = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 33));
	}
	vBeam[iRow].iMidPerformType = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 34));
	vBeam[iRow].iSeverePerformType = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 35));
	vBeam[iRow].iStructType = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 36));
	vBeam[iRow].iMidNormSectPerformObject = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 37));
	vBeam[iRow].iMidDiagSectPerformObject = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 38));
	vBeam[iRow].iRareNormSectPerformObject = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 39));
	vBeam[iRow].iRareDiagSectPerformObject = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 40));
	vBeam[iRow].iParaNumbers = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 41));
	if (vBeam[iRow].iParaNumbers == 8)
	{
		vBeam[iRow].fAxisFactor = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 42));
		vBeam[iRow].fMomentFactor = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 43));
		vBeam[iRow].fShearFactor = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 44));
		vBeam[iRow].iAppendMat = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 45));
		vBeam[iRow].iNode1Sec = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 46));
		vBeam[iRow].iNode2Sec = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 47));
		vBeam[iRow].iShearNonlinear = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 48));
		vBeam[iRow].fBeamSpan = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 49));
	}
	if (vBeam[iRow].iParaNumbers == 9)
	{
		vBeam[iRow].fAxisFactor = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 42));
		vBeam[iRow].fMomentFactor = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 43));
		vBeam[iRow].fShearFactor = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 44));
		vBeam[iRow].iAppendMat = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 45));
		vBeam[iRow].iNode1Sec = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 46));
		vBeam[iRow].iNode2Sec = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 47));
		vBeam[iRow].iShearNonlinear = _ttoi(m_Grid_Beam.GetItemText(iRow + 1, 48));
		vBeam[iRow].fBeamSpan = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 49));
		vBeam[iRow].iReinforcedSec = _ttof(m_Grid_Beam.GetItemText(iRow + 1, 50));
	}
}

void CTabDlg2::WriteBeamData(int iRow, CString& sNewLine)
{
	char temp[512];
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].ID);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iPKPM);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iLine);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iSection);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iSubType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].bArtiNode1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].bArtiNode2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iConcMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iRebarMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iStirrupMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iSteelMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iStage);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iTower);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fRotateAng);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fOffsetX1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fOffsetY1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fOffsetZ1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fOffsetX2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fOffsetY2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fOffsetZ2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fUpperRebarLeft);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fUpperRebarMid);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fUpperRebarRight);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fLowerRebarLeft);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fLowerRebarMid);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fLowerRebarRight);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fStirrupArea_D);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fStirrupArea_UD);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].nForceParament);
	sNewLine += temp;
	if (vBeam[iRow].nForceParament == 2)
	{
		sprintf_s(temp, sizeof(temp), "0 0 %g %g %g 1 0 %g %g %g ", vBeam[iRow].fF1, vBeam[iRow].fLength, vBeam[iRow].fF1, vBeam[iRow].fF2,vBeam[iRow].fLength, vBeam[iRow].fF2);
		sNewLine += temp;
	}
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iMidPerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iSeverePerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iStructType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iMidNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iMidDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iRareNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iRareDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iParaNumbers);
	sNewLine += temp;
	if (vBeam[iRow].iParaNumbers == 8){
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fAxisFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fMomentFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fShearFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iAppendMat);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iNode1Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iNode2Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iShearNonlinear);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fBeamSpan);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
		sNewLine += temp;
	}
	if (vBeam[iRow].iParaNumbers == 9) {
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fAxisFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fMomentFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fShearFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iAppendMat);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iNode1Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iNode2Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iShearNonlinear);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vBeam[iRow].fBeamSpan);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vBeam[iRow].iReinforcedSec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
		sNewLine += temp;
	}
}

void CTabDlg2::SetGridItemText(int iRow,int iColCount, CGridCtrl& m_Grid_Beam, CDataFile& fin, Beam& beam)
{
	for (int j = 0; j < iColCount; j++)
	{
		if (j < 31)
		{
			m_Grid_Beam.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[j]);
		}
		if (j >= 31 && beam.nForceParament == 2)
		{
			m_Grid_Beam.SetItemText(iRow + 1, 31, (LPCTSTR)fin.arrInfo[33]);
			m_Grid_Beam.SetItemText(iRow + 1, 32, (LPCTSTR)fin.arrInfo[34]);
			m_Grid_Beam.SetItemText(iRow + 1, 33, (LPCTSTR)fin.arrInfo[38]);
			if (j >= 34 && j <= 49)
			{
				m_Grid_Beam.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[j + 7]);
			}
			if (beam.iParaNumbers == 9 && j == 50)
			{
				m_Grid_Beam.SetItemText(iRow + 1, 50, (LPCTSTR)fin.arrInfo[57]);
			}
		}
		if (j >= 31 && beam.nForceParament == 0)
		{
			if (j >= 34 && j <= 49)
			{
				m_Grid_Beam.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[j - 3]);
			}
			if (beam.iParaNumbers == 9 && j == 50)
			{
				m_Grid_Beam.SetItemText(iRow + 1, 50, (LPCTSTR)fin.arrInfo[47]);
			}
		}
	}
	fin.arrInfo.RemoveAll();
	//ComboBox内容的单独设置
	if (beam.iConcMat != 0) {
		m_Grid_Beam.SetCellType(iRow + 1, 8, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, iRow + 1, 8, arrConcMat, beam.iConcMat);
	}
	if (beam.iRebarMat != 0)
	{
		m_Grid_Beam.SetCellType(iRow + 1, 9, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, iRow + 1, 9, arrRebarMat, beam.iRebarMat);
	}
	if (beam.iStirrupMat != 0)
	{
		m_Grid_Beam.SetCellType(iRow + 1, 10, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, iRow + 1, 10, arrRebarMat, beam.iStirrupMat);
	}
	if (beam.iSteelMat != 0)
	{
		m_Grid_Beam.SetCellType(iRow + 1, 11, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, iRow + 1, 11, arrRebarMat, beam.iSteelMat);
	}
}
	

int CTabDlg2::GetComboBoxIndex(CString sMat)
{
	for (int i = 0; i < arrConcMat.GetSize(); i++)
	{
		if (arrConcMat.GetAt(i) == sMat)
		{
			return i+1;
		}
	}
	for (int i = 0; i < arrRebarMat.GetSize(); i++)
	{
		if (arrRebarMat.GetAt(i) == sMat)
		{
			return i + 101;
		}
	}
	for (int i = 0; i < arrSteelMat.GetSize(); i++)
	{
		if (arrSteelMat.GetAt(i) == sMat)
		{
			return i + 201;
		}
	}
}

void CTabDlg2::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat)
{
	CGridCellCombo* pCell = (CGridCellCombo*)m_Grid.GetCell(nRow, nCol);
	pCell->SetOptions(arrText);
	if (iMat < 100)
	{
		pCell->SetText(arrText.GetAt(iMat));
	}
	else if(iMat<200)
	{
		pCell->SetText(arrText.GetAt((iMat - 101)));
	}
	else if (iMat < 300)
	{
		pCell->SetText(arrText.GetAt((iMat - 201)));
	}
}

BOOL CTabDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Beam.GetClientRect(&cr);
	m_Grid_Beam.SetColumnCount(51);//设置列数
	m_Grid_Beam.SetFixedRowCount(1);//设置表头
	m_Grid_Beam.SetItemText(0, 0, _T("ID"));
	m_Grid_Beam.SetItemText(0, 1, _T("PKPM结构线编号"));
	m_Grid_Beam.SetItemText(0, 2, _T("结构线编号"));
	m_Grid_Beam.SetItemText(0, 3, _T("对象类型"));
	m_Grid_Beam.SetItemText(0, 4, _T("截面类型"));
	m_Grid_Beam.SetItemText(0, 5, _T("子类型"));
	m_Grid_Beam.SetItemText(0, 6, _T("梁1端连接形式"));
	m_Grid_Beam.SetItemText(0, 7, _T("梁2端连接形式"));
	m_Grid_Beam.SetItemText(0, 8, _T("混凝土强度等级"));
	m_Grid_Beam.SetItemText(0, 9, _T("钢筋级别"));
	m_Grid_Beam.SetItemText(0, 10, _T("箍筋级别"));
	m_Grid_Beam.SetItemText(0, 11, _T("钢材型号"));
	m_Grid_Beam.SetItemText(0, 12, _T("楼层"));
	m_Grid_Beam.SetItemText(0, 13, _T("施工阶段"));
	m_Grid_Beam.SetItemText(0, 14, _T("塔号"));
	m_Grid_Beam.SetItemText(0, 15, _T("方向角（度）"));
	m_Grid_Beam.SetItemText(0, 16, _T("1点X方向偏移"));
	m_Grid_Beam.SetItemText(0, 17, _T("1点Y方向偏移"));
	m_Grid_Beam.SetItemText(0, 18, _T("1点Z方向偏移"));
	m_Grid_Beam.SetItemText(0, 19, _T("2点X方向偏移"));
	m_Grid_Beam.SetItemText(0, 20, _T("2点Y方向偏移"));
	m_Grid_Beam.SetItemText(0, 21, _T("2点Z方向偏移"));
	m_Grid_Beam.SetItemText(0, 22, _T("面筋左端配筋面积"));
	m_Grid_Beam.SetItemText(0, 23, _T("面筋中端配筋面积"));
	m_Grid_Beam.SetItemText(0, 24, _T("面筋右端配筋面积"));
	m_Grid_Beam.SetItemText(0, 25, _T("底筋左端配筋面积"));
	m_Grid_Beam.SetItemText(0, 26, _T("底筋中端配筋面积"));
	m_Grid_Beam.SetItemText(0, 27, _T("底筋右端配筋面积"));
	m_Grid_Beam.SetItemText(0, 28, _T("加密区箍筋面积"));
	m_Grid_Beam.SetItemText(0, 29, _T("非加密区箍筋面积"));
	m_Grid_Beam.SetItemText(0, 30, _T("荷载参数"));
	m_Grid_Beam.SetItemText(0, 31, _T("恒荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 32, _T("长度"));
	m_Grid_Beam.SetItemText(0, 33, _T("活荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 34, _T("中震本构"));
	m_Grid_Beam.SetItemText(0, 35, _T("大震本构"));
	m_Grid_Beam.SetItemText(0, 36, _T("重要性分类"));
	m_Grid_Beam.SetItemText(0, 37, _T("中震正截面性能"));
	m_Grid_Beam.SetItemText(0, 38, _T("中震斜截面性能"));
	m_Grid_Beam.SetItemText(0, 39, _T("大震正截面性能"));
	m_Grid_Beam.SetItemText(0, 40, _T("大震斜截面性能"));
	m_Grid_Beam.SetItemText(0, 41, _T("性能化参数个数"));
	m_Grid_Beam.SetItemText(0, 42, _T("轴力内力调整系数"));
	m_Grid_Beam.SetItemText(0, 43, _T("弯矩内力调整系数"));
	m_Grid_Beam.SetItemText(0, 44, _T("剪力内力调整系数"));
	m_Grid_Beam.SetItemText(0, 45, _T("附加材料"));
	m_Grid_Beam.SetItemText(0, 46, _T("1端半刚性属性"));
	m_Grid_Beam.SetItemText(0, 47, _T("2端半刚性属性"));
	m_Grid_Beam.SetItemText(0, 48, _T("剪切属性"));
	m_Grid_Beam.SetItemText(0, 49, _T("构件跨度"));
	m_Grid_Beam.SetItemText(0, 50, _T("附加加固截面"));


	//设置列宽，并将部分列隐藏
	for (int i = 0; i < 51; i++)
	{
		m_Grid_Beam.SetColumnWidth(i, 60);
	}
	m_Grid_Beam.SetColumnWidth(1, 0);
	m_Grid_Beam.SetColumnWidth(30, 0);
	m_Grid_Beam.SetColumnWidth(41, 0);
	m_Grid_Beam.SetColumnWidth(50, 0);
	m_Grid_Beam.EnableHiddenColUnhide(FALSE);//使隐藏列不能显示
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



LRESULT CTabDlg2::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	CDataFile fin;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fin.SeekToBegin();
	CString sLine;
	int iBeamNumbers = 0;
	int iColCount = m_Grid_Beam.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		if (sLine.Find(TEXT("NBEAM NUMBER=")) != -1)
		{
			iBeamNumbers = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			m_Grid_Beam.SetRowCount(iBeamNumbers + 1);
		
			break;
		}
	}
	for (int i = 0; i < iBeamNumbers; i++)
	{
		fin.ReadString(sLine);
		fin.SetData(sLine);
		Beam beam;
		SetBeamData(beam, fin);
		vBeam.push_back(beam);
		SetGridItemText(i, iColCount, m_Grid_Beam, fin, beam);
	}
	return LRESULT();
}
LRESULT CTabDlg2::OnWriteDate(WPARAM wParam, LPARAM lParam)
{
	CDataFile fin;
	CDataFile fout;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	CString sNewPath = sPath.Left(sPath.ReverseFind('.')) + _T("(new)") + sPath.Mid(sPath.ReverseFind('.'));
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fout.Open(sNewPath, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone);
	fin.SeekToBegin();
	fout.SeekToBegin();
	CString sLine;
	CString sNewLine;
	int iColCount = m_Grid_Beam.GetColumnCount();
	int iBeamNumbers = 0;
	while (fin.ReadString(sLine))
	{
		fout.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("NBEAM NUMBER=")) != -1)//先定位
		{
			iBeamNumbers = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			for (int i = 0; i < iBeamNumbers; i++)
			{
				fin.ReadString(sLine);
				GetBeamData(m_Grid_Beam, i);
				WriteBeamData(i, sNewLine);
				//MessageBox(sNewLine);
				fout.WriteString(sNewLine + _T("\n"));
				sNewLine.Empty();

			}
		}
	}
	fin.Close();
	fout.Close();
	fin.Remove(sPath);
	fout.Rename(sNewPath, sPath);
	return LRESULT();
	return LRESULT();
}

 


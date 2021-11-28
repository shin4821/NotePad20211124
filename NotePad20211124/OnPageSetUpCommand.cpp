//OnPageSetUpCommand.cpp
#include"OnPageSetUpCommand.h"
#include"NotePadForm.h"
#include"LineChange.h"
#include"PageSetUpDialog.h"
#include"PageInfo.h"
#include<afxdlgs.h>
#include<afxwin.h>

OnPageSetUpCommand::OnPageSetUpCommand(NotePadForm* notePadForm)
	:Command(notePadForm) {
#if 0
	this->top = 20;
	this->bottom = 20;
	this->left = 25;
	this->right = 25;
	this->paperWidth = 210; //A4 기본 너비
	this->paperHeight = 297; //A4 기본 높이
	this->actualWidth = 170; //A4 기본 너비 - 4000
 	this->actualHeight = 247; //A4 기본 높이 - 5000
	
	//this->paperSize = 기본 A4 사이즈로 하고싶은데, 대화상자를 만들어야 알 수 있으니 원,,,
#endif
}

OnPageSetUpCommand::~OnPageSetUpCommand() {

}

void OnPageSetUpCommand::Execute() {

	CSize paperSize;
	CString header;
	CString footer;
	HANDLE  hDevMode = NULL;
	int orientation;
	int actualWidth;
	int actualHeight;
	int paperSizeCx;
	int paperSizeCy;

	//Modal 이어서 굳이 힙에 할당 안해도 됨.
	PageSetUpDialog pageSetUpDialog(this->notePadForm);

#if 0
	if (this->notePadForm->pageSetUpDialog == NULL) {
		this->notePadForm->pageSetUpDialog = new PageSetUpDialog(this->notePadForm);
	}
#endif

	//#if 0

	//3. 사용자가 열 파일을 정상적으로 선택 하였을 때
	if (IDOK == pageSetUpDialog.DoModal()) {
		//if (IDOK == this->notePadForm->pageSetUpDialog->DoModal()) {

			//3.1. 입력된 여백을 읽는다.
		this->notePadForm->pageInfo->FixTop(pageSetUpDialog.m_psd.rtMargin.top / 100);
		this->notePadForm->pageInfo->FixLeft(pageSetUpDialog.m_psd.rtMargin.left / 100);
		this->notePadForm->pageInfo->FixRight(pageSetUpDialog.m_psd.rtMargin.right / 100);
		this->notePadForm->pageInfo->FixBottom(pageSetUpDialog.m_psd.rtMargin.bottom / 100);

		//3.2. 머리글, 바닥글을 구한다. 
		//DoModal에서 작업해야되는게 아니라, DoModal하면 컨트롤이 사라지므로, 작동되는 중에(PageSetUpDialog) 얻어야한다.

		this->notePadForm->pageInfo->FixHeader(pageSetUpDialog.GetHeader());
		this->notePadForm->pageInfo->FixFooter(pageSetUpDialog.GetFooter());

		//3.3. 선택한 용지를 구한다.
		DEVMODE* portName = pageSetUpDialog.GetDevMode();
		portName->dmFields |= DM_ORIENTATION | DM_PAPERSIZE;

		CString beforeFormName = this->notePadForm->pageInfo->GetFormName();
		this->notePadForm->pageInfo->FixFormName(portName->dmFormName);
		this->notePadForm->pageInfo->FixPaperSize(portName->dmPaperSize);

		//3.4. 선택한 방향을 구한다.
		this->notePadForm->pageInfo->FixOrientation(portName->dmOrientation);

		//3.5. 해당 용지의 너비, 길이를 구한다.
		paperSize = pageSetUpDialog.GetPaperSize();

		if (beforeFormName != portName->dmFormName) {
			this->notePadForm->pageInfo->FixPaperWidth(paperSize.cx / 100);
			this->notePadForm->pageInfo->FixPaperHeight(paperSize.cy / 100);
			paperSizeCx = paperSize.cx / 100;
			paperSizeCy = paperSize.cy / 100;
		}
		else {
			paperSizeCx = this->notePadForm->pageInfo->GetPaperWidth();
			paperSizeCy = this->notePadForm->pageInfo->GetPaperHeight();
		}


		//3.6. 실제 너비를 구한다.
		actualWidth = paperSizeCx -
			(pageSetUpDialog.m_psd.rtMargin.left / 100 + pageSetUpDialog.m_psd.rtMargin.right / 100);
		actualHeight = paperSizeCy -
			(pageSetUpDialog.m_psd.rtMargin.top / 100 + pageSetUpDialog.m_psd.rtMargin.bottom / 100);


		this->notePadForm->pageInfo->FixActualWidth(actualWidth);
		this->notePadForm->pageInfo->FixActualHeight(actualHeight);
#if 0
		paperSize = pageSetUpDialog.GetPaperSize();
		this->notePadForm->pageInfo->FixPaperWidth(paperSize.cx / 100);
		this->notePadForm->pageInfo->FixPaperHeight(paperSize.cy / 100);

		//3.6. 실제 너비를 구한다.
		actualWidth = paperSize.cx / 100 -
			(pageSetUpDialog.m_psd.rtMargin.left / 100 + pageSetUpDialog.m_psd.rtMargin.right / 100);
		actualHeight = paperSize.cy / 100 -
			(pageSetUpDialog.m_psd.rtMargin.top / 100 + pageSetUpDialog.m_psd.rtMargin.bottom / 100);

		this->notePadForm->pageInfo->FixActualWidth(actualWidth);
		this->notePadForm->pageInfo->FixActualHeight(actualHeight);
	}
#endif
	}
}




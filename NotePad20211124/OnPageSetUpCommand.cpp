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
	this->paperWidth = 210; //A4 �⺻ �ʺ�
	this->paperHeight = 297; //A4 �⺻ ����
	this->actualWidth = 170; //A4 �⺻ �ʺ� - 4000
 	this->actualHeight = 247; //A4 �⺻ ���� - 5000
	
	//this->paperSize = �⺻ A4 ������� �ϰ������, ��ȭ���ڸ� ������ �� �� ������ ��,,,
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

	//Modal �̾ ���� ���� �Ҵ� ���ص� ��.
	PageSetUpDialog pageSetUpDialog(this->notePadForm);

#if 0
	if (this->notePadForm->pageSetUpDialog == NULL) {
		this->notePadForm->pageSetUpDialog = new PageSetUpDialog(this->notePadForm);
	}
#endif

	//#if 0

	//3. ����ڰ� �� ������ ���������� ���� �Ͽ��� ��
	if (IDOK == pageSetUpDialog.DoModal()) {
		//if (IDOK == this->notePadForm->pageSetUpDialog->DoModal()) {

			//3.1. �Էµ� ������ �д´�.
		this->notePadForm->pageInfo->FixTop(pageSetUpDialog.m_psd.rtMargin.top / 100);
		this->notePadForm->pageInfo->FixLeft(pageSetUpDialog.m_psd.rtMargin.left / 100);
		this->notePadForm->pageInfo->FixRight(pageSetUpDialog.m_psd.rtMargin.right / 100);
		this->notePadForm->pageInfo->FixBottom(pageSetUpDialog.m_psd.rtMargin.bottom / 100);

		//3.2. �Ӹ���, �ٴڱ��� ���Ѵ�. 
		//DoModal���� �۾��ؾߵǴ°� �ƴ϶�, DoModal�ϸ� ��Ʈ���� ������Ƿ�, �۵��Ǵ� �߿�(PageSetUpDialog) �����Ѵ�.

		this->notePadForm->pageInfo->FixHeader(pageSetUpDialog.GetHeader());
		this->notePadForm->pageInfo->FixFooter(pageSetUpDialog.GetFooter());

		//3.3. ������ ������ ���Ѵ�.
		DEVMODE* portName = pageSetUpDialog.GetDevMode();
		portName->dmFields |= DM_ORIENTATION | DM_PAPERSIZE;

		CString beforeFormName = this->notePadForm->pageInfo->GetFormName();
		this->notePadForm->pageInfo->FixFormName(portName->dmFormName);
		this->notePadForm->pageInfo->FixPaperSize(portName->dmPaperSize);

		//3.4. ������ ������ ���Ѵ�.
		this->notePadForm->pageInfo->FixOrientation(portName->dmOrientation);

		//3.5. �ش� ������ �ʺ�, ���̸� ���Ѵ�.
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


		//3.6. ���� �ʺ� ���Ѵ�.
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

		//3.6. ���� �ʺ� ���Ѵ�.
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




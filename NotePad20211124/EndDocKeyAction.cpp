//EndDocKeyAction.cpp
#include"EndDocKeyAction.h"
#include"NotePadForm.h"
#include"Glyph.h"
#include"Composite.h"
#include"Character.h"
#include"Note.h"
#include"Row.h"
#include"SingleByteCharacter.h"
#include"DoubleByteCharacter.h"
#include"CreateGlyph.h"
#include"CreateProduct.h"
#include"GetTextSize.h"
#include"Location.h"
#include"Font.h"
#include"Caret.h"
#include"Observer.h"
#include"Scroll.h"
#include"SelectWords.h"
#include<string>
using namespace std;
#pragma warning(disable:4996)


EndDocKeyAction::EndDocKeyAction(NotePadForm* notePadForm)
	:KeyAction(notePadForm) {
}
EndDocKeyAction::~EndDocKeyAction() {
}
void EndDocKeyAction::KeyDown() {
	Glyph* character;
	int caretX = 0;
	int length;
	string strCharacter;
	char chaCharacter[3];


	//21.08.04 �߰�
	Long beforeCurrentY = this->notePadForm->note->GetCurrent();


	//2. Ctrl+ home Ű ��ư ������ ��
	//2.0. ���� note���� First�� ȣ���Ѵ�.
	this->notePadForm->note->Last();

	//2.1. ���� note�� current Ȯ���Ѵ�.
	Long currentY = this->notePadForm->note->GetCurrent();
	//2.2. ���� note�� row�� ã�´�.
	this->notePadForm->row = this->notePadForm->note->GetChild(currentY);
	//2.3. ���� row���� First�� ȣ���Ѵ�.
	this->notePadForm->row->Last();
	Long currentX = this->notePadForm->row->GetCurrent();
	currentX++;
	this->notePadForm->row->MoveCurrent(currentX);


	int i = 0;
	while (i < currentX) {
		//2.6.1. i��° ���ڸ� ��´�.
		character = this->notePadForm->row->GetChild(i);
		strCharacter = character->GetContent();
		strcpy(chaCharacter, strCharacter.c_str());

		if (chaCharacter[0] >= 0 && chaCharacter[0] < 128) {
			chaCharacter[1] = '\0';
		}
		else {
			chaCharacter[2] = '\0';
		}

		//2.6.2. Location�� CalculateX�� ȣ���Ѵ�.
		this->notePadForm->getTextSize->CalculateX(chaCharacter);
		//CalculateX(chaCharacter);
		i++;
	}

	//int caretX = this->notePadForm->location->caret->GetX();
	caretX = this->notePadForm->location->caret->GetX();


	if (caretX > this->notePadForm->scroll->windowWidth) {
		this->notePadForm->scroll->siHorizon.nPos = caretX - this->notePadForm->scroll->windowWidth;

		// ��ũ�� ������ set�Ѵ�.
		this->notePadForm->SetScrollInfo(SB_HORZ, &this->notePadForm->scroll->siHorizon, TRUE);
	}


	//2.4. ĳ���� �ű��.
	this->notePadForm->isOnImeCharForMove = FALSE;
	this->notePadForm->isFirstComposingForMove = FALSE;


	// Scroll ������Ʈ �� ���� ������ �����Ѵ�.
	this->notePadForm->isJumpOverForPrevious = FALSE;
	this->notePadForm->isJumpOverForNext = FALSE;
	this->notePadForm->isUp = FALSE;
	this->notePadForm->isDown = FALSE;
	this->notePadForm->isDoubleByte = FALSE;

	this->notePadForm->Notify();
}
//OnPreviewCommand.cpp
#include"OnPreviewCommand.h"
#include"NotePadForm.h"
#include"Preview.h"
#include"Scroll.h"


OnPreviewCommand::OnPreviewCommand(NotePadForm* notePadForm)
	:Command(notePadForm) {
}

OnPreviewCommand::~OnPreviewCommand() {
}

void OnPreviewCommand::Execute() {

	int width = this->notePadForm->scroll->windowWidth;
	int height = this->notePadForm->scroll->windowHeight;

	//1. 미리보기 프레임윈도우를 띄운다. (대화상자 아니라)
	Preview* preview = new Preview(this->notePadForm);

	preview->Create(NULL, "미리보기");
	preview->ShowWindow(SW_SHOW);
	preview->UpdateWindow();

}






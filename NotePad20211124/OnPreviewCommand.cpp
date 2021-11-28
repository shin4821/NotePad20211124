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

	//1. �̸����� �����������츦 ����. (��ȭ���� �ƴ϶�)
	Preview* preview = new Preview(this->notePadForm);

	preview->Create(NULL, "�̸�����");
	preview->ShowWindow(SW_SHOW);
	preview->UpdateWindow();

}






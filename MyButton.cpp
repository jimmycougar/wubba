#include <QtGui>
#include <iostream>

#include "MyButton.h"
#include "PokerInput.h"

MyButton::MyButton(const QString &text) 
: QPushButton(text) {
	connect(this, SIGNAL(clicked()), this, SLOT(addNewItem()));
}

void MyButton::addNewItem() 
{
	PokerInput *pokerInput = new PokerInput();
	pokerInput->setModal(true);
	pokerInput->exec();
}

void MyButton::quitClicked() {
	std::cout << "QUIT CLICKED()!\n";
}

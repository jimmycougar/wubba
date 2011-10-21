#include <QtGui>
#include "MyButton.h"

void MyButton::addNewItem() 
{
//	std::cout << "Inside Add New Item()" << std::endl;
	QDialog *window = new QDialog();
	QLabel *label = new QLabel("New window");
	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(label);
	window->setLayout(layout);
	window->show();
}


#include <QtGui>
#include "PokerInput.h"
#include "MyButton.h"

#include <iostream>

PokerInput::PokerInput() : QDialog() {
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	
	QLabel *header = new QLabel("Please enter the following information: ");
	mainLayout->addWidget(header);
	
	QLabel *dateLabel = new QLabel("Date: ");
	QLineEdit *dateInput = new QLineEdit();

	QLabel *nameLabel = new QLabel("Name: ");
	QLineEdit *nameInput = new QLineEdit();

	QLabel *gameTypeLabel = new QLabel("Game Type: ");
	QLineEdit *gameTypeInput = new QLineEdit();

	QLabel *netChangeLabel = new QLabel("Net Change: ");
	QLineEdit *netChangeInput = new QLineEdit();

	
	QGridLayout *inputLayout = new QGridLayout();
	inputLayout->addWidget(dateLabel,0,0);
	inputLayout->addWidget(dateInput,0,1);
	inputLayout->addWidget(nameLabel,1,0);
	inputLayout->addWidget(nameInput,1,1);
	inputLayout->addWidget(gameTypeLabel,2,0);
	inputLayout->addWidget(gameTypeInput,2,1);
	inputLayout->addWidget(netChangeLabel,3,0);
	inputLayout->addWidget(netChangeInput,3,1);
	mainLayout->addLayout(inputLayout);

	QPushButton *submitButton = new QPushButton("Submit");
	//connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
	mainLayout->addWidget(submitButton);

	MyButton *cancelButton = new MyButton("Cancel");
	connect(cancelButton, SIGNAL(clicked()), cancelButton, SLOT(quitClicked()));
	mainLayout->addWidget(cancelButton);

	setModal(true);
	setLayout(mainLayout);
	show();
}

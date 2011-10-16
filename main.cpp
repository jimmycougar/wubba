#include <QtGui>

#include "MyButton.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	QApplication app(argc, argv);
	QWidget window;
	QLabel *welcomeLabel = new QLabel("Welcome to Wubba!");
	
	QGridLayout *optionsLayout = new QGridLayout();
	QCheckBox *balanceOption = new QCheckBox("Balance");
	QCheckBox *incomeOption = new QCheckBox("Income");
	QCheckBox *expenseOption = new QCheckBox("Expense");

	optionsLayout->addWidget(balanceOption,0,0);
	optionsLayout->addWidget(incomeOption,1,0);
	optionsLayout->addWidget(expenseOption,2,0);
	
	QHBoxLayout *graphLayout = new QHBoxLayout();
	graphLayout->addLayout(optionsLayout);
	QTextEdit *temp = new QTextEdit("This is where a graph will go");
	graphLayout->addWidget(temp);

//	QPushButton createItemButton("Create New Item");
//	createItemButton.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//	QObject::connect(&createItemButton, SIGNAL(clicked()), &MyNewItem(), SLOT(createMyNewItem()));

	MyButton *createButton = new MyButton("My Button");
	createButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	QPushButton *quitButton = new QPushButton("Quit");
	quitButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	QObject::connect(quitButton, SIGNAL(clicked()), &app, SLOT(quit()));
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget(welcomeLabel);
	mainLayout->addLayout(graphLayout);
	mainLayout->addWidget(createButton, 2, Qt::AlignCenter);
	mainLayout->addWidget(quitButton, 2, Qt::AlignCenter);
	window.setLayout(mainLayout);
	window.setWindowTitle("Wubba Projector");
	window.show();
	
	return app.exec();
}





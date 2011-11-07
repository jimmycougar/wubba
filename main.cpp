#include <QtGui>
#include <stdlib.h>

#include "MyButton.h"
#include "PokerTable.h"

using namespace std;

PokerTable* init_table()
{
	PokerTable * table = new PokerTable();

	QFile inputFile("poker.txt");
	if (!inputFile.open(QIODevice::ReadOnly))
	{
		cout << "Error opening file.\n";
		return table;
	}

	QTextStream stream(&inputFile);

	int total = 0;
	int kevin = 0;
	int estelle = 0;

	while(!stream.atEnd())
	{
		QString date, person, stakes, amount_str;
		stream >> date >> person >> stakes >> amount_str;
		table->AddRow(date, person, stakes, amount_str);
		int amount = atoi(amount_str.toUtf8());
		total += amount;

		if(person == QString("Kevin"))
		{
			kevin += amount;
		}

		if(person == QString("Estelle")) 
		{
			estelle += amount;
		}
	}

	table->SetTotal(QString::number(total),QString::number(kevin),QString::number(estelle));

	return table;
}

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

	PokerTable * table = init_table();
	
	graphLayout->addWidget(table);

//	QPushButton createItemButton("Create New Item");
//	createItemButton.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//	QObject::connect(&createItemButton, SIGNAL(clicked()), &MyNewItem(), SLOT(createMyNewItem()));

	MyButton *createButton = new MyButton("Add an item");
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





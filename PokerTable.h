
#ifndef POKER_TABLE_H
#define POKER_TABLE_H

#include <QtGui>

using namespace std;

class PokerTable : public QTableWidget
{
public:
	PokerTable() : QTableWidget(0, 4)
	{
		// row for Total
		insertRow(rowCount());
		// rows for individuals
		insertRow(rowCount());
		insertRow(rowCount());
	}
	~PokerTable(){}

	void AddRow(QString date, QString person, QString stakes, QString amount)
	{
		int row = rowCount();
		insertRow(row);
		setItem(row, 0, new QTableWidgetItem(date));
		setItem(row, 1, new QTableWidgetItem(person));
		setItem(row, 2, new QTableWidgetItem(stakes));
		setItem(row, 3, new QTableWidgetItem(amount));
	}

	void SetTotal(QString amount, QString kevin, QString estelle)
	{
		setItem(0,0, new QTableWidgetItem("Total"));
		setItem(0,3, new QTableWidgetItem(amount));
		setItem(1,0, new QTableWidgetItem("Kevin"));
		setItem(1,3, new QTableWidgetItem(kevin));
		setItem(2,0, new QTableWidgetItem("Estelle"));
		setItem(2,3, new QTableWidgetItem(estelle));
	}

};

#endif //POKER_TABLE_H

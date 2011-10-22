
#ifndef POKER_TABLE_H
#define POKER_TABLE_H

#include <QtGui>

using namespace std;

class PokerTable : public QTableWidget
{
public:
	PokerTable() : QTableWidget(0, 4){}
	~PokerTable(){}

	void addRow(QString date, QString person, QString stakes, QString amount)
	{
		int row = rowCount();
		insertRow(row);
		setItem(row, 0, new QTableWidgetItem(date));
		setItem(row, 1, new QTableWidgetItem(person));
		setItem(row, 2, new QTableWidgetItem(stakes));
		setItem(row, 3, new QTableWidgetItem(amount));
	}

};

#endif //POKER_TABLE_H

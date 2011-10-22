#ifndef _MyButton_included_
#define _MyButton_included_

#include <QPushButton>
#include <iostream>

class MyButton : public QPushButton 
{
	Q_OBJECT

	public:
		MyButton(const QString &text);

	public slots:
		void addNewItem();
		void quitClicked();
};
#endif


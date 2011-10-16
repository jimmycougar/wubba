#ifndef _MyButton_included_
#define _MyButton_included_

#include <QPushButton>
#include <iostream>

class MyButton : public QPushButton 
{
	Q_OBJECT

	public:
		MyButton(const QString &text) : QPushButton(text)
		{ 
		 connect(this, SIGNAL(clicked()), this, SLOT(addNewItem()));
		}

	public slots:
		void addNewItem();

};
#endif


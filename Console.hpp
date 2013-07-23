#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <QtGui/QDialog>
#include "ui_Console.h"

class Console : public QDialog
{
  Q_OBJECT;

public:

  Console( QWidget* parent=0, Qt::WFlags flags=0 );
  ~Console();

private:

  Ui::ConsoleClass ui;
};

#endif // CONSOLE_HPP
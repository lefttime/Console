#ifndef OUTPUTWINDOW_HPP
#define OUTPUTWINDOW_HPP

#include <QPlainTextEdit>

class OutputWindow : public QPlainTextEdit
{
  Q_OBJECT;

public:

  enum State { Browsing, Commanding };

  OutputWindow( QWidget* parent );
  ~OutputWindow();

private:

  void init();
  void enterState( State );

private slots:

  void on_blockCountChanged( int newBlockCount );
};

#endif // OUTPUTWINDOW_HPP
#include "OutputWindow.hpp"

#include "CommandProcessor.hpp"

#include <QTextBlock>
#include <QTextDocument>

OutputWindow::OutputWindow( QWidget* parent ) : QPlainTextEdit( parent )
{
  init();
}

OutputWindow::~OutputWindow()
{
}

void OutputWindow::init()
{
  enterState( Commanding );
}

void OutputWindow::enterState( OutputWindow::State state )
{
  QTextCharFormat fmt;
  QTextCursor cursor = textCursor();

  switch( state ) {
  case Browsing:    fmt.setForeground( Qt::black ); break;

  case Commanding: {
    cursor.insertText( QString( ">>>" ) );
    fmt.setForeground( Qt::blue );
  }break;

  default: break;
  }

  cursor.mergeCharFormat( fmt );
  mergeCurrentCharFormat( fmt );
}

void OutputWindow::on_blockCountChanged( int newBlockCount )
{
  QString inputStr = document()->findBlockByNumber( newBlockCount-2 ).text();
  inputStr.remove( ">>>" );
  parentWidget()->setWindowTitle( inputStr );

  enterState( Browsing );
  blockSignals( true );
  if( !theCommandProcessor->parse( inputStr ) ) {
    textCursor().insertText( QString( "Error while executing TCL command:\n\ninvalid command name \"" ) +
                             inputStr +
                             QString( "\"\n  while executing\n") +
                             QString( "\"" ) + inputStr + QString( "\"\n" ));
  } else {
    textCursor().insertText( theCommandProcessor->getLastError() + "\n" );
  }
  blockSignals( false );

  enterState( Commanding );
}

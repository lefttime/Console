#include "Console.hpp"
#include <QtGui/QApplication>

int main( int argc, char* argv[] )
{
  QApplication app( argc, argv );

  Console w;
  w.show();

  return app.exec();
}

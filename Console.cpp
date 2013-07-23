#include "Console.hpp"

Console::Console( QWidget* parent, Qt::WFlags flags ) : QDialog( parent, flags )
{
  ui.setupUi( this );
}

Console::~Console()
{
}

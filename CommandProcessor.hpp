#ifndef COMMANDPROCESSOR_HPP
#define COMMANDPROCESSOR_HPP

#include <QObject>

class CommandProcessor : public QObject
{
  Q_OBJECT;

public:

  static CommandProcessor* instance();

  ~CommandProcessor();

  bool parse( const QString& content ) const;
  QString getLastError() const;

private:

  CommandProcessor( QObject* parent=0 );

  class CommandProcessorPrivate;
  QScopedPointer<CommandProcessorPrivate>         _pd;

};

#define theCommandProcessor CommandProcessor::instance()

#endif // COMMANDPROCESSOR_HPP
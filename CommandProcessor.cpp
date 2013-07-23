#include "CommandProcessor.hpp"

#include <QFile>
#include <QtDebug>
#include <QStringList>
#include <QScriptEngine>

class CommandProcessor::CommandProcessorPrivate
{
public:

  CommandProcessorPrivate( CommandProcessor* me ) : m_self( me ) {

  }

  void init() {
    QFile file( ":/Resources/Script/Core.js" );
    file.open( QIODevice::ReadOnly );
    QScriptValue result = m_engine.evaluate( file.readAll() );
    file.close();
    if( m_engine.hasUncaughtException() ) {
      int lineNo = m_engine.uncaughtExceptionLineNumber();
      qWarning() << "line" << lineNo << ":" << result.toString();
    }
  }

  QString evaluate( const QStringList& cmdLine ) const {
    return QString();
  }

  CommandProcessor*         m_self;
  QScriptEngine             m_engine;

  QString                   m_lastError;
};

CommandProcessor* CommandProcessor::instance()
{
  static CommandProcessor* selfObject = 0;
  if( !selfObject ) {
    selfObject = new CommandProcessor();
  }

  return selfObject;
}

bool CommandProcessor::parse( const QString& content ) const
{
  if( !_pd->m_engine.canEvaluate( content ) ) {
    return false;
  }

  QStringList cmdList = content.trimmed().split( ";" );
  foreach( const QString& cmd, cmdList ) {
    QStringList arguments = cmd.trimmed().split( ' ' );
    if( !arguments.isEmpty() ) {
      _pd->m_lastError = _pd->evaluate( arguments );
    }
  }
  return true;
}

QString CommandProcessor::getLastError() const
{
  return _pd->m_lastError;
}

CommandProcessor::~CommandProcessor()
{
}

CommandProcessor::CommandProcessor( QObject* parent ) : QObject( parent ), _pd( new CommandProcessorPrivate( this ) )
{
  _pd->init();
}

#ifndef SERIALPORTTOOL_H
#define SERIALPORTTOOL_H

#include <QObject>

class SerialPortTool : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortTool(QObject *parent = nullptr);

signals:

};

#endif // SERIALPORTTOOL_H

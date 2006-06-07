/*
 * This file was generated by dbusidl2cpp version 0.5
 * when processing input file org.kde.KWin.xml
 *
 * dbusidl2cpp is Copyright (C) 2006 Trolltech AS. All rights reserved.
 *
 * This is an auto-generated file.
 */

#include "kwinadaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class KWinAdaptor
 */

KWinAdaptor::KWinAdaptor(QObject *parent)
   : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

KWinAdaptor::~KWinAdaptor()
{
    // destructor
}

void KWinAdaptor::cascadeDesktop()
{
    // handle method call org.kde.KWin.cascadeDesktop
    QMetaObject::invokeMethod(parent(), "cascadeDesktop");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->cascadeDesktop();
}

void KWinAdaptor::circulateDesktopApplications()
{
    // handle method call org.kde.KWin.circulateDesktopApplications
    QMetaObject::invokeMethod(parent(), "circulateDesktopApplications");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->circulateDesktopApplications();
}

int KWinAdaptor::currentDesktop()
{
    // handle method call org.kde.KWin.currentDesktop
    int out0;
    QMetaObject::invokeMethod(parent(), "currentDesktop", Q_RETURN_ARG(int, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->currentDesktop();
    return out0;
}

void KWinAdaptor::doNotManage(const QString &name)
{
    // handle method call org.kde.KWin.doNotManage
    QMetaObject::invokeMethod(parent(), "doNotManage", Q_ARG(QString, name));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->doNotManage(name);
}

void KWinAdaptor::killWindow()
{
    // handle method call org.kde.KWin.killWindow
    QMetaObject::invokeMethod(parent(), "killWindow");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->killWindow();
}

bool KWinAdaptor::kompmgrIsRunning()
{
    // handle method call org.kde.KWin.kompmgrIsRunning
    bool out0;
    QMetaObject::invokeMethod(parent(), "kompmgrIsRunning", Q_RETURN_ARG(bool, out0));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->kompmgrIsRunning();
    return out0;
}

void KWinAdaptor::nextDesktop()
{
    // handle method call org.kde.KWin.nextDesktop
    QMetaObject::invokeMethod(parent(), "nextDesktop");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->nextDesktop();
}

void KWinAdaptor::previousDesktop()
{
    // handle method call org.kde.KWin.previousDesktop
    QMetaObject::invokeMethod(parent(), "previousDesktop");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->previousDesktop();
}

void KWinAdaptor::reconfigure()
{
    // handle method call org.kde.KWin.reconfigure
    QMetaObject::invokeMethod(parent(), "reconfigure");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->reconfigure();
}

void KWinAdaptor::refresh()
{
    // handle method call org.kde.KWin.refresh
    QMetaObject::invokeMethod(parent(), "refresh");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->refresh();
}

bool KWinAdaptor::setCurrentDesktop(int desktop)
{
    // handle method call org.kde.KWin.setCurrentDesktop
    bool out0;
    QMetaObject::invokeMethod(parent(), "setCurrentDesktop", Q_RETURN_ARG(bool, out0), Q_ARG(int, desktop));

    // Alternative:
    //out0 = static_cast<YourObjectType *>(parent())->setCurrentDesktop(desktop);
    return out0;
}

void KWinAdaptor::setDesktopLayout(int orientation, int x, int y)
{
    // handle method call org.kde.KWin.setDesktopLayout
    QMetaObject::invokeMethod(parent(), "setDesktopLayout", Q_ARG(int, orientation), Q_ARG(int, x), Q_ARG(int, y));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setDesktopLayout(orientation, x, y);
}

void KWinAdaptor::setOpacity(qlonglong winId, uint opacityPercent)
{
    // handle method call org.kde.KWin.setOpacity
    QMetaObject::invokeMethod(parent(), "setOpacity", Q_ARG(qlonglong, winId), Q_ARG(uint, opacityPercent));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setOpacity(winId, opacityPercent);
}

void KWinAdaptor::setShadowSize(qlonglong winId, uint shadowSizePercent)
{
    // handle method call org.kde.KWin.setShadowSize
    QMetaObject::invokeMethod(parent(), "setShadowSize", Q_ARG(qlonglong, winId), Q_ARG(uint, shadowSizePercent));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setShadowSize(winId, shadowSizePercent);
}

void KWinAdaptor::setUnshadowed(qlonglong winId)
{
    // handle method call org.kde.KWin.setUnshadowed
    QMetaObject::invokeMethod(parent(), "setUnshadowed", Q_ARG(qlonglong, winId));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->setUnshadowed(winId);
}

void KWinAdaptor::showWindowMenuAt(qlonglong winId, int x, int y)
{
    // handle method call org.kde.KWin.showWindowMenuAt
    QMetaObject::invokeMethod(parent(), "showWindowMenuAt", Q_ARG(qlonglong, winId), Q_ARG(int, x), Q_ARG(int, y));

    // Alternative:
    //static_cast<YourObjectType *>(parent())->showWindowMenuAt(winId, x, y);
}

void KWinAdaptor::startKompmgr()
{
    // handle method call org.kde.KWin.startKompmgr
    QMetaObject::invokeMethod(parent(), "startKompmgr");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->startKompmgr();
}

void KWinAdaptor::stopKompmgr()
{
    // handle method call org.kde.KWin.stopKompmgr
    QMetaObject::invokeMethod(parent(), "stopKompmgr");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->stopKompmgr();
}

void KWinAdaptor::unclutterDesktop()
{
    // handle method call org.kde.KWin.unclutterDesktop
    QMetaObject::invokeMethod(parent(), "unclutterDesktop");

    // Alternative:
    //static_cast<YourObjectType *>(parent())->unclutterDesktop();
}


#include "kwinadaptor.moc"

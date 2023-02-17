QT       += core gui sql network testlib
QT += printsupport  serialport charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets multimedia
TARGET=app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS = cinemapp.ico
SOURCES += \
    ClientF.cpp \
    Programmation.cpp \
    ardcap.cpp \
    ardrfid.cpp \
    arduino.cpp \
    caisse.cpp \
    client.cpp \
    clientetfinance.cpp \
    connexion.cpp \
    employe.cpp \
    excel.cpp \
    facture.cpp \
    film.cpp \
    historique.cpp \
    kiosque.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    notificationP.cpp \
    produit.cpp \
    qcustomplot.cpp \
    salle.cpp \
    server.cpp \
    servicetech.cpp \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimecontentformatter.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimemultipart.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/quotedprintable.cpp \
    src/smtpclient.cpp \
    ticket.cpp

HEADERS += \
    ClientF.h \
    Programmation.h \
    ardcap.h \
    ardrfid.h \
    arduino.h \
    caisse.h \
    client.h \
    clientetfinance.h \
    connexion.h \
    employe.h \
    excel.h \
    facture.h \
    film.h \
    historique.h \
    kiosque.h \
    login.h \
    mainwindow.h \
    notificationP.h \
    produit.h \
    qcustomplot.h \
    salle.h \
    server.h \
    servicetech.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h \
    ticket.h \
    ui_client.h

FORMS += \
    Programmation.ui \
    ardcap.ui \
    ardrfid.ui \
    client.ui \
    clientetfinance.ui \
    kiosque.ui \
    mainwindow.ui \
    server.ui \
    servicetech.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cinemApp.qrc \
    click_son.qrc \
    translation.qrc

DISTFILES +=

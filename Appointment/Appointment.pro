#-------------------------------------------------
#
# Project created by QtCreator 2017-03-02T15:29:26
#
#-------------------------------------------------

QT       += core gui sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Appointment
TEMPLATE = app


SOURCES += main.cpp\
        appointmentcheck.cpp \
    createnewaccount.cpp \
    mainwindow.cpp \
    createcontact.cpp \
    createappointment.cpp \
    admindelete.cpp \
    deleteaccount.cpp \
    changeappointment.cpp \
    cancelappointment.cpp \
    contactinfo.cpp \
    smtp.cpp \
    sendemailreminder.cpp \
    updatecontactinfo.cpp \
    changepassword.cpp \
    adminchangepassword.cpp \
    forgotpassword.cpp \
    help.cpp \
    aboutus.cpp \
    listedrange.cpp \
    availability.cpp

HEADERS  += appointmentcheck.h \
    createnewaccount.h \
    mainwindow.h \
    createcontact.h \
    createappointment.h \
    admindelete.h \
    deleteaccount.h \
    changeappointment.h \
    cancelappointment.h \
    contactinfo.h \
    smtp.h \
    sendemailreminder.h \
    updatecontactinfo.h \
    changepassword.h \
    adminchangepassword.h \
    forgotpassword.h \
    help.h \
    aboutus.h \
    listedrange.h \
    availability.h

FORMS    += appointmentcheck.ui \
    createnewaccount.ui \
    mainwindow.ui \
    createcontact.ui \
    createappointment.ui \
    admindelete.ui \
    deleteaccount.ui \
    changeappointment.ui \
    cancelappointment.ui \
    contactinfo.ui \
    sendemailreminder.ui \
    updatecontactinfo.ui \
    changepassword.ui \
    adminchangepassword.ui \
    forgotpassword.ui \
    help.ui \
    aboutus.ui \
    listedrange.ui \
    availability.ui

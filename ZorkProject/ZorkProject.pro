QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Encounter.cpp \
        Parser.cpp \
        Room.cpp \
        Wordle.cpp \
        ZorkUL.cpp \
        item.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Encounter.h \
    Parser.h \
    Room.h \
    Wordle.h \
    ZorkUL.h \
    item.h

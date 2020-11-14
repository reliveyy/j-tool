//
// Created by justin on 2020/11/13.
//

#pragma once

#include <QWidget>
#include <QVector>
#include <QGroupBox>
#include <QPushButton>
#include <QAction>

#include "../include/TodoItem.h"

class TodoList : public QWidget {
Q_OBJECT

public:
    TodoList(QWidget *parent = nullptr);

    QGroupBox* getSelfWidget();

private slots:

    void loadFromFile();

    void saveToFile();

    void addItem(TodoItem&);

    void removeItem(int);

    void clear();

private:

    QGroupBox* todoListBox;

    QVector<TodoItem>* todoListData;

    QPushButton* loadFromFileBtn;
    QPushButton* saveToFileBtn;
    QPushButton* addItemBtn;
    QPushButton* clearBtn;
    QPushButton* removeItemBtn; // attached on TodoItem

    QAction *loadFromFileAct;
    QAction *saveToFileAct;
    QAction *addItemAct;
    QAction *clearAct;
    QAction *removeItemAct;

};

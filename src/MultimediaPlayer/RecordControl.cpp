//
// Created by justin on 2021/02/07.
//

#include "RecordControl.h"

RecordControl::RecordControl(QWidget *parent) : QWidget(parent) {
    recordAudioBtn = new QPushButton("Record Audio");
    recordVideoBtn = new QPushButton("Record Video");
    connect(recordAudioBtn, &QAbstractButton::clicked, this, &RecordControl::recordAudio);
    connect(recordVideoBtn, &QAbstractButton::clicked, this, &RecordControl::recordVideo);

    QBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(recordAudioBtn);
    mainLayout->addWidget(recordVideoBtn);
}

RecordControl::~RecordControl() {

}

void RecordControl::recordAudio() {
    emit emitRecordAudio();
}

void RecordControl::recordVideo() {
    emit emitRecordVideo();
}

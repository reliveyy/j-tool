//
// Created by justin on 2021/02/03.
//

#include <QBoxLayout>

#include "./MultimediaPlayer.h"

#include <QVector>

MultimediaPlayer::MultimediaPlayer(QWidget *parent) : QWidget(parent) {
    ffmpegDecoder = FFmpegDecoder();
    ffmpegRecorder = FFmpegRecorder();

    // displayLayout
    playlist = new QMediaPlaylist();
    playlistModel = new PlaylistModel(this);
    playlistModel->setPlaylist(playlist);
    playlistView = new QListView;
    playlistView->setModel(playlistModel);
    connect(playlistView, &QAbstractItemView::activated, this, &MultimediaPlayer::jump);

    screen = new QLabel;
    screen->setStyleSheet("QLabel { background-color : black; }");
    ffmpegDecoder.setScreen(screen);

    QBoxLayout *displayLayout = new QHBoxLayout();
    displayLayout->addWidget(screen, 2);
    displayLayout->addWidget(playlistView);

    // main layout
    playControl = new PlayControl;
    connect(playControl, &PlayControl::emitAddToPlayList, this, &MultimediaPlayer::addToPlayList);
    connect(playControl, &PlayControl::emitPlay, this, &MultimediaPlayer::play);

    recordControl = new RecordControl;
    connect(recordControl, &RecordControl::emitRecordVideo, this, &MultimediaPlayer::recordVideo);
    connect(recordControl, &RecordControl::emitRecordAudio, this, &MultimediaPlayer::recordAudio);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(displayLayout);
    layout->addWidget(playControl);
    layout->addWidget(recordControl);
}

MultimediaPlayer::~MultimediaPlayer() {

}

void MultimediaPlayer::addToPlayList(const QString &filepath) {
    QUrl url = QUrl(filepath);
    playlist->addMedia(url);
}

void MultimediaPlayer::jump(const QModelIndex &index) {
    if (index.isValid()) {
        playlist->setCurrentIndex(index.row());
        QUrl currentFileUrl = playlist->currentMedia().request().url();
        play(currentFileUrl.toString());
    }
}

void MultimediaPlayer::play(const QString &filename) {
    ffmpegDecoder.decodeMultimediaFile(filename.toStdString());
}

void MultimediaPlayer::recordAudio() {
    ffmpegRecorder.recordAudio();
}

void MultimediaPlayer::recordVideo() {
    // todo
    // ffmpegRecorder.recordVideo();
}



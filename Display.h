#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>

namespace Ui {
    class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();

signals:

public slots:
    void showFrame(const QImage& frame);

private:
    Ui::Display *ui;
};

#endif // DISPLAY_H

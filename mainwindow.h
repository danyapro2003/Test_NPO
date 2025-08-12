#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBrowseInput_clicked();
    void on_btnBrowseOutput_clicked();
    void on_btnStart_clicked();

signals:
    void progressChanged(int value);
    void progressSetMaximum(int value);
    void statusChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    void runXorProcess();
    void xorFile(QByteArray &fileData, const quint64 key);
    QStringList findInputFiles(const QString &folderPath, const QString &mask);
};
#endif // MAINWINDOW_H

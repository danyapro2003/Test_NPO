#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDataStream>
#include <QByteArray>
#include <QtConcurrent/QtConcurrentRun>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::runXorProcess);

    connect(this, &MainWindow::progressChanged, ui->progressBar, &QProgressBar::setValue);
    connect(this, &MainWindow::progressSetMaximum, ui->progressBar, &QProgressBar::setMaximum);
    connect(this, &MainWindow::statusChanged, ui->labelStatus, &QLabel::setText);

    // connect(ui->btnBrowseOutput, &QPushButton::clicked,
    //         this, &MainWindow::on_btnBrowseOutput_clicked);

    // connect(ui->btnBrowseInput, &QPushButton::clicked,
    //         this, &MainWindow::on_btnBrowseInput_clicked);

    // connect(ui->btnStart, &QPushButton::clicked,
    //         this, &MainWindow::on_btnStart_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBrowseInput_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Choose folder with input files"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        ui->lineEditInputPath->setText(dir);
    }
}

void MainWindow::on_btnBrowseOutput_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Choose folder for output files"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        ui->lineEditSavePath->setText(dir);
    }
}

QStringList MainWindow::findInputFiles(const QString &folderPath, const QString &mask){
    QDir dir(folderPath);

    if(!dir.exists()){
        qDebug() << "Folder is not found!";
    }

    QStringList masks;

    if(mask.contains(';')){
        masks = mask.split(';', Qt::SkipEmptyParts);
        for (auto &i : masks){
            i = i.trimmed();
        }
        //qDebug() << masks[1];
    } else {
        masks << mask;
        for (auto &i : masks){
            i = i.trimmed();
        }
    }

    QStringList files = dir.entryList(masks, QDir::Files);
    return files;
}

void MainWindow::xorFile(QByteArray &fileData, const quint64 key) {
    for (int i = 0; i < fileData.size(); ++i) {
        fileData[i] = fileData[i] ^ key;
    }
}

bool existFileInOutDir(QString outputFile){
    QFileInfo File(outputFile);

    return File.exists();
}

void MainWindow::runXorProcess(){
    QString inputDir(ui->lineEditInputPath->text());
    QString outputDir(ui->lineEditSavePath->text());
    QString mask = ui->lineEditMask->text();
    //bool mode = ui->radioOnce->isChecked();
    bool deleteFiles = ui->checkDeleteInput->isChecked();
    bool ifNameExist = ui->comboNameConflict->currentIndex(); // 0 - rewrite; 1 - iterator for files

    QString textXOR = ui->lineEditXorValue->text();
    bool okXOR;
    quint64 key = textXOR.toULongLong(&okXOR);
    if (!okXOR) {
        qWarning() << "ERROR casting 8 byte key! Try one more.";
    }

    if(inputDir.isEmpty() || outputDir.isEmpty() || mask.isEmpty()){
        qWarning() << "Please, fill in all fields!";
        return;
    }

    qDebug() << "Starting XOR";
    emit statusChanged("Статус: Обработка файлов...");
    //ui->labelStatus->setText("Статус: Обработка файлов...");

    QStringList files = findInputFiles(inputDir, mask);

    emit progressChanged(0);
    emit progressSetMaximum(files.size());
    // ui->progressBar->setValue(0);
    // ui->progressBar->setMaximum(files.size());

    int iterFiles = 1;
    for(auto &filePath: files){
        iterFiles++;
        emit progressChanged(iterFiles);
        //ui->progressBar->setValue(iterFiles);
        //qDebug() << filePath;
        filePath = inputDir + "/" + filePath;
        QFile file(filePath);

        if(!file.open(QIODevice::ReadOnly)){
            qDebug() << "Failed to open file for reading:" << filePath;
            continue;
        }

        QByteArray fileData = file.readAll();
        file.close();


        xorFile(fileData, key);

        QFileInfo fileInfo(filePath);
        QString outputPath = outputDir + "/" + fileInfo.fileName();

        if(existFileInOutDir(outputPath) && ifNameExist){
            outputPath = outputDir + "/";
            QStringList listName = fileInfo.fileName().split(".");
            for(int i = 0; i < listName.size() - 1; i++){
                outputPath += listName[i];
            }
            outputPath += QString::number(iterFiles) + "." + listName.last();
        }

        QFile outputFile(outputPath);

        if (!outputFile.open(QIODevice::WriteOnly)) {
            qWarning() << "Failed to open file for writing:" << outputPath;
            continue;
        }

        outputFile.write(fileData);
        outputFile.close();

        if(deleteFiles){
            if(file.remove()){
                qDebug() << "File is deleted";
            }
            else {
                qDebug() << "ERROR deleting file: " << file.errorString();
            }
        }
    }
    emit statusChanged("Статус: Готово");
    //ui->labelStatus->setText("Статус: Готово");
    qDebug() << "XOR is end";
}

void MainWindow::on_btnStart_clicked(){
    if (ui->radioOnce->isChecked()) {
        auto future = QtConcurrent::run([this]() {
            runXorProcess();
        });
    }
    else if (ui->radioTimer->isChecked()) {
        bool ok;
        int intervalSec = ui->spinInterval->text().toInt(&ok);
        if (!ok || intervalSec <= 0) {
            qWarning() << "Неверный интервал!";
            return;
        }
        timer->start(intervalSec * 1000);
        qDebug() << "Таймер запущен каждые" << intervalSec << "секунд";
    }
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define COUNT_SOURCE_OF_RISKS 18.0
#define COUNT_RISKS_EVENTS 41.0
#define NUMBER_OF_JURY 10.0

#include <QMainWindow>
#include <QAbstractButton>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QRandomGenerator>
#include <algorithm>
#include <QDebug>
#include <QComboBox>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonGroup_clicked(QAbstractButton* button);
    void on_buttonGroup2_clicked(QAbstractButton* button);
    void on_buttonGroup3_clicked(QAbstractButton* button);
    void on_buttonGroup4_clicked(QAbstractButton* button);

    void on_buttonGroup5_clicked(QAbstractButton* button);
    void on_buttonGroup6_clicked(QAbstractButton* button);
    void on_buttonGroup7_clicked(QAbstractButton* button);
    void on_buttonGroup8_clicked(QAbstractButton* button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    int sourceOfRiskSet[4]{7,3,3,5};
    int potentialRiskEvents[4]{11,7,9,14};
    std::vector<int> highLevelRisks;

    void calculateSourceOfRisk();
    void calculateRiskEvents();
    void initializateTable(QTableWidget* table, QString initValue, int startingColumn);
    void setZeroForNotCheckedRisk();
    int setByRiskPosition(int position);
    QString extraPaymentPerRiskToText(double min, double max, double value);
    QString ERtoText(double ER);
    int areasOfRiskToInt(QString text);

};
#endif // MAINWINDOW_H

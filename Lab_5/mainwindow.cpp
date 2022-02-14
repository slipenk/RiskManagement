#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->buttonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup_clicked);
    connect(ui->buttonGroup_2, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup2_clicked);
    connect(ui->buttonGroup_3, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup3_clicked);
    connect(ui->buttonGroup_4, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup4_clicked);
    connect(ui->buttonGroup_5, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup5_clicked);
    connect(ui->buttonGroup_6, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup6_clicked);
    connect(ui->buttonGroup_7, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup7_clicked);
    connect(ui->buttonGroup_8, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this,&MainWindow::on_buttonGroup8_clicked);

    initializateTable(ui->tableWidget,"0.00",1);


    initializateTable(ui->tableWidget_2,"0",1);
    initializateTable(ui->tableWidget_3,"0.00",0);
    initializateTable(ui->tableWidget_4,"",1);
    initializateTable(ui->tableWidget_5,"",1);
    initializateTable(ui->tableWidget_6,"0.00",0);
    initializateTable(ui->tableWidget_7,"0.00",1);
    initializateTable(ui->tableWidget_8,"0.00",1);

    ui->tableWidget_4->horizontalHeader()->resizeSection(0, 120);
    ui->tableWidget_4->horizontalHeader()->resizeSection(1, 160);
    ui->tableWidget_4->horizontalHeader()->resizeSection(2, 160);
    ui->tableWidget_4->horizontalHeader()->resizeSection(3, 160);
    ui->tableWidget_4->horizontalHeader()->resizeSection(4, 160);
    ui->tableWidget_4->horizontalHeader()->resizeSection(5, 160);

    ui->tableWidget_5->horizontalHeader()->resizeSection(1, 120);
    ui->tableWidget_5->horizontalHeader()->resizeSection(2, 160);
    ui->tableWidget_5->horizontalHeader()->resizeSection(3, 160);
    ui->tableWidget_5->horizontalHeader()->resizeSection(4, 160);
    ui->tableWidget_5->horizontalHeader()->resizeSection(5, 160);


    ui->tableWidget_7->horizontalHeader()->resizeSection(0, 120);
    ui->tableWidget_2->horizontalHeader()->resizeSection(0, 80);


    calculateSourceOfRisk();
    calculateRiskEvents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonGroup_clicked(QAbstractButton *button)
{
    if(button->isChecked()) sourceOfRiskSet[0] += 1;
    else sourceOfRiskSet[0] -= 1;
    calculateSourceOfRisk();
}

void MainWindow::on_buttonGroup2_clicked(QAbstractButton *button)
{
    if(button->isChecked()) sourceOfRiskSet[1] += 1;
    else sourceOfRiskSet[1] -= 1;
    calculateSourceOfRisk();
}

void MainWindow::on_buttonGroup3_clicked(QAbstractButton *button)
{
    if(button->isChecked()) sourceOfRiskSet[2] += 1;
    else sourceOfRiskSet[2] -= 1;
    calculateSourceOfRisk();
}

void MainWindow::on_buttonGroup4_clicked(QAbstractButton *button)
{
    if(button->isChecked()) sourceOfRiskSet[3] += 1;
    else sourceOfRiskSet[3] -= 1;
    calculateSourceOfRisk();
}

void MainWindow::on_buttonGroup5_clicked(QAbstractButton *button)
{
    if(button->isChecked()) potentialRiskEvents[0] += 1;
    else potentialRiskEvents[0] -= 1;
    calculateRiskEvents();
}

void MainWindow::on_buttonGroup6_clicked(QAbstractButton *button)
{
    if(button->isChecked()) potentialRiskEvents[1] += 1;
    else potentialRiskEvents[1] -= 1;
    calculateRiskEvents();
}

void MainWindow::on_buttonGroup7_clicked(QAbstractButton *button)
{
    if(button->isChecked()) potentialRiskEvents[2] += 1;
    else potentialRiskEvents[2] -= 1;
    calculateRiskEvents();
}

void MainWindow::on_buttonGroup8_clicked(QAbstractButton *button)
{
    if(button->isChecked()) potentialRiskEvents[3] += 1;
    else potentialRiskEvents[3] -= 1;
    calculateRiskEvents();
}

void MainWindow::calculateSourceOfRisk()
{
    ui->lineEdit->setText(QString::number((sourceOfRiskSet[0]/COUNT_SOURCE_OF_RISKS)*100,'f',2) + "%");
    ui->lineEdit_2->setText(QString::number((sourceOfRiskSet[1]/COUNT_SOURCE_OF_RISKS)*100,'f',2) + "%");
    ui->lineEdit_7->setText(QString::number((sourceOfRiskSet[2]/COUNT_SOURCE_OF_RISKS)*100,'f',2) + "%");
    ui->lineEdit_3->setText(QString::number((sourceOfRiskSet[3]/COUNT_SOURCE_OF_RISKS)*100,'f',2) + "%");

    double sum = 0;
    for(int i = 0; i < 4; ++i) sum += (sourceOfRiskSet[i]/COUNT_SOURCE_OF_RISKS)*100;
    ui->lineEdit_8->setText(QString::number((double)sum,'f',2) + "%");
}

void MainWindow::calculateRiskEvents()
{
    ui->lineEdit_13->setText(QString::number((potentialRiskEvents[0]/COUNT_RISKS_EVENTS)*100,'f',2) + "%");
    ui->lineEdit_11->setText(QString::number((potentialRiskEvents[1]/COUNT_RISKS_EVENTS)*100,'f',2) + "%");
    ui->lineEdit_9->setText(QString::number((potentialRiskEvents[2]/COUNT_RISKS_EVENTS)*100,'f',2) + "%");
    ui->lineEdit_10->setText(QString::number((potentialRiskEvents[3]/COUNT_RISKS_EVENTS)*100,'f',2) + "%");

    double sum = 0;
    for(int i = 0; i < 4; ++i) sum += (potentialRiskEvents[i]/COUNT_RISKS_EVENTS)*100;
    ui->lineEdit_12->setText(QString::number((double)sum,'f',2) + "%");
}

void MainWindow::on_pushButton_clicked()
{
    QRandomGenerator* rand = new QRandomGenerator(QDateTime::currentDateTime().toTime_t());
    for(int i = 0; i < ui->tableWidget->rowCount();++i)
    {
        for(int j = 1; j < ui->tableWidget->columnCount()-1;++j)
        {
            ui->tableWidget->item(i,j)->setText(QString::number(rand->bounded(1.0),'f',2));
        }
    }

    for(int i = 0; i < ui->tableWidget->rowCount();++i)
    {
        double sum = 0;
        for(int j = 1; j < ui->tableWidget->columnCount();++j)
        {
            sum += ui->tableWidget->item(i,j)->text().toDouble();
        }
        ui->tableWidget->item(i,11)->setText(QString::number(sum/NUMBER_OF_JURY,'f',3));
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        for(int j = 1; j < ui->tableWidget->columnCount(); ++j)
        {
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void MainWindow::initializateTable(QTableWidget* table, QString initValue, int startingColumn)
{
    for(int i = 0; i < table->rowCount();++i)
    {
        for(int j = startingColumn; j < table->columnCount();++j)
        {
            QTableWidgetItem* item = new QTableWidgetItem(initValue);
            table->setItem(i,j,item);
        }
    }
}

void MainWindow::setZeroForNotCheckedRisk()
{
    QList<QAbstractButton*> allRisks = ui->buttonGroup_5->buttons() + ui->buttonGroup_6->buttons() + ui->buttonGroup_7->buttons() + ui->buttonGroup_8->buttons();
    std::sort(allRisks.begin(),allRisks.end(),[](QAbstractButton* b1, QAbstractButton* b2){return b1->objectName() < b2->objectName();});

    for(int i = 0; i < ui->tableWidget->rowCount();++i)
    {
        if(!allRisks[i]->isChecked())
        {
            for(int j = 1; j < ui->tableWidget_4->columnCount();++j)
            {
                ui->tableWidget_4->item(i,j)->setText("0");
                if(j == 2) ui->tableWidget_4->item(i,j)->setText("Дуже низька");
                if(j == 5) ui->tableWidget_4->item(i,j)->setText("Низький");
            }
        }
    }
}

int MainWindow::setByRiskPosition(int position)
{
    if(position < 11) return 0;
    if(position >= 11 && position < 18) return 1;
    if(position >= 18 && position < 28) return 2;
    if(position >= 28 && position < 41) return 3;
    else return 4;
}

QString MainWindow::extraPaymentPerRiskToText(double min, double max, double value)
{
    double mpr = (max-min)/3.0;
    if(value >= min && value < mpr+min) return "Низький";
    if(value >= mpr + min && value < 2*mpr + min) return "Середній";
    else return "Високий";
}

QString MainWindow::ERtoText(double ER)
{
    if(ER < 0.1) return "Дуже низька";
    if(ER >= 0.1 && ER < 0.25) return "Низька";
    if(ER >= 0.25 && ER < 0.5) return "Середня";
    if(ER >= 0.5 && ER < 0.75) return "Висока";
    else return "Дуже висока";
}

int MainWindow::areasOfRiskToInt(QString text)
{
    if(text == "Пом'якшення") return 1;
    if(text == "Прийняття") return 2;
    if(text == "Ухилення") return 3;
    if(text == "Передача") return 4;
}

void MainWindow::on_pushButton_2_clicked()
{
    QRandomGenerator* rand = new QRandomGenerator(QDateTime::currentDateTime().toTime_t());
    for(int i = 0; i < ui->tableWidget_2->rowCount();++i)
    {
        int sum = 0;
        for(int j = 1; j < ui->tableWidget_2->columnCount();++j)
        {
            int val = rand->bounded(11);
            sum += val;
            ui->tableWidget_2->item(i,j)->setText(QString::number(val));
        }
        ui->tableWidget_2->item(i,11)->setText(QString::number(sum));
    }

    for(int i = 0; i < ui->tableWidget_2->rowCount(); ++i)
    {
        for(int j = 1; j < ui->tableWidget_2->columnCount(); ++j)
        {
            ui->tableWidget_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    double sum = 0;
    QRandomGenerator* rand = new QRandomGenerator(QDateTime::currentDateTime().toTime_t());
    for(int j = 1; j < ui->tableWidget_3->columnCount();++j)
    {
        double val = rand->bounded(501.0);
        int c = int(val);
        int k = c % 10;
        if(c % 10 != 0) {
            c = c - k;
            val = c;
        }
        sum += val;

        ui->tableWidget_3->item(0,j)->setText(QString::number(round(val),'f',1));
    }
    ui->tableWidget_3->item(0,0)->setText(QString::number(round(sum),'f',1));


        for(int j = 0; j < ui->tableWidget_3->columnCount(); ++j)
        {
            ui->tableWidget_3->item(0,j)->setTextAlignment(Qt::AlignCenter);
        }

}

void MainWindow::on_pushButton_4_clicked()
{

    //ER(coef)
    for(int i = 0; i < ui->tableWidget->rowCount();++i)
    {
        double sum = 0;
        for(int j = 1; j < ui->tableWidget->columnCount()-1;++j)
        {
            sum += ui->tableWidget->item(i,j)->text().toDouble() * ui->tableWidget_2->item(setByRiskPosition(i),j)->text().toDouble();
        }
        ui->tableWidget_4->item(i,1)->setText(QString::number(sum/ui->tableWidget_2->item(setByRiskPosition(i),11)->text().toDouble(),'f',3));
    }

    //ER(text)
    for(int i = 0; i < ui->tableWidget->rowCount();++i)
    {
        ui->tableWidget_4->item(i,2)->setText(ERtoText(ui->tableWidget_4->item(i,1)->text().toDouble()));
    }

    setZeroForNotCheckedRisk();

    //table_5
    double setER[4]{0};
    double setERcoef[4]{0};
    double setLossFactor[4]{0};
    int countOfElements = 0;

    for(int i = 0; i < ui->tableWidget_4->rowCount(); ++i)
    {
        int setNum = setByRiskPosition(i);
        setER[setNum] += ui->tableWidget->item(i,11)->text().toDouble();
        setERcoef[setNum] += ui->tableWidget_4->item(i,1)->text().toDouble();
        setLossFactor[setNum] += ui->tableWidget_7->item(i,1)->text().toDouble();
        ++countOfElements;

        if(setNum < setByRiskPosition(i+1))
        {
            ui->tableWidget_5->item(setNum,1)->setText(QString::number(setER[setNum] / countOfElements,'f',3));
            ui->tableWidget_5->item(setNum,2)->setText(QString::number(setERcoef[setNum] / countOfElements,'f',3));
            ui->tableWidget_5->item(setNum,3)->setText(ERtoText(setERcoef[setNum] / countOfElements));
            countOfElements = 0;
        }
    }

    //money


    std::vector<double> paymentPerRist;
    std::vector<double> extraPaymentPerRisk;

    double extraPaymentPerSet[4]{0};

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        paymentPerRist.push_back(ui->tableWidget_7->item(i,1)->text().toDouble()*ui->tableWidget_3->item(0,setByRiskPosition(i)+1)->text().toDouble()/setLossFactor[setByRiskPosition(i)]);
    }

    double totalSum = 0;
    for(int i = 0; i < ui->tableWidget_4->rowCount(); ++i)
    {
        int setNum = setByRiskPosition(i);

        ui->tableWidget_4->item(i,3)->setText(QString::number(ui->tableWidget_4->item(i,1)->text().toDouble()*paymentPerRist[i],'f',2));
        ui->tableWidget_4->item(i,4)->setText(QString::number(ui->tableWidget_4->item(i,3)->text().toDouble()+paymentPerRist[i],'f',2));
        extraPaymentPerSet[setByRiskPosition(i)] += ui->tableWidget_4->item(i,3)->text().toDouble();
        extraPaymentPerRisk.push_back(ui->tableWidget_4->item(i,3)->text().toDouble());

        setZeroForNotCheckedRisk();

        if(setNum < setByRiskPosition(i+1))
        {
            ui->tableWidget_5->item(setNum,4)->setText(QString::number(extraPaymentPerSet[setNum],'f',2));
            ui->tableWidget_5->item(setNum,5)->setText(QString::number(ui->tableWidget_5->item(setNum,4)->text().toDouble() + ui->tableWidget_3->item(0,setNum+1)->text().toDouble(),'f',2));
            ui->tableWidget_6->item(0,setNum + 1)->setText(QString::number(ui->tableWidget_5->item(setNum,4)->text().toDouble() + ui->tableWidget_3->item(0,setNum+1)->text().toDouble(),'f',2));
            totalSum += ui->tableWidget_5->item(setNum,4)->text().toDouble() + ui->tableWidget_3->item(0,setNum+1)->text().toDouble();
        }
    }
    ui->tableWidget_6->item(0,0)->setText(QString::number(totalSum,'f',2));

    double min = *std::min_element(extraPaymentPerRisk.begin(),extraPaymentPerRisk.end());
    double max = *std::max_element(extraPaymentPerRisk.begin(),extraPaymentPerRisk.end());

    ui->tableWidget_9->setRowCount(0);
    highLevelRisks.clear();



    //Пріоритети

    for(int i = 0; i < extraPaymentPerRisk.size(); ++i)
    {
        QString priority = extraPaymentPerRiskToText(min,max,ui->tableWidget_4->item(i,3)->text().toDouble());
        ui->tableWidget_4->item(i,5)->setText(priority);

        if(priority == "Високий")
        {
            highLevelRisks.push_back(i);

            ui->tableWidget_9->setRowCount(ui->tableWidget_9->rowCount()+1);

            ui->tableWidget_9->setItem(ui->tableWidget_9->rowCount()-1,0,new QTableWidgetItem());
            ui->tableWidget_9->setItem(ui->tableWidget_9->rowCount()-1,1,new QTableWidgetItem());

            ui->tableWidget_9->item(ui->tableWidget_9->rowCount()-1,0)->setText(QString::number(i));
            ui->tableWidget_9->item(ui->tableWidget_9->rowCount()-1,1)->setText(ui->tableWidget_4->item(i,0)->text());

            QComboBox* riskHelper{new QComboBox()};
            QComboBox* areasOfRisk{new QComboBox()};
            areasOfRisk->addItems({"Пом'якшення", "Прийняття", "Ухилення", "Передача"});

            QRandomGenerator* rand = new QRandomGenerator(QDateTime::currentDateTime().toMSecsSinceEpoch());

            for(int j = 0; j < 3; ++j)
            {
                riskHelper->addItem(ui->tableWidget_8->item(rand->bounded(19),0)->text());
            }

            ui->tableWidget_9->setCellWidget(ui->tableWidget_9->rowCount()-1,2,riskHelper);
            ui->tableWidget_9->setCellWidget(ui->tableWidget_9->rowCount()-1,3,areasOfRisk);
        }
    }

    for(int i = 0; i < ui->tableWidget_4->rowCount(); ++i)
    {
        for(int j = 1; j < ui->tableWidget_4->columnCount(); ++j)
        {
            ui->tableWidget_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    for(int i = 0; i < ui->tableWidget_5->rowCount(); ++i)
    {
        for(int j = 1; j < ui->tableWidget_5->columnCount(); ++j)
        {
            ui->tableWidget_5->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    for(int j = 0; j < ui->tableWidget_6->columnCount(); ++j)
    {
        ui->tableWidget_6->item(0,j)->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QRandomGenerator* rand = new QRandomGenerator(QDateTime::currentDateTime().toTime_t());
    for(int i = 0; i < ui->tableWidget_7->rowCount();++i)
    {
        for(int j = 1; j < ui->tableWidget_7->columnCount();++j)
        {
            ui->tableWidget_7->item(i,j)->setText(QString::number(rand->bounded(1.0),'f',2));
        }
    }

    for(int i = 0; i < ui->tableWidget_7->rowCount(); ++i)
    {
        for(int j = 1; j < ui->tableWidget_7->columnCount(); ++j)
        {
            ui->tableWidget_7->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QRandomGenerator* rand = new QRandomGenerator(QDateTime::currentDateTime().toTime_t());
    for(int i = 0; i < ui->tableWidget_8->rowCount();++i)
    {
        for(int j = 1; j < ui->tableWidget_8->columnCount();++j)
        {
            ui->tableWidget_8->item(i,j)->setText(QString::number(rand->bounded(0.21),'f',2));
        }
    }
    for(int i = 0; i < ui->tableWidget_8->rowCount(); ++i)
    {
        for(int j = 1; j < ui->tableWidget_8->columnCount(); ++j)
        {
            ui->tableWidget_8->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    std::vector<double> paymentPerRisk;
    std::vector<double> extraPaymentPerRisk;
    std::vector<double> oldPaymentPerHighRisk;
    double setLossFactor[4]{0};

    for(int i = 0; i < ui->tableWidget_4->rowCount() ;++i)
    {
        setLossFactor[setByRiskPosition(i)] += ui->tableWidget_7->item(i,1)->text().toDouble();
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        paymentPerRisk.push_back(ui->tableWidget_7->item(i,1)->text().toDouble()*ui->tableWidget_3->item(0,setByRiskPosition(i)+1)->text().toDouble()/setLossFactor[setByRiskPosition(i)]);
    }


    for(int i = 0; i < highLevelRisks.size(); ++i)
    {
        double currentExtraPayment = ui->tableWidget_4->item(highLevelRisks[i],3)->text().toDouble();
        double setOldVal = ui->tableWidget_5->item(setByRiskPosition(highLevelRisks[i]),4)->text().toDouble();
        setOldVal -= currentExtraPayment;

        QComboBox* choise_1 = (QComboBox*)ui->tableWidget_9->cellWidget(i,2);
        QComboBox* areaOfRisk = (QComboBox*)ui->tableWidget_9->cellWidget(i,3);

        double coef = 1.0 - ui->tableWidget_8->item(ui->tableWidget_8->findItems(choise_1->currentText(), Qt::MatchExactly)[0]->row(),areasOfRiskToInt(areaOfRisk->currentText()))->text().toDouble();
        qDebug() << ui->tableWidget_8->findItems(choise_1->currentText(), Qt::MatchExactly)[0]->row();
        ui->tableWidget_4->item(highLevelRisks[i],3)->setText(QString::number(currentExtraPayment * coef,'f',2));
        ui->tableWidget_5->item(setByRiskPosition(highLevelRisks[i]),4)->setText(QString::number(setOldVal + currentExtraPayment * coef,'f',2));

        setOldVal = ui->tableWidget_5->item(setByRiskPosition(highLevelRisks[i]),5)->text().toDouble();
        setOldVal -= currentExtraPayment;

        ui->tableWidget_4->item(highLevelRisks[i],4)->setText(QString::number(currentExtraPayment * coef + paymentPerRisk[highLevelRisks[i]],'f',2));
        ui->tableWidget_5->item(setByRiskPosition(highLevelRisks[i]),5)->setText(QString::number(setOldVal + currentExtraPayment * coef,'f',2));
        ui->tableWidget_6->item(0,setByRiskPosition(highLevelRisks[i])+1)->setText(QString::number(setOldVal + currentExtraPayment * coef,'f',2));
    }

    for(int i = 0; i < ui->tableWidget_4->rowCount() ;++i)
    {
        extraPaymentPerRisk.push_back(ui->tableWidget_4->item(i,3)->text().toDouble());
    }


    double min = *std::min_element(extraPaymentPerRisk.begin(),extraPaymentPerRisk.end());
    double max = *std::max_element(extraPaymentPerRisk.begin(),extraPaymentPerRisk.end());

    for(int i = 0; i < highLevelRisks.size(); ++i)
    {
        QString priority = extraPaymentPerRiskToText(min,max,ui->tableWidget_4->item(highLevelRisks[i],4)->text().toDouble());
        ui->tableWidget_4->item(highLevelRisks[i],5)->setText(priority);
    }

    double sum = 0.0;
    for(int i = 1; i < ui->tableWidget_6->columnCount(); ++i)
    {
        sum += ui->tableWidget_6->item(0,i)->text().toDouble();
    }
    ui->tableWidget_6->item(0,0)->setText(QString::number(sum,'f',2));


     for(int j = 0; j < ui->tableWidget_9->rowCount(); ++j)
     {
         ui->tableWidget_9->item(j,0)->setTextAlignment(Qt::AlignCenter);
     }

}



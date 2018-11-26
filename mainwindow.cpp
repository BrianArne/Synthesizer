#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <vector>
#include "JpegParser.hpp"
#include "Mapper.hpp"
#include <iostream>
#include "Sine.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString q_hertz=ui->lineEdit->text();
    int hertz = q_hertz.toInt();
    std::vector<double>holder;
    std::vector<std::vector<double> > partials;

    double s_1 = (ui->verticalSlider->value()/100.); holder.push_back(s_1);
    double s_2 = (ui->verticalSlider_2->value()/100.);holder.push_back(s_2);
    double s_3 = (ui->verticalSlider_3->value()/100.);holder.push_back(s_3);
    double s_4 = (ui->verticalSlider_4->value()/100.);holder.push_back(s_4);
    double s_5 = (ui->verticalSlider_5->value()/100.);holder.push_back(s_5);
    double s_6 = (ui->verticalSlider_6->value()/100.);holder.push_back(s_6);
    double s_7 = (ui->verticalSlider_7->value()/100.);holder.push_back(s_7);
    double s_8 = (ui->verticalSlider_8->value()/100.);holder.push_back(s_8);
    double s_9 = (ui->verticalSlider_9->value()/100.);holder.push_back(s_9);
    double s_10 = (ui->verticalSlider_10->value()/100.);holder.push_back(s_10);
    double s_11 = (ui->verticalSlider_11->value()/100.);holder.push_back(s_11);
    double s_12 = (ui->verticalSlider_12->value()/100.);holder.push_back(s_12);
    double s_13 = (ui->verticalSlider_13->value()/100.);holder.push_back(s_13);
    double s_14 = (ui->verticalSlider_14->value()/100.);holder.push_back(s_14);
    double s_15 = (ui->verticalSlider_15->value()/100.);holder.push_back(s_15);
    double s_16 = (ui->verticalSlider_16->value()/100.);holder.push_back(s_16);

    partials.push_back(holder);

    int which_partial = 0;

    Sine sine(hertz, partials, &which_partial);

    ScopedPaHandler paInit;
    //if( paInit.result() != paNoError ) goto error;

    if (sine.open(Pa_GetDefaultOutputDevice()))
    {
        if (sine.start())
        {
            //for (which_partial = 0; which_partial < partials[0].size(); which_partial++){
                //printf("Play for %d seconds.\n", NUM_SECONDS );
                Pa_Sleep( NUM_SECONDS * 5000 );
            //}
            sine.stop();
        }

        sine.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select JPEG"), "~/");

    QByteArray q_filename = filename.toLatin1();
    const char * c_file = q_filename.data();

    QString q_hertz=ui->lineEdit->text();
    int hertz = q_hertz.toInt();

    JpegParser::JpegParser pic(c_file);
    pic.fill_vec();
    JpegParser::RGBVec vec = pic.get_rgb_vec();

    Mapper::Mapper map(vec);
    map.map_partials();
    Mapper::PartialContainer partials = map.get_partials();
    int which_partial = 0;

    Sine sine(hertz, partials, &which_partial);

    ScopedPaHandler paInit;
    if( paInit.result() != paNoError ) goto error;

    if (sine.open(Pa_GetDefaultOutputDevice()))
    {
        if (sine.start())
        {
            for (which_partial = 0; which_partial < partials.size(); which_partial++){
                printf("Play for %d seconds.\n", NUM_SECONDS );
                Pa_Sleep( NUM_SECONDS * 1000 );
            }
            sine.stop();
        }

        sine.close();
    }

    printf("Test finished.\n");
    //return paNoError;

error:
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", paInit.result() );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( paInit.result() ) );
    //return 1;

}

void MainWindow::on_lineEdit_returnPressed()
{
   //Fundamental Entererd
}

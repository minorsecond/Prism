/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QLabel *pathFormatLabel;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *pathFormatLineEdit;
    QComboBox *whiteSpaceReplacementSelector;
    QComboBox *attributeSelectorInput;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLineEdit *inputPathEdit;
    QLabel *rootPathLabel;
    QLabel *label;
    QPushButton *outputPathBrowseButton;
    QPushButton *inputPathBrowseButton;
    QLineEdit *outputPathEdit;
    QCheckBox *seperateOutputPathCheckbox;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QCheckBox *tiffCheckBox;
    QCheckBox *rawCheckBox;
    QCheckBox *jpgCheckBox;
    QCheckBox *includeSidecarCheckbox;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *progressBar;
    QDialogButtonBox *mainButtonBox;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(855, 398);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pathFormatLabel = new QLabel(frame_3);
        pathFormatLabel->setObjectName(QString::fromUtf8("pathFormatLabel"));

        gridLayout_4->addWidget(pathFormatLabel, 1, 0, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        pathFormatLineEdit = new QLineEdit(frame_3);
        pathFormatLineEdit->setObjectName(QString::fromUtf8("pathFormatLineEdit"));

        gridLayout_4->addWidget(pathFormatLineEdit, 1, 2, 1, 1);

        whiteSpaceReplacementSelector = new QComboBox(frame_3);
        whiteSpaceReplacementSelector->setObjectName(QString::fromUtf8("whiteSpaceReplacementSelector"));

        gridLayout_4->addWidget(whiteSpaceReplacementSelector, 3, 2, 1, 1);

        attributeSelectorInput = new QComboBox(frame_3);
        attributeSelectorInput->setObjectName(QString::fromUtf8("attributeSelectorInput"));

        gridLayout_4->addWidget(attributeSelectorInput, 2, 2, 1, 1);


        gridLayout->addWidget(frame_3, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        inputPathEdit = new QLineEdit(frame);
        inputPathEdit->setObjectName(QString::fromUtf8("inputPathEdit"));

        gridLayout_2->addWidget(inputPathEdit, 1, 1, 1, 1);

        rootPathLabel = new QLabel(frame);
        rootPathLabel->setObjectName(QString::fromUtf8("rootPathLabel"));

        gridLayout_2->addWidget(rootPathLabel, 1, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        outputPathBrowseButton = new QPushButton(frame);
        outputPathBrowseButton->setObjectName(QString::fromUtf8("outputPathBrowseButton"));

        gridLayout_2->addWidget(outputPathBrowseButton, 3, 2, 1, 1);

        inputPathBrowseButton = new QPushButton(frame);
        inputPathBrowseButton->setObjectName(QString::fromUtf8("inputPathBrowseButton"));

        gridLayout_2->addWidget(inputPathBrowseButton, 1, 2, 1, 1);

        outputPathEdit = new QLineEdit(frame);
        outputPathEdit->setObjectName(QString::fromUtf8("outputPathEdit"));

        gridLayout_2->addWidget(outputPathEdit, 3, 1, 1, 1);

        seperateOutputPathCheckbox = new QCheckBox(frame);
        seperateOutputPathCheckbox->setObjectName(QString::fromUtf8("seperateOutputPathCheckbox"));

        gridLayout_2->addWidget(seperateOutputPathCheckbox, 2, 1, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tiffCheckBox = new QCheckBox(frame_2);
        tiffCheckBox->setObjectName(QString::fromUtf8("tiffCheckBox"));

        gridLayout_3->addWidget(tiffCheckBox, 3, 1, 1, 1);

        rawCheckBox = new QCheckBox(frame_2);
        rawCheckBox->setObjectName(QString::fromUtf8("rawCheckBox"));

        gridLayout_3->addWidget(rawCheckBox, 1, 1, 1, 1);

        jpgCheckBox = new QCheckBox(frame_2);
        jpgCheckBox->setObjectName(QString::fromUtf8("jpgCheckBox"));

        gridLayout_3->addWidget(jpgCheckBox, 0, 1, 1, 1);

        includeSidecarCheckbox = new QCheckBox(frame_2);
        includeSidecarCheckbox->setObjectName(QString::fromUtf8("includeSidecarCheckbox"));

        gridLayout_3->addWidget(includeSidecarCheckbox, 2, 1, 1, 1);


        gridLayout->addWidget(frame_2, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 7, 0, 1, 1);

        mainButtonBox = new QDialogButtonBox(centralwidget);
        mainButtonBox->setObjectName(QString::fromUtf8("mainButtonBox"));
        mainButtonBox->setOrientation(Qt::Horizontal);
        mainButtonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

        gridLayout->addWidget(mainButtonBox, 9, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 22));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(inputPathEdit, inputPathBrowseButton);
        QWidget::setTabOrder(inputPathBrowseButton, seperateOutputPathCheckbox);
        QWidget::setTabOrder(seperateOutputPathCheckbox, outputPathEdit);
        QWidget::setTabOrder(outputPathEdit, outputPathBrowseButton);
        QWidget::setTabOrder(outputPathBrowseButton, jpgCheckBox);
        QWidget::setTabOrder(jpgCheckBox, rawCheckBox);
        QWidget::setTabOrder(rawCheckBox, tiffCheckBox);
        QWidget::setTabOrder(tiffCheckBox, pathFormatLineEdit);
        QWidget::setTabOrder(pathFormatLineEdit, attributeSelectorInput);
        QWidget::setTabOrder(attributeSelectorInput, whiteSpaceReplacementSelector);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ExifSort", nullptr));
        pathFormatLabel->setText(QCoreApplication::translate("MainWindow", "Path Format:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Replace Whitespace with:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Attribute Selector", nullptr));
        rootPathLabel->setText(QCoreApplication::translate("MainWindow", "Input Path:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Output Path:", nullptr));
        outputPathBrowseButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        inputPathBrowseButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        seperateOutputPathCheckbox->setText(QCoreApplication::translate("MainWindow", "Separate output path", nullptr));
        tiffCheckBox->setText(QCoreApplication::translate("MainWindow", "Tiff", nullptr));
        rawCheckBox->setText(QCoreApplication::translate("MainWindow", "RAW", nullptr));
        jpgCheckBox->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        includeSidecarCheckbox->setText(QCoreApplication::translate("MainWindow", "Include sidecar files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'bearermonitor_240_320.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEARERMONITOR_240_320_H
#define UI_BEARERMONITOR_240_320_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BearerMonitor
{
public:
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *systemState;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *onlineStateLayout;
    QLabel *onlineStateLabel;
    QLabel *onlineState;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *configurationNameLayout;
    QLabel *configurationNameLabel;
    QLabel *configurationName;
    QHBoxLayout *configurationStateLayout;
    QLabel *configurationStateLabel;
    QLabel *configurationState;
    QHBoxLayout *configurationTypeLayout;
    QLabel *configurationTypeLabel;
    QLabel *configurationType;
    QHBoxLayout *configurationPurposeLayout;
    QLabel *configurationPurposeLabel;
    QLabel *configurationPurpose;
    QHBoxLayout *configurationIdentifierLayout;
    QLabel *configurationIdentifierLabel;
    QLabel *configurationIdentifier;
    QHBoxLayout *configurationRoamingLayout;
    QLabel *configurationRoamingLabel;
    QLabel *configurationRoaming;
    QHBoxLayout *configurationChildrenLayout;
    QLabel *configurationChildrenLabel;
    QLabel *configurationChildren;
    QGroupBox *nlaGroup;
    QHBoxLayout *horizontalLayout;
    QPushButton *registerButton;
    QPushButton *unregisterButton;
    QPushButton *newSessionButton;
    QPushButton *deleteSessionButton;
    QPushButton *scanButton;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QTreeWidget *treeWidget;
    QGroupBox *sessionGroup;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;

    void setupUi(QWidget *BearerMonitor)
    {
        if (BearerMonitor->objectName().isEmpty())
            BearerMonitor->setObjectName(QStringLiteral("BearerMonitor"));
        BearerMonitor->resize(240, 320);
        verticalLayout_5 = new QVBoxLayout(BearerMonitor);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        scrollArea = new QScrollArea(BearerMonitor);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -274, 206, 576));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        systemState = new QGroupBox(scrollAreaWidgetContents);
        systemState->setObjectName(QStringLiteral("systemState"));
        systemState->setFlat(true);
        verticalLayout_4 = new QVBoxLayout(systemState);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 0, 0);
        onlineStateLayout = new QHBoxLayout();
        onlineStateLayout->setObjectName(QStringLiteral("onlineStateLayout"));
        onlineStateLabel = new QLabel(systemState);
        onlineStateLabel->setObjectName(QStringLiteral("onlineStateLabel"));

        onlineStateLayout->addWidget(onlineStateLabel);

        onlineState = new QLabel(systemState);
        onlineState->setObjectName(QStringLiteral("onlineState"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(onlineState->sizePolicy().hasHeightForWidth());
        onlineState->setSizePolicy(sizePolicy);

        onlineStateLayout->addWidget(onlineState);


        verticalLayout_4->addLayout(onlineStateLayout);


        verticalLayout_2->addWidget(systemState);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(true);
        horizontalLayout_9 = new QHBoxLayout(groupBox);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, -1, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        configurationNameLayout = new QHBoxLayout();
        configurationNameLayout->setObjectName(QStringLiteral("configurationNameLayout"));
        configurationNameLabel = new QLabel(groupBox);
        configurationNameLabel->setObjectName(QStringLiteral("configurationNameLabel"));

        configurationNameLayout->addWidget(configurationNameLabel);

        configurationName = new QLabel(groupBox);
        configurationName->setObjectName(QStringLiteral("configurationName"));
        sizePolicy.setHeightForWidth(configurationName->sizePolicy().hasHeightForWidth());
        configurationName->setSizePolicy(sizePolicy);

        configurationNameLayout->addWidget(configurationName);


        verticalLayout->addLayout(configurationNameLayout);

        configurationStateLayout = new QHBoxLayout();
        configurationStateLayout->setObjectName(QStringLiteral("configurationStateLayout"));
        configurationStateLabel = new QLabel(groupBox);
        configurationStateLabel->setObjectName(QStringLiteral("configurationStateLabel"));

        configurationStateLayout->addWidget(configurationStateLabel);

        configurationState = new QLabel(groupBox);
        configurationState->setObjectName(QStringLiteral("configurationState"));
        sizePolicy.setHeightForWidth(configurationState->sizePolicy().hasHeightForWidth());
        configurationState->setSizePolicy(sizePolicy);

        configurationStateLayout->addWidget(configurationState);


        verticalLayout->addLayout(configurationStateLayout);

        configurationTypeLayout = new QHBoxLayout();
        configurationTypeLayout->setObjectName(QStringLiteral("configurationTypeLayout"));
        configurationTypeLabel = new QLabel(groupBox);
        configurationTypeLabel->setObjectName(QStringLiteral("configurationTypeLabel"));

        configurationTypeLayout->addWidget(configurationTypeLabel);

        configurationType = new QLabel(groupBox);
        configurationType->setObjectName(QStringLiteral("configurationType"));
        sizePolicy.setHeightForWidth(configurationType->sizePolicy().hasHeightForWidth());
        configurationType->setSizePolicy(sizePolicy);

        configurationTypeLayout->addWidget(configurationType);


        verticalLayout->addLayout(configurationTypeLayout);

        configurationPurposeLayout = new QHBoxLayout();
        configurationPurposeLayout->setObjectName(QStringLiteral("configurationPurposeLayout"));
        configurationPurposeLabel = new QLabel(groupBox);
        configurationPurposeLabel->setObjectName(QStringLiteral("configurationPurposeLabel"));

        configurationPurposeLayout->addWidget(configurationPurposeLabel);

        configurationPurpose = new QLabel(groupBox);
        configurationPurpose->setObjectName(QStringLiteral("configurationPurpose"));
        sizePolicy.setHeightForWidth(configurationPurpose->sizePolicy().hasHeightForWidth());
        configurationPurpose->setSizePolicy(sizePolicy);

        configurationPurposeLayout->addWidget(configurationPurpose);


        verticalLayout->addLayout(configurationPurposeLayout);

        configurationIdentifierLayout = new QHBoxLayout();
        configurationIdentifierLayout->setObjectName(QStringLiteral("configurationIdentifierLayout"));
        configurationIdentifierLabel = new QLabel(groupBox);
        configurationIdentifierLabel->setObjectName(QStringLiteral("configurationIdentifierLabel"));

        configurationIdentifierLayout->addWidget(configurationIdentifierLabel);

        configurationIdentifier = new QLabel(groupBox);
        configurationIdentifier->setObjectName(QStringLiteral("configurationIdentifier"));
        sizePolicy.setHeightForWidth(configurationIdentifier->sizePolicy().hasHeightForWidth());
        configurationIdentifier->setSizePolicy(sizePolicy);

        configurationIdentifierLayout->addWidget(configurationIdentifier);


        verticalLayout->addLayout(configurationIdentifierLayout);

        configurationRoamingLayout = new QHBoxLayout();
        configurationRoamingLayout->setObjectName(QStringLiteral("configurationRoamingLayout"));
        configurationRoamingLabel = new QLabel(groupBox);
        configurationRoamingLabel->setObjectName(QStringLiteral("configurationRoamingLabel"));

        configurationRoamingLayout->addWidget(configurationRoamingLabel);

        configurationRoaming = new QLabel(groupBox);
        configurationRoaming->setObjectName(QStringLiteral("configurationRoaming"));
        sizePolicy.setHeightForWidth(configurationRoaming->sizePolicy().hasHeightForWidth());
        configurationRoaming->setSizePolicy(sizePolicy);

        configurationRoamingLayout->addWidget(configurationRoaming);


        verticalLayout->addLayout(configurationRoamingLayout);

        configurationChildrenLayout = new QHBoxLayout();
        configurationChildrenLayout->setObjectName(QStringLiteral("configurationChildrenLayout"));
        configurationChildrenLabel = new QLabel(groupBox);
        configurationChildrenLabel->setObjectName(QStringLiteral("configurationChildrenLabel"));

        configurationChildrenLayout->addWidget(configurationChildrenLabel);

        configurationChildren = new QLabel(groupBox);
        configurationChildren->setObjectName(QStringLiteral("configurationChildren"));
        sizePolicy.setHeightForWidth(configurationChildren->sizePolicy().hasHeightForWidth());
        configurationChildren->setSizePolicy(sizePolicy);

        configurationChildrenLayout->addWidget(configurationChildren);


        verticalLayout->addLayout(configurationChildrenLayout);

        nlaGroup = new QGroupBox(groupBox);
        nlaGroup->setObjectName(QStringLiteral("nlaGroup"));
        horizontalLayout = new QHBoxLayout(nlaGroup);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        registerButton = new QPushButton(nlaGroup);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        horizontalLayout->addWidget(registerButton);

        unregisterButton = new QPushButton(nlaGroup);
        unregisterButton->setObjectName(QStringLiteral("unregisterButton"));

        horizontalLayout->addWidget(unregisterButton);


        verticalLayout->addWidget(nlaGroup);

        newSessionButton = new QPushButton(groupBox);
        newSessionButton->setObjectName(QStringLiteral("newSessionButton"));

        verticalLayout->addWidget(newSessionButton);

        deleteSessionButton = new QPushButton(groupBox);
        deleteSessionButton->setObjectName(QStringLiteral("deleteSessionButton"));

        verticalLayout->addWidget(deleteSessionButton);

        scanButton = new QPushButton(groupBox);
        scanButton->setObjectName(QStringLiteral("scanButton"));

        verticalLayout->addWidget(scanButton);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);

        verticalLayout->addWidget(progressBar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        treeWidget = new QTreeWidget(groupBox);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);


        horizontalLayout_9->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox);

        sessionGroup = new QGroupBox(scrollAreaWidgetContents);
        sessionGroup->setObjectName(QStringLiteral("sessionGroup"));
        sessionGroup->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(sessionGroup);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, 0, 0);
        tabWidget = new QTabWidget(sessionGroup);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(tabWidget);


        verticalLayout_2->addWidget(sessionGroup);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        retranslateUi(BearerMonitor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BearerMonitor);
    } // setupUi

    void retranslateUi(QWidget *BearerMonitor)
    {
        BearerMonitor->setWindowTitle(QApplication::translate("BearerMonitor", "BearerMonitor", nullptr));
        systemState->setTitle(QApplication::translate("BearerMonitor", "System State", nullptr));
        onlineStateLabel->setText(QApplication::translate("BearerMonitor", "Online State:", nullptr));
        onlineState->setText(QString());
        groupBox->setTitle(QApplication::translate("BearerMonitor", "Configurations", nullptr));
        configurationNameLabel->setText(QApplication::translate("BearerMonitor", "Name:", nullptr));
        configurationName->setText(QString());
        configurationStateLabel->setText(QApplication::translate("BearerMonitor", "State:", nullptr));
        configurationState->setText(QString());
        configurationTypeLabel->setText(QApplication::translate("BearerMonitor", "Type:", nullptr));
        configurationType->setText(QApplication::translate("BearerMonitor", "Invalid", nullptr));
        configurationPurposeLabel->setText(QApplication::translate("BearerMonitor", "Purpose:", nullptr));
        configurationPurpose->setText(QApplication::translate("BearerMonitor", "Unknown", nullptr));
        configurationIdentifierLabel->setText(QApplication::translate("BearerMonitor", "Identifier:", nullptr));
        configurationIdentifier->setText(QString());
        configurationRoamingLabel->setText(QApplication::translate("BearerMonitor", "Roaming:", nullptr));
        configurationRoaming->setText(QString());
        configurationChildrenLabel->setText(QApplication::translate("BearerMonitor", "Children:", nullptr));
        configurationChildren->setText(QString());
        nlaGroup->setTitle(QApplication::translate("BearerMonitor", "Network Location Awareness", nullptr));
        registerButton->setText(QApplication::translate("BearerMonitor", "Register", nullptr));
        unregisterButton->setText(QApplication::translate("BearerMonitor", "Unregister", nullptr));
        newSessionButton->setText(QApplication::translate("BearerMonitor", "New Session", nullptr));
        deleteSessionButton->setText(QApplication::translate("BearerMonitor", "Delete Session", nullptr));
        scanButton->setText(QApplication::translate("BearerMonitor", "Scan", nullptr));
        progressBar->setFormat(QApplication::translate("BearerMonitor", "%p%", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("BearerMonitor", "1", nullptr));
        sessionGroup->setTitle(QApplication::translate("BearerMonitor", "Sessions", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BearerMonitor", "Session 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BearerMonitor: public Ui_BearerMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEARERMONITOR_240_320_H

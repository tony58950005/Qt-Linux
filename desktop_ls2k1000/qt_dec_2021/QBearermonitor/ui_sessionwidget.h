/********************************************************************************
** Form generated from reading UI file 'sessionwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESSIONWIDGET_H
#define UI_SESSIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SessionWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *sessionIdLayout;
    QLabel *sessionIdLabel;
    QLabel *sessionId;
    QHBoxLayout *sessionStateLayout;
    QLabel *sessionStateLabel;
    QLabel *sessionState;
    QHBoxLayout *configurationLayout;
    QLabel *configurationLabel;
    QLabel *configuration;
    QHBoxLayout *bearerLayout;
    QLabel *bearerLabel;
    QLabel *bearer;
    QHBoxLayout *interfaceNameLayout;
    QLabel *interfaceNameLabel;
    QLabel *interfaceName;
    QHBoxLayout *interfaceGuidLayout;
    QLabel *interfaceGuidLabel;
    QLabel *interfaceGuid;
    QHBoxLayout *lastErrorLayout;
    QLabel *lastErrorLabel;
    QLabel *lastError;
    QHBoxLayout *errorStringLayout;
    QLabel *errorStringLabel;
    QLabel *errorString;
    QHBoxLayout *horizontalLayout_3;
    QLabel *rxData;
    QLabel *txData;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *activeTime;
    QHBoxLayout *horizontalLayout;
    QPushButton *openSessionButton;
    QPushButton *openSyncSessionButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *closeSessionButton;
    QPushButton *stopSessionButton;

    void setupUi(QWidget *SessionWidget)
    {
        if (SessionWidget->objectName().isEmpty())
            SessionWidget->setObjectName(QStringLiteral("SessionWidget"));
        SessionWidget->resize(340, 276);
        verticalLayout_2 = new QVBoxLayout(SessionWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        sessionIdLayout = new QHBoxLayout();
        sessionIdLayout->setObjectName(QStringLiteral("sessionIdLayout"));
        sessionIdLabel = new QLabel(SessionWidget);
        sessionIdLabel->setObjectName(QStringLiteral("sessionIdLabel"));

        sessionIdLayout->addWidget(sessionIdLabel);

        sessionId = new QLabel(SessionWidget);
        sessionId->setObjectName(QStringLiteral("sessionId"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sessionId->sizePolicy().hasHeightForWidth());
        sessionId->setSizePolicy(sizePolicy);

        sessionIdLayout->addWidget(sessionId);


        verticalLayout->addLayout(sessionIdLayout);

        sessionStateLayout = new QHBoxLayout();
        sessionStateLayout->setObjectName(QStringLiteral("sessionStateLayout"));
        sessionStateLabel = new QLabel(SessionWidget);
        sessionStateLabel->setObjectName(QStringLiteral("sessionStateLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sessionStateLabel->sizePolicy().hasHeightForWidth());
        sessionStateLabel->setSizePolicy(sizePolicy1);

        sessionStateLayout->addWidget(sessionStateLabel);

        sessionState = new QLabel(SessionWidget);
        sessionState->setObjectName(QStringLiteral("sessionState"));
        sizePolicy.setHeightForWidth(sessionState->sizePolicy().hasHeightForWidth());
        sessionState->setSizePolicy(sizePolicy);

        sessionStateLayout->addWidget(sessionState);


        verticalLayout->addLayout(sessionStateLayout);

        configurationLayout = new QHBoxLayout();
        configurationLayout->setObjectName(QStringLiteral("configurationLayout"));
        configurationLabel = new QLabel(SessionWidget);
        configurationLabel->setObjectName(QStringLiteral("configurationLabel"));

        configurationLayout->addWidget(configurationLabel);

        configuration = new QLabel(SessionWidget);
        configuration->setObjectName(QStringLiteral("configuration"));
        sizePolicy.setHeightForWidth(configuration->sizePolicy().hasHeightForWidth());
        configuration->setSizePolicy(sizePolicy);

        configurationLayout->addWidget(configuration);


        verticalLayout->addLayout(configurationLayout);

        bearerLayout = new QHBoxLayout();
        bearerLayout->setObjectName(QStringLiteral("bearerLayout"));
        bearerLabel = new QLabel(SessionWidget);
        bearerLabel->setObjectName(QStringLiteral("bearerLabel"));

        bearerLayout->addWidget(bearerLabel);

        bearer = new QLabel(SessionWidget);
        bearer->setObjectName(QStringLiteral("bearer"));
        sizePolicy.setHeightForWidth(bearer->sizePolicy().hasHeightForWidth());
        bearer->setSizePolicy(sizePolicy);

        bearerLayout->addWidget(bearer);


        verticalLayout->addLayout(bearerLayout);

        interfaceNameLayout = new QHBoxLayout();
        interfaceNameLayout->setObjectName(QStringLiteral("interfaceNameLayout"));
        interfaceNameLabel = new QLabel(SessionWidget);
        interfaceNameLabel->setObjectName(QStringLiteral("interfaceNameLabel"));

        interfaceNameLayout->addWidget(interfaceNameLabel);

        interfaceName = new QLabel(SessionWidget);
        interfaceName->setObjectName(QStringLiteral("interfaceName"));
        sizePolicy.setHeightForWidth(interfaceName->sizePolicy().hasHeightForWidth());
        interfaceName->setSizePolicy(sizePolicy);

        interfaceNameLayout->addWidget(interfaceName);


        verticalLayout->addLayout(interfaceNameLayout);

        interfaceGuidLayout = new QHBoxLayout();
        interfaceGuidLayout->setObjectName(QStringLiteral("interfaceGuidLayout"));
        interfaceGuidLabel = new QLabel(SessionWidget);
        interfaceGuidLabel->setObjectName(QStringLiteral("interfaceGuidLabel"));

        interfaceGuidLayout->addWidget(interfaceGuidLabel);

        interfaceGuid = new QLabel(SessionWidget);
        interfaceGuid->setObjectName(QStringLiteral("interfaceGuid"));
        sizePolicy.setHeightForWidth(interfaceGuid->sizePolicy().hasHeightForWidth());
        interfaceGuid->setSizePolicy(sizePolicy);

        interfaceGuidLayout->addWidget(interfaceGuid);


        verticalLayout->addLayout(interfaceGuidLayout);

        lastErrorLayout = new QHBoxLayout();
        lastErrorLayout->setObjectName(QStringLiteral("lastErrorLayout"));
        lastErrorLabel = new QLabel(SessionWidget);
        lastErrorLabel->setObjectName(QStringLiteral("lastErrorLabel"));

        lastErrorLayout->addWidget(lastErrorLabel);

        lastError = new QLabel(SessionWidget);
        lastError->setObjectName(QStringLiteral("lastError"));
        sizePolicy.setHeightForWidth(lastError->sizePolicy().hasHeightForWidth());
        lastError->setSizePolicy(sizePolicy);

        lastErrorLayout->addWidget(lastError);


        verticalLayout->addLayout(lastErrorLayout);

        errorStringLayout = new QHBoxLayout();
        errorStringLayout->setObjectName(QStringLiteral("errorStringLayout"));
        errorStringLabel = new QLabel(SessionWidget);
        errorStringLabel->setObjectName(QStringLiteral("errorStringLabel"));

        errorStringLayout->addWidget(errorStringLabel);

        errorString = new QLabel(SessionWidget);
        errorString->setObjectName(QStringLiteral("errorString"));
        sizePolicy.setHeightForWidth(errorString->sizePolicy().hasHeightForWidth());
        errorString->setSizePolicy(sizePolicy);

        errorStringLayout->addWidget(errorString);


        verticalLayout->addLayout(errorStringLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        rxData = new QLabel(SessionWidget);
        rxData->setObjectName(QStringLiteral("rxData"));
        rxData->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(rxData);

        txData = new QLabel(SessionWidget);
        txData->setObjectName(QStringLiteral("txData"));
        txData->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(txData);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(SessionWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        activeTime = new QLabel(SessionWidget);
        activeTime->setObjectName(QStringLiteral("activeTime"));
        sizePolicy.setHeightForWidth(activeTime->sizePolicy().hasHeightForWidth());
        activeTime->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(activeTime);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        openSessionButton = new QPushButton(SessionWidget);
        openSessionButton->setObjectName(QStringLiteral("openSessionButton"));

        horizontalLayout->addWidget(openSessionButton);

        openSyncSessionButton = new QPushButton(SessionWidget);
        openSyncSessionButton->setObjectName(QStringLiteral("openSyncSessionButton"));

        horizontalLayout->addWidget(openSyncSessionButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        closeSessionButton = new QPushButton(SessionWidget);
        closeSessionButton->setObjectName(QStringLiteral("closeSessionButton"));

        horizontalLayout_2->addWidget(closeSessionButton);

        stopSessionButton = new QPushButton(SessionWidget);
        stopSessionButton->setObjectName(QStringLiteral("stopSessionButton"));

        horizontalLayout_2->addWidget(stopSessionButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SessionWidget);

        QMetaObject::connectSlotsByName(SessionWidget);
    } // setupUi

    void retranslateUi(QWidget *SessionWidget)
    {
        SessionWidget->setWindowTitle(QApplication::translate("SessionWidget", "Session Details", nullptr));
        sessionIdLabel->setText(QApplication::translate("SessionWidget", "Session ID:", nullptr));
        sessionId->setText(QString());
        sessionStateLabel->setText(QApplication::translate("SessionWidget", "Session State:", nullptr));
        sessionState->setText(QApplication::translate("SessionWidget", "Invalid", nullptr));
        configurationLabel->setText(QApplication::translate("SessionWidget", "Configuration:", nullptr));
        configuration->setText(QString());
        bearerLabel->setText(QApplication::translate("SessionWidget", "Bearer:", nullptr));
        bearer->setText(QString());
        interfaceNameLabel->setText(QApplication::translate("SessionWidget", "Interface Name:", nullptr));
        interfaceName->setText(QString());
        interfaceGuidLabel->setText(QApplication::translate("SessionWidget", "Interface GUID:", nullptr));
        interfaceGuid->setText(QString());
        lastErrorLabel->setText(QApplication::translate("SessionWidget", "Last Error:", nullptr));
        lastError->setText(QString());
        errorStringLabel->setText(QApplication::translate("SessionWidget", "Error String:", nullptr));
        errorString->setText(QString());
        rxData->setText(QApplication::translate("SessionWidget", "0", nullptr));
        txData->setText(QApplication::translate("SessionWidget", "0", nullptr));
        label_3->setText(QApplication::translate("SessionWidget", "Active Time:", nullptr));
        activeTime->setText(QApplication::translate("SessionWidget", "0 seconds", nullptr));
        openSessionButton->setText(QApplication::translate("SessionWidget", "Open", nullptr));
        openSyncSessionButton->setText(QApplication::translate("SessionWidget", "Blocking Open", nullptr));
        closeSessionButton->setText(QApplication::translate("SessionWidget", "Close", nullptr));
        stopSessionButton->setText(QApplication::translate("SessionWidget", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SessionWidget: public Ui_SessionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESSIONWIDGET_H

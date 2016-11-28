#include <QApplication>
#include <QComboBox>
#include <QFont>
#include <QPushButton>
#include "QStringListRefModel.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Quit");
    QComboBox cbo;
    QStringList cboList;
    QStringListRefModel cboListModel(&cboList);

    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    cbo.resize(75, 30);
    cbo.setModel(&cboListModel);
    cboList.append("Test 1");
    cboList.append("Test 2");
    cboList.append("Test 3");

    quit.show();
    cbo.show();

    return app.exec();
}

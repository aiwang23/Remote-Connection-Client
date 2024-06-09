#pragma execution_character_set("utf-8")

#include <QApplication>
#include "mymainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window::MyMainWindow window;
    window.show();
    // ftp_widget.show();
    return QApplication::exec();
}

#include "graph.h"
#include <windows.h>
#include <conio.h>
#include <process.h>
#include "Psapi.h"
#include <TlHelp32.h>
#include <tchar.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph w;
    w.show();
    return a.exec();
}

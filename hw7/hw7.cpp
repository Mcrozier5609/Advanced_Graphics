//  Michael Crozier
//  HW7: Image processing

#include <QApplication>
#include "hw7viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   hw7viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

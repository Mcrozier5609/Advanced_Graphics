//
//  Hw4:  OpenGL 3&4
//  Michael Crozier
//  CSCI 4239
//

#include <QApplication>
#include "hw4viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Hw4viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

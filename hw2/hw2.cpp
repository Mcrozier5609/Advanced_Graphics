//Michael Crozier
//HW2: Procedural texture
//CSCI 4239

#include <QApplication>
#include "hw2viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Ex03viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

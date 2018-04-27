//
//  HW1: ndc to rgb shader
//  Michael Crozier
//  CSCI 4239
//

#include <QApplication>
#include "hw1viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   hw1viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

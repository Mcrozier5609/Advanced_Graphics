//
//  Michael Crozier
//  HW3
//  CSCI 4239/5239
//

#include <QApplication>
#include "hw3viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Ex04viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

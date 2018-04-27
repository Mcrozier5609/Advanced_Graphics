//
//  HW9: Advanced Shaders
//  Michael Crozier
//  CSCI 4239
//

#include <QApplication>
#include "hw9viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   hw9viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

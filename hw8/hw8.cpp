//
//  hw8: Stored Textures
//  Michael Crozier
//  CSCI 4239/5239 Spring 2018
//

#include <QApplication>
#include "hw8viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   hw8viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}

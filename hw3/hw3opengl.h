//
//  OpenGL Ex04opengl Widget
//

#ifndef EX04OPENGL_H
#define EX04OPENGL_H

#include "CUgl.h"

class Ex04opengl : public CUgl
{
Q_OBJECT
private:
   float x0,y0; // Model center
   float z0;    // Zoom level
   int frame; //  Frame counter
   int t0;    //  Frame seconds
public:
   Ex04opengl(QWidget* parent=0);                   // Constructor
   QSize sizeHint() const {return QSize(400,400);}  // Default size of widget
protected:
    void initializeGL();  // Initialize widget
    void paintGL();       // Draw widget
signals:
    void fps(QString);    // Frames per second
};

#endif

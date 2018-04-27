//
//  OpenGL hw7opengl Widget
//

#ifndef hw7OPENGL_H
#define hw7OPENGL_H

#include "CUgl.h"

class hw7opengl : public CUgl
{
Q_OBJECT
private:
   int     N;         //  Nomber of passes
   float   x0,y0;     //  Object center
   float   z0;        //  Zoom
   QOpenGLFramebufferObject* framebuf[2]; //  Framebuffers
public:
   hw7opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
public slots:
    void setPasses(int pass);  //  Slot to set number of passes
protected:
    void initializeGL();       //  Initialize widget
    void resizeGL(int,int);    //  Resize widget
    void paintGL();            //  Draw widget
};

#endif

//
//  OpenGL hw8opengl Widget
//

#ifndef hw8OPENGL_H
#define hw8OPENGL_H

#include "CUgl.h"

class hw8opengl : public CUgl
{
Q_OBJECT
public:
   hw8opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
   QOpenGLTexture* map;
protected:
   void initializeGL(); //  Initialize widget
   void paintGL();      //  Draw widget
};

#endif

//
//  OpenGL hw9opengl Widget
//

#ifndef hw9OPENGL_H
#define hw9OPENGL_H

#include "CUgl.h"

class hw9opengl : public CUgl
{
Q_OBJECT
private:
   int     N;         //  Particle count
   float   zh;        //  Light position
   int     n;         //  Particle count
   float*  Vert;      //  Vertices
   float*  Color;     //  Colors
   float*  Vel;       //  Velocities
   float*  Start;     //  Start time
   QOpenGLTexture* tex; //  Texture
public:
   hw9opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
public slots:
   void setMode(int m);  //  Setmode
protected:
   void initializeGL();  //  Initialize widget
   void paintGL();       //  Draw widget
private:
  void InitPart();
  void DrawPart();
};

#endif

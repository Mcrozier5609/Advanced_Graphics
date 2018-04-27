//
//  OpenGL widget
//
#include "hw3opengl.h"
#include "Cube.h"
#include "WaveOBJ.h"
#include "Teapot.h"

//
//  Constructor
//
Ex04opengl::Ex04opengl(QWidget* parent)
    : CUgl(parent)
{
   t0 = frame = x0 = y0 = 0;
   z0 = 1;
}

//
//  Initialize
//
void Ex04opengl::initializeGL()
{
   //  Load shaders
   addShader("",":/hw3a.frag");
   addShader(":/hw3b.vert",":/hw3b.frag");
   addShader(":/hw3c.vert",":/hw3c.frag");
   addShader(":/hw3d.vert",":/hw3d.frag");
   addShader(":/hw3e.vert",":/hw3e.frag");
   addShader(":/hw2b.vert",":/hw2.frag");
   addShader(":/hw2b.vert",":/hw2_no_functions.frag");
   addShader(":/hw2b.vert",":/hw2_no_sin.frag");

   //  Load objects
   addObject(new Cube(":/crate.png"));
   addObject(new Teapot(8,":/pi.png",0.5));
   addObject(new WaveOBJ("cruiser.obj",":"));
   setObject(0);

   //  Set max frame rate
   maxFPS(1);
}

//
//  Draw the window
//
void Ex04opengl::paintGL()
{
   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   //  Apply projection
   doModelViewProjection();

   //  Apply lighting
   doLight();

   //  Apply shader
   if (mode) {
      shader[mode]->bind();
      //  Dimensions
      QVector3D loc(x0,y0,1/z0);
      shader[mode]->setUniformValue("loc",loc);
      //  Time
      float t = getTime();
      shader[mode]->setUniformValue("time",t);
   }

   //  Draw scene
   doScene();

   //  Release shader
   if (mode) shader[mode]->release();
   glDisable(GL_LIGHTING);
   glDisable(GL_DEPTH_TEST);

   //  Frame counter
   frame++;
   int t = time.elapsed()/1000;
   if (t>t0)
   {
      emit fps(QString::number(frame));
      t0 = t;
      frame = 0;
   }
}

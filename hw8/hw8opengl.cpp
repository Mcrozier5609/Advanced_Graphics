//
//  OpenGL widget
//
#include "hw8opengl.h"
#include "Cube.h"
#include "Teapot.h"
#include "WaveOBJ.h"
#include "Noise.h"

//
//  Constructor
//
hw8opengl::hw8opengl(QWidget* parent)
    : CUgl(parent)
{
}

//
//  Initialize
//
void hw8opengl::initializeGL()
{
   //  Load shaders
   addShader(":/hw8.vert",":/hw8a.frag");
   addShader(":/hw8.vert",":/hw8b.frag");
   addShader(":/hw8.vert",":/hw8c.frag");
   addShader(":/hw8.vert",":/hw8d.frag");
   addShader(":/hw8.vert",":/hw8new.frag");

   //  Objects
   addObject(new Cube());
   addObject(new Teapot(8));
   addObject(new WaveOBJ("bunny.obj",":/"));
   setObject(0);

   map     = loadImage(":/us-snow-cover-map-us-snow-cover-map-noaa-with-512.jpg");

   //  Set noise texture
   CreateNoise3D(GL_TEXTURE1);
}

//
//  Draw the window
//
void hw8opengl::paintGL()
{
   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   //  Apply projection
   doModelViewProjection();

   //  Apply lighting
   doLight();

   //  Apply shader
   if (mode)
   {
      glActiveTexture(GL_TEXTURE2);
      map->bind();
      glActiveTexture(GL_TEXTURE0);
      shader[mode]->bind();
      shader[mode]->setUniformValue("Noise3D",1);
      shader[mode]->setUniformValue("tex1",2);
   }

   //  Draw scene
   doScene();

   //  Release shader
   if (mode) shader[mode]->release();

   //  Disable lighting
   glDisable(GL_LIGHTING);
   glDisable(GL_DEPTH_TEST);
}

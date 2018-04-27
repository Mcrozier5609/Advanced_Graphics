//
//  OpenGL widget
//
#include "hw9opengl.h"
#include <QStringList>
#include "Noise.h"
#include <math.h>

//  Set up array indexes for program
const int VELOCITY_ARRAY=4;
const int START_ARRAY=5;
const char* Name = ",,,,Vel,Start";

/*
 *  Random numbers with range and offset
 */
static float frand(float rng,float off)
{
   return rand()*rng/RAND_MAX+off;
}

/*
 *  Initialize particles
 */
void hw9opengl::InitPart(void)
{
   //  Array Pointers
   float* vert  = Vert;
   float* color = Color;
   float* vel   = Vel;
   float* start = Start;
   //  Loop over NxN patch
   n = 15;
   for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
      {
         //  Location x,y,z
         *vert++ = 5*((i+0.5)/n-0.75);
         *vert++ = 5;
         *vert++ = 5*((j+0.5)/n-0.75);
         //  Color r,g,b (0.5-1.0)
         *color++ = frand(0.5,0.5);
         *color++ = frand(0.5,0.5);
         *color++ = frand(0.5,0.5);
         //  Velocity
         *vel++ = frand( 1.0,3.0);
         *vel++ = frand(10.0,0.0);
         *vel++ = frand( 1.0,3.0);
         //  Launch time
         *start++ = frand(2.0,6.0);
      }
}

/*
 *  Draw particles
 */
void hw9opengl::DrawPart(void)
{
   QOpenGLFunctions glf(QOpenGLContext::currentContext());
   //  Set particle size
   glPointSize(15);
   //  Point vertex location to local array Vert
   glVertexPointer(3,GL_FLOAT,0,Vert);
   //  Point color array to local array Color
   glColorPointer(3,GL_FLOAT,0,Color);
   //  Point attribute arrays to local arrays
   glf.glVertexAttribPointer(VELOCITY_ARRAY,3,GL_FLOAT,GL_FALSE,0,Vel);
   glf.glVertexAttribPointer(START_ARRAY,1,GL_FLOAT,GL_FALSE,0,Start);
   //  Enable arrays used by DrawArrays
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);
   glf.glEnableVertexAttribArray(VELOCITY_ARRAY);
   glf.glEnableVertexAttribArray(START_ARRAY);
   //  Set transparent large particles
   glEnable(GL_POINT_SPRITE);
   glTexEnvi(GL_POINT_SPRITE,GL_COORD_REPLACE,GL_TRUE);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE);
   glDepthMask(0);
   //  Draw arrays
   glDrawArrays(GL_POINTS,0,n*n);
   //  Reset
   glDisable(GL_POINT_SPRITE);
   glDisable(GL_BLEND);
   glDepthMask(1);
   //  Disable arrays
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_COLOR_ARRAY);
   glf.glDisableVertexAttribArray(VELOCITY_ARRAY);
   glf.glDisableVertexAttribArray(START_ARRAY);
}

//
//  Constructor
//
hw9opengl::hw9opengl(QWidget* parent)
    : CUgl(parent,false)
{
   N = 100;
   Vert  = new float[3*N*N];
   Color = new float[3*N*N];
   Vel   = new float[3*N*N];
   Start = new float[N*N];
   InitPart();
}

//
//  Initialize
//
void hw9opengl::setMode(int m)
{
   setShader(m);
   InitPart();
}

//
//  Initialize
//
void hw9opengl::initializeGL()
{
   //  Load shader
   addShader(":/hw9_snow.vert",":/hw9_snow.frag",Name);

   //  Load random texture
   CreateNoise3D(GL_TEXTURE1);

   //  Load smoke particle
   tex = loadImage(":/snow.png");
}

//
//  Draw the window
//
void hw9opengl::paintGL()
{
   //  Wall time (seconds)
   float t = 0.001*time.elapsed();
   zh = fmod(90*t,360);

   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   //  Bind texture
   tex->bind();

   //  Apply projection
   doModelViewProjection();

   //  Apply shader
   shader[0]->bind();
   shader[0]->setUniformValue("time",t);
   shader[0]->setUniformValue("img",0);
   shader[0]->setUniformValue("Noise3D",1);

   //  Draw scene
   DrawPart();

   //  Release shader
   shader[0]->release();

   //  Draw axes
   glBegin(GL_LINES);
   glVertex3d(0,0,0);
   glVertex3d(1,0,0);
   glVertex3d(0,0,0);
   glVertex3d(0,1,0);
   glVertex3d(0,0,0);
   glVertex3d(0,0,1);
   glEnd();
}

#ifndef hw9V_H
#define hw9V_H

#include "hw9opengl.h"

class hw9viewer : public QWidget
{
Q_OBJECT
private:
   hw9opengl*  ogl;
public:
    hw9viewer();
};

#endif

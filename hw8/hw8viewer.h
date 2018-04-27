#ifndef hw8V_H
#define hw8V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw8opengl.h"

class hw8viewer : public QWidget
{
Q_OBJECT
private:
   QSlider*     Lpos;
   QSlider*     Zpos;
   QPushButton* light;
   hw8opengl*  ogl;
private slots:
   void lmove();        //  Light movement
public:
    hw8viewer();
};

#endif

#ifndef hw7V_H
#define hw7V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw7opengl.h"

class hw7viewer : public QWidget
{
Q_OBJECT
private:
   QSlider*     Lpos;
   QSlider*     Zpos;
   QPushButton* light;
   hw7opengl*  ogl;
private slots:
   void lmove();        //  Light movement
public:
    hw7viewer();
};

#endif

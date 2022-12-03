#include "graphicpyramid.h"

GraphicPyramid::GraphicPyramid(QWidget *parent) : QOpenGLWidget(parent)
{
     background = QColor("lightgray");
     triColor = QColor("blue");
     angle = 0.0;
}

void GraphicPyramid::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());
}

void GraphicPyramid::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0f,10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
    //glOrtho(0.0f,w * 1.0f, 0.0f, h * 1.0f, -1000.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraphicPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

  //  glTranslatef(1.5,1.5,1.5);
   // glScalef(100,100,100);
    glScalef(5,5,5);
    glRotatef(angle,0.0,1.0,0.0);

     glLineWidth(1.5);
    glBegin(GL_TRIANGLES);




//green
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,0.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,0.0f,-1.0);

    //blue
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-1.0f,0.0f,-1.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(1.0f,0.0f,-1.0f);

    glColor3f(0.0f,0.5f,0.5f);
    glVertex3f(1.0f,0.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,0.0f,-1.0f);

//red
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(-1.0f,0.0f,1.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(1.0f,0.0f,1.0f);

    glEnd();

     glBegin(GL_QUADS);

     glColor3f(0.0f,0.0f,0.0f);
     glVertex3f(-1.0f,0.0f,1.0f);
     glVertex3f(-1.0f,0.0f,-1.0f);
     glVertex3f(1.0f,0.0f,-1.0f);
     glVertex3f(1.0f,0.0f,1.0f);




    glEnd();
    glPopMatrix();
    glFlush();
}

void GraphicPyramid::mousePressEvent(QMouseEvent *event)
{
    pressed = true;
    lastX = event->pos().x();

}

void GraphicPyramid::mouseReleaseEvent(QMouseEvent *event)
{

}

void GraphicPyramid::mouseMoveEvent(QMouseEvent *event)
{

    //int lastX = event->pos().x();
    if(pressed == true){
        if(event->pos().x() > lastX ){
            angle +=1;


            qDebug() <<  lastX;
        }else{
               angle -=1;
            qDebug() << lastX;
        }
        lastX = event->pos().x();

    }else {
        qDebug() << "not pressed";
    }
    update();
}

void GraphicPyramid::wheelEvent(QWheelEvent *event)
{

}


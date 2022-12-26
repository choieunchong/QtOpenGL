#include "widget.h"
#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Matrix");
    resize(600, 600);
}


Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();            // 함수 초기화
    glClearColor(0.0, 0.0, 0.0, 0.0);

}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

//    GLfloat angle = 45.0;
//    GLfloat value = angle * M_PI / 180;
//    GLfloat trans[16] = {
//        cos(value), -sin(value), 0, 0,
//        sin(value), cos(value), 0, 0,
//        0, 0, 1, 0,
//        0, 0, 0, 1

//    };

    GLfloat transScale[16] = {
        1,0, 0, 0,
        0.5, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    glMultMatrixf(transScale);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush();

}

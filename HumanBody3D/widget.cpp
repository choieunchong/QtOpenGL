#include "widget.h"
#include "Qtgluth.h"

#ifdef __APPLE__            // Mac OS X인 경우
#include <OpenGL/glu.h>
#else                       // Linux 등의 OS 인 경우
#include <GL/glu.h>
#endif

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = 0, yAngle = 0; zAngle = 0;
    setWindowTitle("OpenGL Human-Body");
    resize(300, 300);
}

Widget::~Widget()
{

}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();            // 함수 초기화
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-700.0, 700.0, -700.0, 700.0, -700.0, 700.0);
    glClearColor(0.5, 0.5, 0.5, 0.0);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotated(xAngle, 1.0f, 0.0f, 0.0f);
    glRotated(yAngle, 0.0f, 1.0f, 0.0f);
    glRotated(zAngle, 0.0f, 0.0f, 1.0f);

    // 카메라 셋팅(시점조정관련)
    gluLookAt(50, 50, 50, 0, 0, 0, 0, 1, 0);

    // 몸통
    glPushMatrix();
    glColor3f(0, 0, 1);
    glScalef(1, 1, 0.5);
    /* 몸의 1/2 만큼 상향이동 */
    glTranslatef(0, 128/2-10, 0);
    glutSolidCube(128);
    glPopMatrix();

    // 머리
    glPushMatrix();
    glColor3f(1, 0, 0);
    /* 몸사이즈 + 머리크기만큼 상향이동 */
    glTranslatef(0, 128+48/2+10, 0);
    glutSolidSphere(48, 18, 18);
    glPopMatrix();

    // 다리
    glPushMatrix();
    glColor3f(0, 1, 1);         // 좌측
    /* 몸 사이즈 및 다리 길이의 1/2만큼 하향이동 */
    glTranslatef(128/4, -128/2-60, 0);
    glScalef(1.5, 7, 1.5);
    glutSolidCube(32);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 1, 1);         // 우측
    /* 몸 사이즈 및 다리 길이의 1/2만큼 하향이동 */
    glTranslatef(-128/4, -128/2-60, 0);
    glScalef(1.5, 7, 1.5);
    glutSolidCube(32);
    glPopMatrix();

    // 팔
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef((128/2+20), 128/2-10, 0);
    glScalef(1, 4, 1);
    glutSolidCube(32);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(-(128/2+20), 128/2-10, 0);
    glScalef(1, 4, 1);
    glutSolidCube(32);
    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
    case Qt::Key_1:
    yAngle += 2;
    break;
    case Qt::Key_2:
    yAngle -= 2;
    break;
    case Qt::Key_3:
    xAngle += 2;
    break;
    case Qt::Key_4:
    xAngle -= 2;
    break;
    case Qt::Key_5:
    zAngle += 2;
    break;
    case Qt::Key_6:
    zAngle -= 2;
    break;
    case Qt::Key_0:
    xAngle = yAngle = zAngle = 0.0;
    break;
    };

    QString str = QString("x : %.1f, y : %.1f, z : %.1f").arg(xAngle).arg(yAngle).arg(zAngle);
    setWindowTitle(str);

    update();
}

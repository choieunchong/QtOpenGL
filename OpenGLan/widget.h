#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtOpenGL>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    bool alias;
    bool hint;

    GLfloat alpha;
    GLenum src;
    GLenum dest;

   // GLboolean bEdge;

//    GLfloat rectPosX;
//    GLfloat rectPosY;
//    GLfloat rectSize;


    //사각형의 이동 변위
//    GLfloat xStep;
//    GLfloat yStep;

//    GLfloat windowWidth;
//    GLfloat windowHeight;

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

protected:
    void keyPressEvent(QKeyEvent* event);

//public slots:
//    void timerFunction();

};
#endif // WIDGET_H

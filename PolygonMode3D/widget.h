#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

GLfloat xAngle, yAngle, zAngle;
GLenum polygonMode;
GLenum shadeMode;

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
void keyPressEvent(QKeyEvent* event);

};
#endif // WIDGET_H

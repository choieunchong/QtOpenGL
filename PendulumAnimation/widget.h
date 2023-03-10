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

    double radius;
    double delta_theta, cord_length;
    double xcenter, ycenter;
    double x, y, theta;
    double current_angle, atime;

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
public slots:
    void timerFuntion();
};
#endif // WIDGET_H

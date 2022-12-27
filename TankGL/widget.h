#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <GL/glut.h>

struct bullet{
float ypos;
float xpos;
float speed;
bullet *next;
};

struct enemy{
    float ypos;
    float xpos;
    float speed;
    bullet *next;
};



class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void keyPressEvent(QKeyEvent *event) override;

    void initializeGL( ) override;
    void paintGL( ) override;
    void resizeGL(int w, int h) override;
  //  void mousePressEvent(QMouseEvent*);
    int loadGLTextures();
 private slots:
    void updateTimer();



protected:
    GLuint filter;
    GLuint texture[4];
    GLuint base;

    bullet *headB;
    bullet *tailB;
    bullet *currentB;

    bool firstShot;
    bool enemyAround;
    float tankPosHoriz;
    float lastShot;
    float newShot;
    float lastMove, newMove;

    enemy normalEnemy;

    GLUquadricObj *quadratic;

    QTimer timer;

    void updateBullet();
    void updateEnemy();
    void loadGLtextures();
};
#endif // WIDGET_H

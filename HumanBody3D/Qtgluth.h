#ifndef QTGLUT_H
#define QTGLUT_H

#include <QObject>
#include <QtOpenGL>

void glutWireCube(GLdouble size);
void glutSolidCube(GLdouble size);

void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius,  GLint nsides, GLint rings);


void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);

class Qtglut
{
public:
    Qtglut();
};

#endif // QTGLUT_H

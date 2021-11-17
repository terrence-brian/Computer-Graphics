#include<GL/glut.h>
#include <math.h>

void init(void) {
    //Defining world coordinate frame
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // model in real word units
    // (left, right, bottom, top, near, far)
}

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(2.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //house outline
    glBegin(GL_LINE_LOOP);

    glVertex2d(6, 3);
    glVertex2d(-6, 3);

    glVertex2d(-6, 0);
    glVertex2d(-5, 0);

    glVertex2d(-5, -8);
    glVertex2d(5, -8);

    glVertex2d(5, 0);
    glVertex2d(6, 0);

    glEnd();

    //door
    glBegin(GL_LINE_LOOP);

    glVertex2d(-1, -8);
    glVertex2d(-1, -4);

    glVertex2d(-1, -4);
    glVertex2d(1, -4);

    glVertex2d(1, -4);
    glVertex2d(1, -8);

    glEnd();

    //windows
    //left
    glBegin(GL_LINE_LOOP);

    glVertex2d(-4, -4);
    glVertex2d(-4, -2);

    glVertex2d(-4, -2);
    glVertex2d(-2, -2);

    glVertex2d(-2, -2);
    glVertex2d(-2, -4);

    glVertex2d(-2, -4);
    glVertex2d(-4, -4);
    glEnd();

    //right
    glBegin(GL_LINE_LOOP);

    glVertex2d(2, -4);
    glVertex2d(2, -2);

    glVertex2d(2, -2);
    glVertex2d(4, -2);

    glVertex2d(4, -2);
    glVertex2d(4, -4);

    glVertex2d(4, -4);
    glVertex2d(2, -4);

    glEnd();

    //grills on window
    //left
    glBegin(GL_LINES);

    glVertex2d(-3, -2);
    glVertex2d(-3, -4);

    glVertex2d(-4, -3);
    glVertex2d(-2, -3);

    glEnd();

    //right
    glBegin(GL_LINES);

    glVertex2d(3, -2);
    glVertex2d(3, -4);

    glVertex2d(4, -3);
    glVertex2d(2, -3);

    glEnd();

    glFlush();

}
int main(int argc, char** argv)

{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 50);
    glutCreateWindow("2D house");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
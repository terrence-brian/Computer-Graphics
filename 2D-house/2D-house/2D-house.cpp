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


    //dome
    float radius = 4;
    float twoPI = 2 * 3.14;

    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex2f((cos(i) * radius), (sin(i) * radius) + 3);

    glEnd();

    //door knob
    int i;

    GLfloat x = .8f;
    int y = -6;
    GLfloat radiuss = .1f;

    int number = 100;

    GLfloat twicePI = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 1.0);

    glVertex2f(x, y);
    for (i = 0; i <= number; i++) {
        glVertex2f(
            x + (radiuss * cos(i * twicePI / number)),
            y + (radiuss * sin(i * twicePI / number))
        );
    }
    glEnd();

    //crecent
    int a = 7;
    int b = 7;
    int radiuse = 1.5;

    int numbere = 30;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.5, 0.0);

    glVertex2f(a, b);
    for (i = 0; i <= numbere; i++) {
        glVertex2f(
            a + (radiuse * cos(i * twicePI / numbere)),
            b + (radiuse * sin(i * twicePI / numbere))
        );
    }
    glEnd();

    float u = 7.5;
    float v = 7.0;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);

    glVertex2f(u, v);
    for (i = 0; i <= numbere; i++) {
        glVertex2f(
            u + (radiuse * cos(i * twicePI / numbere)),
            v + (radiuse * sin(i * twicePI / numbere))
        );
    }
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
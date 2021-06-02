#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

static int shoulder = 0, shoulderSR = 0, shoulderSL = 0, elbow = 0, rightHip = 0, rightKnee = 0;
static int leftHip = 0, leftKnee = 0, LArmL = 0, RArmL = 0, RLegL = 0, LLegL = 0, fingerBase2 = 0, fingerUp2 = 0, fingerBase3 = 0, fingerUp3 = 0, fingerBase4 = 0, fingerUp4 = 0;
int moving, startx, starty;

GLfloat angle = 0.0;  /* in degrees */
GLfloat angle2 = 0.0; /* in degrees */
//Setting Camera
double eye[] = { 0, 0, 6.5 };
double center[] = { 0.0, 0.0, 0.0 };
double up[] = { 0, 1, 0 };
double pi = 3.1428571;
double speed = 0.1;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(85.0, 1.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

    //Draw Body
    glPushMatrix(); //original push

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glTranslatef(1.0, 1.0, -2.0);

    glPushMatrix(); //1
    glScalef(1.0, 2.0, 0.5);
    glutWireCube(2.0);
    glPopMatrix(); //1

    // Draw Head
    glPushMatrix(); //2

    glTranslatef(-1.0, 3.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix(); //3
    glScalef(1.0, 1.0, 1.0);
    glutWireSphere(0.5, 10, 8);
    glPopMatrix(); //3

    glPopMatrix(); //2

    //Draw right Hip

    glPushMatrix();
    glTranslatef(0.5, -3.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)rightHip, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)RLegL, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -1.0, 0.0);

    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw right Knee
    glTranslatef(0.0, -2.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)rightKnee, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);

    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw right Foot
    glTranslatef(0.0, -1.2, 0.0);
    glTranslatef(0.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.5, 0.2, 1.2);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

    //Draw left Hip

    glPushMatrix();
    glTranslatef(-0.8, -3.0, 0.0);
    glTranslatef(0.15, 0.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)leftHip, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)LLegL, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -1.0, 0.0);

    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw left Knee
    glTranslatef(0.0, -2.0, 0.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)leftKnee, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 1.0, 0.5);
    glutWireCube(2);
    glPopMatrix();

    //Draw left Foot
    glTranslatef(0.0, -1.2, 0.0);
    glTranslatef(0.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.5, 0.2, 1.2);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

    //Draw right Shoulder

    glPushMatrix();
    glTranslatef(0.5, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.5, 1.0, 0.0);
    glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
    glTranslatef(1.5, -1.0, 0.0);

    glRotatef((GLfloat)shoulderSR, 0.0, 1.0, 0.0);

    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)RArmL, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();

    //Draw right Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.0, -2.0, 0.0);
    glTranslatef(1.5, 1.0, 0.0);
    glRotatef((GLfloat)elbow, 1, 0.0, 0);
    glTranslatef(-1.5, -1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();

    glPopMatrix();

    //Draw left Shoulder

    glPushMatrix();
    //why??
    glTranslatef(-2.5, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.5, 1.0, 0.0);
    glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
    glTranslatef(1.5, -1.0, 0.0);
    //just why ?

    glRotatef((GLfloat)shoulderSL, 0.0, 1.0, 0.0);

    glTranslatef(0.0, 1.0, 0.0);
    glRotatef((GLfloat)LArmL, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();

    //Draw left Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glTranslatef(-1.0, -2.0, 0.0);
    glTranslatef(1.5, 1.0, 0.0);
    glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
    glTranslatef(-1.5, -1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    glutWireCube(2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void defaultCamera()
{
    double e[] = { 0.0, 0.0, 6.5 };
    double c[] = { 0.0, 0.0, 0.0 };
    double u[] = { 0.0, 1.0, 0.0 };
    for (int i = 0; i < 3; i++)
    {
        eye[i] = e[i];
        center[i] = c[i];
        up[i] = u[i];
    }
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void normalize(double a[])
{
    double norm;
    norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    norm = sqrt(norm);
    a[0] /= norm;
    a[1] /= norm;
    a[2] /= norm;
}
void rotatePoint(double a[], double theta, double p[])
{

    double temp[3];
    temp[0] = p[0];
    temp[1] = p[1];
    temp[2] = p[2];

    temp[0] = -a[2] * p[1] + a[1] * p[2];
    temp[1] = a[2] * p[0] - a[0] * p[2];
    temp[2] = -a[1] * p[0] + a[0] * p[1];

    temp[0] *= sin(theta);
    temp[1] *= sin(theta);
    temp[2] *= sin(theta);

    temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
    temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
    temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

    temp[0] += cos(theta) * p[0];
    temp[1] += cos(theta) * p[1];
    temp[2] += cos(theta) * p[2];

    p[0] = temp[0];
    p[1] = temp[1];
    p[2] = temp[2];
}

void crossProduct(double a[], double b[], double c[])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

void turnLeft()
{
    rotatePoint(up, (-pi / 15), eye);
}

void turnRight()
{

    rotatePoint(up, (pi / 15), eye);
}

void moveDown()
{

    double rotationH[3];
    double direction[3];
    direction[0] = center[0] - eye[0];
    direction[1] = center[1] - eye[1];
    direction[2] = center[2] - eye[2];
    crossProduct(up, direction, rotationH);
    normalize(rotationH);

    rotatePoint(rotationH, (-pi / 15), eye);
    rotatePoint(rotationH, (-pi / 15), up);
}

void moveUp()
{

    double rotationH[3];
    double direction[3];

    direction[0] = center[0] - eye[0];
    direction[1] = center[1] - eye[1];
    direction[2] = center[2] - eye[2];

    crossProduct(up, direction, rotationH);
    normalize(rotationH);

    rotatePoint(rotationH, (pi / 15), eye);
    rotatePoint(rotationH, (pi / 15), up);
}

// Forward and Backward
void zoomIn()
{
    double direction[3];
    direction[0] = center[0] - eye[0];
    direction[1] = center[1] - eye[1];
    direction[2] = center[2] - eye[2];

    eye[0] += direction[0] * speed;
    eye[1] += direction[1] * speed;
    eye[2] += direction[2] * speed;

    center[0] += direction[0] * speed;
    center[1] += direction[1] * speed;
    center[2] += direction[2] * speed;
}

void zoomOut()
{

    double direction[3];
    direction[0] = center[0] - eye[0];
    direction[1] = center[1] - eye[1];
    direction[2] = center[2] - eye[2];

    eye[0] -= direction[0] * speed;
    eye[1] -= direction[1] * speed;
    eye[2] -= direction[2] * speed;

    center[0] -= direction[0] * speed;
    center[1] -= direction[1] * speed;
    center[2] -= direction[2] * speed;
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        turnLeft();
        break;

    case GLUT_KEY_RIGHT:
        turnRight();
        break;

    case GLUT_KEY_UP:
        moveUp();
        break;
    case GLUT_KEY_DOWN:
        moveDown();
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 's':
        if (shoulder == -175)
            break;
        shoulder = (shoulder - 5);
        glutPostRedisplay();
        break;
    case 'S':
        if (shoulder == 50)
            break;
        else
            shoulder = (shoulder + 5);
        glutPostRedisplay();
        break;

    case 'x':
        if (shoulderSR == 0)
            break;
        shoulderSR = (shoulderSR - 5);
        glutPostRedisplay();
        break;
    case 'X':
        if (shoulderSR == 90)
            break;
        else
            shoulderSR = (shoulderSR + 5);
        glutPostRedisplay();
        break;

    case 'C':
        if (shoulderSL == -90)
            break;
        shoulderSL = (shoulderSL - 5);
        glutPostRedisplay();
        break;
    case 'c':
        if (shoulderSL == 0)
            break;
        else
            shoulderSL = (shoulderSL + 5);
        glutPostRedisplay();
        break;

    case 'E':
        if (elbow == -145)
            break;
        else
            elbow = (elbow - 5);
        glutPostRedisplay();
        break;
    case 'e':
        if (elbow == 0)
            break;
        else
            elbow = (elbow + 5);
        glutPostRedisplay();
        break;

    case '3':
        if (rightHip == -65)
            break;
        else
            rightHip = (rightHip - 5);
        glutPostRedisplay();
        break;
    case '#':
        if (rightHip == 65)
            break;
        else
            rightHip = (rightHip + 5);
        glutPostRedisplay();
        break;

    case '4':
        if (rightKnee == 0)
            break;
        else
            rightKnee = (rightKnee - 5);
        glutPostRedisplay();
        break;
    case '$':
        if (rightKnee == 135)
            break;
        else
            rightKnee = (rightKnee + 5);
        glutPostRedisplay();
        break;

    case '1':
        if (leftHip == -65)
            break;
        else
            leftHip = (leftHip - 5);
        glutPostRedisplay();
        break;
    case '!':
        if (leftHip == 65)
            break;
        else
            leftHip = (leftHip + 5);
        glutPostRedisplay();
        break;

    case '2':
        if (leftKnee == 0)
            break;
        else
            leftKnee = (leftKnee - 5);
        glutPostRedisplay();
        break;
    case '@':
        if (leftKnee == 135)
            break;
        else
            leftKnee = (leftKnee + 5);
        glutPostRedisplay();
        break;

    case 'd':
        if (RLegL == 0)
            break;
        else
            RLegL = (RLegL - 5);
        glutPostRedisplay();
        break;
    case 'D':
        if (RLegL == 75)
            break;
        else
            RLegL = (RLegL + 5);
        glutPostRedisplay();
        break;

    case 'A':
        if (LLegL == -75)
            break;
        else
            LLegL = (LLegL - 5);
        glutPostRedisplay();
        break;
    case 'a':
        if (LLegL == 0)
            break;
        else
            LLegL = (LLegL + 5);
        glutPostRedisplay();
        break;

    case 'r':
        if (RArmL == 0)
            break;
        else
            RArmL = (RArmL - 5);
        glutPostRedisplay();
        break;
    case 'R':
        if (RArmL == 90)
            break;
        else
            RArmL = (RArmL + 5);
        glutPostRedisplay();
        break;

    case 'L':
        if (LArmL == -90)
            break;
        else
            LArmL = (LArmL - 5);
        glutPostRedisplay();
        break;
    case 'l':
        if (LArmL == 0)
            break;
        else
            LArmL = (LArmL + 5);
        glutPostRedisplay();
        break;

    case 'i': // Zoom in
        zoomIn();
        glutPostRedisplay();
        break;

    case 'o': // Zoom out
        zoomOut();
        glutPostRedisplay();
        break;

    case '0': // Reset camera angle
        defaultCamera();
        glutPostRedisplay();
        break;

    case 29:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP)
        {
            moving = 0;
        }
    }
}

static void motion(int x, int y)
{
    if (moving)
    {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
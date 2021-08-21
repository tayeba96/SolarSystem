#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "imageloader.h"

using namespace std;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	}
}

// Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            // level-of-detail number
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
						  //as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


GLuint textureSun, textureMercury, textureVenus, textureEarth, textureMoon, textureMars, textureJupiter;; //The id of the textur
GLUquadric *sun, *mercury, *venus, *earth, *moon, *mars, *jupiter;
float r = 0.0, me = 0.0, v = 0.0, e = 0.0, ma = 0.0, ju = 0.0;

void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	sun = gluNewQuadric();
	mercury = gluNewQuadric();
	venus = gluNewQuadric();
	earth = gluNewQuadric();
	moon = gluNewQuadric();
	mars = gluNewQuadric();
	jupiter = gluNewQuadric();

	Image* imageSun = loadBMP("sun.bmp");
	textureSun = loadTexture(imageSun);
	delete imageSun;

	Image* imageMercury = loadBMP("mercury.bmp");
	textureMercury = loadTexture(imageMercury);
	delete imageMercury;

	Image* imageVenus = loadBMP("venus.bmp");
	textureVenus = loadTexture(imageVenus);
	delete imageVenus;

	Image* imageEarth = loadBMP("earth.bmp");
	textureEarth = loadTexture(imageEarth);
	delete imageEarth;

	Image* imageMoon = loadBMP("moon.bmp");
	textureMoon = loadTexture(imageMoon);
	delete imageMoon;

	Image* imageMars = loadBMP("mars.bmp");
	textureMars = loadTexture(imageMars);
	delete imageMars;

	Image* imageJupiter = loadBMP("jupiter.bmp");
	textureJupiter = loadTexture(imageJupiter);
	delete imageJupiter;

}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void color()
{
	// Set lighting intensity and color
	GLfloat ambientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	// Set the light position
	GLfloat lightPosition[] = { 0.1, 0.1, 10.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	GLfloat high_shininess[] = { 128.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseLight);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

}
void Sun()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	color();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureSun);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(sun, 1);
	gluSphere(sun, 2, 20, 20);
	glPopMatrix();
}

void Mercury()
{
	glPushMatrix();

	glRotatef(me, 0, 1, 0);

	glTranslatef(2.8f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMercury);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(mercury, 1);
	gluSphere(mercury, .5, 20, 20);
	glPopMatrix();
}

void Venus()
{
	glPushMatrix();

	glRotatef(v, 0, 1, 0);

	glTranslatef(4.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureVenus);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(venus, 1);
	gluSphere(venus, .9, 20, 20);
	glPopMatrix();
}

void Moon()
{
	//glPushMatrix();
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.5f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMoon);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(moon, 1);
	gluSphere(moon, .2, 20, 20);
	//glPopMatrix();
}

void Earth()
{
	glPushMatrix();

	glRotatef(e, 0, 1, 0);

	glTranslatef(7.5f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureEarth);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(earth, 1);
	gluSphere(earth, .7, 20, 20);
	Moon();
	glPopMatrix();
}

void Mars()
{
	glPushMatrix();

	glRotatef(ma, 0, 1, 0);

	glTranslatef(11.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMars);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(mars, 1);
	gluSphere(mars, .63, 20, 20);
	glPopMatrix();
}

void Jupiter()
{
	glPushMatrix();

	glRotatef(ju, 0, 1, 0);

	glTranslatef(14.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureJupiter);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	gluQuadricTexture(jupiter, 1);
	gluSphere(jupiter, 1, 20, 20);
	glPopMatrix();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -30.0f);

	Sun();
	Mercury();
	Venus();
	Earth();
	Mars();
	Jupiter();

	glutSwapBuffers();
}
void update(int value)
{
	r += 2.0f;
	if (r>360.f)
		r -= 360;

	e = e + .3;
	if (e>360)e = 0;
	me = me + .43;
	if (me>360)me = 0;
	ma = ma + .55;
	if (ma>360)ma = 0;
	v = v + .1;
	if (v>360)v = 0;
	ju = ju + 0.73;
	if (ju>360)ju = 0;

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);

	glutCreateWindow("Textures");
	init();

	glutTimerFunc(25, update, 0);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(resize);

	glutMainLoop();
	return 0;
}

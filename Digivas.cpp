#include "iGraphics.h"

int x = 0, y = 0, p = 3, ptsno, eraser = 3, tool = 0, circleradius = 30, cirno, recno, recdx = 80, recdy = 60, ellno, ellda = 40, elldb = 20, lineno, textno, mode = 0;
int r = 0, g = 0, b = 0;

//function iDraw() is called again and again by the system.

typedef struct
{ // brush
	int x;
	int y;
	int p;
	int r;
	int g;
	int b;
} Point;

Point *pts = (Point *)malloc(999999 * sizeof(Point));

typedef struct
{ // circle
	int x;
	int y;
	int r;
	int g;
	int b;
	int size;
} Circle;

Circle *circleArr = (Circle *)malloc(100 * sizeof(Circle));
int *circlesAt = (int *)malloc(100 * sizeof(int));

typedef struct
{ // rectangle
	int x;
	int y;
	int r;
	int g;
	int b;
	int dx;
	int dy;
} Rect;

Rect *recArr = (Rect *)malloc(100 * sizeof(Rect));
int *recsAt = (int *)malloc(100 * sizeof(int));

typedef struct
{ // ellipse
	int x;
	int y;
	int r;
	int g;
	int b;
	int da;
	int db;
} Ellip;

Ellip *ellArr = (Ellip *)malloc(100 * sizeof(Ellip));
int *ellsAt = (int *)malloc(100 * sizeof(int));

typedef struct
{ // line
	int x1;
	int y1;
	int x2;
	int y2;
	int r;
	int g;
	int b;
} Line;

Line *lineArr = (Line *)malloc(100 * sizeof(Line));
int *linesAt = (int *)malloc(100 * sizeof(int));

typedef struct
{ // text
	int x;
	int y;
	int r;
	int g;
	int b;
	char text[100];
} Text;

Text *textArr = (Text *)malloc(100 * sizeof(Text));
int *textsAt = (int *)malloc(100 * sizeof(int));

void display()
{
	int i, c, e, rc, l, t;
	for (i = 0, c = 0, rc = 0, e = 0, l = 0; i < ptsno; i++)
	{
		if (circlesAt[c] == i)
		{
			iSetColor(circleArr[c].r, circleArr[c].g, circleArr[c].b);
			iCircle(circleArr[c].x, circleArr[c].y, circleArr[c].size);
			c++;
		}
		if (recsAt[rc] == i)
		{
			iSetColor(recArr[rc].r, recArr[rc].g, recArr[rc].b);
			iRectangle(recArr[rc].x, recArr[rc].y, recArr[rc].dx, recArr[rc].dy);
			rc++;
		}
		if (ellsAt[e] == i)
		{
			iSetColor(ellArr[e].r, ellArr[e].g, ellArr[e].b);
			iEllipse(ellArr[e].x, ellArr[e].y, ellArr[e].da, ellArr[e].db);
			e++;
		}
		if (linesAt[l] == i)
		{
			iSetColor(lineArr[l].r, lineArr[l].g, lineArr[l].b);
			iLine(lineArr[l].x1, lineArr[l].y1, lineArr[l].x2, lineArr[l].y2);
			l++;
		}
		if (textsAt[t] == i)
		{
			iSetColor(textArr[t].r, textArr[t].g, textArr[t].b);
			iText(textArr[t].x, textArr[t].y, textArr[t].text);
			t++;
		}
		iSetColor(pts[i].r, pts[i].g, pts[i].b);
		iPoint(pts[i].x, pts[i].y, pts[i].p);
	}
}

void iDraw()
{
	// place your drawing codes here
	iClear();
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 1900, 1000);
	display();
	iSetColor(0, 0, 0); // Black
	iFilledCircle(1610, 60, 10);
	iSetColor(255, 0, 0); // Red
	iFilledCircle(1660, 60, 10);
	iSetColor(255, 200, 0); // Yellow
	iFilledCircle(1710, 60, 10);
	iSetColor(0, 255, 0); // Green
	iFilledCircle(1760, 60, 10);
	iSetColor(255, 100, 200); // Pink
	iFilledCircle(1810, 60, 10);
	iSetColor(0, 0, 255); // Blue
	iFilledCircle(1860, 60, 10);
	iSetColor(0, 0, 0); // Current Brush Color
	iText(1620, 25, "Current Brush Color : ");
	iSetColor(r, g, b);
	iFilledCircle(1800, 30, 10);
	iSetColor(150, 150, 150); // Erase
	iFilledEllipse(1540, 60, 30, 13);
	iSetColor(255, 255, 255);
	iText(1517, 55, "Eraser");
	iSetColor(0, 0, 0); // Size Increase
	iFilledCircle(1475, 60, 10);
	iSetColor(255, 255, 255);
	iText(1473, 55, ">");
	iSetColor(0, 0, 0); // Size Decrease
	iFilledCircle(1425, 60, 10);
	iSetColor(255, 255, 255);
	iText(1420, 55, "<");
	iSetColor(0, 0, 0); // Pen Tool
	iFilledEllipse(1450, 40, 30, 10);
	iSetColor(255, 255, 255);
	iText(1430, 35, "Brush");
	iSetColor(0, 0, 0); // Circle
	iFilledCircle(1375, 60, 30, 10);
	iSetColor(255, 255, 255);
	iText(1350, 55, "Circle");
	iSetColor(0, 0, 0); // Rectangle
	iFilledRectangle(1250, 50, 90, 20);
	iSetColor(255, 255, 255);
	iText(1260, 55, "Rectangle");
	iSetColor(0, 0, 0); // Ellipse
	iFilledEllipse(1200, 60, 40, 10);
	iSetColor(255, 255, 255);
	iText(1175, 55, "Ellipse");
	iSetColor(0, 0, 0); // Line
	iFilledRectangle(1100, 50, 50, 20);
	iSetColor(255, 255, 255);
	iText(1110, 55, "Line");
	iSetColor(0, 0, 0); // Text
	iFilledRectangle(1040, 50, 50, 20);
	iSetColor(255, 255, 255);
	iText(1050, 55, "Text");
	iSetColor(0, 0, 0); // Go back to menu
	iFilledRectangle(980, 50, 50, 20);
	iSetColor(255, 255, 255);
	iText(990, 55, "Menu");
	if (mode == 0)
	{
		iSetColor(0, 0, 0);
		iFilledRectangle(0, 0, 1900, 1000);
		iSetColor(255, 255, 255);
		iFilledRectangle(890, 495, 105, 20);
		iSetColor(0, 0, 0);
		iText(900, 500, "New Drawing");
		iSetColor(255, 255, 255);
		iFilledRectangle(890, 465, 105, 20);
		iSetColor(0, 0, 0);
		iText(895, 470, "Instructions");
		iSetColor(255, 255, 255);
		iFilledRectangle(890, 435, 105, 20);
		iSetColor(0, 0, 0);
		iText(915, 440, "Credits");
		iSetColor(255, 255, 255);
		iFilledRectangle(890, 405, 105, 20);
		iSetColor(0, 0, 0);
		iText(930, 410, "Exit");
		iSetColor(255, 255, 255);
		iText(870, 530, "Welcome to DIGIVAS");
	}
	if (mode == 2)
	{
		iSetColor(0, 0, 0);
		iFilledRectangle(0, 0, 1900, 1000);
		iSetColor(255, 255, 255);
		iText(50, 950, "Instructions");
		iText(50, 930, "1. To draw, select the brush tool and click and drag the mouse");
		iText(50, 910, "2. To draw a circle, select the circle tool and click where you want the center of the circle");
		iText(50, 890, "3. To draw a rectangle, select the rectangle tool and click where you want the top left corner of the rectangle");
		iText(50, 870, "4. To draw an ellipse, select the ellipse tool and click where you want the center of the ellipse");
		iText(50, 850, "5. To draw a line, select the line tool and left click where you want the starting point of the line and right click where you want the ending point of the line");
		iText(50, 830, "6. To write text, select the text tool and click where you want to write");
		iText(50, 810, "7. To change the color of the brush, click on the color you want to change to");
		iText(50, 790, "8. To increase the size of the brush, radius of circle, major and minor axis of ellipse, height and base of rectangle, click on the + sign when respective tools are selected");
		iText(50, 770, "9. To decrease the size of the brush, radius of circle, major and minor axis of ellipse, height and base of rectangle, click on the - sign when respective tools are selected");
		iText(50, 750, "10. To erase, click on the eraser");
		iText(50, 730, "11. To start a new drawing, click on New Drawing");
		iText(50, 710, "12. To see the credits, click on Credits");
		iText(50, 690, "13. To exit, click on Exit");
		iSetColor(255, 255, 255);
		iFilledRectangle(980, 50, 50, 20);
		iSetColor(0, 0, 0);
		iText(990, 55, "Menu");
	}
	if (mode == 3)
	{
		iSetColor(0, 0, 0);
		iFilledRectangle(0, 0, 1900, 1000);
		iSetColor(255, 255, 255);
		iText(50, 950, "Credits");
		iText(50, 930, "This project is made by Adib Bin Iqbal");
		iText(50, 910, "This project is made using C language and iGraphics (A Wrapper For OpenGL in 2D)");
		iText(50, 890, "This project is made for the course CSE 102");
		iText(50, 870, "iGraphics is made by S. M. Shahriar Nirjon Sir");
		iText(50, 850, "Special thanks to Rifat Rahman Sir for his guidance and support");
		iText(50, 830, "Special thanks to BUET CSE department for providing the platform to learn and make this project");
		iSetColor(255, 255, 255);
		iFilledRectangle(980, 50, 50, 20);
		iSetColor(0, 0, 0);
		iText(990, 55, "Menu");
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	if (ptsno < 999999 && tool == 1)
	{
		pts[ptsno].x = mx;
		pts[ptsno].y = my;
		pts[ptsno].p = p;
		pts[ptsno].r = r;
		pts[ptsno].g = g;
		pts[ptsno].b = b;
		ptsno++;
	}
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		x = mx;
		y = my;
		printf("x = %d, y= %d\n", mx, my);
		if (mx >= 1600 && mx <= 1620 && my >= 50 && my <= 70)
		{
			r = 0;
			g = 0;
			b = 0;
			p = eraser;
		}
		if (mx >= 1650 && mx <= 1670 && my >= 50 && my <= 70)
		{
			r = 255;
			g = 0;
			b = 0;
			p = eraser;
		}
		if (mx >= 1700 && mx <= 1720 && my >= 50 && my <= 70)
		{
			r = 255;
			g = 200;
			b = 0;
			p = eraser;
		}
		if (mx >= 1750 && mx <= 1770 && my >= 50 && my <= 70)
		{
			r = 0;
			g = 255;
			b = 0;
			p = eraser;
		}
		if (mx >= 1800 && mx <= 1820 && my >= 50 && my <= 70)
		{
			r = 255;
			g = 100;
			b = 200;
			p = eraser;
		}
		if (mx >= 1850 && mx <= 1870 && my >= 50 && my <= 70)
		{
			r = 0;
			g = 0;
			b = 255;
			p = eraser;
		}
		if (mx >= 1515 && mx <= 1565 && my >= 50 && my <= 70)
		{
			r = 255;
			g = 255;
			b = 255;
			eraser = p;
			p = 15;
			tool = 1;
		}
		if (mx >= 1465 && mx <= 1485 && my >= 50 && my <= 70)
		{
			if (p < 10 && tool == 1)
			{
				p++;
			}
			if (circleradius < 100 && tool == 2)
			{
				circleradius += 5;
			}
			if (recdx < 210 && recdy < 200 && tool == 3)
			{
				recdx += 10;
				recdy += 10;
			}
			if (ellda < 210 && elldb < 200 && tool == 4)
			{
				ellda += 10;
				elldb += 8;
			}
		}
		if (mx >= 1415 && mx <= 1435 && my >= 50 && my <= 70)
		{
			if (p > 1 && tool == 1)
			{
				p--;
			}
			if (circleradius > 10 && tool == 2)
			{
				circleradius -= 5;
			}
			if (recdx > 10 && recdy > 10 && tool == 3)
			{
				recdx -= 10;
				recdy -= 5;
			}
			if (ellda > 10 && elldb > 10 && tool == 4)
			{
				ellda -= 10;
				elldb -= 8;
			}
		}
		if (mx >= 1420 && mx <= 1480 && my >= 30 && my <= 50)
		{
			tool = 1;
			p = eraser;
			r = 0;
			g = 0;
			b = 0;
		}
		if (mx >= 1350 && mx <= 1390 && my >= 30 && my <= 90)
		{
			tool = 2;
			r = 0;
			g = 0;
			b = 0;
		}
		if (mx >= 1250 && mx <= 1340 && my >= 40 && my <= 70)
		{
			tool = 3;
			r = 0;
			g = 0;
			b = 0;
		}
		if (mx >= 1160 && mx <= 1240 && my >= 50 && my <= 70)
		{
			tool = 4;
			r = 0;
			g = 0;
			b = 0;
		}
		if (mx >= 1100 && mx <= 1150 && my >= 50 && my <= 70)
		{
			tool = 5;
			r = 0;
			g = 0;
			b = 0;
		}
		if (mx >= 1040 && mx <= 1090 && my >= 50 && my <= 70)
		{
			tool = 6;
			r = 0;
			g = 0;
			b = 0;
		}
		if (tool == 2 && !(mx >= 1040 && mx <= 1900 && my >= 30 && my <= 90))
		{
			circlesAt[cirno] = ptsno++;
			circleArr[cirno].x = mx;
			circleArr[cirno].y = my;
			circleArr[cirno].r = r;
			circleArr[cirno].g = g;
			circleArr[cirno].b = b;
			circleArr[cirno].size = circleradius;
			cirno++;
		}
		if (tool == 3 && !(mx >= 1040 && mx <= 1900 && my >= 30 && my <= 90))
		{
			recsAt[recno] = ptsno++;
			recArr[recno].x = mx;
			recArr[recno].y = my;
			recArr[recno].r = r;
			recArr[recno].g = g;
			recArr[recno].b = b;
			recArr[recno].dx = recdx;
			recArr[recno].dy = recdy;
			recno++;
		}
		if (tool == 4 && !(mx >= 1040 && mx <= 1900 && my >= 30 && my <= 90))
		{
			ellsAt[ellno] = ptsno++;
			ellArr[ellno].x = mx;
			ellArr[ellno].y = my;
			ellArr[ellno].r = r;
			ellArr[ellno].g = g;
			ellArr[ellno].b = b;
			ellArr[ellno].da = ellda;
			ellArr[ellno].db = elldb;
			ellno++;
		}
		if (tool == 5 && !(mx >= 1040 && mx <= 1900 && my >= 30 && my <= 90))
		{
			linesAt[lineno] = ptsno;
			lineArr[lineno].x1 = mx;
			lineArr[lineno].y1 = my;
			lineArr[lineno].r = r;
			lineArr[lineno].g = g;
			lineArr[lineno].b = b;
		}
		if (tool == 6 && !(mx >= 1040 && mx <= 1900 && my >= 30 && my <= 90))
		{
			textsAt[textno] = ptsno++;
			textArr[textno].x = mx;
			textArr[textno].y = my;
			textArr[textno].r = r;
			textArr[textno].g = g;
			textArr[textno].b = b;
		}
		if (mode == 0 && mx >= 890 && mx <= 995 && my >= 495 && my <= 515)
		{
			mode = 1;
		}
		if (mode == 0 && mx >= 890 && mx <= 995 && my >= 465 && my <= 485)
		{
			mode = 2;
		}
		if (mode == 0 && mx >= 890 && mx <= 995 && my >= 435 && my <= 455)
		{
			mode = 3;
		}
		if (mode == 0 && mx >= 890 && mx <= 995 && my >= 405 && my <= 425)
		{
			exit(0);
		}
		if (mx >= 980 && mx <= 1030 && my >= 50 && my <= 70)
		{
			mode = 0;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (tool == 5)
		{
			lineArr[lineno].x2 = mx;
			lineArr[lineno].y2 = my;
			ptsno++;
			lineno++;
		}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (tool == 6)
	{
		if (key == '\r')
		{
			textArr[textno].text[strlen(textArr[textno].text) + 1] = '\0';
			textno++;
		}
		else
		{
			textArr[textno].text[strlen(textArr[textno].text)] = key;
			textArr[textno].text[strlen(textArr[textno].text) + 1] = '\0';
		}
	}
	if (mode == 0)
	{
		if (key == 'n')
		{
			mode = 1;
		}
		if (key == 'i')
		{
			mode = 2;
		}
		if (key == 'c')
		{
			mode = 3;
		}
		if (key == 'q')
		{
			exit(0);
		}
	}
	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	iInitialize(1900, 1000, "DigiVas");
	return 0;
}

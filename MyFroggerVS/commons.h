#pragma once

#include <iostream>
#include <gl/freeglut.h>

#define DEBUG 1

#if DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x) 
#endif

struct Color
{
	GLfloat red;
	GLfloat green;
	GLfloat blue;
};

//  sunken -> submerso -> totalmente embaixo dágua
//  emerging -> emergindo -> voltando a superfície
//  emerged -> emerso -> totalmente fora dágua
//  submerging -> submergindo -> afundando
enum SinkableStates { sunken, emerging, emerged, submerging };

struct Position
{
	int x;
	int y;
};


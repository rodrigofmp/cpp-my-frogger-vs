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

//  sunken -> submerso -> totalmente embaixo d�gua
//  emerging -> emergindo -> voltando a superf�cie
//  emerged -> emerso -> totalmente fora d�gua
//  submerging -> submergindo -> afundando
enum SinkableStates { sunken, emerging, emerged, submerging };

struct Position
{
	int x;
	int y;
};


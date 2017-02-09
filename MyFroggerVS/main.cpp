//-------------------------------------------------------------------------
//  MyFrogger
//
// Escrito por Rodrigo Petters Novembro 2016
//
// Projeto para p�s Jogos Digitais da FMU.
//
// Objetivo: produzir uma c�pia de um jogo cl�ssico da Atari.
//-------------------------------------------------------------------------

#include <gl/freeglut.h>
#include "board.h"
#include "boardgl.h"
#include "commons.h"
#include "frog.h"
#include "froggl.h"
#include "automobile.h"
#include "objectgl.h"
#include "gear.h"
#include "rules.h"

//  defini��o dos m�todos
void init();
void display(void);
void centerOnScreen();

void startGame();
void validateGameState();
void freeMemoryGame();

void drawObjects();
void spinObjects();

void specialKeys(int key, int x, int y);
void timerFunc(int n);

//  define a posi��o da janela na tela
int window_x;
int window_y;

//  vari�veis que representam o tamanho da janela
int window_width = 800;
int window_height = 600;

//  vari�vel que representa o t�tulo da janela
char *window_title = "MyFroggerVS";

//  vari�veis globais de OpenGL
GLfloat scale = 1;
GLdouble planLeft = 1; // -65;
GLdouble planRight = 100; // 65;
GLdouble planBottom = 1; // 50;
GLdouble planUp = 100; // -50;

//  vari�veis globais do jogo
Board *board;
Frog *frog;
Automobile *auto1;
Automobile *auto2;
Automobile *auto3;

//-------------------------------------------------------------------------
//  M�todo do programa principal
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Cria janela principal do programa
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Configura��es iniciais de OpenGL
	init();

	//  Inicializa o jogo com o estado inicial
	startGame();

	//  Define fun��es de callback
	glutDisplayFunc(display);

	//  Trata teclas de movimento
	glutSpecialFunc(specialKeys);

	//  Registra o timer principal que dar� vida aos objetos da tela
	timerFunc(1000);

	//  Libera mem�ria alocada para o jogo
	atexit(freeMemoryGame);

	//  Inicia o loop de processamento do GLUT
	glutMainLoop();
}

//-------------------------------------------------------------------------
//  Configura��es iniciais de OpenGL
//-------------------------------------------------------------------------
void init()
{
	//  Inicializa o buffer de cores com preto
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
//  Esta fun��o � passada para glutDisplayFunc para mostrar o conte�do
//  OpenGL na janela
//-------------------------------------------------------------------------
void display(void)
{
	//  Limpa o buffer do frame
	glClear(GL_COLOR_BUFFER_BIT);

	//  Para que n�o perca a propor��o da imagem ao redimensionar a tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//  Define plano cartesiano maior
	gluOrtho2D(planLeft, planRight, planUp, planBottom);

	//  Trata escala do objeto
	glScalef(scale, scale, 0);

	//  Desenha objetos
	drawObjects();

	//  Joga para o buffer principal o que foi desenhado no buffer secund�rio
	glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Esta fun��o muda as coordenadas x e y da tela
//  de maneira a deix�-la no centro
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}

//-------------------------------------------------------------------------
//  Inicializa o jogo com o estado inicial
//-------------------------------------------------------------------------
void startGame()
{
	LOG("Inicializa jogo");

	//	Tabuleiro do jogo
	board = new Board(
		7,								//  Tamanho de um bloco de tela
		11,								//  N�mero de linhas vis�veis para o sapo se movimentar
		13,								//  N�mero de colunas vis�veis para o sapo se movimentar
		{7, 11},						//  Posi��o inicial do sapo
		-8,								//  �ltima posi��o na esquerda antes do objeto ser transferido para direita
		16,								//  �ltima posi��o na direita antes do objeto ser transferido para esquerda
		{1, 1},							//  Posi��o para ganhar No 1
		{4, 1},							//  Posi��o para ganhar No 2
		{7, 1},							//  Posi��o para ganhar No 3
		{10, 1},						//  Posi��o para ganhar No 4
		{13, 1}							//  Posi��o para ganhar No 5
	);

	//  Sapo (player character)
	frog = new Frog(
		(*board).getStartPosition().x,	//  Posi��o inicial X do sapo � definida pelo tabuleiro
		(*board).getStartPosition().y,	//  Posi��o inicial Y do sapo � definida pelo tabuleiro
		{0.0f, 0.5f, 0.0f},				//  Cor do sapo
		3								//  Com quantas vidas o sapo nasce
	);

	//  Ve�culos da primeira linha (contando de baixo para cima)
	auto1 = new Automobile(
		1,								//  Posi��o inicial X
		10,								//  Posi��o inicial Y
		{ 0.6f, 0.2f, 0.3f },			//  Cor
		1,   						    //	Velocidade
		1								//  Tamanho
	);

	auto2 = new Automobile(5, 10, { 0.6f, 0.2f, 0.3f }, 1, 1);
	auto3 = new Automobile(9, 10, { 0.6f, 0.2f, 0.3f }, 1, 1);
}

//-------------------------------------------------------------------------
//  Aplica as regras ap�s mudan�as no estado no jogo
//-------------------------------------------------------------------------
void validateGameState()
{
	//  Se sapo alcan�ou uma posi��o n�o ocupada, deixar o sapo pintado fixo,
	//  reiniciar o round
	//  Se sapo alcan�ou uma posi��o ocupada, tirar uma vida do sapo, reiniciar o round.
	// Rules::WinPosition((*frog), (*board));

	//  P�e o sapo de volta no lugar, e reinicia os objetos
	//Gear::RestartRound();

}

//-------------------------------------------------------------------------
//  Libera mem�ria alocada para o jogo
//-------------------------------------------------------------------------
void freeMemoryGame()
{
	LOG("Finaliza jogo");
	delete auto1;
	delete auto2;
	delete auto3;
	delete frog;
	delete board;	
}

//-------------------------------------------------------------------------
//  Desenha objetos da tela
//-------------------------------------------------------------------------
void drawObjects()
{
	BoardGL::Draw((*board));
	FrogGL::Draw((*frog), (*board));
	ObjectGL::Draw((*auto1), (*board));
	ObjectGL::Draw((*auto2), (*board));
	ObjectGL::Draw((*auto3), (*board));
}

//-------------------------------------------------------------------------
//  Aplica mudan�as de movimento nos objetos que se movem
//-------------------------------------------------------------------------
void spinObjects()
{
	Gear::Move((*auto1), (*board));	
	Gear::Move((*auto2), (*board));
	Gear::Move((*auto3), (*board));
}

//-------------------------------------------------------------------------
//  Fun��o callback chamada para gerenciar eventos do teclado
//  para teclas especiais, tais como F1, PgDn e Home
//-------------------------------------------------------------------------
void specialKeys(int key, int x, int y)
{
	//  Cada tecla possui tratamento para que o sapo n�o saia pelas bordas
	if (key == GLUT_KEY_UP) {
		if ((*frog).getY() > 1) 
		{
			(*frog).setY((*frog).getY() - 1);
		}
	}
	if (key == GLUT_KEY_DOWN) {
		if ((*frog).getY() < (*board).getRows())
		{
			(*frog).setY((*frog).getY() + 1);
		}
	}
	if (key == GLUT_KEY_LEFT) {
		if ((*frog).getX() > 1)
		{
			(*frog).setX((*frog).getX() - 1);
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		if ((*frog).getX() < (*board).getCols())
		{ 
			(*frog).setX((*frog).getX() + 1);
		}
	}
	glutPostRedisplay();
	validateGameState();
}

//-------------------------------------------------------------------------
//  Registra o timer principal que dar� vida aos objetos da tela
//-------------------------------------------------------------------------
void timerFunc(int n)
{
	spinObjects();
	glutPostRedisplay();
	validateGameState();
	glutTimerFunc(n, timerFunc, n);
}
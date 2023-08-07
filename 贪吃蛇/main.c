#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#pragma comment(lib, "winmm.lib")
void start();
void chose();
void init();
void DrawMap();
void ChangeDir;
void move;
void addfood;
void autoseek;

enum game
{
    SPACE,WALL,SNAKE,FOOD
};
int mode;
int score;

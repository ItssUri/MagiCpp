#include <iostream>
#include "MagiaEstatica.h"
#include <windows.h> 
#include <random>


int main()
{
	srand(time(NULL));
	MagiaEstatica::Telepatia::introduction(); 
	MagiaEstatica::Telepatia::nameGathering();
	MagiaEstatica::Telepatia::nameMagic();
	MagiaEstatica::Telepatia::bdayGathering();
	MagiaEstatica::Telepatia::zodiacMagic();
	MagiaEstatica::Telepatia::ending();
}

#pragma once
#include <iostream>
namespace MagiaEstatica {
	class Adivinacion {
	public:
		static int encoder(std::string _cadena);
		static std::string nameReading(int name);
		static bool checkDate(std::string date);
		static std::string starSign(std::string date);
		static std::string zodiacReading(std::string sign);
		
	};
	class Modificacion {
	public:
		static void setColor(std::string color);
		static void resetColor();
		static void printZodiacSign(std::string sign);
		static void crystalBallReading(std::string text, int time, int  endline);
	};
	class Telepatia {
	public:
		static void introduction();
		static void nameGathering();
		static void nameMagic();
		static void bdayGathering();
		static void zodiacMagic();
		static void ending();
	};
	class Ilusionismo {
	public:
		static void woodCabin(int time);
		static void continuar(bool clear, int time);
		static void enmarcar(std::string text, bool typewriter);
		static void door(int time);
		static void title();
		static void input(std::string pregunta, std::string& var);
		static void crystalBall(int time);
		
	};
}
#include "MagiaEstatica.h"
#include <string>
#include <regex>
#include <iostream>
#include <time.h>
#include <random>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
std::string name;
int encoded_name;
std::string date;

namespace MagiaEstatica {
	int Adivinacion::encoder(std::string _cadena)
	{
		//A1z52 encoder
		int encoded = 0;
		char letters[52] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		for (int i = 0; i < _cadena.size(); i++) {
			for (int y = 0; y <= 52; y++) {
				if (_cadena[i] == letters[y]) {
					//std::cout << _cadena[i] << " = " << y << std::endl;
					encoded += y+1;
				}
			}
		}
		return encoded;
	}
	std::string Adivinacion::nameReading(int name) {
		name = name % 10;
		switch (name) {
		case 1:
			return "Veig una gran oportunitat arribant a la teva vida en breu.";
		case 2:
			return "L'amor està al teu voltant, només has de ser obert a acceptar-lo.";
		case 3:
			return "Una nova amistat et portarà molta felicitat i alegria.";
		case 4:
			return "És el moment de prendre decisions importants per al teu futur.";
		case 5:
			return "La prosperitat et seguirà en tot allà on vagis.";
		case 6:
			return "Una sorpresa inesperada canviarà la teva vida per sempre.";
		case 7:
			return "T'esperen grans èxits professionals en un futur no molt llunyà.";
		case 8:
			return "La teva salut millorarà considerablement en els pròxims mesos.";
		case 9:
			return "La teva creativitat i inspiració estan en un moment àlgid.";
		case 0:
			return "Hi ha algú que guarda secrets sobre tu, sigues cautelós.";
		default:
			break;
		}
	}
	bool Adivinacion::checkDate(std::string date) {
		//should be dd/mm/yyyy
		if (std::regex_match(date, std::regex("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-]\\d{4}$"))) {
			return true;
		}
		return false;
	}
	std::string Adivinacion::starSign(std::string date)
	{
		int day; std::string month;
		day = stoi(date.substr(0, 2));
		month = date.substr(3, 2);
		if ((day >= 21 && month == "03") || (day <= 19 && month == "04")) { return "Aries"; }
		else if ((day >= 21 && month == "04") || (day <= 20 && month == "05")) { return "Taure"; }
		else if ((day >= 20 && month == "05") || (day <= 20 && month == "06")) { return "Geminis"; }
		else if ((day >= 21 && month == "06") || (day <= 22 && month == "07")) { return "Cancer"; }
		else if ((day >= 23 && month == "07") || (day <= 22 && month == "08")) { return "Leo"; }
		else if ((day >= 23 && month == "08") || (day <= 22 && month == "09")) { return "Virgo"; }
		else if ((day >= 23 && month == "09") || (day <= 22 && month == "10")) { return "Libra"; }
		else if ((day >= 23 && month == "10") || (day <= 21 && month == "11")) { return "Escorpio"; }
		else if ((day >= 22 && month == "11") || (day <= 21 && month == "12")) { return "Sagitari"; }
		else if ((day >= 22 && month == "12") || (day <= 19 && month == "01")) { return "Capricorn"; }
		else if ((day >= 20 && month == "01") || (day <= 18 && month == "02")) { return "Aquari"; }
		else if ((day >= 19 && month == "02") || (day <= 20 && month == "03")) { return "Pisces"; }
	}
	std::string Adivinacion::zodiacReading(std::string sign) {
		/*srand(time(NULL));
		int quote = (rand() % 3) + 1;*/
		if (sign == "Aries") {
			return "Impulsiu i valent, sempre esta llest per afrontar nous reptes i endinsar-se en aventures emocionants sense pensar-ho dues vegades.";
		}
		else if (sign == "Taure") {
			return "Pacient i persistent, Treballador incansable que no es rendeix facilment davant els obstacles i sempre busca la estabilitat i seguretat en la seva vida.";
		}
		else if (sign == "Geminis") {
			return "Intel·ligent i comunicatiu, sempre esta buscant noves formes d'aprendre i compartir el seu coneixement amb els altres, pot adaptar-se facilment a diferents situacions i es molt sociable.";
		}
		else if (sign == "Cancer") {
			return "Empatic i afectuos, tendeix a protegir i cuidar dels seus essers estimats i sempre esta disponible per oferir suport emocional a tots aquells que l'envolten.";
		}
		else if (sign == "Leo") {
			return "Carismatic i confiat, sempre es el centre d'atencio alla on va i busca destacar-se a traves del seu carisma i lideratge natural, no te por de ser el protagonista de la historia.";
		}
		else if (sign == "Virgo") {
			return "Practic i detallista, es caracteritza per la seva organitzacio i perfeccionisme en tot el que fa, sempre busca la millor manera de resoldre els problemes i no deixa cap detall sense tenir en compte.";
		}
		else if (sign == "Libra") {
			return "Amable i equilibrat, sempre esta buscant la pau i l'harmonia en les seves relacions amb els altres, es capaç de comprendre els dos costats d'una situacio i trobar el punt mitja que satisfaci tothom.";
		}
		else if (sign == "Escorpio") {
			return "Apassionat i profund, te una personalitat intensa i misteriosa que amaga un gran poder emocional, sempre busca la veritat i l'essencia de les coses encara que hagi d'afrontar els seus propis temors i secrets mes profunds.";
		}
		else if (sign == "Sagitari") {
			return "Optimista i aventurer, sempre esta en constant recerca de noves experiencies i aprenentatges, es molt spontani i li agrada viure el present sense preocupar-se pel futur.";
		}
		else if (sign == "Capricorn") {
			return "Responsable i disciplinat, sempre busca la perfeccio en tot el que fa i no para fins aconseguir els seus objectius, te una gran capacitat d'organitzacio i planificacio que el fa destacar en els seus projectes.";
		}
		else if (sign == "Aquari") {
			return "Innovador i humanitari, sempre esta compromes amb causes socials i busca canviar el mon a traves de noves idees i solucions creatives, es molt independent i original en la seva forma de ser.";
		}
		else if (sign == "Pisces") {
			return "Sensible i imaginatiu, te una gran intuïcio i empatia que li permet connectar amb les emocions dels altres, es molt creatiu i idealista, sempre veu el costat positiu de les coses i esta disposat a ajudar als altres en tot moment.";
		}
	}
	void Modificacion::setColor(std::string color)
	{
		std::string colors[] = { "black","dark_blue","dark_green","dark_aqua","dark_red","dark_pink","dark_yellow","dark_white","gray","blue","green","aqua","red","pink","yellow","white"};
		if (color != "random") {
			for (int i = 0; i <= sizeof(colors); i++) {
				if (colors[i] == color) {
					SetConsoleTextAttribute(hConsole, i);
					break;
				}
			}
		}
		else {
			int randNum = (rand() % 15) + 1;
			SetConsoleTextAttribute(hConsole, randNum);
		}
	}
	void Modificacion::resetColor()
	{
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Modificacion::printZodiacSign(std::string sign)
	{
		if (sign == "Aries") {
			std::cout << " .-.   .-. " << std::endl;
			std::cout << "(_  \\ /  _)" << "	 Aries - El Corder"; std::cout  <<	std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
		}
		else if (sign == "Taure") {
			std::cout << "    .     ." << std::endl;
			std::cout << "    '.___.'       Taure - El Toro" << std::endl;
			std::cout << "    .'   `." << std::endl;
			std::cout << "   :       :" << std::endl;
			std::cout << "   :       :" << std::endl;
			std::cout << "    `.___.'" << std::endl;
		}
		else if (sign == "Geminis") {
			std::cout << "    ._____." << std::endl;
			std::cout << "      | |         Geminis - Els Bessons" << std::endl;
			std::cout << "      | |" << std::endl;
			std::cout << "     _|_|_" << std::endl;
			std::cout << "    '     '" << std::endl;
		}
		else if (sign == "Cancer") {
			std::cout << "      .--." << std::endl;
			std::cout << "     /   _`.      Cancer - El Cranc" << std::endl;
			std::cout << "    (_) ( )" << std::endl;
			std::cout << "   '.    /" << std::endl;
			std::cout << "     `--'" << std::endl;
		}
		else if (sign == "Leo") {
			std::cout << "      .--." << std::endl;
			std::cout << "     (    )        Leo - El Lleo" << std::endl;
			std::cout << "    (_)  /" << std::endl;
			std::cout << "        (_," << std::endl;
		}
		else if (sign == "Virgo") {
			std::cout << "   _" << std::endl;
			std::cout << "  ' `:--.--." << std::endl;
			std::cout << "     |  |  |_      Virgo - La Verge" << std::endl;
			std::cout << "     |  |  | )" << std::endl;
			std::cout << "     |  |  |/" << std::endl;
			std::cout << "          (J" << std::endl;
		}
		else if (sign == "Libra") {
			std::cout << "        __" << std::endl;
			std::cout << "   ___.'  '.___    Libra - La Balança" << std::endl;
			std::cout << "   ____________" << std::endl;
		}
		else if (sign == "Escorpio") {
			std::cout << "   _" << std::endl;
			std::cout << "  ' `:--.--." << std::endl;
			std::cout << "     |  |  |       Escorpio -  L'escorpi	" << std::endl;
			std::cout << "     |  |  |" << std::endl;
			std::cout << "     |  |  |  ..," << std::endl;
			std::cout << "           `---':" << std::endl;
		}
		else if (sign == "Sagitari") {
			std::cout << "          ..." << std::endl;
			std::cout << "          .':      Sagitari-  L'arquer" << std::endl;
			std::cout << "        .'" << std::endl;
			std::cout << "    `..'" << std::endl;
			std::cout << "    .'`." << std::endl;
		}
		else if (sign == "Capricorn") {
			std::cout << "            _" << std::endl;
			std::cout << "    \\      /_)     Capricorn - La Cabra" << std::endl;
			std::cout << "     \\    /`." << std::endl;
			std::cout << "      \\  /   ;" << std::endl;
			std::cout << "       \\/ __.'" << std::endl;
		}
		else if (sign == "Aquari") {
			std::cout << " .-"" - ._. - ""-._.-    Aquari - L'Aiguader" << std::endl;
			std::cout << " .-"" - ._. - ""-._.-" << std::endl;
		}
		else if (sign == "Pisces") {
			std::cout << "     `-.    .-'    Pisces - Els Peixos" << std::endl;
			std::cout << "        :  :" << std::endl;
			std::cout << "      --:--:--" << std::endl;
			std::cout << "        :  :" << std::endl;
			std::cout << "     .-'    `-." << std::endl;
		}
	}
	void Modificacion::crystalBallReading(std::string text, int time, int endline)
	{
		for (int i = 0; i < text.size(); i++)
		{
			std::cout << text[i];
			Sleep(time);
		}
		if (endline == 1)
		{
			std::cout << std::endl;
		}
		
	}
	void Telepatia::introduction(){
		Ilusionismo::woodCabin(0);
		Sleep(2000);
		Modificacion::setColor("yellow");
		Ilusionismo::enmarcar("Eh? On soc?",true);
		Sleep(2000);
		Ilusionismo::enmarcar("Una cabanya?",true);
		Sleep(2000);
		Ilusionismo::continuar(true,0);
		Ilusionismo::door(1);
		Sleep(1000);
		Modificacion::setColor("yellow");
		Ilusionismo::enmarcar("... Tinc fred, entrare ....", true);
		Sleep(3000);
		system("CLS");
		PlaySound(TEXT("door.wav"), NULL, SND_FILENAME | SND_SYNC);
		Sleep(1500);
		Ilusionismo::title();
		Sleep(4000);
		system("CLS");
		Sleep(3000);
	}
	void Telepatia::nameGathering() {;
		Modificacion::setColor("red");
		Ilusionismo::enmarcar("Benvingut, viatger.", true);
		Sleep(1000);
		Ilusionismo::enmarcar("Si ets aqui es per questio del desti.", true);
		Sleep(1000);
		Ilusionismo::enmarcar("Digues, jove. Quin es el teu nom?", true);
		Sleep(1000);
		Ilusionismo::input("Quin es el teu nom?", name);
		Modificacion::setColor("red");
		Sleep(1000);
		Ilusionismo::enmarcar(("... " + name + " eh? ..."), 1);
		Sleep(1000);
		Ilusionismo::enmarcar(("... Deixa'm que t'ensenyi el futur, " + name), 1);
		Sleep(3000);
		encoded_name = Adivinacion::encoder(name);
		Ilusionismo::continuar(false,0);
	}
	void Telepatia::nameMagic()
	{
		system("CLS");
		Ilusionismo::crystalBall(1);
		Sleep(1000);
		Ilusionismo::enmarcar("Veig el teu futur .....", 1);
		Sleep(3000);
		std::cout << std::endl;
		Modificacion::crystalBallReading("\t" + Adivinacion::nameReading(Adivinacion::encoder(name)),1,1);
		Sleep(3000);
		Ilusionismo::continuar(false,0);
		system("CLS");
	}
	void Telepatia::bdayGathering() {
		bool goodDate;
		Modificacion::setColor("red");
		Ilusionismo::enmarcar("... Molt interessant ...", true);
		Sleep(1000);
		Ilusionismo::enmarcar("Digues ara, quin dia vas neixer?", true);
		Sleep(1000);
		Ilusionismo::input("(dd/mm/aaaa) Quan vas néixer?", date);
		goodDate = Adivinacion::checkDate(date);
		while (!goodDate)
		{
			Ilusionismo::input("[Error. Datos incorrectos] (dd/mm/aaaa) Quan vas néixer?", date);
			goodDate = Adivinacion::checkDate(date);
		}
		
		Modificacion::setColor("red");
		Sleep(1000);
		Ilusionismo::enmarcar(("... Les  estrelles em parlen. El teu signe ..."), 1);
		Modificacion::setColor("random");
		Sleep(1000);
		std::cout << std::endl;
		Modificacion::printZodiacSign(Adivinacion::starSign(date));
		Sleep(1000);
		Ilusionismo::enmarcar((Adivinacion::starSign(date) + " ..."), 1);
		Sleep(4000);
		
	}
	void Telepatia::zodiacMagic() {
		Modificacion::setColor("white");
		Sleep(2000);
		system("CLS");
		Modificacion::crystalBallReading("\n\t* Mires al sostre i notes una foscor que t'envolta *", 2, 1);
		Modificacion::crystalBallReading("\n\t* T'envolten estrelles i formen una frase devant teu. *",2,1);
		Modificacion::crystalBallReading("\n\t* Les estrelles determinen la teva personalitat. *", 4, 1);
		std::cout << std::endl;
		Sleep(3000);

		Modificacion::crystalBallReading((Adivinacion::zodiacReading(Adivinacion::starSign(date))),2,1);
		std::cout << std::endl;
		Sleep(4000);
		Ilusionismo::continuar(0, 0);
	}
	void Telepatia::ending() {
		system("CLS");
		Sleep(2000);
		Modificacion::setColor("dark_blue");
		Ilusionismo::enmarcar("De sobte, tot s'apaga i notes com lleugerament et començes a desmaiar", 1);
		Modificacion::setColor("red");
		Sleep(3500);
		Ilusionismo::enmarcar("Et criden. Has de tornar.", 1);
		Sleep(4000);
		system("CLS");
		Modificacion::setColor("yellow");
		Ilusionismo::enmarcar("Gracies per jugar MagiC++.", 1);
		Sleep(5000);
		exit(0);
	}
	void Ilusionismo::woodCabin(int time)
	{
		Modificacion::setColor("dark_blue");
		Modificacion::crystalBallReading("                                            /\\\\", time, 1);
		Modificacion::crystalBallReading("/\\                                         /%%\\\\  /\\\\", time, 1);
		Modificacion::crystalBallReading("%%\\             ,                          /%%%%\\/%%\\", time, 1);
		Modificacion::crystalBallReading("%%%\\          ,~,                /\\       /%%%%/%%%%\\    ,   /\\", time, 1);
		Modificacion::crystalBallReading("%%%\\         ,~~~,   /\\         /%%\\  /\\ /%%%%%//\\%%\\/\\ ,~, /%%\\", time, 1);
		Modificacion::crystalBallReading("%%%%\\  /\\   ,~~~~~, /%%\\   /\\   /%%\\ /%%\\%/\\%/\\/%%\\%/%%\\~~~/%%%%\\", time, 1);
		Modificacion::crystalBallReading("%%%%\\ /%%\\ /\\~~~~~~/%%%%\\ /%%\\ /%%%%\\/%%\\/%%\\%%\\%%%/%(%%\\~~/%%%%\\", time, 1);
		Modificacion::crystalBallReading("%%%%%\\/%%\\/%%\\~/\\~~/%%%%\\/%%%%/%%%%%%\\%%/%%%%\\%%\\%%/)%%%\\~/%%%%%%\\", time, 1);
		Modificacion::crystalBallReading("%/\\%%/%%%%\\%%%/%%\\/%%%%%%\\%%/\\/%%/\\%%\\%%/\\%%%\\%%\\%%(%%%%%/%%%%%%%%\\ ", time, 1);
		Modificacion::crystalBallReading("/%%\\/%%%%%%\\/\\/%%\\/%%%%%%\\%/%%\\%/%%\\%%\\/%%\\_______[_]________%%%%%\\", time, 1);
		Modificacion::crystalBallReading("%%%%/%%%%%%/%%\\%%/%%%%%%%%\\/%%\\%/%%\\%%/%%%%\\ _-       _-  _- \\%%%%%\\", time, 1);
		Modificacion::crystalBallReading("%%%/%%%%%%%/%%\\%%/%%/\\%%%%/%%%%\\%%%%\\/%%%%%%\\______-__________\\""" "", time, 1);
		Modificacion::crystalBallReading("lc/%%%%%%%/%%%%\\/%%/%%\\%%%/%%%%\\%%%%\\/%%%%%%%\\__===______====_]   ,~,  _-", time, 1);
		Modificacion::crystalBallReading(""" /%%%%%%/%%%%%%,%%/%%\\%%/%%%%%%\\%%%/%%%%%%%%%\\_|_|______|  |_]  ,~~~,", time, 1);
		Modificacion::crystalBallReading(" /%%%%%%%/%%%%%,~,/%%%%\\/%%%%%%%%\\%/%%%%%%%%%%\\_________|- |_] ,~~~~~,", time, 1);
		Modificacion::crystalBallReading(" /%%%%%%/%%%%%,~~~,%%%%\\/%%%%%%%%\\%/%%%%%%%%%%\\___#__#__|__|_],~~~~~~~,", time, 1);
		Modificacion::crystalBallReading("/%%%%%#%/#%%%,~~~~~,%%%/%%%%%%%%%%/%%%%%%%%%%%%\\"" \\  / """ "/ \\," "~~;" "~~,", time, 1);
	}
	void Ilusionismo::continuar(bool clear, int time) {
		Modificacion::resetColor();
		Modificacion::crystalBallReading("\n+---------------------------------+", time,1);
		Modificacion::crystalBallReading("| Presiona Enter per continuar... |", time,1);
		Modificacion::crystalBallReading("+---------------------------------+", time,1);
		std::cin.ignore();
		if (clear) {
			system("CLS");
		}
	}
	void Ilusionismo::enmarcar(std::string text, bool typewriter) {
		int textsize = text.size();
		
		if (typewriter)
		{
			PlaySound(TEXT("sans.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Modificacion::crystalBallReading("\n#", 1, 0);
			for (int i = 0; i < textsize + 2; i++) {
				Modificacion::crystalBallReading("=", 1, 0);
			}
			Modificacion::crystalBallReading("#\n", 1, 0);
			Modificacion::crystalBallReading("| " + text + " |\n", 1, 0);
			Modificacion::crystalBallReading("#", 1, 0);
			for (int i = 0; i < textsize + 2; i++) {
				Modificacion::crystalBallReading("=", 1, 0);
			}
			Modificacion::crystalBallReading("#\n", 1, 0);
		}
		else {
			std::cout << "\n#";
			for (int i = 0; i < textsize + 2; i++) {
				std::cout << "=";
			}
			std::cout << "#\n";
			std::cout << "| " << text << " |\n";
			std::cout << "#";
			for (int i = 0; i < textsize + 2; i++) {
				std::cout << "=";
			}
			std::cout << "#\n";
		}
		
	}
	void Ilusionismo::door(int time) {
		Modificacion::setColor("blue");
		Modificacion::crystalBallReading("      ______", time, 1);
		Modificacion::crystalBallReading("   ,-' ;  ! `-.", time, 1);
		Modificacion::crystalBallReading("  / :  !  :  . \\", time, 1);
		Modificacion::crystalBallReading(" |_ ;   __:  ;  |", time, 1);
		Modificacion::crystalBallReading(" )| .  :)(.  !  |", time, 1);
		Modificacion::crystalBallReading(" |     (##)   _ | ", time, 1);
		Modificacion::crystalBallReading(" |  :  ;`'  (_) (", time, 1);
		Modificacion::crystalBallReading(" |  :  :  .     |", time, 1);
		Modificacion::crystalBallReading(" )_ !  ,  ;  ;  |", time, 1);
		Modificacion::crystalBallReading(" || .  .  :  :  |", time, 1);
		Modificacion::crystalBallReading(" |     . | :  . | ", time, 1);
		Modificacion::crystalBallReading(" |mt-2_;----.___|", time, 1);
	}
	void Ilusionismo::title() {
		Modificacion::setColor("dark_blue");
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "@                                                                 @" << std::endl;
		std::cout << "@"; Modificacion::setColor("dark_yellow"); std::cout << "  )\\   )\\     /`-.      )\\.-.   .'( "; Modificacion::setColor("pink"); std::cout << "    )\\.-.     )`.      )`.   "; Modificacion::setColor("dark_blue"); std::cout << "@" << std::endl;
		Modificacion::setColor("dark_blue"); std::cout << "@ ";
		Modificacion::setColor("dark_yellow"); std::cout << "(  ',/ /   ,' _  \\   ,' ,-,_)  \\  )  ";
		Modificacion::setColor("pink"); std::cout << ",' ,-,_)   (  /     (  /   "; 
		Modificacion::setColor("dark_blue"); std::cout << "@" << std::endl;
		
		Modificacion::setColor("dark_blue"); std::cout << "@  ";
		Modificacion::setColor("dark_yellow"); std::cout << ")    (   (  '-' (  (  .   __  ) (  ";
		Modificacion::setColor("pink"); std::cout << "(  .   _  .-    -. .-    -. ";
		Modificacion::setColor("dark_blue"); std::cout << "@" << std::endl;

		Modificacion::setColor("dark_blue"); std::cout << "@ ";
		Modificacion::setColor("dark_yellow"); std::cout << "(  \\(\\ \\   )   _  )  ) '._\\ _) \\  )  ";
		Modificacion::setColor("pink"); std::cout << ") '..' ) '-    -' '-    -' ";
		Modificacion::setColor("dark_blue"); std::cout << "@" << std::endl;

		Modificacion::setColor("dark_blue"); std::cout << "@  ";
		Modificacion::setColor("dark_yellow"); std::cout << "`.) /  ) (  ,' ) \\ (  ,   (    ) \\ ";
		Modificacion::setColor("pink"); std::cout << "(  ,   (    /  )     /  )   ";
		Modificacion::setColor("dark_blue"); std::cout << "@" << std::endl;

		Modificacion::setColor("dark_blue"); std::cout << "@      ";
		Modificacion::setColor("dark_yellow"); std::cout << "'.(   )/    )/  )/'._.'     )/  ";
		Modificacion::setColor("pink"); std::cout << ")/'._.'    '.(      '.(    ";
		Modificacion::setColor("dark_blue"); std::cout << "@" << std::endl;
		std::cout << "@                                                                 @" << std::endl;
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	}
	void Ilusionismo::input(std::string pregunta, std::string& var) {
		Modificacion::setColor("yellow");
		pregunta = "\n\t} - " + pregunta + " : ";
		Modificacion::crystalBallReading(pregunta, 0, 0);
		getline(std::cin, var);

	}
	void Ilusionismo::crystalBall(int time) {
		Modificacion::setColor("dark_pink");
		Modificacion::crystalBallReading("         _...._", time, 1);
		Modificacion::crystalBallReading("       .`      `.", time, 1);
		Modificacion::crystalBallReading("      / ***      \\", time, 1);
		Modificacion::crystalBallReading("     : **         : ", time, 1);
		Modificacion::crystalBallReading("     :            :", time, 1);
		Modificacion::crystalBallReading("      \\          /", time, 1);
		Modificacion::crystalBallReading("       `-.,,,,.-' ", time, 1);
		Modificacion::crystalBallReading("        _(    )_", time, 1);
		Modificacion::crystalBallReading("       )        (", time, 1);
		Modificacion::crystalBallReading("      (          )", time, 1);
		Modificacion::crystalBallReading("       `-......-`lc", time, 1);
	}
}
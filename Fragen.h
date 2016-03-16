
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fragen

{
public:
	Fragen(){};
	void createFrage();
	void setFrage(const char* new_frage, const char* new_antwort_r, const char* new_antwort_f1, const char* new_antwort_f2,
                        const char* new_antwort_f3,int wissensbereich);
	void listAll();
	void menu();
	bool read(int p_id);
	void createUpdate();
	void update(int temp_id);
	void entfernen();
	void anzeigen();
	void setEnd(bool a){ended=a;}
	bool getEnd(){return ended;}

private:
    bool ended;

};




#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Wissensbereiche
{
public:
	Wissensbereiche(){};
	void createWissensbereich();
	void setWissensbereich(const char* new_name,const char* new_beschreibung);
	int getID(){ return id; };
	void listAll();
	void menu();
	string getName(){ return sql_name; };
	string getBeschreibung(){ return sql_beschreibung; };
	void read(int p_id);
	void createUpdate();
	void update(int temp_id);
	void entfernen();

private:
	string sql_name;
	string sql_beschreibung;
	int id;
};


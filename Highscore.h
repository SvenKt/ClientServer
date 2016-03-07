#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Highscore
{
public:
	Highscore(){};
	void createHighscore();
	void setHighscore(const char* new_h_name,long new_score);
	int getID(){ return id; };
	void listAll();
	void menu();
	string getName(){ return sql_name; };
	string getScore(){ return sql_score; };
	bool read(int p_id);
	void createUpdate();
	void update(int temp_id);
	void entfernen();

private:
	string sql_name;
	string sql_score;
	int id;
};


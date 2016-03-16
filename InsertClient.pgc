// InsertClient.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include "Wissensbereiche.h"
#include "Fragen.h"
#include "Highscore.h"

using namespace std;

int main()
{
//graphInt gui;
Wissensbereiche wb;
Fragen fr;
Highscore hs;

    EXEC SQL BEGIN DECLARE SECTION;
        char dbname[1024];
        char name[64];
        int testid;
    EXEC SQL END DECLARE SECTION;


    //namenskonvention: alle tabellen / spalten müssen klein geschrieben sein!! auch in der datenbank!
	EXEC SQL CONNECT TO 'csdb1@lamp.wlan.hwr-berlin.de' USER csdb1 IDENTIFIED BY csdb1;
	EXEC SQL SELECT current_database() INTO :dbname;

	// sample code
	//EXEC SQL SELECT testchar INTO :name FROM test WHERE test_id=1;

    printf("Willkommen im Quizadmin!\nSie wurden erfolgreich verbunden mit Datenbank \'%s\'\n\n", dbname);

   //sample code result
   // printf("%s\n",name);
	string antwort = "1";
	while (antwort[0] != '0'){
		cout << "Welche Tabelle wollen Sie bearbeiten?\n\n 1: Wissensbereiche\n 2: Fragen\n 3: Highscore\n 0: Beenden" << endl;
		getline(cin,antwort);
        if(antwort.length() < 2){
            switch (antwort[0]){
            case '0': cout << "Programm wird beendet" << endl;break;
            case '1': cout << "Wissensbereiche werden geladen...\n" << endl;
                    wb.menu(); break;
            case '2': cout << "Fragen werden geladen..." << endl;  antwort = '1';
                    fr.menu(); break;
            case '3': cout << "Highscore wird geladen..." << endl;  antwort = '1';
                    hs.menu(); break;
            default: cout << "Fehler: falsche Eingabe. Bitte erneut eingeben!" << endl;  antwort = '1';
            }
		} else {
            cout << "Fehlerhafte Eingabe!" << endl;
		}
	}
}


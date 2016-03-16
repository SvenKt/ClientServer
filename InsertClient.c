/* Processed by ecpg (4.9.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "InsertClient.pgc"
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

    /* exec sql begin declare section */
         
         
         
    
#line 21 "InsertClient.pgc"
 char dbname [ 1024 ] ;
 
#line 22 "InsertClient.pgc"
 char name [ 64 ] ;
 
#line 23 "InsertClient.pgc"
 int testid ;
/* exec sql end declare section */
#line 24 "InsertClient.pgc"



    //namenskonvention: alle tabellen / spalten müssen klein geschrieben sein!! auch in der datenbank!
	{ ECPGconnect(__LINE__, 0, "csdb1@lamp.wlan.hwr-berlin.de" , "csdb1" , "csdb1" , NULL, 0); }
#line 28 "InsertClient.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select current_database ( )", ECPGt_EOIT, 
	ECPGt_char,(dbname),(long)1024,(long)1,(1024)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 29 "InsertClient.pgc"


	// sample code
	//EXEC SQL SELECT testchar INTO :name FROM test WHERE test_id=1;

    printf("Willkommen im Quizadmin!\nSie wurden erfolgreich verbunden mit Datenbank \'%s\'\n\n", dbname);

   //sample code result
   // printf("%s\n",name);
	string antwort = "1";
	while (antwort != "0"){
		cout << "Welche Tabelle wollen Sie bearbeiten?\n\n 1: Wissensbereiche\n 2: Fragen\n 3: Highscore\n 0: Programm beenden" << endl;
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


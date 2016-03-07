/* Processed by ecpg (4.9.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "Wissensbereich.pgc"
#include "Wissensbereiche.h"

void Wissensbereiche::setWissensbereich(char new_name[255], char new_beschreibung[255]){
	cout << "entry" << endl;
	/*name = new_name;
	beschreibung = new_beschreibung;
	*/
	/* exec sql begin declare section */
           
           
         
	
#line 9 "Wissensbereich.pgc"
 char insertname [ 255 ] = new_name ;
 
#line 10 "Wissensbereich.pgc"
 char insertbeschr [ 255 ] = new_beschreibung ;
 
#line 11 "Wissensbereich.pgc"
 long insertid ;
/* exec sql end declare section */
#line 12 "Wissensbereich.pgc"


    //EXEC SQL SELECT MAX(w_id) INTO :insertid FROM wissensbereich;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into wissensbereich values ( 3 , \"Essen\" , \"Alles, was gut ist\" )", ECPGt_EOIT, ECPGt_EORT);}
#line 15 "Wissensbereich.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 16 "Wissensbereich.pgc"


	cout << "Hallo" <<endl;//insertid+1 << " " << insertname << " " << insertbeschr << endl;
	/*
	SQL STATEMENT
	EXEC SQL BEGIN DECLARE SECTION;
	long sql_id;
	char[256] sql_name;
	char[256] sql_beschreibung;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL SELECT MAX(W_ID) INTO :sql_id FROM Wissensbereich;
	sql_name = new_name;
	sql_beschreibung = new_beschreibung;
	EXEC SQL INSERT INTO Wissensbereich Values (:sql_id+1, :sql_name, sql_beschreibung);
	*/
};

void Wissensbereiche::read(int p_id) {
	/*SQL STATEMENT
	EXEC SQL BEGIN DECLARE SECTION;
	long sql_id;
	char[256] sql_name;
	char[256] sql_beschreibung;
	EXEC SQL END DECLARE SECTION;
	sql_id = p_id;
	EXEC SQL SELECT W_Name, W_Beschreibung INTO :sql_name, :sql_beschreibung FROM Wissensbereich WHERE W_ID = :sql_id;
	id = p_id;
	name = sql_name;
	beschreibung = sql_beschreibung;
	*/
};

void Wissensbereiche::update(string new_name, string new_beschreibung){
	name = new_name;
	beschreibung = new_beschreibung;
	/*SQL STATEMENT
	EXEC SQL BEGIN DECLARE SECTION;
	long sql_id;
	char[256] sql_name;
	char[256] sql_beschreibung;
	EXEC SQL END DECLARE SECTION;
	sql_id = id;
	sql_name = new_name;
	sql_beschreibung = new_beschreibung;
	EXEC SQL UPDATE Wissensbereich SET W_Name = :sql_name, W_Beschreibung = :sql_beschreibung WHERE W_ID = :sql_id;
	*/
};

void Wissensbereiche::entfernen(){
	//todo
};


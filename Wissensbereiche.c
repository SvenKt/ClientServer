/* Processed by ecpg (4.9.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "Wissensbereiche.pgc"
#include "Wissensbereiche.h"


    //sample code working for where statement
    //EXEC SQL SELECT w_name INTO :name FROM wissensbereich WHERE w_id=1;
    //printf("%s\n", name);


void Wissensbereiche::setWissensbereich(const char* new_name,const char* new_beschreibung){

	/* exec sql begin declare section */
          
          
         
	
#line 12 "Wissensbereiche.pgc"
 const char * insertname ;
 
#line 13 "Wissensbereiche.pgc"
 const char * insertbeschr ;
 
#line 14 "Wissensbereiche.pgc"
 int insertid ;
/* exec sql end declare section */
#line 15 "Wissensbereiche.pgc"


	insertname = new_name;
    insertbeschr = new_beschreibung;

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( w_id ) from wissensbereich", ECPGt_EOIT, 
	ECPGt_int,&(insertid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 20 "Wissensbereiche.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into wissensbereich values ( $1  + 1 , $2  , $3  )", 
	ECPGt_int,&(insertid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(insertname),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(insertbeschr),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 21 "Wissensbereiche.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 22 "Wissensbereiche.pgc"

};

void Wissensbereiche::read(int p_id) {

	/* exec sql begin declare section */
	 
	 
	 
	
#line 28 "Wissensbereiche.pgc"
 long sql_id ;
 
#line 29 "Wissensbereiche.pgc"
 char name [ 256 ] ;
 
#line 30 "Wissensbereiche.pgc"
 char beschreibung [ 256 ] ;
/* exec sql end declare section */
#line 31 "Wissensbereiche.pgc"

	sql_id = p_id;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select w_name , w_beschreibung from wissensbereich where w_id = $1 ", 
	ECPGt_long,&(sql_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(beschreibung),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 33 "Wissensbereiche.pgc"


	cout << "\n" << p_id << "\t" << name << "\t" << beschreibung << "\t\n" << endl;
};

void Wissensbereiche::update(int temp_id){

    string new_name;
    string new_desc;

    read(temp_id);

    cout << "Geben Sie den neuen Namen ein: "<< endl;
    getline(cin,new_name);

    cout << "Geben Sie die neue Beschreibung ein: "<< endl;
    getline(cin, new_desc);

	/* exec sql begin declare section */
	 
	   
	  
	
#line 52 "Wissensbereiche.pgc"
 int sql_id ;
 
#line 53 "Wissensbereiche.pgc"
 const char * sql_new_name ;
 
#line 54 "Wissensbereiche.pgc"
 const char * sql_new_beschreibung ;
/* exec sql end declare section */
#line 55 "Wissensbereiche.pgc"


	sql_id = temp_id;
	sql_new_name = new_name.c_str();
	sql_new_beschreibung = new_desc.c_str();
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update wissensbereich set w_name = $1  , w_beschreibung = $2  where w_id = $3 ", 
	ECPGt_char,&(sql_new_name),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sql_new_beschreibung),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 60 "Wissensbereiche.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 61 "Wissensbereiche.pgc"


};

void Wissensbereiche::entfernen(){
	string temp;
	cout << "Geben Sie die ID des zu entfernenden Wissensbereiches an: ";
    getline(cin, temp);
    istringstream ss(temp);
    ss >> id;
    cout << "Zu entfernender Wissensbereich:\t" << endl;
    read(id);

    cout << "Wollen Sie diesen Wissensbereich wirklich entfernen?\n(1)\tJa\n(0)\tNein\n";
    getline(cin, temp);

    if(temp == "1"){
      /* exec sql begin declare section */
             
      
#line 79 "Wissensbereiche.pgc"
 int del_id ;
/* exec sql end declare section */
#line 80 "Wissensbereiche.pgc"

      del_id = id;

      { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from wissensbereich where w_id = $1 ", 
	ECPGt_int,&(del_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 83 "Wissensbereiche.pgc"

      { ECPGtrans(__LINE__, NULL, "commit");}
#line 84 "Wissensbereiche.pgc"

    }

};

void Wissensbereiche::listAll(){

	/* exec sql begin declare section */
		 
		 
		 
		 
	
#line 92 "Wissensbereiche.pgc"
 char name [ 256 ] ;
 
#line 93 "Wissensbereiche.pgc"
 char beschr [ 256 ] ;
 
#line 94 "Wissensbereiche.pgc"
 long current_id ;
 
#line 95 "Wissensbereiche.pgc"
 int counter ;
/* exec sql end declare section */
#line 96 "Wissensbereiche.pgc"

    cout << "ID\tName\tBeschreibung\n"<<endl;


    //select all wissensbereiche
    /* declare cur cursor for select w_name , w_beschreibung , w_id from wissensbereich order by w_id */
#line 101 "Wissensbereiche.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur cursor for select w_name , w_beschreibung , w_id from wissensbereich order by w_id", ECPGt_EOIT, ECPGt_EORT);}
#line 102 "Wissensbereiche.pgc"

    /* exec sql whenever not found  break ; */
#line 103 "Wissensbereiche.pgc"


   while(1){
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in cur", ECPGt_EOIT, 
	ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(beschr),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(current_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 106 "Wissensbereiche.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 106 "Wissensbereiche.pgc"

    printf("%ld\t%s\t%s\n", current_id,name,beschr);
   }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur", ECPGt_EOIT, ECPGt_EORT);}
#line 110 "Wissensbereiche.pgc"

}

void Wissensbereiche::menu(){
    string antwort_wb = "1";

    while (antwort_wb[0] != '0'){
        listAll();
        cout << "\n\nWelche Aktion wollen Sie durchfuehren?\n(1)\tNeuen Wissensbereich eintragen\n(2)\tWissensbereich bearbeiten\n(3)\tWissensbereich entfernen\n(0)\tBeenden\n\n" <<endl;
        getline(cin,antwort_wb);
        switch(antwort_wb[0]){
              case '1':
                   createWissensbereich();
              break;
                case '2': createUpdate();break;
                case '3': entfernen(); break;
                case '0':break;
        }
    }
}

void Wissensbereiche::createWissensbereich(){
    cout << "Name: ";
    getline(cin,sql_name);
    cout << "Beschreibung: ";
    getline(cin,sql_beschreibung) ;

    setWissensbereich(sql_name.c_str(), sql_beschreibung.c_str());
}

void Wissensbereiche::createUpdate(){
string antwort_up = "1";
    while (antwort_up[0] != '0'){
        listAll();
        cout << "\n\nWelchen Wissensbereich wollen Sie bearbeiten? \n(0)\tAbbrechen\n(<ID>)\t Bearbeiten\n" <<endl;
        getline(cin,antwort_up);
        if(antwort_up[0] == '0') {
            break;
        }
        istringstream ss(antwort_up);
        ss >> id;
        update(id);
    }
}


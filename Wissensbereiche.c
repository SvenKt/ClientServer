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

bool Wissensbereiche::read(int p_id) {

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


    if (sqlca.sqlcode == 100){
        cout << "Fehler, keine solche ID vorhanden" << endl;
        return false;
    } else{
    	cout << "\n" << p_id << "\t" << name << "\t" << beschreibung << "\t\n" << endl;
        return true;
    }


};

void Wissensbereiche::update(int temp_id){

    string new_name;
    string new_desc;

    if (read(temp_id)){
     cout << "<Enter> für das Beibehalten der alten Werte" << endl;
        cout << "Geben Sie den neuen Namen ein: "<< endl;
        getline(cin,new_name);



        cout << "Geben Sie die neue Beschreibung ein: "<< endl;
        getline(cin, new_desc);




        /* exec sql begin declare section */
         
           
          
        
#line 65 "Wissensbereiche.pgc"
 int sql_id ;
 
#line 66 "Wissensbereiche.pgc"
 const char * sql_new_name ;
 
#line 67 "Wissensbereiche.pgc"
 const char * sql_new_beschreibung ;
/* exec sql end declare section */
#line 68 "Wissensbereiche.pgc"


        sql_id = temp_id;
        sql_new_name = new_name.c_str();
        sql_new_beschreibung = new_desc.c_str();

         if(new_name != ""){
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update wissensbereich set w_name = $1  where w_id = $2 ", 
	ECPGt_char,&(sql_new_name),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 75 "Wissensbereiche.pgc"

        }
        if (new_desc != ""){
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update wissensbereich set w_beschreibung = $1  where w_id = $2 ", 
	ECPGt_char,&(sql_new_beschreibung),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 78 "Wissensbereiche.pgc"

        }

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 81 "Wissensbereiche.pgc"

    }
};

void Wissensbereiche::entfernen(){
	string temp;
	while (temp[0] != '0'){
        listAll();
        cout << "\n\nWelchen Wissensbereich wollen Sie entfernen? \n(0)\tAbbrechen\n(<ID>)\t Entfernen\n";
        getline(cin, temp);
        istringstream ss(temp);
        ss >> id;
        if(id == 0){
            break;
        }

        cout << "Zu entfernender Wissensbereich:\t" << endl;
        if(read(id)){
            cout << "Wollen Sie diesen Wissensbereich wirklich entfernen?\n(1)\tJa\n(0)\tNein\n";
            getline(cin, temp);

            if(temp == "1"){



              /* exec sql begin declare section */
                     
                     
              
#line 107 "Wissensbereiche.pgc"
 int del_id ;
 
#line 108 "Wissensbereiche.pgc"
 int anzahl ;
/* exec sql end declare section */
#line 109 "Wissensbereiche.pgc"

              del_id = id;

              { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( f_id ) from fragen where w_id = $1 ", 
	ECPGt_int,&(del_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(anzahl),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 112 "Wissensbereiche.pgc"


             if(anzahl > 0) {
              cout << "Es befinden sich noch " << anzahl << " Fragen in diesem Wissensbereich. Diese werden auch entfernt. Fortfahren?\n(1)\tJa\n(0)\tNein" << endl;
             getline(cin, temp);

                if(temp == "1"){
                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from fragen where w_id = $1 ", 
	ECPGt_int,&(del_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 119 "Wissensbereiche.pgc"

                } else {
                    break;
                }

             }

              { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from wissensbereich where w_id = $1 ", 
	ECPGt_int,&(del_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 126 "Wissensbereiche.pgc"

              { ECPGtrans(__LINE__, NULL, "commit");}
#line 127 "Wissensbereiche.pgc"

            }
        }
	}

};

void Wissensbereiche::listAll(){

	/* exec sql begin declare section */
		 
		 
		 
		 
	
#line 137 "Wissensbereiche.pgc"
 char name [ 256 ] ;
 
#line 138 "Wissensbereiche.pgc"
 char beschr [ 256 ] ;
 
#line 139 "Wissensbereiche.pgc"
 long current_id ;
 
#line 140 "Wissensbereiche.pgc"
 int counter ;
/* exec sql end declare section */
#line 141 "Wissensbereiche.pgc"

    cout << "ID\tName\tBeschreibung\n"<<endl;


    //select all wissensbereiche
    /* declare cur cursor for select w_name , w_beschreibung , w_id from wissensbereich order by w_id */
#line 146 "Wissensbereiche.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur cursor for select w_name , w_beschreibung , w_id from wissensbereich order by w_id", ECPGt_EOIT, ECPGt_EORT);}
#line 147 "Wissensbereiche.pgc"

    /* exec sql whenever not found  break ; */
#line 148 "Wissensbereiche.pgc"


   while(1){
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in cur", ECPGt_EOIT, 
	ECPGt_char,(name),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(beschr),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(current_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 151 "Wissensbereiche.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 151 "Wissensbereiche.pgc"

    printf("%ld\t%s\t%s\n", current_id,name,beschr);
   }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur", ECPGt_EOIT, ECPGt_EORT);}
#line 155 "Wissensbereiche.pgc"

}

void Wissensbereiche::menu(){
    string antwort_wb = "1";


    while (antwort_wb[0] != '0'){
        listAll();
        cout << "\n\nWelche Aktion wollen Sie durchfuehren?\n(1)\tNeuen Wissensbereich eintragen\n(2)\tWissensbereich bearbeiten\n(3)\tWissensbereich entfernen\n(0)\tBeenden\n\n" <<endl;
        getline(cin,antwort_wb);

        if(antwort_wb.length() < 2){
            switch(antwort_wb[0]){
              case '1':
                   createWissensbereich();
              break;
                case '2': createUpdate();break;
                case '3': entfernen(); break;
                case '0':break;
                default : cout << "Fehlerhafte Eingabe" << endl;
            }
        } else {
            cout << "Fehlerhafte Eingabe" << endl;
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


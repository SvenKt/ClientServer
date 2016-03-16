/* Processed by ecpg (4.9.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "Fragen.pgc"

#include "Wissensbereiche.h"
#include "Fragen.h"

    //sample code working for where statement
    //EXEC SQL SELECT w_name INTO :name FROM wissensbereich WHERE w_id=1;
    //printf("%s\n", name);


void Fragen::setFrage(const char* new_frage, const char* new_antwort_r, const char* new_antwort_f1, const char* new_antwort_f2,
                        const char* new_antwort_f3,int wissensbereich){

	/* exec sql begin declare section */
          
          
          
          
          
         
         
	
#line 14 "Fragen.pgc"
 const char * fr ;
 
#line 15 "Fragen.pgc"
 const char * a_r ;
 
#line 16 "Fragen.pgc"
 const char * a_f1 ;
 
#line 17 "Fragen.pgc"
 const char * a_f2 ;
 
#line 18 "Fragen.pgc"
 const char * a_f3 ;
 
#line 19 "Fragen.pgc"
 int wb ;
 
#line 20 "Fragen.pgc"
 int id ;
/* exec sql end declare section */
#line 21 "Fragen.pgc"


	fr = new_frage;
    a_r = new_antwort_r;
    a_f1 = new_antwort_f1;
    a_f2 = new_antwort_f2;
    a_f3 = new_antwort_f3;
    wb = wissensbereich;

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( f_id ) from fragen", ECPGt_EOIT, 
	ECPGt_int,&(id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 30 "Fragen.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into fragen values ( $1  + 1 , $2  , $3  , $4  , $5  , $6  , $7  )", 
	ECPGt_int,&(id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(wb),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(fr),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(a_r),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(a_f1),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(a_f2),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(a_f3),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 31 "Fragen.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 32 "Fragen.pgc"



};

bool Fragen::read(int p_id) {
	/* exec sql begin declare section */
	 
	 
	 
	 
	 
	 
	 
	 
	
#line 39 "Fragen.pgc"
 long sql_id ;
 
#line 40 "Fragen.pgc"
 long sql_wb ;
 
#line 41 "Fragen.pgc"
 char wissensbereich [ 256 ] ;
 
#line 42 "Fragen.pgc"
 char fr [ 256 ] ;
 
#line 43 "Fragen.pgc"
 char a_r [ 256 ] ;
 
#line 44 "Fragen.pgc"
 char a_f1 [ 256 ] ;
 
#line 45 "Fragen.pgc"
 char a_f2 [ 256 ] ;
 
#line 46 "Fragen.pgc"
 char a_f3 [ 256 ] ;
/* exec sql end declare section */
#line 47 "Fragen.pgc"

	sql_id = p_id;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select w_id , frage , antwort_r , antwort_f1 , antwort_f2 , antwort_f3 from fragen where f_id = $1 ", 
	ECPGt_long,&(sql_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_long,&(sql_wb),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fr),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(a_r),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(a_f1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(a_f2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(a_f3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 49 "Fragen.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select w_name from wissensbereich where w_id = $1 ", 
	ECPGt_long,&(sql_wb),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(wissensbereich),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 50 "Fragen.pgc"


    if (sqlca.sqlcode == 100){
        cout << "Fehler, keine solche ID vorhanden" << endl;
        return false;
    } else{
    	cout << "\n" << p_id << "\t" << wissensbereich << "\t" << fr << "\n(x)\t" << a_r << "\n( )\t" << a_f1 << "\n( )\t" << a_f2 << "\n( )\t" << a_f3 << "\t\n" << endl;
        return true;
    }
};


void Fragen::update(int temp_id){
    int new_wb;
    string new_fr;
    string new_a_r;
    string new_a_f1;
    string new_a_f2;
    string new_a_f3;

    if (read(temp_id)){
        cout << "<Enter> für das Beibehalten der alten Werte" << endl;
        cout << "Geben Sie die neue Frage an:" << endl;
        getline(cin,new_fr);

        cout << "Geben Sie die neue richtige Antwort ein: "<< endl;
        getline(cin,new_a_r);

        cout << "Geben Sie eine neue falsche Antwort ein: "<< endl;
        getline(cin, new_a_f1);
        cout << "Geben Sie eine neue falsche Antwort ein: "<< endl;
        getline(cin, new_a_f2);
        cout << "Geben Sie eine neue falsche Antwort ein: "<< endl;
        getline(cin, new_a_f3);

        /* exec sql begin declare section */
             
             
              
              
              
              
              
        
#line 86 "Fragen.pgc"
 int sql_id ;
 
#line 87 "Fragen.pgc"
 int sql_wb ;
 
#line 88 "Fragen.pgc"
 const char * sql_fr ;
 
#line 89 "Fragen.pgc"
 const char * sql_a_r ;
 
#line 90 "Fragen.pgc"
 const char * sql_a_f1 ;
 
#line 91 "Fragen.pgc"
 const char * sql_a_f2 ;
 
#line 92 "Fragen.pgc"
 const char * sql_a_f3 ;
/* exec sql end declare section */
#line 93 "Fragen.pgc"


        sql_id = temp_id;
        sql_wb = new_wb;

        if(new_fr != ""){
            sql_fr = new_fr.c_str();
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fragen set frage = $1  where f_id = $2 ", 
	ECPGt_char,&(sql_fr),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 100 "Fragen.pgc"

        }

        if (new_a_r != ""){
            sql_a_r = new_a_r.c_str();
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fragen set antwort_r = $1  where f_id = $2 ", 
	ECPGt_char,&(sql_a_r),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 105 "Fragen.pgc"

        }

        if (new_a_f1 != ""){
            sql_a_f1 = new_a_f1.c_str();
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fragen set antwort_f1 = $1  where f_id = $2 ", 
	ECPGt_char,&(sql_a_f1),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 110 "Fragen.pgc"

        }

        if (new_a_f2 != ""){
            sql_a_f2 = new_a_f2.c_str();
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fragen set antwort_f2 = $1  where f_id = $2 ", 
	ECPGt_char,&(sql_a_f2),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 115 "Fragen.pgc"

        }

        if (new_a_f3 != ""){
            sql_a_f3 = new_a_f3.c_str();
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fragen set antwort_f3 = $1  where f_id = $2 ", 
	ECPGt_char,&(sql_a_f3),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 120 "Fragen.pgc"

        }

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 123 "Fragen.pgc"

    }
};

void Fragen::entfernen(){
	int id;
	string temp;
	while (temp[0] != '0'){
        listAll();
        cout << "\n\nWelche Frage wollen Sie entfernen? \n(0)\tAbbrechen\n(<ID>)\t Entfernen\n";
        getline(cin, temp);
        istringstream ss(temp);
        ss >> id;
        if(id == 0){
            break;
        }

        cout << "Zu entfernende Frage:\t" << endl;
        if(read(id)){
            cout << "Wollen Sie diese Frage wirklich entfernen?\n(1)\tJa\n(0)\tNein\n";
            getline(cin, temp);

            if(temp == "1"){
              /* exec sql begin declare section */
                     
              
#line 147 "Fragen.pgc"
 long del_id ;
/* exec sql end declare section */
#line 148 "Fragen.pgc"

              del_id = id;

              { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from fragen where f_id = $1 ", 
	ECPGt_long,&(del_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 151 "Fragen.pgc"

              { ECPGtrans(__LINE__, NULL, "commit");}
#line 152 "Fragen.pgc"

            }
        }
	}
};

void Fragen::listAll(){
 struct frage {         /* deklariert den Strukturtyp person */
    int id;
    char wb[256];
    char frage[256];
  };

  string temp = "";
  int anz_fragen = 20;


  frage fragen[1000];

	/* exec sql begin declare section */
		 
		 
		 
		 
	
#line 172 "Fragen.pgc"
 char fr [ 256 ] ;
 
#line 173 "Fragen.pgc"
 char a_f3 [ 256 ] ;
 
#line 174 "Fragen.pgc"
 char wb [ 256 ] ;
 
#line 175 "Fragen.pgc"
 long current_id ;
/* exec sql end declare section */
#line 176 "Fragen.pgc"

    cout << "Wissensbereich\tID\tFrage\n"<<endl;


    //select all Fragen
    /* declare cur cursor for select w . w_name , f . f_id , f . frage from fragen f , wissensbereich w where w . w_id = f . w_id order by w . w_name , f . f_id */
#line 181 "Fragen.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur cursor for select w . w_name , f . f_id , f . frage from fragen f , wissensbereich w where w . w_id = f . w_id order by w . w_name , f . f_id", ECPGt_EOIT, ECPGt_EORT);}
#line 182 "Fragen.pgc"

    /* exec sql whenever not found  call setEnd ( 1 ) ; */
#line 183 "Fragen.pgc"


    setEnd(false);
   while(1){

    //printf("%s\t%ld\t%s\n", wb, current_id, fr);
    for(int i = 0; i<anz_fragen; i++){
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in cur", ECPGt_EOIT, 
	ECPGt_char,(wb),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(current_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fr),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 190 "Fragen.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) setEnd ( 1 );}
#line 190 "Fragen.pgc"

        if(!getEnd()){
            printf("%s\t%ld\t%s\n", wb, current_id, fr);
        }

       // fragen[counter].id=current_id;
       // fragen[counter].wb=wb;
    //fragen[counter].frage=fr;
    }
    if(getEnd()){
        break;
    }
    cout << "\n<Enter>\tWeitere Fragen\n(0)\tZur Auswahl" << endl;
    getline(cin, temp);
    if(temp == "0"){
        break;
    }
   }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur", ECPGt_EOIT, ECPGt_EORT);}
#line 209 "Fragen.pgc"

}

void Fragen::menu(){
    string antwort_fr = "1";


    while (antwort_fr[0] != '0'){
        //listAll();
        cout << "\n\nWelche Aktion wollen Sie durchfuehren?\n(1)\tNeue Frage eintragen\n(2)\tFrage bearbeiten\n(3)\tFrage entfernen\n(4)\tFrage anzeigen\n(0)\tBeenden\n\n" <<endl;
        getline(cin,antwort_fr);

        if(antwort_fr.length() < 2){
            switch(antwort_fr[0]){
              case '1':
                   createFrage();
              break;
                case '2': createUpdate();break;
                case '3': entfernen(); break;
                case '4': anzeigen(); break;
                case '0':break;
                default : cout << "Fehlerhafte Eingabe" << endl;
            }
        } else {
            cout << "Fehlerhafte Eingabe" << endl;
        }
    }
}

void Fragen::createFrage(){

    Wissensbereiche wib;

    string sql_frage;
    string sql_a_r;
    string sql_a_f1;
    string sql_a_f2;
    string sql_a_f3;
    string temp;
    int sql_wb;

    wib.listAll();

    cout << "\n\nZu welchem Wissensbereich wollen Sie eine Frage erstellen? \n(0)\tAbbrechen\n(<ID>)\t Auswählen\n";
    getline(cin,temp);

    if(temp[0] != '0') {
        istringstream ss(temp);
        ss >> sql_wb;


        if(wib.read(sql_wb)) {

            cout << "Frage: ";
            getline(cin,sql_frage);

            cout << "Richtige Antwort: ";
            getline(cin,sql_a_r);

            cout << "1. Falsche Antwort: ";
            getline(cin,sql_a_f1);

            cout << "2. Falsche Antwort: ";
            getline(cin,sql_a_f2);

            cout << "3. Falsche Antwort: ";
            getline(cin,sql_a_f3);

            setFrage(sql_frage.c_str(), sql_a_r.c_str(), sql_a_f1.c_str(), sql_a_f2.c_str(), sql_a_f3.c_str(), sql_wb);
        }
    }
};

void Fragen::createUpdate(){
    string antwort_up = "1";
    int id;
    while (antwort_up[0] != '0'){
        listAll();
        cout << "\n\nWelche Frage wollen Sie bearbeiten? \n(0)\tAbbrechen\n(<ID>)\t Bearbeiten\n" <<endl;
        getline(cin,antwort_up);
            if(antwort_up[0] == '0') {
                break;
            }
            istringstream ss(antwort_up);
            ss >> id;
            update(id);
    }
};

void Fragen::anzeigen(){
    string antwort_up = "1";
    int id;
    while (antwort_up[0] != '0'){
        listAll();
        cout << "\n\nWelche Frage wollen Sie anzeigen lassen? \n(0)\tAbbrechen\n(<ID>)\t Anzeigen\n" <<endl;
        getline(cin,antwort_up);
        if(antwort_up[0] == '0') {
            break;
        }

        if(antwort_up == ""){
            cout << "Fehlerhafte Eingabe" << endl;
        } else{
            istringstream ss(antwort_up);
            ss >> id;
            read(id);
        }

    }
}

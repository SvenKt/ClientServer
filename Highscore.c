/* Processed by ecpg (4.9.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "Highscore.pgc"
#include "Highscore.h"


    //sample code working for where statement
    //EXEC SQL SELECT w_name INTO :name FROM wissensbereich WHERE w_id=1;
    //printf("%s\n", name);


void Highscore::setHighscore(const char* new_h_name,long new_score){

	/* exec sql begin declare section */
          
         
         
	
#line 12 "Highscore.pgc"
 const char * insertname ;
 
#line 13 "Highscore.pgc"
 long insertscore ;
 
#line 14 "Highscore.pgc"
 int insertid ;
/* exec sql end declare section */
#line 15 "Highscore.pgc"


	insertname = new_h_name;
    insertscore = new_score;

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( h_id ) from highscore", ECPGt_EOIT, 
	ECPGt_int,&(insertid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 20 "Highscore.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into highscore values ( $1  + 1 , $2  , $3  )", 
	ECPGt_int,&(insertid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(insertname),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(insertscore),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 21 "Highscore.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 22 "Highscore.pgc"

};

bool Highscore::read(int p_id) {

	/* exec sql begin declare section */
	 
	 
	 
	
#line 28 "Highscore.pgc"
 long sql_id ;
 
#line 29 "Highscore.pgc"
 char sql_name [ 256 ] ;
 
#line 30 "Highscore.pgc"
 long sql_score ;
/* exec sql end declare section */
#line 31 "Highscore.pgc"

	sql_id = p_id;
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select h_name , score from highscore where h_id = $1 ", 
	ECPGt_long,&(sql_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(sql_name),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(sql_score),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 33 "Highscore.pgc"


    if (sqlca.sqlcode == 100){
        cout << "Fehler, keine solche ID vorhanden" << endl;
        return false;
    } else{
    	cout << "\n" << p_id << "\t" << sql_name << "\t" << sql_score << "\t\n" << endl;
        return true;
    }


};

void Highscore::update(int temp_id){

    string new_name;
    string temp_score;
    long new_score;


    if (read(temp_id)){
        cout << "Geben Sie den neuen Namen ein: "<< endl;
        getline(cin,new_name);



        cout << "Geben Sie die neuen Highscore ein: "<< endl;
        getline(cin, temp_score);
        istringstream ss(temp_score);
        ss >> new_score;


        /* exec sql begin declare section */
         
           
         
        
#line 66 "Highscore.pgc"
 int sql_id ;
 
#line 67 "Highscore.pgc"
 const char * sql_new_name ;
 
#line 68 "Highscore.pgc"
 long sql_new_score ;
/* exec sql end declare section */
#line 69 "Highscore.pgc"

        sql_id = temp_id;
        sql_new_name = new_name.c_str();
        sql_new_score = new_score;

         if(new_name != ""){
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update highscore set h_name = $1  where h_id = $2 ", 
	ECPGt_char,&(sql_new_name),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 75 "Highscore.pgc"

        }
        if (new_score){
            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update score set score = $1  where h_id = $2 ", 
	ECPGt_long,&(sql_new_score),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 78 "Highscore.pgc"

        }

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 81 "Highscore.pgc"

    }
};

void Highscore::entfernen(){
	string temp;
	while (temp[0] != '0'){
        listAll();
        cout << "\n\nWelchen Highscore wollen Sie entfernen? \n(0)\tAbbrechen\n(<ID>)\t Entfernen\n";
        getline(cin, temp);
        istringstream ss(temp);
        ss >> id;
        if(id == 0){
            break;
        }

        cout << "Zu entfernender Highscore:\t" << endl;
        if(read(id)){
            cout << "Wollen Sie diesen Highscore wirklich entfernen?\n(1)\tJa\n(0)\tNein\n";
            getline(cin, temp);

            if(temp == "1"){
              /* exec sql begin declare section */
                     
              
#line 104 "Highscore.pgc"
 int del_id ;
/* exec sql end declare section */
#line 105 "Highscore.pgc"

              del_id = id;

              { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from highscore where h_id = $1 ", 
	ECPGt_int,&(del_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 108 "Highscore.pgc"

              { ECPGtrans(__LINE__, NULL, "commit");}
#line 109 "Highscore.pgc"

            }
        }
	}

};

void Highscore::listAll(){

	/* exec sql begin declare section */
		 
		 
		 
		 
	
#line 119 "Highscore.pgc"
 char h_name [ 256 ] ;
 
#line 120 "Highscore.pgc"
 long score ;
 
#line 121 "Highscore.pgc"
 long current_id ;
 
#line 122 "Highscore.pgc"
 int counter ;
/* exec sql end declare section */
#line 123 "Highscore.pgc"

    cout << "ID\tName\tHighscore\n"<<endl;


    //select all wissensbereiche
    /* declare cur cursor for select h_name , score , h_id from highscore order by h_id */
#line 128 "Highscore.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur cursor for select h_name , score , h_id from highscore order by h_id", ECPGt_EOIT, ECPGt_EORT);}
#line 129 "Highscore.pgc"

    /* exec sql whenever not found  break ; */
#line 130 "Highscore.pgc"


   while(1){
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in cur", ECPGt_EOIT, 
	ECPGt_char,(h_name),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(score),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(current_id),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 133 "Highscore.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 133 "Highscore.pgc"

    printf("%ld\t%s\t%ld\n", current_id,h_name,score);
   }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur", ECPGt_EOIT, ECPGt_EORT);}
#line 137 "Highscore.pgc"

}

void Highscore::menu(){
    string antwort_h = "1";


    while (antwort_h[0] != '0'){
        listAll();
        cout << "\n\nWelche Aktion wollen Sie durchfuehren?\n(1)\tNeuen Highscore eintragen\n(2)\tHighscore bearbeiten\n(3)\tHighscore entfernen\n(0)\tBeenden\n\n" <<endl;
        getline(cin,antwort_h);

        if(antwort_h.length() < 2){
            switch(antwort_h[0]){
              case '1':
                   createHighscore();
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

void Highscore::createHighscore(){
    cout << "Name: ";
    getline(cin,sql_name);
    cout << "Highscore: ";
    getline(cin, sql_score);
    istringstream ss(sql_score);
    long temp_score;
    ss >> temp_score;
    setHighscore(sql_name.c_str(), temp_score);
}

void Highscore::createUpdate(){
string antwort_up = "1";
    while (antwort_up[0] != '0'){
        listAll();
        cout << "\n\nWelchen Highscore wollen Sie bearbeiten? \n(0)\tAbbrechen\n(<ID>)\t Bearbeiten\n" <<endl;
        getline(cin,antwort_up);
            if(antwort_up[0] == '0') {
                break;
            }
            istringstream ss(antwort_up);
            ss >> id;
            update(id);
    }
}

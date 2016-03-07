#include "Wissensbereiche.h"


    //sample code working for where statement
    //EXEC SQL SELECT w_name INTO :name FROM wissensbereich WHERE w_id=1;
    //printf("%s\n", name);


void Wissensbereiche::setWissensbereich(const char* new_name,const char* new_beschreibung){

	EXEC SQL BEGIN DECLARE SECTION;
        const char* insertname;
        const char* insertbeschr;
        int insertid;
	EXEC SQL END DECLARE SECTION;

	insertname = new_name;
    insertbeschr = new_beschreibung;

    EXEC SQL SELECT MAX(w_id) INTO :insertid FROM wissensbereich;
	EXEC SQL INSERT INTO wissensbereich VALUES (:insertid+1, :insertname, :insertbeschr);
	EXEC SQL COMMIT;
};

bool Wissensbereiche::read(int p_id) {

	EXEC SQL BEGIN DECLARE SECTION;
	long sql_id;
	char name[256];
	char beschreibung[256];
	EXEC SQL END DECLARE SECTION;
	sql_id = p_id;
	EXEC SQL SELECT w_name, w_beschreibung INTO :name, :beschreibung FROM wissensbereich WHERE w_id = :sql_id;

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
        cout << "Geben Sie den neuen Namen ein: "<< endl;
        getline(cin,new_name);



        cout << "Geben Sie die neue Beschreibung ein: "<< endl;
        getline(cin, new_desc);




        EXEC SQL BEGIN DECLARE SECTION;
        int sql_id;
        const char*  sql_new_name;
        const char* sql_new_beschreibung;
        EXEC SQL END DECLARE SECTION;

        sql_id = temp_id;
        sql_new_name = new_name.c_str();
        sql_new_beschreibung = new_desc.c_str();

         if(new_name != ""){
            EXEC SQL UPDATE wissensbereich SET w_name = :sql_new_name WHERE w_id = :sql_id;
        }
        if (new_desc != ""){
            EXEC SQL UPDATE wissensbereich SET w_beschreibung = :sql_new_beschreibung WHERE w_id = :sql_id;
        }

        EXEC SQL COMMIT;
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
              EXEC SQL BEGIN DECLARE SECTION;
                    int del_id;
              EXEC SQL END DECLARE SECTION;
              del_id = id;

              EXEC SQL DELETE FROM wissensbereich WHERE w_id=:del_id;
              EXEC SQL COMMIT;
            }
        }
	}

};

void Wissensbereiche::listAll(){

	EXEC SQL BEGIN DECLARE SECTION;
		char name[256];
		char beschr[256];
		long current_id;
		int counter;
	EXEC SQL END DECLARE SECTION;
    cout << "ID\tName\tBeschreibung\n"<<endl;


    //select all wissensbereiche
    EXEC SQL DECLARE cur CURSOR FOR SELECT w_name, w_beschreibung, w_id FROM wissensbereich ORDER BY w_id;
    EXEC SQL OPEN cur;
    EXEC SQL WHENEVER NOT FOUND DO BREAK;

   while(1){
    EXEC SQL FETCH IN cur INTO :name, :beschr, :current_id;
    printf("%ld\t%s\t%s\n", current_id,name,beschr);
   }

    EXEC SQL CLOSE cur;
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


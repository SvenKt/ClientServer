#include "Highscore.h"


    //sample code working for where statement
    //EXEC SQL SELECT w_name INTO :name FROM wissensbereich WHERE w_id=1;
    //printf("%s\n", name);


void Highscore::setHighscore(const char* new_h_name,long new_score){

	EXEC SQL BEGIN DECLARE SECTION;
        const char* insertname;
        long insertscore;
        int insertid;
	EXEC SQL END DECLARE SECTION;

	insertname = new_h_name;
    insertscore = new_score;

    EXEC SQL SELECT MAX(h_id) INTO :insertid FROM highscore;
	EXEC SQL INSERT INTO highscore VALUES (:insertid+1, :insertname, :insertscore);
	EXEC SQL COMMIT;
};

bool Highscore::read(int p_id) {

	EXEC SQL BEGIN DECLARE SECTION;
	long sql_id;
	char sql_name[256];
	long sql_score;
	EXEC SQL END DECLARE SECTION;
	sql_id = p_id;
	EXEC SQL SELECT h_name, score INTO :sql_name, :sql_score FROM highscore WHERE h_id = :sql_id;

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

        EXEC SQL BEGIN DECLARE SECTION;
        int sql_id;
        const char*  sql_new_name;
        long sql_new_score;
        EXEC SQL END DECLARE SECTION;
        sql_id = temp_id;
        sql_new_name = new_name.c_str();
        sql_new_score = new_score;


         if(new_name != ""){
            EXEC SQL UPDATE highscore SET h_name = :sql_new_name WHERE h_id = :sql_id;
        }
        if (temp_score != ""){

            EXEC SQL UPDATE highscore SET score = :sql_new_score WHERE h_id = :sql_id;
        }

        EXEC SQL COMMIT;
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
              EXEC SQL BEGIN DECLARE SECTION;
                    int del_id;
              EXEC SQL END DECLARE SECTION;
              del_id = id;

              EXEC SQL DELETE FROM highscore WHERE h_id=:del_id;
              EXEC SQL COMMIT;
            }
        }
	}

};

void Highscore::listAll(){

	EXEC SQL BEGIN DECLARE SECTION;
		char h_name[256];
		long score;
		long current_id;
		int counter;
	EXEC SQL END DECLARE SECTION;
    cout << "ID\tPunkte\tName\n"<<endl;


    //select all wissensbereiche
    EXEC SQL DECLARE cur CURSOR FOR SELECT h_name, score, h_id FROM highscore ORDER BY score DESC;
    EXEC SQL OPEN cur;
    EXEC SQL WHENEVER NOT FOUND DO BREAK;

   while(1){
    EXEC SQL FETCH IN cur INTO :h_name, :score, :current_id;
    printf("%ld\t%ld\t%s\n", current_id,score, h_name);
   }

    EXEC SQL CLOSE cur;
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

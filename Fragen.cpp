
#include "Wissensbereiche.h"
#include "Fragen.h"

    //sample code working for where statement
    //EXEC SQL SELECT w_name INTO :name FROM wissensbereich WHERE w_id=1;
    //printf("%s\n", name);


void Fragen::setFrage(const char* new_frage, const char* new_antwort_r, const char* new_antwort_f1, const char* new_antwort_f2,
                        const char* new_antwort_f3,int wissensbereich){

	EXEC SQL BEGIN DECLARE SECTION;
        const char* fr;
        const char* a_r;
        const char* a_f1;
        const char* a_f2;
        const char* a_f3;
        int wb;
        int id;
	EXEC SQL END DECLARE SECTION;

	fr = new_frage;
    a_r = new_antwort_r;
    a_f1 = new_antwort_f1;
    a_f2 = new_antwort_f2;
    a_f3 = new_antwort_f3;
    wb = wissensbereich;

    EXEC SQL SELECT MAX(f_id) INTO :id FROM fragen;
	EXEC SQL INSERT INTO fragen VALUES (:id+1, :wb, :fr, :a_r, :a_f1, :a_f2, :a_f3);
	EXEC SQL COMMIT;


};

bool Fragen::read(int p_id) {
	EXEC SQL BEGIN DECLARE SECTION;
	long sql_id;
	long sql_wb;
	char wissensbereich[256];
	char fr[256];
	char a_r[256];
	char a_f1[256];
	char a_f2[256];
	char a_f3[256];
	EXEC SQL END DECLARE SECTION;
	sql_id = p_id;
	EXEC SQL SELECT w_id, frage, antwort_r, antwort_f1, antwort_f2, antwort_f3 INTO :sql_wb, :fr, :a_r, :a_f1, :a_f2, :a_f3 FROM fragen WHERE f_id = :sql_id;
    EXEC SQL SELECT w_name INTO :wissensbereich FROM wissensbereich WHERE w_id = :sql_wb;

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

        EXEC SQL BEGIN DECLARE SECTION;
            int sql_id;
            int sql_wb;
            const char* sql_fr;
            const char* sql_a_r;
            const char* sql_a_f1;
            const char* sql_a_f2;
            const char* sql_a_f3;
        EXEC SQL END DECLARE SECTION;

        sql_id = temp_id;
        sql_wb = new_wb;

        if(new_fr != ""){
            sql_fr = new_fr.c_str();
            EXEC SQL UPDATE fragen SET frage = :sql_fr WHERE f_id = :sql_id;
        }

        if (new_a_r != ""){
            sql_a_r = new_a_r.c_str();
            EXEC SQL UPDATE fragen SET antwort_r = :sql_a_r WHERE f_id = :sql_id;
        }

        if (new_a_f1 != ""){
            sql_a_f1 = new_a_f1.c_str();
            EXEC SQL UPDATE fragen SET antwort_f1 = :sql_a_f1 WHERE f_id = :sql_id;
        }

        if (new_a_f2 != ""){
            sql_a_f2 = new_a_f2.c_str();
            EXEC SQL UPDATE fragen SET antwort_f2 = :sql_a_f2 WHERE f_id = :sql_id;
        }

        if (new_a_f3 != ""){
            sql_a_f3 = new_a_f3.c_str();
            EXEC SQL UPDATE fragen SET antwort_f3 = :sql_a_f3 WHERE f_id = :sql_id;
        }

        EXEC SQL COMMIT;
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
              EXEC SQL BEGIN DECLARE SECTION;
                    long del_id;
              EXEC SQL END DECLARE SECTION;
              del_id = id;

              EXEC SQL DELETE FROM fragen WHERE f_id=:del_id;
              EXEC SQL COMMIT;
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

	EXEC SQL BEGIN DECLARE SECTION;
		char fr[256];
		char a_f3[256];
		char wb[256];
		long current_id;
	EXEC SQL END DECLARE SECTION;
    cout << "Wissensbereich\tID\tFrage\n"<<endl;


    //select all Fragen
    EXEC SQL DECLARE cur CURSOR FOR SELECT w.w_name, f.f_id, f.frage FROM fragen f, wissensbereich w WHERE w.w_id = f.w_id ORDER BY w.w_name, f.f_id;
    EXEC SQL OPEN cur;
    EXEC SQL WHENEVER NOT FOUND CALL setEnd(1);

    setEnd(false);
   while(1){

    //printf("%s\t%ld\t%s\n", wb, current_id, fr);
    for(int i = 0; i<anz_fragen; i++){
        EXEC SQL FETCH IN cur INTO :wb, :current_id, :fr;
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

    EXEC SQL CLOSE cur;
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

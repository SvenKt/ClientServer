
cp InsertClient.cpp InsertClient.pgc;
cp Wissensbereiche.cpp Wissensbereiche.pgc; 
cp Fragen.cpp Fragen.pgc;
cp Highscore.cpp Highscore.pgc
ecpg *.pgc; 
g++ -I /usr/include/postgresql -c InsertClient.c Wissensbereiche.c Fragen.c Highscore.c;
g++ -o main *.o -L/usr/lib/psql -lecpg;
./main

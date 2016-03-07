
cp InsertClient.cpp InsertClient.pgc;
cp Wissensbereiche.cpp Wissensbereiche.pgc; 
ecpg *.pgc; 
g++ -I /usr/include/postgresql -c InsertClient.c Wissensbereiche.c ;
g++ -o main *.o -L/usr/lib/psql -lecpg;
./main

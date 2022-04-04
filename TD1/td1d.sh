cd ..;
arm-linux-g++ -Wall -Wextra TD1/src/main_td1d.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD1/TD1_D -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD1/;
chmod +x TD1_D;

scp TD1_D root@192.168.50.46:
rm TD1_D
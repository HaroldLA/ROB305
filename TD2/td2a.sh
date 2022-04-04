cd ..;
arm-linux-g++ -Wall -Wextra TD2/src/main_td2a.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD2/TD2_A -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD2/;
chmod +x TD2_A;

scp TD2_A root@192.168.50.46:
rm TD2_A
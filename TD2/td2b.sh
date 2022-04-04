cd ..;
arm-linux-g++ -Wall -Wextra TD2/src/main_td2b.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD2/TD2_B -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD2;
chmod +x TD2_B;

scp TD2_B root@192.168.50.46:
rm TD2_B
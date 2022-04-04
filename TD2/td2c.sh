cd ..;
arm-linux-g++ -Wall -Wextra TD2/src/main_td2c.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD2/TD2_C -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD2;
chmod +x TD2_C;

scp TD2_C root@192.168.50.46:
rm TD2_C
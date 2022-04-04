cd ..;
arm-linux-g++ -Wno-psabi -Wall -Wextra TD3/src/main_td3a.cpp Time_Lib/src/Fonctions.cpp TD3/src/Chrono/Chrono.cpp -o TD3/TD3_A -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD3/;
chmod +x TD3_A;

scp TD3_A root@192.168.50.46:
rm TD3_A
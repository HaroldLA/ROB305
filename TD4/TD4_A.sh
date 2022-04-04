cd ..;
arm-linux-g++ -Wall -Wextra TD4/src/main_td4a.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/CountThread/CountThread.cpp -o TD4/TD4_A -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD4/;
chmod +x TD4_A;

scp TD4_A root@192.168.50.46:
rm TD4_A
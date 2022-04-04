cd ..;
arm-linux-g++ -Wall -Wextra TD4/src/main_td4b.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/Mutex/Mutex.cpp TD4/src/Monitor/Monitor.cpp TD4/src/Lock/Lock.cpp TD4/src/CountMutex/CountMutex.cpp -o TD4/TD4_B -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD4/;
chmod +x TD4_B;

scp TD4_B root@192.168.50.46:
rm TD4_B
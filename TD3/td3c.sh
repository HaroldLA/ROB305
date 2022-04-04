cd ..;
arm-linux-g++ -Wno-psabi -Wall -Wextra TD3/src/main_td3c.cpp Time_Lib/src/Fonctions.cpp TD3/src/Chrono/Chrono.cpp TD3/src/PeriodicTimer/PeriodicTimer.cpp TD3/src/Timer/Timer.cpp TD3/src/Looper/Looper.cpp TD3/src/CpuLoop/CpuLoop.cpp TD3/src/Calibrator/Calibrator.cpp -o TD3/TD3_C -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD3/;
chmod +x TD3_C;

scp TD3_C root@192.168.50.46:
rm TD3_C
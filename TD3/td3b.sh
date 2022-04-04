cd ..;
arm-linux-g++ -Wno-psabi -Wall -Wextra TD3/src/main_td3b.cpp Time_Lib/src/Fonctions.cpp TD3/src/PeriodicTimer/PeriodicTimer.cpp TD3/src/Timer/Timer.cpp TD3/src/CountDown/CountDown.cpp -o TD3/TD3_B -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD3/;
chmod +x TD3_B;

scp TD3_B root@192.168.50.46:
rm TD3_B
cd ..;
arm-linux-g++ -Wall -Wextra TD4/src/main_td4c.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/Mutex/Mutex.cpp TD4/src/Monitor/Monitor.cpp TD4/src/Lock/Lock.cpp TD4/src/Semaphore/Semaphore.cpp TD4/src/SemaphoreConsumer/SemaphoreConsumer.cpp TD4/src/SemaphoreProducer/SemaphoreProducer.cpp -o TD4/TD4_C -lrt -lpthread;
if [ "$?" != "0" ]; then exit; fi; 
cd TD4/;
chmod +x TD4_C;

scp TD4_C root@192.168.50.46:
rm TD4_C
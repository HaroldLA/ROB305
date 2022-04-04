# [TD-4] Classes de base pour la programmation multitâches

* Author: Harold Exinover LOZANO ARIAS

## a)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:
arm-linux-g++ -Wall -Wextra TD4/src/main_td4a.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/CountThread/CountThread.cpp -o TD4/TD4_A -lrt -lpthread;
Or:
chmod +x td4a.sh
./td4a.sh
```

2. Execute Raspberry:

```bash
./TD4_A
```

## b)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:
arm-linux-g++ -Wall -Wextra TD4/src/main_td4b.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/Mutex/Mutex.cpp TD4/src/Monitor/Monitor.cpp TD4/src/Lock/Lock.cpp TD4/src/CountMutex/CountMutex.cpp -o TD4/TD4_B -lrt -lpthread;
Or:
chmod +x td4b.sh
./td4b.sh
```

2. Execute Raspberry:

```bash
./TD4_B
```


## c)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:
arm-linux-g++ -Wall -Wextra TD4/src/main_td4c.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/Mutex/Mutex.cpp TD4/src/Monitor/Monitor.cpp TD4/src/Lock/Lock.cpp TD4/src/Semaphore/Semaphore.cpp TD4/src/SemaphoreConsumer/SemaphoreConsumer.cpp TD4/src/SemaphoreProducer/SemaphoreProducer.cpp -o TD4/TD4_C -lrt -lpthread;
Or:
chmod +x td4c.sh
./td4c.sh
```

2. Execute Raspberry:

```bash
./TD4_C
```

## d)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:
arm-linux-g++ -Wall -Wextra TD4/src/main_td4d.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp TD3/src/Chrono/Chrono.cpp TD4/src/PosixThread/PosixThread.cpp TD4/src/Thread/Thread.cpp TD4/src/Mutex/Mutex.cpp TD4/src/Monitor/Monitor.cpp TD4/src/Lock/Lock.cpp -o TD4/TD4_D -lrt -lpthread;
Or:
chmod +x td4d.sh
./td4d.sh
```

2. Execute Raspberry:

```bash
./TD4_D
```

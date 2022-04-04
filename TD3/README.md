# [TD-3] Classes pour la gestion du temps

* Author: Harold Exinover LOZANO ARIAS

## a)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wno-psabi -Wall -Wextra TD3/src/main_td3a.cpp Time_Lib/src/Fonctions.cpp TD3/src/Chrono/Chrono.cpp -o TD3/TD3_A -lrt -lpthread;

Or:

chmod +x td3a.sh
./td3a.sh
```

2. Execute Raspberry:

```bash
./TD3_A
```

## b)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wno-psabi -Wall -Wextra TD3/src/main_td3b.cpp Time_Lib/src/Fonctions.cpp TD3/src/PeriodicTimer/PeriodicTimer.cpp TD3/src/Timer/Timer.cpp TD3/src/CountDown/CountDown.cpp -o TD3/TD3_B -lrt -lpthread;

Or:

chmod +x td3b.sh
./td3b.sh
```

2. Execute Raspberry:

```bash
./TD3_B
```


## c)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wno-psabi -Wall -Wextra TD3/src/main_td3c.cpp Time_Lib/src/Fonctions.cpp TD3/src/Chrono/Chrono.cpp TD3/src/PeriodicTimer/PeriodicTimer.cpp TD3/src/Timer/Timer.cpp TD3/src/Looper/Looper.cpp TD3/src/CpuLoop/CpuLoop.cpp TD3/src/Calibrator/Calibrator.cpp -o TD3/TD3_C -lrt -lpthread;

Or:

chmod +x td3c.sh
./td3c.sh
```

2. Execute Raspberry:

```bash
./TD3_C
```



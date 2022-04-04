# [TD-1] Mesure de temps et échantillonnage en temps

* Author: Harold Exinover LOZANO ARIAS

## a)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wall -Wextra TD1/src/main_td1a.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD1/TD1_A -lrt -lpthread;

Or:

chmod +x td1a.sh
./td1a.sh
```

2. Execute Raspberry:

```bash
./TD1_A
```

## b)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wall -Wextra TD1/src/main_td1b.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD1/TD1_B -lrt -lpthread;

Or:

chmod +x td1b.sh
./td1b.sh
```

2. Execute Raspberry:

```bash
./TD1_B
```


## c)
1. Compile:

```bash
It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wall -Wextra TD1/src/main_td1c.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD1/TD1_C -lrt -lpthread;

Or:

chmod +x td1c.sh
./td1c.sh
```

2. Execute Raspberry:

```bash
./TD1_C
```


## d)
1. Compile:

```bash
* Without the calib() function:

It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wall -Wextra TD1/src/main_td1d.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD1/TD1_D -lrt -lpthread;

Or:

chmod +x td1d.sh
./td1d.sh

* With the calib() function:

It is possible to execute the next line in the ROB305 directory:

arm-linux-g++ -Wall -Wextra TD1/src/main_td1d_1.cpp Time_Lib/src/Fonctions.cpp Time_Lib/src/Operateurs.cpp -o TD1/TD1_D1 -lrt -lpthread;

Or:

chmod +x td1d_1.sh
./td1d_1.sh
```

2. Execute Raspberry:

```bash
* Without the calib() function:
 
./TD1_D

* With the calib() function:

./TD1_D1
```
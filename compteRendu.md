# TD N°3 Processus

## 1 Créations multiples

#### Exercice N°1
```
[robin@robin-recoil3gtx15 td03]$ ./multiple_fork.exe 
fils n°0
fils n°0
fils n°0
fils n°0
fils n°0
fils n°0
fils n°0
fils n°0
fils n°0
fils n°0
fils n°1
fils n°1
fils n°1
fils n°1
fils n°1
fils n°1
fils n°1
fils n°1
fils n°1
fils n°1
[...]
fils n°9
fils n°9
fils n°9
fils n°9
fils n°9
fils n°9
fils n°9
fils n°9
fils n°9
fils n°9
[robin@robin-recoil3gtx15 td03]$ ./multiple_fork.exe | wc -l
100
```

#### Exercice 2

les pid des P processus sont 16198 16199 16200 16201 16202 16203 16204 16205 16206 16207 16240
On peut en conclure que le pid du processus père est 16240.

## Fin de vie de  processus

### Zombie

#### Exercice 3

On observe un "Z+" et un "\<defunct>" sur le processus zombie

```
[robin@robin-recoil3gtx15 td03]$ ps aux | grep zombie.exe 
robin      19445  0.0  0.0   2504   912 pts/1    S+   11:21   0:00 ./zombie.exe
robin      19446  0.0  0.0      0     0 pts/1    Z+   11:21   0:00 [zombie.exe] <defunct>
robin      19456  0.0  0.0   6692  2680 pts/2    S+   11:21   0:00 grep zombie.exe
```
### Orphelin

#### Exercice 4

output du processus pid 1 dans ps aux, il s'agit du processu init.

```
[robin@robin-recoil3gtx15 td03]$ ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0 185336  5948 ?        Ss   09:37   0:01 /sbin/init splash
```

## Propriétés des primitives de la famille execXX()

#### Exercice 5

Avec fork() on peut constater que le buffer de sortie est bien le même car l'affichage dans la console de deux messages sur deux threads différents s'effectue simultanément lors du flush du buffer par un 
```c 
printf("\n");
```

ce qui donne l'output suivant :
```
[robin@robin-recoil3gtx15 td03]$ ./exec_prop.exe 
Child : 28912, Father : 28911
```
On constate aussi que leur pid sont différents.

l'exécution suite à l'implémentation de la fonction execlp produit le résultat suivant : 

```
[robin@robin-recoil3gtx15 td03]$  ./exec_prop.exe 
Child : 30529, Father : 30528
exec call pid : 30528, argv[0] : exec_prop-aux
```

## Le Shell et la fonction system()

### Principe d'exécution du Shell

Exercice 6

Grâce à deux appels à execlp dans respectivement un processus père et un processus fils il est possible de lancer les commandes comme dans le shell.

```
$ ./shell_exec.exe 
aitelec  tty2         2022-03-01 09:38 (:1)
aitelec  pts/3        2022-03-01 12:42 (:1.0)
compteRendu.md     multiple_fork.exe
exec_prop-aux.c    orphan.c
exec_prop-aux.exe  orphan.exe
exec_prop.c        README.md
exec_prop.exe      secret_file.txt
fcat.c             shell_exec.c
fcat.exe           shell_exec.exe
Makefile           zombie.c
multiple_fork.c    zombie.exe
```

#### Exercice 7

j'ai rajouté un 
```c
switch(fork())
```
afin de prendre en compte la troisième commande. J'ai ainsi obtenu l'output suivant : 

```
[robin@RG-Recoil-III-GTX td03]$ ./shell_exec.exe 
compteRendu.md   exec_prop-aux.exe  exec_prop.exe  fcat.exe  multiple_fork.c    orphan.c    README.md        shell_exec.c    shell_system.c    TESTSAVE  zombie.exe
exec_prop-aux.c  exec_prop.c        fcat.c         Makefile  multiple_fork.exe  orphan.exe  secret_file.txt  shell_exec.exe  shell_system.exe  zombie.c
robin    tty1         2022-02-28 23:51 (:0)
```
On remarque que le dossier affiché n'est pas ~ car la commande cd est exécutée dans un autre processus.

### Extension de shell_exec

Malheureusement pas fini mon prompt apparaît correctement mais la commande que je passe en scanf s'exécute en boucle lorsque j'appuie sur enter :/
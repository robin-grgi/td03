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
fils n°2
fils n°2
fils n°2
fils n°2
fils n°2
fils n°2
fils n°2
fils n°2
fils n°2
fils n°2
fils n°3
fils n°3
fils n°3
fils n°3
fils n°3
fils n°3
fils n°3
fils n°3
fils n°3
fils n°3
fils n°4
fils n°4
fils n°4
fils n°4
fils n°4
fils n°4
fils n°4
fils n°4
fils n°4
fils n°4
fils n°5
fils n°5
fils n°5
fils n°5
fils n°5
fils n°5
fils n°5
fils n°5
fils n°5
fils n°5
fils n°6
fils n°6
fils n°6
fils n°6
fils n°6
fils n°6
fils n°6
fils n°6
fils n°6
fils n°6
fils n°7
fils n°7
fils n°7
fils n°7
fils n°7
fils n°7
fils n°7
fils n°7
fils n°7
fils n°7
fils n°8
fils n°8
fils n°8
fils n°8
fils n°8
fils n°8
fils n°8
fils n°8
fils n°8
fils n°8
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

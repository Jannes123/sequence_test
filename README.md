## Sequence code test

Very simple c program to run and build use the following on the individual folders.

```bash
cmake . -B build/
cd build/
make
./Collies 100000000

```


Example output program two
---

```
/build-12:55>./Collies 

 Enter the value of the upper limit : 40000

 40000 

Calculating Collatz: 

empirical guess of lower limit with longest sequence chain : 24000 
largest value in sequence :  41163712 
start :  35655 
steps :  323 

Finished. 
Longest sequence is : 323 
```

Example output program one
---
```
build-13:45>./Collies 

Enter the value of the upper limit : 76543210
Calculating Collatz: 
---
empirical guess at lowest value : 45925924 
Answer: start value of longest sequence : 63728127
Finished. 
Longest sequence is : 949 steps.

```

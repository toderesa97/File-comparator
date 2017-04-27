# micmp

This program compares two or more files to determine whether they are equal or not. The program is made in C and it's ideal for terminal use. The program can do:
  1. Compare two files and retrieve whether they're equal or not.
  2. Compare two files from different shifts.
  3. Compare two files showing in a table the differences between the files (ASCII)

## Syntax

First of all what we need it's to compile micmp.c, type in terminal in the correspondent directory where the file is located.
```
gcc micmp.c -o <desire_name>
```

Once compiled, you can choose executing the different options: (suppose we've created two files : file1.txt and file2.txt)

### (1)
```
./<desired_name> file1.txt file2.txt
```
![cmp_basic](https://cloud.githubusercontent.com/assets/19231158/25473867/fdb06528-2b28-11e7-9cfc-24c5c95c084f.png)

### (2)
```
./<desired_name> -i X:Y file1.txt file2.txt
```
Where X and Y represent a shift (ie, program will start comparing the file1 from position X and file2 from Y to the end)

![cmp_i](https://cloud.githubusercontent.com/assets/19231158/25473868/fdb0f254-2b28-11e7-84e0-9b1cd7d05d45.png)

### (3)
```
./<desired_name> -l file1.txt file2.txt
```
![cmp_l](https://cloud.githubusercontent.com/assets/19231158/25473866/fd8a1c92-2b28-11e7-93b7-c71d3b6d7787.png)

Output when two file are different... (modifying the last line of file1.txt)

"...tools and technologies that allow researchers to study cells and their DNA."  modified to ...
"...tools and technologies that allow researchers to study cells and their -DNA."

```
./<desired_name> -l file1.txt file2.txt
```
![cmp_l2](https://cloud.githubusercontent.com/assets/19231158/25474260/77f953e8-2b2a-11e7-9ac6-5e694acecec5.png)




That's all.
Regards,

Toderesa97.

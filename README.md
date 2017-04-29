# micmp

This program compares two or more files to determine whether they are equal or not. The program is made in C and it's ideal for terminal use. The program has three variations:
  1. Compare two files and retrieve whether they're equal or not.
  2. Compare two files from different shifts.
  3. Compare two files showing in a table the differences between the files (ASCII)
  
More than one functionality could be executed just in a statement. (ie, you could execute 1,1,2,3,1)

## Syntax (Basic cases)

First of all what we need it's to compile micmp.c, type in terminal in the correspondent directory where the file is located.
```
gcc micmp.c -o <desired_name>
```

Once compiled, you can choose executing the different options: (suppose we've created two files : file1.txt and file2.txt, you can download them from this project)

### (1)
```
./<desired_name> file1.txt file2.txt
```
![cmp_basic](https://cloud.githubusercontent.com/assets/19231158/25473867/fdb06528-2b28-11e7-9cfc-24c5c95c084f.png)

### (2)
```
./<desired_name> -i X:Y file1.txt file2.txt
```
Where X and Y represent a shift (ie, program will start comparing file1 from position X and file2 from Y till the end)

![cmp_i](https://cloud.githubusercontent.com/assets/19231158/25473868/fdb0f254-2b28-11e7-84e0-9b1cd7d05d45.png)

### (3)
```
./<desired_name> -l file1.txt file2.txt
```
![cmp_l](https://cloud.githubusercontent.com/assets/19231158/25473866/fd8a1c92-2b28-11e7-93b7-c71d3b6d7787.png)

Output when two files are different... (modifying the last line of file1.txt)

"...tools and technologies that allow researchers to study cells and their DNA."  

##### modified to ...

"...tools and technologies that allow researchers to study cells and their -DNA."

```
./<desired_name> -l file1.txt file2.txt
```
![cmp_l2](https://cloud.githubusercontent.com/assets/19231158/25474260/77f953e8-2b2a-11e7-9ac6-5e694acecec5.png)


## Composed cases.

As it was told at the beginning you can execute in one statement more than one comparison, even using different variations. In other words, what about if I want to see if two files are the same, whether they are the same with different shifts and show , between two files, the differences in a table; all this in one line...? as follows: (any file could be used)

```
./<desired_name> my_wage.txt uni -l another.txt file.txt -i 4:45 hello file1.txt
```
Note that variation 132 is being used. Other examples of variations may be:
  1. 1131
  2. 33113
  
If more than one variation is executed program will split and show them in the terminal properly sorted using the tag pad (#) followed by an autoincrement_id (which starts in 1), then the statement to be executed and finally the result.


That's all.
Regards,

Toderesa97.

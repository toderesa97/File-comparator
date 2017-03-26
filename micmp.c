#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int compareFiles(int fd_file1, int shift_f1 ,int fd_file2, int shift_f2, int l1, int l2);
void show_file_differences(int fd_file1, int fd_file2, int l1, int l2);

int main(int argc, char* argv[]){

	//int fd = open("ficddh.txt", O_RDONLY);
	//int fd1 = open(argv[1], O_RDONLY);
	//int fd2 = open(argv[2], O_RDONLY);
	
	int fd1, fd2;
	//printf("The array length has:%d\n",argc);
	int i;
	int operation = 1;
	for(i=1; i<argc; i++){
		
		if(strcmp(argv[i], "-i")==0){
			if((i+3)>=argc){ 
				printf("Error, file not found\n");
				break;
			}
			int shift[2];
			int j = 0;
			printf("#%d operation: %s %s %s %s\n", operation++, argv[i], argv[i+1], argv[i+2], argv[i+3]);
			char* tokens = strtok(argv[i+1], ":");	
			while(tokens){
				//puts(tokens);
				shift[j++] = (int)strtol(tokens, NULL, 10);
				tokens = strtok(NULL, ":");
			}
			if(j<2) {	
				printf("Check arguments\n");
				continue;
			}
			fd1 = open(argv[i+2],O_RDONLY);
			fd2 = open(argv[i+3],O_RDONLY);
			if(strcmp(argv[i+2],argv[i+3]) == 0){
				printf("Files are the same\n");
				i = i+3;
				continue;
			}
			if(fd1 == -1 || fd2 == -1){
				perror("");
				i = i + 3;
				continue;
			}
			
			FILE *fp1 = fopen(argv[i+2], "rb");
			fseek(fp1, 0, SEEK_END);
			int l1 = ftell(fp1);
			fclose(fp1);
			FILE *fp2 = fopen(argv[i+3], "rb");
			fseek(fp2, 0, SEEK_END);
			int l2 = ftell(fp2);
			fclose(fp2);
			//printf("VALUES--> %d, %d", l1, l2);
			
			if(compareFiles(fd1, shift[0], fd2, shift[1], l1, l2) == 0){
				printf("Files are equal!\n");
			} else {
				printf("Files are NOT equal\n");
			}
			
			i = i + 3;
		}else if(strcmp(argv[i], "-l")==0){
			//printf("-l found %s\n", argv[i]);
			if((i+2)>=argc){
				printf("Error, file not found\n");
				break;
			}
			printf("#%d operation: %s %s %s\n", operation++, argv[i], argv[i+1], argv[i+2]);	
			fd1 = open(argv[i+1],O_RDONLY);
			fd2 = open(argv[i+2],O_RDONLY);
			if(strcmp(argv[i+1],argv[i+2]) == 0){
				printf("Files are the same\n");
				i = i+2;
				continue;
			}
			if(fd1 == -1 || fd2 == -1){
				perror("");
				i = i + 2;
				continue;
			}
			
			
			FILE *fp1 = fopen(argv[i+1], "rb");
			fseek(fp1, 0, SEEK_END);
			int l1 = ftell(fp1);
			fclose(fp1);
			FILE *fp2 = fopen(argv[i+2], "rb");
			fseek(fp2, 0, SEEK_END);
			int l2 = ftell(fp2);
			fclose(fp2);			
			show_file_differences(fd1, fd2, l1, l2);			
			
			i = i + 2;
		}else{
			//comparing two files with no 'propeties'
			if((i+1)>=argc){ 
				printf("Error, file not found\n");
				break;
			}
			fd1 = open(argv[i],O_RDONLY);
			fd2 = open(argv[i+1],O_RDONLY);
			printf("#%d operation: %s %s\n", operation++, argv[i], argv[i+1]);
			if(strcmp(argv[i],argv[i+1]) == 0){
				printf("Files are the same\n");
				i = i+1;
				continue;
			}
			if(fd1 == -1 || fd2 == -1){
				perror("");
				i = i + 1;
				continue;
			}
			if(fd1 == fd2) {
				printf("Files are the same");
				i = i + 1;
				continue;
			}
			FILE *fp1 = fopen(argv[i], "rb");
			fseek(fp1, 0, SEEK_END);
			int l1 = ftell(fp1);
			fclose(fp1);
			FILE *fp2 = fopen(argv[i+1], "rb");
			fseek(fp2, 0, SEEK_END);
			int l2 = ftell(fp2);
			fclose(fp2);
			
			if(compareFiles(fd1, 0, fd2, 0,l1,l2)==0){
				printf("Files are equal!\n");
			}else{
				printf("Files are NOT equal\n");
			}
			i = i + 1;
		}	
	}
}



int compareFiles(int fd_file1, int shift_f1 ,int fd_file2, int shift_f2, int l1, int l2){
	if(shift_f1 >= l1 || shift_f2 >= l2) return -1;
	char* reserva_file1 = malloc(sizeof(char)*5);
	char* reserva_file2 = malloc(sizeof(char)*5);
	lseek(fd_file1,shift_f1,SEEK_SET);
	lseek(fd_file2,shift_f2,SEEK_SET);
	int rd1 = read(fd_file1, reserva_file1, sizeof(char)*5);
	int rd2 = read(fd_file2, reserva_file2, sizeof(char)*5);
	int max;
	if(l1 > l2){
		max = l1;
	}else{
		max = l2;
	}
	int byteCounter = 0;
	while(rd1 <= sizeof(char)*5 && rd2 <= sizeof(char)*5 && byteCounter < max){
		if(strcmp(reserva_file1, reserva_file2) != 0) return -1;
		rd1 = read(fd_file1, reserva_file1, sizeof(char)*5);
		rd2 = read(fd_file2, reserva_file2, sizeof(char)*5);
		
		byteCounter += sizeof(char);
	}
	//printf("BC:%d - %d\n", byteCounter, max);
	return strcmp(reserva_file1, reserva_file2);
}

void show_file_differences(int fd_file1, int fd_file2, int l1, int l2){
	char* reserva_file1 = malloc(sizeof(char)*1);
	char* reserva_file2 = malloc(sizeof(char)*1);
	lseek(fd_file1,0,SEEK_SET);
	lseek(fd_file2,0,SEEK_SET);
	int rd1 = read(fd_file1, reserva_file1, sizeof(char)*1);
	int rd2 = read(fd_file2, reserva_file2, sizeof(char)*1);
	int min;
	if(l1 < l2){
		min = l1;
	}else{
		min = l2;
	}
	int byteCounter = 0;
	printf("________________________________________________________________________\n");
	printf("|Position (byte)\t|ASCII (first file)\t|ASCII (second file)\t|\n");
	printf("________________________________________________________________________");
	while(rd1 <= sizeof(char)*1 && rd2 <= sizeof(char)*1 && byteCounter < min){
		if(*reserva_file1 != *reserva_file2){
			//printf("||%d||-%c-%c\n",byteCounter, *reserva_file1, *reserva_file2);
			printf("\n|%d\t\t\t|%d\t\t\t|%d\t\t\t|", (byteCounter), (int)*reserva_file1, (int)*reserva_file2);
			
		}
		rd1 = read(fd_file1, reserva_file1, (int)sizeof(char)*1);
		rd2 = read(fd_file2, reserva_file2, (int)sizeof(char)*1);
		byteCounter += (int)sizeof(char)*1;
	}
	printf("\n________________________________________________________________________\n");
}

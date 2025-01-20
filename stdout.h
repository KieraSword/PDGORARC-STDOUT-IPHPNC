#include <stdio.h>
#ifdef _WIN32
#define WINDOWS 1
#else
#define WINDOWS 0
#endif
#define stdout custom_stdout

struct stdout{
	void (*write)(char[]);
	void (*writeln)(char[]);
};
void write(char string[]){
    FILE *file = NULL;
	if(WINDOWS){
		file = fopen("CON", "w");
	} else {
		file = fopen("/dev/stdout", "w");
	}
    if (file == NULL) {
        printf("Error accessing STDIO\n");
    }
    fprintf(file, string);
	fclose(file); 
}
void writeln(char string[]){
    FILE *file = NULL;
	if(WINDOWS){
		file = fopen("CON", "w");
	} else {
		file = fopen("/dev/stdout", "w");
	}
    if (file == NULL) {
        printf("Error accessing STDIO\n");
    }
    fprintf(file, string);
	fprintf(file, "\n");
	fclose(file); 
}
struct stdout stdout = { write, writeln };
/*
int main(){
	stdout.writeln("Hello World!");
}
*/
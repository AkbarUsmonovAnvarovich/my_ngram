#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_str(char** p1) {
    int x = 0;
    for (int i = 1; p1[i]; i++) {
        x += strlen(p1[i]);
    }
    return x;
}

char* array_str(char** p1 , int p2) {
    char* out = malloc(sizeof(char) *p2);
    int index = 0;
    for (int i = 1; p1[i]; i++) {
        for (int in = 0; p1[i][in]; in++) {
            out[index] = p1[i][in];
            index++;
        }
    }
    return out;
}

int my_cmp_str(char* p1, char p2){

    for (int i = 0; p1[i]; i++) {
        if (p1[i] == p2) {
            return 0;
        }
    }
    return 1;
}

void my_swap(char* p1, char* p2){
    char temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubble_sort(char* p1){
    for (int i = 0; i < ((int)strlen(p1) -1); i++) {
        for (int in = i +1; in < (int)strlen(p1); in++) {
           if (p1[i] > p1[in]) {
               my_swap(&p1[i], &p1[in]);
           }
        }   
    }
}

void my_ngram(char** p1){
    int length = length_str(p1);
    int index_sort = 0;
    char* str = malloc(sizeof(char) *length);
    char* sort = malloc(sizeof(char) *length);
    str = array_str(p1 , length);
    
    for (int i = 0; str[i]; i++) {
        if (my_cmp_str(sort, str[i])) {
            sort[index_sort] = str[i];
            index_sort++;
        }
    }
    bubble_sort(sort);
    
    int ascii_count[128] = {0};
    for (int i = 0; sort[i]; i++) {
        for (int in = 0; str[in]; in++) {
            if (sort[i] == str[in]) {
                ascii_count[(int)sort[i]]++;
            }
        }
    }
    for(int i = 0; i < 128; i++)
    {
        if (ascii_count[i] > 0) {
            printf("%c:%d\n", i, ascii_count[i]);
        }
    }
}

int main(int ac , char** av) {
    my_ngram(av);
    if(ac){}
    return 0;
}
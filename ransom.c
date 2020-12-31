#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the checkMagazine function below.
void checkMagazine(int magazine_count, char** magazine,
    int note_count, char** note);
bool check_cases (char *str1, char *str2);

int main()
{
    char** mn = split_string(readline());

    char* m_endptr;
    char* m_str = mn[0];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n_endptr;
    char* n_str = mn[1];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** magazine_temp = split_string(readline());

    char** magazine = malloc(m * sizeof(char*));

    for (int i = 0; i < m; i++) {
        char* magazine_item = *(magazine_temp + i);

        *(magazine + i) = magazine_item;
    }

    int magazine_count = m;

    char** note_temp = split_string(readline());

    char** note = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* note_item = *(note_temp + i);

        *(note + i) = note_item;
    }

    int note_count = n;

    checkMagazine(magazine_count, magazine, note_count, note);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

// Check if both word are identical - case sensetive
bool check_cases (char *str1, char *str2){
    if (strcmp(str1,str2)==0){
        for (int k=0; k< strlen(str1);k++){
            if (str1[k] != str2[k]){return false;}
        }
    } else {
        return false;
    }
    return true;
}

void checkMagazine(int magazine_count, char** magazine,
    int note_count, char** note) {
    //Magazine length is equal or longer than not length
    if (magazine_count<note_count) {
        printf("No");
        exit(1);
    }
    //flag for each word in magazine if it was used
    int found[magazine_count];
    int j;
    //set the first value to 0 
    for (j=0; j < magazine_count; ++j){found[j]=0;}
    //search every word from note in magazine
    for (int i = 0; i < note_count; i++){

        for (j=0; j < magazine_count; j++){
            //Check if both word are identical and the word in mag. wasn't used
            if (check_cases(*(note+i),*(magazine+j)) && (!found[j])){
                //if all condition exist mark flag, update j and brake
                found[j++]=1;
                break;
            }
        }
        //check if the note's word is found in magazine
        if (!found[j-1]){
            printf("No");
            exit(1);
        }
    }
    printf("Yes");
}

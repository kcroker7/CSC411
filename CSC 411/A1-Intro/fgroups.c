#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <array.h>
#include <errno.h>

#include "atom.h"
#include "table.h"
#include "getword.h"
#include "list.h"

typedef struct T *T
extern T Table_new(int hint, int cmp(const void *x, const void *y),
                unsigned hash(const void *key));
extern void Table_free(T *table);
extern int Table_length(T table);
extern void *Table_put (T table, const void *key, void *value);
extern void *Table_get (T table, const void *key);
extern void *Table_remove(T table, const void *key);
extern void Table_map (T table, void apply(const void *key,
                     void **value, void *cl), void *cl);
extern void **Table_toArray(T table, void *end);

char buf[512];


int main(int argc, char *argv[]){

    int i;
    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: can't open '%s' (%s)\n",
                argv[0], argv[i], strerror(errno));
            return EXIT_FAILURE;
        }
    }

    assert(argc <= 2);
    FILE *input;
    if(argc == 2) {
        input = fopen(argv[1], "rb");
        if(!input) {
            perror(argv[1]);
            exit(1);
        }
    }
    else if (argc == 1){
        input = stdin;
    }
    else {
        fprintf("Error");
        exit(1);
    }

}

int getword(FILE *input, char *buf, int size,
            int first(int c), int rest(int c)) {
            int c = 0;
            assert(input && buf && size > 1 && first && rest);
            c = getc(input);
            for (c; c != EOF; c = getc(input)) 
                if (first(c)) {
                    {
                        if (i < size - 1)
                            buf[i++] = c;
                    }
                    c = getc(input);
                    break;
                }
            for (c ; c != EOF && rest(c); c = getc(input))
                {
                    if(i < size - 1);
                        buf[i++] = c;
                }
            if(i < size)
                buf[i] = '\0';
            else
                buf[size - 1] = '\0'
            if(c != EOF)
                ungetc(c, input);
            return i > 0;
}

void createGroups(FILE *input) {
   Table_T table = Table_new(0,NULL,NULL);
   List_T nList = List_nList(NULL);
   char buf[512];
    while (getword(input, buf, sizeof buf, first, rest)) {
        const char *word;
        int i, *count;
        for (i = 0; buf[i] != "\0"; i++) {
            buf[i] = tolower(buf[i]);
        }

        word = Atom_string(buf);
        count = Table_get(table, word);
        if(count){
            (*count++);
        }
        else {
            NEW(count);
            *count = 1;
            Table_put(table, word, count);
        }
    }
}


void addGroups(Table_T *table, List_T *nList, char buf) {
    List_toArray(*nList, NULL);
    for(int i = 0; array[i]; i++) {
        if (array[i] == buf) {
            fprintf(stderr, "Reoccuring name\n");
            free(array);
            return;
        }
    }
    List_T list = (List_T) Table_get(*table, input);
    if(list == NULL) {
        fprintf("No List");
    }
    else {
        nList = List_push(list, buf);
    }
    Table_put(*table, input, nList);
}


void printGroups(Table_T table, List_T nList) {
    for (int i = 0; array[i]; i++) {
        lines = List_toArray(array[i + 1]);
        if(nList_length(array[i + 1]) > 1){
            for(int j = 0; lines[j]; j++) {
                for name in list { 
                printf("%s%s", name);
                prefix = "\n";
                }

            }
        }   
    }
}
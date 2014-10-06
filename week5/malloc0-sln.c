/**
 * malloc0-sln.c - Malloc Exercise (Solution)
 *
 * Computer Science 50
 * Week 5
 *
 * Eric Ouyang <eouyang@college.harvard.edu>
 * Frederick Widjaja <fwidjaja@college.harvard.edu>
 *
 * An example of how malloc can be used.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ALPHA_LEN 26

int* alpha_count(char* str);

int main(void)
{
    char* str = "The quick brown fox jumps over the lazy dog";
    int* counts = alpha_count(str);
    
    // print out the count of each alphabet in our string
    for (int i = 0; i < ALPHA_LEN; i++)
    {
        printf("%c: %d\t", 'a' + i, counts[i]);
    }
    printf("\n");
    
    free(counts);
}

int* alpha_count(char* str)
{
    // allocate some space to store our counts
    int* counts = malloc(sizeof(int) * ALPHA_LEN);
    for (int i = 0; i < ALPHA_LEN; i++)
    {
        counts[i] = 0;
    }
    
    // loop through the string
    for (char* ptr = str; *ptr != '\0'; ptr++)
    {
        char c = *ptr;
        
        // only count alpha characters
        if (isalpha(c))
        {
            // increment the counter for the appropriate alphabet
            counts[tolower(c) - 'a'] += 1;
        }
    }
    
    return counts;
}

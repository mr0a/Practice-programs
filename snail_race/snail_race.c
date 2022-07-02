#include <stdio.h>
#include <stdlib.h>

/*
void displayStatus(char **snail_names, int **snail_progress, int num_snails_racing, int finish_line)
{
    for (int i = 0; i < 40; i++)
        printf("\n");
    printf("START");
    for (int i = 0; i < finish_line - 5; i++)
        printf(" ");
    printf("FINISH\n");

    printf("|");
    for (int i = 0; i < finish_line - 1; i++)
        printf(" ");
    printf("|\n");

    for (int i = 0; i < num_snails_racing; i++)
    {
        printf("%s\n", snail_names[i]);
        printf("@v\n");
        // snail_progress[i] = 0;
    }
}
*/

int main()
{

    const int max_num_snails = 8;
    const int max_name_length = 20;
    const int finish_line = 40;

    int num_snails_racing = 0;
    while (1)
    {
        printf("How many snails will race? Max: %d\n> ", max_num_snails);
        scanf("%d", &num_snails_racing);
        if (num_snails_racing > 1 && num_snails_racing <= max_num_snails)
            break;
        printf("Enter a number between 2 and %d\n", max_num_snails);
    }
    // printf("Hello %d", num_snails_racing);
    char *snail_names[max_num_snails];
    int snail_progress[max_num_snails];
    for (int i = 0; i < num_snails_racing; i++)
        snail_progress[i] = 0;

    for (int i = 0; i < num_snails_racing; i++)
    {
        char *name = malloc(max_name_length);
        // scanf("%[^\n]%*c", name);
        printf("Enter snail #%d's name:\n> ", i + 1);
        scanf("%s", name);
        snail_names[i] = name;
    }

    // for(int i = 0; i < num_snails_racing; i++){
    //     printf("snail #%d's name: %s \n", i+1, snail_names[i]);
    // }

    for (int i = 0; i < 40; i++)
        printf("\n");
    printf("START");
    for (int i = 0; i < finish_line - 5; i++)
        printf(" ");
    printf("FINISH\n");

    printf("|");
    for (int i = 0; i < finish_line - 1; i++)
        printf(" ");
    printf("|\n");

    for (int i = 0; i < num_snails_racing; i++)
    {
        printf("%s\n", snail_names[i]);
        printf("@v\n");
    }

    for(int i = 0; i < __INT_MAX__/100; i++);

    while (1)
    {
        for(unsigned int i = 0; i < (unsigned int) __INT16_MAX__ * 10000; i++);
        int rand_count = (rand() % (num_snails_racing / 2));
        rand_count = rand_count == 0 ? 1: rand_count;

        // printf("rand_count is %d", rand_count);
        for(int i = rand_count; i > 0; i--){
            int rand_snail = rand() % num_snails_racing;
            // printf("rand_snail is %d", rand_snail);
            ;

            if ((snail_progress[rand_snail] += 1) == finish_line){
                printf("%s has won!\n", snail_names[rand_snail]);
                exit(0);
            }
        }

        for (int i = 0; i < 40; i++)
            printf("\n");
        printf("START");
        for (int i = 0; i < finish_line - 5; i++)
            printf(" ");
        printf("FINISH\n");

        printf("|");
        for (int i = 0; i < finish_line - 1; i++)
            printf(" ");
        printf("|\n");

        for (int i = 0; i < num_snails_racing; i++)
        {
            int spaces = snail_progress[i];
            for(int j = 0; j < spaces; j++) printf(" ");
            printf("%s\n", snail_names[i]);
            for(int j = 0; j < spaces; j++) printf(".");
            printf("@v\n");
            // snail_progress[i] = 0;
        }
    }

    return 0;
}

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int temperatureChart[32][11];

    // fill chart with zeros
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            temperatureChart[i][j] = 0;
        }
    }

    // filling cities and days as per question
    for(int i = 1; i < 32; i++)
    {
        temperatureChart[i][0] = i;
        for(int j = 1; j < 11; j++)
        {
            temperatureChart[0][j] = j;
        }
    }


    int mode = -1;
    printf("Enter 1 to start entering temperature data\n");
    printf("Enter 2 to take random generated numbers as input\n");
    scanf("%d", &mode);
    if (mode == 1)
    {
        // take input from stdin
        for(int i = 1; i < 32; i++)
        {
            printf("enter temparatures for day : %i of all cities  \n", i);
            for(int j = 1; j < 11; j++)
            {
            printf("    ");
            scanf("%i", &temperatureChart[i][j]);
            }
            printf("\n");
        }
    }
    else if (mode == 2)
    {
        // take input from random generator
        srand(time(0));
        for(int i = 1; i < 32; i++)
        {
            for(int j = 1; j < 11; j++)
            {
                temperatureChart[i][j] = rand();
            }
        }
    }else
    {
        printf("Invalid input. Program exits");
        exit(1001);
    }
    
    

    // display chart content
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            printf("    %d", temperatureChart[i][j]);
        }
        printf("\n");
    }

    //find max_temp_temp element
    int max_temp = -100;  // default some value
    int max_city = 0;
    for(int i =1; i < 31; i++)
    {
        for(int j = 1; j < 11; j++)
        {
            if(max_temp <= temperatureChart[i][j])
            {
                max_temp = temperatureChart[i][j];
                max_city = j;
            }
            else
            {
                continue;
            }
            
        }
    }
    //find min_temp element
    int min_temp = 100;  // default some value
    int min_city = 0;
    for(int i =1; i < 31; i++)
    {
        for(int j = 1; j < 11; j++)
        {
            if(min_temp >= temperatureChart[i][j])
            {
                min_temp = temperatureChart[i][j];
                min_city = j;
            }
            else
            {
                continue;
            }
            
        }
    }

    printf("--------------------------------------\n");
    printf("Minimum Temperature:  %d,   City:    %d\n", min_temp, min_city);
    printf("Maximum Temperature:  %d,   City:    %d\n", max_temp, max_city);

    printf("\nEnter any key to end the program\n");
    getch();

    return 111;
}
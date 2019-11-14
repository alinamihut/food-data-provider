#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_TYPE_NAME 10
#define MAX_SPECIFIC_FOOD_NAME 30
#define MAX_LINE 10
#define MAX_DRINK_NAME 10
void readSpecificFoods(char * specificFoods);
void readDrinks ( char * drinks);

int main() {
    int noOfFoodTypes;
    int noOfDrinks;
    printf("Please input number of food types \n");
    scanf("%d", &noOfFoodTypes);
    getchar();

    char **foodTypes;
    foodTypes = (char **) malloc(noOfFoodTypes * sizeof(char *));
    printf("Please input the food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i < noOfFoodTypes; i++) {
        foodTypes[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        gets(foodTypes[i]);
    }
    /*//todo: delete later
    for (int i = 0; i < noOfFoodTypes; i++) {
        printf("Food Type %s\n", foodTypes[i]);
    }
     */
    int * noOfSpecificFoods = (int*)malloc(noOfFoodTypes * sizeof(int));
    char *** specificFoods = (char***)malloc(noOfFoodTypes * sizeof(char**));
    double ** pricesOfFoods = (double**)malloc(noOfFoodTypes* sizeof(double*));
    for(int i=0; i<noOfFoodTypes; i++) {
        printf("Please input no of specific foods for food %s\n",foodTypes[i]);
        scanf("%d",&noOfSpecificFoods[i]);
        getchar();

        specificFoods[i] = (char**)malloc(noOfSpecificFoods[i]* sizeof(char*));
        pricesOfFoods[i] = (double*)malloc(noOfSpecificFoods[i]* sizeof(double));

        printf("Please input \"%s\" specific foods & prices: each line in the format <specific food> (price): \n",foodTypes[i]);
        for(int j=0;j<noOfSpecificFoods[i];j++){
            specificFoods[i][j] = (char*)malloc(MAX_SPECIFIC_FOOD_NAME * sizeof(char));
            readSpecificFoods(specificFoods[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &pricesOfFoods[i][j]);
            getchar();
        }
    }
    /*//todo: delete later
    for (int i = 0; i < noOfFoodTypes; i++)
        for(int j=0;j<noOfSpecificFoods[i];j++)
        {
            printf("Specific Foods and prices %s %lf\n", specificFoods[i][j], pricesOfFoods[i][j]);
        }
        */

    printf ("Please input no of drinks %d\n", noOfDrinks);
    scanf("%d", &noOfDrinks);
    getchar();
    char ** drinks;
    drinks = (char **) malloc(noOfDrinks *  sizeof(char *));
    double ** pricesOfDrinks = (double**)malloc(noOfDrinks * sizeof(double*));
    printf ("Please input the drinks: each line in the format <drink> (price): \n");
    for (int i=0;i<noOfDrinks;i++)
    {
        drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        pricesOfDrinks[i] = (double*)malloc(noOfDrinks * sizeof(double));
        readDrinks(drinks[i]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &pricesOfDrinks[i]);


    }
    /*//todo: delete later
    for (int i = 0; i < noOfDrinks; i++)
            {
        printf("Drinks and prices %s %.2lf\n", drinks[i], pricesOfDrinks[i]);
    }*/

    printf("The food data is:\n");
    for(int i=0;i<noOfFoodTypes;i++) {
        printf("%s: ", foodTypes[i]);
        for(int j=0;j<noOfSpecificFoods[i];j++) {
            printf("(%s - %.2lf) ",specificFoods[i][j],pricesOfFoods[i][j]);
        }
        printf("\n");
    }
    printf ("The drink data is: \n");
    for(int i=0;i<noOfDrinks;i++) {
        printf("drinks: %s", drinks[i]);
        if (i<noOfDrinks-1) printf(", ");
        printf("prices: %s", pricesOfDrinks[i]);
        if (i<noOfDrinks-1) printf(", ");

        printf("\n");
    }
    for(int i=0;i<noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificFoods;j++) {
            free(specificFoods[i][j]);
        }
        free(specificFoods[i]);
        free(pricesOfFoods[i]);
        free(foodTypes[i]);
    }
    for(int i=0;i<noOfDrinks;i++) {
        free(pricesOfDrinks[i]);
        free(drinks[i]);

    }
    free(specificFoods);
    free(pricesOfFoods);
    free(foodTypes);
    free (drinks);
    free (pricesOfDrinks);

    return 0;
}

void readSpecificFoods(char * specificFoods) {
    char c = getchar();
    int i=0;
    while(c!='(') {
        specificFoods[i] = c;
        c = getchar();
        i++;
    }
    specificFoods[i] = '\0';
}


void readDrinks ( char * drinks){
    char c = getchar();
    int i=0;
    while(c!='(') {
        drinks[i] = c;
        c = getchar();
        i++;
    }
    drinks[i] = '\0';
}


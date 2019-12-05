#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_TYPE_NAME 10
#define MAX_SPECIFIC_FOOD_NAME 30
#define MAX_LINE 10
#define MAX_DRINK_NAME 10
FILE *fptr;
void readSpecificFoods(char * specificFoods);
void readDrinks ( char * drinks);

int main() {
    fptr = fopen("/Users/alinamihut/Computer programming/food-data-provider/data.txt","w");
    int *noOfFoodTypes=malloc (sizeof(int));
    printf("Please input number of food types \n");
    scanf("%d", noOfFoodTypes);
    getchar();

    char **foodTypes;
    foodTypes = (char **) malloc(*noOfFoodTypes * sizeof(char *));
    printf("Please input the food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i <*noOfFoodTypes; i++) {
        foodTypes[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        gets(foodTypes[i]);
    }

    int * noOfSpecificFoods = (int*)malloc(*noOfFoodTypes * sizeof(int));
    char *** specificFoods = (char***)malloc(*noOfFoodTypes * sizeof(char**));
    double ** pricesOfFoods = (double**)malloc(*noOfFoodTypes* sizeof(double*));
    for(int i=0; i<*noOfFoodTypes; i++) {
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
        }
    }

    int *noOfDrinks= malloc (sizeof (int));
    printf ("Please input no of drinks \n");
    scanf("%d", noOfDrinks);
    getchar();
    char ** drinks= (char **) malloc(*noOfDrinks *  sizeof(char *));
    double *pricesOfDrinks = (double *)malloc(*noOfDrinks * sizeof(double));
    printf ("Please input the drinks: each line in the format <drink> (price): \n");
    for (int i=0;i<*noOfDrinks;i++)
    {
        drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        //pricesOfDrinks[i] = (double*)malloc(*noOfDrinks * sizeof(double));
        readDrinks(drinks[i]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &pricesOfDrinks[i]);


    }

    printf("The food data is: \n");
    for(int i=0;i<*noOfFoodTypes;i++) {
        printf("%s: ", foodTypes[i]);
        for(int j=0;j<noOfSpecificFoods[i];j++) {
            printf("(%s - %.2lf) ", specificFoods[i][j], pricesOfFoods[i][j]);
        }
        printf("\n");
    }
    printf ("The drink data is: \n");
    printf("drinks: ");
    for(int i=0;i<*noOfDrinks;i++)
         printf ("%s, ", drinks[i]);
    printf("\n");
    printf("prices: ");
    for(int i=0;i<*noOfDrinks;i++)
        printf ("%.2lf, ", pricesOfDrinks[i]);
    printf("\n");

    //save to file
    fprintf(fptr, " %d: \n", *noOfFoodTypes);
    for(int i=0;i<*noOfFoodTypes;i++) {
        fprintf(fptr, "%s %d: ", foodTypes[i], noOfSpecificFoods[i]);
        for(int j=0;j<noOfSpecificFoods[i];j++) {
            fprintf(fptr, "(%s - %.2lf) ", specificFoods[i][j], pricesOfFoods[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fprintf(fptr, " %d\n", *noOfDrinks);
    for(int i=0;i<*noOfDrinks;i++)
        fprintf(fptr, "(%s - %.0lf), ", drinks[i], pricesOfDrinks[i]);
    fprintf(fptr, "\n");

    for(int i=0;i< *noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificFoods[i];j++) {
            free(specificFoods[i][j]);
        }
        free(specificFoods[i]);
        free(foodTypes[i]);
    }
    for(int i=0;i<*noOfDrinks;i++) {
        free(drinks[i]);

    }
    free (specificFoods);
    free(pricesOfFoods);
    free (noOfSpecificFoods);
    free(foodTypes);
    free (noOfFoodTypes);
    free (drinks);
    free (pricesOfDrinks);
    free (noOfDrinks);


    fclose(fptr);
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


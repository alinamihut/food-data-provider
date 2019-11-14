#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_TYPE_NAME 10
#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_LINE 10
void readSpecificFoods(char * specificFoods);

int main() {
    //foodtype=brand
    //max brand name= max food type name
    //models=specific foods
    // function for reading drinks
    int noOfFoodTypes;
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
    //todo: delete later
    for (int i = 0; i < noOfFoodTypes; i++) {
        printf("Food Type %s\n", foodTypes[i]);
    }
    int * noOfSpecificFoods = (int*)malloc(noOfFoodTypes* sizeof(int));
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
    //todo: delete later
    for (int i = 0; i < noOfFoodTypes; i++)
        for(int j=0;j<noOfSpecificFoods[i];j++)
            {
        printf("SpecificFoods and prices %s %lf\n", specificFoods[i][j], pricesOfFoods[i][j]);
    }
/*
    // display data
    printf("The data is:\n");
    for(int i=0;i<noOfBrands;i++) {
        // display brand
        printf("%s: ", brands[i]);
        for(int j=0;j<noOfModels[i];j++) {
            printf("(%s, %.2lf) ",models[i][j],prices[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i=0;i<noOfBrands;i++) {
        for(int j=0;j<noOfModels;j++) {
            free(models[i][j]);
        }
        free(models[i]);
        free(prices[i]);
        free(brands[i]);
    }
    free(models);
    free(prices);
    free(brands);
    free(noOfModels);

    return 0;
}
  */}
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




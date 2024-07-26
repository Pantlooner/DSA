 //counting sort
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int array[], int size)
{
	//get max value in array
	int maxValue = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > maxValue)
		{
			maxValue = array[i];
		}
	}
	
	int countArraySize = maxValue + 1;
	int *countArray = (int*) malloc(countArraySize * sizeof(int));
	for (int i = 0; i < countArraySize; i++)
	{
		countArray[i] = 0;
	}
	
	//count the frequency of the elements in the input array
	for (int i = 0; i < size; i++)
	{
		countArray[array[i]]++;
	}

	//perform a cumulative sum on the countArray
	for (int i = 1; i < countArraySize; i++)
	{
		countArray[i] += countArray[i-1];
	}

	//iterate backwards through the input array, indexing into the countArray
	//and subtracting 1 to find the proper location in the output array
	int *outputArray = (int*) malloc(size * sizeof(int));
	for (int i = size; i >= 0; i--)
	{
		outputArray[countArray[array[i]] - 1] = array[i];
		countArray[array[i]]--;
	}
	
	//change the input array to match the output array
	for (int i = 0; i < size; i++)
	{
		array[i] = outputArray[i];
	}
	
	free(countArray);
	free(outputArray);
}

int main()
{
	int arraySize;
	do {
		printf("Enter array size: ");
		scanf("%d", &arraySize);
	} while (arraySize <= 1);
	
	int *array = (int*) malloc(arraySize * sizeof(int));
	for (int i = 0; i < arraySize; i++)
	{
		printf("type int: ");
		scanf("%d", &array[i]);
	}
	
	counting_sort(array, arraySize);
	
	printf("Sorted array: [ ");
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d ", array[i]);
	}
	printf("]\n");
	free(array);
	return 0;
}
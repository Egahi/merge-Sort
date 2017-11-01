/**
 * mergeSort.cpp
 *
 * this program sorts a sequence of characters from least to greatest
 * using divide and conquer approach (leveraging recursion)
 *
 * s_egahi
 *
 * this is merge sort
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#define ZERO 0
#define ONE 1
#define RANGE 21

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

using namespace std;

int main(void)
{
	// use current time as seed for rand()
	srand(time(NULL));

	int *randomNumbers = new int[RANGE];

	for (int i = ZERO; i < RANGE - ONE; i++)
	{
		// generate random numbers between 1 and 20
		randomNumbers[i] = (ONE + rand() % 20);
	}

	// NULL terminate array
	randomNumbers[RANGE - ONE] = '\0';
	cout << endl;

	// print out the numbers
	for (int i = ZERO; i < RANGE - ONE; i++)
	{
		cout << randomNumbers[i] << " ";
	}

	cout << endl;

	// sort the sequence
	mergeSort(randomNumbers, ONE, RANGE - ONE);

	// print out the sorted numbers
	for (int i = ZERO; i < RANGE - ONE; i++)
	{
		cout << randomNumbers[i] << " ";
	}

	cout << endl;

	delete[] randomNumbers;

	// success
	return ZERO;
}

/**
 * divide the sequence in half,
 * sort left half, sort right half
 * merge both halves
 */
void mergeSort(int *random, int start, int end)
{
	// locate index of middle value
	int mid = (start + end) / 2;

	// perform operations for only sequence with more than one element
	if (start < end)
	{
		// sort left half
		mergeSort(random, start, mid);

		// sort right half
		mergeSort(random, mid + ONE, end);

		// merge sorted halves
		merge(random, start, mid, end);
	}
}

/**
 * merge sorted subsequence together
 */
void merge(int *sorted, int start, int mid, int end)
{
	// size of left subarray
	int lft = (mid - start) + ONE;

	// size of right subarray
	int rgt = end - mid;

	// left subarray
	int *left = new int[lft + ONE];
	left[lft] = '\0';

	// right subarray
	int *right = new int[rgt + ONE];
	right[rgt] = '\0';

	// fill up leftsubarray
	for (int i = ZERO; i < lft; i++)
		left[i] = sorted[start + i - 1];

	// fill up rightsubarray
	for (int i = ZERO; i < rgt; i++)
		right[i] = sorted[i + mid];

	// indices for subarrays
	int j = ZERO, k = ZERO;

	for (int i = start - 1; i < end; i++)
	{
		// lowest value is in left subarray
		if ((left[j] <= right[k] && left[j] != '\0') || right[k] == '\0')
		{
			// put value in lower index of sorted array
			sorted[i] = left[j];
			j++;
		}

		// lowest value is in rightsub array
		else
		{
			// put value in lower index of sorted array
			sorted[i] = right[k];
			k++;
		}
	}

	delete[] left;
	delete[] right;
}

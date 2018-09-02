/* W03
*  temperatureAnalyzer.c
*  Ivy Leano
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUMS 4
#define MAXTEMP 40
#define MINTEMP -40

int main(void) {

	int days;
	int high;
	int low;
	int highestTempDay = 0;
	int lowestTempDay = 0;
	int highestTemp = 0;
	int lowestTemp = 0;
	int totalHigh = 0;
	int totalLow = 0;
	int totalTempReadings;
	double sumHighLow;


	printf("---=== IPC Temperature Analyzer ===---\n");

	// For-construct iterates through the NUM of days

	for (days = 1; days < NUMS + 1; days++)
	{
		// Prompts user for high and low temperature input

		printf("Enter the high value for day %d: ", days);
		scanf("%d", &high);
		printf("\n");

		printf("Enter the low value for day %d: ", days);
		scanf("%d", &low);
		printf("\n");

		// While-construct used to avoid incorrect temperature input
		// Re-prompts temperature input if incorrect

		while (high < low || high > MAXTEMP || low < MINTEMP)
		{
			printf("Incorrect values, temperatures must be in the range %d to %d, high must be greater than low.\n", MINTEMP, MAXTEMP);

			printf("\n");
			printf("Enter the high value for day %d: ", days);
			scanf("%d", &high);
			printf("\n");

			printf("Enter the low value for day %d: ", days);
			scanf("%d", &low);
			printf("\n");

		}

		// High and low temperatures are added to the totalHigh and totalLow variables, respectively  

		totalHigh += high;
		totalLow += low;

		// If-statements allow program to retain the highest/lowest temperature inputs and the days they were taken on

		if (high > highestTemp)
		{
			highestTemp = high;
			highestTempDay = days;
		}

		if (low < lowestTemp)
		{
			lowestTemp = low;
			lowestTempDay = days;
		}
	}

	sumHighLow = totalHigh + totalLow;

	// The max NUM of days is 4, the total temperature readings is doubled to include high and low temperature inputs

	totalTempReadings = NUMS * 2;

	printf("The average (mean) temperature was: %.2lf\n", sumHighLow / totalTempReadings);
	printf("The highest temperature was %d, on day %d\n", highestTemp, highestTempDay);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestTempDay);

	return 0;
}


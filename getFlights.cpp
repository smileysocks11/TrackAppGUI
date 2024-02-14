/*
 * BRIGHTON HILYARD'S FILE
*/

#include <iostream>
#include <string>
#include "Athletes.h"
using namespace std;



void getFlights(Athletes a[], int num_athletes, string input, int flights) {
	/*
	 * gets the amount of flights for the meet
	 * returns to main
	 */

	int count = 0;
	int div = num_athletes / flights;
	int inFlights[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	if (div * flights != num_athletes)
	{
		for (int i = 0; i < flights; i++)
		{
			inFlights[i] += div;
		}

		int remainder = num_athletes - (div * flights);
		while (remainder != 0)
		{
			inFlights[count] += 1; remainder -= 1;
			count++;
			if (count == flights)
			{
				count = 0;
			}
		}
		count = 0;

		for (int f = 0; f < 10; f++)
		{
			for (int i = 0; i < inFlights[f]; i++)
			{
				a[count].flightNum = f + 1;
				count++;
			}
		}
		count = 0;
	}
	else {
		for (int i = 0; i < flights; i++)
		{
			inFlights[i] += div;
		}
		for (int f = 0; f < 10; f++)
		{
			for (int i = 0; i < inFlights[f]; i++)
			{
				a[count].flightNum = f + 1;
				count++;
			}
		}
		count = 0;
	}

}
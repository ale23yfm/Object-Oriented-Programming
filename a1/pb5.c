#include <stdio.h>
#include <stdbool.h>

void reading(int v[], int l, int *read)
{
	/*
	Reads the elements of an array.
	input:
		v[] - the array to be read
		l - the length of the array
		read - 1 if an array was read, 0 otherwise
	*/
	int i;
	for (i = 0; i < l; i++)
	{
		printf("\nElement index %d is:", i);
		scanf_s("%d", &v[i]);
	}
	printf("\nThe array is:");
	for (i = 0; i < l; i++)
		printf("%d ", v[i]);
	*read = 1;
}

bool isPrime(int n)
{
	/*
	Decides if a number is prime or not.
	input:
		n - the given number
	output:
		returns true if the number is prime, false otherwise 
	*/
	int d;
	if (n < 2)
		return false;
	for (d = 2; d < n; d++)
		if (n % d == 0)
			return false;
	return true;
}

int exponentOfDivisor(int n, int p, int e)
{
	/*
	Divides a number n by p and keeps the exponent of p.
	input:
		n - the number to be decomposed
		p - the divisor
		e - the exponent of p
	*/
	while (n % p == 0)
	{
		n /= p;
		e++;
	}
	return e;
}

int gcd(int a, int b)
{
	/*
	Greatest common divisor of a and b
	input: 
		a, b - the two numbers
	output: 
		the greatest common divisor of a and b
	*/
	if (a < 0)
		a = a * (-1);
	if (b < 0)
		b = b * (-1);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void lcs(int v[], int l, int *maxLen, int *maxIndex)
{
	/*
	Finds the longest contiguous subsequence of prime numbers.
	input:
		v[] - the array of numbers
		l - the length of the array
		*maxLen - pointer for maximum length of the contiguous subsequence
		*maxIndex - the index of the first element in lcs 
	output:
		maxLen - contains the numbers of elements in lcs
		maxIndex - contains the index of the first element in lcs
	*/
	int currLen = 1, currIndex = 0, i;
	for (i = 0; i < l - 1; i++)
		if (gcd(v[i], v[i + 1]) == 1)
			currLen++;
		else
		{
			if (currLen > *maxLen)
			{
				*maxLen = currLen;
				*maxIndex = currIndex;
			}
			currIndex = i + 1;
			currLen = 1;
		}
	if (currLen > *maxLen)
	{
		*maxLen = currLen;
		*maxIndex = currIndex;
	}
}

int main()
{
	printf("Welcome to the menu!\n");
	int v[100] = { 0 };
	int o, l = 0, i, n, p, read = 0, w;
	while (1)
	{
		printf("\nPlease choose an option:\n");
		printf("1. Read an array.\n");
		printf("2. Print the exponent of a prime number.\n");
		printf("3. Print find the longest contiguous subsequence.\n");
		printf("4. Exit.\n");
		printf("Your option is:");
		scanf_s("%d", &o);

		//Option 1
		if (o == 1)
		{
			printf("Type the size of the array:");
			scanf_s("%d", &l);
			printf("Type the elements:\n");
			reading(v, l, &read);
			printf("\n");
		}

		//Option 2
		else if (o == 2)
		{
			//a.Print the exponent of a prime number p from the decomposition in prime factors of a given number n (n is a non-null natural number).

			printf("Enter a number: ");
			scanf_s("%d", &n);
			int nn = n, e = 0;

			do
			{
				printf("\nEnter a divisor: ");
				scanf_s("%d", &p);

				if (!isPrime(p))
					printf("You should enter a prime number. Try again.");
			} while (!isPrime(p));

			e = exponentOfDivisor(nn, p, e);
			if (e == 0)
				printf("%d is not a divisor of %d \n", p, n);
			else
				printf("The exponent of this divisor is %d \n", e);
		}

		//Option 3
		else if (o == 3)
		{
			//b.Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.
			if (read)
			{
				printf("\nDo you want to use the read array? \n1. yes \n2. no");
				scanf_s("%d", &w);
				if (w == 1)
				{
					printf("The array is:");
					for (i = 0; i < l; i++)
						printf(" %d", v[i]);
					printf("\n");
				}
				else
				{
					printf("Type the size of the array:");
					scanf_s("%d", &l);
					printf("Type the elements:\n");
					reading(v, l, &read);
				}
			}
			else
			{
				printf("Type the size of the array:");
				scanf_s("%d", &l);
				printf("Type the elements:\n");
				reading(v, l, &read);
			}

			int maxLen = 0, maxIndex = 0;
			lcs(v, l, &maxLen, &maxIndex);

			printf("\nThe longest contiguous subsequence is: ");
			for (i = maxIndex; i < maxIndex + maxLen; i++)
				printf("%d ", v[i]);
		}

		//Option 4
		else
		{
			printf("Goodbye!");
			return 0;
		}
	}
	return 0;
}

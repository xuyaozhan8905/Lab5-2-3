#include<stdio.h>
#include<stdlib.h>
#define issue 5
#define rating 10

void recordresponse(int i, int response);
void highest();
void lowest();
float average(int issues);
void display();

int Response[issue][rating];
const char *topic[issue] = { "Global warming","The economy","War","Health Care","Education" };

int main()
{
	int response,i;

	do
	{
		printf("Please rate the following topics on a scale from 1 - 10\n 1= least important, 10 = most important\n");
		for (i = 0; i < issue; i++)
		{
			do
			{
				printf("%s",topic[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
		scanf_s("%d", &response);
	} while (response != 1);
	display();
	system("pause");
}
void recordresponse(int i, int response)
{
	Response[i][response- 1]++;
}
void highest()
{
	int highrating = 0;
	int hightopic = 0;
	int i, j;
	for (i=0;i<issue;i++)
	{
		int topicrating = 0;
		for (j=0;j<rating;j++)
		{
			topicrating += Response[i][j] * (j + 1);
		}
		if (highrating<topicrating)
		{
			highrating = topicrating;
			hightopic = i;
		}
	}
	printf("The highest rated topic was %s with a total rating of %d\n",topic[hightopic],highrating);
}
void lowest()
{
	int lowrating;
	int lowtopic = 0;
	int i, j;
	for (i=0;i<issue;i++)
	{
		int topicrating = 0;
		for (j=0;j<rating;j++)
		{
			topicrating += Response[i][j] * (j + 1);

		}
		if (i == 0)
		{
			lowrating = topicrating;
		}
		if (lowrating>topicrating)
		{
			lowrating = topicrating;
			lowtopic = i;
		}
	}
	printf("The lowest rated topic was %s with a total rating of %d\n",topic[lowtopic],lowrating);
}
float average(int issues)
{
	float total = 0;
	int counter=0, j;
	for (j=0;j<rating;j++)
	{
		if (Response[issues][j]!=0)
		{
			total += Response[issues][j] * (j + 1);
			counter += Response[issues][j];
		}
	}
	return total / counter;
}
void display()
{
	int i, j;
	printf("%20s","Topic");
	for (i=1;i<=rating;i++)
	{
		printf("%4d",i);
	}
	printf("%20s","Average rating");
	for (i=0;i<issue;i++)
	{
		printf("\n%20s",topic[i]);
		for (j=0;j<rating;j++)
		{
			printf("%4d",Response[i][j]);
		}
		printf("%20.2f",average(i));
	}
	printf("\n");
	highest();
	lowest();
}
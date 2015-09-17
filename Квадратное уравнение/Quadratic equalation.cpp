#include <stdio.h>
#include <math.h>
#include <float.h>

const int InfiniteRoots = -1;
int SolveSquare1(double a, double b, double c, double* x1, double* x2);
double Input(const char name[]);
bool AskYorN();

int main()
{
	printf("# SolveSquare v.1\n\n");
	do
	{
		double a = 0, b = 0, c = 0;
		printf("# Enter a,b,c for a*x^2+b*x+c=0\n");
		a = Input("a");
		b = Input("b");
		c = Input("c");
		printf("Your equalation: %lg*x^2+%lg*x+%lg=0\n", a, b, c);
		double x1 = 0, x2 = 0;
		int nRoots = SolveSquare1(a, b, c, &x1, &x2);
		switch (nRoots)
		{
		case 2:
			printf("Equalation has 2 roots: %lg и %lg\n", x1, x2);
			break;
		case 1:
			printf("Equalation has 1 root: %lg\n", x1);
			break;
		case 0:
			printf("Equalation doesn't have roots :c\n");
			break;
		case -1:
			printf("Equalation has infinite numbers of roots\n");
		}
		printf("Do you want to solve another equalation?\n");
	}
	while (AskYorN());
	return 0;
}

double Input(const char name[])
{
	double val = 0;
	int noError=0;
	do
	{
		printf("#Input %s\n>", name);
		noError=scanf_s("%lg", &val);
		getchar();
	} while (!noError);
	return val;
}

int SolveSquare1(double a, double b, double c, double* const x1, 
	double* const x2)
{
	if (fabs(a) > DBL_EPSILON)
	{
		if (b)
		{
			if (c)
			{
				double D = b*b - 4 * a*c;
				if (D > 0)
				{
					*x1 = (b - sqrt(D)) / (-2 * a);
					// Возможно стоит попробовать x1 = -b/2a+sqrt(b*b/(4a*a)-c/a)
					*x2 = (b + sqrt(D)) / (-2 * a);
					return 2;
				}
				else if (!D)
				{
					*x1 = (b / (-2 * a));
					return 1;
				}
				else
					return 0;
			}
			else
			{
				// *x1 = 0;
				*x2 = -b / a;
				return 2;
			}
		}
		else if (!c)
			//{ *x1 = 0;
			return 1;
			//}
		else if (-c / a > 0)
		{
			*x1 = sqrt(-c / a);
			return 1;
		}
		else return 0;
	}
	else if (b)
	{
		if (c) *x1 = -c / b;
		return 1;
	}
	else return -1;
}

bool AskYorN()
{
	printf("(y/n)\n>");
	char answer=0;
	for (int i = 0; i < 100; ++i)
	{
		scanf_s("%c", &answer);
		if (answer == 'Y' || answer == 'y') return 1;
		else if (answer == 'N' || answer == 'n') return 0;
		printf("You should enter 'Y'/'y' or 'N'/'n'\n>");
	}
	return 0;
}
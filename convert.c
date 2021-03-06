#include<stdio.h>
#include<stdlib.h>
float ctof (float x)
{
	return x*1.8+32;
}
float ftoc (float x)
{
	return (x-32)*5.0/9.0;
}
float ctok (float x)
{
	return x+273.15;
}
float ktoc (float x)
{
	return x-273.15;
}

int main(int argc, char *argv[])
{
	float c;
	if (argc!=1)
		c = atof(argv[1]);
	else
	{
		printf("Error!");
		return 1;
	}
	if (argc==3)
		switch (*argv[2])
		{
			case 'C':
			case 'c':
				if (ctok(c) < 0)
					printf("Temperature is less than absolute zero!\n");
				else
					printf("%.2lf F\n%.2f K", ctof(c), ctok(c));
				break;
			case 'F':
			case 'f':
				if (ctok(ftoc(c)) < 0)	
					printf("Temperature is less than absolute zero!\n");
				else	
					printf("%.2f C\n%.2f K", ftoc(c), ctok(ftoc(c)));
				break;
			case 'K':
			case 'k':
				if (c < 0)
					printf("Temperature is less than absolute zero!\n");
				else
					printf("%.2f C\n%.2f F", ktoc(c), ctof(ktoc(c)));
				break;
		}
	else
	{
		printf ("%.2f C:\n", c);
		if (ctok(c) < 0)
			printf("Temperature is less than absolute zero!\n");
		else
			printf("%.2f F\n%.2f K\n", ctof(c), ctok(c));
		printf ("%.2f F:\n", c);
		if (ctok(ftoc(c)) < 0)	
			printf("Temperature is less than absolute zero!\n");
		else
			printf("%.2f C\n%.2f K\n", ftoc(c), ctok(ftoc(c)));
		printf ("%.2f K:\n", c);
		if (c < 0)
			printf("Temperature is less than absolute zero!\n");
		else
			printf("%.2f C\n%.2f F\n", ktoc(c), ctof(ktoc(c)));
		}

return 0;
}

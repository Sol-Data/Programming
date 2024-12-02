   //A program for calculating biorhythms written in C language

   #include <stdio.h>
   #include <math.h>
   #include <time.h>
   #define PI 3.1415926535897932384626433832795
   
   int Days(int year, int month, int day)
   {
       //The variable where the day value will be stored    
       int count = 0;
       //Array to count the number of months    
       int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
       int i;
       //365 days in non-leap years, 366 days in leap years
       for (i = 0; i<year; i++)
       {
           //In leap years
             if (i % 4 == 0) count += 366;
             else count += 365;
       } 
       for (i = 0; i< month; i++)
       {
           //If the year is a leap year  
           if (year % 4 == 0)
           {
               //February is the 29th
   	       if (i == 1) count += (mon[i] + 1);
               else count += mon[i];
           }
           //When not 
   	   else
   	   {
   		count += mon[i];
   	   }
       }
       //Days remaining value  
       count += day;
       return count;
   }
   void GetBirth(int *yy, int *mm, int *dd)
   {
       while (1)
       {
   	   printf("Enter your birthday (YYYY MM DD) : ");
   	   scanf("%d %d %d", yy, mm, dd);
   	   if (*mm < 1 || *mm>12 || *dd < 1 || *dd >31)
   	       printf("The value entered is not valid.\n");
   	   else
               return;
       }
   }
   void CalcRhythm(double *b, double *e, double *i, double *s, int surviveday)
   {
       *b = sin((2 * PI* ((double)surviveday / 23)));
       *e = sin((2 * PI* ((double)surviveday / 28)));
       *i = sin((2 * PI* ((double)surviveday / 33)));
       *s = sin((2 * PI* ((double)surviveday / 38)));
   }
   void Print(double body, double emotion, double intelligent, double sense, int tyear,
   int tmonth, int tday, int uyear, int umonth, int uday)
   {
       double bb, ee, ii, ss;
       int i;
    
       system("cls");
       printf("%d year. %d month. %d day, Born on %d year. %d month. %d day, your biorhythms are as follows. \n\n", tyear, tmonth
   , tday, uyear, umonth, uday);
       printf("Item\t-100%%==============0%%==============+100%%\n");
       //Body Graph  
       printf("Body\t");
       if (body*10 < 0)
       {
   	   bb = floor(body * 10 *-1);
   	   for (i = 10; i > bb; i--) printf("□");
   	   for (i = bb; i > 0; i--) printf("■");
   	   for (i = 0; i < 10; i++) printf("□");
        }
        else
        {
   	   bb = floor(body * 10);
   	   for (i = 0; i < 10; i++) printf("□");
   	   for (i = 0; i < bb; i++) printf("■");
   	   for (i = bb; i < 10; i++) printf("□");
   	}
        printf("\t%.2lf%%\n", body * 100);
   
        //Emotion Graph   
   	printf("Emotion\t");
   	if (emotion * 10 < 0)
   	{
   	    ee = floor(emotion * 10 *-1);
   	    for (i = 10; i > ee; i--) printf("□");
   	    for (i = ee; i > 0; i--) printf("■");
   	    for (i = 0; i < 10; i++) printf("□");
   	}
   	else
   	{
   	    ee = floor(emotion * 10);
   	    for (i = 0; i < 10; i++) printf("□");
   	    for (i = 0; i < ee; i++) printf("■");
   	    for (i = ee; i < 10; i++) printf("□");
   	}
   	printf("\t%.2lf%%\n", emotion * 100);
   
   	//Intelligence Graph   
   	printf("Intelligence\t");
   	if (intelligent * 10 < 0)
   	{
   	    ii = floor(intelligent * 10 *-1);
   	    for (i = 10; i > ii; i--) printf("□");
   	    for (i = ii; i > 0; i--) printf("■");
   	    for (i = 0; i < 10; i++) printf("□");
   	}
   	else
   	{
   	    ii = floor(intelligent * 10);
   	    for (i = 0; i < 10; i++) printf("□");
   	    for (i = 0; i < ii; i++) printf("■");
   	    for (i = ii; i < 10; i++) printf("□");
   	}
   	printf("\t%.2lf%%\n", intelligent * 100);
   
   	//Sense Graph    
   	printf("sense\t");
   	if (sense * 10 < 0)
   	{
   	    ss = floor(sense * 10 *-1);
    	    for (i = 10; i > ss; i--) printf("□");
   	    for (i = ss; i > 0; i--) printf("■");
   	    for (i = 0; i < 10; i++) printf("□");
   	}
   	else
   	{
   	    ss = floor(sense * 10);
   	    for (i = 0; i < 10; i++) printf("□");
   	    for (i = 0; i < ss; i++) printf("■");
   	    for (i = ss; i < 10; i++) printf("□");
   	}
   	printf("\t%.2lf%%\n", sense * 100);
   }
   void main()
   {
   	int uyear, umonth, uday;
   	int tyear, tmonth, tday;
   	int surviveday;
   	char exit;
   	double body, emotion, intelligent, sense;
   
   	time_t current;
  	struct tm *d;
   
  	printf("Enter your birthday and we'll let you know today's biorhythm!\n\n");
   
   	while (1)
  	{
   	    current = time(NULL);
   	    d = localtime(&current);
   	    tyear = 1900 + (d->tm_year); tmonth = (d->tm_mon) + 1; tday = (d->
    tm_mday);
   
   	    printf("오늘은 %dyear %dmonth %dday.\n", tyear, tmonth, tday);
   	    GetBirth(&uyear, &umonth, &uday);
   	    surviveday = (Days(tyear, tmonth, tday)-Days(uyear, umonth, uday)) + 1;
       //The function adds +1 because the base date is day 0;
  
  	    CalcRhythm(&body, &emotion, &intelligent, &sense, surviveday);
   	    Print(body, emotion, intelligent, sense, tyear, tmonth, tday, uyear, umonth,
    uday);
   	    printf("\nEnter Y to return to the beginning or N to exit the program : ");
  
  	    fflush(stdin);
   	    scanf("%c", &exit);
   	    switch (exit)
   	    {
   	    case 'n':
   	    case 'N':
   	        system("cls");
   		printf("Exit the program. ");
   		return;
   
  	    default:
   	    case 'y':
   	    case 'Y':
   		system("cls");
   		break;
   	    }
   	}
    }
   
  

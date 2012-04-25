#include <math.h>
#include <stdio.h>

/*
NOTE:
1) minimum granular angle for a minute hand = 360 degrees/60 minutes = 6 degrees
2) minimum granular angle for a hour hand = 360 degrees / 12 hours = 30 degrees
3) total hour hand angle = 
hour angle + (1/12 * minute angle) 
	==> because hour hand traves 30 degrees for every 360 degrees travelled by 
		minute hand so 30 degrees / 360 degress = 1/12

Firstly calculate the angle for hour and minute hands keeping 12'o clock as base. 
Then subtract the values to find the difference in angle.

*/


float find_angle(int hour, int minute)
{
	float minute_angle = minute * 6.0;
	float hour_angle = ((hour%12) * 30.0) + (minute_angle / 12.0);

	if (minute_angle > hour_angle) return minute_angle-hour_angle;
	else return hour_angle-minute_angle;
}

int main()
{
	int hour, minute;
	
	printf("Hour: ");
	scanf("%d", &hour);

	printf("Minute: ");
	scanf("%d", &minute);

	if (hour < 0 || hour > 12) {
		printf("invalid hour (0-12) : %d\n", hour);
		return 0;
	}
		
	if (minute < 0 || minute > 60) {
		printf("invalid minute (0-60) : %d\n", minute);
		return 0;
	}

	printf("Angle between %d hour and %d minutes = %3.1f degrees \n", 
			hour, minute, find_angle(hour, minute));

	return 0;
}



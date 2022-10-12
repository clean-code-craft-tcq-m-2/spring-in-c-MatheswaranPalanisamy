#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void)
{
    emailAlertCallCount++;
}

void ledAlerter(void)
{
    ledAlertCallCount++;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    int setlength = sizeof(alerters) / sizeof(alerters[0])
    int counter = 0;

    if(computedStats.max > maxThreshold)
    {
        while(counter < setlength)
        {
            if(alerters[counter] != (void *)0)
            {
                alerters[counter]();
            }
            counter++;
        }
    }
}

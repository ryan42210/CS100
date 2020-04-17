#include <stdio.h>

// This function calculate the minutes bewteen two time.
int timeCal(int h1, int m1, int h2, int m2) {
    int min = (h2 - h1) * 60 - m1 + m2;
    return min;
}

// The following two function receive the length of lecture/rest time and give
// up/down of mood level
float mdDown(int min) {
    float down;
    if (min <= 60)
        down = 0.4 * min;
    else
        down = 24 + (min - 60) * 0.8;
    return down;
}
float mdUp(int min) {
    float up = min * 0.5;
    return up;
}

int main() {
    printf("How many lectures today?\n");
    int lecNum = 3;
    scanf("%d", &lecNum);  // read the number of lectures

    float mdLv = 100.0;

    int h1, h2, m1, m2;

    int lastHr = 8;
    int lastMin = 0;
    int restTime, lecTime;

    for (int i = 0; i < lecNum; i++) {
        scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);  // read the time of lecture

        // calculate the rest time BEFORE lecture and add it to mood level
        restTime = timeCal(lastHr, lastMin, h1, m1);
        if (mdLv < 100.0) {
            if (100.0 - mdLv >= mdUp(restTime))
                mdLv = mdLv + mdUp(restTime);
            else
                mdLv = 100.0;
        } else
            mdLv = 100.0;

        lecTime = timeCal(h1, m1, h2, m2);
        mdLv = mdLv - mdDown(lecTime);

        if (mdLv <= 0) {
            printf("Gezi Wang has been sent to hospital. ");
            break;
        } else
            lastHr = h2;
        lastMin = m2;
    }
    if (mdLv>0){
        restTime = timeCal(lastHr, lastMin, 22, 0);
        mdLv = mdLv + mdUp(restTime);

        if (mdLv > 100.0) mdLv = 100.0;

        printf("His mood level is %.1f at the end of the day. ", mdLv);
    }
    return 0;
}
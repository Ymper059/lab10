#include <stdio.h>
#include <locale.h>
#include "task2.h"
int get_duration(int start_sec, int end_sec) {
    return end_sec - start_sec;
}
int check_status(int duration_sec) {
    if (duration_sec <= 30) {
        return -1; 
    }
    else if (duration_sec >= 45) {
        return 0;  
    }
    else {
        return 1;  
    }
}
int get_full_minutes(int total_sec) {
    return total_sec / 60;
}

void print_time_mm_ss(int minutes, int seconds) {
    printf("%02d:%02d\n", minutes, seconds);
}
void process_stage(int start_sec, int end_sec) {
    setlocale(LC_CTYPE, "RUS");
    int duration = get_duration(start_sec, end_sec);
    int status = check_status(duration);
    int full_min = get_full_minutes(duration);
    int rem_sec = duration % 60;
    printf("Время: ");
    print_time_mm_ss(full_min, rem_sec);
    printf("Статус: ");
    switch (status) {
    case -1:
        printf("Дисквалификация\n");
        break;
    case 0:
        printf("Норма\n");
        break;
    case 1:
        printf("Штраф\n");
        break;
    }
}
double calculate_speed(double distance_m, int start_sec, int end_sec) {
    int duration = get_duration(start_sec, end_sec);
    if (duration <= 0) return 0.0; 
    return (distance_m / duration) * 3.6;
}
int dynamic_record(int current_sec, int best_sec) {
    if (current_sec < best_sec) {
        return 1;
    }
    return 0; 
}

int age_coefficient(int finish_sec, int age_group) {
    int bonus = 0;
    if (age_group == 1) {
        bonus = 15;
    }
    else if (age_group == 3) {
        bonus = 10;
    }
    return finish_sec - bonus;
}
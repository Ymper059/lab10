#include <stdio.h>
#include <locale.h>
#include "task2.h"
int main() {
    setlocale(LC_CTYPE, "RUS");
    int num_stages, i;
    double distance_m;
    printf("--- СИСТЕМА ХРОНОМЕТРАЖА ---\n");
    printf("Введите длину трассы в метрах: ");
    scanf("%lf", &distance_m);
    printf("Введите количество этапов : ");
    scanf("%d", &num_stages);
    int prev_finish = 0; 
    for (i = 1; i <= num_stages; i++) {
        int bib, start_sec, end_sec;
        printf("\nЭтап %d\n", i);
        printf("Введите код спортсмена: ");
        scanf("%d", &bib);
        if (bib == 1) {
            printf("Внимание! Код 1 зарезервирован.\n");
        }
        printf("Введите время старта : ");
        scanf("%d", &start_sec);
        printf("Введите время финиша (в секундах): ");
        scanf("%d", &end_sec);
        process_stage(start_sec, end_sec);
        double speed = calculate_speed(distance_m, start_sec, end_sec);
        printf("Скорость: %.1f км/ч\n", speed);
        if (i > 1) {
            int is_record = dynamic_record(end_sec - start_sec, prev_finish - (end_sec - start_sec)); 
            if (is_record) {
                printf("!!! НОВЫЙ РЕКОРД ЭТАПА !!!\n");
            }
        }
        prev_finish = end_sec;
    }
    int group;
    printf("\n--- РАСЧЕТ ВОЗРАСТНОГО КОЭФФИЦИЕНТА ---\n");
    printf("Введите итоговое время спортсмена (сек): ");
    int final_time;
    scanf("%d", &final_time);
    printf("Введите возрастную группу (1-дети, 2-взрослые, 3-ветераны): ");
    scanf("%d", &group);

    int corrected_time = age_coefficient(final_time, group);
    printf("Скорректированное время: %d сек.\n", corrected_time);
    return 0;
}
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int get_duration(int start_sec, int end_sec);
int check_status(int duration_sec);
int get_full_minutes(int total_sec);
void print_time_mm_ss(int minutes, int seconds);
void process_stage(int start_sec, int end_sec);
double calculate_speed(double distance_m, int start_sec, int end_sec);
int dynamic_record(int current_sec, int best_sec);
int age_coefficient(int finish_sec, int age_group);
#endif

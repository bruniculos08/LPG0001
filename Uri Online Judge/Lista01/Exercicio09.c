#include <stdio.h>
#include <math.h>
 
int main() {
    int game_hours, game_minutes, game_seconds, initial_hour, initial_minute, initial_seconds, final_hour, final_minute, final_seconds;

    do
    {
        scanf("%i %i %i %i", &initial_hour, &initial_minute, &final_hour, &final_minute);
    } while (initial_hour > 24 || initial_hour < 0 || final_hour > 24 || final_hour < 0 || initial_minute > 60 || initial_minute < 0 || final_minute > 60 || final_minute < 0);
    initial_seconds = (initial_hour*3600) + (initial_minute*60);
    final_seconds = (final_hour*3600) + (final_minute*60);
    if (initial_seconds == final_seconds)
    {
        game_seconds = 24*3600;
    }
    else if (initial_seconds > final_seconds )
    {
        game_seconds = (final_seconds+(24*3600)) - initial_seconds;
    }
    else {
        game_seconds = final_seconds - initial_seconds; 
    }
    game_hours = game_seconds/3600;
    game_minutes = (game_seconds-(game_hours*3600))/60;    
    
    printf("O JOGO DUROU %i HORA(S) E %i MINUTO(S)\n", game_hours, game_minutes);
    return 0;
}
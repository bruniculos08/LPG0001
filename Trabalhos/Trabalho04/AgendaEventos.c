#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct horario {
    int hora, minuto;
} Horario;

typedef struct evento{
    Data data_evento;
    Horario hora_incial, hora_final;
    char descricao[50], local[20];
} Evento;

Horario add_horario(int h){
    Horario nova_hora;
    if (h == 0)
    {
        printf("Type the inicial hour: ");
        do
        {
            scanf("%i", &nova_hora.hora);
        } while (nova_hora.hora > 23 || nova_hora.hora < 0);
        
        printf("Type the inicial minute: ");
        do
        {
            scanf("%i", &nova_hora.minuto);
        } while (nova_hora.minuto > 59 || nova_hora.minuto < 0);
        return nova_hora;
    }
    else if (h == 1){
        printf("Type the final hour: ");
        do
        {
            scanf("%i", &nova_hora.hora);
        } while (nova_hora.hora > 23 || nova_hora.hora < 0);
        
        printf("Type the final minute: ");
        do
        {
            scanf("%i", &nova_hora.minuto);
        } while (nova_hora.minuto > 59 || nova_hora.minuto < 0);
        return nova_hora;

    }


}

Evento add_evento(){

    Evento novo_evento;
    
    printf("Type the event year: ");
    scanf("%i", &novo_evento.data_evento.ano);
    
    printf("Type the event month: ");
    scanf("%i", &novo_evento.data_evento.mes);
    
    printf("Type the event day: ");
    scanf("%i", &novo_evento.data_evento.dia);

    novo_evento.hora_incial = add_horario(0);
    novo_evento.hora_final = add_horario(1);

    printf("Type the event description: ");
    scanf("%i", &novo_evento.descricao);

    printf("Type the event local: ");
    scanf("%i", &novo_evento.local);

    return novo_evento;
}

//* retorna 0 se o evento 0 acontecerá antes...
int compara_data(Evento evento_0, Evento evento_1){
    if (evento_0.data_evento.ano > evento_1.data_evento.ano) return 1;
    if (evento_0.data_evento.ano < evento_1.data_evento.ano) return 0;
    if (evento_0.data_evento.ano == evento_1.data_evento.ano){
        if (evento_0.data_evento.mes > evento_1.data_evento.mes) return 1;
        if (evento_0.data_evento.mes < evento_1.data_evento.mes) return 0;
        if (evento_0.data_evento.mes < evento_1.data_evento.mes) {
            if (evento_0.data_evento.dia > evento_1.data_evento.dia) return 1;
            if (evento_0.data_evento.dia < evento_1.data_evento.dia) return 0;
            if (evento_0.data_evento.dia == evento_1.data_evento.dia) {
                if (evento_0.hora_incial.hora > evento_1.hora_incial.hora) return 1;
                if (evento_0.hora_incial.hora < evento_1.hora_incial.hora) return 0;
                if (evento_0.hora_incial.hora == evento_1.hora_incial.hora) {
                    if (evento_0.hora_incial.minuto > evento_1.hora_incial.minuto) return 1;
                    if (evento_0.hora_incial.minuto < evento_1.hora_incial.minuto) return 0;
                    if (evento_0.hora_incial.minuto == evento_1.hora_incial.minuto) {
                        return 0;
                    }    
                }    
            }
        }
    }
}

void ordenar_vetor(Evento *agenda){
    Evento aux_evento;
    for (int i = 0; i < (sizeof(*agenda)/sizeof(agenda[0])); i++)
    {
        for (int j = 0; j < (sizeof(*agenda)/sizeof(agenda[0])); j++)
        {
            if (compara_data(agenda[i], agenda[j]) == 1 && i!=j)
            {
                aux_evento = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = aux_evento;
            }
        }
    }
}

void cadastrar(Evento *agenda){
    Evento novo_evento = add_evento();
    agenda = realloc(agenda, sizeof(*agenda) + sizeof(Evento));
    agenda[-1] = novo_evento;
    ordenar_vetor(agenda);
}

int main (void) {
    FILE *arquivo_agenda;
    arquivo_agenda = fopen("agenda", "rb");
    Evento *agenda;
    agenda = malloc(sizeof(Evento));
    strcpy(agenda[0].local, "testeA");
    strcpy(agenda[0].descricao, "teste");
    //printf("%s", agenda[0].local);
    fseek(arquivo_agenda, 0, SEEK_SET);
    fwrite(agenda, sizeof(*agenda), 1, arquivo_agenda);
    fread(agenda, sizeof(*agenda), 1, arquivo_agenda);
    printf("%s ", agenda[0].local);
    printf("%i", sizeof(*agenda)/sizeof(agenda[0]));
}
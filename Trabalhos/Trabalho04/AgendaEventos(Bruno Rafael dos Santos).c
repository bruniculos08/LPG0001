
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
    Horario hora_inicial, hora_final;
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

    novo_evento.hora_inicial = add_horario(0);
    novo_evento.hora_final = add_horario(1);

    printf("Type the event description: ");
    scanf("%s", novo_evento.descricao);

    printf("Type the event local: ");
    scanf("%s", novo_evento.local);

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
                if (evento_0.hora_inicial.hora > evento_1.hora_inicial.hora) return 1;
                if (evento_0.hora_inicial.hora < evento_1.hora_inicial.hora) return 0;
                if (evento_0.hora_inicial.hora == evento_1.hora_inicial.hora) {
                    if (evento_0.hora_inicial.minuto > evento_1.hora_inicial.minuto) return 1;
                    if (evento_0.hora_inicial.minuto < evento_1.hora_inicial.minuto) return 0;
                    if (evento_0.hora_inicial.minuto == evento_1.hora_inicial.minuto) {
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
    agenda[sizeof(*agenda)/sizeof(Evento)] = novo_evento;
    ordenar_vetor(agenda);
}

void eventos_data(Evento *agenda, Data data_usuario){
    int exist = 1;
    for (int i = 0; i < sizeof(*agenda)/sizeof(Evento); i++){
        if (agenda[i].data_evento.dia == data_usuario.dia && agenda[i].data_evento.mes == data_usuario.mes && agenda[i].data_evento.ano == data_usuario.ano){
            printf("Evento: %s\nLocal: %s\n", agenda[i].descricao, agenda[i].local);
            exist = 0;
     }
    }
    if (exist == 1) printf("Not found any event.\n");
}

void todos_eventos(Evento *agenda){
    int exist = 1;
    for (int i = 0; i < sizeof(*agenda)/sizeof(Evento); i++){
        if (agenda == NULL) printf("Error, this schedule is empty.\n");
        else printf("Evento: %s\nLocal: %s\n", agenda[i].descricao, agenda[i].local);
    }
}

void cinco_eventos(Evento *agenda, Data data_atual){
    int j = 0;
    for (int i = 0; i < sizeof(*agenda)/sizeof(Evento); i++){
        if (agenda[i].data_evento.dia >= data_atual.dia && agenda[i].data_evento.mes >= data_atual.mes && agenda[i].data_evento.ano >= data_atual.ano){
            printf("Evento: %s\nLocal: %s\n", agenda[i].descricao, agenda[i].local);
            j++;
        }
        if (j == 5) break;
    }
    if (j == 0) printf("There is no scheduled event.");
}

void remover(Evento *agenda, Data data_evento, Horario hora_inicial){
    Evento *nova_agenda;    
    nova_agenda = malloc(((sizeof(*agenda)/sizeof(Evento))-1)*sizeof(Evento));

    for (int i = 0, j = 0; i < (sizeof(*agenda)/sizeof(Evento)); i++){
        if (data_evento.dia == agenda[i].data_evento.dia && data_evento.mes == agenda[i].data_evento.mes && data_evento.ano == agenda[i].data_evento.ano && hora_inicial.hora == agenda[i].hora_inicial.hora && hora_inicial.minuto == agenda[i].hora_inicial.minuto){

        }
        else *(nova_agenda+i) = *(agenda+i);
    }

    free(agenda);
    agenda = malloc(((sizeof(*nova_agenda)/sizeof(Evento)))*sizeof(Evento));
    for (int i = 0; i < (sizeof(*nova_agenda)/sizeof(Evento)); i++) *(agenda+i) = *(nova_agenda+1);
    free(nova_agenda);
}

int main (void) {
    FILE *arquivo_agenda;
    arquivo_agenda = fopen("agenda", "r+b");
    
    //* colocoando dados no vetor agenda
    Evento *agenda;
    todos_eventos(agenda);
    int tamanho_vetor = 0, option;
    fseek(arquivo_agenda, 0, SEEK_SET);
    

    if (arquivo_agenda == NULL)
    {
        printf("Error");
        return 1;
    }
    else 
    {
        do
        {
            printf("realocating schedule\n");
            agenda = realloc(agenda, (tamanho_vetor+1)*sizeof(Evento));
            fread(&agenda[tamanho_vetor], sizeof(Evento), 1, arquivo_agenda);
            tamanho_vetor++;
        } while (!feof(arquivo_agenda));
        
    }

    do
    {
        do
        {
            printf("Type your option: \n0.Cadastrar\n1.Mostrar todos os eventos da agenda\n2.Mostrar todos os eventos de uma data\n3.Mostrar 5 eventos proximos\n4.Remover um evento\n5.Sair do programa\n");
            scanf("%i", &option);
        } while (option < 0 || option > 5);
        
            Data data_usuario;
            Horario hora_usuario;
            
            switch(option){
            case 0:
                cadastrar(agenda);
                break;
                
            case 1:
                todos_eventos(agenda);
                printf("todos_eventos\n");
                break;
        
            case 2:
                printf("todos_eventos");
                printf("Type the year: ");
                scanf("%i", data_usuario.ano);
                printf("Type the month: ");
                scanf("%i", data_usuario.mes);
                printf("Type the day: ");
                scanf("%i", data_usuario.dia);
                eventos_data(agenda, data_usuario);
                break;
            
            case 3:
                printf("Type today's year: ");
                scanf("%i", data_usuario.ano);
                printf("Type today's month: ");
                scanf("%i", data_usuario.mes);
                printf("Type today's day: ");
                scanf("%i", data_usuario.dia);
                cinco_eventos(agenda, data_usuario);
                break;
            case 4:
                printf("Type the year: ");
                scanf("%i", data_usuario.ano);
                printf("Type the month: ");
                scanf("%i", data_usuario.mes);
                printf("Type the day: ");
                scanf("%i", data_usuario.dia);
                printf("Type the hour: ");
                scanf("%i", hora_usuario.hora);
                printf("Type the minute: ");
                scanf("%i", hora_usuario.minuto);
                remover(agenda, data_usuario, hora_usuario);
                break;
            case 5: 
                break;
        }
    } while (option);

    for (int i = 0; i < sizeof(*agenda)/sizeof(Evento); i++)
    {
       fwrite(&agenda[i], sizeof(Evento), 1, arquivo_agenda);
    }
    fclose(arquivo_agenda);
    free(agenda);
}
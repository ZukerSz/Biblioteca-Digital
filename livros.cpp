//alunos: Iuker de Souza Santos, Gabriel Bauer

#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    char autor[MAX_NOME];
    char categoria[MAX_NOME];
} Livro;

Livro biblioteca[MAX_LIVROS];
int contador_livros = 0;

void inserir_livro(char nome[], char autor[], char categoria[]) {
    if (contador_livros < MAX_LIVROS) {
        strcpy(biblioteca[contador_livros].nome, nome);
        strcpy(biblioteca[contador_livros].autor, autor);
        strcpy(biblioteca[contador_livros].categoria, categoria);
        contador_livros++;
        printf("\n");
        printf("O livro '%s' foi inserido com sucesso!\n", nome);
        printf("\n");
    } else {
        printf("A biblioteca está cheia! Não é possível inserir mais livros.\n");
    }
}

void buscar_livro_por_nome(char nome[]) {
    int encontrado = 0;
    for (int i = 0; i < contador_livros; i++) {
        if (strcmp(biblioteca[i].nome, nome) == 0) {
            printf("\n");
            printf("Livro encontrado: %s, Autor: %s, Categoria: %s\n", biblioteca[i].nome, biblioteca[i].autor, biblioteca[i].categoria);
            printf("\n");

            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("\n");
        printf("Nenhum livro encontrado com o nome '%s'.\n", nome);
        printf("\n");
    }
}

void buscar_livro_por_autor(char autor[]) {
    int encontrado = 0;
    for (int i = 0; i < contador_livros; i++) {
        if (strcmp(biblioteca[i].autor, autor) == 0) {
            printf("\n");
            printf("Livro encontrado: %s, Autor: %s, Categoria: %s\n", biblioteca[i].nome, biblioteca[i].autor, biblioteca[i].categoria);
            printf("\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("\n");
        printf("Nenhum livro encontrado com o autor '%s'.\n", autor);
        printf("\n");
    }
}

void remover_livro(char nome[]) {
    int encontrado = 0;
    for (int i = 0; i < contador_livros; i++) {
        if (strcmp(biblioteca[i].nome, nome) == 0) {
            for (int j = i; j < contador_livros - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            contador_livros--;
            printf("\n");
            printf("O livro '%s' foi removido com sucesso!\n", nome);
            printf("\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\n");
        printf("Nenhum livro encontrado com o nome '%s'.\n", nome);
        printf("\n");
    }
}

void menu() {
    int opcao;
    char nome[MAX_NOME];
    char autor[MAX_NOME];
    char categoria[MAX_NOME];

    do {
        printf("--------------------------------------\n");
        printf("--- Biblioteca Imaginária Digital ---\n");
        printf("--------------------------------------\n");
        printf("\n");
        printf("1. Inserir um livro\n");
        printf("\n");
        printf("2. Buscar livro por nome\n");
        printf("\n");
        printf("3. Buscar livro por autor\n");
        printf("\n");
        printf("4. Remover livro\n");
        printf("\n");
        printf("5. Sair\n");
        printf("\n");
        printf("Escolha uma opção: ");
        printf("\n");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("\n");  
                printf("Digite o nome do livro: ");
                printf("\n");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                printf("\n");
                printf("Digite o nome do autor: ");
                printf("\n");
                fgets(autor, MAX_NOME, stdin);
                autor[strcspn(autor, "\n")] = '\0';
                printf("\n");
                printf("Digite a categoria do livro: ");
                printf("\n");
                fgets(categoria, MAX_NOME, stdin);
                categoria[strcspn(categoria, "\n")] = '\0';
                inserir_livro(nome, autor, categoria);
                break;
            case 2:
                printf("\n");
                printf("Digite o nome do livro para buscar: ");
                printf("\n");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscar_livro_por_nome(nome);
                break;
            case 3:
                printf("\n");
                printf("Digite o nome do autor para buscar: ");
                printf("\n");
                fgets(autor, MAX_NOME, stdin);
                autor[strcspn(autor, "\n")] = '\0';
                buscar_livro_por_autor(autor);
                break;
            case 4:
                printf("\n");
                printf("Digite o nome do livro para remover: ");
                printf("\n");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                remover_livro(nome);
                break;
            case 5:
                printf("\n");
                printf("Saindo...\n");
                printf("\n");
                break;
            default:
                printf("\n");
                printf("Opção inválida. Tente novamente.\n");
                printf("\n");
                break;
        }
    } while (opcao != 5);
}

int main() {
    menu();
    return 0;
}

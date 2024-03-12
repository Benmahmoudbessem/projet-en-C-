#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un employé

typedef struct Employee {
    int id;
    char name[50];
    char address[100];
    char phoneNumber[15];
    float salary;
    struct Employee* next;
} Employee;

// Fonction pour créer un nouvel employé

Employee* createEmployee(int id , const char* name, const char* address , const char* phoneNumber , float salary  ) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    if (newEmployee != NULL) {
        newEmployee->id = id;
        strncpy(newEmployee->name, name, sizeof(newEmployee->name) - 1);
        strncpy(newEmployee->address, address, sizeof(newEmployee->address) - 1);
        strncpy(newEmployee->phoneNumber, phoneNumber, sizeof(newEmployee->phoneNumber) - 1);
        newEmployee->salary = salary;
        newEmployee->next = NULL;

    }
    return newEmployee;
}

// Fonction pour ajouter un employé à la liste

void addEmployee(Employee** head, Employee* newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
    } else {
        newEmployee->next = *head;
        *head = newEmployee;
    }
}

// Fonction pour afficher la liste des employés

void displayEmployees(Employee* head) {
    printf("Liste des employes :\n");
    Employee* current = head;
    while (current != NULL) {
        printf("\033[1;31m ID: %d \n \n Nom: %s \n\n Adresse: %s \n \n Telephone: %s \n \n Salaire: %.2f\n\n\n-------------------------------- \033[0m \n",
               current->id, current->name, current->address, current->phoneNumber, current->salary);
        current = current->next;
    }
    printf("\n");

}

// Fonction pour rechercher un employé par ID

Employee* findEmployeeById(Employee* head, int id) {
    Employee* current = head;
    while (current != NULL) {
        if (current->id == id) {
                 printf(" \033[1;31m -----------------------------------\n  \033[0m ");
            return current;
        }
        current = current->next;
    }
    return NULL; // Employé non trouvé
}

// Fonction pour supprimer un employé par ID

void deleteEmployeeById(Employee** head, int id) {
    Employee* current = *head;
    Employee* prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf(" \033[1;31m **Employe avec ID %d non trouve**\n  \033[0m ", id);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf(" \033[1;31m **Employe avec ID %d est supprimer** \n \033[0m ", id);
}

// Fonction pour modifier les détails d'un employé par ID

void updateEmployeeById(Employee* head, int id, const char* newName, const char* newAddress, const char* newPhoneNumber, float newSalary) {
    Employee* current = findEmployeeById(head, id);
    if (current != NULL) {
        strncpy(current->name, newName, sizeof(current->name) - 1);
        strncpy(current->address, newAddress, sizeof(current->address) - 1);
        strncpy(current->phoneNumber, newPhoneNumber, sizeof(current->phoneNumber) - 1);
        current->salary = newSalary;
        printf(" \033[1;31m Details de l'employe avec ID %d mis a jour.\n \033[0m ", id);
    } else {
        printf(" \033[1;31m Employe avec ID %d non trouve.\n \033[0m ", id);
    }
}

// Fonction pour sauvegarder la liste des employés dans un fichier

void saveEmployeesToFile(Employee* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        Employee* current = head;
        while (current != NULL) {
            fprintf(file, "%d\n %s\n %s\n %s\n %.2f\n", current->id, current->name, current->address, current->phoneNumber, current->salary);
            current = current->next;
        }
        fclose(file);
        printf(" \033[1;31m  Liste des employes sauvegarder dans %s \033[0m\n", filename);
    } else {
        printf(" \033[1;31m  Erreur lors de l'ouverture du fichier %s\n", filename);
    }
}

// Fonction pour charger la liste des employés depuis un fichier

Employee* loadEmployeesFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        Employee* head = NULL;
        int id;
        char name[50];
        char address[100];
        char phoneNumber[15];
        float salary;

        while (fscanf(file, "%d %s %s %s %f", &id, name, address, phoneNumber, &salary) == 5) {
            Employee* newEmployee = createEmployee(id, name, address, phoneNumber, salary);
            addEmployee(&head, newEmployee);
        }

        fclose(file);
        printf("Liste des employes chargee depuis %s.\n", filename);
        return head;
    } else {
        printf("Erreur lors de l'ouverture du fichier %s.\n", filename);
        return NULL;
    }
}

// Fonction pour s'authentifier

int authenticate() {
    char username[20];
    char password[20];
    printf("\n\n");
    printf("Veuillez vous connecter\n");
    printf("Nom d'utilisateur : ");
    scanf("%s", username);

    printf("Mot de passe : ");
    scanf("%s", password);

    // Vérification basique du nom d'utilisateur et du mot de passe

    if (strcmp(username, "tekup") == 0 && strcmp(password, "root") == 0) {
        printf("\n\n\n\n");
        printf("\033[1;31m       \n");
        printf("Authentification reussie.   \033[0m \n");
        return 1; // Authentification réussie

        }

        else {
         printf("\033[1;31m       \n");
    printf("\n\t\t Incorrect login credentials. Please try again  \033[0m \n");
    printf("\033[1;31m       \n");
        printf("******  *******    ********** **       *********          \n");
        printf("**        **      **            **     **     **        \n");
        printf("******    **     **            **      *********         \n");
        printf("    **    **      **           **      **                \n");
        printf("    **    **       **         **       **               \n");
        printf("******    **        *** ** ****        **              \033[0m \n");
}
        return 0; // Echec de l'authentification
    }

    // afficher le char n fois

    void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}


    void printHead()
{ system("cls");
printf("\t");
printChar('--',75);
printf("\n\t");
printChar('--',12);
printf("\033[1;31m ");
printf(" "" < B&B > < EMPLOYEE > < MANAGEMENT > < SYSTEM > \033[0m  "" ");
printChar('--',7);
printf("\n\t");
printChar('--',75);

}
    void welcomeMessage() {
    printf("\033[1;31m");

    printf("********* WELCOME TO THE EMPLOYEE MANAGEMENT SYSTEM OF OUR COMPANY ******* \n"  )  ;
    printf("\033[0m");
    printf("--------------------------BESSEM & BILEL-----------------------------------------\n");


}


// Fonction principale

int main() {
printHead();
printf("\n\n");
welcomeMessage();

    if (!authenticate()) {
        printf("Authentification echouer  vous n'etes pas l'utilisateur \n");
        return 1;
    }

    Employee* employeeList = NULL;

    // Chargement des employés depuis un fichier (s'il existe)

    employeeList = loadEmployeesFromFile("employees.txt");

    int choice;
    do {
        printf("1. Ajouter un employe\n");
        printf("2. Afficher la liste des employes\n");
        printf("3. Rechercher un employe par ID\n");
        printf("4. Supprimer un employe par ID\n");
        printf("5. Mettre a jour les details d'un employe par ID\n");
        printf("6. Sauvegarder la liste des employes dans un fichier\n");
        printf("7. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id;
                char name[50];
                char address[100];
                char phoneNumber[15];
                float salary;

                printf("ID de l'employe : ");
                scanf("%d", &id);

                // Vérification si l'ID existe déjà

             if (findEmployeeById(employeeList, id) != NULL) {
           printf("\n\033[1;31m Erreur : L'ID existe deja. Veuillez choisir un autre ID.\033[0m\n");
        break;
    }

                printf("Nom de l'employe : ");
                scanf("%s", name);

                printf("Adresse de l'employe : ");
                scanf("%s", address);

                printf("Numero de telephone de l'employe : ");
                scanf("%s", phoneNumber);

                printf("Salaire de l'employe : ");
                scanf("%f", &salary);


                addEmployee(&employeeList, createEmployee(id, name, address, phoneNumber, salary));
                printf(" \033[1;31m Employe ajoute avec succes. \033[0m \n");
                printf("*****************************************\n\n");
                break;
            }
            case 2:
                displayEmployees(employeeList);
                break;
            case 3: {
                int idToFind;
                printf("ID de l'employe a rechercher : ");
                scanf("%d", &idToFind);

                Employee* foundEmployee = findEmployeeById(employeeList, idToFind);
                if (foundEmployee != NULL) {
                    printf("ID: %d\n\n, Nom: %s\n\n  Adresse: %s\n\n  Telephone: %s\n\n  Salaire: %.2f\n\n",
                           foundEmployee->id, foundEmployee->name, foundEmployee->address, foundEmployee->phoneNumber, foundEmployee->salary);
                } else {
                    printf(" \033[1;31m Employe avec ID %d non trouve.\033[0m \n ", idToFind);
                }
                break;
            }
            case 4: {
                int idToDelete;
                printf("ID de l'employe a supprimer : ");
                scanf("%d", &idToDelete);

                deleteEmployeeById(&employeeList, idToDelete);
                break;
            }
            case 5: {
                int idToUpdate;
                char newName[50];
                char newAddress[100];
                char newPhoneNumber[15];
                float newSalary;

                printf("ID de l'employe a mettre a jour : ");
                scanf("%d", &idToUpdate);

                printf("Nouveau nom de l'employe : ");
                scanf("%s", newName);

                printf("Nouvelle adresse de l'employe : ");
                scanf("%s", newAddress);

                printf("Nouveau numero de telephone de l'employe : ");
                scanf("%s", newPhoneNumber);

                printf("Nouveau salaire de l'employe : ");
                scanf("%f", &newSalary);

                updateEmployeeById(employeeList, idToUpdate, newName, newAddress, newPhoneNumber, newSalary);
                break;
            }
            case 6:
                saveEmployeesToFile(employeeList, "employees.txt");
                break;
            case 7:
                printf("Programme termine.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choice != 7);

    // Libération de la mémoire allouée pour la liste des employés

    Employee* current = employeeList;
    while (current != NULL) {
        Employee* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

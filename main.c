    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    typedef struct  {
            int jour;
            int mois;
            int annee;
    }deadline;

    typedef struct  {
      int id;
      char titre[100];
      char description[200];
      char statut[100];
      deadline A;
    }taches;

    int size=0 , i=0 , choice,j,k ;
    taches T[100];
    void print(){
            printf("-----------------------------------------------\n");
            //printf("entrer la valeur du id:");
            //scanf("%d",&T[i].id);
            printf("entrer la valeur du titre:");
            getchar();
            gets(T[size].titre);
            printf("entrer la valeur du description:");
            getchar();
            gets(T[size].description);
            printf("entrer la valeur du statut (a realiser, en cours de realisation, finalisee):");
            getchar();
            gets(T[size].statut);
            printf("entree la valeur du deadline :");
            scanf("%d/%d/%d",&T[size].A.jour,&T[size].A.mois,&T[size].A.annee);
            T[size].id = size+1;
            size++;
            printf("------------------------------------------------\n");
    }
    void menu(){

        printf("++++++++++++++++++++++++++++++++++++++++++\n");
        printf("[1]Ajouter une nouvelle tache:\n");
        printf("[2]Ajouter plusieurs nouvelles taches:\n");
        printf("[3]tirer les taches par alphabitique:\n");
        printf("[4]Modifier une Tache:\n");
        printf("[5]Supprimer une tache par identifiant:\n");
        printf("[6]Rechercher les Tâches :\n");
        printf("[7]Statistiques :\n");
        printf("[8]Quitter:\n");
        scanf("%d",&choice);

    }

    void affichage(){
                    for ( k = 0; k < size; k++){
                        printf("id : [%d]\n",T[k].id);
                        printf("titre : [%s]\n",T[k].titre);
                        printf("description : [%s]\n",T[k].description);
                        printf("statut : [%s]\n",T[k].statut);
                        printf("deadline : %d/%d/%d\n",T[k].A.jour,T[k].A.mois,T[k].A.annee);
                    }

    }



void sortAlpha() {
    taches temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(T[i].titre, T[j].titre) > 0) {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}

// modifier description
void modifyDescription(int taskid) {
    if (taskid >= 1 && taskid <= size) {
        printf("Saisissez la nouvelle description de la tâche %d:\n", taskid);
        getchar();
        gets(T[taskid - 1].description);
        printf("Description modifiée avec succès !\n");
    } else {
        printf("ID de tache invalide. Veuillez saisir un ID de tache valide.\n");
    }
}


void modifystatut(int taskid) {
    if (taskid >= 1 && taskid <= size) {
        printf("Entrez la nouvelle règle de la mission %d:\n", taskid);
        getchar();
        gets(T[taskid - 1].statut);
        printf("statut modifié avec succès!\n");
    } else {
        printf("ID de tâche invalide. Veuillez saisir un ID de tâche valide.\n");
    }
}

void modifyDeadline(int taskid) {
    if (taskid >= 1 && taskid <= size) {
        printf("Entrez la nouvelle date limite (jour mois année) pour la tâche %d:\n", taskid);
        scanf("%d %d %d", &T[taskid - 1].A.jour, &T[taskid - 1].A.mois, &T[taskid - 1].A.annee);
        printf("Date limite modifiée avec succès !\n");
    } else {
        printf("ID de tâche invalide. Veuillez saisir un ID de tâche valide.\n");
    }
}

void SupprimerTask() {
    int idtemps;
    printf("entrer ID:");
    scanf("%d",&idtemps);
     if (size >0 || size<100) {
        // Déplacez toutes les tâches après la tâche supprimée vers la gauche
   for(i=0;i<size;i++){
        if(idtemps==T[i].id){
        for (j = i+1; j < size-1; j++) {
            T[j] = T[j + 1];
        }
        size--; // Réduisez la taille du tableau pour refléter la suppression
        printf("Tache avec l'identifiant supprimée avec succès!\n");
        break;
        }
    }
    }

    else {
        printf("Identifiant de tâche invalide. Veuillez entrer un identifiant de tâche valide.\n");
    }
}

void recherecheid(){
    int idtemps;
    printf("entrer ID:");
    scanf("%d",&idtemps);
    for (i=0;i<size;i++){
        if(T[i].id==idtemps){
           printf("id : [%d]\n",T[k].id);
                        printf("titre : [%s]\n",T[k].titre);
                        printf("description : [%s]\n",T[k].description);
                        printf("statut : [%s]\n",T[k].statut);
                        printf("deadline : %d/%d/%d\n",T[k].A.jour,T[k].A.mois,T[k].A.annee);
            break;
        }
    }
}

int main()
{


        do{
            menu();
            switch(choice){
            case 1:
                        printf("Tache [%d]:\n", size+1);
                        print();

                    //printf("Le tableau est plein\n");

                break ;
            case 2:
                 if (size < 100) {
                        int numTasks;
                        printf("Combien de tâches voulez-vous ajouter ? ");
                        scanf("%d", &numTasks);
                        if (i + numTasks <= 100) {
                            for (k = 0; k < numTasks; k++) {
                                printf("Tache [%d]:\n", i + k + 1);
                                print();
                            }
                        } else {
                            printf("Impossible d'ajouter autant de tâches, le tableau serait plein.\n");
                        }
                    } else {
                        printf("Le tableau est déjà plein.\n");
                    }
                break ;
            case 3:{

                printf("[1]affichage tout les element:\n");
                printf("[2]trier les tache par ordre alphabitique :\n");
                scanf("%d",&choice);
                    switch(choice){
                    case 1:
                        affichage();
                        break;
                    case 2:
                            sortAlpha();
                        break;
                    }
                    break;
                  }
            case 4:
                    if (size == 0) {
                       printf("Aucune tache a modifier. Ajoutez d'abord des taches.\n");
                        break;
                }

                printf("Entrez l'ID de la tache a modifier : ");
                int taskid;
                scanf("%d", &taskid);

                if (taskid < 1 || taskid > size) {
                    printf("ID de tache invalide. Veuillez entrer un ID valide.\n");
                    break;
                }

                printf("[1] Modifier la description\n");
                printf("[2] Modifier le statut\n");
                printf("[3] Modifier le deadline\n");
                int modificationChoice;
                scanf("%d", &modificationChoice);

                switch(modificationChoice){
                case 1:
                    modifyDescription(taskid);
                    break;
                case 2:
                    modifystatut(taskid);
                    break;
                case 3:
                    modifyDeadline(taskid);
                    break;
                }
                break;
            case 5:
                    SupprimerTask();
                    break;
            case 6:
                printf("[1] Rechercher une tâche par son Id .\n");
                printf("[2] Rechercher une tâche par son Titre\n");
                int rechereche;
                scanf("%d", &rechereche);

                switch(rechereche){
                case 1:
                    recherecheid();
                    break;
                }
                case 8:{
                    printf("Au revoir !\n");
                    break;
                }


                default:
                    printf("Choix invalide. Veuillez reessayer .\n");
                    break;
            }
        }while(choice!=8);
        return 0;
    }



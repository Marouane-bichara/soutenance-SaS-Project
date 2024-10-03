#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int jour, mois, annee;
} Date;

typedef struct
{
    char nom[40], prenom[40], status[40];
    char telephone[15];
    int age , reference;
    Date laDate;
} reservation;

reservation Reservations[200];
reservation ReservationsCopy[200];
int count = 10;


void demoData();
void Afficher();
void ajouter();
void modifierSupprimer();
void triReservation();
void Recherche();
void Statistiques();
void CopyTableux();

int main()
{
    demoData();
    CopyTableux();

    int choix;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Ajouter une reservation.\n");
        printf("2. Modifier ou supprimer une reservation.\n");
        printf("3. Afficher les details d'une reservation.\n");
        printf("4. Tri des reservations.\n");
        printf("5. Recherche des reservation.\n");
        printf("6. Statistiques.\n");
        printf("7. Exite\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        system("@cls||clear");

        switch (choix)
        {
        case 1:
            system("@cls||clear");
            ajouter();
            break;
        case 2:
            system("@cls||clear");
            modifierSupprimer();
            break;
        case 3:
            system("@cls||clear");
            Afficher();
            break;
        case 4:
            system("@cls||clear");
            triReservation();
            break;
        case 5:
            system("@cls||clear");
            Recherche();
            break;
        case 6:
            Statistiques();
            break;
        }
    } while (choix != 7);
    
    return 0;
}

void demoData()
{
    char nome[][40] = {"Farsi", "Mansoori", "Sayed", "Hamadi", "Nasr", "Jabari", "Qadi", "Basri", "Amin", "Zahrani"};
    char prenome[][40] = {"Ayoub", "Zineb", "Soufiane", "Khadija", "Rachid", "Salma", "Yassine", "Nour", "Hassan", "Fatima"};
    int uniqueReferences[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
    char phoneNumbers[][15] = {"+212600000001", "+212600000002", "+212600000003", "+212600000004", "+212600000005", "+212600000006", "+212600000007", "+212600000008", "+212600000009", "+212600000010"};
    char statuses[][40] = {"Valide", "Reporte", "Annule", "Traite", "Valide", "Annule", "Traite", "Reporte", "Valide", "Traite"};
    int days[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int mois[] = {6, 1, 8, 3, 12, 4, 10, 2, 11, 5};
    int ages[] = {22, 34, 29, 45, 18, 31, 27, 40, 36, 25};

    for (int i = 0; i < 10; i++)
    {
        strcpy(Reservations[i].nom, nome[i]);
        strcpy(Reservations[i].prenom, prenome[i]);
        strcpy(Reservations[i].status, statuses[i]);
        strcpy(Reservations[i].telephone, phoneNumbers[i]);
        Reservations[i].age = ages[i];
        Reservations[i].reference = uniqueReferences[i];
        Reservations[i].laDate.jour = days[i];
        Reservations[i].laDate.mois = mois[i];
        Reservations[i].laDate.annee = 2024;
    }
}

void Afficher()
{
    for (int i = 0; i < count; i++)
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("Le nom : %s\n", Reservations[i].nom);
        printf("Le prenom : %s\n", Reservations[i].prenom);
        printf("Le statut : %s\n", Reservations[i].status);
        printf("La reference : %d\n", Reservations[i].reference);
        printf("Le telephone : %s\n", Reservations[i].telephone);
        printf("L'age : %d\n", Reservations[i].age);
        printf("Date : %d/%d/%d\n", Reservations[i].laDate.jour, Reservations[i].laDate.mois, Reservations[i].laDate.annee);
    }
}

void ajouter()
 {

    if (count >= 200)
    {
        printf("La liste des Reservation est pleine.\n");
        return;
    }
    srand(time(NULL));
    int randomNum = rand() % 10000;
    Reservations[count].reference = randomNum;

    int choix;

    printf("Reference unique : %d\n" , randomNum);
    printf("Entrez le nom : ");
    scanf("%s", Reservations[count].nom);

    printf("Entrez le prenom : ");
    scanf("%s", Reservations[count].prenom);

    printf("Entrez le numero de telephone : ");
    scanf("%s", Reservations[count].telephone);

    printf("Entrez l'age : ");
    scanf("%d", &Reservations[count].age);

    printf("Entrez la date.\n");
    printf("Entrez jour: ");
    scanf("%d", &Reservations[count].laDate.jour);
    printf("Entrez mois: ");
    scanf("%d", &Reservations[count].laDate.mois);
    printf("Entrez annee: ");
    scanf("%d", &Reservations[count].laDate.annee);


    printf("Entrez le statut : \n");
    printf("Entrez 1 pour Valide.\n");
    printf("Entrez 2 pour Reporte.\n");
    printf("Entrez 3 pour Annule.\n");
    printf("Entrez 4 pour Traite.\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 4)
    {
        printf("\nChoix invalide. Entrez un nombre entre 1 et 4 : ");
        scanf("%d", &choix);
    }

    switch (choix)
    {
    case 1:
        strcpy(Reservations[count].status , "Valide");
        break;
    case 2: 
        strcpy(Reservations[count].status , "Reporte");
        break;
    case 3:
        strcpy(Reservations[count].status , "Annule");
        break;
    case 4:
        strcpy(Reservations[count].status , "Traite");
        break;
    }



    count++;
    printf("Reservation ajoutee avec succes !\n");
}

void Modifer()
{
    int reference;
    printf("Entrez le reference unique : ");
    scanf("%d" , &reference);
    for (int i = 0; i < count; i++)
    {
        if (reference == Reservations[i].reference)
        {
            int choix;

            printf("Entrez le nom : ");
            scanf("%s", Reservations[i].nom);

            printf("Entrez le prenom : ");
            scanf("%s", Reservations[i].prenom);

            printf("Entrez le numero de telephone : ");
            scanf("%s", Reservations[i].telephone);

            printf("Entrez l'age : ");
            scanf("%d", &Reservations[i].age);

            printf("Entrez la date.\n");
            printf("Entrez jour: ");
            scanf("%d", &Reservations[i].laDate.jour);
            printf("Entrez mois: ");
            scanf("%d", &Reservations[i].laDate.mois);
            printf("Entrez annee: ");
            scanf("%d", &Reservations[i].laDate.annee);


            printf("Entrez le statut : \n");
            printf("Entrez 1 pour Valide.\n");
            printf("Entrez 2 pour Reporte.\n");
            printf("Entrez 3 pour Annule.\n");
            printf("Entrez 4 pour Traite.\n");
            printf("Entrez votre choix : ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 4)
    {
        printf("\nChoix invalide. Entrez un nombre entre 1 et 4 : ");
        scanf("%d", &choix);
    }

    switch (choix)
    {
    case 1:
        strcpy(Reservations[i].status , "Valide");
        break;
    case 2: 
        strcpy(Reservations[i].status , "Reporte");
        break;
    case 3:
        strcpy(Reservations[i].status , "Annule");
        break;
    case 4:
        strcpy(Reservations[i].status , "Traite");
        break;
    }


    srand(time(NULL));
    int randomNum = rand() % 10000;
    Reservations[i].reference = randomNum;
    printf("Reservation Edited avec succes !\n");
        }
    }
}

void Supprimmer()
{
    int reference;
    printf("Entrez le reference unique : ");
    scanf("%d" , &reference);
    for (int i = 0; i < count; i++)
    {
        if (reference == Reservations[i].reference)
        {
            for (int j = i; j < count - 1; j++)
            {
                Reservations[j] = Reservations[j + 1];
            }
            count--;
            break;
        }
        
    }
}

void modifierSupprimer()
{
    int choix;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Modifier une reservation.\n");
        printf("2. Supprimer une reservation.\n");
        printf("3. Exite.\n");
        printf("Entrez votre choix : ");
        scanf("%d" , &choix);

        system("@cls||clear");

        switch (choix)
        {
        case 1:
            Modifer();
            break;
        case 2:
            Supprimmer();
            break;
        }
    } while (choix != 3);  
}

void CopyTableux()
{
    for (int i = 0; i < count; i++)
    {
        ReservationsCopy[i] = Reservations[i];
    }
}

void triParNome()
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (strcasecmp(ReservationsCopy[j].nom , ReservationsCopy[j + 1].nom) > 0)
            {
                reservation temp;
                temp = ReservationsCopy[j];
                ReservationsCopy[j] = ReservationsCopy[j+1];
                ReservationsCopy[j+1] = temp;
            }
        }
        
    }

    
    for (int i = 0; i < count; i++) {
        printf("\n");
        printf("__\n");
        printf("\n");
        printf("Le nom : %s\n", ReservationsCopy[i].nom);
        printf("Le prenom : %s\n", ReservationsCopy[i].prenom);
        printf("Le statut : %s\n", ReservationsCopy[i].status);
        printf("La reference : %d\n", ReservationsCopy[i].reference);
        printf("Le telephone : %s\n", ReservationsCopy[i].telephone);
        printf("L'age : %d\n", ReservationsCopy[i].age);
        printf("Date : %d/%d/%d\n", ReservationsCopy[i].laDate.jour, ReservationsCopy[i].laDate.mois, ReservationsCopy[i].laDate.annee);
    }
}

void triParStatut() 
{


    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (strcasecmp(ReservationsCopy[j].status, ReservationsCopy[j + 1].status) > 0) {
                reservation temp = ReservationsCopy[j];
                ReservationsCopy[j] = ReservationsCopy[j + 1];
                ReservationsCopy[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("\n");
        printf("__\n");
        printf("\n");
        printf("Le nom : %s\n", ReservationsCopy[i].nom);
        printf("Le prenom : %s\n", ReservationsCopy[i].prenom);
        printf("Le statut : %s\n", ReservationsCopy[i].status);
        printf("La reference : %d\n", ReservationsCopy[i].reference);
        printf("Le telephone : %s\n", ReservationsCopy[i].telephone);
        printf("L'age : %d\n", ReservationsCopy[i].age);
        printf("Date : %d/%d/%d\n", ReservationsCopy[i].laDate.jour, ReservationsCopy[i].laDate.mois, ReservationsCopy[i].laDate.annee);
    }
}

void triParLeDate()
{

        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1; j++)
            {          
                 if (ReservationsCopy[j].laDate.jour > ReservationsCopy[j + 1].laDate.jour)
                 {
                        reservation temp = ReservationsCopy[j];
                        ReservationsCopy[j] = ReservationsCopy[j + 1];
                        ReservationsCopy[j + 1] = temp;
                 }
            }
            
        }

        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1; j++)
            {          
                 if (ReservationsCopy[j].laDate.mois > ReservationsCopy[j + 1].laDate.mois)
                 {
                        reservation temp = ReservationsCopy[j];
                        ReservationsCopy[j] = ReservationsCopy[j + 1];
                        ReservationsCopy[j + 1] = temp;
                 }
            }
            
        }


        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1; j++)
            {          
                 if (ReservationsCopy[j].laDate.annee > ReservationsCopy[j + 1].laDate.annee)
                 {
                        reservation temp = ReservationsCopy[j];
                        ReservationsCopy[j] = ReservationsCopy[j + 1];
                        ReservationsCopy[j + 1] = temp;
                 }
            }
            
        }

        

    for (int i = 0; i < count; i++) {
        printf("\n");
        printf("__\n");
        printf("\n");
        printf("Le nom : %s\n", ReservationsCopy[i].nom);
        printf("Le prenom : %s\n", ReservationsCopy[i].prenom);
        printf("Le statut : %s\n", ReservationsCopy[i].status);
        printf("La reference : %d\n", ReservationsCopy[i].reference);
        printf("Le telephone : %s\n", ReservationsCopy[i].telephone);
        printf("L'age : %d\n", ReservationsCopy[i].age);
        printf("Date : %d/%d/%d\n", ReservationsCopy[i].laDate.jour, ReservationsCopy[i].laDate.mois, ReservationsCopy[i].laDate.annee);
    }
        
}

void triReservation()
{
    CopyTableux();
    int choix;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Tri des reservations par Nom.\n");
        printf("2. Tri des reservations par date.\n");
        printf("3. Tri des reservations par statut.\n");
        printf("4. Exite\n");
        printf("Entrez votre choix : ");
        scanf("%d" , &choix);

  

        switch (choix)
        {
        case 1:
            triParNome();
            break;
        
        case 2:
            triParLeDate();
            break;
        case 3:
            triParStatut();
            break;
        }

    } while (choix != 4);
    
}

void RecherchParleNome()
{
    char nome[20];
    int found = 0;
    printf("Entrez le nome : ");
    scanf("%s" , nome);

    for (int i = 0; i < count; i++)
    {
        if (strcasecmp(nome , Reservations[i].nom) == 0)
        {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("Le nom : %s\n", Reservations[i].nom);
        printf("Le prenom : %s\n", Reservations[i].prenom);
        printf("Le statut : %s\n", Reservations[i].status);
        printf("La reference : %d\n", Reservations[i].reference);
        printf("Le telephone : %s\n", Reservations[i].telephone);
        printf("L'age : %d\n", Reservations[i].age);
        printf("Date : %d/%d/%d\n", Reservations[i].laDate.jour, Reservations[i].laDate.mois, Reservations[i].laDate.annee);
        found = 1;
        return;
        }   
    }
    if (!found)
    {
        printf("____________________\n");
        printf("                      \n");
        printf("Reservation introuvable.");
    }
    
}

void RechercheParReference()
{
    int Referencce;
    int found = 0;
    printf("\n");
    printf("_______________\n");
    printf("\n");
    printf("Entrez Reference unique : ");
    scanf("%d" , &Referencce);
    for (int i = 0; i < count; i++)
    {
        if (Referencce == Reservations[i].reference)
        {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("Le nom : %s\n", Reservations[i].nom);
        printf("Le prenom : %s\n", Reservations[i].prenom);
        printf("Le statut : %s\n", Reservations[i].status);
        printf("La reference : %d\n", Reservations[i].reference);
        printf("Le telephone : %s\n", Reservations[i].telephone);
        printf("L'age : %d\n", Reservations[i].age);
        printf("Date : %d/%d/%d\n", Reservations[i].laDate.jour, Reservations[i].laDate.mois, Reservations[i].laDate.annee); 
        found = 1;
        return;
        }
    }
    if (!found)
    {
        printf("____________________\n");
        printf("                      \n");
        printf("Reservation introuvable.");
    }
    
    
}

void RechercheParLeDate()
{  
        int jour, mois, anne;
        int found = 0;
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("Entrez le jour : ");
        scanf("%d" , &jour);
        printf("Entrez le mois : ");
        scanf("%d" , &mois);
        printf("Entrez le mois : ");
        scanf("%d" , &anne);

        for (int i = 0; i < count; i++)
        {
            if ((Reservations[i].laDate.jour == jour) && 
            (Reservations[i].laDate.mois == mois) && 
            (Reservations[i].laDate.annee == anne))
            {
                printf("\n");
                printf("_______________\n");
                printf("\n");
                printf("Le nom : %s\n", Reservations[i].nom);
                printf("Le prenom : %s\n", Reservations[i].prenom);
                printf("Le statut : %s\n", Reservations[i].status);
                printf("La reference : %d\n", Reservations[i].reference);
                printf("Le telephone : %s\n", Reservations[i].telephone);
                printf("L'age : %d\n", Reservations[i].age);
                printf("Date : %d/%d/%d\n", Reservations[i].laDate.jour, Reservations[i].laDate.mois, Reservations[i].laDate.annee);
                found = 1; 
            }
        }
    if (!found)
    {
        printf("____________________\n");
        printf("                      \n");
        printf("Reservation introuvable.");
    }
    
        
}

void Recherche()
{
    int choix;
    do
    {
        
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Recherche d'une reservation par reference unique.\n");
        printf("2. Recherche d'une reservation par nom.\n");
        printf("3. Recherche d'une reservation par date.\n");
        printf("4. Exite.\n");
        printf("Entrez votre choix : ");
        scanf("%d" , &choix);


        switch (choix)
        {
        case 1:
            RechercheParReference();
            break;
        case 2:
            RecherchParleNome();
            break;
        case 3:
            RechercheParLeDate();
            break;

        }
    } while (choix != 4);
}

float MoyenneAge()
{
    int age = 0;
    for (int i = 0; i < count; i++)
    {
        age += Reservations[i].age;
    }
    
    return age / count;
}

void NombreParage()
{
    int nombre0_18 = 0;
    int nombre19_35 = 0;
    int nombre36 = 0;

    for (int i = 0; i < count; i++)
    {
        if (Reservations[i].age >= 0 && Reservations[i].age <= 18)
        {
            nombre0_18++;
        }
        else if(Reservations[i].age >= 19 && Reservations[i].age <= 35)
        {
            nombre19_35++;
        }
        else if(Reservations[i].age >= 36)
        {
            nombre36++;
        }
    }
    printf("\n");
    printf("_______________\n");
    printf("\n");
    printf("Age (0-18 ans) : %d\n" , nombre0_18);
    printf("Age (19-35 ans) : %d\n" , nombre19_35);
    printf("Age (36+ ans) : %d\n" , nombre36);
}

void NombreTotale()
{
    int valide = 0;
    int Reporte = 0;
    int Annule = 0;
    int Traite = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcasecmp(Reservations[i].status , "Valide") == 0)
        {
            valide++;
        }
        else if (strcasecmp(Reservations[i].status , "Reporte") == 0)
        {
            Reporte++;
        }
        else if (strcasecmp(Reservations[i].status , "Annule") == 0)
        {
            Annule++;
        }
        else if (strcasecmp(Reservations[i].status , "Traite") == 0)
        {
            Traite++;
        }
    }
    printf("\n");
    printf("_______________\n");
    printf("\n");
    printf("Nombre de valide status : %d\n" , valide);
    printf("Nombre de Reporte status : %d\n" , Reporte);
    printf("Nombre de Annule status : %d\n" , Annule);
    printf("Nombre de Traite status : %d\n" , Traite);
}

void Statistiques()
{
        int choix;
    do
    {
        
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Calculer la moyenne d'age des patients ayant reserve.\n");
        printf("2. Afficher le nombre de patients par tranche d'age.\n");
        printf("3. Generer des statistiques pour connaitre le nombre total de reservations par statut\n");
        printf("4. Exite.\n");
        printf("Entrez votre choix : ");
        scanf("%d" , &choix);

        system("@cls||clear");

        switch (choix)
        {
        case 1:
            printf("La moyenne d'age : %.2f" , MoyenneAge());
            break;
        case 2:
            NombreParage();
            break;
        case 3:
            NombreTotale();
            break;
        }
    } while (choix != 4);
}
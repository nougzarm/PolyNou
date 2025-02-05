#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/* Commentaires:
*/

int accueil(int hauteur, int largeur){
    attron(A_BOLD);  
    mvprintw(0, (largeur-strlen("PolyNou"))/2, "PolyNou");  
    attroff(A_BOLD);
    char titre[] = "Bienvenu(e) dans PolyNou !";
    mvprintw(hauteur/2, (largeur-strlen(titre))/2, titre);
    char ch = getch();
    while(ch != '\n'){
        ch = getch();
    }
    clear();  // Rafraîchit l'écran
    return 0;
}

int main() {
    initscr(); 
    curs_set(0);
    int hauteur, largeur;
    getmaxyx(stdscr, hauteur, largeur);

    /*  Entrer sur la page d'accueil */         
    accueil(hauteur, largeur);

    refresh();
    mvprintw(hauteur/2, 2, "Bravo ! vous avez réussi à entrer"); // Affiche le texte en (5,10)
    getch();    // Attend une touche
    endwin();   // Quitte ncurses
    return 0;
}
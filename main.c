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
    mvprintw(hauteur/2, (largeur-strlen("Bienvenu(e) dans PolyNou !"))/2, "Bienvenu(e) dans PolyNou !");
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
    mvprintw(hauteur/2, 2, "Bravo ! vous avez réussi à entrer");
    getch();

    // Nettoyage
    clear();
    delwin(stdscr);
    endwin();  // Quitte proprement ncurses
    refresh();
    return 0;
}
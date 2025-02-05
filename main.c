#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/* Commentaires:
*/

int accueil(int hauteur, int largeur){
    WINDOW* cadre_titre = subwin(stdscr, 3, 20, 0, (largeur-20)/2);
    box(cadre_titre, 0, 0);
    attron(A_BOLD);  
    mvwprintw(cadre_titre, 1, (20-strlen("PolyNou"))/2, "PolyNou");  
    attroff(A_BOLD);
    mvprintw(hauteur/2, (largeur-strlen("Bienvenu(e) dans PolyNou !"))/2, "Bienvenu(e) dans PolyNou !");
    char ch = getch();
    while(ch != '\n'){
        ch = getch();
    }
    delwin(cadre_titre);
    clear();  // Rafraîchit l'écran
    return 0;
}

int afficher_page(int hauteur, int largeur){
    WINDOW* menu = subwin(stdscr, hauteur / 2, largeur, 0, 0);
    box(menu, 0, 0);
    mvwprintw(menu, 2, 2, "salut");
    char ch = getch();
    while(ch != '\n'){
        ch = getch();
    }
    delwin(menu);
    clear();
    refresh();
    return 0;
}

int main() {
    initscr(); 
    curs_set(0);
    int hauteur, largeur;
    getmaxyx(stdscr, hauteur, largeur);

    /*  Entrer sur la page d'accueil */
    accueil(hauteur, largeur);

    afficher_page(hauteur, largeur);

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
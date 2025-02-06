#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/*  Fonction écran d'accueil au démarrage du programme  */
int accueil(int hauteur, int largeur){
    /*  Fenêtre du titre - nom du programme  */
    WINDOW* fenetre_titre = subwin(stdscr, 3, 20, 0, (largeur-20)/2);
    box(fenetre_titre, 0, 0);
    /* wbkgd(fenetre_titre, COLOR_PAIR(2)); */
    wattron(fenetre_titre, A_BOLD);  
    mvwprintw(fenetre_titre, 1, (20-strlen("PolyNou"))/2, "PolyNou");  
    wattroff(fenetre_titre, A_BOLD);

    WINDOW* fenetre_description = subwin(stdscr, 10, 40, 3, (largeur-40)/2);
    box(fenetre_description, 0, 0);
    mvwprintw(fenetre_description, 1, (40-strlen("Bienvenu(e) dans PolyNou !"))/2, "Bienvenu(e) dans PolyNou !");
    wrefresh(fenetre_description);

    /*  Attente de l'utilisateur  */
    char ch = getch();
    while(ch != '\n'){
        ch = getch();
    }

    /*  Suppression des WINDOW's et autres */
    delwin(fenetre_titre);
    delwin(fenetre_description);
    clear();
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
    start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    wbkgd(stdscr, COLOR_PAIR(2));
    int hauteur, largeur;
    getmaxyx(stdscr, hauteur, largeur);

    /*  Entrer sur la page d'accueil */
    accueil(hauteur, largeur);

    afficher_page(hauteur, largeur);

    refresh();
    mvprintw(hauteur/2, 2, "Bravo ! vous avez réussi à entrer");
    getch();

    // Nettoyage
    curs_set(1);
    refresh();
    endwin();  // Quitte proprement ncurses
    return 0;
}
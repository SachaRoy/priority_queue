#include "priority_queue.hpp"


// ########## Méthodes de la classe "maillon_max" ##########

struct maillon_max {
    int v;
    maillon_max* next;

    void init();
    void add(maillon_max* suiv, int e);
};

void maillon_max::init() {
    this->next = nullptr;
}

void maillon_max::add(maillon_max* suiv, int e) {
    maillon_max* new_m = new maillon_max;
    new_m->init();
    new_m->v = e;
    new_m->next = suiv;
    this->next = new_m;
}


// ########## Méthodes de la classe "Q_max" ##########

void Q_max::init() {   // Initialise une instance de "Q_max"
    this->l = 0;
    this->val = nullptr;
}

void Q_max::erase() {   // Supprime une instance de "Q_max"
    while(this->pop());
    delete this->val;
    delete this;
}

int Q_max::head() {   // Renvoie la valeur située en tête de la file
    if(not this->is_empty()) {
        return this->val->v;
    }
    else {
        return -1;
    }
}

int Q_max::length() {   // Renvoie la taille de la file
    return this->l;
}

bool Q_max::is_empty() {   // Renvoie true si la file est vide
    return this->l == 0;
}

void Q_max::push(int e) {   // Ajoute l'élément e dans la file selon la propriété priviliégée par la file
    if(this->is_empty()) {
        maillon_max* new_m = new maillon_max;
        new_m->init();
        new_m->v = e;
        this->val = new_m;
    }

    else if(this->val->v <= e) {
        maillon_max* new_m = new maillon_max;
        new_m->init();
        new_m->v = e;

        new_m->next = this->val;
        this->val = new_m;
    }

    else {
        maillon_max* temp = this->val->next;
        maillon_max* prec = this->val;

        while(temp != nullptr) {
            if(prec->v <= e) break;
            prec = temp;
            temp = temp->next;
        }
        prec->add(temp, e);
    }
    this->l++;
}

bool Q_max::pop() {   // Retire la tête de file
    if(this->is_empty()) {
        return false;
    }
    else {
        maillon_max* temp = this->val;
        this->val = this->val->next;
        this->l--;

        delete temp;
        return true;
    }
}

void Q_max::print() {   // Procédure d'affichage de la file
    if(not this->is_empty()) {
        maillon_max* temp = this->val;

        std::cout << "<-";
        while(temp != nullptr) {
            std::cout << " " << temp->v << "]";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
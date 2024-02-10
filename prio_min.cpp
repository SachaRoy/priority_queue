#include "priority_queue.hpp"


// ########## Méthodes de la classe "maillon_min" ##########

struct maillon_min {
    int v;
    maillon_min* next;

    void init();
    void add(maillon_min* suiv, int e);
};

void maillon_min::init() {
    this->next = nullptr;
}

void maillon_min::add(maillon_min* suiv, int e) {
    maillon_min* new_m = new maillon_min;
    new_m->init();
    new_m->v = e;
    new_m->next = suiv;
    this->next = new_m;
}


// ########## Méthodes de la classe "Q_min" ##########

void Q_min::init() {   // Initialise une instance de "Q_min"
    this->l = 0;
    this->val = nullptr;
}

void Q_min::erase() {   // Supprime une instance de "Q_min"
    while(this->pop());
    delete this->val;
    delete this;
}

int Q_min::head() {   // Renvoie la valeur située en tête de file
    if(not this->is_empty()) {
        return this->val->v;
    }
    else {
        return -1;
    }
}

int Q_min::length() {   // Renvoie la taille de la file
    return this->l;
}

bool Q_min::is_empty() {   // Renvoie true si la file est vide
    return this->l == 0;
}

void Q_min::push(int e) {   // Ajoute l'élément e dans la file selon la propriété priviliégée par la file
    if(this->is_empty()) {
        maillon_min* new_m = new maillon_min;
        new_m->init();
        new_m->v = e;
        this->val = new_m;
    }

    else if(this->val->v >= e) {
        maillon_min* new_m = new maillon_min;
        new_m->init();
        new_m->v = e;

        new_m->next = this->val;
        this->val = new_m;
    }

    else {
        maillon_min* temp = this->val->next;
        maillon_min* prec = this->val;

        while(temp != nullptr) {
            if(prec->v >= e) break;
            prec = temp;
            temp = temp->next;
        }
        prec->add(temp, e);
    }
    this->l++;
}

bool Q_min::pop() {   // Retire la tête de file
    if(this->is_empty()) {
        return false;
    }
    else {
        maillon_min* temp = this->val;
        this->val = this->val->next;
        this->l--;

        delete temp;
        return true;
    }
}

void Q_min::print() {   // Procédure d'affichage de la file
    if(not this->is_empty()) {
        maillon_min* temp = this->val;

        std::cout << "<-";
        while(temp != nullptr) {
            std::cout << " " << temp->v << "]";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
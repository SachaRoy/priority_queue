#include "priority_queue.hpp"


// ########## Autres fonctions ##########

bool Q_min::is_equal(Q_min* q2) {
    bool rep = true;
    if(this->length() != q2->length()) {
        rep = false;
    }
    else if(not this->is_empty()) {
        maillon_min* t1{this->val};
        maillon_min* t2{q2->val};

        while(t1 != nullptr) {
            if(t1->v != t2->v) {
                rep = false;
                break;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    return rep;
}

bool Q_max::is_equal(Q_max* q2) {
    bool rep = true;
    if(this->length() != q2->length()) {
        rep = false;
    }
    else if(not this->is_empty()) {
        maillon_max* t1{this->val};
        maillon_max* t2{q2->val};

        while(t1 != nullptr) {
            if(t1->v != t2->v) {
                rep = false;
                break;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    return rep;
}


Q_min* Q_min::copy() {
    Q_min* rep = new Q_min;
    rep->init();
    if(not this->is_empty()) {
        maillon_min* temp = this->val;
        while(temp != nullptr) {
            rep->push(temp->v);
            temp = temp->next;
        }
    }
    return rep;
}

Q_max* Q_max::copy() {
    Q_max* rep = new Q_max;
    rep->init();
    if(not this->is_empty()) {
        maillon_max* temp = this->val;
        while(temp != nullptr) {
            rep->push(temp->v);
            temp = temp->next;
        }
    }
    return rep;
}
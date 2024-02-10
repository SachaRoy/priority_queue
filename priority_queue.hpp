#include <iostream>


struct maillon_min {
    int v;
    maillon_min* next;

    void init();
    void add(maillon_min* suiv, int e);
};

struct maillon_max {
    int v;
    maillon_max* next;

    void init();
    void add(maillon_max* suiv, int e);
};


class Q_min {
    private:
    maillon_min* val;
    int l;

    public:
    void init();
    void erase();
    int head();
    int length();
    bool is_empty();
    void push(int e);
    bool pop();
    void print();

    bool is_equal(Q_min* q2);
    Q_min* copy();
};


class Q_max {
    private:
    maillon_max* val;
    int l;

    public:
    void init();
    void erase();
    int head();
    int length();
    bool is_empty();
    void push(int e);
    bool pop();
    void print();

    bool is_equal(Q_max* q2);
    Q_max* copy();
};

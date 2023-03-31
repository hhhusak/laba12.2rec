#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef int Info;
struct Elem
{
    Elem *link;
    Info info;
};
void enqueue(Elem* L, Info value);
Info dequeue(Elem* L);
void Print(Elem* L);
Info Count(Elem* L);

void enqueue(Elem* L, Info value) {
    Elem *tmp = new Elem;
    tmp->info = value;
    tmp->link = L->link;
    L->link = tmp;
}

Info dequeue(Elem* L) {
    Elem *tmp = new Elem;
    Info value = L->info;
    delete L;
    L = tmp;
    return value;
}

void Print(Elem* L){
    if(L != NULL) {
        cout << L->info << "; ";
        return Print(L->link);
    }
}

Info Count(Elem* L) {
    if(L != NULL) {
        if(L->info < 0){
            return 1 + Count(L->link);
        } else {
            return Count(L->link);
        }
    } else {
        return 0;
    }
}

int main() {
    srand((unsigned) time(nullptr));

    Elem* L = new Elem;
    for (int i = -5; i < 10; i++) {
        int random = (rand() % 13) - 6;
        enqueue(L, random);
    }

    cout << "Spisok: ";
    Print(L);
    cout << endl;
    cout << "Count of numbs info < 0: " << Count(L);
    dequeue(L);

    return 0;
}

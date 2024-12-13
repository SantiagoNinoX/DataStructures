#include <iostream>
#include "dlinkedlist.h"
#include "monster.h"

class HashTable {
    public:
        HashTable() {
            table = nullptr;
            size = 0;
        }
        ~HashTable() { borraTabla(); };
        bool creatTable(unsigned int nSize);
        void borraTabla();
        bool insertar(Monster dato);
        bool borrar(Monster dato);
        Monster *buscar(std::string name);
    private:
        unsigned int hashMonsterToIndex(Monster dato);
        ListaDL<Monster> *table;
        unsigned int size;
};
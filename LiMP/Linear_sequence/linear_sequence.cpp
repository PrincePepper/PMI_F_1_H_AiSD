#include "linear_sequence.h"

typedef struct item *pL_Itm;
typedef struct list *pL_List;
typedef struct iterator *pListIterator;

///структура элементов
typedef struct item {
    LSQ_BaseTypeT val;
    pL_Itm prev;
    pL_Itm next;
} List_Itm;

///первая и последняя граница
typedef struct list {
    pL_Itm first;
    pL_Itm last;
    int cnt;
} L_List;

///
typedef struct iterator {
    pL_List list;
    pL_Itm item;
} ListIterator;

static pL_Itm create_item(pL_Itm prev, pL_Itm next, LSQ_BaseTypeT value) {
    pL_Itm new_item = new(List_Itm);
    new_item->val = value;
    new_item->prev = prev;
    new_item->next = next;
    return new_item;
}

///Функция, создающая пустой контейнер. Возвращает назначенный ему дескриптор
LSQ_HandleT LSQ_CreateSequence(void) {
    pL_List new_list = new(L_List);
    new_list->first = create_item(nullptr, nullptr, 0);
    new_list->last = create_item(new_list->first, nullptr, 0);
    new_list->first->next = new_list->last;
    new_list->cnt = 0;
    return (LSQ_HandleT) new_list;
}

///Функция, возвращающая текущее количество элементов в контейнере
LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
    if (handle != LSQ_HandleInvalid) {
        return ((pL_List) handle)->cnt;
    } else {
        return 0;
    }
}

///Функция, возвращающая текущее количество элементов в контейнере
int LSQ_IsIteratorDereferencable(LSQ_IteratorT iterator) {
    return !(LSQ_IsIteratorPastRear(iterator) || LSQ_IsIteratorBeforeFirst(iterator));
}

///Функция, определяющая, может ли данный итератор быть разыменован
int LSQ_IsIteratorBeforeFirst(LSQ_IteratorT iterator) {
    return ((pListIterator) iterator)->item->prev == nullptr;
}

///Функция, определяющая, указывает ли данный итератор на элемент, следующий за последним в контейнере
int LSQ_IsIteratorPastRear(LSQ_IteratorT iterator) {
    return ((pListIterator) iterator)->item->next == nullptr;
}

///Функция, разыменовывающая итератор.
LSQ_BaseTypeT *LSQ_DereferenceIterator(LSQ_IteratorT iterator) {
    if (LSQ_IsIteratorDereferencable(iterator)) {
        return &(((pListIterator) iterator)->item->val);
    }
    return NULL;
}
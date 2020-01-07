#include "linear_sequence.h"

#define new(type) (type*)(malloc( sizeof(type)))

typedef struct itm *pL_Itm;
typedef struct list *pL_List;
typedef struct iterator *pListIterator;

//
typedef struct itm {
    LSQ_BaseTypeT val;
    pL_Itm prev;
    pL_Itm next;
} List_Itm;

//
typedef struct list {
    pL_Itm first;
    pL_Itm last; /*....... first и last - границы .......*/
    int cnt; //!
} L_List;

//
typedef struct iterator {
    pL_List list;
    pL_Itm itm;
} ListIterator;

//
static pL_Itm create_item(pL_Itm prev, pL_Itm next, LSQ_BaseTypeT value) {
    pL_Itm new_item = new(List_Itm);
    new_item->val = value;
    new_item->prev = prev;
    new_item->next = next;
    return new_item;
}

//
static pL_Itm get_item(pL_List list, unsigned int index) {
    if (index > list->cnt)return NULL;

    pL_Itm item;
    for (item = list->first->next; index > 0; item = item->next)
        index--;
    return item;
}

//
static LSQ_IteratorT create_iterator(pL_Itm item, pL_List list) {
    pListIterator new_iterator = new(ListIterator);
    new_iterator->itm = item;
    new_iterator->list = list;
    return (LSQ_IteratorT) new_iterator;
}

//
static pL_Itm add_item(pL_List list, pL_Itm cur, LSQ_BaseTypeT value) {
    pL_Itm new_itm = create_item(cur->prev, cur, value);
    cur->prev->next = new_itm;
    cur->prev = new_itm;
    list->cnt++;
    return new_itm;
}

//
static pL_Itm delete_item(pL_List list, pL_Itm itm) {
    if (list->cnt == 0) return itm;

    pL_Itm next = itm->next;
    itm->prev->next = next;
    itm->next->prev = itm->prev;

    free(itm);
    list->cnt--;
    return next;
}

//Функция, возвращающая текущее количество элементов в контейнере
LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
    if (handle != LSQ_HandleInvalid) {
        return ((pL_List) handle)->cnt;
    } else {
        return 0;
    }
}

//Функция, уничтожающая контейнер с заданным дескриптором. Освобождает принадлежащую ему память
void LSQ_DestroySequence(LSQ_HandleT handle) {
    if (handle != LSQ_HandleInvalid) {
        pL_List list = (pL_List) handle;


        pL_Itm curr = list->first, next;
        while (curr != NULL) {
            next = curr->next;
            free(curr);
            curr = next;
        }

        free(list);
    }
}

//Функция, создающая пустой контейнер. Возвращает назначенный ему дескриптор
LSQ_HandleT LSQ_CreateSequence(void) {
    pL_List new_list = new(L_List);
    new_list->first = create_item(NULL, NULL, 0);
    new_list->last = create_item(new_list->first, NULL, 0);
    new_list->first->next = new_list->last;
    new_list->cnt = 0;
    return (LSQ_HandleT) new_list;
}

//Функция, возвращающая текущее количество элементов в контейнере
int LSQ_IsIteratorDereferencable(LSQ_IteratorT iterator) {
    return !(LSQ_IsIteratorPastRear(iterator) || LSQ_IsIteratorBeforeFirst(iterator));
}

//Функция, определяющая, может ли данный итератор быть разыменован
int LSQ_IsIteratorBeforeFirst(LSQ_IteratorT iterator) {
    return ((pListIterator) iterator)->itm->prev == NULL;
}

//Функция, определяющая, указывает ли данный итератор на элемент, следующий за последним в контейнере
int LSQ_IsIteratorPastRear(LSQ_IteratorT iterator) {
    return ((pListIterator) iterator)->itm->next == NULL;
}

//Функция, разыменовывающая итератор.
LSQ_BaseTypeT *LSQ_DereferenceIterator(LSQ_IteratorT iterator) {
    if (LSQ_IsIteratorDereferencable(iterator)) {
        return &(((pListIterator) iterator)->itm->val);
    }
    return NULL;
}

// Функция, возвращающая итератор, ссылающийся на элемент с указанным индексом
LSQ_IteratorT LSQ_GetElementByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index) {
    if (handle == LSQ_HandleInvalid) return NULL;

    pL_Itm item = get_item((pL_List) handle, index);
    if (item == NULL) return NULL;

    return create_iterator(item, (pL_List) handle);
}

// Функция, возвращающая итератор, ссылающийся на элемент контейнера следующий за последним
LSQ_IteratorT LSQ_GetPastRearElement(LSQ_HandleT handle) {
    if (handle == LSQ_HandleInvalid) return NULL;
    return create_iterator(((pL_List) handle)->last, (pL_List) handle);
}

// Функция, возвращающая итератор, ссылающийся на первый элемент контейнера
LSQ_IteratorT LSQ_GetFrontElement(LSQ_HandleT handle) {
    return LSQ_GetElementByIndex(handle, 0);
}

//Функция, уничтожающая итератор с заданным дескриптором и освобождающая принадлежащую ему память
void LSQ_DestroyIterator(LSQ_IteratorT iterator) {
    if (iterator != NULL) free(iterator);
}

//Функция, перемещающая итератор на один элемент вперед
void LSQ_AdvanceOneElement(LSQ_IteratorT iterator) {
    LSQ_ShiftPosition(iterator, 1);
}

// Функция, перемещающая итератор на один элемент назад
void LSQ_ShiftPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT shift) {
    pListIterator itercast = (pListIterator) iterator;
    while (shift != 0) {
        if (shift > 0) {
            if (LSQ_IsIteratorPastRear(iterator)) break;
            itercast->itm = itercast->itm->next;
            shift--;
        } else {
            if (LSQ_IsIteratorBeforeFirst(iterator)) break;
            itercast->itm = itercast->itm->prev;
            shift++;
        }
    }
}

// Функция, перемещающая итератор на заданное смещение со знаком
void LSQ_RewindOneElement(LSQ_IteratorT iterator) {
    LSQ_ShiftPosition(iterator, -1);
}

// Функция, устанавливающая итератор на элемент с указанным номером
void LSQ_SetPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT pos) {

    pListIterator itercast = (pListIterator) iterator;
    pL_Itm item = get_item(itercast->list, pos);
    if (item != NULL) itercast->itm = item;
}

// Функция, добавляющая элемент в начало контейнера
void LSQ_InsertFrontElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
    if (handle != LSQ_HandleInvalid) {
        add_item((pL_List) handle, ((pL_List) handle)->first->next, element);
    }
}

void LSQ_InsertRearElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
    if (handle != LSQ_HandleInvalid) {
        add_item((pL_List) handle, ((pL_List) handle)->last, element);
    }
}

// Функция, добавляющая элемент в контейнер на позицию, указываемую в данный момент итератором.
void LSQ_InsertElementBeforeGiven(LSQ_IteratorT iterator, LSQ_BaseTypeT newElement) {
    if (iterator == NULL) return;
    if (!LSQ_IsIteratorBeforeFirst(iterator)) {
        pListIterator itercast = (pListIterator) iterator;
        itercast->itm = add_item(itercast->list, itercast->itm, newElement);
    }
}

// Функция, удаляющая первый элемент контейнера
void LSQ_DeleteFrontElement(LSQ_HandleT handle) {
    if (handle != LSQ_HandleInvalid) {
        delete_item((pL_List) handle, ((pL_List) handle)->first->next);
    }
}

// Функция, удаляющая последний элемент контейнера
void LSQ_DeleteRearElement(LSQ_HandleT handle) {
    if (handle != LSQ_HandleInvalid) {
        delete_item((pL_List) handle, ((pL_List) handle)->last->prev);
    }
}

// Функция, удаляющая элемент контейнера, указываемый заданным итератором.
void LSQ_DeleteGivenElement(LSQ_IteratorT iterator) {
    if (LSQ_IsIteratorDereferencable(iterator)) {
        pListIterator itercast = (pListIterator) iterator;
        itercast->itm = delete_item(itercast->list, itercast->itm);
    }
}

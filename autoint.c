#include "autoint.h"

#include <stdlib.h>

// =========================
// AutoInt::Memory Functions 
// =========================

struct AutoInt* autoint_create(void) {
    struct AutoInt* num;

    if(num = malloc(sizeof num)) {
        if(num->data = malloc(sizeof num->data)) {
            autoint_safecreate(num);
        } else { // AutoInt->data couldn't be declared
            free(num);
            return NULL;
        }
    }

    return num;
}

void autoint_safecreate(struct AutoInt* x) {
    x->carry = 0;
    x->positive = 1;
    x->data[0].d = 0;
    x->len = 1;
}

void autoint_free(struct AutoInt* x) {
    free(x->data);
    free(x);
}
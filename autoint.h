//
// autoint for C
//

#ifndef __AUTOINT_H
#define __AUTOINT_H

struct autoint__digit {
    unsigned int d : 4;
}; 

struct AutoInt {
    int carry : 1;        // carry flag
    int positive : 1;     // is_positive
    struct __digit* data;
    int len;
};

/* Memory Functions */
struct AutoInt* createNumber(void);                      // allocate a new empty AutoInt. Will return NULL if malloc() fails.
void safeCreate(struct AutoInt* preallocated);           // given a preallocated AutoInt, this will fill the struct with default values.
int deleteNumber(struct AutoInt* x);                     // frees an AutoInt
/* Arithmetic Functions  */
struct AutoInt  add(struct AutoInt x, struct AutoInt y); // adds two AutoInts       (x + y)
struct AutoInt  sub(struct AutoInt x, struct AutoInt y); // Subtracts two AutoInts  (x - y)
struct AutoInt  mul(struct AutoInt x, struct AutoInt y); // multiplies two AutoInts (x * y)
struct AutoInt  div(struct AutoInt x, struct AutoInt y); // divides two AutoInts    (x / y)
struct AutoInt  mod(struct AutoInt x, struct AutoInt y); // returns the remainder   (x % y)
/* IO Functions */
void printNumber(struct AutoInt* x);                     // prints an AutoInt, safely
char* to_string(struct AutoInt* x);                      // returns the string representing the given AutoInt. Note, it is the caller's responsibility to free() that string later.
/* Misc. Functions */
struct AutoInt ToAutoInt(long long int n);               // returns an AutoInt from the given number n
struct AutoInt fast_ToAutoInt(signed char n);            // statically creates an AutoInt from a given number in [-128, 127].

#endif // __AUTOINT_H
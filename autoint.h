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
    struct autoint__digit* data;
    int len;
};

/* Memory Functions */

/** allocate a new empty AutoInt. Will return NULL if malloc() fails. */
struct AutoInt* autoint_create(void);

/** given a preallocated AutoInt, this will fill the struct with default values. */
void autoint_safecreate(struct AutoInt* preallocated);

/** frees an AutoInt */
int deleteNumber(struct AutoInt* x);

/* Arithmetic Functions  */

struct AutoInt  autoint_add(struct AutoInt x, struct AutoInt y); 
struct AutoInt  autoint_sub(struct AutoInt x, struct AutoInt y); 
struct AutoInt  autoint_mul(struct AutoInt x, struct AutoInt y); 
struct AutoInt  autoint_div(struct AutoInt x, struct AutoInt y); 
struct AutoInt  autoint_mod(struct AutoInt x, struct AutoInt y); 

/* IO Functions */

/** prints an AutoInt, safely (does not use malloc) */
void autoint_print(struct AutoInt* x);

/** returns the string representing the given AutoInt. Note, it is the caller's responsibility to free() that string later. (this function uses malloc!)*/
char* autoint_to_string(struct AutoInt* x);
/* Misc. Functions */

/** returns an AutoInt from the given number n */
struct AutoInt ToAutoInt(long long int n);

/** statically creates an AutoInt from a given number in [-128, 127]. */
struct AutoInt fast_ToAutoInt(signed char n);

#endif // __AUTOINT_H
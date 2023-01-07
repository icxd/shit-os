#include "include/locale.h"

typedef struct {
    locale_t* loc;
    char* name;
    char* decimal_point;
    char* thousands_sep;
    char* grouping;
    char* int_curr_symbol;
    char* currency_symbol;
    char* mon_decimal_point;
    char* mon_thousands_sep;
    char* mon_grouping;
    char* positive_sign;
    char* negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    char int_p_cs_precedes;
    char int_n_cs_precedes;
    char int_p_sep_by_space;
    char int_n_sep_by_space;
    char int_p_sign_posn;
    char int_n_sign_posn;
} lconv;

char* setlocale(int category, const char* locale) {
    return "C";
}

struct lconv* localeconv(void) {
    lconv* loc = malloc(sizeof(lconv));
    loc->decimal_point = ".";
    loc->thousands_sep = ",";
    loc->grouping = "\3";
    loc->int_curr_symbol = "USD";
    loc->currency_symbol = "$";
    loc->mon_decimal_point = ".";
    loc->mon_thousands_sep = ",";
    loc->mon_grouping = "\3";
    loc->positive_sign = "";
    loc->negative_sign = "-";
    loc->int_frac_digits = 2;
    loc->frac_digits = 2;
    loc->p_cs_precedes = 1;
    loc->p_sep_by_space = 0;
    loc->n_cs_precedes = 1;
    loc->n_sep_by_space = 0;
    loc->p_sign_posn = 3;
    loc->n_sign_posn = 3;
    loc->int_p_cs_precedes = 1;
    loc->int_n_cs_precedes = 1;
    loc->int_p_sep_by_space = 0;
    loc->int_n_sep_by_space = 0;
    loc->int_p_sign_posn = 3;
    loc->int_n_sign_posn = 3;
    return loc;
}

locale_t newlocale(int category_mask, const char* locale, locale_t base) {
    
}

locale_t duplocale(locale_t dataset) {

}

void freelocale(locale_t dataset) {

}

locale_t uselocale(locale_t dataset) {

}
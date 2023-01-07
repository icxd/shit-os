#ifndef KERNEL_LOCALE_H
#define KERNEL_LOCALE_H

#ifdef __cplusplus
extern "C" {
#endif

#define LC_ALL 0
#define LC_COLLATE 1
#define LC_CTYPE 2
#define LC_MONETARY 3
#define LC_NUMERIC 4
#define LC_TIME 5
#define LC_MESSAGES 6

#define LC_GLOBAL_LOCALE ((locale_t) -1)

typedef struct __locale_struct *locale_t;

char *setlocale(int category, const char *locale);
struct lconv *localeconv(void);

locale_t newlocale(int category_mask, const char *locale, locale_t base);
locale_t duplocale(locale_t locale);
void freelocale(locale_t locale);
locale_t uselocale(locale_t locale);

#ifdef __cplusplus
}
#endif

#endif /* KERNEL_LOCALE_H */
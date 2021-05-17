#pragma warning(disable:4996)

/* setlocale example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */
#include <locale.h>     /* struct lconv, setlocale, localeconv */
#include <conio.h>      /* _getch() */

/*  Source by CPlusPlus
    Modified for Learn by Rizky Khapidsyah 
    I.D.E : Microsoft Visual Studio 2019 Community Edition
    */

int main() {
    time_t waktuMentah;
    struct tm* infoWaktu;
    char buffer[80];

    struct lconv* lc;

    time(&waktuMentah);
    infoWaktu = localtime(&waktuMentah);

    int duaKali = 0;

    do {
        printf("Locale is: %s\n", setlocale(LC_ALL, NULL));

        strftime(buffer, 80, "%c", infoWaktu);
        printf("Date is: %s\n", buffer);

        lc = localeconv();
        printf("Currency symbol is: %s\n-\n", lc->currency_symbol);

        setlocale(LC_ALL, "");
    } while (!duaKali++);

    _getch();
    return 0;
}
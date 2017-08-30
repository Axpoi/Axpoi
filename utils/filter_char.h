//
// Created by axoford12 on 8/29/17.
//

#ifndef AXPOI_FILTER_CHAR_H
#define AXPOI_FILTER_CHAR_H
void filter_char(char *filter_char, char filter) {
    int rel_index = 0;
    for (int i = 0; filter_char[i] != '\0'; ++i) {

        if (filter_char[i] != filter) {
            filter_char[rel_index] = filter_char[i];
            rel_index++;
        }

    }
    filter_char[rel_index] = '\0';
}
#endif //AXPOI_FILTER_CHAR_H

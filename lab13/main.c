#include <string.h>	// Lab 13
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define n 800000
typedef unsigned set_data_elem;

enum {
 bits_per_char = 8,
 bits_per_elem = sizeof(set_data_elem) * bits_per_char,
 datalen = (1 << bits_per_char) / bits_per_elem
};

typedef struct {
 set_data_elem data[datalen];
} set;

void set_clear(set *s) {
 memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int c) {
 s->data[c / bits_per_elem] |= 1u << (c % bits_per_elem);
}

void set_generate(set *s, bool indicator(int)) {
 int i;
 set_clear(s);
 for(i = 0; i != 1 << bits_per_char; i++) {
 if(indicator(i)) {
 set_insert(s, i);
 }
 }
}

void set_erase(set *s, int c) {
 s->data[c / bits_per_elem] &= ~(1u << c % bits_per_elem);
}

bool set_in(const set *s, int c) {
 return (s->data[c/ bits_per_elem] & (1u << c % bits_per_elem)) != 0;
}

int set_size(const set *s) {
 int i, size = 0;
 for(i = 0; i != 1 << bits_per_char; i++) {
 if(set_in(s, i)) {
 size++;
 }
 }
 return size;
}

bool set_equal(const set *s1, const set *s2) {
 int i;
 for(i = 0; i != datalen; i++) {
 if(s1->data[i] != s2->data[i]) {
 return false;
 }
 }
 return true;
}

bool set_includes(const set *s1, const set *s2) {
 int i;
 for(i = 0; i != datalen; i++) {
 if((s1->data[i] | s2->data[i]) != s1->data[i]) {
 return false;
 }
 }
 return true;
}

set set_union(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] | s2->data[i];
 }
 return result;
}

set set_intersection(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] & s2->data[i];
 }
 return result;
}

set set_difference(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] & ~(s2->data[i]);
 }
 return result;
}

set set_symmetric_difference(const set *s1, const set *s2) {
 int i;
 set result;
 for(i = 0; i != datalen; i++) {
 result.data[i] = s1->data[i] ^ s2->data[i];
 }
 return result;
}

bool is_alpha(int c) { return isalpha(c); }
bool is_digit(int c) { return isdigit(c); }

//--------------------------------------------

bool is_razd(char a) {
  if (a == ' ' || a == '\n' || a == '\t') {
    return true;
  }
  else {
    return false;
  }
}

int main()
{
  set word;
  char c;
  set consonants;
  for (char alpha = 'a'; alpha <= 'z'; alpha++) {
    if (alpha != 'a' && alpha != 'e' && alpha != 'i' && alpha != 'o' && alpha != 'u' && alpha != 'y') {
      set_insert(&consonants, alpha);
    }
  }

  bool flag = true;
  bool sogl = false;
  while ((c = getchar()) != EOF) {
    if (is_razd(c)) {
      set_clear(&word);
    }
    else if (set_in(&consonants, c)) {
      if (set_in(&word, c)) {
        flag = false;
        continue;
      }
      set_insert(&word, c);
      sogl = true;
    }
  }

  if (flag == false) {
    printf("Есть слово, где согласные повторяются\n");
  }
  else {
    printf("Во всех словах согласные различны\n");
  }

  /*int i;
  set s1,s2;

  set_clear(&s1);
  set_generate(&s1,is_alpha);
  set_generate(&s2,is_digit);
  set_insert(&s2,'a');
  set_insert(&s2,'A');
  s1=set_symmetric_difference(&s1, &s2);
  for(i=0;i!=1<<bits_per_char;++i)
    {
      if (set_in(&s1,i)) printf("%d --- in set (%c)\n",i,i);
      //      else               printf("%d --- not in set\n",i);
    }
  printf("size set = %d\n",set_size(&s2));*/
}
 
*/

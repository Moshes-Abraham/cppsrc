#include <iostream>

int main()
{
  unsigned int num;
  char score;
  std :: cin >> num;
  if (num == 5)
    score = 'a';
  else if (num == 4)
    score = 'b';
  else if (num == 3)
    score = 'c';
  else if (num == 2)
    score = 'd';
  else
    score = 'e';
  std :: cout << score;
}

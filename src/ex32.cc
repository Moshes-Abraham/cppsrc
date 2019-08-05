#include <iostream>

int main()
{
  int item1, item2;
  while (std :: cin >> item1 >> item2)
    {
      try
        {

        } catch (std :: runtime_error err)
        {
          std :: cout << err.what()
                      << "\nTry Again? Enter y or n" << std :: endl;
          char c;
          std :: cin >> c;
          if (!std :: cin || c == 'n')
            break;
        }
    }
}

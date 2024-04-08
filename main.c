      #include <stdio.h>
      #include <stdlib.h>
      #include <string.h>

      int main()
      {
          char *names[] = { "Danielle", "Edward", "Francis" };
          char initials[] = { 'D', 'E', 'F' };
          double sales[] = { 0.0, 0.0, 0.0 };

          char input[2];
          double saleAmount;
          int index;

          while (1)
          {
              printf("Enter a salesperson's initial (or 'z' to quit): ");
              scanf("%1s", input);

              if (input[0] == 'z')
                  break;

              index = -1;
              for (int i = 0; i < sizeof(initials); i++)
              {
                  if (initials[i] == input[0])
                  {
                      index = i;
                      break;
                  }
              }

              if (index != -1)
              {
                  printf("Enter the amount of sale: ");
                  scanf("%lf", &saleAmount);
                  sales[index] += saleAmount;
              }
              else
              {
                  printf("Sorry - invalid salesperson\n");
              }
          }

          for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
          {
              printf("%s sold %.2f\n", names[i], sales[i]);
          }

          double totalSales = sales[0] + sales[1] + sales[2];
          printf("Total sales were %.2f\n", totalSales);

          int maxIndex = 0;
          for (int i = 1; i < sizeof(sales) / sizeof(sales[0]); i++)
          {
              if (sales[i] > sales[maxIndex])
                  maxIndex = i;
          }

          int tieCount = 0;
          for (int i = 0; i < sizeof(sales) / sizeof(sales[0]); i++)
          {
              if (sales[i] == sales[maxIndex])
                  tieCount++;
          }

          if (tieCount > 1)
          {
              printf("There was a tie\n");
          }
          else
          {
              printf("%s sold the most\n", names[maxIndex]);
          }

          return 0;
      }
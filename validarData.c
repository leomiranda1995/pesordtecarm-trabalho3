#include
#include

void validarDt()
{
      int dia, mes, ano, bis, erro = 1; // declara��o de vari�veis necess�rias
      char smes[12][11] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho",
                                    "julho", "agosto", "setembro", "outubro", "novembro",
                                    "dezembro"}; // matriz de string para converter de inteiro
                                                      // para string o mes digitado
      printf("Digite uma data: (dd/mm/aaaa)\n");
      printf("Dia: ");
      scanf ("%d", &dia); // le o dia
      printf("\nMes: ");
      scanf("%d", &mes);  // le o mes
      printf("\nAno: ");
      scanf("%d", &ano); // le o ano


      if (mes  12){ /* caso o ano n�o seja v�lido, ser� informado que o ano
                        est� errado, e atribuir� o valor 2 na flag de erro; */
         printf("mes invalido"); erro = 2;}
      else
          if (dia  3000 || ano < 1900) /* caso o ano n�o seja v�lido, ser�
                                                       informado que o ano est� errado,
                                                       e atribuir� o valor 2 na flag de erro; */
              {
                 printf("ano invalido");
                 erro = 2;
              }
              else
                  if (mes == 2) /* caso o mes seja 2, ele verificar� se o ano � bissexto,
                                        caso seja, ele admitir� que o m�s v� at� o dia 29,
                                        caso contrario, apenas at� o dia 28. Qualquer erro
                                        occorido, atribuir� o valor 2 na flag de erro */
                     {
                      if (ano%4 == 0)
                      {
                         if (dia  29){
                            printf("Dia invalido para o mes"); erro = 2;}
                      }
                      else
                          if (dia  28){
                             printf("Dia invalido para o mes"); erro = 2;}
                     }

                        else
                            if (mes < 7) /* caso o m�s v� de 1 a 6, todos os meses
                                                 pares vao at� dia 30, e os impares at� dia 31.
                                                 Ele verificar� isso, atribuindo o valor 2 para a
                                                 flag de erro caso o dia digitado nao
                                                 satisfa�a as condi��es */
                            {
                               if (mes%2 == 0)
                               {
                                  if (dia  30){
                                     printf("Dia inv�lido para o mes"); erro = 2;}
                               }
                               else
                                   if (dia  31){
                                      printf("Dia invalido para o mes"); erro = 2;}
                            }
                            else
                                if (mes > 6) /* caso o m�s seja maior que 6, todos os
                             meses impares ir�o at� o dia 30, e os meses pares
                             ir�o at� o dia 31. Ele verificar� isso, atribuindo o valor 2
                             para a flag de erro caso o dia digitado nao satisfa�a as condi��es */
                                {
                                   if (mes%2 == 0)
                                   {
                                      if (dia > 31){
                                         printf("dia invalido para o mes"); erro = 2;}
                                   }
                                   else
                                       if (dia > 30){
                                          printf("dia invalido para o mes"); erro = 2;}
                                }




      if (erro == 1) // caso nao tenha dado nenhum erro nas datas,
                        // o programa informar� a data digitada e verificar�
                        // se o ano � bissexto
      {
         printf("\n\nDATA DIGITADA: \n%d de %s de %d\n", dia, smes[mes-1], ano);
         bis = ano % 4;
         if (bis == 0) // verifica se o ano � bissexto, exibindo na tela
             printf("\nAno bissexto\n");
         else
             printf("Nao e bissexto\n");
      }

      system("pause");
}

An�ncios

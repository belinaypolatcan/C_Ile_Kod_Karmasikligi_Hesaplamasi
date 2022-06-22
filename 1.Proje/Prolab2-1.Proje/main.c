#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



// 210202104 Belinay Polatcan
// 200202015 Ahmet Can Okumus



 int CalculateBigO(){


    int sayac=0;

    int maxsayac=0;


  char const* const fileName = "kodlar.txt";

    FILE* file = fopen(fileName, "r");

    char line[500];



     while (fgets(line, sizeof(line), file))
    {

        if(strstr(line,"for ") || strstr(line,"while "))
        {
            sayac = sayac + 1 ;
        }
        if(strstr(line,"} ")){

            if (sayac > maxsayac){

                maxsayac = sayac;

            }

            sayac = sayac - 1 ;


        }



     }


        return maxsayac;

 }



int main()
{

     clock_t start_t, end_t;

      FILE* file = fopen("kodlar.txt", "r");

       char line[1000];



    int yerkarma;
    int dizisayac;

    int dizisayac2;
    int logsayac;
    int bigo;





    while (fgets(line, sizeof(line), file))
    {

        printf("%s", line);

        }

        fclose(file);

       start_t=clock();

     for(int i=0;i<32765;i++)

        {




     yerkarma=0;
    dizisayac=0;

     dizisayac2=0;
     logsayac=0;






    FILE* file = fopen("kodlar.txt", "r");



    char line2[1000];


    while (fgets(line2, sizeof(line2), file))
    {





        if(strstr(line2,"int ") || strstr(line2,"return ") || strstr(line2,"float ") || strstr(line2,"long ")){

            yerkarma=yerkarma+4;

        }

        if(strstr(line2,"//int ")){
            yerkarma=yerkarma-4;
        }

        if(strstr(line2,"[n] ") || strstr(line2, "[] ")) {

            dizisayac=dizisayac+1;
             yerkarma=yerkarma-4;

        }
        if(strstr(line2,"[n][n] ") || strstr(line2,"[][] ")){

           dizisayac2=dizisayac2+2;

           dizisayac=dizisayac-1;

           }



        if(strstr(line2,"char ") || strstr(line2,"bool ")){

            yerkarma=yerkarma+1;

        }

        if(strstr(line2,"i=i* ") || strstr(line2,"j=j* ")){

            logsayac=logsayac+1;

        }



    }




    fclose(file);




     }


     bigo=CalculateBigO();






      if(logsayac<=0){

        if(bigo==0){

             printf("\nbigO karmasiklik hesabi: O(1)\n");
        }


        printf("\nbigO karmasiklik hesabi: O(n^%d)\n",bigo);

    }



    if(logsayac>0){

    bigo=bigo-logsayac;

    printf("\nbigO karmasiklik hesabi: O(n^%d*log^%d(n))\n",bigo,logsayac);


    }



    printf("\n");



    printf("Yer(hafiza) karmasikligi: %d +%d.(4n)+4(n^%d) ",yerkarma,dizisayac,dizisayac2);

     end_t=clock();


    printf(" Verilen kodun calisma süresi: %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);


    return 0;

}

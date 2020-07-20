#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double squere_ave,int n);
int main(void)
{
    double val,var,ave,squere_ave,squere_ave_n1,ave_n1=0,gosa,huhen;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int n=0;
   
    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
    ave=ave_online(n,val,ave_n1,n);
    squere_ave=ave_online(val*val,ave_n1,n);
    var=var_online(val,ave_n1,squere_ave_n1,n);
    ave_n1=ave;
    n=n+1;
    }
    huhen=n*var/(n-1);
    gosa=pow(huhen/n,0.5);
    

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

double ave_online(double val,double ave,int n)
{    double ave_n;
    ave_n=(((n-1)/n)*ave)+(val/n);
    return ave_n;}
double var_online(double val,double ave,double square_ave,int n)
{     double var;
    var=((n-1)/n)*(square_ave)+(pow(val,2)/n)-pow(((n-1)*ave)/n+(val/n),2);
      return var;}   






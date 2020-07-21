#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _USE_MATH_DEFINES
extern double p_stdnorm(double z);
#define MU_A 170.8
#define MU_B 169.9
#define sigma_A 5.43
#define sigma_B 5.5
int main(void)
{
    double val,m1,m2,s1,s2,y1,y2,x1,x2;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

    m1=MU_A;
    m2=MU_B;
    s1=sigma_A;
    s2=sigma_B;

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
    y1=(val-m1)/s1;
    y2=(val-m2)/s2;
    x1=p_stdnorm(y1);
    x2=p_stdnorm(y2);
    L1=L1*x1;
    L2=L2*x2;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L1);
    printf("L_B: %f\n",L2);

    return 0;


}

double p_stdnorm(double z)
{   
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define N 256


struct D{double ID;int gender;double height;};
int main(void)
{
    int i,data_exist;
    double val,id,ID;
    char fname[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    char buf[256];
    char buf2[256];
    FILE* fp,*fp2;
    int gender,num_male,num_female,num_unknoown,num_whole;
    struct D date[N];
    i=-1;
    data_exist=0;

    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);
    
    printf("input the filename of sample ID:");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] = '\0';
    printf("the filename of sample: %s\n",fname2);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }


    num_male=num_female=num_unknoown=0;
    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
        sscanf(buf,"%d,%lf",&gender,&val);
        i++;
        date[i].gender=gender;
        date[i].height=val;
    if(gender==1)
    {
        num_male++;
    }
    else if(gender==2)
    {
        num_female++;
    }
    else
    {
        num_unknoown++;
    }
}
num_whole = num_male+num_female+num_unknoown;

printf("Which ID's data do you want?:\n");
scanf("%lf",&id);

i=0;
while(fgets(buf2,sizeof(buf2),fp2) !=NULL)
{
    sscanf(buf2,"%lf",&ID);
    i++;
    date[i].ID=ID;
}
for(i=1;i<=num_whole;i++)
{
    if(date[i].ID==id)
    {
        printf("ID:%.0lf\n",date[i].ID);
        printf("gender:");
        if(date[i].gender==1)
        {
            printf("male\n");
        }
        else
        {
            printf("female\n");
        }
        printf("height:%1lf\n",date[i].height);
        data_exist=1;
    }
}
if(data_exist==0){
            printf("No date\n");
        }
return 0;
}


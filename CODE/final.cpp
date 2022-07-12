#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct sms
{
    char id[100];
    char name[100];
    char gender[100];
    char area[100];
    char religion[100];
    char background[100];
    char blood[100];
    char fop[100];
    int hsc;
    int age;
    float cgpa;
};
struct login
{
    char email[200];
    char password[100];
};
struct book
{
    char id[100];
    char name[100];
    char publisher_name[100];
    char catagory[100];
    char type[100];
    float price;
    int avail;
};
struct record
{
    char name[1000];
    char reg[1000];
    int level;
    int term;
    float cg;
};
int interface1()
{
    printf("Developed by MD AMIRUL ISLAM\n");
    printf("\n\n\t\t\t\tWelcome to\n");
    printf("\n\t\t\tUniversity of Asia Pacific\n\n\n");
    printf("\t\tPress 1 to enter Admin Section\n");
    printf("\t\tPress 2 to enter Student Section\n");
    printf("\t\tPress 3 to enter Library management\n");
    int enter;
    scanf("%d",&enter);
    if(enter==1)
    {
        return 1;
    }
    else if(enter==2)
    {
        return 2;
    }
    else if(enter==3)
    {
        return 3;
    }
    else
    {
        printf("\n\nWrong Keyword\n");
        printf("Press anykey");
        getch();
        system("cls");
        interface1();
    }
}
void admin_section()
{
    printf("\t\t\tStudent Management System\n\n");
    printf("Press...\n");
    printf("1. Count Male Student\t2. Count Female Student\t3. Highest CGPA\n");
    printf("4. Youngest ID\t        5. Oldest ID\t\t6. Youngest Male\n");
    printf("7. Youngest Female\t8. Highest Female CG\t9.Highest Male CG\n");
    printf("10. From Dhaka\t\t11. Outside Dhaka\t12. Blood Group\n");
    printf("13. Muslim+Hindu Student 14.Diploma Background\t15. 3.50+ CG\n");
    printf("16. HSC Year\t\t17. Left The Versity\t18.Father's no more\n");
    printf("19. Father's Occupation\t20. Logout\n");
}
void student_section()
{
    printf("Press...\n");
    printf("1. Book Search\n");
    printf("2. Catagory-wise Search\n");
    printf("3. Book Order\n");
    printf("4. Log-out\n");
}
void library()
{
    printf("Press...\n");
    printf("1. Enter Records.\n");
    printf("2. Search a Record.\n");
    printf("3. Edit a Record.\n");
    printf("4. Delete a Record.\n");
    printf("5. Logout.\n");
}
void lib1()
{
    system("cls");
    int i,k=1,press;
    record s[k];
    FILE *f;
    f=fopen("record.txt","a");
    char l[1000],m[100];
    int n,o;
    float p;
    printf("Name -\t");
    getchar();
    scanf("%s",l);
    printf("Reg -\t");
    getchar();
    scanf("%s",m);
    printf("Level -\t");
    scanf("%d",&n);
    printf("Term -\t");
    scanf("%d",&o);
    printf("CGPA -\t");
    scanf("%f",&p);
    fprintf(f,"%s %s %d %d %f\n",l,m,n,o,p);
    fclose(f);
    po:printf("Entry new record ?\nPress 1 to Yes\tPress 2 to no\n");
    scanf("%d",&press);
    if(press==1)
    {
        system("cls");
        lib1();
    }
    else if(press==2)
    {
        printf("Thank you !\n");
        printf("Press any key ");
        getch();
        system("cls");
    }
    else
    {
        printf("Wrong key word !\n");
        system("cls");
        goto po;
    }
}
void lib2()
{
    system("cls");
    int i,n,cnt=0;
    FILE *fr;
    fr=fopen("record.txt","r");
    char ch;
    while((ch=fgetc(fr))!=EOF)
    {
        if(ch=='\n')
        {
            cnt++;
        }
    }
    n=cnt;
    record s[n];
    FILE *f;
    f=fopen("record.txt","r");
    for(i=0;i<n;i++)
    {
        fscanf(f,"%s %s %d %d %f",s[i].name,s[i].reg,&s[i].level,&s[i].term,&s[i].cg);
    }
    fclose(f);
    char reg[1000];
    printf("Enter a registration number - ");
    scanf("%s",reg);
    for(i=0;i<n;i++)
    {
       //printf("%s %s",reg,s[i].reg);
        if(strcmp(reg,s[i].reg)==0)
        {
            printf("Name -\t");
            puts(s[i].name);
            printf("Reg -\t");
            puts(s[i].reg);
            printf("Level -\t");
            printf("%d\n",s[i].level);
            printf("Term-\t");
            printf("%d\n",s[i].term);
            printf("CGPA-\t");
            printf("%.2f\n",s[i].cg);
        }
    }
    printf("\n\tPress anykey ");
    getch();
    system("cls");
}
void lib3()
{
    system("cls");
    int i,n,press,cnt=0;
    FILE *fr;
    FILE *del;
    del=fopen("edit.txt","w");
    fclose(del);
    fr=fopen("record.txt","r");
    char chr;
    while((chr=fgetc(fr))!=EOF)
    {
        if(chr=='\n')
        {
            cnt++;
        }
    }
    n=cnt;
    record s[n];
    FILE *f;
    f=fopen("record.txt","r");
    for(i=0;i<n;i++)
    {
        fscanf(f,"%s %s %d %d %f",s[i].name,s[i].reg,&s[i].level,&s[i].term,&s[i].cg);
    }
    fclose(f);
    char id[1000];
    printf("Enter a registration number - ");
    scanf("%s",id);
    int e;
    for(i=0;i<n;i++)
    {
        if(strcmp(id,s[i].reg)==0)
            {
                //printf("%d\n",i);
                e=i;
                break;
            }
    }
    f=fopen("edit.txt","a");
    for(i=0;i<e;i++)
    {
        fprintf(f,"%s %s %d %d %f",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
    }
    fclose(f);
            printf("1. Name -\t");
            puts(s[e].name);
            printf("2. Reg -\t");
            puts(s[e].reg);
            printf("3. Level -\t");
            printf(" %d\n",s[e].level);
            printf("4. Term-\t");
            printf("%d\n",s[e].term);
            printf("5. CGPA-\t");
            printf("%.2f\n",s[e].cg);
            f=fopen("edit.txt","a");
            char g[100];
            pop:printf("Press the serial number to edit .\n");
            scanf("%d",&press);
            if(press==1)
            {
                printf("Now edit - ");
                getchar();
                gets(g);
                strcpy(s[e].name,g);
                if(e==0)
                {
                    fprintf(f,"%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                else
                {
                    fprintf(f,"\n%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                fclose(f);
                int c=e+1;
                f=fopen("edit.txt","a");
                for(i=c;i<n;i++)
                {
                    fprintf(f,"\n%s %s %d %d %f",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
                }
                fclose(f);
                printf("press anykey ");
                getch();
                system("cls");
            }
            else if(press==2)
            {
                printf("Now edit - ");
                getchar();
                gets(g);
                strcpy(s[e].reg,g);
                if(e==0)
                {
                    fprintf(f,"%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                else
                {
                    fprintf(f,"\n%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                fclose(f);
                int c=e+1;
                f=fopen("edit.txt","a");
                for(i=c;i<n;i++)
                {
                    fprintf(f,"\n%s %s %d %d %f",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
                }
                fclose(f);
                printf("press anykey ");
                getch();
                system("cls");
            }
            else if(press==3)
            {
                printf("Now edit - ");
                int fff;
                scanf("%d",&fff);
                s[e].level=fff;
                if(e==0)
                {
                    fprintf(f,"%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                else
                {
                    fprintf(f,"\n%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                fclose(f);
                int c=e+1;
                f=fopen("edit.txt","a");
                for(i=c;i<n;i++)
                {
                    fprintf(f,"\n%s %s %d %d %f",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
                }
                fclose(f);
                printf("press anykey ");
                getch();
                system("cls");
            }
            else if(press==4)
            {
                printf("Now edit - ");
                int fff;
                scanf("%d",&fff);
                s[e].term=fff;
                if(e==0)
                {
                    fprintf(f,"%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                else
                {
                    fprintf(f,"\n%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                fclose(f);
                int c=e+1;
                f=fopen("edit.txt","a");
                for(i=c;i<n;i++)
                {
                    fprintf(f,"\n%s %s %d %d %f",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
                }
                fclose(f);
                printf("press anykey ");
                getch();
                system("cls");
            }
            else if(press==5)
            {
                printf("Now edit - ");
                float fff;
                scanf("%f",&fff);
                s[e].cg=fff;
                if(e==0)
                {
                    fprintf(f,"%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                else
                {
                    fprintf(f,"\n%s %s %d %d %f",s[e].name,s[e].reg,s[e].level,s[e].term,s[e].cg);
                }
                fclose(f);
                int c=e+1;
                f=fopen("edit.txt","a");
                for(i=c;i<n;i++)
                {
                    fprintf(f,"\n%s %s %d %d %f",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
                }
                fclose(f);
                printf("Press anykey ");
                getch();
                system("cls");
            }
            else
            {
                printf("Wrong keyword\n");
                printf("press anykey ");
                getch();
                system("cls");
                goto pop;
            }
            FILE *f1,*f2;
            char ch;
            f1=fopen("edit.txt","r");
            f2=fopen("record.txt","w");
            if(f1==NULL)
            {
                exit(0);
            }
             for(i=0;i<n;i++)
             {
                 fscanf(f1,"%s %s %d %d %f",s[i].name,s[i].reg,&s[i].level,&s[i].term,&s[i].cg);
             }
             for(i=0;i<n;i++)
             {
                 fprintf(f2,"%s %s %d %d %f\n",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
             }
            fclose(f1);
            fclose(f2);
            f1=fopen("edit.txt","w");
            fclose(f1);
}
void lib4()
{
        system("cls");
        int i,n,press,cnt=0;
        FILE *opps;
        opps=fopen("aa.txt","w");
        fclose(opps);
        FILE *fr;
        fr=fopen("record.txt","r");
        char chr;
        while((chr=fgetc(fr))!=EOF)
        {
            if(chr=='\n')
            {
                cnt++;
            }
        }
        n=cnt;
        fclose(fr);
        record s[n];
        FILE *f;
        f=fopen("record.txt","r");
        for(i=0;i<n;i++)
        {
            fscanf(f,"%s %s %d %d %f",s[i].name,s[i].reg,&s[i].level,&s[i].term,&s[i].cg);
        }
        fclose(f);
        int level,term,e;
        printf("Enter level - ");
        scanf("%d",&level);
        printf("Enter term - ");
        scanf("%d",&term);
        system("cls");
        printf("The Regestration Numbers are here - \n");
        for(i=0;i<n;i++)
        {
            if(level==s[i].level)
            {
                if(term==s[i].term)
                {
                        puts(s[i].reg);
                }
            }
        }
        printf("\n\n\t\tEnter a Registration number\n\t\t");
        getchar();
        char tst[100];
        gets(tst);
        system("cls");
        for(i=0;i<n;i++)
        {
            if(level==s[i].level)
            {
                if(term==s[i].term)
                {
                    if(strcmp(tst,s[i].reg)==0)
                    {
                        puts(s[i].name);
                        puts(s[i].reg);
                        printf("%.2f",s[i].cg);
                        e=i;
                    }
                }
            }
        }
        FILE *t;
        t=fopen("aa.txt","a");
        for(i=0;i<e;i++)
        {
            fprintf(t,"%s %s %d %d %f\n",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
        }
        for(i=e+1;i<n;i++)
        {
            fprintf(t,"%s %s %d %d %f\n",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
        }
        fclose(t);
        int del=(n-1);
        FILE *x,*y;
        x=fopen("aa.txt","r");
        y=fopen("record.txt","w");
        for(i=0;i<del;i++)
        {
            fscanf(x,"%s %s %d %d %f",s[i].name,s[i].reg,&s[i].level,&s[i].term,&s[i].cg);
        }
        for(i=0;i<del;i++)
        {
            fprintf(y,"%s %s %d %d %f\n",s[i].name,s[i].reg,s[i].level,s[i].term,s[i].cg);
        }
        fclose(x);
        fclose(y);
        opps=fopen("aa.txt","w");
        fclose(opps);
        printf("\n\tOperation ok\n");
        printf("\nPress Any key ");
        getch();
        system("cls");
}
int main()
{
    man:system("color F0");
    int i,n=50;
    sms s[n];
    FILE *f;
    f=fopen("sms.txt","r");
    for(i=0;i<50;i++)
    {
        fscanf(f,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%d:%d:%f",s[i].id,s[i].name,s[i].gender,s[i].area,s[i].religion,s[i].background,s[i].blood,s[i].fop,&s[i].age,&s[i].hsc,&s[i].cgpa);
    }
    fclose(f);
    int p=interface1();
    if(p==1)
    {
      l1:printf("\t\t\tAdmin Login\n\n");
        system("cls");
        system("color E5");
        char w[1000],y[100];
        getchar();
        printf("\nEnter your ID-\t");
        gets(w);
        printf("Enter password-\t");
        //gets(y);
        int pointer=0;
        char ch;
        while(1)
        {
            ch=getch();
            if(ch==13)//For Enter key
            {
                break;
            }
            else if(ch==8)//For Backspace key
            {
                if(pointer>0)
                {
                    pointer--;
                    y[pointer]='\0';
                    printf("\b \b"); /* first \b is scapping and removing *
                                        <SPACE> is for blank in lieu of * blinding the console
                                         second \b is scapping the space */
                }
            }
            else if(ch==32 || ch==9)
            {
                continue;
            }
            else
            {
                y[pointer]=ch;
                pointer++;
                printf("*");
            }
        }
        y[pointer]='\0';
        int ggg=1;
        if(strcmp(w,"Admin")==0&&strcmp(y,"12569")==0)
        {
            ggg=0;
        }
        if(ggg==1)
        {
            printf("\n\n\tYou are not an admin!!!!!\n\n");
            char vua[1];
                printf("   [ Want to watch your password ? 'Y' ] ");
                scanf("%s",vua);
                strlwr(vua);
                if(strcmp(vua,"y")==0)
                {
                    printf("   %s\n",y);
                }
            printf("Press any key ");
            getch();
            system("cls");
            goto l1;
        }
        else
            {
                system("color F0");
                system("cls");
                int z;
                a:admin_section();
                while(1)
                {
                    scanf("%d",&z);
                    if(z==1)
                    {
                        system("cls");
                        printf("\n How many male student ? \n");
                        int male=0;
                        for(i=0;i<n;i++)
                        {
                            if(strcmp(s[i].gender,"Male")==0)
                            {
                                male++;
                            }
                        }
                        printf("\nNumber of Male Student- %d\n",male);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==2)
                    {
                        system("cls");
                                printf("\n How many female student ? \n");
                                int female=0;
                                for(i=0;i<n;i++)
                                {
                                    if(strcmp(s[i].gender,"Female")==0)
                                        {
                                            female++;
                                        }
                                }
                                printf("\nNumber of Female Student- %d\n",female);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==3)
                    {
                        system("cls");
                        printf("\nWhich student has the Highest CGPA\n");
                            float high=-1000;
                            for(i=0;i<n;i++)
                            {
                                if(s[i].cgpa>high)
                                {
                                    high=s[i].cgpa;
                                }
                            }
                            printf("\nHighest CGPA\n");
                            for(i=0;i<n;i++)
                            {
                                if(s[i].cgpa==high)
                                {
                                    puts(s[i].name);
                                    puts(s[i].id);
                                    printf("%.2f\n",s[i].cgpa);
                                }
                            }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==4)
                    {
                        system("cls");
                        printf("\nWho is the youngest ?\n");
                            int young=1000;
                            for(i=0;i<n;i++)
                            {
                                if(s[i].age<young)
                                {
                                    young=s[i].age;
                                }
                            }
                            printf("\nYoungest Student\n");
                            for(i=0;i<n;i++)
                            {
                                if(s[i].age==young)
                                {
                                    puts(s[i].name);
                                    printf("ID-%s\n",s[i].id);
                                    printf("Age-%d\n",s[i].age);
                                }
                            }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==5)
                    {
                        system("cls");
                            printf("Who is the oldest student ?\n");
                            int old=-1000;
                            for(i=0;i<n;i++)
                            {
                                if(s[i].age>old)
                                {
                                    old=s[i].age;
                                }
                            }
                            printf("\nOLDEST ID\n");
                            for(i=0;i<n;i++)
                            {
                                if(s[i].age==old)
                                {
                                    puts(s[i].name);
                                    printf("ID-%s\n",s[i].id);
                                    printf("Age-%d\n",s[i].age);
                                }
                            }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==6)
                    {
                        system("cls");
                        printf("Who is the youngest male ?\n");
                            int ymale=10000;
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].gender,"Male")==0)
                                {
                                    if(s[i].age<ymale)
                                    {
                                        ymale=s[i].age;
                                    }
                                }
                            }
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].gender,"Male")==0)
                                {
                                    if(s[i].age==ymale)
                                    {
                                        puts(s[i].name);
                                        printf("ID-%s\n",s[i].id);
                                        printf("Age-%d\n",s[i].age);
                                    }
                                }
                            }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==7)
                    {
                        system("cls");
                        printf("\n Who is the youngest Female ?\n");
                                    int ylady=1000;
                                    for(i=0;i<n;i++)
                                    {
                                        if(strcmp(s[i].gender,"Female")==0)
                                        {
                                            if(s[i].age<ylady)
                                            {
                                                ylady=s[i].age;
                                            }
                                        }
                                    }
                                    printf("\nYoungest Lady\n");
                                    for(i=0;i<n;i++)
                                    {
                                        if(strcmp(s[i].gender,"Female")==0)
                                        {
                                            if(s[i].age==ylady)
                                            {
                                                puts(s[i].name);
                                                printf("ID : %s\n",s[i].id);
                                                printf("AGE : %d\n",s[i].age);
                                            }
                                        }
                                    }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==8)
                    {
                        system("cls");
                        printf("Which Female student have highest CGPA among the female student ?\n");
                                    float hfcgpa=-1000;
                                    for(i=0;i<n;i++)
                                    {
                                        if(strcmp(s[i].gender,"Female")==0)
                                        {
                                            if(s[i].cgpa>hfcgpa)
                                            {
                                                hfcgpa=s[i].cgpa;
                                            }
                                        }
                                    }
                                    for(i=0;i<n;i++)
                                    {
                                        if(strcmp(s[i].gender,"Female")==0)
                                        {
                                            if(s[i].cgpa==hfcgpa)
                                            {
                                                puts(s[i].name);
                                                printf("CGPA= %.2f\n",s[i].cgpa);
                                            }
                                        }
                                    }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==9)
                    {
                        system("cls");
                        printf("WHo has the Highest CGPA among male student?\n");
                            float hmcgpa=-1000;
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].gender,"Male")==0)
                                {
                                    if(s[i].cgpa>hmcgpa)
                                    {
                                        hmcgpa=s[i].cgpa;
                                    }
                                }
                            }
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].gender,"Male")==0)
                                {
                                    if(s[i].cgpa==hmcgpa)
                                    {
                                        puts(s[i].name);
                                        printf("CGPA= %.2f\n",s[i].cgpa);
                                    }
                                }
                            }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==10)
                    {
                        system("cls");
                        printf("\n Which Student come from Dhaka ?\n");
                            printf("From Dhaka \n");
                            int dhaka=0;
                            for(i=0;i<n;i++)
                            {
                              if(strcmp(s[i].area,"Dhaka")==0)
                              {
                                  dhaka++;
                              }
                            }
                            printf("%d\n",dhaka);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==11)
                    {
                        system("cls");
                        printf("Which student come from outside Dhaka ?\n");
                            printf("Outside Dhaka \n");
                            int ndhaka=0;
                            for(i=0;i<n;i++)
                            {
                              if(strcmp(s[i].area,"Dhaka")!=0)
                              {
                                  ndhaka++;
                              }
                            }
                            printf("%d\n",ndhaka);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==12)
                    {
                        system("cls");
                        int o=0;
                            printf("\t\tBlood group - 'O'\n");
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].blood,"O+")==0)
                                {
                                    puts(s[i].name);
                                    o++;
                                }
                            }
                            printf("\nTotal -\t%d\n",o);
                            int A=0;
                            printf("\t\tBlood group - 'A'\n");
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].blood,"A")==0)
                                {
                                    puts(s[i].name);
                                    A++;
                                }
                            }
                            printf("\nTotal -\t%d\n",A);
                            int b=0;
                            printf("\t\tBlood group - 'B'\n");
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].blood,"B")==0)
                                {
                                    puts(s[i].name);
                                    b++;
                                }
                            }
                            printf("\nTotal -\t%d\n",b);
                            int ab=0;
                            printf("\t\tBlood group - 'AB'\n");
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].blood,"AB")==0)
                                {
                                    puts(s[i].name);
                                    ab++;
                                }
                            }
                            printf("\nTotal -\t%d\n",ab);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==13)
                    {
                        system("cls");
                        printf("Number of hindu & Islam religion student ?\n");
                            int hindu=0, muslim=0;
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].religion,"Islam")==0)
                                {
                                    muslim++;
                                }
                            }
                            printf("Number of muslim Student is-\t%d\n",muslim);
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].religion,"Hindu")==0)
                                {
                                    puts(s[i].name);
                                    hindu++;
                                }
                            }
                            printf("IN TOTAL (hindu pupil) -\t%d\n",hindu);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==14)
                    {
                        system("cls");
                        printf("Which student have the diploma background?\n");
                            int ndiploma=0;
                            printf("Diploma holders :\n");
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].background,"Diploma")==0)
                                {
                                    puts(s[i].name);
                                }
                                else
                                {
                                    ndiploma++;
                                }
                            }
                            printf("Number of Non Diploma : %d\n",ndiploma);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==15)
                    {
                        system("cls");
                        printf("who obtain 3.50+ cgpa ?\n");
                                    printf("Cgpa above 3.50\n");
                                    for(i=0;i<n;i++)
                                    {
                                        if(s[i].cgpa>=3.50)
                                        {
                                            puts(s[i].name);
                                        }
                                    }
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                    else if(z==16)
                    {
                        system("cls");
                        printf("HSC passing year ?\n");
                            int oh=0,nh=0;
                            for(i=0;i<n;i++)
                            {
                                if(s[i].hsc==2014)
                                {
                                    oh++;
                                }
                                else if(s[i].hsc==2015)
                                {
                                    nh++;
                                }
                                else
                                {
                                    printf("Below 2014\n");
                                    puts(s[i].name);
                                }
                              }
                                printf("\nHSC in 2014= %d\n",oh);
                                printf("HSC in 2015= %d\n",nh);
                        printf("Press anykey ");
                        getch();
                        system("cls");
                        goto a;
                    }
                else if(z==17)
                {
                    system("cls");
                    printf("WHO left the university ?\n");
                        printf("Leaving the university\n");
                        for(i=0;i<n;i++)
                        {
                            if(s[i].cgpa==0.00)
                            {
                                puts(s[i].name);
                            }
                        }
                    printf("Press anykey ");
                    getch();
                    system("cls");
                    goto a;
                }
                else if(z==18)
                {
                    system("cls");
                    printf("Whose Father's are no more?\n");
                        for(i=0;i<n;i++)
                        {
                            if(strcmp(s[i].fop,"Late")==0)
                            {
                                puts(s[i].name);
                            }
                        }
                    printf("Press anykey ");
                    getch();
                    system("cls");
                    goto a;
                }
                else if(z==19)
                {
                    system("cls");
                    printf("Father occupation ?\n");
                            int doctor=0,engineer=0,lawyer=0,businessman=0,civil=0,sh=0;
                            for(i=0;i<n;i++)
                            {
                                if(strcmp(s[i].fop,"Civil")==0)
                                {
                                    civil++;
                                }
                                if(strcmp(s[i].fop,"Businessman")==0)
                                {
                                    businessman++;
                                }
                                if(strcmp(s[i].fop,"Doctor")==0)
                                {
                                    doctor++;
                                }
                                if(strcmp(s[i].fop,"Engineer")==0)
                                {
                                    engineer++;
                                }
                                if(strcmp(s[i].fop,"Service Holder")==0)
                                {
                                    sh++;
                                }
                                if(strcmp(s[i].fop,"Lawyer")==0)
                                {
                                    lawyer++;
                                }
                            }
                            printf("Civil-\t%d\n",civil);
                            printf("Doctor-\t%d\n",doctor);
                            printf("Businessman-\t%d\n",businessman);
                            printf("Engineer-\t%d\n",engineer);
                            printf("Service Holder - %d\n",sh);
                            printf("Lawyer\t%d\n",lawyer);
                    printf("Press anykey ");
                    getch();
                    system("cls");
                    goto a;
                }
                else if(z==20)
                {
                    system("color 06");
                    system("cls");
                    printf("Thank you for using\n");
                    printf("Press any key ");
                    getch();
                    system("cls");
                    goto man;
                }
                else
                {
                    printf("Wrong Keyword !\n");
                    printf("Press anykey ");
                    getch();
                    system("cls");
                    goto a;
                }
            }
        }
    }
    else if(p==2)
    {
        system("cls");
        system("color 06");
        l2:printf("\t\t\tUAP LIBRARY\n\n");
                int j,k,nn;
                nn=1;
                printf("Press 100 to registration\nPress 101 to login\n");
                scanf("%d",&j);
                if(j==100)
                {
                    system("cls");
                    getchar();
                    b:printf("\n\n\tPlease use example@uap-bd.edu \n\n");
                    char sid[1000],m[1000];
                    FILE *reg;
                    reg=fopen("Reg.txt","a");
                    printf("Enter your Email-\t");
                    gets(sid);
                    printf("Enter your Password-\t");
                    gets(m);
                        char check[1000];
                        strcpy(check,"uap-bd.edu");
                        int inc=0,err=0,incc=0,errr;
                        errr=strlen(check);
                        for(i=0;sid[i]!='\0';i++)
                        {
                            if(sid[i]=='@')
                            {
                                err=1;
                            }
                        }
                        if(err==0)
                        {
                            printf("\n\t\tError Type email\n");
                            printf("Press anykey ");
                            getch();
                            system("cls");
                            goto b;
                        }
                        else
                        {
                            for(i=0;sid[i]!='@';i++)
                            {
                                inc++;
                            }
                            for(i=(inc+1);sid[i]!='\0';i++)
                            {
                                incc++;
                            }
                            if(errr!=incc)
                            {
                                printf("\n\t\tNot acceptable!\n");
                                printf("Press anykey ");
                                getch();
                                system("cls");
                                goto b;
                            }
                            else
                            {
                                fprintf(reg,"%s %s\n",sid,m);
                                printf("Registration Successful! Please Wait for Confirmation....\n");
                                printf("Press anykey ");
                                getch();
                                system("cls");
                                goto l2;
                            }
                        }
                    fclose(reg);
                }
                else if(j==101)
                {
                    system("cls");
                    system("color 29");
                    getchar();
                    int i,nn,cnt=0;
                    FILE *fr;
                    fr=fopen("Reg.txt","r");
                    char chr;
                    while((chr=fgetc(fr))!=EOF)
                    {
                        if(chr=='\n')
                        {
                            cnt++;
                        }
                    }
                    nn=cnt;
                            l3:login m[nn];
                            FILE *g;
                            g=fopen("Reg.txt","r");
                            for(i=0;i<nn;i++)
                            {
                                fscanf(g,"%s %s",m[i].email,m[i].password);
                            }
                           /* for(i=0;i<nn;i++)
                            {
                                puts(m[i].email);
                                puts(m[i].password);
                            }*/
                            fclose(g);
                            char p[1000],q[100];
                            printf("\t\tStudent's Login\n\n");
                            printf("enter your email -\t");
                            gets(p);
                            printf("enter you password -\t");
                            //gets(q);
                            int pointer=0;
                            char ch;
                            while(1)
                            {
                                ch=getch();
                                if(ch==13)//For Enter key
                                {
                                    break;
                                }
                                else if(ch==8)//For Backspace key
                                {
                                    if(pointer>0)
                                    {
                                        pointer--;
                                        q[pointer]='\0';
                                        printf("\b \b"); /* first \b is scapping and removing *
                                                            <SPACE> is for blank in lieu of * blinding the console
                                                             second \b is scapping the space */
                                    }
                                }
                                else if(ch==32 || ch==9)
                                {
                                    continue;
                                }
                                else
                                {
                                    q[pointer]=ch;
                                    pointer++;
                                    printf("*");
                                }
                            }
                            q[pointer]='\0';
                            int flag=0,a,b;
                            for(i=0;i<nn;i++)
                            {
                                a=strcmp(p,m[i].email);
                                b=strcmp(q,m[i].password);
                                if(a==0&&b==0)
                                {
                                    flag=0;
                                    break;
                                }
                                else
                                {
                                    flag=1;
                                }
                            }
                            if(flag==0)
                            {
                                system("cls");
                                system("color F0");
                                printf("\t\tTHANK YOU\n");
                                int press;
                                int oo=8; /* Number of books */
                                char email[1000];
                                strcpy(email,m[i].email);
                                book y[oo];
                                FILE *r;
                                r=fopen("Books.txt","r");
                                for(i=0;i<oo;i++)
                                {
                                    fscanf(r,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%f:%d",y[i].id,y[i].name,y[i].publisher_name,y[i].catagory,y[i].type,&y[i].price,&y[i].avail);
                                }
                                fclose(r);
                                /******** Test OUTPUT **********
                                for(i=0;i<oo;i++)
                                {
                                    puts(y[i].id);
                                    puts(y[i].name);
                                    puts(y[i].publisher_name);
                                    puts(y[i].catagory);
                                    puts(y[i].type);
                                    printf("%.2f\n",y[i].price);
                                    printf("Available :%d\n",y[i].avail);
                                }*/
                            o:student_section();
                            while(1)
                            {
                                scanf("%d",&press);
                                if(press==1)
                                {
                                    system("cls");
                                    printf("Is The Book Available in the Library?\n");
                                                            char tt[1000];
                                                            int ll;
                                                            getchar();
                                                            gets(tt);
                                                            strlwr(tt);
                                                            for(i=0;i<oo;i++)
                                                            {
                                                                strlwr(y[i].name);
                                                                ll=strcmp(tt,y[i].name);
                                                                if(ll==0)
                                                                {
                                                                    printf("\n\n");
                                                                    puts(y[i].name);
                                                                    printf("\tID-\t%s\n",y[i].id);
                                                                    printf("\tTotal Available: %d\n",y[i].avail);
                                                                    break;
                                                                }
                                                                else
                                                                {
                                                                    printf("\nSORRY!!! Not available at this moment\n");
                                                                    break;
                                                                }
                                                            }
                                            printf("Press any key ");
                                            getch();
                                            system("cls");
                                            goto o;
                                }
                                else if(press==2)
                                {
                                    system("cls");
                                    char mm[100];
                                    int ll;
                                        getchar();
                                        printf("Enter the catagory name (MUST BE IN UPPERCASE)-\t");
                                        gets(mm);
                                        for(i=0;i<oo;i++)
                                        {
                                            ll=strcmp(mm,y[i].catagory);
                                            if(ll==0)
                                            {
                                                printf("NAME:-");
                                                puts(y[i].name);
                                                printf("Type:-");
                                                puts(y[i].type);
                                                printf("---------------\n");
                                            }
                                        }
                                    printf("Press any key ");
                                    getch();
                                    system("cls");
                                    goto o;
                                }
                                else if(press==3)
                                {
                                    system("cls");
                                        getchar();
                                        int err=0;
                                        char book[1000],writter[1000];
                                        printf("Book : ");
                                        gets(book);
                                        printf("Writter : ");
                                        gets(writter);
                                        strlwr(book);
                                        strlwr(writter);
                                        for(i=0;i<oo;i++)
                                        {
                                            strlwr(y[i].publisher_name);
                                            strlwr(y[i].name);
                                            if(strcmp(book,y[i].name)==0)
                                            {
                                                if(strcmp(writter,y[i].publisher_name)==0)
                                                {
                                                    if(y[i].avail>0)
                                                    {
                                                        FILE *req;
                                                        req=fopen("req.txt","a");
                                                        fprintf(req,"%s %s %s\n",y[i].id,y[i].name,email);
                                                        printf("please wait for confirmation !!...\n");
                                                        fclose(req);
                                                        break;
                                                        err=0;
                                                    }
                                                    else
                                                    {
                                                        printf("Sorry not in stock !!!\n");
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                err=1;
                                            }
                                        }
                                        if(err==1)
                                        {
                                            printf("Invalid books or writter name!\n");
                                        }
                                    printf("Press any key ");
                                    getch();
                                    system("cls");
                                    goto o;
                                }
                                else if(press==4)
                                {
                                    system("cls");
                                    printf("Thank you for using :) \n");
                                    printf("press any key ");
                                    getch();
                                    system("cls");
                                    goto man;
                                }
                            }
                }
                else
                {
                    system("cls");
                    system("color 1F");
                    printf("\n\tWrong Username or password... Try Again\n");
                    printf("Press any key.. ");
                    getch();
                    system("cls");
                    goto l3;
                }
        }
        else
        {
            system("cls");
            printf("\n\tWrong keyword!!\n");
            printf("press any key...");
            getch();
            system("cls");
            goto l2;
        }
    }
    else if(p==3)
    {
        system("cls");
        getchar();
        char lib[1000],pass[100];
        r:printf("\n\n\n\n\t\t\tUsername :\t");
        gets(lib);
        printf("\t\t\tPassword :\t");
        //gets(pass);
        int pointer=0;
        char ch;
        while(1)
        {
            ch=getch();
            if(ch==13)//For Enter key
            {
                break;
            }
            else if(ch==8)//For Backspace key
            {
                if(pointer>0)
                {
                    pointer--;
                    pass[pointer]='\0';
                    printf("\b \b"); /* first \b is scapping and removing *
                                        <SPACE> is for blank in lieu of * blinding the console
                                         second \b is scapping the space */
                }
            }
            else if(ch==32 || ch==9)
            {
                continue;
            }
            else
            {
                pass[pointer]=ch;
                pointer++;
                printf("*");
            }
        }
        pass[pointer]='\0';
        if(strcmp(lib,"uap-lib")==0&&(strcmp(pass,"00055")==0))
        {
            system("cls");
            system("color 1F");
            w:library();
            int press;
            while(1)
            {
                scanf("%d",&press);
                if(press==1)
                {
                    lib1();
                    system("cls");
                    goto w;
                }
                if(press==2)
                {
                    lib2();
                    goto w;
                }
                if(press==3)
                {
                    lib3();
                    goto w;
                }
                if(press==4)
                {
                    lib4();
                    goto w;
                }
                if(press==5)
                {
                    system("cls");
                    printf("\n\n\n\t\tAre You Sure ?\n\t\tY\tN\n");
                    getchar();
                    char t[10];
                    gets(t);
                    if((strcmp(t,"Y")==0)||(strcmp(t,"y")==0))
                    {
                        system("cls");
                        goto man;
                    }
                    else if((strcmp(t,"N")==0)||(strcmp(t,"n")==0))
                    {
                        system("cls");
                        goto w;
                    }
                    else
                    {
                        printf("wrong keyword!\nPress anykey ");
                        getch();
                        goto w;
                    }
                }
            }
        }
        else
        {
            printf("\n\n\tInvalid username or password...!\n");
            printf("\n\tPress any key ");
            getch();
            goto r;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
int qu(int x);
int  guan(int m);
int xue(char id[],char nian[]);
int laoshi(char name[]);
int liulan(int x);
int createstulist(int x);
int stulistlesert(int x);
int stulistdelete(int x);
int buzhi(char name[]);
int zuoti(char id[],char niann[]);
int paiming(int x);
int tii(int x);
int tiliang(char nian[]);
int fenlei(int j);
void pp(char nian[]);


struct stu{

    char ti[10];
    int jie;
};
struct p{
  char id1[10];
  char name1[10];
  char mi1[10];
  char nian1[10];
  int sum1;
};
struct guan {
  char name[10];
  char mi[10];

};
int main()
{
     int x=1,m;
          m=qu(x);
      if(m==1)
        {
            system("cls");
          guan(m);                                               /*管理员系统*/
        }
      /*if(m==3)                                                   /*学生系统*/
      /*{
          system("cls");
          xue(m);
      }*/
      /*if(m==2)
      {
          system("cls");
          laoshi(m);
      }*/
    return 0;
}

int qu(int x)                                                     /*登录系统*/
{
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10];
    int sum,n,i,flag=0,t=0,ci=0;
    int a1;
    printf("============================\n");
    printf("欢迎登陆,请选择:\n");
    printf("1:管理员\n2:教师\n3:学生\n4:创建\n5.退出\n");
    printf("=============================\n");
    scanf("%d",&n);

    if(n==1||n==2)
     {
        FILE *fp;
        if(n==1)
        fp=fopen("D:\\xiao\\f.txt","r");
        if(n==2)
        fp=fopen("D:\\xiao\\f0.txt","r");

        printf("请输入用户名:");
        scanf("%s",name);

        while(1)
         {
          fscanf(fp,"%s%s",name1,mi1);
          if(feof(fp)) break;

           if(strcmp(name,name1)==0)
           {
               flag=1;
               break;
           }
         }
            fclose(fp);
         if(flag==0)
           {
            printf("无此用户名");
            return t;
           }

          if(flag==1)
          {

              printf("请输入密码:");
              while(ci<=3)
              {
                  if(n==1)
              fp=fopen("D:\\xiao\\f.txt","r");                       /*f....f1*/
              if(n==2)
              fp=fopen("D:\\xiao\\f0.txt","r");

                    for(i=0;i<10;i++)
                 {
                 mi[i]=getch();
                 if(mi[i]=='\r') break;
                 printf("*");
                }
                mi[i]='\0';
                 //printf("%s",mi);
                   while(1)
                {
                    if(n==1)
                      fscanf(fp,"%s%s",name1,mi1);
                    if(n==2)
                       fscanf(fp,"%s%s%s%d",name1,mi1,nian,&a1);
                    if(feof(fp)) break;

                    if(strcmp(mi,mi1)==0&&strcmp(name,name1)==0)
                     {
                        flag=2;
                        if(n==1) t=1;                   /*管理员*/
                        if(n==2) laoshi(name);                       /*教师*/
                        break;
                     }
                }
                   printf("\n");
                  if(flag==1&&ci<3)
                  {
                      printf("密码错误，请重新输入:");
                      fclose(fp);
                  }
                  ci++;
                  if(flag==2) break;
              }
              fclose(fp);
             if(flag==1)
             {
                  t=8;
            printf("密码错误过多，退出系统");
            return t;
             }
          if(t==2||t==1)
           {return t;}

          }
     }

     if(n==3)
     {
         FILE *fp1;


         while(ci<=3)
         {
               fp1=fopen("D:\\xiao\\d.txt","r");
             printf("请输入学号:");
             scanf("%s",id);
             printf("请输入密码:");
              for(i=0;i<10;i++)
                 {
                 mi[i]=getch();
                 if(mi[i]=='\r') break;
                 printf("*");
                }
                mi[i]='\0';
                // printf("%s",mi);

             while(!feof(fp1))
                {
                 fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian,&sum);
                //if(feof(fp1)) break;
                //printf("%s%s%s%s%d\n",id1,name1,mi1,nian,sum);
                if(strcmp(id,id1)==0&&strcmp(mi,mi1)==0)
                {
                   flag=1; t=3;                                      /*学生*/
                   break;
                }
             }

             if(flag==0&&ci<=3)
                {
                      printf("\n账号或密码错误，请重新输入:\n");
                            fclose(fp1);
                }
                  ci++;
                if(flag==1) break;
         }
         fclose(fp1);
             if(flag==0)
            printf("错误过多，退出系统");
        else{
            xue(id,nian);
        }

     }
     if(n==4)
     {

         char mi2[10];
         int tt=0,f=0,y;
         FILE *fp,*fp1;
         fp=fopen("D:\\xiao\\d.txt","a");
         fprintf(fp,"\n");

         printf("请输入学号:");
         scanf("%s",id);
         printf("请输入姓名:");
         scanf("%s",name);
          printf("-------------------------------------------------------------------------\n");
          printf("1.一年级\t2.二年级\t3.三年级\t4.四年级\t5.五年级\n");
           printf("-------------------------------------------------------------------------\n");
          printf("请选择年级:");
         scanf("%d",&y);

        if(y==1) strcpy(nian,"一年级");
        if(y==2) strcpy(nian,"二年级");
        if(y==3) strcpy(nian,"三年级");
        if(y==4) strcpy(nian,"四年级");
        if(y==5) strcpy(nian,"五年级");


         while(1)
         {
              printf("请输入密码:");
             for(i=0;i<10;i++)
                 {
                 mi[i]=getch();
                 if(mi[i]=='\r') break;
                 printf("*");
                }
                mi[i]='\0';
                //printf("%s",mi);
              printf("\n请再次输入密码:");
             for(i=0;i<10;i++)
                 {
                 mi1[i]=getch();
                 if(mi1[i]=='\r') break;
                 printf("*");
                }
                mi1[i]='\0';
                // printf("%s",mi1);
              if(strcmp(mi,mi1)==0)
              {

                  fprintf(fp,"%s\t%s\t%s\t%s\t%d",id,name,mi,nian,tt);
                    fclose(fp);
                  if(strcmp(nian,"一年级")==0)
                         {

                             fp1=fopen("D:\\xiao\\d1.txt","a");
                             fprintf(fp1,"\n");
                         fprintf(fp1,"%s\t%s\t%s\t%s\t%d",id,name,mi,nian,tt);}
                   if(strcmp(nian,"二年级")==0)
                          {

                              fp1=fopen("D:\\xiao\\d2.txt","a");
                                 fprintf(fp1,"\n");
                          fprintf(fp1,"%s\t%s\t%s\t%s\t%d",id,name,mi,nian,tt);}
                    if(strcmp(nian,"三年级")==0)
                           {
                                   fp1=fopen("D:\\xiao\\d3.txt","a");
                                   fprintf(fp1,"\n");
                           fprintf(fp1,"%s\t%s\t%s\t%s\t%d",id,name,mi,nian,tt);}
                     if(strcmp(nian,"四年级")==0)
                            {
                                  fp1=fopen("D:\\xiao\\d4.txt","a");
                                           fprintf(fp1,"\n");
                            fprintf(fp1,"%s\t%s\t%s\t%s\t%d",id,name,mi,nian,tt);}
                    if(strcmp(nian,"五年级")==0)
                             {
                                   fp1=fopen("D:\\xiao\\d5.txt","a");
                                    fprintf(fp1,"\n");
                             fprintf(fp1,"%s\t%s\t%s\t%s\t%d",id,name,mi,nian,tt);}
                  printf("创建成功\n");
                  fclose(fp1);
                  f=1;
                   break;
              }
              else printf("\n密码不一致\n");
         }
        if(f==1)
        {system("cls");
         qu(x);
        }
     }
     if(n==5)
     exit(0);
}

int guan(int m)                                                /*管理员系统*/
 {
      int select,x,t;
      printf("欢迎您,管理员\n");
      while(1)
     {
        printf("===========================\n");
        printf("1:查询用户账号\n");
        printf("2:删除用户账号\n");
        printf("3:重置用户密码\n");
        printf("4:生成题库\n5.返回登录\n");
        printf("0:退出系统\n");
        printf("===========================\n");
        printf("请选择菜单项：\n");
        scanf("%d",&select);
         x=select;
         switch(select){
            case 1: {
                    system("cls");
                    createstulist(x);
                    return guan(m);
                    }
            case 2:
                {
                    system("cls");
                    stulistlesert(x);
                    break;
                }
            case 3:{
                    system("cls");
                     stulistdelete( x);
                    break;
                   }
             case 4:{
                      system("cls");
                      //printf("生成成功\n");
                      tii(x);
                      printf("生成成功\n");
                      break;
                    }
             case 5: {
                       system("cls");
                       return qu(x);
                     }
             case 0: exit(0);
                    break;
              }
      }
 }
int laoshi(char name[])                                                            /*老师系统*/
{
       system("cls");
       int select,x,t;
        while(1)
         {
             printf("===========================\n");
              printf("1:浏览学生信息\n");
              printf("2:删除学生信息\n");
              printf("3:布置作业\n4.返回登录\n");
             printf("0:退出系统\n");
               printf("===========================\n");
              printf("请选择菜单项：\n");
              scanf("%d",&select);
              x=select;
             switch(select){
                    case 1: {system("cls");
                              liulan(x);
                                break;}
                    case 2:{system("cls");
                            stulistlesert(x);
                             break;}
                    case 3:
                           {system("cls");
                           buzhi(name);
                           break;}
                    case 4: {
                            system("cls");
                              return qu(x);
                     case 0: exit(0);
                              break;
                              }
                         }
         }
}
int xue(char id[],char nian[])
{
    system("cls");
              int select,x,t;
      printf("欢迎您\n");
      while(1)
     {
        printf("===========================\n");
        printf("1:重置密码\n");
        printf("2:做题\n");
        printf("3:排行榜\n4.返回登录\n");
        printf("0:退出系统\n");
        printf("===========================\n");
        printf("请选择菜单项：\n");
        scanf("%d",&select);
        x=select;
         switch(select){
            case 1:{
                     system("cls");
                     stulistdelete(x);
                     break;
                   }
             case 2: {system("cls");
                    zuoti(id,nian);
                    fenlei(x);
                    break;
                    }
            case 3:
                 {system("cls");
                  paiming(x);
                    break;}
            case 4: {
                       system("cls");
                       return qu(x);
                     }
             case 0: exit(0);
                    break;
              }
     }
}

int liulan(int x)                                                      /*浏览学生信息*/
 {
     int n,sum,sum1,t=0,ming,flag=0;
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10];
    FILE *fp,*fp1;

     printf("---------------------------\n");
     printf("1.查询某年级学生\n2.查询个人<按学号查询>\n3.查询个人<按姓名查询>\n4.返回\n");
     printf("----------------------------\n");
     printf("请选择:");
     scanf("%d",&n);

     if(n==1)
     {
         printf("请输入年级:");
         scanf("%s",nian);

          if(strcmp(nian,"一年级")==0)                                                    /*不同年级加减法*/
                   fp=fopen("D:\\xiao\\d1.txt","r");
           if(strcmp(nian,"二年级")==0)
                   fp=fopen("D:\\xiao\\d2.txt","r");
           if(strcmp(nian,"三年级")==0)
                   fp=fopen("D:\\xiao\\d3.txt","r");
           if(strcmp(nian,"四年级")==0)
                    fp=fopen("D:\\xiao\\d4.txt","r");
           if(strcmp(nian,"五年级")==0)
                  fp=fopen("D:\\xiao\\d5.txt","r");
                 while(1)
          {
              fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp)) break;
              printf("%s\t%s\t%d\n",id1,name1,sum1);
          }
           fclose(fp);
          return liulan(x);

     }
     if(n==2)
     {
         printf("请输入要查询学生的学号:");
         scanf("%s",id);
         fp1=fopen("D:\\xiao\\d.txt","r");

          while(1)
          {
              fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp1)) break;
              if(strcmp(id,id1)==0)
              {
                  flag=1;
                   printf("%s\t%s\t%d\n",id1,name1,sum1);
              }

          }
          if(flag==0)
            printf("无含有此学号的学生\n");
            printf("\n");
            fclose(fp1);
            return liulan(x);
     }
     if(n==3)
        {
         printf("请输入要查询学生的姓名:");
         scanf("%s",name);
         fp1=fopen("D:\\xiao\\d.txt","r");

          while(1)
          {
              fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp1)) break;
              if(strcmp(name,name1)==0)
              {
                  flag=1;
                   printf("%s\t%s\t%d\n",id1,name1,sum1);
              }

          }
          if(flag==0)
            printf("无含有此姓名的学生\n");
            printf("\n");
            fclose(fp1);
            return liulan(x);
     }
     if(n==4)
     {
         system("cls");
         return laoshi(n);
     }
 }



int buzhi(char name[])                                                    /*布置作业*/
{
    int i,n,sum,j;
    char name1[10],mi1[10],nian[10];
     FILE *fp,*fp1;
     fp=fopen("D:\\xiao\\f0.txt","r");
     fp1=fopen("D:\\xiao\\f00.txt","w");
     fclose(fp1);
     fp1=fopen("D:\\xiao\\f00.txt","a");


      while(1)
     {
          fscanf(fp,"%s%s%s%d",name1,mi1,nian,&sum);
              if(feof(fp)) break;
         if(strcmp(name,name1)==0)
         {
             printf("您是%s老师,",nian);
               printf("请选择出题量:");
               scanf("%d",&i);
                 sum=i;
         }
         fprintf(fp1,"%s\t%s\t%s\t%d\n",name1,mi1,nian,sum);
     }
     fclose(fp);
     fclose(fp1);

      fp=fopen("D:\\xiao\\f0.txt","w");
         fclose(fp);
      fp=fopen("D:\\xiao\\f0.txt","a");
      fp1=fopen("D:\\xiao\\f00.txt","r");
       while(1)
     {
          fscanf(fp1,"%s%s%s%d",name1,mi1,nian,&sum);
              if(feof(fp1)) break;
         fprintf(fp,"%s\t%s\t%s\t%d\n",name1,mi1,nian,sum);
     }
     fclose(fp);
     fclose(fp1);
     tiliang(nian);
     printf("生成成功\n");
}
int tiliang(char nian[])                                                                 /*出题数量*/
{
    int sum;
    char name1[10],mi1[10],nian1[10];
    FILE *fp,*fp1;
    fp=fopen("D:\\xiao\\f0.txt","r");
     while(1)
     {
          fscanf(fp,"%s%s%s%d",name1,mi1,nian1,&sum);
              if(feof(fp)) break;
              if(strcmp(nian,nian1)==0)
              {
                  if(strcmp(nian1,"一年级")==0)
                         return sum;
                  if(strcmp(nian1,"二年级")==0)
                         return sum;
                  if(strcmp(nian1,"三年级")==0)
                         return sum;
                   if(strcmp(nian1,"四年级")==0)
                         return sum;
                   if(strcmp(nian1,"五年级")==0)
                         return sum;
              }

     }
    fclose(fp);
}

 int createstulist(int x)
{
    int n,sum,sum1,t=0;
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10];

    system("cls");
    FILE *fp,*fp1;

    while(1)
    {
        printf("\n");
        printf("-------------\n");
        printf("1.按学号查询\n");
        printf("2.按名字查询\n");
        printf("3.按年级查询\n");
        printf("4.返回\n");
        printf("-------------\n");
        printf("请选择:");
        scanf("%d",&n);
        if(n==1)                                                     /*按学号查*/
        {
            int flag=0;
            printf("请输入学号\n");
            scanf("%s",id);
            fp=fopen("D:\\xiao\\d.txt","r");
            while(1)
            {
                fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
                if(feof(fp)) break;
                if(strcmp(id,id1)==0)
                {
                    printf("%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                    flag=1;
                }
            }
            if(flag==0)
                printf("无此用户\n");
            fclose(fp);
        }
        if(n==2)                                                     /*按名字查*/
        {
            int flag=0;
            printf("请输入名字:");
            scanf("%s",name);
            fp=fopen("D:\\xiao\\d.txt","r");
            while(1)
            {
                fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
                if(feof(fp)) break;
                if(strcmp(name,name1)==0)
                {
                    printf("%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                    flag=1;
                }
            }
            if(flag==0)
                printf("无此用户\n");
            fclose(fp);
        }
        if(n==3)                                                     /*按年级查*/
        {
            printf("请输入年级:");
            scanf("%s",nian);

            if(strcmp(nian,"一年级")==0)
           fp1=fopen("D:\\xiao\\d1.txt","r");
         if(strcmp(nian,"二年级")==0)
            fp1=fopen("D:\\xiao\\d2.txt","r");
        if(strcmp(nian,"三年级")==0)
             fp1=fopen("D:\\xiao\\d3.txt","r");
        if(strcmp(nian,"四年级")==0)
           fp1=fopen("D:\\xiao\\d4.txt","r");
       if(strcmp(nian,"五年级")==0)
          fp1=fopen("D:\\xiao\\d5.txt","r");

            while(1)
            {
                fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
                if(feof(fp1)) break;
                printf("%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
            }
            fclose(fp1);
        }
        if(n==4)   return t;
    }
}

int stulistlesert(int x)                     /*删除用户*/
{
    int n,sum,sum1,t=0,j=0;
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10];

    printf("请输入要删除的用户的账户:");
    scanf("%s",id);
    FILE *fp,*fp1;
    fp=fopen("D:\\xiao\\d.txt","r");
    fp1=fopen("D:\\xiao\\d11.txt","w");
    fclose(fp1);
    fp1=fopen("D:\\xiao\\d11.txt","a");
      while(1)
        {
             fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp)) break;

              if(strcmp(id,id1)==0)
                {
                    continue;
                }
                else fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
        }

        fclose(fp);
        fclose(fp1);
    fp1=fopen("D:\\xiao\\d11.txt","r");
    fp=fopen("D:\\xiao\\d.txt","w");
    fclose(fp);
    fp=fopen("D:\\xiao\\d.txt","a");
     while(1)
        {
             fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp1)) break;
                fprintf(fp,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);

        }

        fclose(fp);
        fclose(fp1);
        fenlei(j);                                                    /*去不同年级*/
        //system("cls");
        printf("已删除\n");
}

int stulistdelete(int x)                                       /*重置密码·*/
{
     int n,sum,sum1,t=0,i;
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10],xin[10];

    printf("请输入要重置密码用户的账户:");
    scanf("%s",id);

    FILE *fp,*fp1;
     fp=fopen("D:\\xiao\\d.txt","r");
     fp1=fopen("D:\\xiao\\d11.txt","w");
     while(1)
     {
          fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp)) break;
              if(strcmp(id,id1)==0)
              {
                  printf("请输入新密码:");
                 for(i=0;i<10;i++)
                 {
                 xin[i]=getch();
                 if(xin[i]=='\r') break;
                 printf("*");
                }
                xin[i]='\0';
                  strcpy(mi1,xin);
              }
         fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
     }
     fclose(fp);
     fclose(fp1);
     fp=fopen("D:\\xiao\\d.txt","w");
     fp1=fopen("D:\\xiao\\d11.txt","r");
      while(1)
     {
          fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp1)) break;
         fprintf(fp,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
     }
      fclose(fp);
     fclose(fp1);
     system("cls");
     printf("修改成功\n");
}


int tii(int x)                                         /*生成题库*/
{
     system("cls");
     int n,sum,t=0,j,j1,m,y,i=0,jieguo;
     int a[6666],b[6666],c[6666],d[6666],e[6666],c3[6666],c2[6666],c1[6666];
     char d1[2],d2[2],d3[2],d4[2];

     strcpy(d1,"+");   strcpy(d2,"-");
     strcpy(d3,"*");   strcpy(d4,"/");

     printf("-------------------------------------------------------------------\n");
     printf("1.一年级上\t2.一年级下\t3.二年级上\t4.二年级下\t5.三年级上\n");
     printf("6.三年级下\t7.四年级上\t8.四年级下\t9.五年级上\t10.五年级下\n");
     printf("-------------------------------------------------------------------\n");

     printf("请选择年级:");
     scanf("%d",&n);
    FILE *fp;
    if(n==1)                                                    /*不同年级加减法*/
    {
        fp=fopen("D:\\xiao\\f1.txt","w");
        j=j1=6;m=5;
    }
     if(n==2)
    {
        fp=fopen("D:\\xiao\\f2.txt","w");
        j=j1=11;m=20;
    }
     if(n==3)
    {
        fp=fopen("D:\\xiao\\f3.txt","w");
        j=j1=21;m=40;
    }
     if(n==4)
    {
        fp=fopen("D:\\xiao\\f4.txt","w");
        j=j1=101;m=200;
    }
    if(n==5)
    {
        fp=fopen("D:\\xiao\\f5.txt","w");
        j=j1=10;
    }
     if(n==6)
    {
        fp=fopen("D:\\xiao\\f6.txt","w");
        j=j1=10;
    }
     if(n==7)
    {
        fp=fopen("D:\\xiao\\f7.txt","w");
        j=10,j1=101;
    }
    if(n==8)
    {
        fp=fopen("D:\\xiao\\f8.txt","w");
        j=101,j1=10;
    }
     if(n==9)
    {
        fp=fopen("D:\\xiao\\f9.txt","w");
        j=100,j1=100;
    }
     if(n==10)
    {
        fp=fopen("D:\\xiao\\f10.txt","w");
        j=100,j1=100;
    }

      printf("请输入要生成几道题:");
      scanf("%d",&y);

     srand(time(NULL));
     while(t<y)
	 {
		a[i]=rand()%j;
		//printf("%d\t",a[i]);
		b[i]=rand()%j1;
		//printf("%d\t",b[i]);
		c[i]=rand()%2;
       //printf("%d\t",c[i]);
        if(n>8)
        {
            e[i]=rand()%j;
            c2[i]=rand()%4;
            c1[i]=rand()%2;
            c3[i]=rand()%4;
        }

        if(n>=5)
        d[i]=rand()%2;
        if(n==5||n==7)  d[i]=1;
        if(n==6||n==8)  d[i]=0;

          if(n<5)
       {
           if(c[i]==1)                                                      /*加法*/
         {
             jieguo=a[i]+b[i];
             if(jieguo<=m)
		   {
		    fprintf(fp,"%d%s%d= %d\t",a[i],d1,b[i],jieguo);
		    t++;
		    if(t>=7&&t%7==0)
            {
                fprintf(fp,"\n");
            }
		   }
         }

         if(c[i]==0)                                                      /*减法*/
        {
             jieguo=a[i]-b[i];
             if(jieguo>0)
		    {
		     fprintf(fp,"%d%s%d= %d\t",a[i],d2,b[i],jieguo);
		     t++;
		    }
		     if(t>=7&&t%7==0)
            {
                fprintf(fp,"\n");
            }
         }

        }
        if(n>4&&n<9)
      {

         if(d[i]==1)
         {
             jieguo=a[i]*b[i];
             if(n!=7)
                fprintf(fp,"%d%s%d= %d\n",a[i],d3,b[i],jieguo);
             if(n==7&&b[i]>9)
                fprintf(fp,"%d%s%d= %d\n",a[i],d3,b[i],jieguo);

             t++;
         }

         if(d[i]==0&&b[i]!=0)
         {
             jieguo=a[i]/b[i];
             if(a[i]>b[i]&&a[i]%b[i]==0)
             {
                 if(n!=8)
                    fprintf(fp,"%d%s%d= %d\n",a[i],d4,b[i],jieguo);
                 if(n==8&&a[i]>=10)
                    fprintf(fp,"%d%s%d= %d\n",a[i],d4,b[i],jieguo);
             }


             t++;
         }
       }

       if(n==9)                                             /*混合*/
       {
           if(c[i]==1&&c1[i]==1)
            {
                jieguo=a[i]+b[i]+e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d1,b[i],d1,e[i],jieguo);
            }
            if(c[i]==1&&c1[i]==0)
            {
                jieguo=a[i]+b[i]-e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d1,b[i],d2,e[i],jieguo);
            }
            if(c[i]==1&&c1[i]==1)
            {
                jieguo=a[i]-b[i]+e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d2,b[i],d1,e[i],jieguo);
            }
            if(c[i]==1&&c1[i]==1)
            {
                jieguo=a[i]-b[i]-e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d2,b[i],d2,e[i],jieguo);
            }
            t++;
       }


       if(n==10)
       {
           if(c2[i]==1&&c3[i]==1)
           {
                jieguo=a[i]+b[i]+e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d1,b[i],d1,e[i],jieguo);
           }
           if(c2[i]==1&&c3[i]==0)
           {
                jieguo=a[i]+b[i]-e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d1,b[i],d2,e[i],jieguo);
           }
           if(c2[i]==0&&c3[i]==0)
           {
                jieguo=a[i]-b[i]-e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d2,b[i],d2,e[i],jieguo);
           }
           if(c2[i]==0&&c3[i]==1)
           {
                jieguo=a[i]-b[i]+e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d2,b[i],d1,e[i],jieguo);
           }
           if(c2[i]==0&&c3[i]==2)
           {
                jieguo=a[i]-b[i]*e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d2,b[i],d3,e[i],jieguo);
           }
           if(c2[i]==0&&c3[i]==3&&e[i]!=0)
           {
               if(b[i]%e[i]==0)
                {
                    jieguo=a[i]-b[i]/e[i];
                    fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d2,b[i],d4,e[i],jieguo);
                }
           }
           if(c2[i]==1&&c3[i]==2)
           {
                jieguo=a[i]+b[i]*e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d1,b[i],d3,e[i],jieguo);
           }
           if(c2[i]==1&&c3[i]==3&&e[i]!=0)
           {
               if(b[i]%e[i]==0)
                {
                    jieguo=a[i]+b[i]/e[i];
                    fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d1,b[i],d4,e[i],jieguo);
                }
           }
           if(c2[i]==2&&c3[i]==0)
           {
                jieguo=a[i]*b[i]-e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d3,b[i],d2,e[i],jieguo);
           }
           if(c2[i]==2&&c3[i]==1)
           {
                jieguo=a[i]*b[i]+e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d3,b[i],d1,e[i],jieguo);
           }
           if(c2[i]==2&&c3[i]==2)
           {
                jieguo=a[i]*b[i]*e[i];
                fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d3,b[i],d3,e[i],jieguo);
           }
           if(c2[i]==2&&c3[i]==3&&e[i]!=0)
           {
               if(a[i]*b[i]%e[i]==0)
               {
                    jieguo=a[i]*b[i]/e[i];
                    fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d3,b[i],d2,e[i],jieguo);
               }
           }
           if(c2[i]==3&&c3[i]==0&&b[i]!=0)
           {

                   if(a[i]%b[i]==0)
                    {
                      jieguo=a[i]/b[i]-e[i];
                      fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d4,b[i],d2,e[i],jieguo);
                    }
           }
           if(c2[i]==3&&c3[i]==1&&b[i]!=0)
           {
                if(a[i]%b[i]==0)
                 {
                     jieguo=a[i]/b[i]+e[i];
                     fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d4,b[i],d1,e[i],jieguo);
                 }
           }

           if(c2[i]==3&&c3[i]==2&&b[i]!=0)
           {
               if(a[i]%b[i]==0)
               {
                   jieguo=a[i]/b[i]*e[i];
                   fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d4,b[i],d3,e[i],jieguo);
               }

           }
           if(c2[i]==3&&c3[i]==3&&b[i]!=0&&e[i]!=0)
           {
               if(a[i]%b[i]==0&&a[i]%b[i]%e[i]==0)
               {
                    jieguo=a[i]/b[i]/e[i];
                    fprintf(fp,"%d%s%d%s%d= %d\n",a[i],d4,b[i],d4,e[i],jieguo);
               }

           }
              t++;
       }
         i++;
	  }
	  fclose(fp);
}


int zuoti(char ii[],char niann[])                                        /*做题*/                                                                                        /*做题*/
{
     int n,sum,t=0,i=0,j,ci=0,k,da,sum1,s=0,t1=0;
     int a,b;
    char ti[10];
    char ti1[10],name1[10],mi1[10],nian1[10],id1[10];
    char id[10],name[10],mi[10],nian[10];
    struct stu w[666];

     printf("-------------------------------------------------------------------------\n");
     printf("1.一年级上\t2.一年级下\t3.二年级上\t4.二年级下\t5.三年级上\n");
     printf("6.三年级下\t7.四年级上\t8.四年级下\t9.五年级上\t10.五年级下\n");
     printf("-------------------------------------------------------------------------\n");
     printf("请选择年级:");
     scanf("%d",&n);

     if(n==1||n==2)
     {
         if(strcmp(niann,"一年级")==0)
          t1=1;
     }
       if(n==3||n==4)
     {
         if(strcmp(niann,"二年级")==0)
          t1=1;
     }
       if(n==5||n==6)
     {
         if(strcmp(niann,"三年级")==0)
          t1=1;
     }
       if(n==7||n==8)
     {
         if(strcmp(niann,"四年级")==0)
          t1=1;
     }
       if(n==9||n==10)
     {
         if(strcmp(niann,"五年级")==0)
          t1=1;
     }
     if(t1==0)
     {
         printf("你是%学生,现在做的不是本年级题目，不计入成绩\n",niann);
         t1=1;
     }
    FILE *fp,*fp1,*fp2;
     if(n==1)                                                    /*不同年级加减法*/
       fp=fopen("D:\\xiao\\f1.txt","r");
     if(n==2)
        fp=fopen("D:\\xiao\\f2.txt","r");
     if(n==3)
        fp=fopen("D:\\xiao\\f3.txt","r");
     if(n==4)
        fp=fopen("D:\\xiao\\f4.txt","r");
    if(n==5)
        fp=fopen("D:\\xiao\\f5.txt","r");
     if(n==6)
        fp=fopen("D:\\xiao\\f6.txt","r");
     if(n==7)
        fp=fopen("D:\\xiao\\f7.txt","r");
    if(n==8)
        fp=fopen("D:\\xiao\\f8.txt","r");
     if(n==9)
        fp=fopen("D:\\xiao\\f9.txt","r");
     if(n==10)
        fp=fopen("D:\\xiao\\f10.txt","r");
        while(1)
        {
             fscanf(fp,"%s%d",w[i].ti,&w[i].jie);
              if(feof(fp)) break;
              //printf("%s\t",w[i].ti);
              i++;
        }
        fclose(fp);
      if(n==1||n==2)  strcpy(niann,"一年级");
      if(n==3||n==4)  strcpy(niann,"二年级");
      if(n==5||n==6)  strcpy(niann,"三年级");
      if(n==7||n==9)  strcpy(niann,"四年级");
      if(n==9||n==10)  strcpy(niann,"五年级");

       j=tiliang(niann);
          /*for(i=0;i<10;i++)
            printf("%s%d\t",w[i].ti,w[i].jie);*/
            printf("老师布置了%d题，认真做哦=.=\n",j);
        srand(time(NULL));

        while(ci<j)
        {
            a=rand()%50;
            //printf("%d",a[i]);
            for(k=0;k<50;k++)
            {
                if(k==a)
                {
                    printf("%s",w[k].ti);
                    scanf("%d",&da);
                    if(da==w[k].jie)
                    {
                        printf("正确\n");
                        s++;
                    }
                    else printf("错误\n");
                        ci++;
                    break;
                }
            }

        }
        fclose(fp);

        printf("题已做完,");
        printf("您做对%d题\n",s);
        if(t1==0)
        {

        fp1=fopen("D:\\xiao\\d.txt","r");
        fp2=fopen("D:\\xiao\\d111.txt","w");
        while(1)
        {
             fscanf(fp1,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
             if(feof(fp1)) break;
             //printf("%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
             if(strcmp(ii,id1)==0)
                     sum1=s;
             fprintf(fp2,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
             //printf("%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
        }
        fclose(fp1);
        fclose(fp2);

     fp1=fopen("D:\\xiao\\d.txt","w");
     fp2=fopen("D:\\xiao\\d111.txt","r");
      while(1)
     {
          fscanf(fp2,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp2)) break;
          fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
     }
      fclose(fp1);
      fclose(fp2);

        }

}

int paiming(int x)                                                                /*排名*/
{

     int n,sum,sum1,t=0,ming,flag=0,y;
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10];


      printf("---------------------------\n");
      printf("1.各个年级\n2.个人\n3.返回\n");
      printf("---------------------------\n");
      printf("请选择:");
      scanf("%d",&n);
      FILE *fp;

           if(n!=3)
           {
                printf("-------------------------------------------------------------------------\n");
                printf("1.一年级\t2.二年级\t3.三年级\t4.四年级\t5.五年级\n");
                printf("-------------------------------------------------------------------------\n");
                printf("请选择年级:");
                scanf("%d",&y);
               if(y==1)  strcpy(nian,"一年级");
               if(y==2)  strcpy(nian,"二年级");
                if(y==3)  strcpy(nian,"三年级");
                if(y==4)  strcpy(nian,"四年级");
                if(y==5)  strcpy(nian,"五年级");
                pp(nian);

           }

          if(strcmp(nian,"一年级")==0)                                                    /*不同年级加减法*/
                   fp=fopen("D:\\xiao\\d1.txt","r");
           if(strcmp(nian,"二年级")==0)
                   fp=fopen("D:\\xiao\\d2.txt","r");
           if(strcmp(nian,"三年级")==0)
                   fp=fopen("D:\\xiao\\d3.txt","r");
           if(strcmp(nian,"四年级")==0)
                    fp=fopen("D:\\xiao\\d4.txt","r");
           if(strcmp(nian,"五年级")==0)
                  fp=fopen("D:\\xiao\\d5.txt","r");
        if(n==1)
        {
                 while(1)
          {
              fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp)) break;
            printf("%s\t%s\t%d\n",id1,name1,sum1);
          }
          fclose(fp);
          return paiming(x);
       }

     if(n==2)                                                                /*个人*/
      {
          ming=0;
          printf("请输入想要查询学生的学号:");
          scanf("%s",id);
          while(1)
          {
              fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1);
              if(feof(fp)) break;
              ming++;
               if(strcmp(id,id1)==0)
               {
                   printf("%s\t%s\t%d\t",id1,name1,sum1);
                   printf("名次为%d\n",ming);
                   printf("\n");
                   flag=1;
                   break;
               }
          }
          if(flag==0)
            printf("无此用户\n");
          fclose(fp);
          return paiming(x);
      }
      if(n==3)
      {
          system("cls");
        return xue(x,nian);
      }

}

int fenlei(int j)                                                                    /*去不同年级*/
{

    int n,sum,sum1,t=0;
    char id[10],name[10],mi[10],nian[10];
    char id1[10],name1[10],mi1[10],nian1[10];
    FILE *fp,*fp1;
    //printf("111");
   fp=fopen("D:\\xiao\\d.txt","r");
   fp1=fopen("D:\\xiao\\d1.txt","w"); fclose(fp1);
   fp1=fopen("D:\\xiao\\d2.txt","w"); fclose(fp1);
   fp1=fopen("D:\\xiao\\d3.txt","w");fclose(fp1);
   fp1=fopen("D:\\xiao\\d4.txt","w");fclose(fp1);
   fp1=fopen("D:\\xiao\\d5.txt","w");fclose(fp1);

     while(1)
     {
         if(fscanf(fp,"%s%s%s%s%d",id1,name1,mi1,nian1,&sum1)!=EOF)
            {

             // if(feof(fp)) break;
              //printf("%s%s%s%s%d\t",id1,name1,mi1,nian1,sum1);
              if(strcmp(nian1,"一年级")==0)
              {
                     fp1=fopen("D:\\xiao\\d1.txt","a");
                     fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                     fclose(fp1);
              }

              if(strcmp(nian1,"二年级")==0)
              {
                     fp1=fopen("D:\\xiao\\d2.txt","a");
                     fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                     fclose(fp1);
              }
              if(strcmp(nian1,"三年级")==0)
              {
                     fp1=fopen("D:\\xiao\\d3.txt","a");
                     fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                     fclose(fp1);
              }

             if(strcmp(nian1,"四年级")==0)
              {
                     fp1=fopen("D:\\xiao\\d4.txt","a");
                     fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                     fclose(fp1);
              }

               if(strcmp(nian1,"五年级")==0)
              {
                     fp1=fopen("D:\\xiao\\d5.txt","a");
                     fprintf(fp1,"%s\t%s\t%s\t%s\t%d\n",id1,name1,mi1,nian1,sum1);
                     fclose(fp1);
              }
            }
            else break;

     }
     fclose(fp);

}

void pp(char nian[])
{

     struct p pai[1000];
     int n,sum,sum1,t=0,i=0,j,k,temp;

     char id1[10],name1[10],mi1[10],nian1[10];
     char id2[10],name2[10],mi2[10],nian2[10];

    FILE *fp;

           if(strcmp(nian,"一年级")==0)                                                    /*不同年级加减法*/
                   fp=fopen("D:\\xiao\\d1.txt","r");
           if(strcmp(nian,"二年级")==0)
                   fp=fopen("D:\\xiao\\d2.txt","r");
           if(strcmp(nian,"三年级")==0)
                   fp=fopen("D:\\xiao\\d3.txt","r");
           if(strcmp(nian,"四年级")==0)
                    fp=fopen("D:\\xiao\\d4.txt","r");
           if(strcmp(nian,"五年级")==0)
                  fp=fopen("D:\\xiao\\d5.txt","r");
            while(1)
          {
              fscanf(fp,"%s%s%s%s%d",pai[i].id1,pai[i].name1,pai[i].mi1,pai[i].nian1,&pai[i].sum1);
              if(feof(fp)) break;
              i++;
          }

          fclose(fp);

            /*for(j=0;j<i;j++)
                printf("%s%s%s%s%d\n",pai[j].id1,pai[j].name1,pai[j].mi1,pai[j].nian1,pai[j].sum1);*/
          if(strcmp(nian,"一年级")==0)
                 fp=fopen("D:\\xiao\\d1.txt","w");
           if(strcmp(nian,"二年级")==0)
                   fp=fopen("D:\\xiao\\d2.txt","w");
           if(strcmp(nian,"三年级")==0)
                   fp=fopen("D:\\xiao\\d3.txt","w");
           if(strcmp(nian,"四年级")==0)
                    fp=fopen("D:\\xiao\\d4.txt","w");
           if(strcmp(nian,"五年级")==0)
                  fp=fopen("D:\\xiao\\d5.txt","w");
          for(j=0;j<i-1;j++)
          {
              for(k=j+1;k<i;k++)
              {
                 // printf("%s%s%s%s%d\n",pai[k].id1,pai[k].name1,pai[k].mi1,pai[k].nian1,pai[k].sum1);
                  if(pai[j].sum1<pai[k].sum1)
                  {

                      strcpy(name2,pai[j].name1);
                      strcpy(pai[j].name1,pai[k].name1);
                      strcpy(pai[k].name1,name2);

                      strcpy(mi2,pai[k].mi1);
                      strcpy(pai[k].mi1,pai[j].mi1);
                      strcpy(pai[k].mi1,mi2);

                      strcpy(nian2,pai[k].nian1);
                      strcpy(pai[k].nian1,pai[j].nian1);
                      strcpy(pai[k].nian1,nian2);

                      temp=pai[j].sum1;
                      pai[j].sum1=pai[k].sum1;
                      pai[k].sum1=temp;
                  }
              }
          }
          for(k=0;k<i;k++)
        fprintf(fp,"%s\t%s\t%s\t%s\t%d\n",pai[k].id1,pai[k].name1,pai[k].mi1,pai[k].nian1,pai[k].sum1);
          fclose(fp);
}


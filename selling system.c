#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
///Selling System:
time_t T;
struct tm tm;
int birth_amount=0;
int bDiscount=0;

struct customerlist
{
    char name[30];
    int phoneNo;
    char shipped[20];
    int price;
    int day;
    int mon;
    int year;
} cList[1000];
struct shoplist
{
    char shopName[30];
    char shopOwner[30];
    int  discount;
    int phoneNo;
} shop[100];

FILE *passFile,*disFile,*cusFile,*cashFile,*soldFile,*clenFile,*shoplistFile,*shopinfoFile,*mallDisFile,*shopDisfromMallFile;
char rerun='y',run;
int getChoice,getPoint=0;
int i,len,discount_amount,opinio,slock,ulock,sSecretNo=523,uSecretNo,aDiscount;
int nPassOne,nPassTwo,sDisount,uDiscount,sCash,sSold,searchNo,mallDis;
int cPhone,cPrice,uCategory,uSize,uColour,sSeeCusto;
int sPrice=1500,tPrice=900,pPrice=2000,jPrice=4000;
char isOwner,isWtf,isDChange,cName[30],category[20],isBuyed,sCategory[20];

cinofList[1000];
///Mall Management System:
struct shopinfo
{
    char shopName[30],ownerName[300];
    int phoneNo;
    int discount;
} sinfoList[100];

struct doshopDis
{
    int percent;
    int phoneNo;
} doshopDisObg;

///Personal Information:
char getName[30],getShopName[100];
int  getPhnNo,getDay,getMon,getYear;

int main()
{
     T=time(NULL);
     tm=*localtime(&T);
     fileopening();



    ///start program body
    loadingbar();
    pwellcome();
    Sleep(300);
    cls();
    ///Check is Owner:

    printf("\n\n\t:::===============================================:::");
    printf("\n\t:::     *Shopping Center Management System*       :::");
    printf("\n\t:::-----------------------------------------------:::");


    while(rerun=='y')
    {
        printf("\n\t:::1.Mall Management\t2.Selling System          :::\n\t:::3.Customers System\t4.Mall Information        :::\n\t>");
        scanf("%d",&getChoice);


        if(getChoice==1)
        {
            ///Asfauqe:
            mallmanagementStyem();

        }
        else if(getChoice==2)
        {

            ///Utsa
            sellingSystem();

        }
        else if(getChoice==3)
        {
            ///Sharif:
            customerSystem();
        }
        else if(getChoice==4)
        {
            mallInformation();
        }
        else
        {
            printf("\n\t:::===============================================:::");
            printf("\n\t:::            %d has not any option              :::",getChoice);
            printf("\n\t:::===============================================:::");
        }


        printf("\n\t:::===============================================:::");
        printf("\n\t:::Do you want to Re-run(y/n):");
        scanf(" %c",&rerun);
        printf("\t:::===============================================:::\n");
    }



}



///Start of Management System///
void mallmanagementStyem()
{
    FILE *shopinfoFile;
    int choose,updtDis,shopPhone,getshopPhone,setshopDis;
    char opinion='y';


    printf("\n\tShopping Mall Management System\n\t...............................");



    while(opinion=='y')
    {
        printf("\n\tEnter Mall Password:");
        scanf("%d",&getChoice);
        cls();
        if(getChoice==01)
        {
        printf("\n\tWhat do you want?");
        printf("\n\t1.Shop List\t2.Set Shop Discount\n\t3.Mall Discount\t4.Mall Info\n\t5.Worker List");
        printf("\n\t>");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            printf("\tTotal Shop:5\n\tShop Name List:\n");
            for(i=0; i<5; i++)
            {
                printf("\n\tShop Name:%s\n",sinfoList[i].shopName);

            }
            break;
        case 2:
            printf("\tShop Owner List:\n");
            for(i=0; i<5; i++)
            {
                printf("\n\t%d.Shop Name:%s\n\tOwner Name:%s\n\tPhone:%d\n\tDiscount:%d",i+1,sinfoList[i].shopName,sinfoList[i].ownerName,sinfoList[i].phoneNo,sinfoList[i].discount);
                printf("\n");
            }

            printf("\n\tSet discount from mall %d percent",mallDis);

            printf("\n\tWhat do you want?\n\t1.Set Discount\n\t2.Close Discount\n\t>");
            scanf("%d",&choose);

            if(shopDisfromMallFile!=NULL)
            {

                printf("\n\tDiscount already set for:");
                for(i=0; i<5; i++)
                {
                    if(sinfoList[i].phoneNo==doshopDisObg.phoneNo)
                    {
                        printf("\n\tShop Name:%s\n\tOwner Name:%s",sinfoList[i].shopName,sinfoList[i].ownerName);

                        getPoint=1;
                    }

                }

                fclose(shopDisfromMallFile);

                // printf("\n\tCongress discount updated");
            }



            if(choose==1)
            {


                if(getPoint!=1)
                {


                    printf("\n\tEnter phone number for \n\tset discount for any shop:");
                    scanf("%d",&shopPhone);


                    for(i=0; i<5; i++)
                    {
                        if(sinfoList[i].phoneNo==shopPhone)
                        {
                            printf("\n\tThis shop already discount:%d",sinfoList[i].discount);
                            getPoint=1;
                        }
                    }
                    if(getPoint==0)
                    {
                        printf("\n\t%d phone no have not any shop",shopPhone);
                    }





                    printf("\n\tDo you want to confirm?(y/n)\n\t>");
                    scanf(" %c",&opinion);

                    if(opinion=='y')
                    {

                        shopDisfromMallFile=fopen("shopdiscountfrommall.txt","w");
                        if(shopDisfromMallFile!=NULL)
                        {

                            fprintf(shopDisfromMallFile,"%d %d",mallDis,shopPhone);

                            fclose(shopDisfromMallFile);

                            printf("\n\tCongress discount updated");
                        }
                        else
                        {
                            printf("\n Do shop discount mall Not Exist");
                        }

                    }

                    else
                    {
                        printf("\n\tOk Thanks!");
                    }

                }
            }
            else if(choose==2)
            {
                if(shopDisfromMallFile!=NULL)
                {

                    printf("\n\tDiscount set for:");
                    for(i=0; i<5; i++)
                    {
                        if(sinfoList[i].phoneNo==doshopDisObg.phoneNo)
                        {
                            printf("\n\tShop Name:%s\n\tOwner Name:%s",sinfoList[i].shopName,sinfoList[i].ownerName);

                            getPoint=1;
                        }

                    }
                    if(getPoint==0)
                    {
                        printf("\n\tNo have set discount for nay shop");
                    }
                    fclose(shopDisfromMallFile);

                    // printf("\n\tCongress discount updated");
                }



                if(getPoint!=0)
                {
                    printf("\n\tDo you want to confirm?(y/n)\n\t>");
                    scanf(" %c",&opinion);

                    if(opinion=='y')
                    {
                        shopDisfromMallFile=fopen("shopdiscountfrommall.txt","w");
                        if(shopDisfromMallFile!=NULL)
                        {

                            fprintf(shopDisfromMallFile,"%d %d",0,0);

                            fclose(shopDisfromMallFile);

                            printf("\n\tCongress discount Closed");
                        }
                    }
                }
                else
                {
                    printf("\n\tOk Thanks");
                }

            }
            break;
        case 3:
            while(opinion=='y')
            {
                printf("\n\tWhat do you want?\n\t1.Available Discount\n\t2.Update Discount\n\t>");
                scanf("%d",&choose);
                if(choose==1)
                {
                    printf("\tAvailable Discount:%d",mallDis);
                }
                else if(choose==2)
                {
                    printf("\n\tYou select update discount:\n");
                    printf("\n\tEnter Discount percentage:");
                    scanf("%d",&updtDis);

                    mallDisFile=fopen("malldiscount.txt","w");
                    if(mallDisFile!=NULL)
                    {


                        fprintf(mallDisFile,"%d",updtDis);

                        printf("\n\tDiscount Updated");
                        fclose(mallDisFile);


                    }
                    else
                    {
                        printf("\n Mall discount file Not Exist");
                    }
                }
                else
                {
                    printf("\n\tYou Select Wrong");
                }
                printf("\n\tDo you want to re-run(y/n):");
                scanf(" %c",&opinion);
            }
            break;

        case 4:
            printf("\tMall Information:\n");
            printf("\tMall Name:My City Mall\n\tAddress:Dhaka,Bangladesh\n\t*You can shopping from us on line and off line*");
            break;
        case 5:
            printf("\n\tWork Category List:\n");
            printf("\n\n\tShop Owners:");
            for(i=0;i<5;i++){
                printf("\n\t======================================");
                printf("\n\tName:%s                            ",sinfoList[i].ownerName);
                printf("\n\t======================================");
                printf("\n");
            }
            printf("\n\tTotal Watchman:5");
            printf("\n\tTotal Security Gard:12");

            break;
        default:
            printf("\tNot have any option");

        }

        }else{
            printf("\n\tSorry Password not Matched");
        }

        fflush (stdin);
        printf("\nAre you to re-run(y/n):");
        scanf(" %c",&opinion);
    }
}

///End of Mall Management System///

///Start of Selling System///
void sellingSystem()
{

    cls();
    while(rerun=='y')
    {

        printf("\n\tSelect Your Shop:\n");
        for(i=0; i<5; i++)
        {
            printf("\n\t%d.Shop Name:%s\n",i+1,sinfoList[i].shopName);
            printf("\n");
        }
        printf("\n\tPress->");

        scanf("%d",&getChoice);
        cls();

        if(getChoice==1)
        {
            printf("\n\t:::==========================:::");
            printf("\n\t::: Are You Shop Owner(y/n)? :::");
            printf("\n\t>");
            scanf(" %c",&isOwner);
            printf("\t:::============================:::\n");
            if(isOwner=='y')
            {
                printf("\n\t:::=================:::");
                printf("\n\t::: Enter Your Lock :::\n\t>");
                scanf("%d",&ulock);
                printf("\n\t:::=================:::\n");
                cls();
                if(slock==ulock)
                {

                    while(rerun=='y')
                    {
                        setHeaderview(1);
                        sellingymainfunction();
                    }
                }
                else
                {
                    printf("\n\t:::=================================:::");
                    printf("\n\t:::Sorry! %d is not a valid Lock     :::\n\t:::Do you want to forgot lock (y/n)?:::\n\t>",ulock);
                    getchar();
                    scanf("%c",&isWtf);
                    if(isWtf=='y')
                    {
                        printf("\nEnter Shop Secret No:");
                        scanf("%d",&uSecretNo);
                        if(sSecretNo==uSecretNo)
                        {
                            printf("\nEnter New Password:");
                            scanf("%d",&nPassOne);
                            printf("\nEnter Confirm Password:");
                            scanf("%d",&nPassTwo);

                            if(nPassOne==nPassTwo)
                            {
                                passFile=fopen("password.txt","w");
                                if(passFile!=NULL)
                                {
                                    fprintf(passFile,"%d",nPassOne);
                                    printf("\n\t:::===============================:::");
                                    printf("\n\t::: Congress Password is Updated  :::\n\t::: New Password is %d           :::",nPassOne);
                                    printf("\n\t:::===============================================:::");
                                    fclose(passFile);
                                }
                                else
                                {
                                    printf("\nFile Error.");
                                }
                            }
                            else
                            {
                                printf("\n\t:============================:");
                                printf("\n\t:Sorry Password are not match:");
                                printf("\n\t:============================:");
                            }
                        }
                        else
                        {
                            printf("\n\t:===================================:");
                            printf("\n\t:  Sorry! %d is not shop secret No  :",uSecretNo);
                            printf("\n\t:===================================:");

                        }
                    }
                    else
                    {
                        printf("\n\t:=====================:");
                        printf("\n\t:Your enter No. Thanks:");
                        printf("\n\t:=====================:");
                    }


                }




            }
            else
            {
                printf("\n\t:========================:");
                printf("\n\t: Sorry! Have a nice day :");
                printf("\n\t:========================:");
            }

            printf("\n\t:==========================:");
            printf("\n\t:Do you want to Re-run(y/n):");
            printf("\n\t:==========================:");
            printf("\n\tPress->");
            scanf(" %c",&rerun);

        }
        else if(getChoice==2)
        {
            loginandgoshop(getChoice);
        }
        else if(getChoice==3)
        {
            loginandgoshop(getChoice);
        }
        else if(getChoice==4)
        {
            loginandgoshop(getChoice);
        }
        else if(getChoice==5)
        {
            loginandgoshop(getChoice);
        }

        else
        {
            printf("\n\tOther shop is no open now\nBecause code going to critical");
        }
    }

}

void loginandgoshop(int index)
{
    index=index-1;

    for(i=0; i<5; i++)
    {
        slock=sinfoList[index].phoneNo;
    }
    printf("\n\t:========================:");
    printf("\n\t:Are You Shop Owner(y/n)?:");
    printf("\n\tPress>");
    scanf(" %c",&isOwner);
    printf("\t:========================:");
    cls();
    if(isOwner=='y')
    {
        printf("\n\t:================:");
        printf("\n\t:Enter Your Lock :\n\tPress>");
        scanf("%d",&ulock);
        printf("\t:================:");
        cls();
        if(slock==ulock)
        {

            while(rerun=='y')
            {
                setHeaderview(index+1);
                sellingymainfunction(index);
            }
        }
        else
        {
        }
        cls();
        printf("\n\t:=====================:");
        printf("\n\t:Password not matched!:");
        printf("\t:=====================:");
    }
    else
    {
        printf("\n\t:======================:");
        printf("\n\t:Sorry! Have a nice day:");
        printf("\n\t:======================:");
    }
    cls();
    printf("\n\t:==========================:");
    printf("\n\t:Do you want to Re-run(y/n):");
    printf("\t:==========================:");
    scanf(" %c",&rerun);

}


void sellingymainfunction(int index)
{
    int setdiscount=0;
    if(getPhnNo==sinfoList[index-1].phoneNo)
    {
        setdiscount=doshopDisObg.percent;
    }
    else
    {
        setdiscount=0;
    }

    printf("\n\t:======================================:\n\t:1.Customer List    2.Setup Discount   :\n\t:3.To-day Sell \t4.Customers Handle     :\n\t:5.Shop Information                    :\n\t:======================================:\n\n\tPress->");
    scanf("%d",&opinio);
    if(opinio==1)
    {
        while(rerun=='y')
        {
            printf("\n\t:::What you want?                                 :::\n\t:::1.Search Customer                              :::\n\t:::2.CustomersList                                :::\n\t:::3.Check Birthday                               :::");
            printf("\n\t   >");
            scanf("%d",&sSecretNo);
            if(sSecretNo==1)
            {   cls();
                printf("\n\t:::===============================================:::");
                printf("\n\t:::Enter customer phone no                        :::");
                printf("\n\t   >");
                scanf("%d",&searchNo);;
                printf("\n\t:::===============================================:::");


                for(i=0; i<len; i++)
                {
                    if(cList[i].phoneNo==searchNo)
                    {
                        printf("\n\t:::Customer Information                           ");
                        printf("\n\t:::Information of %d phone no customer            ",searchNo);
                        printf("\n\t:::Name:%s                                      \n\t:::Shopped:%s                                  \n\t:::Price:%d                                       \n\t:::Date:%d-%d-%d                                        ",cList[i].name,cList[i].shipped,cList[i].price,cList[i].day,cList[i].mon,cList[i].year);
                        break;

                    }
                    else
                    {
                        printf("\nSorry Not any Customer exist in %d phone no",searchNo);
                    }
                }
            }
            else if(sSecretNo==2)
            {    cls();
                printf("\n\t:::===============================================");
                printf("\n\t:::Customer List                                  ");
                printf("\n\t:::===============================================");

                for(i=0; i<len; i++)
                {
                    printf("\n\t:::Name:%s                                      :::\n\t:::Phone No:%d                                    :::\n\t:::Shipped:%s                                  :::\n\t:::Price:%d                                       :::\n\t:::Date:%d-%d-%d                                        :::",cList[i].name,cList[i].phoneNo,cList[i].shipped,cList[i].price,cList[i].day,cList[i].mon,cList[i].year);
                    printf("\n\t:::===============================================:::");
                    printf("\n");
                }
            }
            else if(sSecretNo==3)
            {

                ///Checking User Birthday:
                printf("\n\t:::Today Birthday Customers                       :::");
                for(i=0; i<len; i++)
                {
                    if(cList[i].day==tm.tm_mday && cList[i].mon==tm.tm_mon+1)
                    {

                        printf("\n\t:::Name:%s                                      :::\n\t:::Shopped:%s                                  :::\n\t:::Price:%d                                       :::\n\t:::Date:%d-%d-%d (Birthday)                                        :::",cList[i].name,cList[i].shipped,cList[i].price,cList[i].day,cList[i].mon,cList[i].year);
                        printf("\n");
                        getPoint=1;

                    }
                }
                if(getPoint==0)
                {
                    printf("\n\tToday not have any customer's birthday");
                }

            }
            else
            {
                printf("\n\t%d is no any option",sSecretNo);
            }

            printf("\n\n\t:::===============================================:::");
            printf("\n\t:::Do you want to Re-run(y/n):");
            scanf(" %c",&rerun);
            printf("\t:::===============================================:::");
        }


    }
    else if (opinio==2)
    {
        printf("\nLast Discount %d percent.\nDo you want to change today discount(y/n):",sDisount);
        scanf(" %c",&isDChange);
        if(isDChange=='y')
        {
            printf("Enter To-Day Discount:",sDisount);
            scanf("%d",&uDiscount);
            disFile=fopen("discount.txt","w");
            if(disFile!=NULL)
            {
                printf("\nFile Opened");
                fprintf(disFile,"%d",uDiscount);
                printf("\nCongress discount is Updated.\nTo-Day Discount is %d",uDiscount);
                fclose(disFile);
            }
            else
            {
                printf("\nFile Error.");
            }
        }
        else
        {
            printf("\n\t:========================:");
            printf("\n\t: Ok Re-run your program :");
            printf("\n\t:========================:");

        }

    }
    else if(opinio==3)
    {
        printf("\n\t*Today Total Sold %d BDT*",sSold);
    }
    else if (opinio==4)
    {
        printf("\n\tHi, Welcome to Young Fashion.\n\tThanks for coming.\n\tWhat do you want to buy?:\n");
        printf("\n\t1.Shirt\n");
        printf("\n\t2.T-Shirt\n");
        printf("\n\t3.Gens\n");
        printf("\n\t4.Jacket\n");
        printf("\n\t5.Others\n");

        printf("\n\tChoose anyone");
        printf("\n\tPress->");
        scanf("%d",&uCategory);
        if(uCategory==1)
        {
            printf("\n\tYou select Shirt.\n\tEnter Your Size:\n\t1.M\t2.XL\n\t3.XXL\t4.Others");
            printf("\n\tChoose anyone:");
            printf("\n\tPress->");
            scanf("%d",&uSize);
            if(uSize==1)
            {
                printf("\n\tYou Select M Size");
                printf("\n\tPlease Select Your Color:\n\t1.White\t2.Black\n\t3.Purple\t4.Others");
                printf("\n\tChoose anyone:");
                printf("\n\tPress->");
                scanf("%d",&uColour);
                if(uColour==1)
                {
                    printf("\n\tYou select White Color");

                    printf("\n\tPrice of Shirt  is %d",sPrice);
                    discount_amount = ((sDisount+setdiscount+doshopDisObg.percent)*sPrice)/100;
                    aDiscount = (sPrice-discount_amount);

                    birth_amount=(20*aDiscount)/100;
                    bDiscount=(aDiscount-birth_amount);

                    printf("\n\tAfter adding Discount price is %d\n\t",aDiscount);
                    printf("\n\tAre You agree with this price(y/n):");
                    scanf(" %c",&isBuyed);

                    if(isBuyed=='y')
                    {


                        int d,m,y;
                        printf("\n\tSir,\n\tWhats Your Name:");
                        getchar();
                        gets(cName);
                        printf("\n\tPhone Number:");
                        scanf("%d",&cPhone);
                        printf("\n\tDOB (d-m-year):");
                        scanf("%d-%d-%d",&d,&m,&y);

                        //Get Cash:
                        cashFile=fopen("totalcash.txt","w");
                        if(cashFile!=NULL)
                        {
                            if(d==tm.tm_mday && m==tm.tm_mon+1)
                            {
                                fprintf(cashFile,"%d",(sCash + bDiscount));
                                fclose(cashFile);
                            }
                            else
                            {
                                fprintf(cashFile,"%d",(sCash + aDiscount));
                                fclose(cashFile);
                            }
                        }
                        else
                        {
                            printf("\nCash Not Exist");
                        }

                        soldFile=fopen("todysell.txt","w");
                        if(soldFile!=NULL)
                        {
                            if(d==tm.tm_mday && m==tm.tm_mon+1)
                            {
                                fprintf(soldFile,"%d",(sSold+bDiscount));
                            }
                            else
                            {
                                fprintf(soldFile,"%d",(sSold+aDiscount));
                            }
                            fclose(soldFile);
                        }
                        else
                        {
                            printf("\Sold File Not Exist");
                        }
                        //Increase Customer Len:
                        clenFile=fopen("totalcustomers.txt","w");
                        if(clenFile!=NULL)
                        {
                            fprintf(clenFile,"%d",(len + 1));
                            fclose(clenFile);
                        }
                        else
                        {
                            printf("\nCustomer Length File Not Exist");
                        }


                        cusFile=fopen("customerslist.txt","a");
                        cls();
                        if(cusFile!=NULL)
                        {

                            if(d==tm.tm_mday && m==tm.tm_mon+1)
                            {
                                fprintf(cusFile,"%s %d %s %d %d %d %d\n",cName,cPhone,"Shirt",bDiscount,d,m,y);

                                printf("\n\tHappy Birthday Sir,\n\tYou also find 20 percent Discount,\n\tHere is your bill:");
                                printf("\n\tName:%s\n\tPhone:%d\n\tItem:Shirt\n\tSize:M\n\tColor:White\n\tPrice:%d",cName,cPhone,bDiscount);
                            }
                            else
                            {
                                fprintf(cusFile,"%s %d %s %d %d %d %d\n",cName,cPhone,"Shirt",aDiscount,d,m,y);

                                printf("\n\tHere is your bill:");
                                printf("\n\tName:%s\n\tPhone:%d\n\tItem:Shirt\n\tSize:M\n\tColor:White\n\tPrice:%d",cName,cPhone,aDiscount);
                            }
                            fclose(cusFile);
                        }
                        else
                        {
                            printf("\nCustomer Not Exist");
                        }

                        printf("\n\t*|Congress|*");

                    }
                    else
                    {
                        printf("\n\tOk No  problem Sir.\n");
                    }
                }
                else if(uColour==2)
                {

                }
                else if(uColour==3)
                {

                }
                else if(uColour==4)
                {

                }
                else
                {

                }

            }
            else if(uSize==2)
            {
            }
            else if(uSize==3)
            {
            }
            else if(uSize==4)
            {
            }
            else
            {
                printf("\n\tNot Others Color Available");
            }

        }
        else if(uCategory==2)
        {
        }
        else if(uCategory==3)
        {
        }
        else if(uCategory==4)
        {
        }
        else if(uCategory==5)
        {
        }
        else
        {
            printf("\n\tComing Soon...");
        }

    }
    else if (opinio==5)
    {
        printf("\n\t:====================:");
        printf("\n\t:Enter Your Shop Lock:");
        printf("\n\t:====================:");
        printf("\n\tType->");
        scanf("%d",&ulock);
        if(slock==ulock)
        {
            printf("\n\tShop Information:");
            printf("\n\t:=========================:");
            printf("\n\t:Today Discount:%d percent:\n\t:=========================:\n\t:Shop Secret No:%d       :\n\t:=========================:\n\t:Shop Lock:%d            :\n\t:=========================:\n\t:Total Case:%d BDT      :",sDisount,sSecretNo,slock,sCash);
            printf("\n\t:=========================:");
        }
    }
    else
    {
        printf("\n\t:================:\n");
        printf("\t:!Sorry! In Correct:\n");
        printf("\n\t:================:");
    }

    printf("\n\t:============================:");
    printf("\n\t:==Do you want to Re-run(y/n):");
    scanf(" %c",&rerun);
    printf("\n\t:============================:");
}

void setHeaderview(int index)
{
    cls();
    index=index-1;


    printf("\n\t:==========================:");
    printf("\n\tWelcome to Your:%s",sinfoList[index].shopName);
    printf("\n\n\tOwner Name:%s",sinfoList[index].ownerName);
    printf("\n\n\tMy Shop ID:201-35-523");
    printf("\n\n\tPhone:%d",sinfoList[index].phoneNo);
    printf("\n\n\tShop No:Block A-01");
    printf("\n\n\t<-Today Discount %d Percent->",sinfoList[index].discount);
    getmalldiscoutonshop(index+1);
    printf("\n\t:===========================:");
    printf("\n\n\t:::Hey What do you want to do?:::");
    printf("\n\t:::                           :::");


}

void getmalldiscoutonshop(int index)
{
    index=index-1;
    getPhnNo= sinfoList[index].phoneNo;

    if(getPhnNo==doshopDisObg.phoneNo)
    {
        printf("\n\tDiscount from mall for me %d",doshopDisObg.percent);
    }
}
///End of Selling System///


///Start of Customer System///
void customerSystem()
{

  customerbuy();

}

void customerbuy()
{

    ///Starting Point:
    FILE *cinfoFIle,*cilenFile;
    int choose,i,cilen;
    char agree[3];

    printf("\n\twhat do you want?\n\t1. Buy Products \n\t2.visiting\n");
    printf("\n\tchoose any option:\n");
    printf("\n\tPress->");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
        printf("\n\tYou select buy\n\tshop list:\n");
        for(i=0; i<5; i++)
        {
            printf("\n\t%d.Shop Name:%s\n",i+1,sinfoList[i].shopName);
        }
        printf("---------------------\n");
        printf("choose any option from shop list:");
        scanf("%d",&choose);
        if(choose == 1)
        {
            printf("mobile Shop\n");
            printf("Which Brand mobile phone you want to buy:\n");//Samsung.Apple.Huawei.Nokia.
            printf(" 1. I phone\n 2. Samsung\n 3. Redmi\n 4. Nokia\n ");
            printf("-------------------\n");
            printf("choose any option from brand list:\n");
            scanf("%d",&choose);
            if(choose == 1)
            {
                printf("I phone\n i phone details:\n");
                printf(" 5.5 Display \n 16GB ROM\n 1GB RAM\n Camera 50 MP\n Battery 5000mph\n Color black\n ");
                printf("price 9000 BDT\n");
                printf("Are you want to buy this Phone(yes/no)\n");
                scanf(" %c",&agree[3]);
                if(agree[3] = "yes")
                {
                    fflush(stdin);
                    int d,m,y,ciphone;
                    char ciName[30];
                    printf("\nSir,\n Whats Your Name:");
                    gets(ciName);
                    printf("\nPhone Number:");
                    scanf("%d",&ciphone);
                    printf("\nDOB (d-m-year):");
                    scanf("%d-%d-%d",&d,&m,&y);
                    //printf("\ncongress for buy this product \n Please come again\n");///need file to apply


                    //Increase Customer Len:
                    clenFile=fopen("totalcustomers.txt","w");
                    if(clenFile!=NULL)
                    {
                        fprintf(clenFile,"%d",len+1);
                        fclose(clenFile);
                    }
                    else
                    {
                        printf("\nCustomer Length File Not Exist");
                    }

                    cusFile=fopen("customerslist.txt","a");
                    if(cusFile!=NULL)
                    {
                        printf("\nCustomers File Opened");

                        fprintf(cusFile,"%s %d %s %d %d %d %d\n",ciName,ciphone,"Mobile",100000,d,m,y);
                        // printf("\nSir,\nHere is your bill:");
                        // printf("\nName:%s\nPhone:%d\nItem:Shirt\nSize:M\nColor:White",cName,ciPhone);

                        fclose(cusFile);
                    }
                    else
                    {
                        printf("\nCustomer Not Exist");
                    }

                    printf("\nDone");


                }
                else
                {
                    printf("Sorry! Please come again\n");
                }

            }

            else
            {
                printf ("this brand is not available its coming soon...");
            }

        }
        else if(choose == 2)
        {
            printf("computer Shop");
            printf("Which Brand Laptop you want to buy:\n");
            printf(" 1. Lenovo\n 2. ASUS\n 3. Dell\n 4. Apple ");
            printf("choose any option from brand list:\n");
            scanf("%d",&choose);
            if(choose == 2)
            {
                printf("ASUS\n ASUS Laptop Details:\n");
                printf(" Screen Size 17.9 inch\n Generation 10Th\n CORE i7\n ");
                printf("price 70000 BDT\n");
                printf("Are you want to buy this Laptop(yes/no)\n");
                scanf(" %c",&agree[3]);
                if(agree[3] = "yes")
                {
                    printf("\ncongress for buy this product \n Please come again");

                }
                else
                {
                    printf("\Sorry! Please come again\n");
                }

            }

            else
            {
                printf ("this brand is not available its coming soon...");
            }

        }
        else if(choose == 3)
        {
            printf("Fashion Shop");
        }
        else if(choose == 4)
        {
            printf("cosmetics Shop");
        }
        else
        {
            printf("you select wrong");
        }


        break;
    case 2:

         visitingfunction();

        break;
    default:
        printf("you select wrong");
        break;

    }
}

visitingfunction(){
       printf("\n\t:::===============================================:::");
    printf("\n\t:::Select Anyone                                  :::\n");
    printf("\n\t:::===============================================:::");

    for(i=0; i<len; i++)
    {
        printf("\n\t:::%d.Name:%s                                      \n",i+1,cList[i].name);
        printf("\n\t:::===============================================");

    }
    printf("\n\t>");
    scanf("%d",&getChoice);
    if(getChoice==1)
    {

        setCustInfo(getChoice);

    }
    else if(getChoice==2)
    {
        setCustInfo(getChoice);
    }
    else if(getChoice==3)
    {
        setCustInfo(getChoice);
    }
    else if(getChoice==4)
    {
        setCustInfo(getChoice);
    }
    else if(getChoice==5)
    {
        setCustInfo(getChoice);
    }
    else
    {
        printf("\n\tChoose wright one");
    }
}
void setCustInfo(int index)
{
    int phn;
    index=index-1;

    printf("\n\tEnter Your Phone:");
    scanf("%d",&phn);

    if(phn==cList[index].phoneNo)
    {


        if(cList[index].day==tm.tm_mday){
            printf("\n\t*Happy Birthday Sir*");

            printf("\n\tIf You Buy Something from any Shop\n\tYou can find 20% of discount");

        }

        printf("\n\tPersonal Information:\n");
        printf("\tName:%s",cList[index].name);
        printf("\n\tPhone%d",cList[index].phoneNo);
        printf("\n\tDOB:%d-%d-%d",cList[index].day,cList[index].mon,cList[index].year);

        customerbuy();
    }
    else
    {
        printf("\n\tSorry Phone number is no matched");
    }
}

///End of Customer System///

void mallInformation()
{
    printf("\n\tCity Shopping Mall\n\tAddress:Dhaka,Bangladesh");
}

void fileopening()
{
    //Get Password:
    passFile=fopen("password.txt","r");
    if(passFile!=NULL)
    {
        printf("\nPassword File Opened");
        while(!feof(passFile))
        {
            fscanf(passFile,"%d",&slock);
        }
        fclose(passFile);
    }
    else
    {
        printf("\nPassword Not Exist");
    }
    //get Mall Discount

    mallDisFile=fopen("malldiscount.txt","r");
    if(mallDisFile!=NULL)
    {
        printf("\nMall Discount File Opened");
        while(!feof(mallDisFile))
        {
            fscanf(mallDisFile,"%d",&mallDis);
        }
        fclose(mallDisFile);
    }
    else
    {
        printf("\n Mall discount file Not Exist");
    }

    //Get shop discount from mall:
    shopDisfromMallFile=fopen("shopdiscountfrommall.txt","r+");
    if(shopDisfromMallFile!=NULL)
    {
        printf("\nDo shop discount from mall File Opened");
        while(!feof(shopDisfromMallFile))
        {
            fscanf(shopDisfromMallFile,"%d %d",&doshopDisObg.percent,&doshopDisObg.phoneNo);
        }
        fclose(shopDisfromMallFile);
    }
    else
    {
        printf("\n Do shop discount mall Not Exist");
    }

    //Get Discount:
    disFile=fopen("discount.txt","r");
    if(disFile!=NULL)
    {
        printf("\nDiscount File Opened");
        while(!feof(passFile))
        {
            fscanf(disFile,"%d",&sDisount);
        }
        fclose(disFile);
    }
    else
    {
        printf("\nPassword Not Exist");
    }
    //Get Customer length:
    clenFile=fopen("totalcustomers.txt","r");
    if(clenFile!=NULL)
    {
        printf("\nCustomer Length File Opened");
        while(!feof(clenFile))
        {
            fscanf(clenFile,"%d",&len);
        }
        fclose(clenFile);
    }
    else
    {
        printf("\nCustomer Length File Not Exist");
    }


    //Get Shop:
    shoplistFile=fopen("shoplist.txt","r");
    if(shoplistFile!=NULL)
    {
        printf("\nShop list File Opened");
        while(!feof(shoplistFile))
        {
            for(i=0; i<len; i++)
            {
                fscanf(shoplistFile,"%s %s %d %d",&shop[i].shopName,&shop[i].shopOwner,&shop[i].discount,&shop[i].phoneNo);
            }
        }
        fclose(shoplistFile);
    }


    //Get Customers:
    cusFile=fopen("customerslist.txt","r");
    if(cusFile!=NULL)
    {
        printf("\nCustomers File Opened");
        while(!feof(cusFile))
        {
            for(i=0; i<len; i++)
            {
                fscanf(cusFile,"%s %d %s %d %d %d %d",&cList[i].name,&cList[i].phoneNo,&cList[i].shipped,&cList[i].price,&cList[i].day,&cList[i].mon,&cList[i].year);
            }
        }
        fclose(cusFile);
    }
    else
    {
        printf("\nCustomer Not Exist");
    }
    //Get Cash:
    cashFile=fopen("totalcash.txt","r");
    if(cashFile!=NULL)
    {
        printf("\nTotal Cash File Opened");
        while(!feof(cashFile))
        {

            fscanf(cashFile,"%d",&sCash);

        }
        fclose(cashFile);
    }
    else
    {
        printf("\nCash Not Exist");
    }

    //Get Today Sold:
    soldFile=fopen("todysell.txt","r");
    if(soldFile!=NULL)
    {
        printf("\nToday Sold File Opened");
        while(!feof(soldFile))
        {
            fscanf(soldFile,"%d",&sSold);
        }
        fclose(soldFile);
    }
    else
    {
        printf("\Sold File Not Exist");
    }

    //get Shop Info list:
    shopinfoFile=fopen("shopinfo.txt","r");

    if(shopinfoFile!=NULL)
    {

        while(!feof(shopinfoFile))
        {
            for(i=0; i<5; i++)
            {
                fscanf(shopinfoFile,"%s %s %d %d",&sinfoList[i].shopName,&sinfoList[i].ownerName,&sinfoList[i].phoneNo,&sinfoList[i].discount);
            }
        }
        fclose(shopinfoFile);
    }

}

///Animation Function///
///HEERE PRINTF STYLE FUNCTION

void pwellcome()
{
    ccolor(26);

    char welcome[50]="WELCOME TO";
    //char welcome2[50]=" TO";
    char welcome3[50]="SHOPPIN MALL MANAGEMENT SYSTEM";
    //char welcome4[50]=" MANAGEMENT SYSTEM";
    printf("\n\t\t\t\t  ");
    for(int wlc=0; wlc<strlen(welcome); wlc++)
    {

        printf(" %c",welcome[wlc]);
        Sleep(100);
    }
    ccolor(26);
    //printf("\n\n\t\t\t\t ");
    //for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

    //printf(" %c",welcome2[wlc2]);
    //Sleep(100);
    //}
    //ccolor(26);
    printf("\n\n\t\t");
    for(int wlc3=0; wlc3<strlen(welcome3) ; wlc3++)
    {
        if(welcome3[wlc3]!='D')
        {

            printf(" %c",welcome3[wlc3]);
        }
        else
        {

            printf(" %c",welcome3[wlc3]);

        }

        Sleep(100);
    }
    ccolor(26);
    //printf("\n\n\n\t\t\t\t ");
    //for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
    //if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

    //printf(" %c",welcome4[wlc3]);
    //}
    //else{

    //printf(" %c",welcome4[wlc3]);
    //}
    //Sleep(100);
    //}
    //ccolor(26);

}
void loadingbar(void)
{

    for (int i=15; i<=100; i+=5)
    {

        cls();

        printf("\n\n\t\t\t\t\t");
        printf("%d%% Progress...\n\n\t",i);

        printf("");

        for (int j=0; j<i; j+=2)
        {

            ccolor(160+j);
            printf(" ");
            ccolor(26);

        }
        Sleep(100);
        if(i==90 || i==50 || i==96 || i==83)
        {
            Sleep(100);
        }

    }

}

void cls()
{

    system("cls");

}

void echo(char print[])
{

    printf("%s",print);
}

void br(int line)
{
    for(int i=0; i<line; i++)
    {
        printf("\n");
    }
}

void pre(int tab)
{

    for(int i=0; i<tab; i++)
    {
        printf("\t");
    }

}
void span(int space)
{

    for(int i=0; i<space; i++)
    {
        printf(" ");
    }

}
void ccolor(int clr)
{

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}




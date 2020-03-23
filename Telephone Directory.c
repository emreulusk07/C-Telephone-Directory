#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// EMRE ULUISIK
typedef struct Rehber
{
    char ad[15];
    char soyad[15];
    int no;

    struct Rehber *next;
} rehber;

rehber *gecici;
rehber *baslangic;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

rehber *RehbereEkle(rehber *p)
{
    int deneme = 0;
    char isim[15];
    char soyisim[15];
    int numara;

    baslangic = p;
    gecici = p;

    if (p == NULL)
    {
        p = (rehber *) malloc(sizeof(rehber));

        printf("___________________________________________\n\n");
        printf("Rehbere eklemek istediginiz kisinin adi: ");
        scanf("%s", isim);
        strcpy(p->ad, isim);

        printf("Rehbere eklemek istediginiz kisinin soyadi: ");
        scanf("%s", soyisim);
        strcpy(p->soyad, soyisim);

        printf("Rehbere eklemek istediginiz kisinin telefon numarasi: ");
        scanf("%d", &numara);
        p->no = numara;

        printf("\nEkleme islemi gerceklestirildi..");
        delay(2300);
        system("CLS");

        p->next = NULL;

        return p;
    }

    else
    {
        baslangic = p;

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = (rehber *) malloc(sizeof(rehber));

        printf("____________________________________________\n\n");
        printf("Rehbere eklemek istediginiz kisinin adi: ");
        scanf("%s", isim);
        strcpy(p->next->ad, isim);

        printf("Rehbere eklemek istediginiz kisinin soyadi: ");
        scanf("%s", soyisim);
        strcpy(p->next->soyad, soyisim);

        printf("Rehbere eklemek istediginiz kisinin telefon numarasini girin: ");
        scanf("%d", &numara);
        p->next->no = numara;

        printf("\nEkleme islemi gerceklestirildi..");
        delay(2300);
        system("CLS");

        p->next->next = NULL;


        return baslangic;
    }


}


rehber *IsmeGoreSirala(rehber *p)
{

    int a, noTut, t, kucuk=0;
    char tut[25], soyadtut[25];

    baslangic = p;

    if(strlen(p->ad) > strlen(p->next->ad)){

        kucuk = strlen(p->next->ad);
    }
    else if(strlen(p->ad) < strlen(p->next->ad)){

        kucuk = strlen(p->ad);
    }
    else{
        kucuk = strlen(p->ad);
    }



    for(; p->next != NULL ;){

        for(; p->next != NULL ;){

            for(a=0; a<kucuk ; a++){

                if(p->ad[a] < p->next->ad[a])
                {
                    p = p->next;
                    break;
                }

                else if(p->ad[a] > p->next->ad[a])
                {
                    strcpy(tut, p->ad);
                    strcpy(p->ad, p->next->ad);
                    strcpy(p->next->ad, tut);

                    strcpy(soyadtut, p->soyad);
                    strcpy(p->soyad, p->next->soyad);
                    strcpy(p->next->soyad, soyadtut);

                    noTut = p->no;
                    p->no = p->next->no;
                    p->next->no = noTut;

                    p = baslangic;
                    break;
                }

                else
                {
                    for(t=0; t<kucuk ; t++){

                        if(p->soyad[a] < p->next->soyad[a])
                        {
                            p = p->next;
                            break;
                        }

                        else if(p->soyad[a] > p->next->soyad[a])
                        {
                            strcpy(soyadtut, p->soyad);
                            strcpy(p->soyad, p->next->soyad);
                            strcpy(p->next->soyad, soyadtut);

                            strcpy(tut, p->ad);
                            strcpy(p->ad, p->next->ad);
                            strcpy(p->next->ad, tut);

                            noTut = p->no;
                            p->no = p->next->no;
                            p->next->no = noTut;

                            p = baslangic;
                            break;
                        }

                        else
                        {
                            break;
                        }

                    }
                }
            }
        }
    }

delay(1700);
system("CLS");
    printf("# Isme Gore Siralama #\n\n");

    for(p = baslangic; p != NULL ; p=p->next)
    {
        printf("%s %s %d\n", p->ad, p->soyad, p->no);
    }
delay(3800);
system("CLS");


    return baslangic;


}


rehber *NumarayaGoreSirala(rehber *p)
{
    int tut, i, j;
    char adtut[25], soyadtut[25];

    baslangic = p;

    for(i=0; p->next != NULL ; i++){

        for(j=0; p->next != NULL ; j++){

            if((p->no > p->next->no) && (p->next != NULL))
            {
                tut = p->no;
                p->no = p->next->no;
                p->next->no = tut;

                strcpy(adtut, p->ad);
                strcpy(p->ad, p->next->ad);
                strcpy(p->next->ad, adtut);

                strcpy(soyadtut, p->soyad);
                strcpy(p->soyad, p->next->soyad);
                strcpy(p->next->soyad, soyadtut);

                p = baslangic;
            }

            else if((p->no == p->next->no) && (p->next != NULL))
            {
                printf("Girdiginiz bir numara baska bir numara ile eslenti.\nIsleminiz gecersiz..");
                break;
            }

            else
            {
                p = p->next;
            }
        }
    }

delay(1700);
system("CLS");
    printf("# Telefon Numarasina Gore Siralama #\n\n");

    for(p = baslangic; p != NULL ; p=p->next)
    {
        printf("%s %s %d\n", p->ad, p->soyad, p->no);
    }
delay(3800);
system("CLS");


    return baslangic;


}


rehber *RehberdenSil(rehber *p)
{

    char silAd[25];

    baslangic = p;

    printf("Silmek istediginiz kisinin adini giriniz: ");
    scanf("%s", silAd);

    printf("\nSilme isleminiz gerceklestirildi..");
delay(2100);
system("CLS");


    if(p == NULL)
    {
        printf("\nRehberinizde kisi bulunmamaktadir..");
    }

    if(strcmp(silAd, baslangic->ad) == 0)
    {
        gecici = p;
        p = p->next;
        free(gecici);
        return p;
    }


    while((p->next != NULL) && (strcmp(silAd, p->next->ad) != 0))
    {
        p = p->next;
    }

    if(strcmp(silAd, p->next->ad) == 0)
    {
        gecici = p->next;
        p->next = p->next->next;
        free(gecici);
        return baslangic;
    }


}


void RehberdenAra(rehber *p)
{
// ********************************************************************************************************
// AYNI ISIMDE BIRDEN FAZLA KISI GIRILDIGINDE, DIGER KISILERIN LISTEDE GORUNMESINDE BIRAZ GECIKME OLUYOR..
// ********************************************************************************************************
    char arananAd[25];
    int i, a, say=0, arananBoyut=0;

    baslangic = p;

    printf("Rehberinizde aramak istediginiz kisinin adini girin: ");
    scanf("%s", arananAd);

    arananBoyut = strlen(arananAd);
delay(1850);
system("CLS");
    printf("# Arama Sonucu #\n\n");

    while(p != NULL){

        for(a=0; a<arananBoyut ; a++){

            if(p->ad[a] == arananAd[a])
            {
                ++say;
                if(say == arananBoyut)
                {
                    printf("%s %s %d\n", p->ad, p->soyad, p->no);
                    p = p->next;
                }
            }

            else
            {
                p = p->next;
                a=0;
            }
        }
    }

delay(3450);
system("CLS");
main();

}


rehber *RehberiGuncelle(rehber *p)
{

    int sec, no, guncelNo, guncellenecekNo;
    char guncelAd[25], guncellenecekAd[25], guncelSoyad[25], guncellenecekSoyad[25];

    baslangic = p;

system("CLS");
    printf("1 >> Adi guncelle\n2 >> Soyadi guncelle\n3 >> Telefon numarasini guncelle\n\nSeciminiz: ");
    scanf("%d", &sec);

    if(sec == 1)
    {
system("CLS");
        printf("Guncellemek istediginiz kisinin adini girin: ");
        scanf("%s", guncellenecekAd);

        printf("Istediginiz guncel adi girin: ");
        scanf("%s", guncelAd);


        if(strcmp(p->ad, guncellenecekAd) == 0)
        {
            strcpy(p->ad, guncelAd);
system("CLS");
            printf("# Guncellenme sonucu #\n\n%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");
            return baslangic;
        }


        while(p->next != NULL)
        {

            if(strcmp(p->next->ad, guncellenecekAd) == 0)
            {
                strcpy(p->next->ad, guncelAd);
system("CLS");
                printf("# Guncellenme sonucu #\n\n%s %s %d", p->next->ad, p->next->soyad, p->next->no);
delay(3450);
system("CLS");
                return baslangic;
            }
            p = p->next;

        }
        if(strcmp(p->ad, guncellenecekAd) == 0)
        {
            strcpy(p->ad, guncelAd);
system("CLS");
            printf("# Guncellenme sonucu #\n\n%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");
            return baslangic;
        }

    }


    else if(sec == 2)
    {
system("CLS");
        printf("Guncellemek istediginiz kisinin soyadini girin: ");
        scanf("%s", guncellenecekSoyad);

        printf("Istediginiz guncel soyadi girin: ");
        scanf("%s", guncelSoyad);


        if(strcmp(p->soyad, guncellenecekSoyad) == 0)
        {
            strcpy(p->soyad, guncelSoyad);
system("CLS");
            printf("# Guncellenme sonucu #\n\n%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");
            return baslangic;
        }


        while(p->next != NULL)
        {

            if(strcmp(p->next->soyad, guncellenecekSoyad) == 0)
            {
                strcpy(p->next->soyad, guncelSoyad);
system("CLS");
                printf("# Guncellenme sonucu #\n\n%s %s %d", p->next->ad, p->next->soyad, p->next->no);
delay(3450);
system("CLS");
                return baslangic;
            }
            p = p->next;

        }
        if(strcmp(p->soyad, guncellenecekSoyad) == 0)
        {
            strcpy(p->soyad, guncelSoyad);
system("CLS");
            printf("# Guncellenme sonucu #\n\n%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");
            return baslangic;
        }

    }


    else if(sec == 3)
    {
system("CLS");
        printf("Guncellemek istediginiz kisinin numarasini girin: ");
        scanf("%d", &guncellenecekNo);

        printf("Istediginiz guncel numarayi girin: ");
        scanf("%d", &guncelNo);


        if(p->no = guncellenecekNo)
        {
            p->no = guncelNo;
system("CLS");
            printf("# Guncellenme sonucu #\n\n%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");
            return baslangic;
        }
        else{
            gecici = RehberiGuncelle(baslangic);
        }


        while(p->next != NULL)
        {

            if(p->next->no = guncellenecekNo)
            {
                p->next->no = guncelNo;
system("CLS");
                printf("# Guncellenme sonucu #\n\n%s %s %d", p->next->ad, p->next->soyad, p->next->no);
delay(3450);
system("CLS");
                p = p->next;
                return baslangic;
            }
            //p = p->next;

            else
            {
                p = p->next;
                gecici = RehberiGuncelle(baslangic);
            }

        }

        if(p->no, guncellenecekNo)
        {
            p->no = guncelNo;
system("CLS");
            printf("# Guncellenme sonucu #\n\n%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");
            return baslangic;
        }

    }

    else
    {
        printf("\nYanlis secim yaptiniz..");
        RehberiGuncelle(baslangic);
    }


}


void RehberiListele(rehber *p)
{

system("CLS");
    printf("# Rehber Listesi #\n\n");

    while(p->next != NULL)
    {
        printf("%s %s %d", p->ad, p->soyad, p->no);
        p = p->next;
        printf("\n");
    }
    printf("%s %s %d", p->ad, p->soyad, p->no);
delay(3450);
system("CLS");

}


int main()
{

    int secim;

    rehber *ilk = NULL;

    while(1==1){

        printf("1 < REHBERE EKLE >\n2 < REHBERI LISTELE >\n3 < ISME GORE SIRALA >\n4 < TELEFON NUMARASINA GORE SIRALA >");
        printf("\n5 < REHBERDEN SIL >\n6 < REHBERDEN ARA >\n7 < REHBERI GUNCELLE >\n8 < CIKIS YAP >");
        printf("\n\nGerceklestirmek istediginiz islemi seciniz: ");
        scanf("%d", &secim);
        switch(secim)
        {

            case 1: ilk = RehbereEkle(ilk);
            break;

            case 2: RehberiListele(ilk);
            break;

            case 3: ilk = IsmeGoreSirala(ilk);
            break;

            case 4: ilk = NumarayaGoreSirala(ilk);
            break;

            case 5: ilk = RehberdenSil(ilk);
            break;

            case 6: RehberdenAra(ilk);
            break;

            case 7: ilk = RehberiGuncelle(ilk);
            break;

            case 8: exit(0);
            break;

        }

    }

}

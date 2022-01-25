#include<stdio.h>
#include<math.h>
#include<string.h>
int binary_to_decimal(int n);
int octal_to_decimal(int n);
int hexadecimal_to_decimal(int n);
int decimal_to_binary(int n);
int octal_to_binary(int n);
void hexadecimal_to_binary(char* hexdec);
int decimal_to_octal(int n);
int binary_to_octal(int n);
int hexadecimal_to_octal(char hexa[]);
int decimal_to_hexadecimal(int n);
int binary_to_hexadecimal(int n);
int octal_to_hexadecimal(int n);


int main ()
{
    int n;
    int choice;
    printf("Instructions\n");
    printf("1.binary_to_decimal\n2.octal_to_decimal\n3.hexadecimal_to_decimal\n4.decimal_to_binary\n5.octal_to_binary\n6.hexadecimal_to_binary\n7.decimal_to_octal\n8.binary_to_octal\n");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter a binary number :");
        scanf("%d",&n);
        printf("%d in binary = %d in decimal",n,binary_to_decimal(n));
    }
    else if (choice==2)
    {
        printf("Enter a octal number :");
        scanf("%d",&n);
        printf("%d in octal = %d in decimal",n,octal_to_decimal(n));
    }
    else if (choice==3)
    {
        printf("Enter a hexadecimal number :");
        scanf("%d",&n);
        printf("%d in hexadecimal = %d in decimal",n,hexadecimal_to_decimal(n));
    }
    else if(choice==4)
    {

        printf("Enter a hexadecimal number :");
        scanf("%d",&n);
        printf("%d in decimal = %d in binary ",n,decimal_to_binary(n));
    }
    else if(choice==5)
    {
        printf("Enter a octal number :");
        scanf("%d",&n);
        printf("%d in octal = %d in binary ",n,octal_to_binary(n));
    }
    else if (choice==6)
    {
        printf("Enter a octal number :");
        char hexdec[100];
       gets(hexdec);

    // Convert HexaDecimal to Binary
    printf("\nEquivalent Binary value is : ");
    hexadecimal_to_binary(hexdec);

    }
    else if(choice==7)
    {
        printf("Enter a decimal number :");
        scanf("%d",&n);
        printf("%d in decimal = %d in octal ",n,decimal_to_octal(n));
    }
    else if(choice==8)
    {
        printf("Enter a binary number :");
        scanf("%d",&n);
        printf("%d in binary = %d in octal ",n,binary_to_octal(n));
    }
    else if (choice==9)
    {
       char hexa[20];

    printf("Enter Hexadecimal Number : ");

    gets(hexa);

    printf("Equivalent Octal Value = %d",exadecimal_to_octal(hexa));
    }

}

int binary_to_decimal(int n)
{

    int rem, i=0,num=0;
    while (n>0)
    {
        rem=n%10;
        num=num+rem*pow(2,i);
        i++;
        n=n/10;

    }
    return num;
}

int octal_to_decimal(int n)
{
    int rem, i=0,num=0;
    while (n>0)
    {
        rem=n%10;
        num=num+rem*pow(8,i);
        i++;
        n=n/10;
    }
    return num;
}

int hexadecimal_to_decimal(int n)
{
    int rem, i=0,num=0;
    while (n>0)
    {
        rem=n%10;
        num=num+rem*pow(16,i);
        i++;
        n=n/10;

    }
    return num;
}

int decimal_to_binary( int n)
{


    int remainder;
    int binary = 0, i = 1;

    while(n != 0)
    {
        remainder = n%2;
        n = n/2;
        binary= binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

int octal_to_binary(int n)
{
    int octalDigitToBinary[8] = {0, 1, 10, 11, 100, 101, 110, 111};
    long octalNumber, binaryNumber = 0, position;
    int digit;
    position = 1;
    while(n!= 0)
    {
        digit = n% 10;
        binaryNumber = (octalDigitToBinary[digit] * position) + binaryNumber;
        n /= 10;
        position *= 1000;
    }
    return binaryNumber;
}

int decimal_to_octal(int n)
{

    int remainder;
    long octal = 0, i = 1;

    while(n != 0)
    {
        remainder = n%8;
        n = n/8;
        octal = octal + (remainder*i);
        i = i*10;
    }
    return octal;
}

int binary_to_octal(int n)
{
    int remainder;
    long decimal = 0, octal = 0, i = 0;

    while(n != 0)
    {
        remainder = n%10;
        n = n/10;
        decimal = decimal + (remainder*pow(2,i));
        ++i;
    }


    i = 1;

    while(decimal != 0)
    {
        remainder = decimal%8;
        decimal = decimal/8;
        octal = octal + (remainder*i);
        i = i*10;
    }

    return octal;
}

void hexadecimal_to_binary(char* hexdec)
{

    long int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        default:
            printf("\nInvalid hexadecimal digit %c",
                   hexdec[i]);
        }
        i++;
    }
}

int hexadecimal_to_octal(char hexa[])

{

    int i,size, deci=0, octa=0;

    for(size=0; hexa[size]!='\0'; size++);  //this loop calculates size of hexadecimal number

    for(i=0; hexa[i]!='\0'; i++,size--)

    {

        if(hexa[i]>='0' && hexa[i]<='9')

        {

            deci= deci + (hexa[i]-'0')*pow(16,size-1);

        }

        if(hexa[i]>='A' && hexa[i]<='F')

        {

            deci = deci + (hexa[i]-55)*pow(16,size-1);

        }

        if(hexa[i]>='a' && hexa[i]<='f')

        {

            deci = deci + (hexa[i]-87)*pow(16,size-1);

        }

    } // deci contains the decimal value of given hexadecimal number.

    i=1;

    while(deci!=0)

    {

        octa = octa + (deci%8)*i;

        deci = deci/8;

        i = i*10;

    }

    return octa;

}



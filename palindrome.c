/*
 *  @author     : SRvSaha
 *  Filename    : pallindrome.c
 *  Timestamp   : 02:24 PM 12-JUL-2016
 *  Description : To check if a number is pallindrome or not.
 *
 */

#include <stdio.h>
int main()
{
    long num,temp;
    long sum;
    char ch;
    do{
        sum = 0;
        printf("Please enter a number : ");
        scanf("%ld",&num);
        temp = num;
        while(num > 0){
            sum = sum*10 + (num%10);
            num /= 10;
        }
        if(temp == sum)
            printf("Number entered is a palindrome\n");
        else
            printf("Number is NOT a palindrome\n");
        printf("Do you want to continue ? Y or N\n");
        scanf(" %c",&ch);
    }while(ch == 'y'||ch == 'Y');
    return 0;
}

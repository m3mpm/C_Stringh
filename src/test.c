#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"

void put(const char *value, char *array, my_size_t size);

START_TEST(test_memchr) {
    unsigned char src[50] = "1234567890";
    char *pm = my_memchr(src, '5', 10);
    char *pms = memchr(src, '5', 10);
    ck_assert_str_eq(pm, pms);

    unsigned char src2[50] = "123\n456\t78 90";
    pm = my_memchr(src2, '\t', 10);
    pms = memchr(src2, '\t', 10);
    ck_assert_str_eq(pm, pms);

    pm = my_memchr(src2, ' ', 12);
    pms = memchr(src2, ' ', 12);
    ck_assert_str_eq(pm, pms);

    pm = my_memchr(src2, '4', 10);
    pms = memchr(src2, '4', 10);
    ck_assert_str_eq(pm, pms);
}
END_TEST

START_TEST(test_strcat) {
    char src1[100] = "one two three";
    char my_dst1[100] = "four five";
    char std_dst1[100] = "four five";
    my_strcat(my_dst1, src1);
    strcat(std_dst1, src1);
    ck_assert_str_eq(my_dst1, std_dst1);

    char src[6] = "aoooa";
    char my_dst[12] = "bz\0zzb";
    char std_dst[12] = "bz\0zzb";
    my_strcat(my_dst, src);
    strcat(std_dst, src);
    ck_assert_str_eq(my_dst, std_dst);

    char my_dst2[30] = "bz\nzzb";
    char std_dst2[30] = "bz\nzzb";
    my_strcat(my_dst2, src);
    strcat(std_dst2, src);
    ck_assert_str_eq(my_dst2, std_dst2);

    char my_dst3[30] = "bz\n\tzzb";
    char std_dst3[30] = "bz\n\tzzb";
    my_strcat(my_dst3, src);
    strcat(std_dst3, src);
    ck_assert_str_eq(my_dst3, std_dst3);

    char my_dst4[12] = "";
    char std_dst4[12] = "";
    my_strcat(my_dst4, src);
    strcat(std_dst4, src);
    ck_assert_str_eq(my_dst4, std_dst4);

    char src2[6] = "";
    char my_dst5[12] = "abc";
    char std_dst5[12] = "abc";
    my_strcat(my_dst5, src2);
    strcat(std_dst5, src2);
    ck_assert_str_eq(my_dst5, std_dst5);

    char src3[6] = "abc";
    char my_dst6[12] = "";
    char std_dst6[12] = "";
    my_strcat(my_dst6, src3);
    strcat(std_dst6, src3);
    ck_assert_str_eq(my_dst6, std_dst6);

    char src4[6] = "3\0";
    char my_dst7[12] = "\0";
    char std_dst7[12] = "\0";
    my_strcat(my_dst7, src4);
    strcat(std_dst7, src4);
    ck_assert_str_eq(my_dst7, std_dst7);
}
END_TEST

START_TEST(test_strcpy) {
    char src1[50] = "abc def 345";
    char cps1[50] = "new line";
    char cp1[50] = "new line";
    strcpy(cps1, src1);
    my_strcpy(cp1, src1);
    ck_assert_str_eq(cps1, cp1);

    char src2[50] = "ab\nc def 3\045";
    char cps2[50] = "new line";
    char cp2[50] = "new line";
    strcpy(cps2, src2);
    my_strcpy(cp2, src2);
    ck_assert_str_eq(cps2, cp2);

    char src3[50] = "";
    char cps3[50] = "new line";
    char cp3[50] = "new line";
    strcpy(cps3, src3);
    my_strcpy(cp3, src3);
    ck_assert_str_eq(cps3, cp3);

    char src4[50] = "\t source \0\0";
    char cps4[50] = "new line";
    char cp4[50] = "new line";
    strcpy(cps4, src4);
    my_strcpy(cp4, src4);
    ck_assert_str_eq(cps4, cp4);

    char src5[50] = "123 In this\b\r\n project you will develop your own";
    char cps5[100] = "new line";
    char cp5[100] = "new line";
    strcpy(cps5, src5);
    my_strcpy(cp5, src5);
    ck_assert_str_eq(cps5, cp5);
}
END_TEST

START_TEST(test_strpbrk) {
    char *src1 = "0123456789";
    char *form = "369";
    char *p1 = strpbrk(src1, form);
    char *ps1 = my_strpbrk(src1, form);
    ck_assert_int_eq(*p1, *ps1);

    char *form2 = "93";
    p1 = strpbrk(src1, form2);
    ps1 = my_strpbrk(src1, form2);
    ck_assert_int_eq(*p1, *ps1);

    char *form3 = "98";
    p1 = strpbrk(src1, form3);
    ps1 = my_strpbrk(src1, form3);
    ck_assert_int_eq(*p1, *ps1);

    char *src2 = "number one\tnumber two\n";
    char *form4 = " ";
    p1 = strpbrk(src2, form4);
    ps1 = my_strpbrk(src2, form4);
    ck_assert_int_eq(*p1, *ps1);

    char *form6 = "tw\0o";
    p1 = strpbrk(src2, form6);
    ps1 = my_strpbrk(src2, form6);
    ck_assert_int_eq(*p1, *ps1);
}
END_TEST

START_TEST(test_upper) {
    char *srcUp = "abcdefghijklmnopqrstuvwxyz";
    char *resUp = my_to_upper(srcUp);
    char *up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ck_assert_str_eq(resUp, up);
    free(resUp);

    char *srcUp2 = "1234567890!@#$%^&*()\n\t\b \0";
    resUp = my_to_upper(srcUp2);
    char *up1 = "1234567890!@#$%^&*()\n\t\b \0";
    ck_assert_str_eq(resUp, up1);
    free(resUp);
}
END_TEST

START_TEST(test_lower) {
    char *srcLower = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lower = "abcdefghijklmnopqrstuvwxyz";
    char *resLower = my_to_lower(srcLower);
    ck_assert_str_eq(resLower, lower);
    free(resLower);

    char *srcLower1 = "1234567890!@#$%^&*()\n\t\b \0";
    char *lower1 = "1234567890!@#$%^&*()\n\t\b \0";
    char *resLower1 = my_to_lower(srcLower1);
    ck_assert_str_eq(resLower1, lower1);
    free(resLower1);
}
END_TEST

START_TEST(test_insert) {
    char srci[100] = "world";
    char ins[100] = "INSIDE";
    char *ri = (char *)my_insert(srci, ins, 2);
    char *chi = "woINSIDErld";
    ck_assert_str_eq(ri, chi);
    free(ri);

    char *ri3 = (char *)my_insert(srci, ins, 5);
    char *chi3 = "worldINSIDE";
    ck_assert_str_eq(ri3, chi3);
    free(ri3);

    char *ri4 = (char *)my_insert(srci, ins, 0);
    char *chi4 = "INSIDEworld";
    ck_assert_str_eq(ri4, chi4);
    free(ri4);

    char ins2[100] = " ";
    char *ri5 = (char *)my_insert(srci, ins2, 2);
    char *chi5 = "wo rld";
    ck_assert_str_eq(ri5, chi5);
    free(ri5);

    char ins3[100] = "WORD";
    char *ri6 = (char *)my_insert("a", ins3, 0);
    char *chi6 = "WORDa";
    ck_assert_str_eq(ri6, chi6);
    free(ri6);

    char *ri7 = (char *)my_insert("a", ins3, 1);
    char *chi7 = "aWORD";
    ck_assert_str_eq(ri7, chi7);
    free(ri7);

    char *ri8 = (char *)my_insert("", ins3, 0);
    char *chi8 = "WORD";
    ck_assert_str_eq(ri8, chi8);
    free(ri8);
}
END_TEST

START_TEST(test_trim) {
    char tr[100] = "hello world";
    char *res1 = (char *)my_trim(tr, "dlr");
    char *check = "hello wo";
    ck_assert_str_eq(res1, check);
    free(res1);

    res1 = (char *)my_trim(tr, "rdl");
    ck_assert_str_eq(res1, check);
    free(res1);

    res1 = (char *)my_trim(tr, "lrd");
    ck_assert_str_eq(res1, check);
    free(res1);

    char tr2[100] = "hello world";
    char *res2 = (char *)my_trim(tr2, "hel");
    char *check2 = "o world";
    ck_assert_str_eq(res2, check2);
    free(res2);

    res2 = (char *)my_trim(tr2, "leh");
    ck_assert_str_eq(res2, check2);
    free(res2);

    res2 = (char *)my_trim(tr2, "elh");
    ck_assert_str_eq(res2, check2);
    free(res2);

    char tr3[100] = "hello world\t";
    char *res3 = (char *)my_trim(tr3, " \t");
    char *check3 = "hello world";
    ck_assert_str_eq(res3, check3);
    free(res3);

    res3 = (char *)my_trim(tr3, "\t");
    ck_assert_str_eq(res3, check3);
    free(res3);

    char tr4[100] = "\n hello world\n";
    char *check4 = " hello world";
    char *res4 = (char *)my_trim(tr4, "\n");
    ck_assert_str_eq(res4, check4);
    free(res4);

    char tr5[10] = {' ', 'n', ' '};
    char *check5 = "n";
    char *res5 = (char *)my_trim(tr5, " ");
    ck_assert_str_eq(res5, check5);
    free(res5);

    char tr6[10] = " \tn\t ";
    char *check6 = "n";
    char *res6 = (char *)my_trim(tr6, " \t");
    ck_assert_str_eq(res6, check6);
    free(res6);

    char tr7[10] = " \tn\t ";
    char *check7 = "n";
    char *res7 = (char *)my_trim(tr7, MY_NULL);
    ck_assert_str_eq(res7, check7);
    free(res7);

    char tr8[10] = " \tn\t ";
    char *check8 = " \tn\t ";
    char *res8 = (char *)my_trim(tr8, "");
    ck_assert_str_eq(res8, check8);
    free(res8);
}
END_TEST

START_TEST(test_memcmp) {

    char str1[] = "1234567";
    char str2[] = "1231r";
    int n1, n2, n3, n4;
    n1 = my_memcmp(str1, str2, 3);
    n2 = memcmp(str1, str2, 3);
    ck_assert_int_eq(n1, n2);

    char str111[] = "a";
    char str211[] = "cr";
    n3 = my_memcmp(str111, str211, 0);
    n4 = memcmp(str111, str211, 0);
    ck_assert_int_eq(n3, n4);

    char str7[3] = "att";
    char str8[3] = "at";
    n3 = my_memcmp(str7, str8, 2);
    n4 = memcmp(str7, str8, 2);
    ck_assert_int_eq(n3, n4);

    char str9[] = "\n\0";
    char str10[] = "\n";
    n3 = my_memcmp(str9, str10, 2);
    n4 = memcmp(str9, str10, 2);
    ck_assert_int_eq(n3, n4);

    char str13[] = "k \na1";
    char str14[] = "a \na9";
    n3 = my_memcmp(str13, str14, 0);
    n4 = memcmp(str13, str14, 0);
    ck_assert_int_eq(n3, n4);
}
END_TEST

START_TEST(test_strncat) {
    char str1n[1024] = "one two three";
    char str2n[1024] = "four five";
    char str3n[1024] = "one two three";
    char str4n[1024] = "four five";
    strncat(str1n, str2n, 3);
    my_strncat(str3n, str4n, 3);
    ck_assert_str_eq(str1n, str3n);

    char str111[40] = "Hello world\0edd";
    char str112[20] = "123555666";
    char str113[40] = "Hello world\0edss";
    char str114[20] = "123555666";
    strncat(str111, str112, 3);
    my_strncat(str113, str114, 3);
    ck_assert_str_eq(str111, str113);

    char str11[40] = "Hello world\nedd";
    char str12[20] = "123555666";
    char str13[40] = "Hello world\nedd";
    char str14[20] = "123555666";
    strncat(str11, str12, 15);
    my_strncat(str13, str14, 15);
    ck_assert_str_eq(str11, str13);

    char str1[40] = "Hello_world\ned\0 ___d";
    char str2[20] = "123555666";
    char str3[40] = "Hello_world\ned\0 ___d";
    char str4[20] = "123555666";
    strncat(str1, str2, 30);
    my_strncat(str3, str4, 30);
    ck_assert_str_eq(str1, str3);

    char str5[40] = "Hello_world\ned\0 ___d";
    char str6[20] = "_ sdf\0 sdf";
    char str7[40] = "Hello_world\ned\0 ___d";
    char str8[20] = "_ sdf\0 sdf";
    strncat(str5, str6, 30);
    my_strncat(str7, str8, 30);
    ck_assert_str_eq(str5, str7);
}
END_TEST

START_TEST(test_strncpy) {
    char str1[1024] = "one two three";
    char str2[1024] = "four five";
    char str3[1024] = "one two three";
    char str4[1024] = "four five";
    strncpy(str1, str2, 4);
    my_strncpy(str3, str4, 4);
    ck_assert_str_eq(str1, str3);

    char s1[1024] = " \n\0";
    char s2[1024] = "123456789abcdef";
    char s3[1024] = " \n\0";
    char s4[1024] = "123456789abcdef";
    strncpy(s1, s2, 17);
    my_strncpy(s3, s4, 17);
    ck_assert_str_eq(s1, s3);

    char st1[1024] = "\0";
    char st2[1024] = "123456789abcdef";
    char st3[1024] = " \0";
    char st4[1024] = "123456789abcdef";
    strncpy(st1, st2, 5);
    my_strncpy(st3, st4, 5);
    ck_assert_str_eq(st1, st3);

    char strr1[1024] = "\n";
    char strr2[1024] = "123456789abcdef";
    char strr3[1024] = " \n";
    char strr4[1024] = "123456789abcdef";
    strncpy(strr1, strr2, 5);
    my_strncpy(strr3, strr4, 5);
    ck_assert_str_eq(strr1, strr3);

    char strr5[10] = "\n";
    char strr6[1024] = " ";
    char strr7[10] = "\n";
    char strr8[1024] = " ";
    strncpy(strr5, strr6, 5);
    my_strncpy(strr7, strr8, 5);
    ck_assert_str_eq(strr5, strr7);

    char strr9[10] = "1";
    char strr10[1024] = "\n";
    char strr11[10] = "1";
    char strr12[1024] = "\n";
    strncpy(strr9, strr10, 5);
    my_strncpy(strr11, strr12, 5);
    ck_assert_str_eq(strr9, strr11);

    char strr13[1024] = "";
    char strr14[1024] = "";
    char strr15[1024] = "";
    char strr16[1024] = "";
    strncpy(strr13, strr14, 5);
    my_strncpy(strr15, strr16, 5);
    ck_assert_str_eq(strr13, strr15);

    char strr17[1024] = "";
    char strr18[1024] = "\0";
    char strr19[1024] = "";
    char strr20[1024] = "\0";
    strncpy(strr17, strr18, 1);
    my_strncpy(strr19, strr20, 1);
    ck_assert_str_eq(strr17, strr19);

    char strr21[1024] = "";
    char strr22[1024] = "sdfsdf";
    char strr23[1024] = "";
    char strr24[1024] = "sdfsdf";
    strncpy(strr21, strr22, 0);
    my_strncpy(strr23, strr24, 0);
    ck_assert_str_eq(strr21, strr23);

    char strr25[1024] = "";
    char strr26[1024] = "sdfsdf \n _ St \0 __ r";
    char strr27[1024] = "";
    char strr28[1024] = "sdfsdf \n _ St \0 __ r";
    strncpy(strr25, strr26, 20);
    my_strncpy(strr27, strr28, 20);
    ck_assert_str_eq(strr25, strr27);

    char str10[10] = "";
    char str11[10] = "";
    char str12[5] = "321";
    my_strncpy(str10, str12, 2);
    strncpy(str11, str12, 2);
    ck_assert_str_eq(str10, str11);

    char str13[10] = "4567";
    char str14[10] = "4567";
    char str15[5] = "321";
    my_strncpy(str13, str15, 2);
    strncpy(str14, str15, 2);
    ck_assert_str_eq(str13, str14);

    char str16[10] = "222";
    char str17[10] = "222";
    char str18[5] = "321";
    my_strncpy(str16, str18, 2);
    strncpy(str17, str18, 2);
    ck_assert_str_eq(str16, str17);

    char str19[10] = "";
    char str20[10] = "";
    char str21[5] = "";
    my_strncpy(str19, str21, 2);
    strncpy(str20, str21, 2);
    ck_assert_str_eq(str19, str20);

    char dst1[] = "abcdef1";
    char dst2[] = "abcdef1";
    char src2[] = "123\n";
    strncpy(dst1, src2, 5);
    my_strncpy(dst2, src2, 5);
    ck_assert_str_eq(dst1, dst2);

    char dst3[] = "abcdef1";
    char dst4[] = "abcdef1";
    char src3[] = "123\n";
    char src4[] = "123\n";
    strncpy(dst3, src3, 4);
    my_strncpy(dst4, src4, 4);
    ck_assert_str_eq(dst3, dst4);
}
END_TEST

START_TEST(test_strrchr) {
    char strq[] = "abaabjdfkdfkldfgb1234";

    char *c1 = my_strrchr(strq, 'b');
    char *c2 = strrchr(strq, 'b');
    ck_assert_ptr_eq(c1, c2);

    c1 = my_strrchr(strq, 'd');
    c2 = strrchr(strq, 'd');
    ck_assert_ptr_eq(c1, c2);

    c1 = my_strrchr(strq, 'a');
    c2 = strrchr(strq, 'a');
    ck_assert_ptr_eq(c1, c2);

    char strq2[] = "012345673810111231415163";
    c1 = my_strrchr(strq2, '3');
    c2 = strrchr(strq2, '3');
    ck_assert_ptr_eq(c1, c2);

    char strq3[] = "_  \n 3 1 \n 45 1 ";
    c1 = my_strrchr(strq3, '\n');
    c2 = strrchr(strq3, '\n');
    ck_assert_ptr_eq(c1, c2);

    char strq4[] = "_  3 1 \n 45 \0 1 0";
    c1 = my_strrchr(strq4, '0');
    c2 = strrchr(strq4, '0');
    ck_assert_ptr_eq(c1, c2);

    char strq5[] = "_  3 1 \n 45 \0 1 0";
    c1 = my_strrchr(strq5, ' ');
    c2 = strrchr(strq5, ' ');
    ck_assert_ptr_eq(c1, c2);

    char strq6[] = "123";
    c1 = my_strrchr(strq6, '9');
    c2 = strrchr(strq6, '9');
    ck_assert_ptr_eq(c1, c2);

    char strq7[] = "2+2=4=4+2+2";
    c1 = my_strrchr(strq7, '+');
    c2 = strrchr(strq7, '+');
    ck_assert_ptr_eq(c1, c2);

    char strq8[] = "";
    c1 = my_strrchr(strq8, 'a');
    c2 = strrchr(strq8, 'a');
    ck_assert_ptr_eq(c1, c2);
}
END_TEST

START_TEST(memmove_test) {
    // test copy n characters from str2 to str1
    char str1[] = "111";
    char str2[] = "222333";
    char str3[] = "111";
    char str4[] = "222333";
    char *s1 = memmove(str1, str2, 3);
    char *my_1 = my_memmove(str3, str4, 3);
    ck_assert_str_eq(s1, my_1);

    // test dest str is same src str &src < &dest
    char dest1[] = "0123456789";
    char dest2[] = "0123456789";
    char *s2 = memmove(&dest1[3], dest1, 5);
    char *my_2 = my_memmove(&dest2[3], dest2, 5);
    ck_assert_str_eq(s2, my_2);

    // test dest str is same src str &dest < &src
    char dest3[] = "0123456789";
    char dest4[] = "0123456789";
    char *s3 = memmove(dest3, &dest3[3], 5);
    char *my_3 = my_memmove(dest4, &dest4[3], 5);
    ck_assert_str_eq(s3, my_3);

    char dest8[] = "s t:\nri,nHg \n";
    char src8[] = "1Strings\0";
    char *s6 = memmove(dest8, src8, 9);
    char *my_6 = my_memmove(dest8, src8, 9);
    ck_assert_str_eq(s6, my_6);

    char *dest11 = "Str \n0/ .,J ";
    char *src11 = " \n";
    char *s8 = memmove(&dest11, &src11, 5);
    char *my_8 = my_memmove(&dest11, &src11, 5);
    ck_assert_str_eq(s8, my_8);

    char *dest12 = "Str \n0/ .,J ";
    char *src12 = " \n";
    char *s9 = memmove(&dest12, (src12 + 3), 5);
    char *my_9 = my_memmove(&dest12, (src12 + 3), 5);
    ck_assert_str_eq(s9, my_9);

    char dest14[4] = "";
    char src14[] = "abcd";
    char *s11 = memmove(&dest14, &src14, 4);
    char *my_11 = my_memmove(&dest14, &src14, 4);
    ck_assert_str_eq(s11, my_11);

    char dest15[20] = "1234567";
    char dest16[20] = "1234567";
    char *s12 = memmove(&dest15[5], &dest15[2], 4);
    char *my_12 = my_memmove(&dest16[5], &dest16[2], 4);
    ck_assert_str_eq(s12, my_12);

    char *dest19 = (char *)calloc(100, sizeof(char));
    char src19[] = "1234567";
    char *dest20 = (char *)calloc(100, sizeof(char));
    char src20[] = "1234567";
    char *s14 = memmove(dest19, src19, 7);
    char *my_14 = my_memmove(dest20, src20, 7);
    ck_assert_str_eq(s14, my_14);
    free(dest19);
    free(dest20);
}
END_TEST

START_TEST(strcmp_test) {
    char str1[] = " abc";
    char str2[] = "abc";
    int s1 = strcmp(str1, str2);
    int my_1 = my_strcmp(str1, str2);
    ck_assert_int_eq(s1, my_1);

    char str5[] = "tab";
    char str6[] = "ab";
    int s3 = strcmp(str5, str6);
    int my_3 = my_strcmp(str5, str6);
    ck_assert_int_eq(s3, my_3);

    char str7[] = "ba";
    char str8[] = "uba";
    int s4 = strcmp(str7, str8);
    int my_4 = my_strcmp(str7, str8);
    ck_assert_int_eq(s4, my_4);
}
END_TEST

START_TEST(strstr_test) {
    // test empty str2
    char str3[] = "gbnabc";
    char str4[] = "";
    ck_assert_ptr_eq(strstr(str3, str4), my_strstr(str3, str4));
    ck_assert_str_eq(strstr(str3, str4), my_strstr(str3, str4));
    // test str has str2
    char str5[] = "gbnabcgbg";
    char str6[] = "abc";
    ck_assert_ptr_eq(strstr(str5, str6), my_strstr(str5, str6));
    ck_assert_str_eq(strstr(str5, str6), my_strstr(str5, str6));
    // test str has not full str2 and function not including the terminating
    // null characters
    char str7[] = "gbngbgab";
    char str8[] = "abc";
    ck_assert_ptr_eq(strstr(str7, str8), my_strstr(str7, str8));
    char str9[] = "";
    char str10[] = "";
    ck_assert_ptr_eq(strstr(str9, str10), my_strstr(str9, str10));
    char str11[] = " ";
    char str12[] = " ";
    ck_assert_ptr_eq(strstr(str11, str12), my_strstr(str11, str12));
    char str13[] = " Str \n0/ .,J  ";
    char str14[] = " \n";
    ck_assert_ptr_eq(strstr(str13, str14), my_strstr(str13, str14));
    ck_assert_str_eq(strstr(str13, str14), my_strstr(str13, str14));
    char str15[] = "";
    char str16[] = "\0";
    ck_assert_ptr_eq(strstr(str15, str16), my_strstr(str15, str16));
    ck_assert_str_eq(strstr(str15, str16), my_strstr(str15, str16));
    char str17[] = "";
    char str18[] = "\n";
    ck_assert_ptr_eq(strstr(str17, str18), my_strstr(str17, str18));
    char str19[] = "\0____";
    char str20[] = "_";
    ck_assert_ptr_eq(strstr(str19, str20), my_strstr(str19, str20));
}
END_TEST

START_TEST(test_strspn) {
    int spn = strspn("0123456789", "210");
    int tmp_spn = my_strspn("0123456789", "210");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("0123456789", "0");
    tmp_spn = my_strspn("0123456789", "0");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("0", "0");
    tmp_spn = my_strspn("0", "0");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("0", "1231");
    tmp_spn = my_strspn("0", "1231");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("\n", "\n\0");
    tmp_spn = my_strspn("\n", "\n\0");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("Strings\0", "s t:ri,nHg \n");
    tmp_spn = my_strspn("Strings\0", "s t:ri,nHg \n");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("Str \n0/ .,J ", ".,J");
    tmp_spn = my_strspn("Str \n0/ .,J ", ".,J");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("123456789012", "0");
    tmp_spn = my_strspn("123456789012", "0");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("312456789012", "210");
    tmp_spn = my_strspn("312456789012", "210");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("301245678912", "210");
    tmp_spn = my_strspn("301245678912", "210");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("012345678912", "210");
    tmp_spn = my_strspn("012345678912", "210");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn(" \n\0", "\n\0");
    tmp_spn = my_strspn(" \n\0", "\n\0");
    ck_assert_int_eq(spn, tmp_spn);

    spn = strspn("Strings\0", "S t:ri,nHg \n");
    tmp_spn = my_strspn("Strings\0", "S t:ri,nHg \n");
    ck_assert_int_eq(spn, tmp_spn);

    char *str1 = calloc(sizeof(char), 5);
    spn = strspn(str1, "\0");
    tmp_spn = my_strspn(str1, "\0");
    ck_assert_int_eq(spn, tmp_spn);
    free(str1);

    char *str2 = calloc(5, sizeof(char));
    spn = strspn(str2, "\0");
    tmp_spn = my_strspn(str2, "\0");
    ck_assert_int_eq(spn, tmp_spn);
    free(str2);

    char *str4 = calloc(5, sizeof(char));
    str4[0] = '\0';
    spn = strspn(str4, "\0");
    tmp_spn = my_strspn(str4, "\0");
    ck_assert_int_eq(spn, tmp_spn);
    free(str4);

    char *str5 = calloc(5, sizeof(char));
    str5[0] = '\t';
    spn = strspn(str5, "\t");
    tmp_spn = my_strspn(str5, "\t");
    ck_assert_int_eq(spn, tmp_spn);
    free(str5);

    char str6[] = "";
    spn = strspn(str6, "\0");
    tmp_spn = my_strspn(str6, "\0");
    ck_assert_int_eq(spn, tmp_spn);

    char str7[4] = "";
    spn = strspn(str7, "\0");
    tmp_spn = my_strspn(str7, "\0");
    ck_assert_int_eq(spn, tmp_spn);

    char str8[4] = "dfk\0";
    spn = strspn(str8, "kdf\0");
    tmp_spn = my_strspn(str8, "kdf\0");
    ck_assert_int_eq(spn, tmp_spn);

    char str9[4] = "d\0fk";
    spn = strspn(str9, "Kdf");
    tmp_spn = my_strspn(str9, "Kdf");
    ck_assert_int_eq(spn, tmp_spn);

    char str10[4] = "dk\0f";
    spn = strspn(str10, "Kdf");
    tmp_spn = my_strspn(str10, "Kdf");
    ck_assert_int_eq(spn, tmp_spn);
}
END_TEST

START_TEST(test_strcspn) {
    int cspn = strcspn("1234", "34");
    int tmp_cspn = my_strcspn("1234", "34");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("0123456789", "0");
    tmp_cspn = my_strcspn("0123456789", "0");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("0", "0");
    tmp_cspn = my_strcspn("0", "0");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("0", "1231");
    tmp_cspn = my_strcspn("0", "1231");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("\n0", "\n\0");
    tmp_cspn = my_strcspn("\n0", "\n\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("\n0", "0");
    tmp_cspn = my_strcspn("\n0", "0");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("Hello world\n\0", "Hello world\n\0");
    tmp_cspn = my_strcspn("Hello world\n\0", "Hello world\n\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("Strings\0", "s t:ri,nHg \n");
    tmp_cspn = my_strcspn("Strings\0", "s t:ri,nHg \n");
    ck_assert_int_eq(cspn, tmp_cspn);

    char str[] = "LOST: 4-8-15-16-23-42";
    char keys[] = "7";
    cspn = strcspn(str, keys);
    tmp_cspn = my_strcspn(str, keys);
    ck_assert_int_eq(cspn, tmp_cspn);

    cspn = strcspn("Hello\n\tworld\0", "\0");
    tmp_cspn = my_strcspn("Hello\n\tworld\0", "\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    char str1[3] = "bb";
    cspn = strcspn(str1, "\0");
    tmp_cspn = my_strcspn(str1, "\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    char str2[3] = "bb";
    cspn = strcspn(str2, "\0");
    tmp_cspn = my_strcspn(str2, "\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    char str3[4] = "bb";
    str3[2] = 'b';
    cspn = strcspn(str3, "\0");
    tmp_cspn = my_strcspn(str3, "\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    char str4[4] = "bb";
    str4[3] = 'b';
    cspn = strcspn(str4, "\0");
    tmp_cspn = my_strcspn(str4, "\0");
    ck_assert_int_eq(cspn, tmp_cspn);

    char *str5 = calloc(5, sizeof(char));
    str5[0] = 'b';
    str5[1] = 'b';
    str5[2] = '\n';
    cspn = strcspn(str5, "\0");
    tmp_cspn = my_strcspn(str5, "\0");
    ck_assert_int_eq(cspn, tmp_cspn);
    free(str5);

    char *str6 = calloc(5, sizeof(char));
    str6[0] = 'b';
    str6[1] = 'b';
    str6[3] = '\n';
    cspn = strcspn(str6, "\0");
    tmp_cspn = my_strcspn(str6, "\0");
    ck_assert_int_eq(cspn, tmp_cspn);
    free(str6);

    char *str7 = calloc(5, sizeof(char));
    str7[0] = 'b';
    str7[1] = 'b';
    str7[3] = '\n';
    cspn = strcspn(str7, "\n");
    tmp_cspn = my_strcspn(str7, "\n");
    ck_assert_int_eq(cspn, tmp_cspn);
    free(str7);
}
END_TEST

START_TEST(test_strchr) {
    char *rchr = strchr("123456789", '7');
    char *tmp_rchr = my_strchr("123456789", '7');
    ck_assert_str_eq(rchr, tmp_rchr);

    char *rchr3 = strchr("abcv", 'b');
    char *tmp_rchr3 = my_strchr("abcv", 'b');
    ck_assert_str_eq(rchr3, tmp_rchr3);

    char *rchr4 = strchr("s t:ri,nHg \n /0", ' ');
    char *tmp_rchr4 = my_strchr("s t:ri,nHg \n /0", ' ');
    ck_assert_str_eq(rchr4, tmp_rchr4);

    char *rchr5 = strchr("-=*   ..1", '.');
    char *tmp_rchr5 = my_strchr("-=*   ..1", '.');
    ck_assert_str_eq(rchr5, tmp_rchr5);

    char *rchr6 = strchr("s t:ri,nHg \n /0", '\n');
    char *tmp_rchr6 = my_strchr("s t:ri,nHg \n /0", '\n');
    ck_assert_str_eq(rchr6, tmp_rchr6);

    char string1[] = "abcd\tefg\niklm";
    char *rchr7 = strchr(string1, '\n');
    char *tmp_rchr7 = my_strchr(string1, '\n');
    ck_assert_str_eq(rchr7, tmp_rchr7);
    ck_assert_ptr_eq(rchr7, tmp_rchr7);

    char string3[] = "";
    char *rchr9 = strchr(string3, '\0');
    char *tmp_rchr9 = my_strchr(string3, '\0');
    ck_assert_str_eq(rchr9, tmp_rchr9);
    ck_assert_ptr_eq(rchr9, tmp_rchr9);

    char *string6 = (char *)calloc(5, sizeof(char));
    string6[0] = 'b';
    string6[1] = 'b';
    char *rchr12 = strchr(string6, '\0');
    char *tmp_rchr12 = my_strchr(string6, '\0');
    ck_assert_str_eq(rchr12, tmp_rchr12);
    ck_assert_ptr_eq(rchr12, tmp_rchr12);
    free(string6);
}
END_TEST

START_TEST(test_memcpy) {
    char src[11] = "072";
    char dst[11] = "";
    char *memcp = (char *)memcpy(dst, src, 4);
    char *tmp_memcp = (char *)my_memcpy(dst, src, 4);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src2[11] = "124";
    char dst2[11] = "dsfsdfsdf";
    memcp = (char *)memcpy(dst2, src2, 4);
    tmp_memcp = (char *)my_memcpy(dst2, src2, 4);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src3[11] = "";
    char dst3[11] = "dsfsdfsdf";
    memcp = (char *)memcpy(dst3, src3, 4);
    tmp_memcp = (char *)my_memcpy(dst3, src3, 4);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src4[11] = "";
    char dst4[11] = "";
    memcp = (char *)memcpy(dst4, src4, 4);
    tmp_memcp = (char *)my_memcpy(dst4, src4, 4);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src5[11] = " ";
    char dst5[11] = "";
    memcp = (char *)memcpy(dst5, src5, 4);
    tmp_memcp = (char *)my_memcpy(dst5, src5, 4);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src6[11] = "sdfdfg";
    char dst6[11] = "";
    memcp = (char *)memcpy(dst6, src6, 0);
    tmp_memcp = (char *)my_memcpy(dst6, src6, 0);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src7[15] = "s t:ri,nHg \n";
    char dst7[15] = "Hello world\n\0";
    memcp = (char *)memcpy(dst7, src7, 5);
    tmp_memcp = (char *)my_memcpy(dst7, src7, 5);
    ck_assert_str_eq(memcp, tmp_memcp);

    char src8[] = "124";
    char dst8[] = "dsfsdfsdf";
    memcp = (char *)memcpy(dst8, src8, 3);
    tmp_memcp = (char *)my_memcpy(dst8, src8, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst11[] = "dsfsdfsd\0f";
    char src11[] = "123456789";
    memcp = (char *)memcpy(dst11, src11, 3);
    tmp_memcp = (char *)my_memcpy(dst11, src11, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst12[] = "dsfsdfsd\tf";
    char src12[] = "123456789";
    memcp = (char *)memcpy(dst12, src12, 3);
    tmp_memcp = (char *)my_memcpy(dst12, src12, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst13[] = "dsfsdfsd\nf";
    char src13[] = "123456789";
    memcp = (char *)memcpy(dst13, src13, 3);
    tmp_memcp = (char *)my_memcpy(dst13, src13, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst14[] = "d\0sfsdfsdf";
    char src14[] = "123456789";
    memcp = (char *)memcpy(dst14, src14, 3);
    tmp_memcp = (char *)my_memcpy(dst14, src14, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst15[] = "d\tsfsdfsdf";
    char src15[] = "123456789";
    memcp = (char *)memcpy(dst15, src15, 3);
    tmp_memcp = (char *)my_memcpy(dst15, src15, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst16[] = "d\nsfsdfsdf";
    char src16[] = "123456789";
    memcp = (char *)memcpy(dst16, src16, 3);
    tmp_memcp = (char *)my_memcpy(dst16, src16, 3);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst17[] = "d\ts\nf\0sdf\0sdf";
    char src17[] = "123456789";
    memcp = (char *)memcpy(dst17, src17, 6);
    tmp_memcp = (char *)my_memcpy(dst17, src17, 6);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst18[] = "d\0\0\0\0\0\0sdfsdf";
    char src18[] = "123456789";
    memcp = (char *)memcpy(dst18, src18, 6);
    tmp_memcp = (char *)my_memcpy(dst18, src18, 6);
    ck_assert_str_eq(memcp, tmp_memcp);

    char dst19[] = "d\t\n\0    jklfdjsak  ";
    char src19[] = "123456789";
    memcp = (char *)memcpy(dst19, src19, 6);
    tmp_memcp = (char *)my_memcpy(dst19, src19, 6);
    ck_assert_str_eq(memcp, tmp_memcp);
}
END_TEST

START_TEST(strlen_test) {
    // block 1: string in argument
    int tmp = my_strlen("stri ng");
    int std = strlen("stri ng");
    ck_assert_int_eq(tmp, std);

    tmp = my_strlen("s");
    std = strlen("s");
    ck_assert_int_eq(tmp, std);

    tmp = my_strlen("\0");
    std = strlen("\0");
    ck_assert_int_eq(tmp, std);

    tmp = my_strlen("\n");
    std = strlen("\n");
    ck_assert_int_eq(tmp, std);

    tmp = my_strlen("\0\n");
    std = strlen("\0\n");
    ck_assert_int_eq(tmp, std);

    tmp = my_strlen("\0 \n");
    std = strlen("\0 \n");
    ck_assert_int_eq(tmp, std);

    tmp = my_strlen(" \n");
    std = strlen(" \n");
    ck_assert_int_eq(tmp, std);

    std = strlen("!@#$%%^&*");
    tmp = my_strlen("!@#$%%^&*");
    ck_assert_int_eq(tmp, std);

    // block 2: string in array
    char block2_st1[] = "array string";
    tmp = my_strlen(block2_st1);
    std = strlen(block2_st1);
    ck_assert_int_eq(tmp, std);

    char block2_st2[] = "s";
    tmp = my_strlen(block2_st2);
    std = strlen(block2_st2);
    ck_assert_int_eq(tmp, std);

    char *block2_st3 = "\0";
    tmp = my_strlen(block2_st3);
    std = strlen(block2_st3);
    ck_assert_int_eq(tmp, std);

    char block2_st4[] = " \n";
    tmp = my_strlen(block2_st4);
    std = strlen(block2_st4);
    ck_assert_int_eq(tmp, std);

    char block2_st5[] = "\0\n";
    tmp = my_strlen(block2_st5);
    std = strlen(block2_st5);
    ck_assert_int_eq(tmp, std);

    char block2_st6[] = "\0 \n";
    tmp = my_strlen(block2_st6);
    std = strlen(block2_st6);
    ck_assert_int_eq(tmp, std);

    char block2_st7[] = " \n";
    tmp = my_strlen(block2_st7);
    std = strlen(block2_st7);
    ck_assert_int_eq(tmp, std);

    char block2_st8[] = "!@#$%%^&*";
    tmp = my_strlen(block2_st8);
    std = strlen(block2_st8);
    ck_assert_int_eq(tmp, std);

    char block2_st9[] = "\0\0";
    tmp = my_strlen(block2_st9);
    std = strlen(block2_st9);
    ck_assert_int_eq(tmp, std);

    char block2_st10[] = "\0Hel lo\0";
    tmp = my_strlen(block2_st10);
    std = strlen(block2_st10);
    ck_assert_int_eq(tmp, std);

    // block 3: literal string from pointer
    char *block3_st1 = "unmodified string";
    tmp = my_strlen(block3_st1);
    std = strlen(block3_st1);
    ck_assert_int_eq(tmp, std);

    char *block3_st2 = "s";
    tmp = my_strlen(block3_st2);
    std = strlen(block3_st2);
    ck_assert_int_eq(tmp, std);

    char *block3_st3 = "\0";
    tmp = my_strlen(block3_st3);
    std = strlen(block3_st3);
    ck_assert_int_eq(tmp, std);

    char *block3_st4 = "\n";
    tmp = my_strlen(block3_st4);
    std = strlen(block3_st4);
    ck_assert_int_eq(tmp, std);

    char *block3_st5 = "\0\n";
    tmp = my_strlen(block3_st5);
    std = strlen(block3_st5);
    ck_assert_int_eq(tmp, std);

    char *block3_st6 = "\0 \n";
    tmp = my_strlen(block3_st6);
    std = strlen(block3_st6);
    ck_assert_int_eq(tmp, std);

    char *block3_st7 = " \n";
    tmp = my_strlen(block3_st7);
    std = strlen(block3_st7);
    ck_assert_int_eq(tmp, std);

    char *block3_st8 = "!@#$%%^&*";
    tmp = my_strlen(block3_st8);
    std = strlen(block3_st8);
    ck_assert_int_eq(tmp, std);

    // block 4: dynamic memory malloc
    char *block4_st1 = (char *)calloc(1000, sizeof(char));
    put("dynamic m\0", block4_st1, 10);
    tmp = my_strlen(block4_st1);
    std = strlen(block4_st1);
    free(block4_st1);
    ck_assert_int_eq(tmp, std);

    char *block4_st2 = (char *)calloc(1000, sizeof(char));
    put("dynamic mm", block4_st2, 10);
    tmp = my_strlen(block4_st2);
    std = strlen(block4_st2);
    free(block4_st2);
    ck_assert_int_eq(tmp, std);

    char *block4_st3 = (char *)calloc(1000, sizeof(char));
    put("dyn\nam\0ic m", block4_st3, 10);
    tmp = my_strlen(block4_st3);
    std = strlen(block4_st3);
    free(block4_st3);
    ck_assert_int_eq(tmp, std);

    char *block4_st4 = (char *)calloc(100, sizeof(char));
    put("\0", block4_st4, 10);
    tmp = my_strlen(block4_st4);
    std = strlen(block4_st4);
    free(block4_st4);
    ck_assert_int_eq(tmp, std);

    char *block4_st5 = (char *)calloc(100, sizeof(char));
    put("dyn", block4_st5, 10);
    tmp = my_strlen(block4_st5);
    std = strlen(block4_st5);
    free(block4_st5);
    ck_assert_int_eq(tmp, std);

    // block 5: dynamic memory calloc
    char *block5_st1 = (char *)calloc(100, sizeof(char));
    put("dynamic m\0", block5_st1, 10);
    tmp = my_strlen(block5_st1);
    std = strlen(block5_st1);
    free(block5_st1);
    ck_assert_int_eq(tmp, std);

    char *block5_st2 = (char *)calloc(100, sizeof(char));
    put("dynamic mm", block5_st2, 10);
    tmp = my_strlen(block5_st2);
    std = strlen(block5_st2);
    free(block5_st2);
    ck_assert_int_eq(tmp, std);

    char *block5_st3 = (char *)calloc(100, sizeof(char));
    put("dyn\nam\0ic m", block5_st3, 10);
    tmp = my_strlen(block5_st3);
    std = strlen(block5_st3);
    free(block5_st3);
    ck_assert_int_eq(tmp, std);

    char *block5_st4 = (char *)calloc(100, sizeof(char));
    put("\0", block5_st4, 10);
    tmp = my_strlen(block5_st4);
    std = strlen(block5_st4);
    free(block5_st4);
    ck_assert_int_eq(tmp, std);

    char *block5_st5 = (char *)calloc(300, sizeof(char));
    put("dyn", block5_st5, 10);
    tmp = my_strlen(block5_st5);
    std = strlen(block5_st5);
    free(block5_st5);
    ck_assert_int_eq(tmp, std);

    // block 6: add a few test with malloc&calloc
    char *block6_st1 = (char *)calloc(100, sizeof(char));
    tmp = my_strlen(block6_st1);
    std = strlen(block6_st1);
    free(block6_st1);
    ck_assert_int_eq(tmp, std);

    char *block6_st2 = (char *)calloc(110, sizeof(char));
    tmp = my_strlen(block6_st2);
    std = strlen(block6_st2);
    free(block6_st2);
    ck_assert_int_eq(tmp, std);
}
END_TEST

START_TEST(strncmp_test) {
    char arr1[] = "Aror";
    char ars1[] = "Aor";
    int std = strncmp(arr1, ars1, 3);
    int tmp = my_strncmp(arr1, ars1, 3);
    ck_assert_int_eq(tmp, std);

    char arr2[] = "3Aori";
    char ars2[] = "Aori";
    std = strncmp(arr2, ars2, 3);
    tmp = my_strncmp(arr2, ars2, 3);
    ck_assert_int_eq(tmp, std);

    char arr3[] = "tAot";
    char ars3[] = "Aoyu";
    std = strncmp(arr3, ars3, 3);
    tmp = my_strncmp(arr3, ars3, 3);
    ck_assert_int_eq(tmp, std);

    char arr5[] = " \0a\0";
    char ars5[] = "\0a\0";
    std = strncmp(arr5, ars5, 3);
    tmp = my_strncmp(arr5, ars5, 3);
    ck_assert_int_eq(tmp, std);

    char arr6[] = "\na\0";
    char ars6[] = "\na\0";
    std = strncmp(arr6, ars6, 3);
    tmp = my_strncmp(arr6, ars6, 3);
    ck_assert_int_eq(tmp, std);

    char arr7[] = "0\0a\n";
    char ars7[] = "\0a\n";
    std = strncmp(arr7, ars7, 3);
    tmp = my_strncmp(arr7, ars7, 3);
    ck_assert_int_eq(tmp, std);

    char arr11[] = "Aho";
    char ars11[] = "Ao";
    std = strncmp(arr11, ars11, 3);
    tmp = my_strncmp(arr11, ars11, 3);
    ck_assert_int_eq(tmp, std);
}
END_TEST

START_TEST(strtok_test) {
    char s1[] = ".st.ri,ng";
    char s2[] = ".st.ri,ng";

    char *std = strtok(s1, ".,");
    char *tmp = my_strtok(s2, ".,");
    ck_assert_str_eq(std, tmp);

    char *std2 = strtok(NULL, ".,");
    char *my_2 = my_strtok(NULL, ".,");
    ck_assert_str_eq(std2, my_2);

    char *std20 = strtok(NULL, ".,");
    char *my_20 = my_strtok(NULL, ".,");
    ck_assert_str_eq(std20, my_20);

    char *std21 = strtok(NULL, ".,");
    char *my_21 = my_strtok(NULL, ".,");
    ck_assert_ptr_eq(std21, my_21);


    char s3[] = "....s t:ri,nHg \n";
    char s4[] = "....s t:ri,nHg \n";

    char *std3 = strtok(s3, ".,H");
    char *my_3 = my_strtok(s4, ".,H");
    ck_assert_str_eq(std3, my_3);

    char *std4 = strtok(NULL, ".,H");
    char *my_4 = my_strtok(NULL, ".,H");
    ck_assert_str_eq(std4, my_4);

    char *std7 = strtok(NULL, ".,H");
    char *my_7 = my_strtok(NULL, ".,H");
    ck_assert_str_eq(std7, my_7);

    char *std8 = strtok(NULL, ".,H");
    char *my_8 = my_strtok(NULL, ".,H");
    ck_assert_ptr_eq(std8, my_8);


    char s5[] = "s t:r\ni,nH g \n";
    char s6[] = "s t:r\ni,nH g \n";

    char *std5 = strtok(s5, ".,H ");
    char *my_5 = my_strtok(s6, ".,H ");
    ck_assert_str_eq(std5, my_5);

    char *std6 = strtok(NULL, ".,H ");
    char *my_6 = my_strtok(NULL, ".,H ");
    ck_assert_str_eq(std6, my_6);


    char s7[] = ".st.\0ri,ng";
    char s8[] = ".st.\0ri,ng";

    char *std9 = strtok(s7, ".,");
    char *my_9 = my_strtok(s8, ".,");
    ck_assert_str_eq(std9, my_9);

    char *std10 = strtok(NULL, ".,");
    char *my_10 = my_strtok(NULL, ".,");
    ck_assert_ptr_eq(std10, my_10);

    char *std11 = strtok(NULL, ".,");
    char *my_11 = my_strtok(NULL, ".,");
    ck_assert_ptr_eq(std11, my_11);


    char s9[] = "\n";
    char s10[] = "\n";

    char *std12 = strtok(s9, ".,");
    char *my_12 = my_strtok(s10, ".,");
    ck_assert_str_eq(std12, my_12);

    char *std13 = strtok(NULL, ".,");
    char *my_13 = my_strtok(NULL, ".,");
    ck_assert_ptr_eq(std13, my_13);


    char s11[] = ".,.";
    char s12[] = ".,.";

    char *std14 = strtok(s11, ".,");
    char *my_14 = my_strtok(s12, ".,");
    ck_assert_ptr_eq(std14, my_14);

    char s13[] = "";
    char s14[] = "";

    char *std15 = strtok(s13, ".,");
    char *my_15 = my_strtok(s14, ".,");
    ck_assert_ptr_eq(std15, my_15);

    char *s15 = MY_NULL;
    char *s16 = MY_NULL;

    char *std16 = strtok(s15, ".,");
    char *my_16 = my_strtok(s16, ".,");
    ck_assert_ptr_eq(std16, my_16);

    
    char s17[] = "a.\nr";
    char s18[] = "a.\nr";

    char *std17 = strtok(s17, ".,");
    char *my_17 = my_strtok(s18, ".,");
    ck_assert_str_eq(std17, my_17);

    char *std18 = strtok(MY_NULL, ".,");
    char *my_18 = my_strtok(MY_NULL, ".,");
    ck_assert_str_eq(std18, my_18);

    char *std19 = strtok(MY_NULL, ".,");
    char *my_19 = my_strtok(MY_NULL, ".,");
    ck_assert_ptr_eq(std19, my_19);
}
END_TEST

START_TEST(memset_test) {
    char str21[] = "string";
    char str[] = "string";
    memset(str, 'A', 3);
    my_memset(str21, 'A', 3);
    ck_assert_str_eq(str21, str);

    char str21_2[] = "string";
    char str_2[] = "string";
    memset(str_2, 'A', 1);
    my_memset(str21_2, 'A', 1);
    ck_assert_str_eq(str21_2, str_2);

    char str21_3[] = "string";
    char str_3[] = "string";
    memset(str_3, 'A', 6);
    my_memset(str21_3, 'A', 6);
    ck_assert_str_eq(str21_3, str_3);

    char str21_4[] = "Hello world\0";
    char str_4[] = "Hello world\0";
    memset(str_4, 'A', 3);
    my_memset(str21_4, 'A', 3);
    ck_assert_str_eq(str21_4, str_4);

    char str21_5[] = "Hello world\n\0";
    char str_5[] = "Hello world\n\0";
    memset(str_5, 'A', 3);
    my_memset(str21_5, 'A', 3);
    ck_assert_str_eq(str21_5, str_5);

    char str21_6[] = "a\n\0";
    char str_6[] = "a\n\0";
    memset(str_6, 'A', 1);
    my_memset(str21_6, 'A', 1);
    ck_assert_str_eq(str21_6, str_6);

    char str21_7[] = " \n\0";
    char str_7[] = " \n\0";
    memset(str_7, 'A', 1);
    my_memset(str21_7, 'A', 1);
    ck_assert_str_eq(str21_7, str_7);

    char str21_8[] = " \0";
    char str_8[] = " \0";
    memset(str_8, 'A', 1);
    my_memset(str21_8, 'A', 1);
    ck_assert_str_eq(str21_8, str_8);

    char str21_9[] = "\n\0";
    char str_9[] = "\n\0";
    memset(str_9, 'A', 1);
    my_memset(str21_9, 'A', 1);
    ck_assert_str_eq(str21_9, str_9);

    char str21_10[] = "\0";
    char str_10[] = "\0";
    memset(str_10, 'A', 1);
    my_memset(str21_10, 'A', 1);
    ck_assert_str_eq(str21_10, str_10);

    char str21_11[] = "abc";
    char str_11[] = "abc";
    memset(str_11, 'A', 3);
    my_memset(str21_11, 'A', 3);
    ck_assert_str_eq(str21_11, str_11);

    char str21_12[] = "abc\n\0";
    char str_12[] = "abc\n\0";
    memset(str_12, 'A', 4);
    my_memset(str21_12, 'A', 4);
    ck_assert_str_eq(str21_12, str_12);

    char str21_15[] = "abc";
    char str_15[] = "abc";
    memset(str_15, 81, 1);
    my_memset(str21_15, 81, 1);
    ck_assert_str_eq(str21_15, str_15);

    char str21_16[] = "abc";
    char str_16[] = "abc";
    char c = 'Q';
    memset(str_16, c, 1);
    my_memset(str21_16, c, 1);
    ck_assert_str_eq(str21_16, str_16);

    char str21_17[] = "abc";
    char str_17[] = "abc";
    int i = -81;
    memset(str_17, i, 1);
    my_memset(str21_17, i, 1);
    ck_assert_str_eq(str21_17, str_17);

    char *str_18 = (char *)calloc(sizeof(char), 5);
    char *str21_18 = (char *)calloc(sizeof(char), 5);
    str_18[1] = 'a';
    str21_18[1] = 'a';
    str_18[2] = 'b';
    str21_18[2] = 'b';
    str_18[3] = 'c';
    str21_18[3] = 'c';
    int ii = 81;
    memset(str_18, ii, 2);
    my_memset(str21_18, ii, 2);
    ck_assert_str_eq(str21_18, str_18);
    free(str_18);
    free(str21_18);
}
END_TEST

void put(const char *value, char *array, my_size_t size) {
    for (my_size_t i = 0; i < size; i++) {
        array[i] = value[i];
    }
}

Suite *my_str_suite(void) {
    Suite *suite = suite_create("Strings");
    TCase *tcase_core = tcase_create("Equelity");
    tcase_add_test(tcase_core, test_memchr);
    tcase_add_test(tcase_core, test_strcat);
    tcase_add_test(tcase_core, test_strcpy);
    tcase_add_test(tcase_core, test_strpbrk);
    tcase_add_test(tcase_core, test_memcmp);
    tcase_add_test(tcase_core, test_strncat);
    tcase_add_test(tcase_core, test_strncpy);
    tcase_add_test(tcase_core, test_strrchr);
    tcase_add_test(tcase_core, memmove_test);
    tcase_add_test(tcase_core, strcmp_test);
    tcase_add_test(tcase_core, strstr_test);
    tcase_add_test(tcase_core, test_strspn);
    tcase_add_test(tcase_core, test_strcspn);
    tcase_add_test(tcase_core, test_strchr);
    tcase_add_test(tcase_core, test_memcpy);
    tcase_add_test(tcase_core, strlen_test);
    tcase_add_test(tcase_core, memset_test);
    tcase_add_test(tcase_core, strncmp_test);
    tcase_add_test(tcase_core, strtok_test);
    tcase_add_test(tcase_core, test_lower);
    tcase_add_test(tcase_core, test_upper);
    tcase_add_test(tcase_core, test_insert);
    tcase_add_test(tcase_core, test_trim);
    suite_add_tcase(suite, tcase_core);
    return suite;
}

int main(void) {
    Suite *suite = my_str_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

/*
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
ʾ�� 1:

����: "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:

����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:

����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
*/
#include <iostream>
#include <ctime>
#include "List.h"

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int  size= s.size(), i = 0, j, k, max = 0;
    size = s.size();
    for (j = 0; j < size; j++) {
        for (k = i; k < j; k++)
            if (s[k] == s[j]) {
                i = k + 1;
                break;
            }
        if (j - i + 1 > max)
            max = j - i + 1;
    }
    return max;
}


int main()
{
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s1)<< endl;
    cout << lengthOfLongestSubstring(s2) << endl;
    cout << lengthOfLongestSubstring(s2) << endl;
	return 0;
}

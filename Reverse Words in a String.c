/**
 *Given an input string, reverse the string word by word.

 *For example,
 *Given s = "the sky is blue",
 *return "blue is sky the".

 *Update (2015-02-12):
 *For C programmers: Try to solve it in-place in O(1) space.

 *Clarification:
 *What constitutes a word?
 *A sequence of non-space characters constitutes a word.
 *Could the input string contain leading or trailing spaces?
 *Yes. However, your reversed string should not contain leading or trailing spaces.
 *How about multiple spaces between two words?
 *Reduce them to a single space in the reversed string.
 */
/**
 *根据网上的思路，先翻转整个句子，再以空格为分隔符翻转每个单词，最后得到的就是结果
 *本例又加入对空格的判断，描述如上。
 */
void reverseWord(char *st, char *ed)
{
    if (st==NULL || ed==NULL || st==ed)
        return;
    while(st < --ed) {
        char ch = *st;
        *st = *ed;
        *ed = ch;
        st ++;
    }
}

void reverseWords(char *s) {
    if (NULL == s)
        return;
    reverseWord(s, s+strlen(s));
    char *st = s;
    char *ed = s;
    while (*ed != '\0') {
        if (*ed != ' ') {
            ed ++;
        } else {
            reverseWord(st, ed);
            st = ++ed;
        }
    }   // while
    reverseWord(st, ed);
    
    /* 去除句子左边空格 */
    char *cur = s;
    while (*s == ' ') {
        s++;
    }
    bool sp = false;
    while (*s != '\0') {
        if (*s != ' ') {
            *cur++ = *s;
            sp = false;
        }
        /* 对于两个单词间有多个空格，只保留一个*/
        if (*s == ' ' && !sp) {  
            *cur++ = *s;
            sp = true;
        }
        s ++;
    }
    /* 如果末尾包含空格*/
    if (sp) {  
        *cur--;
    }
    *cur = '\0';
}

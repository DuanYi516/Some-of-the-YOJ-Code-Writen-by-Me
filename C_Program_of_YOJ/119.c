#include <stdio.h>
#include <string.h>
void f(char s[], int l, int r)
{
    //在此补充代码
    char c;
    if(r>l){
        c=s[r];
        s[r]=s[l];
        s[l]=c;
        f(s,l+1,r-1);
    }
}

int main(){

    char s[10001]="nxqrzwbnqnnozawktlxxnyfqdhlsiaixrzplwxkukjrxveywsoftoklcclaqnjxldjtxqbiwdowubkmkktuwbleqqwxdeyfvfylnqdyyydjqhermrythjdrhcjprgqqqnhkgsiqhezhmvqnqiivokgibsrmqlrrvhicwcslqqyxostnwotfawtnnoytktbkraeyiuwmlwqobpaznuwipwgonhnoqcyyaxvbtxlhloapmsbgqagpwyemhujyazvtvkguwoekotbvvbiyjmpzydvqyrovspsujjmxcrdlmiefulvowtmvttxqmtpryoxghqlyxmcyxdkfdgcehammicuwojbhggbrknjyapwrjhvqodmehviqmzctwbpovmmxyacznvzaroiakyridewafpysorprxwsaiqyholluxfoibljqdevynknlxaazauywhkwopvommpvgnhnabykprgvuzvvfyoyzucdwsewyhswlwbmgcvllwshzvmcsdqmrcmoyoetdicvvvbrsuzftqgkzzwcoimtcwotoxtvecqdymfkcomzqmwjahyfbzsfsyuxotafrhhtpocccxhbpcfgvrmckdnimrijfgfavpftckmmrtfqrbwjmywsxtssxqtitknpirnxnplcnhohfhryiorqrmwqdzdunosnywhphkiufcvdwxaefwwxokoutehvhgkcfcyprpkivftmvkuyxrdzpmbmpcsboieyff";
    //scanf("%s", s);
    f(s,0,strlen(s)-1);
    printf("%s",s);
    return 0;
}
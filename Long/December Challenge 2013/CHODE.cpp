//Md. Khairullah Gaurab
//CSE, SUST
//20th Batch
//gaurab.cse.sust@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;
int F[200];

bool comp(char a, char b)
{
	if(F[(int)a]!=F[(int)b]) return F[(int)a]<F[(int)b];
	return a<b;
}

int main(int argc, char const *argv[])
{
	//ios::sync_with_stdio(false);
	int test;
	string  aux, res;
	char frq[100];
	char cypher[250000];
	map<char, int> mp;
	cin>>test;
	getchar();
	
	while(test--)
	{
		res.clear();
		mp.clear();
		aux.clear();
		gets(frq);
		gets(cypher);
		memset(F,0,sizeof(F));
		for(int i=0; i<26; i++) aux+='a'+i;
		int len =  (int)strlen(cypher);
		for (int i = 0; i <len; ++i)
		{
			if((cypher[i]>='a' and cypher[i]<='z') or
				(cypher[i]>='A' and cypher[i]<='Z'))
				F[(int)tolower(cypher[i])]++;
		}
		sort(aux.begin(),aux.end(),comp);
		for (int i = 0; i < 26; ++i)
		{
			mp[(int)aux[i]] = frq[i];
		}
		for (int i = 0; i <len; ++i)
		{
			
			if((cypher[i]>='a' and cypher[i]<='z') or
				(cypher[i]>='A' and cypher[i]<='Z'))
			{
				if(tolower(cypher[i])==cypher[i])
					printf("%c",mp[(int)cypher[i]]);
				else printf("%c",toupper(mp[(int)tolower(cypher[i])]));
			}
			else printf("%c", cypher[i]);
			
		}
		printf("\n");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

FILE* optimized;

void optimize(char *s)
{
	//printf ("Splitting string \"%s\" into tokens:\n",s);
	char *end_str;
	char *token =strtok_r(s, "\n", &end_str);
	bool prev=false;
	while (token != NULL)
	{
		char *end_token,*reg1,*reg2,*reg3,*reg4;
		printf("%s\n", token);
		char *saved=(char*)malloc(sizeof(char) * (strlen(token)+1));
		strcpy(saved,token);

		char *token2 = strtok_r(token, " ", &end_token);
		printf("%s\n", token2);
		if(!strcmp(token2,"mov"))
		{
			printf("Mov found = %s\n", token2);
			reg3 = strtok_r(NULL, ",", &end_token);
			reg4 = end_token;
			printf("Reg3 = %s Reg4 = %s\n\n", reg3,reg4);
			if(prev && !strcmp(reg1,reg4) &&!strcmp(reg2,reg3))
			{
				printf("Match found\n");
				fprintf(optimized,"mov %s,%s\n",reg1,reg2);
				prev=false;
			}
			else
			{
				//cout<<"####1"<<endl;
				if(prev){
				fprintf(optimized,"mov %s,%s\n",reg1,reg2);
				}
                //cout<<"####2"<<endl;
				prev=true;
                reg1=reg3;
                reg2=reg4;
				//prev=false;

			}


		}
        else {
                 if(prev)
                 {
                    fprintf(optimized,"mov %s,%s\n",reg1,reg2);
                 }
                prev=false;
                fprintf(optimized,"%s\n",saved);
            }
		token = strtok_r(NULL, "\n", &end_str);
	}
}

int main()
{
    char* buffer = 0;
    long length;
    FILE * f = fopen ("inopti.txt", "rb"); //was "rb"

    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = (char*)malloc ((length+1)*sizeof(char));
      if (buffer)
      {
        fread (buffer, sizeof(char), length, f);
      }
      fclose (f);
    }
    buffer[length] = '\0';


    char *copyb=(char*)malloc(sizeof(char) * (strlen(buffer)+1));
		strcpy(copyb,buffer);
    printf("%s\n\n",copyb);

    optimized= fopen("optimized.asm","w");
    optimize(copyb);



}

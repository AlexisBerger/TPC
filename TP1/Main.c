#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char chiffreVigenere(const char lettre, const char cle);
char* chaineVigenere(const char* chaine, const char* cle);
short isUp(char l);
char* checkKey(const char* string);
char decryptCleChar(char lettre);
char* decryptCle(char* cle);

int main(void) {
	char* choix = malloc(3 * sizeof(char));
	char* message = malloc(255*sizeof(char));
	char* cle = malloc(255 * sizeof(char));
	char* res = malloc(255 * sizeof(char));
	int choixI = 0;

		printf("Saisir le message :  \n> ");
		//scanf("%253[^\n]", message);
		fgets(message, 255, stdin);
		message[strlen(message)-1] = '\0';
		printf("Saisir la cle :  \n> ");
		//scanf("%253[^\n]", cle);
		fgets(cle, 255, stdin);
		cle[strlen(cle) - 1] = '\0';

		do
		{
			printf("Choix :\n");
			printf("1 - Cryptage\n");
			printf("2 - Decryptage\n");
			printf("> ");
			fgets(choix, 3, stdin);
			choix[strlen(choix) - 1] = '\0';
			choixI = atoi(choix);
		} while (choixI > 2 || choixI < 1);
		
		
		switch (choixI)
		{
		case 1:
			res = chaineVigenere(message, cle);
			break;
		case 2:
			res = chaineVigenere(message, decryptCle(checkKey(cle)));
			break;
		default:
			break;
		}


	printf("Resultat : %s\n", res);
	

	system("PAUSE");

	return 0;
}

char chiffreVigenere(const char lettre, const char cle) {
	char l;
	switch (isUp(lettre))
	{
	case 1:
		l = lettre;
		break;
	case 0:
		l = toupper(lettre);
		break;
	case -1:
	default:
		return -1;
		break;
	}
	return (((l - 'A') + (toupper(cle) - 'A')) % 26)+'A';
}

char decryptCleChar(char lettre) {
	return (('A' + 26 - lettre) % 26 + 'A');
}

char* decryptCle(char* cle) {
	char* resultat = malloc((strlen(cle) + 1)*sizeof(char));
	size_t i;
	for (i = 0; i < strlen(cle); i++)
	{
		resultat[i] = decryptCleChar(cle[i]);
	}
	resultat[i] = '\0';
	return resultat;
}

short isUp(char l) {
	if (l >= 'A' && l <= 'Z')
		return 1;
	else if (l >= 'a' && l <= 'z')
		return 0;
	else
		return -1;
}

char* checkKey(const char* string) {
	char* resultat = malloc((strlen(string) + 1)*sizeof(char));
	unsigned int j = 0;
	size_t i;
	for (i = 0; i < strlen(string); i++)
	{
		if (string[i] != ' ') {
			switch (isUp(string[i]))
			{
			case 1:
				resultat[j] = string[i];
				break;
			case 0:
				resultat[j] = toupper(string[i]);
				break;
			case -1:
			default:
				return " ";
				break;
			}
			
			j++;
		}
	}
	resultat[j] = '\0';
	size_t taille = strlen(resultat) + 1;
	char* retourne = malloc(taille*sizeof(char));
	strcpy_s(retourne, taille, resultat);
	return retourne;
}

char* chaineVigenere(const char* chaine, const char* cle) {
	printf("Texte :\t%s\n", chaine);
	char* secret = checkKey(cle);
	if (*secret == " ")
		return "Seuls les caracteres de a-z et A-Z sont acceptee\n";
	printf("Cle :\t%s\n", secret);
	char* resultat = malloc((strlen(chaine) + 1)*sizeof(char));
	size_t i;
	unsigned int j = 0;
	for (i = 0; i < strlen(chaine); i++)
	{
		if (chaine[i] == ' ')
			resultat[i] = ' ';
		else 
		{
			if ((resultat[i] = chiffreVigenere(chaine[i], secret[j%strlen(secret)])) == -1)
				return "Seuls les caracteres de a-z et A-Z sont acceptee\n";
			j++;
		}
	}
	resultat[i] = '\0';
	return resultat;
}
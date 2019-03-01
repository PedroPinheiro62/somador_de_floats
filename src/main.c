/* Somador de Floats
 *
 * Este programa recebera uma serie de caracteres e indentifica nela todos os numeros. Esses numeros sao somados
 * e o resultado dessa soma eh exibido pelo programa. O resultado eh dado com o minimo de casas decimais possivel.
 * Numeros grudados em strings ou em outros numeros nao sao adicionados ao resultado.
 */

#include <stdio.h>

int main() {
	
	//Inicializacao de variaveis para o calculo da soma e da variavel c que ira percorrer a string recebida.
	float globalCounter, intCounter, decCounter, multiplier;	
	char c;
	
	//Inicializamos o resultado como 0.
	globalCounter = 0.0;
	
	//Pegamos o primeiro caractere da string.
  	scanf("%c", &c);

	// Percorremos a serie de caracteres um a um checando seus valores na tabela ASCII para saber o que representam.
  	while (c != '\n'){	
		//Checamos se o caractere é uma letra ou algo que não seja um espaço ou um numero.
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) || ((c != 32) && (c < 48 || c > 57))){	
			//Olhamos o proximo caractere para saber se eh um numero. Nesse caso esse numero eh desprezado.
			scanf("%c", &c);
			while (c >= 48 && c <= 57){
				scanf("%c", &c);
			}
		}
		
		//Se o caractere for um numero nao grudado, começamos a contabilizar a parte inteira desse numero.
		else if(c >= 48 && c <= 57){
			intCounter = (c - 48);			
			scanf("%c", &c);			

			//Calculo da parte inteira do numero.
			while (c >= 48 && c <= 57){
				intCounter = (intCounter*10 + c - 48);				
				scanf("%c", &c);
			}
			
			//Se a parte inteira do numero eh seguida de um espaço ou do fim da string, o adicionamos ao resultado final.
			if (c == 32 || c == '\n'){
				globalCounter = globalCounter + intCounter;
			}	

			//Se o numero eh seguido de um ponto ou uma virgula, ele pode ser um numero com casas decimais.		
   			else if (c == 46 || c == 44){
				multiplier = 0;
				scanf("%c", &c);
				
				//Contabilizamos então a parte decimal do numero se presente.
				if(c >= 48 && c <= 57){
					multiplier = 10;
					decCounter = (c - 48);
					scanf("%c", &c);
					
					//Calculo da parte decimal do numero.
					while(c >= 48 && c <= 57){
						multiplier = multiplier*10;
						decCounter = (decCounter*10 + c - 48);
						scanf("%c", &c);
					}

					//Se o numero eh seguida de um espaço ou fim da string, o adicionamos ao resultado final.
					if (c == 32 || c == '\n'){
						globalCounter = globalCounter + intCounter + (decCounter/multiplier);
					}
				}
			}
		}
		//Se o caractere avaliado trata-se de um espaço, apenas passamos ao proximo caractere da string.
		else {
			scanf("%c", &c);
		}
  	} 

	//Impressao do resultado final da soma dos numeros presentes na string com o numero minimo de casas decimais.
  	printf("%g\n", globalCounter);
  	return 0;
}

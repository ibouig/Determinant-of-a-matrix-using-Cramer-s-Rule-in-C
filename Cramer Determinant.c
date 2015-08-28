/********PROGRAMME CALCULATEUR DE DETERMINANT*********/
/*************CRAMER BY BOUIGHERDAINE-2012************/

//created & concepted by Said Bouigherdaine --ibouig--
//ESTA- 1ére Génie informatique promo 2012


// Déclaration des Bibliothéques
#include<stdio.h>
#include<stdlib.h>
//Déclaration des fonctions 

 /*la fonctionne COPYMAT qui permet de copier la 
sous_matrice en référence de pos:position par colonne*/

void copymat(float**tab,float**copytab,int dim,int pos)
{
	int a;
	int b;
	int k=0;
	
	 for (b=0;b<dim;b++)
	 {
		 
		 if (!(b==pos))
		 {
			
			 for (a=1;a<dim;a++) 
			 {
				 copytab[a-1][k]=tab[a][b];
				 
			 }
			 k++;
		 }
	 }
}

/*la fonctionne DETMAT qui permet de calculer 
                             le determinant de cramer*/

float detmat(float**tab,int dim)
{
	
	int r=0;
	float det=0;
	//la sous matrice qui va contenir la matrice de dimension n-1
	float **sous_tab; 
	int signe=1;
	int x=0;
     
	if (dim==1) 
	{
		return(tab[0][0]);
	}


//alloctaion memoir de ma sous matrice
	sous_tab=(float**)malloc((dim-1)*sizeof(float*));
	
	for (x=0;x<(dim-1);x++)
	{ 
        sous_tab[x]=(float*)malloc((dim-1)*sizeof(float)); 
	}
	
//cette boucle permet la fonction qu'elle s'appelle elle méme 

	for (r=0;r<dim;r++)
	{
// creation de la sous matrice alloée
		copymat(tab,sous_tab,dim,r);
//SOMMATION DU DETERMINANT
		det+=signe*tab[0][r]*detmat(sous_tab,dim-1);             
		signe=(-signe);
		
	}

	return(det);// reteourne mon determinant 
	
}
		
/*************************************************************/
// debut du programme
main()
{
	float**mat;
	int n;
	int i=0;/*#################################################################*/             
	int j=0;                                                                 
	float determinant;
	char c;
do{       
	printf("\n\n#################################################################\n#                                                               #\n#                                                               #\n#              PROGRAMME CALCULATEUR DE DETERMINANT             #\n#                  CRAMER BY BOUIGHERDAINE-2012                 #\n#                                                               #\n#                                                               #\n#################################################################\n\nBienvenue dans Votre Programme qui calcule le Determinant de cramer\n----->SVP veuillez taper la dimension de votre matrice carree: ");		                                    
	scanf("%d",&n);

//allocation mémoire de la matrice
	mat=(float**)malloc(n*sizeof(float*));
	for (j=0;j<n;j++)
	{ 
        mat[j]=(float*)malloc(n*sizeof(float));
       
	}
//remplissage de ma matrice
	for (i=0;i<n;i++)
	{ 
        for(j=0;j<n;j++)
        {
			printf("\nTapez la valeur de l element (%d,%d) de votre matrice : ",i+1,j+1);
            scanf("%f",&mat[i][j]);
		}
    }

	determinant=detmat(mat,n);// appel de la fonction detmat

// affichage de la matrice
	printf("\n----->Votre Matrice que vous avez remplie:\n");
	for (i=0;i<n;i++)
	{ 
        for(j=0;j<n;j++)
        {
			printf("%3.f ",mat[i][j]);
          }
		printf("\n");
	}
	printf("\n----->le det de votre matrice est :%3.f \n\nTappez sur r ou R pour redemarrer sinon sur n'importe quelle touche !: ",determinant);


}while ((getch(c)=='r')||(getch(c)=='R'));
//	system("pause");

} /* Fin du programme */

Fonctions probables:
1: Reader
2: gestionnaire d'erreurs
3: fonction de rendu
4: fonction de detection du tetromino

Fonctions autorisees:
exit, open, close, write, read, malloc, free

Notes:
Jamais plus de 26 tetrominos dansle fichier de description
aucune rotation n'est possible dans les tetrominos
Les tetrominos sont places dans l'ordre dans lequel ils apparaissent dans le fichier
priorite de placement: le plus en haut PUIS le plus a gauche possible

Idees:
mettre un compteur de tetromino pour commencer direct au premier resultat esperable
	(i.e. 4 tet. => 4x4 ou plus, 5 tet => 5x5 ou plus, 7 tet => 6x6ou plus)

1: Reader

2: gestionnaire d'erreurs
if arg != 1, montrer l'usage
4 lignes de 4 caracteres suivi d'un retour a la lignes
ligne blanche entre chaque tetromino
il faut que le tetromino soit un bloc "classique"
s'il y a une erreur, mettre erreur sur la sortie standard et quitter proprement

3: fonction de rendu

4: fonction de detection du tetromino
23 possibilites

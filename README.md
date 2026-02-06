# 🐣 S1 | Prog: Workshop

Template de projet pour le workshop de prog des Imac1. Vous trouverez le sujet ici: https://dsmte.github.io/Learn--cpp_programming/Workshop

Projet:
Ce projet a été réalisé dans le cadre d’un workshop dédié à la manipulation d’images. L’objectif est d’apprendre à coder des effets visuels similaires aux filtres.

L’objectif principal est d’expérimenter plusieurs algorithmes permettant :
La modification des couleurs d’une image
L’application de filtres visuels
La transformation géométrique d’images
La création d’animations simples

Technologies et bibliothèques utilisées :
Langage : C++
Bibliothèque graphique : SIL
Aléatoire : random.hpp

Structure du projet :
images/ # Images sources
output/ # Images générées (résultat)
main.cpp # fonctions principales
README.md

EXERCICES

1. Exercices sur la manipulation des couleurs
   logo de base :c
   a- Mettre en vert
   La fonction mettre_vert() supprime les composantes rouge et bleue afin d’isoler la composante verte de l’image
   b- Échange des couleurs rouge et bleu
   La fonction echanger_rouge_bleu() permute les deux couleurs.
   ![alt text](image-1.png)
   c- Conversion en niveaux de gris
   ![alt text](image-2.png)
   d- Effet négatif
   La fonction negatif() inverse les couleurs en appliquant une symétrie par rapport au blanc.
   ![alt text](image-3.png)
   e- Effet RGB Split
   La fonction rgb_split() décale indépendamment les canaux couleur afin de produire un effet visuel inspiré des erreurs de transmission vidéo.
   ![alt text](image-4.png)
   f- Dégradé noir vers blanc
   La fonction degrader_noir_blanc() génère un dégradé horizontal progressif.

2. Transformations géométriques
   a-Disque et cercle
   Les fonctions disque_blanc() et cercle_blanc() utilisent la distance euclidienne afin de générer des formes géométriques centrées.
   ![alt text](image-6.png)
   ![alt text](image-7.png)
   b-Rosace
   La fonction rosace() construit plusieurs cercles répartis autour d’un centre commun.
   ![alt text](image-8.png)
   c-Miroir horizontal
   La fonction miroir_horizontal() échange les pixels symétriquement selon l’axe vertical.
   ![alt text](image-9.png)
   d- Rotation 90°
   La fonction rotation_90_droite() reconstruit l’image dans un nouveau repère.
   ![alt text](image-10.png)
   e- Rotation 180°
   La fonction rotation_180() effectue une symétrie centrale de l’image , je l'utilise uniquement dans l'exo pour les mosaiques

3. Effets visuels
   a- Ajout de bruit aléatoire
   La fonction ajouter_bruit() modifie certains pixels selon une probabilité donnée.
   ![alt text](image-11.png)
   b- Effet glitch
   La fonction glitch() échange aléatoirement des blocs de pixels pour produire un effet de distorsion numérique.
   ![alt text](image-12.png)

4. Génération de mosaïques
   a-Répétition d’image
   La fonction mosaique_self() reproduit l’image dans une grille définie.
   ![alt text](image-13.png)
   b-Mosaïque miroir/rotation
   La fonction mosaique_miroir_rotation() combine symétrie et rotation pour générer des motifs complexes.
   ![alt text](image-14.png)
5. Animation
   La fonction animer_cercle_gauche_droite() génère une séquence d’images représentant un disque se déplaçant horizontalement.
   ![alt text](image-15.png)

Perspectives d’amélioration :
Faire plus d'exercices notamment avec des algorithmes lié aux fractales (ex : Mandelbrot)
Optimisation des performances
Ajout de nouveaux filtres artistiques

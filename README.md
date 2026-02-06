# 🐣 S1 | Prog: Workshop

Template de projet pour le workshop de prog des Imac1. Vous trouverez le sujet ici: https://dsmte.github.io/Learn--cpp_programming/Workshop

Template de projet pour le workshop de prog des Imac1. Vous trouverez le sujet ici: https://dsmte.github.io/Learn--cpp_programming/Workshop

Traitement d’Images en C++

Projet:
Ce projet a été conçu dans le cadre d’un workshop dédié à la manipulation d’images. L’objectif est d’apprendre à coder des effets visuels similaires à ceux que l’on retrouve dans Photoshop ou les filtres Instagram.

L’objectif principal est d’expérimenter plusieurs algorithmes permettant :
La modification des couleurs d’une image
L’application de filtres visuels
La transformation géométrique d’images
La création d’animations simples

L’ensemble des manipulations est réalisé à l’aide de la bibliothèque graphique SIL.

Ce workshop a pour but de :
Comprendre la représentation matricielle d’une image numérique
Manipuler directement les pixels d’une image
Mettre en place des formules mathématiques sur des images
Utiliser des boucles imbriquées pour parcourir une image
Développer des effets visuels et graphiques

Technologies et bibliothèques utilisées
Langage : C++
Bibliothèque graphique : SIL
Aléatoire : random.hpp

Structure du projet :
images/ # Images sources
output/ # Images générées (résultat)
main.cpp # fonctions principales
README.md

Compilation et exécution :

Le projet peut être compilé avec un compilateur C++ standard style gcc.
Les résultats sont automatiquement enregistrés dans le dossier output.

Description des fonctionnalités

1. Exercices sur la manipulation des couleurs
   l'image de base :
   ![alt text](image.png)
   a- Mettre en vert
   La fonction mettre_vert() supprime les composantes rouge et bleue afin d’isoler la composante verte de l’image.
   ![alt text](output/vert.png)
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
2. Génération procédurale
   a- Dégradé noir vers blanc
   La fonction degrader_noir_blanc() génère un dégradé horizontal progressif.

b-Disque et cercle
Les fonctions disque_blanc() et cercle_blanc() utilisent la distance euclidienne afin de générer des formes géométriques centrées.

c-Rosace
La fonction rosace() construit un motif décoratif en combinant plusieurs cercles répartis angulairement autour d’un centre commun.

3. Transformations géométriques
   a- Miroir horizontal
   La fonction miroir_horizontal() échange les pixels symétriquement selon l’axe vertical.

b- Rotation 90°
La fonction rotation_90_droite() reconstruit l’image dans un nouveau repère.

c- Rotation 180°
La fonction rotation_180() effectue une symétrie centrale de l’image.

4. Effets visuels
   a- Ajout de bruit aléatoire
   La fonction ajouter_bruit() modifie certains pixels selon une probabilité donnée afin de simuler du bruit visuel.

b- Effet glitch
La fonction glitch() échange aléatoirement des blocs de pixels pour produire un effet de distorsion numérique.

c- Tri de pixels
La fonction trier_pixels_colonne() réorganise les pixels selon leur luminosité, créant un effet artistique.

5. Génération de mosaïques
   a-Répétition d’image
   La fonction mosaique_self() reproduit l’image dans une grille définie.

b-Mosaïque miroir/rotation
La fonction mosaique_miroir_rotation() combine symétrie et rotation pour générer des motifs complexes.

6. Animation
   La fonction animer_cercle_gauche_droite() génère une séquence d’images représentant un disque se déplaçant horizontalement.

Les images sont sauvegardées sous la forme :
output/frame000.png
output/frame001.png
...

Approche algorithmique :
Un parcours complet des pixels
Des calculs géométriques simples (distance, symétrie, rotation)
L’utilisation de copies intermédiaires pour éviter les modifications simultanées
L’exploitation de fonctions aléatoires pour générer des effets visuels

Résultats et observations :
Les expérimentations réalisées montrent que :
La manipulation directe des pixels permet de produire une grande variété d’effets visuels.
Les transformations géométriques nécessitent souvent la création d’images intermédiaires.
Les effets aléatoires apportent une dimension artistique intéressante.
L’optimisation peut devenir nécessaire pour les images de grande taille.

Perspectives d’amélioration :
Plusieurs extensions peuvent être envisagées :
Implémentation d’algorithmes de fractales (ex : Mandelbrot)
Génération d’animations GIF
Ajout d’une interface utilisateur
Optimisation des performances
Ajout de nouveaux filtres artistiques

BOIRE Yasmine
vqebab'B4

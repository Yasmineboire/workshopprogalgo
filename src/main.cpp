#include <sil/sil.hpp>

void mettre_vert(sil::Image& image)
{
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            auto& pixel = image.pixel(x, y);
            pixel.r = 0; 
            pixel.b= 0;
        }
    }
}

#include <algorithm> // pour std::swap

void echanger_rouge_bleu(sil::Image& image)
{
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            auto& pixel = image.pixel(x, y);

            std::swap(pixel.r, pixel.b);
        }
    }
}

void noir_et_blanc(sil::Image& image)
{
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            auto& pixel = image.pixel(x, y);

            float gris = 0.299f * pixel.r +
                         0.587f * pixel.g +
                         0.114f * pixel.b;

            pixel.r = gris;
            pixel.g = gris;
            pixel.b = gris;
        }
    }
}

void negatif(sil::Image& image)
{
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            auto& pixel = image.pixel(x, y);

            pixel.r = 1.f - pixel.r;
            pixel.g = 1.f - pixel.g;
            pixel.b = 1.f - pixel.b;
        }
    }
}

void degrader_noir_blanc(sil::Image& image)
{
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            float valeur = (float)x / (image.width() - 1);

            auto& pixel = image.pixel(x, y);

            pixel.r = valeur;
            pixel.g = valeur;
            pixel.b = valeur;
        }
    }
}
void miroir_horizontal(sil::Image& image)
{
    int width = image.width();
    int height = image.height();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++) // on ne parcourt que la moitié
        {
            auto& pixel1 = image.pixel(x, y);
            auto& pixel2 = image.pixel(width - 1 - x, y);

            // échange les pixels
            std::swap(pixel1, pixel2);
        }
    }
}
#include "random.hpp" // pour random_int, random_float, true_with_probability

void ajouter_bruit(sil::Image& image, float probabilite = 0.05f)
{
    int width = image.width();
    int height = image.height();

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // avec une certaine probabilité, on change le pixel
            if (true_with_probability(probabilite))
            {
                auto& pixel = image.pixel(x, y);

                // générer une couleur aléatoire
                pixel.r = random_float(0.0f, 1.0f);
                pixel.g = random_float(0.0f, 1.0f);
                pixel.b = random_float(0.0f, 1.0f);
            }
        }
    }
}
void rotation_90_droite(sil::Image& image)
{
    int width = image.width();
    int height = image.height();

    // créer une nouvelle image avec taille inversée
    sil::Image new_image{height, width};

    // copier les pixels selon la formule
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            new_image.pixel(y, width - 1 - x) = image.pixel(x, y);
        }
    }

    // remplacer l'image originale par la nouvelle
    image = new_image;
}

void rgb_split(sil::Image& image, int decalage_r = 15, int decalage_b = 15)
{
    int width = image.width();
    int height = image.height();

    sil::Image new_image{width, height};

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            auto& pixel_orig = image.pixel(x, y);
            auto& pixel_new  = new_image.pixel(x, y);

            // canal rouge : beaucoup à droite
            int x_r = x + decalage_r;
            if (x_r >= width) x_r = width - 1;
            pixel_new.r = image.pixel(x_r, y).r;

            // canal vert : reste au centre
            pixel_new.g = pixel_orig.g;

            // canal bleu : beaucoup à gauche
            int x_b = x - decalage_b;
            if (x_b < 0) x_b = 0;
            pixel_new.b = image.pixel(x_b, y).b;
        }
    }

    image = new_image;
}
#include <glm/vec3.hpp>

void disque_blanc(sil::Image& image)
{
    int width = image.width();
    int height = image.height();

    int cx = width / 2;   // centre X
    int cy = height / 2;  // centre Y
    int rayon = std::min(width, height) / 4; // taille du disque

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int dx = x - cx;
            int dy = y - cy;

            if (dx*dx + dy*dy <= rayon*rayon)
            {
                image.pixel(x, y) = glm::vec3(1.f, 1.f, 1.f); // blanc
            }
            else
            {
                image.pixel(x, y) = glm::vec3(0.f, 0.f, 0.f); // noir
            }
        }
    }
}

void cercle_blanc(sil::Image& image)
{
    int width = image.width();
    int height = image.height();

    int cx = width / 2;   
    int cy = height / 2;  
    int rayon = std::min(width, height) / 4;

    int thickness = 8; // épaisseur du cercle

    int rExt = rayon + thickness / 2;
    int rInt = rayon - thickness / 2;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int dx = x - cx;
            int dy = y - cy;

            int dist2 = dx * dx + dy * dy;

            if (dist2 <= rExt * rExt && dist2 >= rInt * rInt)
            {
                image.pixel(x, y) = glm::vec3(1.f, 1.f, 1.f); // blanc
            }
            else
            {
                image.pixel(x, y) = glm::vec3(0.f, 0.f, 0.f); // noir
            }
        }
    }
}

void animer_cercle_gauche_droite()
{
    int width = 500;
    int height = 500;

    float cy = height / 2.0f;
    float rayon = 100.0f;

    int nb_frames = 60;

    for (int i = 0; i < nb_frames; i++)
    {
        sil::Image image{width, height}; // image noire

        float t = static_cast<float>(i) / (nb_frames - 1);
        float cx = rayon + t * (width - 2 * rayon);

        // dessin du disque
        for (int x = 0; x < image.width(); x++)
        {
            for (int y = 0; y < image.height(); y++)
            {
                float dx = x - cx;
                float dy = y - cy;

                if (dx * dx + dy * dy <= rayon * rayon)
                {
                    auto& pixel = image.pixel(x, y);
                    pixel.r = 1.0f;
                    pixel.g = 1.0f;
                    pixel.b = 1.0f;
                }
            }
        }

        std::ostringstream name;
        name << "output/frame"
             << std::setw(3) << std::setfill('0')
             << i << ".png";

        image.save(name.str());
    }
}

#include <cmath>

#include <cmath>

void rosace(sil::Image& image)
{
    int width = image.width();
    int height = image.height();

    int cx = width / 2;
    int cy = height / 2;

    int rayon = std::min(width, height) / 6;  // rayon des cercles
    int thickness = 5;

    int rExt = rayon + thickness / 2;
    int rInt = rayon - thickness / 2;

    int nbCercles = 6; // nombre de cercles autour

    // Fond noir
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            image.pixel(x, y) = glm::vec3(0.f);

    // Cercle central
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int dx = x - cx;
            int dy = y - cy;
            int dist2 = dx * dx + dy * dy;
            if (dist2 <= rExt * rExt && dist2 >= rInt * rInt)
                image.pixel(x, y) = glm::vec3(1.f);
        }
    }

    // Cercles autour (centre sur le bord du cercle central)
    for (int i = 0; i < nbCercles; i++)
    {
        float angle = i * 2.f * M_PI / nbCercles;

        // Distance égale au rayon du cercle central
        int centreX = cx + rayon * std::cos(angle);
        int centreY = cy + rayon * std::sin(angle);

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int dx = x - centreX;
                int dy = y - centreY;
                int dist2 = dx * dx + dy * dy;
                if (dist2 <= rExt * rExt && dist2 >= rInt * rInt)
                    image.pixel(x, y) = glm::vec3(1.f);
            }
        }
    }
}



// Crée une mosaïque en reproduisant la même image en 5x5
void mosaique_self(sil::Image& image, int largeur, int hauteur)
{
    sil::Image copie = image; // copie de l'image originale pour prendre les pixels
    int taille_bloc_x = image.width() / largeur;
    int taille_bloc_y = image.height() / hauteur;

    for (int bx = 0; bx < largeur; bx++)
    {
        for (int by = 0; by < hauteur; by++)
        {
            for (int x = 0; x < taille_bloc_x; x++)
            {
                for (int y = 0; y < taille_bloc_y; y++)
                {
                    int fx = bx * taille_bloc_x + x;
                    int fy = by * taille_bloc_y + y;

                    if (fx < image.width() && fy < image.height())
                    {
                        // Prendre le pixel correspondant dans la copie
                        int px = x * copie.width() / taille_bloc_x;
                        int py = y * copie.height() / taille_bloc_y;

                        image.pixel(fx, fy) = copie.pixel(px, py);
                    }
                }
            }
        }
    }
}

void rotation_180(sil::Image& image)
{
    int width = image.width();
    int height = image.height();

    for (int y = 0; y < height / 2; y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::swap(image.pixel(x, y), image.pixel(width - 1 - x, height - 1 - y));
        }
    }

    // Si la hauteur est impaire, inverser la ligne du milieu
    if (height % 2 == 1)
    {
        int mid = height / 2;
        for (int x = 0; x < width / 2; x++)
        {
            std::swap(image.pixel(x, mid), image.pixel(width - 1 - x, mid));
        }
    }
}
void mosaique_miroir_rotation(sil::Image& image, int nbX, int nbY)
{
    int largeur_bloc = image.width() / nbX;
    int hauteur_bloc = image.height() / nbY;

    sil::Image copie_originale = image;

    for (int by = 0; by < nbY; by++)
    {
        for (int bx = 0; bx < nbX; bx++)
        {
            sil::Image bloc = copie_originale;

            // Lignes 2 et 4 -> rotation 180°
            if (by == 1 || by == 3)
            {
                rotation_180(bloc);
            }

            // Une image sur deux -> miroir horizontal
            if ((bx + by * nbX) % 2 == 1)
            {
                miroir_horizontal(bloc);
            }

            // Copier le bloc dans l'image finale
            for (int x = 0; x < largeur_bloc; x++)
            {
                for (int y = 0; y < hauteur_bloc; y++)
                {
                    int fx = bx * largeur_bloc + x;
                    int fy = by * hauteur_bloc + y;

                    if (fx < image.width() && fy < image.height())
                    {
                        int px = x * bloc.width() / largeur_bloc;
                        int py = y * bloc.height() / hauteur_bloc;

                        image.pixel(fx, fy) = bloc.pixel(px, py);
                    }
                }
            }
        }
    }
}





#include "random.hpp"

void glitch(sil::Image& image, int nb_glitchs = 20, int max_width = 100, int max_height = 10)
{
    int width = image.width();
    int height = image.height();

    for (int i = 0; i < nb_glitchs; ++i)
    {
        // Taille du rectangle : long horizontalement, fin verticalement
        int block_width = random_int(10, max_width);  // au moins 10 px pour être visible
        int block_height = random_int(1, max_height); // fin verticalement

        // Position du premier rectangle
        int x1 = random_int(0, width - block_width);
        int y1 = random_int(0, height - block_height);

        // Position du deuxième rectangle
        int x2 = random_int(0, width - block_width);
        int y2 = random_int(0, height - block_height);

        // Échange des pixels
        for (int dx = 0; dx < block_width; ++dx)
        {
            for (int dy = 0; dy < block_height; ++dy)
            {
                auto& pixel1 = image.pixel(x1 + dx, y1 + dy);
                auto& pixel2 = image.pixel(x2 + dx, y2 + dy);
                std::swap(pixel1, pixel2);
            }
        }
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include "random.hpp" // Pour random_int, set_random_seed, etc.

// Fonction pour calculer la luminosité d'une couleur
float brightness(const glm::vec3& color) {
    return 0.299f * color.r + 0.587f * color.g + 0.114f * color.b;
}

// Fonction qui trie les pixels par colonne selon la luminosité (ou une composante)
void trier_pixels_colonne(sil::Image& image) {
    int w = image.width();
    int h = image.height();

    for (int x = 0; x < w; x++) {
        std::vector<glm::vec3> colonne;

        // On copie tous les pixels de la colonne
        for (int y = 0; y < h; y++) {
            colonne.push_back(image.pixel(x, y));
        }

        // Tri selon la luminosité (ou une composante, ici luminosité)
        std::sort(colonne.begin(), colonne.end(), [](const glm::vec3& a, const glm::vec3& b) {
            return brightness(a) < brightness(b);
        });

        // On remet les pixels triés dans l'image
        for (int y = 0; y < h; y++) {
            image.pixel(x, y) = colonne[y];
        }
    }
}






int main()
{
    //sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    //mettre_vert(image);
    // image.save("output/pouet.png");
    //echanger_rouge_bleu(image);
    // image.save("output/logo_swap.png");
    //noir_et_blanc(image);
    // image.save("output/noir_blanc.png");
    //negatif(image);
    //image.save("output/negatif.png");
    //degrader_noir_blanc(image);
    //image.save("output/degrade.png");
    //miroir_horizontal(image);
    //image.save("output/miroir.png");
    //ajouter_bruit(image);
    //image.save("output/bruit.png");
    //rotation_90_droite(image);
    //image.save("output/rotation.png");
    //rgb_split(image);
    //image.save("output/split.png");
    sil::Image image{500, 500};
    //cercle_blanc(image);
    //image.save("output/cercle.png");
    //sil::Image image{500, 500};
    //cercle_blanc(image);
    //image.save("output/cercle_blanc.png");
    animer_cercle_gauche_droite();
    image.save("output/cercleanime.png");
    //rosace(image);
    //image.save("output/rosace.png");
    //mosaique_miroir_rotation(image, 5, 5);
    //image.save("output/mosaique_miroir.png");
    // Pour avoir la même suite de nombres aléatoires à chaque lancement
    //set_random_seed(0);
    //glitch(image, 20, 100, 10);
    //image.save("output/logo_glitch.png");
    //trier_pixels_colonne(image);
    //image.save("output/tripixels.png");
    //generer_mandelbrot(image);    // fonction qui fait tout le boulot
    //image.save("output/mandelbrot.pgm");
}




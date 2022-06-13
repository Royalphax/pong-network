<div align="center">
<img src="https://imgur.com/LKNbhLF.jpg" width="800"/>
<h1>Pong Network</h1>
<p><i>Le jeu du pong, en réseau !</i><br/><b>Développeurs : </b>Charles B, Nicolas V, Simon D, Thérence F</p>
<h2>Liens utiles</h2>
<a href="https://github.com/fabrice1618/pong" target="blank">Projet initial de @fabrice1618</a>
<br/>
<a href="https://github.com/users/Royalphax/projects/2" target="blank">Backlog et suivi des tâches</a>
<br/>
<a href="https://blog.ahmadz.ai/sdl2-for-clion-and-cmake/" target="blank">Tuto installation SDL2</a>
<br/>
<a href="https://www.geeksforgeeks.org/handling-multiple-clients-on-server-with-multithreading-using-socket-programming-in-c-cpp/" target="blank">Tuto socket C++</a>
<br/>
<a href="https://gamedev.stackexchange.com/questions/197232/how-to-create-editable-sdl2-text-input-boxes" target="blank">Création entrée textuelle SDL2</a>
<br/>
...
<hr/>
</div>

## Arborescence

```bash
PongNetwork
     │
     ├── nlohmann_json/ # Librairie JSON
     ├── sockpp/        # Librairie Sockpp
     │
     ├── src/           # Code source
     │   ├── client/        # Code du client
     │   │   ├── main.cpp       # Code principal pour lancer le client
     │   │   └── ...
     │   │
     │   ├── server/        # Code du serveur
     │   │   ├── main.cpp       # Code principal pour lancer le serveur
     │   │   └── ...
     │   │
     │   └── common/        # Code commun au serveur et au client
     │       ├── include/       # Répertoire des librairies en commun
     │       ├── lib.cpp        # Méthodes en commun
     │       └── ...
     │
     ├── cmake/             # Gestion de la compilation
     │   └── modules/           # Modules de compilation
     │
     ├── cmake-build-debug/ # Cache des données de compilation
     │   ├── Pong.ttf           # Police d'écriture du jeu
     │   ├── SDL2.dll           # Référence de la librairie SDL2    
     │   ├── SDL2_ttf.dll       # Référence de la librairie SDL2 ttf   
     │   └── SDL2_image.dll     # Référence de la librairie SDL2 image
     │
     ├── CMakeList.txt      # Fichier CMake pour gérer automatiquement la compilation
     │
     └── README.md
```

## Modèle d'échange de données

Données transmises au serveur par les clients | Données transmises aux clients par le serveur
------------------------------|------------------------------
Touche Clavier [HAUT / BAS]   | Position des barres
.                             | Position de la balle
.                             | Score des clients
.                             | Etat de la partie (pas commencée, en cours, finie)

**Principe :** Le serveur reçoit si le client veut monter ou descendre sa barre et s'occupe de calculer la position de la barre puis de la balle à l'instant suivant. Une fois le calcul effectué, il transmet les informations aux clients afin qu'ils mettent à jour leur affichage.

**Avantages :**
1. **Simplifie le code des clients :** ils doivent seulement afficher le jeu à partir des données fournies par le serveur.
2. **Empêche la triche :** les clients n'interviennent pas dans le calcul de la position de la balle et de leur barre et ne peuvent donc pas la manipuler.
3. **Centralise la puissance de calcul coté serveur :** Permet de bénéficier d'un code client plus léger.

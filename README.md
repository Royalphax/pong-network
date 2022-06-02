<div align="center">
<img src="https://media.giphy.com/media/aTGwuEFyg6d8c/giphy.gif" width="300"/>
<h1>Pong Network</h1>
<p><i>Le jeu du pong, en réseau !</i><br/><b>Développeurs : </b>Charles B, Enzo G, Jean-Denis M, Jordan D, Nicolas V, Simon D, Thérence F</p>
<h2>Liens utiles</h2>
<a href="https://github.com/fabrice1618/pong" target="blank">Projet initial du prof</a>
<br/>
<a href="https://github.com/users/Royalphax/projects/2" target="blank">Backlog et suivi des tâches</a>
<br/>
...
<hr/>
</div>

## Arborescence

```bash
PongNetwork
    │
    ├── design/        # Modélisations UML
    │   └── ...
    │
    ├── server/        # Code du serveur
    │   ├── run/           # Algorithmes de calcul des positions barres/balles
    │   │   └── ...
    │   ├── net/           # Gestion de la connexion avec le client (via socket)
    │   │   └── ...
    │   ├── main.cpp       # Code principal pour lancer le serveur
    │   └── ...
    │
    ├── client/        # Code du client
    │   ├── gui/           # Gestion de l'interface (OpenGL?)
    │   │   └── ...
    │   ├── net/           # Gestion de la connexion avec le serveur (via socket)
    │   │   └── ...
    │   ├── main.cpp       # Code principal pour lancer le client
    │   └── ...
    │
    ├── README.md
    └── ...
```

## Modèle d'échange de données
<img src="https://i.imgur.com/Wr3AaqO.png" width="700"/>

Données transmises au serveur | Données transmises au client
------------------------------|------------------------------
ToucheClavier                 | Position de la barre
.                             | Position de la balle
.                             | Score du client
.                             | Score de son adversaire
.                             | Etat de la partie (pas commencée, en cours, finie)

**Principe :** Le serveur reçoit si le client veut monter ou descendre sa barre et s'occupe de calculer la position de la barre puis de la balle à l'instant suivant. Une fois le calcul effectué, il transmet les informations aux clients afin qu'ils mettent à jour leur affichage.

**Avantages :**
1. **Simplifie le code des clients :** ils doivent seulement afficher le jeu à partir des données fournies par le serveur.
2. **Empêche la triche :** les clients n'interviennent pas dans le calcul de la position de la balle et de leur barre et ne peuvent donc pas la manipuler.
3. **Centralise la puissance de calcul coté serveur :** Permet de bénéficier d'un code client plus léger.

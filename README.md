# minitalk

Ce projet permet la transmission de 10 000 caractères d'un client à un serveur en moins d'une seconde sur Ubuntu.

Notions abordées : signaux UNIX, opérateurs binaires

![Capture d’écran 2022-05-02 à 23 46 19](https://user-images.githubusercontent.com/96736158/166332912-d27f6eb1-946b-4396-b803-a5fcfaff8a17.png)



Remarques : 

- Le système Linux ne met PAS les signaux en file d’attente lorsqu'un signal de ce type est déjà en attente de traitement. 
Il faut donc mettre en place une sorte de "ping-pong" : le client envoie un premier bit au serveur puis se met en pause (usleep(20000)),
lorsque le serveur a bien enregistré le bit, il envoie un signal au client qui sort de sa pause et envoie un nouveau bit au serveur, 
et ainsi de suite. Sur Mac en revanche vous n'aurez pas ce problème.

- Testez votre programme avec  : ./client -1 "hello".
Vos terminaux se sont fermés ? N'oubliez pas d'utiliser la fonction sigemptyset lorsque vous mettez en place sigaction. Pour plus de détails à ce sujet : man kill et voir ce qui se passe avec kill -1.

- Le sujet précise bien qu'il faut imprimer la chaîne de caractères quand elle est entièrement reçue par le serveur, il ne faut donc pas afficher les caractères un à un. Dans ce projet, le client envoie d'abord la taille de la chaîne de caractères au serveur pour que ce dernier puisse allouer l'espace nécessaire à sa réception avec un seul malloc. Si vous utilisez plusieurs mallocs avec un ft_strjoin pour chaque caractère reçu, vous risquez de ralentir la communication entre le client et le serveur. 

- Une seule variable globale par programme est permise. Si vous jouez le jeu, vous n'aurez pas besoin de maquiller de nombreuses variables avec une structure, il est tout à fait possible de faire le projet avec les deux seules variables globales autorisées. Essayez, vous verrez !

- Que se passe-t-il si le client envoie un signal à un serveur qui a été fermé ?

- Cas plus complexe : que se passe-t-il si vous envoyez une très longue chaîne de caractère au serveur, mais que vous fermez le client avant la transmission totale de la chaîne de caractère ? Et si un nouveau client envoie une chaîne de caractère à la suite ?

Note : 125/100

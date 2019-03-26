# libft
Premier projet de l'ecole 42 : coder une librairie libft.a.
Lors du projet de nombreuses fonctions présentes dans la libc ont été recodées.
Avec le temps, quelques fonctions additionnelles personnelles sont venues se greffer.

- [libft](#libft)
	- [Fonctions mémoire](#fonctions-m%C3%A9moire)
	- [Fonctions chaînes de caractères](#fonctions-cha%C3%AEnes-de-caract%C3%A8res)
	- [Fonctions caractères](#fonctions-caract%C3%A8res)
	- [Fonctions nombres et calculs](#fonctions-nombres-et-calculs)
	- [Fonctions listes chaînées](#fonctions-listes-cha%C3%AEn%C3%A9es)
	- [Fonctions d'ouverture, fermeture, suppression... de File Descriptor](#fonctions-douverture-fermeture-suppression-de-file-descriptor)
	- [Fonctions d'affichage, lecture, écriture](#fonctions-daffichage-lecture-%C3%A9criture)

## Fonctions mémoire
Fonctions | Prototype | Description
--- | ---- | ---------------------
[ft_memset](ft_memset.c) | `void	*ft_memset(void *b, int c, size_t len);` | (cf. man) Remplit les n premiers octets de la zone mémoire pointée par s avec l'octet c. Renvoie un pointeur sur la zone mémoire s.
[ft_bzero](ft_bzero.c)  | `void	ft_bzero(void *s, size_t len);` | (cf. man) Met à 0 (octets contenant « \0 ») les n premiers octets du bloc pointé par s.
[ft_memcpy](ft_memcpy.c) | `void	*ft_memcpy(void *dst, const void *src, size_t n);` | (cf. man) Copie n octets depuis la zone mémoire src vers la zone mémoire dest. Les deux zones ne doivent pas se chevaucher (overlap). Si c'est le cas, utiliser plutôt ft_memmove. Renvoie un pointeur sur dest.
[ft_memccpy](ft_memccpy.c) | `void	*ft_memccpy(void *dst, const void *src, int c, size_t n);` | (cf. man) Copie au plus n octets de la zone mémoire src vers la zone mémoire dest, s'arrêtant dès qu'elle rencontre le caractère c. Renvoie un pointeur sur le caractère immédiatement après c dans la zone dest, ou NULL si c n'a pas été trouvé.
[ft_memmove](ft_memmove.c) | `void	*ft_memmove(void *dst, const void *src, size_t n);` | (cf. man) Copie n octets depuis la zone mémoire src vers la zone mémoire dest. Les deux zones peuvent se chevaucher (overlap).
[ft_memchr](ft_memchr.c) | `void	*ft_memchr(const void *s, int c, size_t n);` | (cf. man) Cherche c parmi les n premiers octets de la zone mémoire pointée par s. Renvoie un pointeur sur le premier octet correspondant, ou NULL si le caractère n'est pas présent.
[ft_memcmp](ft_memcmp.c) | `int		ft_memcmp(const void *s1, const void *s2, size_t n);` | (cf. man) Compare les n premiers octets des zones mémoire s1 et s2. Renvoie un entier négatif, nul ou positif si les n premiers octets de s1 sont respectivement inférieurs, égaux ou supérieurs aux n premiers octets de s2.
[ft_memalloc](ft_memalloc.c) | `void	ft_memalloc(size_t size);` | Alloue avec malloc(3) et retourne une zone de memoire "fraiche". La memoire allouee est intialisee a 0. Si l'allocation echoue, la fonction renvoie NULL.
[ft_memdel](ft_memdel.c) | `void	ft_memdel(void **ap);` | Prend en parametre l’adresse d’un pointeur dont la zone pointee doit etre liberee avec free(3), puis le pointeur est mis a NULL.
[ft_swap](ft_swap.c) | `void	ft_swap(int *a, int *b);` | Echange le contenu de deux entiers dont les adresses sont données en paramètres.
[ft_memccpy_src](ft_memccpy_src.c) | `void		*ft_memccpy_src(void *dst, void *src, int c, size_t n);` | La fonction ft_memccpy_src() copie au plus n octets de la zone mémoire src vers la zone mémoire dest, s'arrêtant dès qu'elle rencontre le caractère c.
*"* | *"* | La fonction ft_memccpy_src() renvoie un pointeur sur le caractère immédiatement après c dans la zone SRC, ou NULL si c n'a pas été trouvé dans les n premiers caractères de src.
*"* | *"* | Elle a un comportement similaire à ft_memccpy(), qui elle, renvoie un pointeur sur la caractère immédiatement après c dans la zone DEST ou NULL si c n'a pas été trouvé.


## Fonctions chaînes de caractères
Fonctions | Prototype | Description
--- | ---- | ---------------------
[ft_strlen](ft_strlen.c) | `size_t	ft_strlen(const char *str);` | (cf. man) Calcule la longueur de la chaîne de caractères s, sans compter l'octet nul « \0 » final.
[ft_strdup](ft_strdup.c) | `char	*ft_strdup(const char *s);` | (cf. man) Renvoie un pointeur sur une nouvelle chaîne de caractères qui est dupliquée depuis s.
[ft_strndup](ft_strndup.c) | `char	*ft_strndup(const char *s, size_t n);` | (cf. man) Renvoie un pointeur sur une nouvelle chaîne de caractères qui est dupliquée depuis les n permiers caractères de s.
[ft_strcpy](ft_strcpy.c) | `char	*ft_strcpy(char *dest, const char *src);` | (cf. man) Copie src (y compris le '\0') dans dest. Les deux chaînes ne doivent pas se chevaucher. dest doit être assez grande pour accueillir la copie.
[ft_strncpy](ft_strncpy.c) | `char	*ft_strncpy(char *dest, const char *src, size_t len);` | (cf. man) Identique à strcpy sauf que seuls les n premiers octets de src sont copiés. Avertissement : s'il n'y a pas de '/0' dans les n premiers octets de src, dest n'en aura pas non plus.
[ft_strcat](ft_strcat.c) | `char	*ft_strcat(char *s1, const char *s2);` | (cf. man) Ajoute src à la fin de dest en écrasant le '\0' à la fin de dest, puis en ajoutant un nouveau caractère nul final. Les chaînes ne doivent pas se chevaucher, et dest doit être assez grande pour accueillir le résultat.
[ft_strncat](ft_strncat.c) | `char	*ft_strncat(char *s1, const char *s2, size_t n);` | (cf. man) Identique à ft_strcat en copiant les n premiers caractères de src à la suite des dest.
[ft_strlcat](ft_strlcat.c) | `size_t	ft_strlcat(char *dst, const char *src, size_t size);` | (cf. man) Concatène les deux chaînes et retourne la longueur totale de la chaîne qu'elle essaye de créer. Cela signifie la taille initiale de dst plus la longueur de src.
[ft_strchr](ft_strchr.c) | `char	*ft_strchr(const char *s, int c);` | (cf. man) Renvoie un pointeur sur la première occurrence du caractère c dans la chaîne s (ou NULL si non trouvé).
[ft_strrchr](ft_strrchr.c) | `char	*ft_strrchr(const crar *s, int c);` | (cf. man) Renvoie un pointeur sur la dernière occurrence du caractère c dans la chaîne s (ou NULL si non trouvé).
[ft_strchr_pos](ft_strchr_pos.c) | `int	ft_strchr(const char *s, int c);` | Renvoie la position de la première occurrence du caractère c dans la chaîne s (ou -1 si non trouvé).
[ft_strrchr_pos](ft_strrchr_pos.c) | `int	ft_strrchr(const crar *s, int c);` | Renvoie la position de la dernière occurrence du caractère c dans la chaîne s (ou -1 si non trouvé).
[ft_strstr](ft_strstr.c) | `char	*ft_strstr(const char *haystack, const char *needle)` | (cf. man) Cherche la première occurrence de la sous-chaîne needle au sein de la chaîne haystack.
[ft_strnstr](ft_strnstr.c) | `char	*ft_strnstr(const char *hstack, const char *ndle, size_t n);` | (cf. man) Cherche la première occurrence de la sous-chaîne needle au sein des n premiers caractères de la chaîne haystack.
[ft_strleft](ft_strleft.c) | `int ft_strleft(const char *str, const char *left);` | Renvoie 1 si la chaîne *str commence par la chaîne *left. Renvoie 0 dans le cas contraire.
[ft_strright](ft_strright.c) | `int ft_strright(const char *str, const char *right);` | Renvoie 1 si la chaîne *str se finie par la chaîne *right. Renvoie 0 dans le cas contraire.
[ft_strcmp](ft_strcmp.c) | `int	ft_strcmp(const char *s1, const char *s2); ` | (cf. man) Compare les deux chaînes s1 et s2. Renvoie un entier négatif, nul, ou positif, si s1 est respectivement inférieure, égale ou supérieure à s2.
[ft_strncmp](ft_strncmp.c) | `int	ft_strncmp(const char *s1, const char *s2, size_t n);`| (cf. man) Identique à strcmp en ne comparant que les n (au plus) premiers caractères de s1 et s2.
[ft_strnew](ft_strnew.c) | `char	*ft_strnew(size_t size);` | Alloue avec malloc(3) et retourne une chaine de caractere “fraiche” terminee par un ’\0’. Chaque caractere de la chaine est initialise a ’\0’. Si l’allocation echoue, la fonction renvoie NULL.
[ft_strdel](ft_strdel.c) | `void	ft_strdel(char **as);` | Prend en parametre l’adresse d’une chaine de caracteres qui doit etre liberee avec free(3) et son pointeur mis a NULL.
[ft_strclr](ft_strclr.c) | `void	ft_strclr(char *s);` | Assigne la valeur ’\0’ a tous les caracteres de la chaine passee en parametre.
[ft_striter](ft_striter.c) | `void	ft_striter(char *s, void (*f)(char *));` | Applique la fonction f a chaque caractere de la chaine de caracteres passee en parametre. Chaque caractere est passe par adresse a la fonction f afin de pouvoir être modifie si necessaire.
[ft_striteri](ft_striteri.c) | `void	ft_striteri(char *s, void (*f)(unsigned int, char *));` | Applique la fonction f a chaque caractere de la chaine de caracteres passee en parametre en precisant son index en premier argument. Chaque caractere est passe par adresse a la fonction f afin de pouvoir etre modifie si necessaire.
[ft_strmap](ft_strmap.c) | `char	*ft_strmap(char const *s, char (*f)(char));` | Applique la fonction f a chaque caractere de la chaine de caracteres passee en parametre pour creer une nouvelle chaine “fraiche” avec malloc(3) resultant des applications successives de f.
[ft_strmapi](ft_strmapi.c) | `char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applique la fonction f a chaque caractere de la chaine de caracteres passee en parametre en precisant son index pour creer une nouvelle chaine “fraiche” avec malloc(3) resultant des applications successives de f.
[ft_strequ](ft_strequ.c) | `int	ft_strequ(char const *s1, char const *s2);` | Compare lexicographiquement s1 et s2. Si les deux chaines sont egales, la fonction retourne 1, ou 0 sinon.
[ft_strnequ](ft_strnequ.c) | `int	ft_strnequ(char const *s1, char const *s2, size_t n);` | Compare lexicographiquement s1 et s2 jusqu’a n caracteres maximum ou bien qu’un ’\0’ ait ete rencontre. Si les deux chaines sont egales, la fonction retourne 1, ou 0 sinon.
[ft_strsub](ft_strsub.c) | `char	*ft_strsub(char const *s, unsigned int start, size_t len);` | Alloue avec malloc(3) et retourne la copie "fraiche" d'un troncon de la chaine de caracteres passee en parametre. Le troncon commence a l'index start et a pour longueur len. Si start et len ne designent pas un troncon de chaine valide, le comportement est indetermine. Si l'allocation echoue, la fonction renvoie NULL.
[ft_strjoin](ft_strjoin.c) | `char	*ft_strjoin(char const *s1, char const *s2);` | Alloue avec malloc(3) et retourne une chaine de caracteres "fraiche" terminee pas un '\0' resultant de la concatenation de s1 de s2. Si l'allocation echoue, la fonction renvoie NULL.
[ft_strnjoin](ft_strnjoin.c) | `char	*ft_strnjoin(char const *s1, char const *s2, size_t len);` | Alloue avec malloc(3) et retourne une chaine de caracteres "fraiche" terminee pas un '\0' resultant de la concatenation de s1 et des n premiers caractères de s2. Si l'allocation echoue, la fonction renvoie NULL.
[ft_strnjoinfree](ft_strnjoinfree.c) | `char	*ft_strnjoinfree(char const *s1, char const *s2, size_t len, int pick);` | Alloue avec malloc(3) et retourne une chaine de caracteres "fraiche" terminee pas un '\0' resultant de la concatenation de s1 et des n premiers caractères de s2. Si l'allocation echoue, la fonction renvoie NULL. Contrairement à ft_strnjoin, ft_strnjoinfree permet de libérer la mémoire allouée à s1, s2 ou les deux.
[ft_strtrim](ft_strtrim.c) | `char	*ft_strtrim(char const *s);` | Alloue avec malloc(3) et retourne une copie de la chaine passee en parametre sans les espaces blancs au debut et a la fin de cette chaine. On considere comme des espaces blancs les caracteres ' ', '\n' et '\t'. Si s ne contient pas d'espaces blancs au debut ou a la fin, la fonction renvoie une copie de s. Si l'allocation echoue, la fonction renvoie NULL.
[ft_stroffset](ft_stroffset.c) | `char	*ft_stroffset(char *str, unsigned int offset);` | Décale les caractères de 'offset' positions. (Exemple ft_stroff("Exemple", 2) renvoie "emple"). Renvoie NULL si offset est plus grand que la taille de la chaîne. Cette fonction permet notamment d'effectuer un décalage du type str++, tout en conservant l'adresse initiale de str.
[ft_strsplit](ft_strsplit.c) | `char	**ft_strsplit(char const *s, char c);` | Alloue avec malloc(3) et retourne un tableau de chaînes de caracteres "fraiches", résultant de la découpe de "s" selon le caractère 'c'. Le tableau et toutes les chaînes sont terminées par '\0'. Si l'allocation échoue, la fonction retourne NULL.
[ft_strmsplit](ft_strmsplit.c) | `char	**ft_strmsplit(char const *s, char *chars);` | Alloue avec malloc(3) et retourne un tableau de chaînes de caracteres "fraiches", résultant de la découpe de "s" selon chacun des caractères de 'chars'. Le tableau et toutes les chaînes sont terminées par '\0'. Si l'allocation échoue, la fonction retourne NULL.
[ft_freetab_strsplit](ft_strsplit.c) | `void	ft_freetab_strsplit(char **tab);` | Libère les espaces mémoires alloués par ft_strsplit.
[ft_countwords](ft_countwords.c) | `int	ft_countwords(char const *s, char c);` | Prend en paramètre une chaîne de caractères "s" et un caractère 'c'. La fonction retourne le nombre de mots issus de la découpe de la chaîne "s" par le séparateur 'c'. Exemple : ft_countwords("*salut*les***etudiants*",’*’) renvoie 3 pour "salut", "les", et "etudiants".
[get_next_line](get_next_line.c) | `int		get_next_line(int fd, char **line);` | La fonction GNL lit une ligne dans le file descriptor fd et complète la chaîne de caractères *line avec le résultat de la lecture (sans '\n' le cas échéant).
*"* | *"* | Une fin de lecture est définie par un '\n' ou un EOF (End Of File).
*"* | *"* | La fonction retourne 1 lorsqu'une ligne est lue ; 0 lorsque la lecture est terminée ; et -1 en cas d'erreur.


## Fonctions caractères
Fonctions | Prototype | Description
--- | -------- | ------------------
[ft_isalpha](ft_isalpha.c) | `int	ft_isalpha(int c);` | (cf. man) Prend un char en paramètre et renvoie 1 s'il s'agit d'un caractère alphabétique. Sinon 0.
[ft_isdigit](ft_isdigit.c) | `int	ft_isdigit(int c);`| (cf. man) Prend un char en paramètre et renvoie 1 s'il s'agit un chiffre. Sinon 0.
[ft_isalnum](ft_isalnum.c) | `int	ft_isalnum(int c);` | (cf. man) Prend un char en paramètre et renvoie 1 s'il s'agit d'un caractère alpha numérique (lettre ou chiffre). Sinon 0.
[ft_isascii](ft_isascii.c) | `int	ft_isascii(int c);` | (cf. man) Prend un char en paramètre et renvoie 1 s'il s'agit d'un caractère ASCII. Sinon 0.
[ft_isprint](ft_isprint.c) | `int	ft_isprint(int c);` | (cf. man) Prend un char en paramètre et renvoie 1 s'il s'agit d'un caractère imprimable. Sinon 0.
[ft_toupper](ft_toupper.c) | `int	ft_toupper(int c);` | (cf. man) Prend un char en paramètre et s'il s'agit d'une lettre minuscule, renvoie le char en majuscule. Sinon la fonction renvoie le char passé en paramètre.
[ft_strupper](ft_toupper.c) | `char	*ft_strupper(char *str);` | Passe une chaîne de caractères en majuscules en utilisant la fonction ft_toupper.
[ft_tolower](ft_tolower.c) | `int	ft_tolower(int c);` | (cf. man) Prend un char en paramètre et s'il s'agit d'une lettre majuscule, renvoie le char en minuscule. Sinon la fonction renvoie le char passé en paramètre.
[ft_strlower](ft_tolower.c) | `char	*ft_strlower(char *str);` | Passe une chaîne de caractères en minuscules en utilisant la fonction ft_tolower.


## Fonctions nombres et calculs
Fonctions | Prototype | Description
--- | -------- | ------------------
[ft_atoi](ft_atoi.c) | `int	ft_atoi(const char *str)` | (cf. man) Convertit une chaîne en entier.
[ft_atoi_base](ft_atoi_base.c) | `int	ft_atoi_base(const char *str, int str_base)` | Convertit une chaîne de la base définie en entier de base 10.
[ft_itoa](ft_itoa.c) | `char	*ft_itoa(int n);` | Alloue avec malloc(3) et retourne une chaine de caracteres "fraiche" terminee par un '\0' representatnt l'entier n passe en parametre. Les nombres negatifs sont geres. Si l'allocation echoue, la fonction renvoie NULL.
[ft_itoa_base](ft_itoa_base.c) | `char	*ft_itoa(intmax_t n, int base);` | Alloue avec malloc(3) et retourne une chaine de caracteres "fraiche" terminee par un '\0' representatnt l'entier n passe en parametre converti selon la base donnée. Les nombres negatifs sont geres. Si l'allocation echoue, la fonction renvoie NULL.
[ft_uitoa_base](ft_itoa_base.c) | `char	*ft_itoa(uintmax_t n, int base);` | Alloue avec malloc(3) et retourne une chaine de caracteres "fraiche" terminee par un '\0' representatnt l'entier n passe en parametre converti selon la base donnée. Les nombres negatifs sont geres. Si l'allocation echoue, la fonction renvoie NULL.
[ft_abs](ft_abs.c) |  `int	ft_abs(int n);` | Prend en paramètre un int et renvoie sa valeur absolue.
[ft_intlen](ft_intlen.c) | `int	ft_intlen(int n);` | Prend en paramètre un int et renvoie le nombre de caractères qui composent le nombre. En cas de valeur négative, le signe '-' est compté comme un caractère.
[ft_power](ft_power.c) | `int	ft_power(int nb, int power);` | Fonction puissance.
[ft_sqrt](ft_sqrt.c) | `int	ft_sqrt(int nb);` | Fonction racine carrée (square root). Si la racine carrée n'est pas entière, la fonction renvoie 0.
[ft_int_sqrt](ft_int_sqrt.c) | `int	ft_int_sqrt(int nb);` | Fonction racine carrée (square root). Renvoie l'entier inférieur de la racine carrée.
[ft_bitlen](ft_bitlen.c) | `int	ft_bitlen(unsigned int n);` | Compte le nombre de bits d'un nombre entier.


## Fonctions listes chaînées
Fonctions | Prototype | Description
--- | ---- | ---------------------
[ft_lstnew](ft_lstnew.c) | `t_list	*ft_lstnew(void const *content, size_t content_size);` | Alloue avec malloc(3) et retourne un maillon “frais”. Les champs content et content_size du nouveau maillon sont initialises par copie des parametres de la fonction. Si le parametre content est nul, le champs content est initialise a NULL et le champs content_size est initialise a 0 quelque soit la valeur du parametre content_size. Le champ next est initialise a NULL. Si l’allocation echoue, la fonction renvoie NULL.
[ft_lstdelone](ft_lstdelone.c) | `void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));` | Prend en parametre l’adresse d’un pointeur sur un maillon et libere la memoire du contenu de ce maillon avec la fonction del passee en parametre puis libere la memoire du maillon en lui meme avec free(3). La memoire du champ next ne doit en aucun cas être liberee. Pour terminer, le pointeur sur le maillon maintenant libere doit etre mis a NULL (de maniere similaire à la fonction ft_memdel).
[ft_lstdel](ft_lstdel.c) | `void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));` | Prend en parametre l’adresse d’un pointeur sur un maillon et libere la memoire de ce maillon et celle de tous ses successeurs l’un apres l’autre avec del et free(3). Pour terminer, le pointeur sur le premier maillon maintenant libere doit etre mis à NULL (de maniere similaire à la fonction ft_memdel).
[ft_lstadd](ft_lstadd.c) | `void	ft_lstadd(t_list **alst, t_list *new0);` | Ajoute l'element new en tete de la liste.
[ft_lstappend](ft_lstappend.c) | `void	ft_lstappend(t_list *new0, t_list *first_link);` | Ajoute l'element new en fin de liste.
[ft_lstiter](ft_lstiter.c) | `void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));` | Parcourt la liste lst en appliquant a chaque maillon la fonction f.
[ft_lstmap](ft_lstmap.c) | `t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));` | Parcourt la liste lst en appliquant à chaque maillon la fonction f et cree une nouvelle liste “fraiche” avec malloc(3) resultant des applications successives. Si une allocation echoue, la fonction renvoie NULL.


## Fonctions d'ouverture, fermeture, suppression... de File Descriptor
Fonctions | Prototype | Description
--- | ---- | ---------------------
[ft_open_fd](ft_open_fd.c) | `int	ft_open_fd(char *path, int oflag, int perm);` | Ouvre un fichier et attribue un file descriptor. Renvoie 1 en cas de succès, sinon -1 en cas d'erreur.
[ft_close_fd](ft_close_fd.c) | `int	ft_close_fd(int fd);` | Ferme un fd déjà ouvert. Renvoie 1 en cas de succès, sinon -1 en cas d'erreur.
[ft_remove](ft_remove.c) | `int	ft_remove(char *path);` | Supprime un fichier. Renvoie 1 en cas de succès, sinon -1 en cas d'erreur.
[ft_file_exists](ft_file_exists.c) | `int	ft_file_exists(char *path);` | Vérifie si un fichier existe en essayant de l'ouvrir en lecture seule. Renvoie 1 s'il existe, puis le ferme. Sinon 0 s'il n'existe pas.


## Fonctions d'affichage, lecture, écriture
Fonctions | Prototype | Description
--- | ---- | ---------------------
[ft_putchar](ft_putchar.c) | `void	ft_putchar(char c);` | Affiche le caractere c sur la sortie standard.
[ft_putchar_fd](ft_putchar_fd.c) | `void	ft_putchar_fd(char c, int fd);` | Ecrit le caractere c sur le descripteur de fichier fd.
[ft_putstr](ft_putstr.c) | `void	ft_putstr(char const *s);` | Affiche la chaine s sur la sortir standard.
[ft_putstr_fd](ft_putstr_fd.c) | `void	ft_putstr_fd(char const *s, int fd);` | Ecrit la chaine s sur le descripteur de fichier fd.
[ft_putendl](ft_putendl.c) | `void	ft_putendl(char const *s);` | Affiche la chaine s sur la sortie standard suivi d'un '\n'.
[ft_putendl_fd](ft_putendl_fd.c) | `void	ft_putendl_fd(char const *s, int fd);` | Ecrit la chaine s sur le descripteur de fichier fd suivi d'un '\n'.
[ft_putnbr](ft_putnbr.c) | `void	ft_putnbr(int n);` | Affiche l'entier n sur la sortie standard.
[ft_putnbr_fd](ft_putnbr_fd.c) | `void	ft_putnbr_fd(int n, int fd);` | Ecrit l'entier n sur le descripteur de fichier fd.


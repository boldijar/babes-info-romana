//Implementati un program care scrie intr-o variabila globala un numar aleator de la 0 la 9 si apoi creeaza 10 thread-uri. 
//Fiecare thread va verifica variabila globala si daca valoarea e chiar numarul de ordine al thread-ului (transmis din main la creare),
//va genera un nou numar de la 0 la 9 (diferit de numarul de ordine propriu) si il va scrie in variabila globala. 
//Thread-urile se termina dupa ce variabila globala a fost schimabta de 20 de ori.
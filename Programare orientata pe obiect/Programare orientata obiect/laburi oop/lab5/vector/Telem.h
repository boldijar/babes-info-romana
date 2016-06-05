#ifndef TELEM_H
#define TELEM_H

typedef void *Telem;

typedef void (*cpyfct)(Telem &, Telem);
typedef int (*cmpfct)(Telem,Telem);
typedef void (*delfct)(Telem &);


#endif;